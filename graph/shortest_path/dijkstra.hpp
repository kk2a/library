#ifndef KK2_GRAPH_SHORTEST_PATH_DIJKSTRA_HPP
#define KK2_GRAPH_SHORTEST_PATH_DIJKSTRA_HPP 1

#include <limits>
#include <queue>
#include <utility>
#include <vector>

namespace kk2 {

namespace shortest_path_impl {

struct dij_edge {
    int to, id;
};

template <class T>
struct dij_result {
    std::vector<T> dist;
    std::vector<dij_edge> prev;
};

template <class WG, class T = typename WG::value_type>
dij_result<T> dijkstra(const WG &g, int start, T inf = std::numeric_limits<T>::max()) {
    static_assert(WG::weighted, "dijkstra requires weighted graph");
    T alt;
    int n = g.size();
    std::vector<T> dist(n, inf);
    std::vector<dij_edge> prev(n, {-1, -1});

    std::priority_queue<std::pair<T, int>,
                        std::vector<std::pair<T, int>>,
                        std::greater<std::pair<T, int>>>
        pq;
    dist[start] = 0;
    pq.push({T(), start});

    while (!pq.empty()) {
        auto q = pq.top();
        pq.pop();
        if (dist[q.second] < q.first) continue;
        for (auto dij_edge : g[q.second]) {
            alt = q.first + dij_edge.cost;
            if (alt < dist[dij_edge.to]) {
                pq.push({alt, dij_edge.to});
                dist[dij_edge.to] = alt;
                prev[dij_edge.to] = {dij_edge.from, dij_edge.id};
            }
        }
    }

    return {dist, prev};
}

} // namespace shortest_path_impl

using shortest_path_impl::dijkstra;

} // namespace kk2

#endif // KK2_GRAPH_SHORTEST_PATH_DIJKSTRA_HPP
