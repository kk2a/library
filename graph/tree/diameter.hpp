#ifndef KK2_GRAPH_TREE_DIAMETER_HPP
#define KK2_GRAPH_TREE_DIAMETER_HPP 1

#include <algorithm>
#include <functional>
#include <type_traits>
#include <utility>
#include <vector>

namespace kk2 {

namespace tree_diameter_impl {

template <class G> struct result {
    std::conditional_t<G::weighted::value, typename G::value_type, int> diameter;
    std::vector<int> path;
};

template <class G, std::enable_if_t<!G::weighted::value> * = nullptr>
result<G> tree_diameter(const G &g) {
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
    return {dist[v], path};
}

template <class G, std::enable_if_t<G::weighted::value> * = nullptr>
result<G> tree_diameter(const G &g) {
    using T = typename G::value_type;
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
    return {dist[v], path};
}

} // namespace tree_diameter_impl

using tree_diameter_impl::tree_diameter;

} // namespace kk2

#endif // KK2_GRAPH_TREE_DIAMETER_HPP
