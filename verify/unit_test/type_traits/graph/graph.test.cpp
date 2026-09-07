// competitive-verifier: STANDALONE

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

int main() {}
