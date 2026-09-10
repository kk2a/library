#ifndef KK2_SEGMENT_TREE_LAZY_HPP
#define KK2_SEGMENT_TREE_LAZY_HPP 1

#include <cassert>
#include <vector>

#include "../type_traits/algebra.hpp"

namespace kk2 {

template <algebra::Action Action> struct LazySegmentTree {
    using S = typename Action::S;
    using F = typename Action::A;

  public:
    LazySegmentTree() : LazySegmentTree(0) {}

    LazySegmentTree(int n) : _n(n) {
        log = 0;
        while ((1ll << log) < _n) log++;
        size = 1 << log;
        d = std::vector<S>(2 * size, S::unit());
        lz = std::vector<F>(size, F::unit());
    }

    template <class... Args>
    LazySegmentTree(int n, Args... args) : LazySegmentTree(std::vector<S>(n, S(args...))) {}

    LazySegmentTree(const std::vector<S> &v) : _n(int(v.size())) {
        log = 0;
        while ((1ll << log) < _n) log++;
        size = 1 << log;
        d = std::vector<S>(2 * size, S::unit());
        lz = std::vector<F>(size, F::unit());
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
        d[p + size] = S(args...);
    }

    using Monoid = S;
    static S Op(S l, S r) { return S::op(l, r); }
    static S MonoidUnit() { return S::unit(); }

    using Hom = F;
    static S Map(F f, S x) { return Action::act(f, x); }
    static F Composition(F l, F r) { return F::op(l, r); }
    static F HomUnit() { return F::unit(); }

    template <class... Args> void set(int p, Args... args) {
        assert(0 <= p && p < _n);
        assert(is_built);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = S(args...);
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        assert(is_built);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        assert(is_built);
        if (l == r) return S::unit();
        l += size;
        r += size;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }
        S sml = S::unit(), smr = S::unit();
        while (l < r) {
            if (l & 1) sml = S::op(sml, d[l++]);
            if (r & 1) smr = S::op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return S::op(sml, smr);
    }

    S all_prod() {
        assert(is_built);
        return d[1];
    }

    template <class... Args> void apply_point(int p, Args... args) {
        assert(0 <= p && p < _n);
        assert(is_built);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = Action::act(F(args...), d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    template <class... Args> void apply_range(int l, int r, Args... args) {
        assert(0 <= l && l <= r && r <= _n);
        assert(is_built);
        if (l == r) return;
        F f = F(args...);
        l += size;
        r += size;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }
        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }

    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(S::unit()));
        assert(is_built);
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = S::unit();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(S::op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = 2 * l;
                    if (g(S::op(sm, d[l]))) {
                        sm = S::op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = S::op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }

    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(S::unit()));
        assert(is_built);
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = S::unit();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(S::op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = 2 * r + 1;
                    if (g(S::op(d[r], sm))) {
                        sm = S::op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = S::op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;
    bool is_built = false;

    void update(int k) { d[k] = S::op(d[2 * k], d[2 * k + 1]); }

    void all_apply(int k, const F &f) {
        d[k] = Action::act(f, d[k]);
        if (k < size) lz[k] = F::op(f, lz[k]);
    }

    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = F::unit();
    }
};

} // namespace kk2

#endif // KK2_SEGMENT_TREE_LAZY_HPP
