#ifndef KK2_GRAPH_TWO_EDGE_CONNECTED_COMPONENTS_HPP
#define KK2_GRAPH_TWO_EDGE_CONNECTED_COMPONENTS_HPP 1

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
    void init_tecc() {
        comp.resize(this->n, -1);
        int k = 0;
        auto dfs = [&](auto self, int now, int par) -> void {
            if (par != -1 && this->ord[par] >= this->low[now]) comp[now] = comp[par];
            else comp[now] = k++;

            for (auto &&e : this->g[now])
                if (comp[e.to] == -1) self(self, e.to, now);
        };
        for (int i = 0; i < this->n; i++) 
            if (this->root[i]) dfs(dfs, i, -1);

        group.resize(k);
        for (int i = 0; i < this->n; i++) { group[comp[i]].emplace_back(i); }

        typename G::edge_container tmp(this->bridges.size());
        for (int i = 0; i < (int)this->bridges.size(); i++) {
            tmp[i] = this->g.edges[this->bridges[i]];
            tmp[i].from = comp[tmp[i].from];
            tmp[i].to = comp[tmp[i].to];
            tmp[i].id = i;
        }
        forest = G(k, tmp);
    }
};

} // namespace kk2

#endif // KK2_GRAPH_TWO_EDGE_CONNECTED_COMPONENTS_HPP
