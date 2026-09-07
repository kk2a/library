#ifndef KK2_DATA_STRUCTURE_SPARSE_TABLE_HPP
#define KK2_DATA_STRUCTURE_SPARSE_TABLE_HPP 1

#include <cassert>
#include <vector>

#include "../type_traits/algebra.hpp"

namespace kk2 {

// require: op(x, x) = x for all x
template <algebra::Monoid M> struct SparseTable {
    SparseTable() = default;

    SparseTable(int n) : _n(n) {
        log = 0;
        while ((1 << log) < _n) log++;
        table.assign(log + 1, std::vector<M>(_n));
    }

    SparseTable(const std::vector<M> &v) : _n(int(v.size())) {
        log = 0;
        while ((1 << log) < _n) log++;
        table.assign(log + 1, std::vector<M>(_n));
        for (int i = 0; i < _n; i++) table[0][i] = v[i];
        build();
    }

    void build() {
        assert(!is_built);
        is_built = true;
        for (int i = 1; i <= log; i++) {
            for (int j = 0; j + (1 << i) <= _n; j++) {
                table[i][j] = M::op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    template <class... Args> void init_set(int p, Args... args) {
        assert(0 <= p && p < _n);
        assert(!is_built);
        table[0][p] = M(args...);
    }

    using Monoid = M;

    static M Op(M l, M r) { return M::op(l, r); }

    static M MonoidUnit() { return M::unit(); }

    M prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        assert(is_built);
        if (l == r) return M::unit();
        int i = 31 ^ __builtin_clz(r - l);
        return M::op(table[i][l], table[i][r - (1 << i)]);
    }

    M get(int i) const {
        assert(0 <= i && i < _n);
        assert(is_built);
        return table[0][i];
    }

    // return r s.t.
    // r = l or f(op(a[l], a[l+1], ..., a[r-1])) == true
    // r = n or f(op(a[l], a[l+1], ..., a[r]))   == false
    template <bool (*f)(M)> int max_right(int l) const {
        return max_right(l, [](M x) { return f(x); });
    }

    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(M::unit()));
        assert(is_built);
        if (l == _n) return _n;
        int left = l - 1, right = _n;
        while (right - left > 1) {
            int mid = (left + right) >> 1;
            if (f(prod(l, mid))) left = mid;
            else right = mid;
        }
        return right;
    }

    // return l s.t.
    // l = r or f(op(a[l], a[l+1], ..., a[r-1])) == false
    // l = 0 or f(op(a[l], a[l+1], ..., a[r]))   == true
    template <bool (*f)(M)> int min_left(int r) const {
        return min_left(r, [](M x) { return f(x); });
    }

    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(M::unit()));
        assert(is_built);
        if (r == 0) return 0;
        int left = -1, right = r;
        while (right - left > 1) {
            int mid = (left + right) >> 1;
            if (f(prod(mid, r))) right = mid;
            else left = mid;
        }
        return right;
    }

  private:
    int _n, log;
    std::vector<std::vector<M>> table;
    bool is_built = false;
};

} // namespace kk2

#endif // KK2_DATA_STRUCTURE_SPARSE_TABLE_HPP
