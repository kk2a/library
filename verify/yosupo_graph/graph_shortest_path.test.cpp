#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../../graph/graph.hpp"
#include "../../graph/shortest_path.hpp"
#include "../../template/template.hpp"
using namespace std;

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    kk2::DWAdjList<i64> g(n, m, false);
    g.input(cin);
    auto [dist, prev] = kk2::ShortestPath(g, s);

    if (prev[t].to == -1) {
        cout << -1 << "\n";
        return 0;
    }

    std::vector<int> path;
    for (int now = t; now != -1; now = prev[now].to) path.emplace_back(now);

    cout << dist[t] << " " << path.size() - 1 << "\n";
    for (int i = path.size() - 1; i; --i) cout << path[i] << " " << path[i - 1] << "\n";

    return 0;
}
