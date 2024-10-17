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
        kk2::ConvexHull ch(p);
        ch.build();
        auto hull = ch.hull;
        kout << ch.hull.size() << "\n";
        for (auto &q : ch.hull) kout << q << "\n";
    }

    return 0;
}
