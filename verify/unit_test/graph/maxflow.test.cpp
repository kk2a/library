// competitive-verifier: STANDALONE

#include <cassert>

#include "../../../graph/graph.hpp"
#include "../../../graph/maxflow.hpp"

int main() {
    kk2::WEdges<int> edges;
    edges.add_edge(0, 1, 3);
    edges.add_edge(0, 2, 2);
    edges.add_edge(1, 3, 2);
    edges.add_edge(2, 3, 2);

    kk2::MaxFlow<kk2::DWAdjList<int>> flow(4, edges);
    assert(flow.flow(0, 3) == 4);
    assert(flow.get_edge(0).flow == 2);
    assert(flow.get_edge(1).flow == 2);
    assert(flow.min_cut(0)[3] == false);
}
