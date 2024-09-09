#ifndef GRAPH_TREE_DIAMETER_HPP
#define GRAPH_TREE_DIAMETER_HPP 1

#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

#include "../shortest_path.hpp"

namespace kk2 {

template <class G> std::pair<int, std::vector<int>> tree_diameter(const G &g) {
    std::vector<int> dist(g.size(), -1), par(g.size(), -1);
    auto dfs = [&](auto self, int now) -> void {
        for (auto &e : g[now]) {
            if ((int)e == par[now]) continue;
            par[(int)e] = now;
            dist[(int)e] = dist[now] + 1;
            self(self, (int)e);
        }
    };
    dist[0] = 0;
    dfs(dfs, 0);
    int u =
        std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);
    dist[u] = 0;
    std::fill(std::begin(par), std::end(par), -1);
    dfs(dfs, u);
    int v =
        std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);
    std::vector<int> path;
    for (int now = v; now != -1; now = par[now]) { path.emplace_back(now); }
    return std::make_pair(dist[v], path);
}

template <class WG, typename T = typename WG::value_type>
std::pair<T, std::vector<int>> weighted_tree_diameter(const WG &g) {
    auto sp = ShortestPath<WG, T>(g);
    auto [dist, _] = sp.query(0);
    int u =
        std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);
    auto [dist2, par] = sp.query(u);
    int v = std::max_element(std::begin(dist2), std::end(dist2))
            - std::begin(dist2);
    std::vector<int> path;
    for (int now = v;;) {
        path.emplace_back(now);
        if (par[now] == -1) break;
        now = g.edges[par[now]].to ^ g.edges[par[now]].from ^ now;
    }
    return std::make_pair(dist2[v], path);
}

} // namespace kk2

#endif // GRAPH_TREE_DIAMETER_HPP
