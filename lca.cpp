struct LCA {
    vector<vector<int>> parent;
    vector<int> depth, perm;
    LCA(const vector<vector<int>> &g, int root) { init(g, root); }

    void init(const vector<vector<int>> &g, int root) {
        int n = g.size(), h = 1;
        while ((1 << h) < n) h++;
        parent.assign(h, vector<int>(n, -1));
        depth.assign(n, -1);
        perm.assign(n, -1);
        int p = 0;
        auto dfs = [&](auto self, int now, int pre, int d) -> void {
            perm[p++] = now;
            parent[0][now] = pre;
            depth[now] = d;
            for (auto &e : g[now]) if (e != pre) self(self, e, now, d + 1);
        };
        dfs(dfs, root, -1, 0);
        for (int i = 0; i < h - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (parent[i][j] == -1) continue;
                parent[i + 1][j] = parent[i][parent[i][j]];
            }
        }
    }

    int query(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        int h = parent.size();
        for (int i = 0; i < h; i++) {
            if ((depth[v] - depth[u]) >> i & 1) {
                v = parent[i][v];
            }
        }
        if (u == v) return u;
        for (int i = h - 1; i >= 0; i--) {
            if (parent[i][u] != parent[i][v]) {
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[query(u, v)];
    }
};
