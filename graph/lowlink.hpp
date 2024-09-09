#ifndef GRAPH_LOWLINK_HPP
#define GRAPH_LOWLINK_HPP 1

#include <algorithm>
#include <functional>
#include <vector>

namespace kk2 {

template <class G> struct LowLink {
    int n, m;
    const G &g;
    std::vector<int> ord, low;
    std::vector<bool> root, used;

    LowLink(const G &g_)
        : n(g_.n),
          m(g_.m),
          g(g_),
          ord(n, -1),
          low(n, -1),
          root(n, false),
          used(m, false) {
        init();
    }

  private:
    void init() {
        int k = 0;
        auto dfs = [&](auto self, int u, int ei = -1) -> int {
            low[u] = ord[u] = k++;
            for (auto &e : g[u]) {
                if (e.id == ei) continue;
                if (ord[e.to] == -1) {
                    used[e.id] = true;
                    low[u] = std::min(low[u], self(self, e.to, e.id));
                }
                // back edge
                else if (ord[e.to] < ord[u]) {
                    low[u] = std::min(low[u], ord[e.to]);
                }
            }
            return low[u];
        };
        for (int u = 0; u < n; u++)
            if (ord[u] == -1) {
                dfs(dfs, u);
                root[u] = true;
            }
    }
};

} // namespace kk2

#endif // GRAPH_LOWLINK_HPP
