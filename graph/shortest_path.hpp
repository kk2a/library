#ifndef GRAPH_DIJKSTRA_HPP
#define GRAPH_DIJKSTRA_HPP 1

#include <limits>
#include <queue>
#include <utility>
#include <vector>

namespace kk2 {

namespace shortest_path_impl {

struct edge {
    int to, id;
};

template <class T>
struct Result {
    std::vector<T> dist;
    std::vector<edge> prev;
};

template <class WG, class T = typename WG::value_type> 
Result<T> shortest_path(const WG &g, int start, T inf = std::numeric_limits<T>::max()) {
    static_assert(WG::weighted::value, "shortest_path requires weighted graph");
    T alt;
    int n = g.size();
    std::vector<T> dist(n, inf);
    std::vector<edge> prev(n, {-1, -1});

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
        for (auto edge : g[q.second]) {
            alt = q.first + edge.cost;
            if (alt < dist[edge.to]) {
                pq.push({alt, edge.to});
                dist[edge.to] = alt;
                prev[edge.to] = {edge.from, edge.id};
            }
        }
    }

    return {dist, prev};
}

} // namespace shortest_path_impl

using shortest_path_impl::shortest_path;

} // namespace kk2

#endif // GRAPH_DIJKSTRA_HPP
