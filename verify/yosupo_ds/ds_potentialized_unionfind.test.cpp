#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include "../../modint/mont.hpp"
#include "../../template/template.hpp"
#include "../../unionfind/potentialized.hpp"
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    kk2::PotentializedUnionfind<kk2::mont998> puf(n);

    rep (q) {
        int t;
        cin >> t;
        if (t == 0) {
            int u, v;
            kk2::mont998 w;
            cin >> u >> v >> w;
            if (puf.same(u, v)) {
                cout << (puf.diff(u, v) == w) << "\n";
            } else {
                cout << "1\n";
                puf.unite(u, v, w);
            }
        }
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            if (puf.same(u, v)) {
                cout << puf.diff(u, v) << "\n";
            } else cout << "-1\n";
        }
    }

    return 0;
}
