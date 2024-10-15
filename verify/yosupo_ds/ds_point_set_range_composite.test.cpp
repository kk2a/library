#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../../functional/reverse_args.hpp"
#include "../../math/homomorphism/affine.hpp"
#include "../../modint/mont.hpp"
#include "../../segment_tree/seg.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    auto a = kk2::GetVecAffine<kk2::mont998>(n);
    kin >> a;
    kk2::SegTree<kk2::homomorphism::Affine<kk2::mont998>,
                 kk2::reverse_args<kk2::homomorphism::AffineComposition<kk2::mont998>>,
                 kk2::homomorphism::AffineUnit<kk2::mont998>>
        seg(a);

    rep (q) {
        int t;
        kin >> t;
        if (t == 0) {
            int p;
            kk2::mont998 c, d;
            kin >> p >> c >> d;
            seg.emplace_set(p, c, d);
        }
        if (t == 1) {
            int l, r;
            kk2::mont998 x; 
            kin >> l >> r >> x;
            kout << seg.prod(l, r).apply(x) << "\n";
        }
    }

    return 0;
}
