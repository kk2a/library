#ifndef KK2_GRAPH_INDUCED_SUBGRAPH_HPP
#define KK2_GRAPH_INDUCED_SUBGRAPH_HPP 1

#include <cassert>
#include <type_traits>
#include <vector>

#include "../type_traits/graph.hpp"

namespace kk2 {

template <graph::EdgeListGraph G> G induced_subgraph(const G &g, const std::vector<int> &vs) {
    G res(g.num_vertices());
    using edge_collection = std::remove_cvref_t<decltype(res.edges)>;
    edge_collection res_edges;
    res_edges.reserve(g.num_edges());

    std::vector<bool> used(g.num_vertices(), false);
    for (int v : vs) used[v] = true;

    for (auto e : g.edges) {
        if (!used[e.from] or !used[e.to]) continue;
        if constexpr (G::weighted) res_edges.add_edge(e.from, e.to, e.cost);
        else res_edges.add_edge(e.from, e.to);
    }

    res = G(g.num_vertices(), res_edges);

    return res;
}

} // namespace kk2

#endif // KK2_GRAPH_INDUCED_SUBGRAPH_HPP
