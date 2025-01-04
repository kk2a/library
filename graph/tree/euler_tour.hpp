#ifndef KK2_GRAPH_TREE_EULER_TOUR_HPP
#define KK2_GRAPH_TREE_EULER_TOUR_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <utility>
#include <vector>

#include "../../data_structure/static_rmq.hpp"

namespace kk2 {

template <typename G> struct EulerTour {
    static_assert(!G::directed::value, "EulerTour requires undirected graph");

    const G &g;
    int root, id;
    std::vector<int> in, out, par;
    std::vector<int> edge_in, edge_out;

    EulerTour(const G &g_, int root_ = 0)
        : g(g_),
          root(root_),
          id(0),
          in(g.size(), -1),
          out(g.size(), -1),
          par(g.size(), root),
          edge_in(g.size() - 1, -1),
          edge_out(g.size() - 1, -1) {
        init();
    }

    std::pair<int, int> get_edge_idx(int i) const {
        return std::make_pair(edge_in[i], edge_out[i]);
    }

    std::pair<int, int> get_node_idx(int u) const { return std::make_pair(in[u], out[u]); }

    int lca(int u, int v) const {
        if (in[u] > in[v]) std::swap(u, v);
        return std::pair<int, int>(rmq.prod(in[u], in[v] + 1)).second;
    }

    int dist(int u, int v) const {
        int depu = std::pair<int, int>(rmq.get(in[u])).first;
        int depv = std::pair<int, int>(rmq.get(in[v])).first;
        return depu + depv - 2 * std::pair<int, int>(rmq.get(in[lca(u, v)])).first;
    }

    template <typename F> void path_query(int u, int v, bool is_node_query, const F &f) {
        int l = lca(u, v);
        f(in[l] + (int)!is_node_query, in[u] + 1);
        f(in[l] + 1, in[v] + 1);
    }

    template <typename F> void subtree_query(int u, bool is_node_query, const F &f) {
        f(in[u] + (int)!is_node_query, out[u]);
    }

  private:
    StaticRMQ<std::pair<int, int>> rmq;

    void init() {
        auto rmq_init = GetVecMin<std::pair<int, int>>(2 * g.size());
        auto dfs = [&](auto self, int now, int pre, int dep) -> void {
            in[now] = id;
            rmq_init[id++] = {dep, now};
            for (auto &&e : g[now]) {
                if ((int)e == pre) continue;
                par[(int)e] = now;
                edge_in[e.id] = id;
                self(self, e, now, dep + 1);
                edge_out[e.id] = id++;
            }
            out[now] = id;
            rmq_init[id] = {dep - 1, pre};
        };
        dfs(dfs, root, -1, 0);
        for (int i = 0; i < (int)g.size(); i++) {
            if (in[i] == -1) dfs(dfs, i, -1, 0);
        }
        rmq = StaticRMQ<std::pair<int, int>>(rmq_init);
    }
};

} // namespace kk2

#endif // KK2_GRAPH_TREE_EULER_TOUR_HPP
