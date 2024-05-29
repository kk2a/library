#ifndef GRAPH_DIJKSTRA_HPP
#define GRAPH_DIJKSTRA_HPP 1

template <class T> struct dij_graph {
  public:
    dij_graph(int n) : _n(n), graph(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to, T weight) {
        graph[from].push_back({weight, to});
    } 

    pair<vector<T>, vector<int>> query(const int& start,
                                          const T& e,
                                          const T& inf) {
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
            for (auto v : graph[q.second]) {
                alt = q.first + v.first;
                if (alt < dist[v.second]) {
                    pq.push( {alt, v.second} );
                    dist[v.second] = alt;
                    prev[v.second] = q.second; 
                }
            }
        }

        return {dist, prev};
    }
    
  private:
    int _n;
    vector<vector<pair<T, int>>> graph;
};

#endif // GRAPH_DIJKSTRA_HPP
