#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull" 

#include "../../geometry/point.hpp"
#include "../../geometry/static_convex_hull.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int t;
    kin >> t;
    rep (t) {
        int n;
        kin >> n;
        vc<kk2::Point<i64>> p(n);
        kin >> p;
        kk2::StaticConvexHull ch(p);
        ch.build();

        if (n == 0) {
            kout << 0 << "\n";
            continue;
        }

        if (ch.up.size() == 1u) {
            kout << 1 << "\n";
            kout << ch.up[0] << "\n";
            continue;
        }

        kout << ch.up.size() + ch.dw.size() - 2 << "\n";
        vc<kk2::Point<i64>> res(ch.up.size() + ch.dw.size() - 2);
        rep (i, n) {
            if (ch.idx_up[i] > 0) res[ch.dw.size() + ch.up.size() - ch.idx_up[i] - 2] = p[i];
            if (ch.idx_dw[i] != -1) res[ch.idx_dw[i]] = p[i];
        }
        for (auto &q : res) kout << q << "\n";
    }

    return 0;
}
