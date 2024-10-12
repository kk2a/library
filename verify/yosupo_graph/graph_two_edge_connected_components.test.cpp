#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../../graph/graph.hpp"
#include "../../graph/two_edge_connected_components.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    kin >> n >> m;
    kk2::AdjList g(n, m, false);
    g.input(kin);
    kk2::TwoEdgeConnectedComponents<kk2::AdjList> tecc(g);
    kout << tecc.size() << "\n";
    for (auto &v : tecc.group) kout << v.size() << " " << v << "\n";

    return 0;
}
