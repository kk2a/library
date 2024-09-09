#ifndef GRAPH_DIJKSTRA_HPP
#define GRAPH_DIJKSTRA_HPP 1

#include <limits>
#include <utility>
#include <vector>
#include <queue>

namespace kk2 {

template <class WG, class T = typename WG::value_type>
struct ShortestPath {
  public:
    ShortestPath(const WG& g) : _n(g.size()), _g(g) {}

    int num_vertices() { return _n; }

    std::pair<std::vector<T>, std::vector<int>> query(
        int start, T e = _ZERO, T inf = _INF) {
        T alt;
        std::vector<T> dist(_n, inf);
        std::vector<int> prev(_n, -1);
        dist[start] = e;

        std::priority_queue<std::pair<T, int>,
                            std::vector<std::pair<T, int>>,
                            std::greater<std::pair<T, int>>> pq;
        pq.push({e, start});

        while (!pq.empty()) {
            auto q = pq.top(); pq.pop();
            if (dist[q.second] < q.first) continue;
            for (auto edge : _g[q.second]) {
                alt = q.first + edge.cost;
                if (alt < dist[edge.to]) {
                    pq.push( {alt, edge.to} );
                    dist[edge.to] = alt;
                    prev[edge.to] = edge.id;
                }
            }
        }

        return {dist, prev};
    }

  private:
    int _n;
    const WG& _g;
    constexpr static T _INF = std::numeric_limits<T>::max();
    constexpr static T _ZERO = T();
};

} // namespace kk2

#endif // GRAPH_DIJKSTRA_HPP
