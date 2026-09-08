#ifndef KK2_GRAPH_DETAIL_STATIC_ADJACENCY_LIST_BASE_HPP
#define KK2_GRAPH_DETAIL_STATIC_ADJACENCY_LIST_BASE_HPP 1

#include <span>
#include <type_traits>
#include <utility>
#include <vector>

#include "../../type_traits/io.hpp"
#include "../edge.hpp"
#include "graph_base.hpp"

namespace kk2::graph::detail {

template <class T, bool is_directed, class Storage>
struct StaticAdjacencyListBase
    : GraphBase<T, is_directed, true>, private Storage {
    using base = GraphBase<T, is_directed, true>;

  public:
    // Public type interface and graph storage.
    using base::edges;
    using base::num_edges;
    using base::weighted;
    using Storage::data;

    using storage_type = Storage;
    using value_type = T;
    using out_edge_type = typename Storage::out_edge_type;
    using out_edges = typename Storage::out_edges;
    using adjacency_container = typename Storage::adjacency_container;

  private:
    std::vector<int> head;

  public:
    using edge_type = _Edge<T>;
    using edge_collection = _Edges<T>;

    // Construction and graph operations.
    StaticAdjacencyListBase() = default;
    explicit StaticAdjacencyListBase(int n) : Storage(), head(n) {}
    template <InputStream IStream>
    StaticAdjacencyListBase(int n, int m, IStream &is, bool oneindexed = false) : head(n) {
        edges.reserve(m);
        _input(is, m, oneindexed);
        build_storage();
    }
    StaticAdjacencyListBase(int n, const edge_collection &edges_) : head(n) {
        edges.reserve(edges_.size());
        for (const auto &e : edges_) _add_edge_with_id(e.from, e.to, _edge_cost(e), e.id);
        build_storage();
    }

    int num_vertices() const { return head.size(); }
    int size() const { return num_vertices(); }
    auto operator[](int k) {
        return Storage::view(head, &edges, k);
    }

    auto operator[](int k) const {
        return Storage::view(std::as_const(head), &edges, k);
    }

    auto edge_ids(int k) const
        requires requires { std::declval<const Storage &>().edge_ids(head, k); }
    {
        return static_cast<const Storage &>(*this).edge_ids(head, k);
    }

    void swap_edges(int v, int i, int j) { Storage::swap_edges(head, v, i, j); }
    void edge_clear() { *this = StaticAdjacencyListBase(num_vertices()); }

    template <OutputStream OStream>
    void debug_output(OStream &os) const {
        os << "[\n";
        for (int i = 0; i < num_vertices(); ++i) {
            os << "  " << i << ": [";
            bool first = true;
            for (auto &&e : (*this)[i]) {
                if (!first) os << ", ";
                first = false;
                e.debug_output(os);
            }
            os << "]\n";
        }
        os << "]\n";
    }

  private:
    void build_storage() {
        for (int i = 1; i < (int)head.size(); ++i) head[i] += head[i - 1];
        Storage::build(head, edges);
    }

  public:
    StaticAdjacencyListBase reverse() const {
        StaticAdjacencyListBase result(num_vertices());
        result.edges.reserve(edges.size());
        for (const auto &e : edges) result._add_edge_with_id(e.to, e.from, _edge_cost(e), e.id);
        result.build_storage();
        return result;
    }

  private:
    template <InputStream IStream>
    void _input(IStream &is, int m, bool oneindexed) {
        edges.clear();
        edges.reserve(m);
        head.assign(num_vertices(), 0);
        for (int i = 0; i < m; ++i) {
            int u, v;
            T w{};
            is >> u >> v;
            if constexpr (weighted) is >> w;
            if (oneindexed) --u, --v;
            _add_edge<false>(u, v, w, i);
        }
    }

    template <bool update = false> void _add_edge(int from, int to, T cost, int id) {
        Storage::count_edge(head, from, to, is_directed);
        if constexpr (update) edges[id] = edge_type(to, cost, from, id);
        else edges.emplace_back(to, cost, from, id);
    }

    void _add_edge_with_id(int from, int to, T cost, int id) {
        Storage::count_edge(head, from, to, is_directed);
        edges.emplace_back(to, cost, from, id);
    }
};

} // namespace kk2::graph::detail

#endif // KK2_GRAPH_DETAIL_STATIC_ADJACENCY_LIST_BASE_HPP
