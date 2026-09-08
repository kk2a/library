#ifndef KK2_GRAPH_DETAIL_DIRECT_ADJACENCY_STORAGE_HPP
#define KK2_GRAPH_DETAIL_DIRECT_ADJACENCY_STORAGE_HPP 1

#include <utility>
#include <vector>

#include "../edge.hpp"
#include "adjacency_storage_common.hpp"

namespace kk2::graph::detail {

template <class T, bool is_directed> struct DirectAdjacencyStorage {
    using edge_type = _Edge<T>;
    using out_edge_type = edge_type;
    using out_edges = _Edges<T>;
    using adjacency_container = std::vector<out_edges>;

    adjacency_container data;

    DirectAdjacencyStorage() = default;
    explicit DirectAdjacencyStorage(int n) : data(n) {}

    int num_vertices() const { return data.size(); }
    out_edges &view(int k) { return data[k]; }
    const out_edges &view(int k) const { return data[k]; }
    void swap_edges(int v, int i, int j) { std::swap(data[v][i], data[v][j]); }
    void add_vertex(int n) { data.insert(data.end(), n, out_edges()); }

    void reset() { data.assign(data.size(), out_edges()); }

    void reserve(const _Edges<T> &edges) {
        const auto degree = adjacency_degrees<T, is_directed>(num_vertices(), edges);
        for (int i = 0; i < num_vertices(); ++i) data[i].reserve(data[i].size() + degree[i]);
    }

    void add_edge(int from, int to, T cost, int id) {
        data[from].emplace_back(to, cost, from, id);
        if constexpr (!is_directed) {
            if (from != to) data[to].emplace_back(from, cost, to, id);
        }
    }
};

} // namespace kk2::graph::detail

#endif // KK2_GRAPH_DETAIL_DIRECT_ADJACENCY_STORAGE_HPP
