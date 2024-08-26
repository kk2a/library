#ifndef GRAPH_TREE_DIAMETER_HPP
#define GRAPH_TREE_DIAMETER_HPP 1

#include "../shortest_path.hpp"

namespace kk2 {

template <class G>
pair<int, vector<int>> tree_diameter(const G& g) {
    vector<int> dist(g.size(), -1), par(g.size(), -1);
    auto dfs = [&](auto self, int now) -> void {
        for (auto& e : g[now]) {
            if ((int)e == par[now]) continue;
            par[(int)e] = now;
            dist[(int)e] = dist[now] + 1;
            self(self, (int)e);
        }
    };
    dist[0] = 0;
    dfs(dfs, 0);
    int u = max_element(begin(dist), end(dist)) - begin(dist);
    dist[u] = 0;
    fill(begin(par), end(par), -1);
    dfs(dfs, u);
    int v = max_element(begin(dist), end(dist)) - begin(dist);
    vector<int> path;
    for (int now = v; now != -1; now = par[now]) {
        path.emplace_back(now);
    }
    return make_pair(dist[v], path);
}

template <class WG, typename T = typename WG::value_type>
pair<T, vector<int>> weighted_tree_diameter(const WG& g) {
    auto sp = ShortestPath<WG, T>(g);
    auto [dist, _] = sp.query(0);
    int u = max_element(begin(dist), end(dist)) - begin(dist);
    auto [dist2, par] = sp.query(u);
    int v = max_element(begin(dist2), end(dist2)) - begin(dist2);
    vector<int> path;
    for (int now = v;;) {
        path.emplace_back(now);
        if (par[now] == -1) break;
        now = g.edges[par[now]].to ^ g.edges[par[now]].from ^ now;
    }
    return make_pair(dist2[v], path);
}

} // namespace kk2

#endif // GRAPH_TREE_DIAMETER_HPP
