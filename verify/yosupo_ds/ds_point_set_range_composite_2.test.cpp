#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite" 

#include "../../bbst/red_black_tree.hpp"
#include "../../functional/reverse_args.hpp"
#include "../../math/monoid/affine.hpp"
#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
using namespace std;

struct S : public kk2::monoid::Affine<kk2::mont998> {
    using base = kk2::monoid::Affine<kk2::mont998>;
    using base::Affine;
    S(const base &b) : base(b) {}
    static inline S op(S l, S r) {
        return S{r.a * l.a, r.a * l.b + r.b};
    }
};

int main() {
    int n, q;
    kin >> n >> q;
    vc<S> a(n);
    kin >> a;
    kk2::RedBlackTree<S> rbt(2 * (n + q));
    auto root = rbt.build(a);

    rep (q) {
        int type;
        kin >> type;
        if (type == 0) {
            int p;
            kk2::mont998 c, d;
            kin >> p >> c >> d;
            rbt.set(root, p, c, d);
        }
        if (type == 1) {
            int l, r;
            kk2::mont998 x;
            kin >> l >> r >> x;
            kout << rbt.prod(root, l, r).eval(x) << "\n";
        }
    }

    return 0;
}
