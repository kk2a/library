#ifndef KK2_SEGMENT_TREE_SEG_HPP
#define KK2_SEGMENT_TREE_SEG_HPP 1

#include <cassert>
#include <vector>

#include "../type_traits/algebra.hpp"

namespace kk2 {

template <algebra::Monoid M> struct SegmentTree {
  public:
    SegmentTree() : SegmentTree(0) {}

    SegmentTree(int n) : _n(n) {
        log = 0;
        while ((1U << log) < (unsigned int)(_n)) log++;
        size = 1 << log;
        d = std::vector<M>(2 * size, M::unit());
    }

    template <class... Args> SegmentTree(int n, Args... args)
        : SegmentTree(std::vector<M>(n, M(args...))) {}

    SegmentTree(const std::vector<M> &v) : _n(int(v.size())) {
        log = 0;
        while ((1U << log) < (unsigned int)(_n)) log++;
        size = 1 << log;
        d = std::vector<M>(2 * size, M::unit());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        build();
    }

    void build() {
        assert(!is_built);
        is_built = true;
        for (int i = size - 1; i >= 1; i--) update(i);
    }

    template <class... Args> void init_set(int p, Args... args) {
        assert(0 <= p && p < _n);
        assert(!is_built);
        d[p + size] = M(args...);
    }

    using Monoid = M;

    static M Op(M l, M r) { return M::op(l, r); }

    static M MonoidUnit() { return M::unit(); }

    template <class... Args> void set(int p, Args... args) {
        assert(0 <= p && p < _n);
        assert(is_built);
        p += size;
        d[p] = M(args...);
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    M get(int p) {
        assert(0 <= p && p < _n);
        assert(is_built);
        return d[p + size];
    }

    M prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        assert(is_built);
        M sml = M::unit(), smr = M::unit();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = M::op(sml, d[l++]);
            if (r & 1) smr = M::op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return M::op(sml, smr);
    }

    M all_prod() {
        assert(is_built);
        return d[1];
    }

    template <bool (*f)(M)> int max_right(int l) {
        return max_right(l, [](M x) { return f(x); });
    }

    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(M::unit()));
        assert(is_built);
        if (l == _n) return _n;
        l += size;
        M sm = M::unit();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(M::op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(M::op(sm, d[l]))) {
                        sm = M::op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = M::op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(M)> int min_left(int r) {
        return min_left(r, [](M x) { return f(x); });
    }

    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(M::unit()));
        assert(is_built);
        if (r == 0) return 0;
        r += size;
        M sm = M::unit();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(M::op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(M::op(d[r], sm))) {
                        sm = M::op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = M::op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<M> d;
    bool is_built = false;

    void update(int k) { d[k] = M::op(d[2 * k], d[2 * k + 1]); }
};

} // namespace kk2

#endif // KK2_SEGMENT_TREE_SEG_HPP
