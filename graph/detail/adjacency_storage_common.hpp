#ifndef KK2_GRAPH_DETAIL_ADJACENCY_STORAGE_COMMON_HPP
#define KK2_GRAPH_DETAIL_ADJACENCY_STORAGE_COMMON_HPP 1

#include <vector>

#include "../edge.hpp"

namespace kk2::graph::detail {

template <class T, bool is_directed>
std::vector<int> adjacency_degrees(int n, const _Edges<T> &edges) {
    std::vector<int> degree(n);
    for (const auto &e : edges) {
        ++degree[e.from];
        if constexpr (!is_directed) {
            if (e.from != e.to) ++degree[e.to];
        }
    }
    return degree;
}

template <bool is_directed> void count_adjacency_edge(std::vector<int> &head, int from, int to) {
    ++head[from];
    if constexpr (!is_directed) {
        if (from != to) ++head[to];
    }
}

} // namespace kk2::graph::detail

#endif // KK2_GRAPH_DETAIL_ADJACENCY_STORAGE_COMMON_HPP
