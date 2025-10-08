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
    static_assert(!G::directed, "EulerTour requires undirected graph");

    const G &g;
    int id;
    std::vector<int> in, out, par;

    EulerTour(const G &g_, int root = 0)
        : g(g_),
          id(0),
          in(g.size(), -1),
          out(g.size(), -1),
          par(g.size(), -1) {
        init(root);
    }

    std::pair<int, int> get_edge_idx(int i) const {
        if (par[i] == -1) return {-1, -1};
        return {in[i], out[i]};
    }

    std::pair<int, int> get_node_idx(int u) const { return {in[u], out[u]}; }

    int lca(int u, int v) const {
        if (in[u] > in[v]) std::swap(u, v);
        return rmq.prod(in[u], in[v] + 1).a.second;
    }

    int dist(int u, int v) const {
        int depu = rmq.get(in[u]).a.first;
        int depv = rmq.get(in[v]).a.first;
        return depu + depv - 2 * rmq.get(in[lca(u, v)]).a.first;
    }

    template <typename F> void path_query(int u, int v, bool is_node_query, const F &f) {
        int l = lca(u, v);
        f(in[l] + (int)!is_node_query, in[u] + 1);
        f(in[l] + 1, in[v] + 1);
    }

    template <typename F>
    void path_noncommutative_query(int u, int v, bool is_node_query, const F &f) {
        int l = lca(u, v);
        f(in[u] + 1, in[l] + (int)!is_node_query);
        f(in[l] + 1, in[v] + 1);
    }

    template <typename F> void subtree_query(int u, bool is_node_query, const F &f) {
        f(in[u] + (int)!is_node_query, out[u]);
    }

  private:
    StaticRMQ<std::pair<int, int>> rmq;

    void init(int root) {
        using Monoid = typename decltype(rmq)::Monoid;
        std::vector<Monoid> rmq_init(2 * g.size());
        auto dfs = [&](auto self, int now, int pre, int dep) -> void {
            in[now] = id;
            rmq_init[id++] = Monoid({dep, now});
            for (auto &&e : g[now]) {
                if ((int)e == pre) continue;
                par[(int)e] = now;
                self(self, e, now, dep + 1);
            }
            rmq_init[id] = Monoid({dep - 1, pre});
            out[now] = id++;
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
