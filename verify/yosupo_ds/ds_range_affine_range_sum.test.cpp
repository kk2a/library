#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../modint/mont.hpp"
#include "../../math/action/affine_sumwithsize.hpp"
#include "../../segment_tree/lazy.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    using A = kk2::action::AffineSumWithSize<kk2::mont998, kk2::mont998>;
    int n, q;
    kin >> n >> q;
    vc<A::S> a(n);
    kin >> a;
    kk2::LazySegmentTreeS<A> seg(a);

    rep (q) {
        int t;
        kin >> t;
        if (t == 0) {
            int l, r;
            kk2::mont998 b, c;
            kin >> l >> r >> b >> c;
            seg.apply_range(l, r, b, c);
        }
        if (t == 1) {
            int l, r;
            kin >> l >> r;
            kout << seg.prod(l, r).a << "\n";
        }
    }

    return 0;
}
