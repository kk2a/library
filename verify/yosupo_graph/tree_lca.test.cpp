#define PROBLEM "https://judge.yosupo.jp/problem/lca" 

#include "../../graph/graph.hpp"
#include "../../graph/tree/heavy_light_decomposition.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    kk2::AdjList g(n);
    rep (i, n - 1) {
        int p;
        kin >> p;
        g.add_edge(i + 1, p);
    }
    kk2::HeavyLightDecomposition<kk2::AdjList> hld(g);
    rep (q) {
        int u, v;
        kin >> u >> v;
        kout << hld.lca(u, v) << "\n";
    }

    return 0;
}
