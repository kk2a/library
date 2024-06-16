#ifndef CENTROID_HPP
#define CENTROID_HPP 1

template <class G>
int centroid(const G& g, vector<long long> weight = {}) {
    if (weight.empty()) weight.assign(g.size(), 1);
    assert((int)g.size() == (int)weight.size());
    int n = g.size();
    vector<long long> sz(n, 0);
    long long sum = accumulate(begin(weight), end(weight), 0LL);
    auto dfs = [&](auto &&self, int u, int p = -1) -> long long {
        sz[u] = weight[u];
        for (int v : g[u]) if (v != p) {
            sz[u] += self(self, v, u);
        }
        return sz[u];
    };
    dfs(dfs, 0);

    auto find = [&](auto &&self, int u, int p = -1) -> int {
        bool is_centroid = true;
        for (int v : g[u]) if (v != p) {
            int ret = self(self, v, u);
            if (ret != -1) return ret;
            if (sz[v] > sum / 2) is_centroid = false;
        }
        if ((sum - sz[u]) > sum / 2) is_centroid = false;
        return is_centroid ? u : -1;
    };
    int res = find(find, 0);
    return res;
}

#endif // CENTROID_HPP
