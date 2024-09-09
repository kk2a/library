#ifndef CENTROID_HPP
#define CENTROID_HPP 1

#include <cassert>
#include <functional>
#include <numeric>
#include <vector>

namespace kk2 {

template <class G>
int centroid(const G& g) {
    int n = g.size();
    std::vector<int> sz(n, 0);
    auto dfs = [&](auto &&self, int u, int p = -1) -> int {
        sz[u] = 1;
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
            if (sz[v] > n / 2) is_centroid = false;
        }
        if ((n - sz[u]) > n / 2) is_centroid = false;
        return is_centroid ? u : -1;
    };
    return find(find, 0);
}

template <class G>
int centroid(const G& g, const std::vector<long long>& weight) {
    assert((int)g.size() == (int)weight.size());
    int n = g.size();
    std::vector<long long> sz(n, 0);
    long long sum = std::accumulate(std::begin(weight), std::end(weight), 0LL);
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
    return find(find, 0);
}

} // namespace kk2

#endif // CENTROID_HPP
