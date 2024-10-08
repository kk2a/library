#ifndef GRAPH_DIJKSTRA_HPP
#define GRAPH_DIJKSTRA_HPP 1

#include <limits>
#include <queue>
#include <utility>
#include <vector>

namespace kk2 {

namespace shortest_path {

struct edge {
    int to, id;
};

template <class T>
struct Result {
    std::vector<T> dist;
    std::vector<edge> prev;
    Result(std::vector<T> dist_, std::vector<edge> prev_)
        : dist(dist_), prev(prev_) {}
};

template <class WG, class T = typename WG::value_type> 
Result<T> ShortestPath(const WG &g, int start) {
    T alt;
    int n = g.size();
    std::vector<T> dist(n, std::numeric_limits<T>::max());
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

} // namespace shortest_path

using shortest_path::ShortestPath;

} // namespace kk2

#endif // GRAPH_DIJKSTRA_HPP
