#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../../graph/graph.hpp"
#include "../../graph/scc.hpp"
#include "../../graph/topological_sort.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    kin >> n >> m;
    kk2::DAdjList g(n, m, false);
    g.input(kin);
    kk2::SCC<kk2::DAdjList> scc(g);
    auto perm = kk2::topological_sort(scc.dag);
    kout << scc.size() << "\n";
    for (auto &v : perm) { kout << scc.same_scc(v).size() << " " << scc.same_scc(v) << "\n"; }

    return 0;
}
