#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
#include "../../unionfind/potentialized.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    kk2::PotentializedUnionfind<kk2::mont998> puf(n);

    rep (q) {
        int t;
        kin >> t;
        if (t == 0) {
            int u, v;
            kk2::mont998 w;
            kin >> u >> v >> w;
            if (puf.same(u, v)) {
                kout << (puf.diff(u, v) == w) << "\n";
            } else {
                kout << "1\n";
                puf.unite(u, v, w);
            }
        }
        if (t == 1) {
            int u, v;
            kin >> u >> v;
            if (puf.same(u, v)) {
                kout << puf.diff(u, v) << "\n";
            } else kout << "-1\n";
        }
    }

    return 0;
}
