#ifndef KK2_GRAPH_DETAIL_DIRECT_STATIC_ADJACENCY_STORAGE_HPP
#define KK2_GRAPH_DETAIL_DIRECT_STATIC_ADJACENCY_STORAGE_HPP 1

#include <span>
#include <utility>

#include "adjacency_storage_common.hpp"
#include "../edge.hpp"

namespace kk2::graph::detail {

template <class T, bool is_directed> struct DirectStaticAdjacencyStorage {
    using edge_type = _Edge<T>;
    using out_edge_type = edge_type;
    using out_edges = _Edges<T>;
    using adjacency_container = _Edges<T>;

    adjacency_container data;

    void count_edge(std::vector<int> &head, int from, int to, bool) {
        count_adjacency_edge<is_directed>(head, from, to);
    }

    std::span<edge_type> view(const std::vector<int> &head, _Edges<T> *, int k) {
        const int end = k + 1 == (int)head.size() ? data.size() : head[k + 1];
        return std::span<edge_type>(data).subspan(head[k], end - head[k]);
    }
    std::span<const edge_type> view(const std::vector<int> &head, const _Edges<T> *, int k) const {
        const int end = k + 1 == (int)head.size() ? data.size() : head[k + 1];
        return std::span<const edge_type>(data).subspan(head[k], end - head[k]);
    }

    void build(std::vector<int> &head, const _Edges<T> &edges) {
        data.resize(head.empty() ? 0 : head.back());
        for (const auto &e : edges) {
            data[--head[e.from]] = e;
            if constexpr (!is_directed) {
                if (e.from != e.to) data[--head[e.to]] = e.rev();
            }
        }
    }

    void swap_edges(const std::vector<int> &head, int v, int i, int j) {
        std::swap(data[head[v] + i], data[head[v] + j]);
    }
};

} // namespace kk2::graph::detail

#endif // KK2_GRAPH_DETAIL_DIRECT_STATIC_ADJACENCY_STORAGE_HPP
