#ifndef GRAPH_TREE_CENTROID_DECOMPOSITION_HPP
#define GRAPH_TREE_CENTROID_DECOMPOSITION_HPP 1

#include <vector>

namespace kk2 {

template <class G> struct CentroidDecomposition {
    const G &g;
    std::vector<int> parent;
    std::vector<int> subsize;
    std::vector<bool> used;
    std::vector<std::vector<int>> children;
    int root;

    CentroidDecomposition(const G &g_, bool isbuild = true)
        : g(g_),
          parent(g.size(), -1),
          subsize(g.size(), 0),
          used(g.size(), false),
          children(g.size()) {
        if (isbuild) build();
    }

    void build() {
        root = build_dfs(0);
    }

    int get_size(int now, int par) {
        subsize[now] = 1;
        for (auto &e : g[now]) {
            if (e.to == par or used[e.to]) continue;
            subsize[now] += get_size(e.to, now);
        }
        return subsize[now];
    }

    int get_centroid(int now, int par, int mid) {
        for (auto &e : g[now]) {
            if (e.to == par or used[e.to]) continue;
            if (subsize[e.to] > mid) return get_centroid(e.to, now, mid);
        }
        return now;
    }

    int build_dfs(int v) {
        int centroid = get_centroid(v, -1, get_size(v, -1) / 2);
        used[centroid] = true;
        for (auto &e : g[centroid]) {
            if (used[e.to]) continue;
            int nxt = build_dfs(e.to);
            if (centroid != nxt) {
                children[centroid].emplace_back(nxt);
                parent[nxt] = centroid;
            }
        }
        used[centroid] = false;
        return centroid;
    }
};

} // namespace kk2

#endif // GRAPH_TREE_CENTROID_DECOMPOSITION_HPP
