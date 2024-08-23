#ifndef GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP
#define GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP 1

template <typename G>
struct HeavyLightDecomposition {
    G& g;
    int root, id;
    vector<int> sz, in, out, head, par, dep;
    HeavyLightDecomposition(G& g_, int root_ = 0) 
        : g(g_),
          root(root_),
          id(0),
          sz(g.size(), 0),
          in(g.size(), -1),
          out(g.size(), -1),
          head(g.size(), root),
          par(g.size(), root),
          dep(g.size(), 0) {
        init();
    }

    int lca(int u, int v) const {
        while (head[u] != head[v]) {
            if (in[u] < in[v]) swap(u, v);
            u = par[head[u]];
        }
        return dep[u] < dep[v] ? u : v;
    }

    int dist(int u, int v) const {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

  private:
    void init() {
        auto dfs_sz = [&](auto self, int now) -> void {
            sz[now] = 1;
            for (auto& e : g[now]) {
                if ((int)e == par[now]) {
                    if (g[now].size() >= 2 and e == g[now][0])
                        swap(e, g[now][1]);
                    else 
                        continue;
                }
                par[(int)e] = now;
                dep[(int)e] = dep[now] + 1;
                self(self, (int)e);
                sz[now] += sz[(int)e];
                if (sz[(int)e] > sz[(int)g[now][0]])
                    swap(e, g[now][0]);
            }
        };
        dfs_sz(dfs_sz, root);

        auto dfs_hld = [&](auto self, int now) -> void {
            in[now] = id++;
            for (auto& e : g[now]) {
                if ((int)e == par[now]) continue;
                head[(int)e] = ((int)e == (int)g[now][0] ? head[now] : (int)e);
                self(self, (int)e);
            }
            out[now] = id;
        };
        dfs_hld(dfs_hld, root);
    }
};

#endif // GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP
