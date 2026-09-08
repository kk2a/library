// competitive-verifier: STANDALONE

#include <cassert>
#include <ranges>
#include <vector>

#include "../../../../graph/graph.hpp"
#include "../../../../graph/static_graph.hpp"
#include "../../../../type_traits/graph.hpp"

static_assert(kk2::graph::Graph<kk2::AdjList>);
static_assert(kk2::graph::EdgeListGraph<kk2::AdjList>);
static_assert(kk2::graph::AdjacencyGraph<kk2::AdjList>);
static_assert(kk2::graph::UnweightedGraph<kk2::AdjList>);
static_assert(kk2::graph::UndirectedGraph<kk2::AdjList>);

static_assert(kk2::graph::WeightedGraph<kk2::DWAdjList<int>>);
static_assert(kk2::graph::WeightedEdgeListGraph<kk2::DWAdjList<int>>);
static_assert(kk2::graph::WeightedEdgeRange<kk2::WEdges<int>>);
static_assert(kk2::graph::WeightedDirectedGraph<kk2::DWAdjList<int>>);
static_assert(kk2::graph::WeightedDirectedEdgeListGraph<kk2::DWAdjList<int>>);

static_assert(kk2::graph::StaticGraph<kk2::SAdjList>);
static_assert(kk2::graph::WeightedEdgeListGraph<kk2::SDWAdjList<int>>);
static_assert(kk2::graph::WeightedUndirectedEdgeListGraph<kk2::SWAdjList<int>>);

static_assert(kk2::graph::Graph<kk2::DWAdjMat<int>>);
static_assert(kk2::graph::WeightedEdgeListGraph<kk2::DWAdjMat<int>>);
static_assert(!kk2::graph::AdjacencyGraph<kk2::DWAdjMat<int>>);
static_assert(!kk2::graph::WeightedGraph<kk2::DWAdjMat<int>>);

static_assert(kk2::graph::VertexAdjacency<std::vector<std::vector<int>>>);
static_assert(std::ranges::random_access_range<decltype(std::declval<const kk2::SAdjList &>()[0])>);

int main() {
    kk2::WEdges<int> edges;
    edges.add_edge(0, 1, 3).add_edge(1, 2, 5);

    kk2::SDWAdjList static_graph(3, edges);
    assert(static_graph[0].size() == 1);
    assert(static_graph[0][0].to == 1);
    static_graph.build();
    assert(static_graph[1].size() == 1);

    kk2::DWAdjList<int> dynamic_graph(3, edges);
    assert(dynamic_graph[0].capacity() >= dynamic_graph[0].size());
}
