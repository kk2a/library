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

        kout << ch.hull.size() << "\n";
        vc<kk2::Point<i64>> res(ch.hull.size());
        rep (i, n) {
            if (ch.idx_hull[i] != -1) res[ch.idx_hull[i]] = p[i];
        }
        for (auto &q : res) kout << q << "\n";
    }

    return 0;
}
