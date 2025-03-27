#ifndef KK2_GRAPH_INDUCED_SUBGRAPH_HPP
#define KK2_GRAPH_INDUCED_SUBGRAPH_HPP 1

#include <cassert>
#include <vector>

namespace kk2 {

template <class G>
G induced_subgraph(const G &g, const std::vector<int> &vs) {
    G res(g.num_vertices());

    std::vector<bool> used(g.num_vertices(), false);
    for (int v : vs) used[v] = true;

    for (auto e : g.edges)
        if (used[e.from] and used[e.to]) res.add_edge(e.from, e.to, e.cost);

    if constexpr (G::static_graph) res.build();

    return res;
}

} // namespace kk2

#endif // KK2_GRAPH_INDUCED_SUBGRAPH_HPP
