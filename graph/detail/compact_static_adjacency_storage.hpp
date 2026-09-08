#ifndef KK2_GRAPH_DETAIL_COMPACT_STATIC_ADJACENCY_STORAGE_HPP
#define KK2_GRAPH_DETAIL_COMPACT_STATIC_ADJACENCY_STORAGE_HPP 1

#include <span>
#include <utility>
#include <vector>

#include "adjacency_storage_common.hpp"
#include "../compact_edge.hpp"

namespace kk2::graph::detail {

template <class T, bool is_directed> struct CompactStaticAdjacencyStorage {
    using edge_type = _Edge<T>;
    using out_edge_type = _AdjacencyEdgeProxy<T, false>;
    using out_edges = std::vector<int>;
    using adjacency_container = std::vector<int>;

    adjacency_container data;

    void count_edge(std::vector<int> &head, int from, int to, bool) {
        count_adjacency_edge<is_directed>(head, from, to);
    }

    std::span<const int> edge_ids(const std::vector<int> &head, int k) const {
        const int end = k + 1 == (int)head.size() ? data.size() : head[k + 1];
        return std::span<const int>(data).subspan(head[k], end - head[k]);
    }
    _AdjacencyView<T, false> view(const std::vector<int> &head, _Edges<T> *edges, int k) {
        const int end = k + 1 == (int)head.size() ? data.size() : head[k + 1];
        return {std::span<int>(data).subspan(head[k], end - head[k]), edges, k};
    }
    _AdjacencyView<T, true> view(const std::vector<int> &head,
                                 const _Edges<T> *edges,
                                 int k) const {
        const int end = k + 1 == (int)head.size() ? data.size() : head[k + 1];
        return {std::span<const int>(data).subspan(head[k], end - head[k]), edges, k};
    }

    void build(std::vector<int> &head, const _Edges<T> &edges) {
        data.resize(head.empty() ? 0 : head.back());
        for (const auto &e : edges) {
            data[--head[e.from]] = e.id;
            if constexpr (!is_directed) {
                if (e.from != e.to) data[--head[e.to]] = e.id;
            }
        }
    }

    void swap_edges(const std::vector<int> &head, int v, int i, int j) {
        std::swap(data[head[v] + i], data[head[v] + j]);
    }
};

} // namespace kk2::graph::detail

#endif // KK2_GRAPH_DETAIL_COMPACT_STATIC_ADJACENCY_STORAGE_HPP
