#ifndef KK2_GRAPH_DETAIL_COMPACT_ADJACENCY_STORAGE_HPP
#define KK2_GRAPH_DETAIL_COMPACT_ADJACENCY_STORAGE_HPP 1

#include <span>
#include <utility>
#include <vector>

#include "adjacency_storage_common.hpp"
#include "../compact_edge.hpp"

namespace kk2::graph::detail {

template <class T, bool is_directed> struct CompactAdjacencyStorage {
    using edge_type = _Edge<T>;
    using out_edge_type = _AdjacencyEdgeProxy<T, false>;
    using out_edges = std::vector<int>;
    using adjacency_container = std::vector<out_edges>;

    adjacency_container data;

    CompactAdjacencyStorage() = default;
    explicit CompactAdjacencyStorage(int n) : data(n) {}

    int num_vertices() const { return data.size(); }
    std::span<const int> edge_ids(int k) const { return data[k]; }
    void swap_edges(int v, int i, int j) { std::swap(data[v][i], data[v][j]); }
    void add_vertex(int n) { data.insert(data.end(), n, out_edges()); }

    _AdjacencyView<T, false> view(int k, _Edges<T> *edges) {
        return {std::span<int>(data[k]), edges, k};
    }
    _AdjacencyView<T, true> view(int k, const _Edges<T> *edges) const {
        return {std::span<const int>(data[k]), edges, k};
    }

    void reset() { data.assign(data.size(), out_edges()); }

    void reserve(const _Edges<T> &edges) {
        const auto degree = adjacency_degrees<T, is_directed>(num_vertices(), edges);
        for (int i = 0; i < num_vertices(); ++i) data[i].reserve(data[i].size() + degree[i]);
    }

    void add_edge(int from, int to, T, int id) {
        data[from].emplace_back(id);
        if constexpr (!is_directed) {
            if (from != to) data[to].emplace_back(id);
        }
    }
};

} // namespace kk2::graph::detail

#endif // KK2_GRAPH_DETAIL_COMPACT_ADJACENCY_STORAGE_HPP
