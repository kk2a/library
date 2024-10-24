#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../template/template.hpp"
#include "../../unionfind/unionfind.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    kk2::UnionFind uf(n);

    rep (q) {
        int t;
        kin >> t;
        if (t == 0) {
            int u, v;
            kin >> u >> v;
            uf.unite(u, v);
        }
        if (t == 1) {
            int u, v;
            kin >> u >> v;
            kout << uf.same(u, v) << "\n";
        }
    }

    return 0;
}
