#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include "../../bbst/lazy_red_black_tree.hpp"
#include "../../modint/mont.hpp"
#include "../../math/action/affine_sumwithsize.hpp"
#include "../../template/template.hpp"
using namespace std;

using mint = kk2::mont998;

using A = kk2::action::AffineSumWithSize<mint, mint>;

int main() {
    int n, q;
    kin >> n >> q;
    vc<A::S> a(n);
    kin >> a;
    kk2::LazyRedBlackTreeS<A> rbt(2 * (n + q));
    auto t = rbt.build(a);
    rep (i, q) {
        int type;
        kin >> type;
        if (type == 0) {
            int p, x;
            kin >> p >> x;
            rbt.insert(t, p, mint(x), mint(1));
        }
        if (type == 1) {
            int p;
            kin >> p;
            rbt.erase(t, p);
        }
        if (type == 2) {
            int l, r;
            kin >> l >> r;
            rbt.reverse(t, l, r);
        }
        if (type == 3) {
            int l, r;
            mint b, c;
            kin >> l >> r >> b >> c;
            rbt.apply(t, l, r, b, c);
        }
        if (type == 4) {
            int l, r;
            kin >> l >> r;
            kout << rbt.prod(t, l, r).a << "\n";
        }
    }

    return 0;
}
