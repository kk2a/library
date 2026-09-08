// competitive-verifier: STANDALONE

#include "../../../../graph/graph.hpp"

#include <cassert>
#include <fstream>
#include <ranges>
#include <sstream>
#include <vector>

#include "../../../../graph/compact_graph.hpp"
#include "../../../../graph/compact_static_graph.hpp"
#include "../../../../graph/matrix.hpp"
#include "../../../../graph/static_graph.hpp"
#include "../../../../type_traits/graph.hpp"

struct TestInput : std::istringstream, kk2::type_traits::istream_tag {
    using std::istringstream::istringstream;
};

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
static_assert(kk2::graph::Graph<kk2::CAdjList>);
static_assert(kk2::graph::AdjacencyGraph<kk2::CAdjList>);
static_assert(kk2::graph::StaticGraph<kk2::CSAdjList>);

static_assert(kk2::graph::Graph<kk2::DWAdjMat<int>>);
static_assert(kk2::graph::WeightedEdgeListGraph<kk2::DWAdjMat<int>>);
static_assert(!kk2::graph::AdjacencyGraph<kk2::DWAdjMat<int>>);
static_assert(!kk2::graph::WeightedGraph<kk2::DWAdjMat<int>>);

static_assert(kk2::graph::VertexAdjacency<std::vector<std::vector<int>>>);
static_assert(
    std::ranges::random_access_range<decltype(std::declval<const kk2::CSAdjList &>()[0])>);
static_assert(std::same_as<decltype(std::declval<kk2::CDWAdjList<int> &>()[0][0].cost), int &>);
static_assert(
    std::same_as<decltype(std::declval<const kk2::CDWAdjList<int> &>()[0][0].cost), const int &>);
static_assert(
    std::same_as<
        decltype(std::declval<const decltype(std::declval<kk2::CDWAdjList<int> &>()[0]) &>()[0]
                     .cost),
        const int &>);
static_assert(std::same_as<decltype(std::declval<kk2::DWAdjMat<int> &>()[0][0].cost), int &>);
static_assert(sizeof(kk2::Edge) < sizeof(kk2::WEdge<int>));

int main() {
    kk2::WEdges<int> edges;
    edges.add_edge(0, 1, 3).add_edge(1, 2, 5);

    kk2::SDWAdjList<int> fast_static_graph(3, edges);
    assert(fast_static_graph[0].size() == 1);
    assert(fast_static_graph[0][0].to == 1);

    kk2::CSDWAdjList static_graph(3, edges);
    assert(static_graph[0].size() == 1);
    assert(static_graph[0][0].to == 1);
    assert(static_graph.edge_ids(0).size() == 1);
    assert(static_graph.edge_ids(0)[0] == 0);
    assert(static_graph[1].size() == 1);
    assert(static_graph[1][0].from == 1);
    assert(static_graph[1][0].to == 2);

    std::ofstream graph_output("/dev/null");
    fast_static_graph.debug_output(graph_output);
    static_graph.debug_output(graph_output);

    kk2::CDWAdjList<int> dynamic_graph(3, edges);
    assert(dynamic_graph.data[0].capacity() >= static_cast<size_t>(dynamic_graph[0].size()));
    assert(dynamic_graph.edge_ids(0).size() == 1);
    assert(dynamic_graph.edge_ids(0)[0] == 0);
    assert(dynamic_graph[0].begin()->to == 1);
    dynamic_graph[0][0].cost = 7;
    assert(dynamic_graph.edges[0].cost == 7);

    kk2::DWAdjList<int> fast_graph(3, edges);
    fast_graph[0][0].cost = 9;
    assert(fast_graph[0][0].cost == 9);

    TestInput input("0 1 4\n1 2 5\n");
    kk2::DWAdjList<int> input_graph(3, 2, input);
    assert(input_graph.edges.size() == 2);
    assert(input_graph[0].size() == 1);
    assert(input_graph[1].size() == 1);
    assert(input_graph[0][0].to == 1);
    assert(input_graph[1][0].to == 2);

    kk2::DWAdjMat<int> matrix(3);
    matrix.add_edge(0, 1, 11);
    assert(matrix[0][1].id == 0);
    assert(matrix[0][1].from == 0);
    assert(matrix[0][1].to == 1);
    matrix[0][1].cost = 13;
    assert(matrix.edges[0].cost == 13);
    assert(matrix[1][0].id == -1);
    matrix.add_vertex();
    assert(matrix[3][3].id == -1);
    matrix.debug_output(graph_output);
}
