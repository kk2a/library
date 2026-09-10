#ifndef KK2_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP
#define KK2_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP 1

#include <limits>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>

#include "../../type_traits/graph.hpp"
#include "../../type_traits/io.hpp"

namespace kk2 {

namespace shortest_path_impl {

template <class T> struct bf_edge {
    int to, id;
};

template <class T> struct bf_len {
    T len;
    bool inf, minf;

    template <OutputStream OStream> void debug_output(OStream &os) const {
        if (minf) os << "MINF";
        else if (inf) os << "INF";
        else os << len;
    }
};

template <class T> struct bf_result {
    std::vector<bf_len<T>> dist;
    std::vector<bf_edge<T>> prev;
};

template <
    graph::ForwardWeightedEdgeRange E,
    class T = std::remove_cvref_t<decltype(std::declval<std::ranges::range_value_t<E>>().cost)>>
bf_result<T> bellman_ford(int n, const E &edges, int start) {

    std::vector<bf_len<T>> dist(n, {0, true, false});
    std::vector<bf_edge<T>> prev(n, {-1, -1});
    dist[start] = {0, false, false};

    int iter = n;
    while (iter--) {
        bool update = false;
        for (auto e : edges) {
            if (dist[e.from].inf) continue;
            if (dist[e.to].inf or dist[e.to].len > dist[e.from].len + e.cost) {
                update = true;
                dist[e.to].len = dist[e.from].len + e.cost;
                dist[e.to].inf = false;
                prev[e.to] = {e.from, e.id};
            }
        }
        if (!update) return {dist, prev};
    }

    iter = n;
    while (iter--) {
        for (auto e : edges) {
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
