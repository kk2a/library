#ifndef KK2_GRAPH_LOWLINK_HPP
#define KK2_GRAPH_LOWLINK_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <type_traits>
#include <vector>

namespace kk2 {

template <class G> struct LowLink {
    static_assert(!G::directed::value, "LowLink requires undirected graph");

    int n, m;
    const G &g;
    std::vector<int> ord, low;
    std::vector<bool> root, used_on_dfs_tree;
    std::vector<int> bridges, articulations;

    LowLink(const G &g_)
        : n(g_.num_vertices()),
          m(g_.num_edges()),
          g(g_),
          ord(n, -1),
          low(n, -1),
          root(n, false),
          used_on_dfs_tree(m, false) {
        init();
    }

  private:
    // v is a child of u in DFS tree
    // edge(u, v) is a bridge <=> ord[u] < low[v]

    // u is an articulation point <=> (u is root and u has two or more children) or
    // there exists a v which is a child of u in DFS tree and ord[u] <= low[v]

    void init() {
        int k = 0;
        auto dfs = [&](auto self, int u, int ei = -1) -> int {
            low[u] = ord[u] = k++;
            bool is_articulation = false;
            int count = 0;
            for (auto &&e : g[u]) {
                if (e.id == ei) continue;
                if (ord[e.to] == -1) {
                    ++count;
                    used_on_dfs_tree[e.id] = true;
                    low[u] = std::min(low[u], self(self, e.to, e.id));
                    if (ei != -1 and ord[u] <= low[e.to]) is_articulation = true;
                    if (ord[u] < low[e.to]) bridges.emplace_back(e.id);
                }
                // back edge
                else if (ord[e.to] < ord[u]) {
                    low[u] = std::min(low[u], ord[e.to]);
                }
            }
            if (ei == -1 and count >= 2) is_articulation = true;
            if (is_articulation) articulations.emplace_back(u);
            return low[u];
        };
        for (int u = 0; u < n; u++)
            if (ord[u] == -1) {
                dfs(dfs, u);
                root[u] = true;
            }
    }
};

} // namespace kk2

#endif // KK2_GRAPH_LOWLINK_HPP
