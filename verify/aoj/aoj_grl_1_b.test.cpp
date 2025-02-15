#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B" 

#include "../../graph/graph.hpp"
#include "../../graph/shortest_path/bellman_ford.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m, s;
    kin >> n >> m >> s;
    kk2::DWAdjList<int> g(n, m);
    g.input(kin);
    auto [dist, prev] = kk2::bellman_ford(g, s);

    rep (i, n) {
        if (dist[i].minf) {
            kout << "NEGATIVE CYCLE" << kendl;
            return 0;
        }
    }

    rep (i, n) {
        if (dist[i].inf) {
            kout << "INF" << kendl;
        } else {
            kout << dist[i].len << kendl;
        }
    }

    return 0;
}
