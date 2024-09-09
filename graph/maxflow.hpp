#ifndef GRAPH_MAXFLOW_HPP
#define GRAPH_MAXFLOW_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <numeric>
#include <limits>
#include <queue>
#include <vector>

namespace kk2 {

template <class WG>
struct MaxFlow {
    static_assert(WG::directed(), "Directed graph required.");

    using Cap = typename WG::value_type;

    const WG& g;
    int n, m;
    std::vector<int> revi;

    MaxFlow(const WG &g_) : g(g_), n(g.num_vertices()),
                            m(g.num_edges()) { init(); }

    void init() {
        revi.resize(m << 1, -1);
        std::vector<int> count(n, 0);
        for (int i = 0; i < m; i++) {
            auto e = g.edges[i];
            revi[i] = (int)g[e.to].size();
            revi[m + i] = count[e.from]++;
            g.add_edge_naive(e.to, e.from, 0);
        }
    } 

    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }

    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < n);
        assert(0 <= t && t < n);
        assert(s != t);

        std::vector<int> level(n), iter(n);
        std::queue<int> que;

        auto bfs = [&]() {
            std::fill(std::begin(level), std::end(level), -1);
            level[s] = 0;
            que = std::queue<int>();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto &e : g[v]) {
                    if (e.cost == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            for (int &i = iter[v]; i < (int)g[v].size(); i++) {
                auto &e = g[v][i];
                if (level[v] <= level[e.to] || g[e.to][revi[e.id]].cost == 0) continue;
                Cap d =
                    self(self, e.to,
                         std::min(up - res, g[e.to][revi[e.id]].cost));
                if (d <= 0) continue;
                g[v][i].cost += d;
                g[e.to][revi[e.id]].cost -= d;
                res += d;
                if (res == up) break;
            }
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(std::begin(iter), std::end(iter), 0);
            while (flow < flow_limit) {
                Cap f = dfs(dfs, t, flow_limit - flow);
                if (!f) break;
                flow += f;
            }
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(n);
        std::queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto &e : g[p]) {
                if (e.cost && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        auto e = g.edges[i];
        return edge{e.from, e.to, e.cost + g[e.to][revi[i]].cost,
                    g[e.to][revi[i]].cost};
    }

    std::vector<edge> get_edges() {
        std::vector<edge> result(m);
        for (int i = 0; i < m; i++) {
            result[i] = get_edge(i);
        }
        return result;
    }
};

} // namespace kk2

#endif // GRAPH_MAXFLOW_HPP
