#define PROBLEM "https://yukicoder.me/problems/no/1326" 

#include "../../graph/graph.hpp"
#include "../../graph/tree/block_cut_tree.hpp"
#include "../../graph/tree/heavy_light_decomposition.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    kin >> n >> m;
    kk2::AdjList g(n, m);
    g.input(kin, 1);

    kk2::BlockCutTree bct(g);
    kk2::HeavyLightDecomposition hld(bct.forest);

    int q;
    kin >> q;

    rep (q) {
        int x, y;
        kin >> x >> y;
        --x, --y;
        if (bct.comp_v[x] == bct.comp_v[y]) {
            kout << 0 << "\n";
            continue;
        }
        int res = hld.dist(bct.comp_v[x], bct.comp_v[y]);
        if (bct.is_articulation(x)) --res;
        if (bct.is_articulation(y)) --res;
        kout << res / 2 << "\n";
    }

    return 0;
}
