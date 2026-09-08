#ifndef KK2_GRAPH_DETAIL_GRAPH_BASE_HPP
#define KK2_GRAPH_DETAIL_GRAPH_BASE_HPP 1

#include <type_traits>

#include "../edge.hpp"

namespace kk2::graph::detail {

// The representation-specific graph classes inherit this base.  Operations
// here only depend on the public graph interface, so they are shared by
// dynamic/static and direct/compact graphs alike.
template <class T, bool is_directed, bool is_static, bool is_adjacency_list = true>
struct GraphBase {
  public:
    // Types and compile-time graph properties.
    using value_type = T;
    using edge_type = _Edge<T>;
    using edge_collection = _Edges<T>;

    static constexpr bool directed = is_directed;
    static constexpr bool weighted = !std::is_same_v<T, empty>;
    static constexpr bool adjacency_list = is_adjacency_list;
    static constexpr bool adjacency_matrix = !is_adjacency_list;
    static constexpr bool static_graph = is_static;

    // Public graph data and common operations.
    edge_collection edges;
    int num_edges() const { return edges.size(); }
};

} // namespace kk2::graph::detail

#endif // KK2_GRAPH_DETAIL_GRAPH_BASE_HPP
