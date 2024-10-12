#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../modint/mont.hpp"
#include "../../segment_tree/utility/affinesum.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    auto a = kk2::GetVecSum<kk2::mont998>(n);
    kin >> a;
    kk2::AffineSum<kk2::mont998> seg(a);

    rep (q) {
        int t;
        kin >> t;
        if (t == 0) {
            int l, r;
            kk2::mont998 b, c;
            kin >> l >> r >> b >> c;
            seg.emplace_apply_range(l, r, b, c);
        }
        if (t == 1) {
            int l, r;
            kin >> l >> r;
            kout << seg.prod(l, r).a << "\n";
        }
    }

    return 0;
}
