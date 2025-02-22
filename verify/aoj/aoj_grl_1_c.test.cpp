#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C" 

#include "../../graph/graph.hpp"
#include "../../graph/shortest_path/warshall_floyd.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    kin >> n >> m;
    kk2::DWAdjMat<int> g(n, m);
    g.input(kin);
    auto dist = kk2::warshall_froyd(g);
    rep (i, n) if (dist[i][i].minf) {
        kout << "NEGATIVE CYCLE" << kendl;
        return 0;
    }

    rep (i, n) {
        rep (j, n) {
            if (!dist[i][j].inf) kout << dist[i][j].len;
            else kout << "INF";
            kout << " \n"[j == n - 1];
        }
    }

    return 0;
}
