#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection" 

#include "../../graph/graph.hpp"
#include "../../graph/cycle_detection.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m;
    kin >> n >> m;
    kk2::DAdjList g(n, m);
    g.input(kin);
    if (const auto res = kk2::cycle_detection(g); res) {
        kout << res->size() << '\n';
        for (auto &&v : res->edges) kout << v << "\n";
    } else kout << -1 << '\n';

    return 0;
}
