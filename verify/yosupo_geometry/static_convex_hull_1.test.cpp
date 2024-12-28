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
        for (int i = 0; i < (int)ch.dw.size(); ++i) {
            kout << ch.dw[i] << "\n";
        }
        for (int i = (int)ch.up.size() - 2; i; --i) {
            kout << ch.up[i] << "\n";
        }
    }

    return 0;
}
