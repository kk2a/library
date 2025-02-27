#ifndef KK2_DATA_STRUCTURE_SPARSE_TABLE_HPP
#define KK2_DATA_STRUCTURE_SPARSE_TABLE_HPP 1

#include <cassert>
#include <vector>

namespace kk2 {

// require: op(x, x) = x for all x
template <class S, S (*op)(S, S), S (*e)()>
struct SparseTable {
    SparseTable() = default;

    SparseTable(int n) : _n(n) {
        log = 0;
        while ((1 << log) < _n) log++;
        table.assign(log + 1, std::vector<S>(_n));
    }

    SparseTable(const std::vector<S> &v) : _n(int(v.size())) {
        log = 0;
        while ((1 << log) < _n) log++;
        table.assign(log + 1, std::vector<S>(_n));
        for (int i = 0; i < _n; i++) table[0][i] = v[i];
        build();
    }

    void build() {
        for (int i = 1; i <= log; i++) {
            for (int j = 0; j + (1 << i) <= _n; j++) {
                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    void init_set(int p, S x) {
        assert(0 <= p && p < _n);
        table[0][p] = x;
    }

    template <class... Args>
    void emplace_init_set(int p, Args... args) {
        init_set(p, S(args...));
    }

    using Monoid = S;

    static S Op(S l, S r) { return op(l, r); }

    static S MonoidUnit() { return e(); }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();
        int i = 31 ^ __builtin_clz(r - l);
        return op(table[i][l], table[i][r - (1 << i)]);
    }

    S get(int i) const {
        assert(0 <= i && i < _n);
        return table[0][i];
    }

    // return r s.t.
    // r = l or f(op(a[l], a[l+1], ..., a[r-1])) == true
    // r = n or f(op(a[l], a[l+1], ..., a[r]))   == false
    template <bool (*f)(S)>
    int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }

    template <class F>
    int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
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
    template <bool (*f)(S)>
    int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }

    template <class F>
    int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
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
    std::vector<std::vector<S>> table;
};

} // namespace kk2

#endif // KK2_DATA_STRUCTURE_SPARSE_TABLE_HPP
