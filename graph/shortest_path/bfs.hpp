#ifndef KK2_GRAPH_SHORTEST_PATH_BFS_HPP
#define KK2_GRAPH_SHORTEST_PATH_BFS_HPP 1

#include <queue>
#include <type_traits>
#include <vector>

namespace kk2 {

template <class G, std::enable_if_t<!G::weighted> * = nullptr>
void bfs(queue &q, std::vector<int> &dist, int init) {
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto e : g[now]) {
            if (dist[e.to] != init) continue;
            dist[e.to] = dist[now] + 1;
            q.push(e.to);
        }
    }
}

template <class G, std::enable_if_t<G::weighted> * = nullptr>
void bfs(queue &q, std::vector<G::value_type> &dist, G::value_type init) {
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto e : g[now]) {
            if (dist[e.to] != init) continue;
            dist[e.to] = dist[now] + e.cost;
            q.push(e.to);
        }
    }
}

} // namespace kk2

#endif // KK2_GRAPH_SHORTEST_PATH_BFS_HPP
