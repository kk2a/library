#ifndef GRAPH_DIJKSTRA_HPP
#define GRAPH_DIJKSTRA_HPP 1

template <class WG, class T = typename WG::value_type>
struct Dijkstra {
  public:
    Dijkstra(const WG& g) : _n(g.num_vertices()), _g(g) {}

    int num_vertices() { return _n; }

    pair<vector<T>, vector<int>> query(
        int start, T e = _ZERO, T inf = _INF) {
        T alt;
        vector<T> dist(_n, inf);
        vector<int> prev(_n, -1);
        dist[start] = e;

        priority_queue<pair<T, int>,
                       vector<pair<T, int>>,
                       greater<pair<T, int>>> pq;
        pq.push({e, start});

        while (!pq.empty()) {
            auto q = pq.top(); pq.pop();
            if (dist[q.second] < q.first) continue;
            for (auto edge : _g[q.second]) {
                alt = q.first + edge.cost;
                if (alt < dist[edge.to]) {
                    pq.push( {alt, edge.to} );
                    dist[edge.to] = alt;
                    prev[edge.to] = q.second; 
                }
            }
        }

        return {dist, prev};
    }

  private:
    int _n;
    const WG& _g;
    constexpr static T _INF = numeric_limits<T>::max();
    constexpr static T _ZERO = T(0);
};

#endif // GRAPH_DIJKSTRA_HPP
