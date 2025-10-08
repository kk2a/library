#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree" 

#include "../../graph/graph.hpp"
#include "../../graph/tree/minimum_spanning_tree.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    kin >> n >> m;
    kk2::WAdjList<i64> g(n, m);
    g.input(kin);
    auto [cost, idxs] = kk2::minimum_spanning_tree(g);
    kout << cost << "\n" << idxs << "\n";

    return 0;
}
