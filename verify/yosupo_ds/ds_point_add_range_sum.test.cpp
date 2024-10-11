#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../segment_tree/utility/sumseg.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    auto a = kk2::GetVecSum<i64>(n);
    cin >> a;
    kk2::SumSeg<i64> seg(a);

    rep (q) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            seg.emplace_set(p, seg.get(p).a + x);
        }
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l, r).a << "\n";
        }
    }

    return 0;
}
