#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum" 

#include "../../graph/tree/heavy_light_decomposition.hpp"
#include "../../graph/graph.hpp"
#include "../../template/template.hpp"
#include "../../data_structure/binary_indexed_tree.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    vc<i64> a(n);
    kin >> a;
    kk2::AdjList g(n, n - 1);
    g.input(kin);

    kk2::HeavyLightDecomposition hld(g);
    kk2::BinaryIndexedTree<i64> bit(hld.id);
    rep (i, n) {
        auto [l, r] = hld.get_node_idx(i);
        bit.add(l, a[i]);
    }
    rep (q) {
        int type;
        kin >> type;
        if (type == 0) {
            int p, x;
            kin >> p >> x;
            auto [l, r] = hld.get_node_idx(p);
            bit.add(l, x);
        } else {
            int u, v;
            kin >> u >> v;
            i64 res = 0;
            hld.path_query(u, v, 1, [&](int l, int r) {
                res += bit.sum(l, r);
            });
            kout << res << "\n";
        }
    }

    return 0;
}
