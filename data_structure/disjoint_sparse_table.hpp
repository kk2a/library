#ifndef KK2_DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP
#define KK2_DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace kk2 {

template <class S, S (*op)(S, S), S (*e)()>
struct DisjointSparseTable {
    DisjointSparseTable() = default;

    DisjointSparseTable(int n) : _n(n) {
        log = 0;
        while ((1 << log) < _n) log++;
        table.assign(log + 1, std::vector<S>(_n));
    }

    DisjointSparseTable(const std::vector<S> &v) : _n(int(v.size())) {
        log = 0;
        while ((1 << log) < _n) log++;
        table.assign(log + 1, std::vector<S>(_n));
        for (int i = 0; i < _n; ++i) table[0][i] = v[i];
        build();
    }

    void build() {
        assert(!is_built);
        is_built = true;
        for (int i = 1; i <= log; ++i) {
            int shift = 1 << i;
            for (int left = 0; left < _n; left += shift << 1) {
                int cent = std::min(left + shift, _n);
                table[i][cent - 1] = table[0][cent - 1];
                for (int j = cent - 2; j >= left; --j) {
                    table[i][j] = op(table[0][j], table[i][j + 1]);
                }
                if (cent == _n) break;
                table[i][cent] = table[0][cent];
                int right = std::min(cent + shift, _n);
                for (int j = cent + 1; j < right; ++j) {
                    table[i][j] = op(table[i][j - 1], table[0][j]);
                }
            }
        }
    }

    template <class... Args>
    void init_set(int p, Args... args) {
        assert(0 <= p && p < _n);
        assert(!is_built);
        table[0][p] = S(args...);
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        assert(is_built);
        if (l == r) return e();
        if (l + 1 == r) return table[0][l];
        --r;
        int pos = 31 ^ __builtin_clz(l ^ r);
        return op(table[pos][l], table[pos][r]);
    }

  private:
    int _n, log;
    std::vector<std::vector<S>> table;
    std::vector<int> lookup;
    bool is_built = false;
};

template <class M>
using DisjointSparseTableS = DisjointSparseTable<M, M::op, M::unit>;

} // namespace kk2

#endif // KK2_DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP
