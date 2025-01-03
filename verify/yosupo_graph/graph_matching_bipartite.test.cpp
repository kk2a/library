#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching" 

#include "../../graph/graph.hpp"
#include "../../graph/maxflow.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int l, r, m;
    kin >> l >> r >> m;
    kk2::DWAdjList<int> g(l + r + 2);
    rep (m) {
        int a, b;
        kin >> a >> b;
        g.add_edge(a, l + b, 1);
    }
    rep (i, l) g.add_edge(l + r, i, 1);
    rep (i, r) g.add_edge(l + i, l + r + 1, 1);

    kk2::MaxFlow<kk2::DWAdjList<int>> mf(g);

    int count = mf.flow(l + r, l + r + 1);
    kout << count << "\n";

    auto tmp = mf.get_edges();
    for (auto &&e : tmp) {
        if (count == 0) break;
        if (e.flow == 0) continue;
        kout << e.from << " " << e.to - l << "\n";
        count--;
    }

    return 0;
}
