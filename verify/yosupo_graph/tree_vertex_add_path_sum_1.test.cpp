#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum" 

#include "../../graph/tree/euler_tour.hpp"
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

    kk2::EulerTour et(g);
    kk2::BinaryIndexedTree<i64> bit(et.id + 1);
    rep (i, n) {
        auto [l, r] = et.get_node_idx(i);
        bit.add(l, a[i]), bit.add(r, -a[i]);
    }
    rep (q) {
        int type;
        kin >> type;
        if (type == 0) {
            int p, x;
            kin >> p >> x;
            auto [l, r] = et.get_node_idx(p);
            bit.add(l, x), bit.add(r, -x);
        } else {
            int u, v;
            kin >> u >> v;
            i64 res = 0;
            et.path_query(u, v, 1, [&](int l, int r) {
                res += bit.sum(l, r);
            });
            kout << res << "\n";
        }
    }

    return 0;
}
