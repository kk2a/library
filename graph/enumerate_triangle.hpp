#ifndef KK2_GRAPH_ENUMERATE_TRIANGLE_HPP
#define KK2_GRAPH_ENUMERATE_TRIANGLE_HPP 1

#include <utility>
#include <type_traits>
#include <vector>

#include "../type_traits/graph.hpp"

namespace kk2 {

template <graph::UndirectedGraph G, graph::DirectedGraph H, class F>
void enumerate_triangle(const G &g, const F &f) {
    H h(g.num_vertices());
    using edge_collection = std::remove_cvref_t<decltype(h.edges)>;
    edge_collection h_edges;
    h_edges.reserve(g.num_edges());
    for (auto &&e : g.edges) {
        int u = e.from, v = e.to;
        if ((g[u].size() == g[v].size() and u > v) or g[u].size() > g[v].size()) std::swap(u, v);
        h_edges.add_edge(u, v);
    }
    h = H(g.num_vertices(), h_edges);
    std::vector<int> buf(g.num_vertices(), -1);
    for (int i = 0; i < g.num_vertices(); i++) {
        for (auto &&e1 : h[i]) buf[e1.to] = i;
        for (auto &&e1 : h[i])
            for (auto &&e2 : h[e1.to])
                if (buf[e2.to] == i) f(i, e1.to, e2.to);
    }
}

} // namespace kk2

#endif // KK2_GRAPH_ENUMERATE_TRIANGLE_HPP
