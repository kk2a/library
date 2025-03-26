#ifndef KK2_SEGMENT_TREE_SEG_HPP
#define KK2_SEGMENT_TREE_SEG_HPP 1

#include <cassert>
#include <functional>
#include <vector>

namespace kk2 {

template <class S, S (*op)(S, S), S (*e)()>
struct SegmentTree {
  public:
    SegmentTree() : SegmentTree(0) {}

    SegmentTree(int n) : _n(n) {
        log = 0;
        while ((1U << log) < (unsigned int)(_n)) log++;
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
    }

    template <class... Args>
    SegmentTree(int n, Args... args) : SegmentTree(std::vector<S>(n, S(args...))){};

    SegmentTree(const std::vector<S> &v) : _n(int(v.size())) {
        log = 0;
        while ((1U << log) < (unsigned int)(_n)) log++;
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        build();
    }

    void build() {
        assert(!is_built);
        is_built = true;
        for (int i = size - 1; i >= 1; i--) { update(i); }
    }

    template <class... Args>
    void init_set(int p, Args... args) {
        assert(0 <= p && p < _n);
        assert(!is_built);
        d[p + size] = S(args...);
    }

    using Monoid = S;

    static S Op(S l, S r) { return op(l, r); }

    static S MonoidUnit() { return e(); }

    template <class... Args>
    void set(int p, Args... args) {
        assert(0 <= p && p < _n);
        assert(is_built);
        p += size;
        d[p] = S(args...);
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        assert(is_built);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        assert(is_built);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() {
        assert(is_built);
        return d[1];
    }

    // return r s.t.
    // r = l or f(op(a[l], a[l+1], ..., a[r-1])) == true
    // r = n or f(op(a[l], a[l+1], ..., a[r]))   == false
    template <bool (*f)(S)>
    int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }

    template <class F>
    int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        assert(is_built);
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    // return l s.t.
    // l = r or f(op(a[l], a[l], ..., a[r-1]))   == true
    // l = 0 or f(op(a[l-1], a[l], ..., a[r-1])) == false
    template <bool (*f)(S)>
    int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }

    template <class F>
    int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        assert(is_built);
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    bool is_built = false;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

template <class M>
using SegmentTreeS = SegmentTree<M, M::op, M::unit>;

} // namespace kk2

#endif // KK2_SEGMENT_TREE_SEG_HPP
