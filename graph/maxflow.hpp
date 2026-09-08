#ifndef KK2_GRAPH_MAXFLOW_HPP
#define KK2_GRAPH_MAXFLOW_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <limits>
#include <numeric>
#include <queue>
#include <ranges>
#include <vector>

#include "../type_traits/graph.hpp"

namespace kk2 {

template <class Cap> struct MaxFlowGraph {
    struct arc {
        int to, rev;
        Cap cap;
    };
    struct edge {
        int from, to, index;
    };

    std::vector<std::vector<arc>> data;
    std::vector<edge> edges;

    MaxFlowGraph() = default;
    explicit MaxFlowGraph(int n) : data(n) {}

    template <class E>
        requires graph::WeightedEdgeRange<const E>
    MaxFlowGraph(int n, const E &input) : data(n) {
        if constexpr (std::ranges::sized_range<const E>) {
            edges.reserve(std::ranges::size(input));
        }
        if constexpr (std::ranges::forward_range<const E>) {
            std::vector<int> degree(n);
            for (const auto &e : input) {
                ++degree[e.from];
                ++degree[e.to];
            }
            for (int v = 0; v < n; ++v) data[v].reserve(degree[v]);
        }
        for (const auto &e : input) add_edge(e.from, e.to, e.cost);
    }

    void add_edge(int from, int to, Cap cap) {
        const int index = data[from].size();
        data[from].push_back({to, -1, cap});
        const int rev = data[to].size();
        data[to].push_back({from, index, Cap(0)});
        data[from][index].rev = rev;
        edges.push_back({from, to, index});
    }
};

template <graph::WeightedDirectedGraph WG> struct MaxFlow {

    using Cap = typename WG::value_type;
    using graph_type = MaxFlowGraph<Cap>;

    graph_type g;
    int n, m;

    MaxFlow(const WG &g_) : g(g_.num_vertices(), g_.edges), n(g_.num_vertices()), m(g_.num_edges()) {}

    template <class Edges_>
        requires graph::WeightedEdgeRange<const Edges_>
    MaxFlow(int n_, const Edges_ &edges) : g(n_, edges), n(n_), m(g.edges.size()) {}

    Cap flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max()); }

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
                for (const auto &e : g.data[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == t) return up;
            Cap res = 0;
            for (int &i = iter[v]; i < (int)g.data[v].size(); i++) {
                auto &e = g.data[v][i];
                if (e.cap == 0 || level[e.to] != level[v] + 1) continue;
                Cap d = self(self, e.to, std::min(up - res, e.cap));
                if (d <= 0) continue;
                e.cap -= d;
                g.data[e.to][e.rev].cap += d;
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
                Cap f = dfs(dfs, s, flow_limit - flow);
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
            for (const auto &e : g.data[p]) {
                if (e.cap && !visited[e.to]) {
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
        const auto &e = g.edges[i];
        const auto &forward = g.data[e.from][e.index];
        const auto &reverse = g.data[forward.to][forward.rev];
        return edge{e.from, e.to, forward.cap + reverse.cap, reverse.cap};
    }

    std::vector<edge> get_edges() {
        std::vector<edge> result(m);
        for (int i = 0; i < m; i++) { result[i] = get_edge(i); }
        return result;
    }
};

} // namespace kk2

#endif // KK2_GRAPH_MAXFLOW_HPP
