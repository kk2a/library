#ifndef GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP
#define GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP 1

#include <cassert>
#include <functional>
#include <utility>
#include <vector>

namespace kk2 {

template <typename G> struct HeavyLightDecomposition {
    static_assert(!G::directed::value, "HeavyLightDecomposition requires undirected graph");

    G &g;
    int root, id;
    std::vector<int> sz, in, out, head, par, dep, edge_idx;

    // e.idはedgesのindexでないといけない
    HeavyLightDecomposition(G &g_, int root_ = 0)
        : g(g_),
          root(root_),
          id(0),
          sz(g.size(), 0),
          in(g.size(), -1),
          out(g.size(), -1),
          head(g.size(), root),
          par(g.size(), root),
          dep(g.size(), 0),
          edge_idx(g.size() - 1, -1) {
        init();
    }

    int get_edge_idx(int i) const { return edge_idx[i]; }

    std::pair<int, int> get_node_idx(int u) const { return std::make_pair(in[u], out[u]); }

    template <typename F> void path_query(int u, int v, bool is_node_query, const F &f) {
        int l = lca(u, v);
        for (auto &[a, b] : ascend(u, l)) {
            int s = a + 1, t = b;
            s > t ? f(t, s) : f(s, t);
        }
        if (is_node_query) f(in[l], in[l] + 1);
        for (auto &[a, b] : descend(l, v)) {
            int s = a, t = b + 1;
            s > t ? f(t, s) : f(s, t);
        }
    }

    template <typename F>
    void path_noncommutative_query(int u, int v, bool is_node_query, const F &f) {
        int l = lca(u, v);
        for (auto &[a, b] : ascend(u, l)) f(a + 1, b);
        if (is_node_query) f(in[l], in[l] + 1);
        for (auto &[a, b] : descend(l, v)) f(a, b + 1);
    }

    template <typename F> void subtree_query(int u, bool is_vertex_query, const F &f) {
        f(in[u] + (int)!is_vertex_query, out[u]);
    }

    int lca(int u, int v) const {
        while (head[u] != head[v]) {
            if (in[u] < in[v]) std::swap(u, v);
            u = par[head[u]];
        }
        return dep[u] < dep[v] ? u : v;
    }

    int dist(int u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }

  private:
    void init() {
        auto dfs_sz = [&](auto self, int now) -> void {
            sz[now] = 1;
            for (auto &e : g[now]) {
                if ((int)e == par[now]) {
                    if (g[now].size() >= 2 and e == g[now][0]) std::swap(e, g[now][1]);
                    else continue;
                }
                par[(int)e] = now;
                dep[(int)e] = dep[now] + 1;
                self(self, (int)e);
                sz[now] += sz[(int)e];
                if (sz[(int)e] > sz[(int)g[now][0]]) std::swap(e, g[now][0]);
            }
        };
        dfs_sz(dfs_sz, root);

        auto dfs_hld = [&](auto self, int now) -> void {
            in[now] = id++;
            for (auto &e : g[now]) {
                if ((int)e == par[now]) continue;
                head[(int)e] = ((int)e == (int)g[now][0] ? head[now] : (int)e);
                edge_idx[e.id] = id;
                self(self, (int)e);
            }
            out[now] = id;
        };
        dfs_hld(dfs_hld, root);
    }

    // [u, v)
    std::vector<std::pair<int, int>> ascend(int u, int v) const {
        std::vector<std::pair<int, int>> res;
        while (head[u] != head[v]) {
            res.emplace_back(in[u], in[head[u]]);
            u = par[head[u]];
        }
        if (u != v) res.emplace_back(in[u], in[v] + 1);
        return res;
    }

    // (u, v]
    std::vector<std::pair<int, int>> descend(int u, int v) const {
        if (u == v) return {};
        if (head[u] == head[v]) return {std::make_pair(in[u] + 1, in[v])};
        auto res = descend(u, par[head[v]]);
        res.emplace_back(in[head[v]], in[v]);
        return res;
    }
};

} // namespace kk2

#endif // GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP
