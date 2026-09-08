#ifndef KK2_GRAPH_TREE_MINIMUM_SPANNING_TREE_HPP
#define KK2_GRAPH_TREE_MINIMUM_SPANNING_TREE_HPP 1

#include <algorithm>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>

#include "../../type_traits/graph.hpp"
#include "../../unionfind/unionfind.hpp"

namespace kk2 {

template <graph::WeightedEdgeRange E> auto minimum_spanning_tree(int n, const E &input_edges) {

    using edge_type = std::ranges::range_value_t<E>;
    using value_type = std::remove_cvref_t<decltype(std::declval<edge_type>().cost)>;

    std::vector<edge_type> edges(std::ranges::begin(input_edges), std::ranges::end(input_edges));
    std::sort(edges.begin(), edges.end(), [](const auto &e1, const auto &e2) {
        return e1.cost < e2.cost;
    });
    UnionFind uf(n);
    std::vector<int> idxs(n - 1);
    value_type total_cost = 0;
    int i = 0;
    for (auto &&e : edges) {
        if (uf.unite(e.from, e.to)) { idxs[i++] = e.id, total_cost += e.cost; }
    }

    return std::make_pair(total_cost, idxs);
}

} // namespace kk2

#endif // KK2_GRAPH_TREE_MINIMUM_SPANNING_TREE_HPP
