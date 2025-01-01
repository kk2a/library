#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../../graph/graph.hpp"
#include "../../graph/shortest_path.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m, s, t;
    kin >> n >> m >> s >> t;
    kk2::DWAdjList<i64> g(n, m);
    g.input(kin);
    auto [dist, prev] = kk2::shortest_path(g, s);

    if (prev[t].to == -1) {
        kout << -1 << "\n";
        return 0;
    }

    std::vector<int> path;
    for (int now = t; now != -1; now = prev[now].to) path.emplace_back(now);

    kout << dist[t] << " " << path.size() - 1 << "\n";
    for (int i = path.size() - 1; i; --i) kout << path[i] << " " << path[i - 1] << "\n";

    return 0;
}
