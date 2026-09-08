// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite

#include "../../functional/reverse_args.hpp"
#include "../../math/monoid/affine.hpp"
#include "../../math/monoid/rev_op.hpp"
#include "../../modint/mont.hpp"
#include "../../segment_tree/seg.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    using M = kk2::monoid::Affine<kk2::mont998>;
    using RM = kk2::monoid::ReverseOp<M>;
    vc<RM> a(n);
    kin >> a;
    kk2::SegmentTree<RM> seg(a);

    rep(q) {
        int t;
        kin >> t;
        if (t == 0) {
            int p;
            kk2::mont998 c, d;
            kin >> p >> c >> d;
            seg.set(p, c, d);
        }
        if (t == 1) {
            int l, r;
            kk2::mont998 x;
            kin >> l >> r >> x;
            kout << seg.prod(l, r).eval(x) << "\n";
        }
    }

    return 0;
}
