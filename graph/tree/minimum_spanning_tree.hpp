#ifndef KK2_GRAPH_TREE_MINIMUM_SPANNING_TREE_HPP
#define KK2_GRAPH_TREE_MINIMUM_SPANNING_TREE_HPP 1

#include <utility>

#include "../../unionfind/unionfind.hpp"

namespace kk2 {

template <class G> auto minimum_spanning_tree(const G &g) {
    static_assert(!G::directed, "minimum_spanning_tree requires undirected graph");
    static_assert(G::weighted, "minimum_spanning_tree requires weighted graph");

    using value_type = typename G::value_type;

    auto edges = g.edges;
    std::sort(edges.begin(), edges.end(), [](const auto &e1, const auto &e2) {
        return e1.cost < e2.cost;
    });
    UnionFind uf(g.num_vertices());
    std::vector<int> idxs(g.num_vertices() - 1);
    value_type total_cost = 0;
    int i = 0;
    for (auto &&e : edges) {
        if (uf.unite(e.from, e.to)) { idxs[i++] = e.id, total_cost += e.cost; }
    }

    return std::make_pair(total_cost, idxs);
}

} // namespace kk2

#endif // KK2_GRAPH_TREE_MINIMUM_SPANNING_TREE_HPP
