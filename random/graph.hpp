#ifndef KK2_RANDOM_GRAPH_HPP
#define KK2_RANDOM_GRAPH_HPP 1

#include <type_traits>
#include <vector>

#include "../graph/graph.hpp"
#include "gen.hpp"

namespace kk2 {

namespace random {

template <bool is_weighted, bool is_directed, class T = int>
using adjlist = std::conditional<is_weighted, WAdjList<T, is_directed>, AdjList<is_directed>>;

template <bool is_weighted, bool is_directed, class T = int>
void add_edge(adjlist<is_weighted, is_directed, T> &g, int from, int to, T l = 0, T r = 1e9) {
    if constexpr (is_weighted) {
        T w = rng(l, r);
        g.add_edge(from, to, w);
    } else {
        g.add_edge(from, to);
    }
}

template <bool is_weighted, bool is_directed, class T = int>
adjlist<is_weighted, is_directed, T> Graph(int n, int m, T l = 0, T r = 1e9) {
    adjlist<is_weighted, is_directed, T> g(n, false);
    for (int i = 0; i < m; i++) {
        int u = rng(0, n), v = rng(0, n);
        add_edge<is_weighted, is_directed, T>(g, u, v, l, r);
    }
    return g;
}

template <bool is_weighted, class T = int>
adjlist<is_weighted, false, T> Tree(int n, T l = 0, T r = 1e9) {
    adjlist<is_weighted, false, T> g(n, false);
    std::vector<int> p = perm<int>(n);
    for (int i = 1; i < n; i++) {
        int u = rng(0, i), v = i;
        add_edge<is_weighted, false, T>(g, p[u], p[v], l, r);
    }
    return g;
}

} // namespace random

} // namespace kk2

#endif // KK2_RANDOM_GRAPH_HPP
