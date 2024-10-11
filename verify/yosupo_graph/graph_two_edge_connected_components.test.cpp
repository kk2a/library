#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../../graph/graph.hpp"
#include "../../graph/two_edge_connected_components.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    kk2::AdjList g(n, m, false);
    g.input(cin);
    kk2::TwoEdgeConnectedComponents<kk2::AdjList> tecc(g);
    cout << tecc.size() << "\n";
    for (auto &v : tecc.group) cout << v.size() << " " << v << "\n";

    return 0;
}
