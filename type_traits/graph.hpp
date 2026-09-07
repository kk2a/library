#ifndef KK2_TYPE_TRAITS_GRAPH_HPP
#define KK2_TYPE_TRAITS_GRAPH_HPP 1

#include <concepts>
#include <ranges>
#include <type_traits>
#include <utility>

namespace kk2::graph {

template <class E>
concept Edge = requires(const E &e) {
    { e.from } -> std::convertible_to<int>;
    { e.to } -> std::convertible_to<int>;
    { e.id } -> std::convertible_to<int>;
};

template <class E>
concept WeightedEdge = Edge<E> && requires(const E &e) { e.cost; };

template <class R>
concept EdgeRange = std::ranges::input_range<R> &&
                    Edge<std::ranges::range_value_t<R>>;

template <class R>
concept WeightedEdgeRange = EdgeRange<R> &&
                            WeightedEdge<std::ranges::range_value_t<R>>;

template <class R>
concept ForwardWeightedEdgeRange = std::ranges::forward_range<R> && WeightedEdgeRange<R>;

template <class G>
concept Graph = requires(const G &g, int v) {
    typename G::value_type;
    { G::directed } -> std::convertible_to<bool>;
    { G::weighted } -> std::convertible_to<bool>;
    { G::adjacency_list } -> std::convertible_to<bool>;
    { G::adjacency_matrix } -> std::convertible_to<bool>;
    { G::static_graph } -> std::convertible_to<bool>;
    { g.num_vertices() } -> std::integral;
    { g.num_edges() } -> std::integral;
    g[v];
    g.edges;
};

template <class G>
concept EdgeListGraph = Graph<G> && requires(const G &g) {
    requires std::ranges::range<decltype(g.edges)>;
    requires Edge<std::ranges::range_value_t<decltype(g.edges)>>;
};

template <class G>
concept AdjacencyGraph = Graph<G> && requires(const G &g, int v) {
    requires std::ranges::range<decltype(g[v])>;
    requires Edge<std::ranges::range_value_t<decltype(g[v])>>;
};

template <class G>
concept WeightedGraph = AdjacencyGraph<G> && G::weighted &&
                        WeightedEdge<std::ranges::range_value_t<decltype(std::declval<const G &>()[0])>>;

template <class G>
concept WeightedEdgeListGraph = EdgeListGraph<G> && G::weighted &&
                                WeightedEdge<std::ranges::range_value_t<decltype(std::declval<const G &>().edges)>>;

template <class G>
concept UnweightedGraph = AdjacencyGraph<G> && (!G::weighted);

template <class G>
concept DirectedGraph = AdjacencyGraph<G> && G::directed;

template <class G>
concept UndirectedGraph = AdjacencyGraph<G> && (!G::directed);

template <class G>
concept WeightedDirectedGraph = WeightedGraph<G> && DirectedGraph<G>;

template <class G>
concept WeightedUndirectedGraph = WeightedGraph<G> && UndirectedGraph<G>;

template <class G>
concept WeightedDirectedEdgeListGraph = WeightedEdgeListGraph<G> && G::directed;

template <class G>
concept WeightedUndirectedEdgeListGraph = WeightedEdgeListGraph<G> && (!G::directed);

template <class G>
concept StaticGraph = Graph<G> && G::static_graph;

// Adjacency over vertices, also usable with vector<vector<int>>.
template <class G>
concept VertexAdjacency = requires(const G &g, int v) {
    { g.size() } -> std::integral;
    requires std::ranges::range<decltype(g[v])>;
    requires std::convertible_to<std::ranges::range_value_t<decltype(g[v])>, int>;
};

} // namespace kk2::graph

#endif // KK2_TYPE_TRAITS_GRAPH_HPP
