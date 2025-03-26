#define PROBLEM "https://judge.yosupo.jp/problem/range_set_range_composite"

#include "../../modint/mont.hpp"
#include "../../segment_tree/lazy.hpp"
#include "../../template/template.hpp"
using namespace std;

struct S {
    kk2::mont998 a, b;
    int size;
};

template <class IStream> IStream &operator>>(IStream &is, S &s) {
    is >> s.a >> s.b;
    s.size = 1;
    return is;
}

S op(S l, S r) {
    return S{r.a * l.a, r.a * l.b + r.b, l.size + r.size};
}

S e() {
    return S{1, 0, 0};
}

struct F {
    S a;
    bool id;
};

S mapping(F f, S x) {
    if (f.id) return x;
    if (f.a.a == kk2::mont998(1)) return S{kk2::mont998(1), f.a.b * x.size, x.size};
    kk2::mont998 p = f.a.a.pow(x.size);
    return S{p, f.a.b * (p - 1) * (f.a.a - 1).inv(), x.size};
}

F composition(F l, F r) {
    if (l.id) return r;
    return l;
}

F id() {
    return F{S{1, 0, 0}, true};
}

int main() {
    int n, q;
    kin >> n >> q;
    vector<S> a(n);
    kin >> a;

    kk2::LazySegmentTree<S, op, e, F, mapping, composition, id> seg(a);

    rep (q) {
        int t;
        kin >> t;
        if (t == 0) {
            int l, r;
            kk2::mont998 c, d;
            kin >> l >> r >> c >> d;
            seg.apply_range(l, r, F{S{c, d, 1}, false});
        }
        if (t == 1) {
            int l, r;
            kk2::mont998 x;
            kin >> l >> r >> x;
            auto f = seg.prod(l, r);
            kout << f.a * x + f.b << "\n";
        }
    }

    return 0;
}
