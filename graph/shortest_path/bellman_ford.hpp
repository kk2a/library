#ifndef KK2_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP
#define KK2_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP 1

#include <limits>
#include <vector>

namespace kk2 {

namespace shortest_path_impl {

template <class T> struct bf_edge {
    int to, id;
};

template <class T> struct bf_len {
    T len;
    bool inf, minf;

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    void debug_output(OStream &os) const {
        if (minf) os << "MINF";
        else if (inf) os << "INF";
        else os << len;
    }
};

template <class T> struct bf_result {
    std::vector<bf_len<T>> dist;
    std::vector<bf_edge<T>> prev;
};

template <class WG, class T = typename WG::value_type>
bf_result<T> bellman_ford(const WG &g, int start) {
    static_assert(WG::weighted, "bellman_ford requires weighted graph");
    static_assert(WG::directed, "bellman_ford requires directed graph");

    std::vector<bf_len<T>> dist(g.num_vertices(), {0, true, false});
    std::vector<bf_edge<T>> prev(g.num_vertices(), {-1, -1});
    dist[start] = {0, false, false};

    int iter = g.num_vertices();
    while (iter--) {
        bool update = false;
        for (int i = 0; i < g.num_edges(); i++) {
            auto e = g.edges[i];
            if (dist[e.from].inf) continue;
            if (dist[e.to].inf or dist[e.to].len > dist[e.from].len + e.cost) {
                update = true;
                dist[e.to].len = dist[e.from].len + e.cost;
                dist[e.to].inf = false;
                prev[e.to] = {e.from, i};
            }
        }
        if (!update) return {dist, prev};
    }

    iter = g.num_vertices();
    while (iter--) {
        for (int i = 0; i < g.num_edges(); i++) {
            auto e = g.edges[i];
            if (dist[e.from].inf) continue;
            if (dist[e.to].inf or dist[e.to].len > dist[e.from].len + e.cost) {
                dist[e.to].minf = true;
                dist[e.to].len = dist[e.from].len + e.cost;
            }
            if (dist[e.from].minf) dist[e.to].minf = true;
        }
    }

    return {dist, prev};
}

} // namespace shortest_path_impl

using shortest_path_impl::bellman_ford;

} // namespace kk2


#endif // KK2_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP
