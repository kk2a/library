#ifndef GRAPH_WARSHALL_FLOYD_HPP
#define GRAPH_WARSHALL_FLOYD_HPP 1

#include <algorithm>
#include <cassert>
#include <limits>

namespace kk2 {

template <class WG, class T = typename WG::value_type> struct WarshallFroyd {
    WG d;
    T inf = std::numeric_limits<T>::max();
    T zero = T();

    WarshallFroyd(const WG &g_) : d(g_) { init(); }

    void init() {
        assert(d.adjacency_matrix);
        int n = d.size();

        for (auto &&e : d.edges) {
            d[e.from][e.to].cost = std::min(d[e.from][e.to].cost, e.cost);
            if constexpr (!WG::directed()) {
                d[e.to][e.from].cost = std::min(d[e.to][e.from].cost, e.cost);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    d[i][j].cost = zero;
                } else if (d[i][j].id == -1) {
                    d[i][j].cost = inf;
                }
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (d[i][k].cost == inf || d[k][j].cost == inf) continue;
                    d[i][j].cost = std::min(d[i][j].cost, d[i][k].cost + d[k][j].cost);
                }
            }
        }
    }

    T operator()(int i, int j) const { return d[i][j].cost == inf ? -1 : d[i][j].cost; }
};

} // namespace kk2

#endif // GRAPH_WARSHALL_FLOYD_HPP
