#ifndef GRAPH_TWO_EDGE_CONNECTED_COMPONENTS_HPP
#define GRAPH_TWO_EDGE_CONNECTED_COMPONENTS_HPP 1

#include <vector>

#include "lowlink.hpp"

namespace kk2 {

template <class G> struct TwoEdgeConnectedComponents : LowLink<G> {
    TwoEdgeConnectedComponents(const G &g_) : LowLink<G>(g_) { init_tecc(); }

    std::vector<int> comp;
    std::vector<std::vector<int>> group;
    G forest;

    int size() const { return group.size(); }

  private:
    // v is a child of u in DFS tree
    // edge(u, v) is a bridge <=> ord[u] < low[v]
    void init_tecc() {
        comp.resize(this->n, -1);
        int k = 0;
        std::vector<typename G::edge_type> bridges;
        auto dfs = [&](auto self, int now, int par, int ei) -> void {
            if (par != -1 && this->ord[par] >= this->low[now]) comp[now] = comp[par];
            else {
                comp[now] = k++;
                if (par != -1) bridges.emplace_back((this->g).edges[ei]);
            }
            for (auto &&e : this->g[now]) {
                if (comp[e.to] == -1) self(self, e.to, now, e.id);
            }
        };
        for (int i = 0; i < this->n; i++) {
            if (this->root[i]) dfs(dfs, i, -1, -1);
        }
        group.resize(k);
        for (int i = 0; i < this->n; i++) { group[comp[i]].emplace_back(i); }
        for (auto &&e : bridges) {
            e.from = comp[e.from];
            e.to = comp[e.to];
        }
        forest = G(k, bridges, this->g.oneindexed);
    }
};

} // namespace kk2

#endif // GRAPH_TWO_EDGE_CONNECTED_COMPONENTS_HPP
