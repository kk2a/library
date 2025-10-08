#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum" 

#include "../../graph/tree/euler_tour.hpp"
#include "../../graph/graph.hpp"
#include "../../template/template.hpp"
#include "../../data_structure/binary_indexed_tree.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, q;
    kin >> n >> q;
    vc<int> a(n);
    vc<int> p(n - 1);
    kin >> a >> p;
    kk2::AdjList g(n);
    rep (i, n - 1) g.add_edge(i + 1, p[i]);

    kk2::EulerTour et(g);
    kk2::BinaryIndexedTree<i64> bit(et.id + 1);
    rep (i, n) {
        auto [l, r] = et.get_node_idx(i);
        bit.add(l, a[i]);
    }
    rep (q) {
        int type;
        kin >> type;
        if (type == 0) {
            int u, x;
            kin >> u >> x;
            auto [l, r] = et.get_node_idx(u);
            bit.add(l, x);
        } else {
            int u;
            kin >> u;
            i64 res = 0;
            et.subtree_query(u, 1, [&](int l, int r) {
                res += bit.sum(l, r);
            });
            kout << res << "\n";
        }
    }

    return 0;
}
