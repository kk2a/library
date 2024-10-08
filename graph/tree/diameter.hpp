#ifndef GRAPH_TREE_DIAMETER_HPP
#define GRAPH_TREE_DIAMETER_HPP 1

#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

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
    int u = std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);
    dist[u] = 0;
    std::fill(std::begin(par), std::end(par), -1);
    dfs(dfs, u);
    int v = std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);
    std::vector<int> path;
    for (int now = v; now != -1; now = par[now]) { path.emplace_back(now); }
    return std::make_pair(dist[v], path);
}

template <class WG, typename T = typename WG::value_type>
std::pair<T, std::vector<int>> weighted_tree_diameter(const WG &g) {
    std::vector<T> dist(g.size(), -1);
    std::vector<int> par(g.size(), -1);

    auto dfs = [&](auto self, int now) -> void {
        for (auto &e : g[now]) {
            if ((int)e == par[now]) continue;
            par[(int)e] = now;
            dist[(int)e] = dist[now] + e.cost;
            self(self, (int)e);
        }
    };
    dist[0] = 0;
    dfs(dfs, 0);
    int u = std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);
    dist[u] = 0;
    std::fill(std::begin(par), std::end(par), -1);
    dfs(dfs, u);
    int v = std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);
    std::vector<int> path;
    for (int now = v; now != -1; now = par[now]) { path.emplace_back(now); }
    return std::make_pair(dist[v], path);
}

} // namespace kk2

#endif // GRAPH_TREE_DIAMETER_HPP
