#ifndef DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP
#define DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace kk2 {

template <class S, S (*op)(S, S), S (*e)()>
struct DisjointSparseTable {
    DisjointSparseTable() = default;
    DisjointSparseTable(const std::vector<S>& v) : _n(int(v.size())) {
        log = 0;
        while ((1 << log) < _n) log++;
        table.assign(log + 1, std::vector<S>(_n));
        for (int i = 0; i < _n; ++i) table[0][i] = v[i];
        for (int i = 1; i <= log; ++i) {
            int shift = 1 << i;
            for (int left = 0; left < _n; left += shift << 1) {
                int cent = std::min(left + shift, _n);
                table[i][cent - 1] = v[cent - 1];
                for (int j = cent - 2; j >= left; --j) {
                    table[i][j] = op(v[j], table[i][j + 1]);
                }
                if (cent == _n) break;
                table[i][cent] = v[cent];
                int right = std::min(cent + shift, _n);
                for (int j = cent + 1; j < right; ++j) {
                    table[i][j] = op(table[i][j - 1], v[j]);
                }
            }
        }
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
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
};

} // namespace kk2

#endif // DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP
