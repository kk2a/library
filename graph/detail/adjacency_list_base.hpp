#ifndef KK2_GRAPH_DETAIL_ADJACENCY_LIST_BASE_HPP
#define KK2_GRAPH_DETAIL_ADJACENCY_LIST_BASE_HPP 1

#include <type_traits>
#include <utility>

#include "../../type_traits/io.hpp"
#include "../edge.hpp"
#include "graph_base.hpp"

namespace kk2::graph::detail {

template <class T, bool is_directed, class Storage>
struct AdjacencyListBase : GraphBase<T, is_directed, false>, private Storage {
    using base = GraphBase<T, is_directed, false>;

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
    using edge_type = _Edge<T>;
    using edge_collection = _Edges<T>;

    // Construction and graph operations.
    AdjacencyListBase() = default;
    explicit AdjacencyListBase(int n) : Storage(n) {}
    template <InputStream IStream>
    AdjacencyListBase(int n, int m, IStream &is, bool oneindexed = false) : Storage(n) {
        edges.reserve(m);
        _input(is, m, oneindexed);
    }
    AdjacencyListBase(int n, const edge_collection &edges_) : Storage(n) {
        edges.reserve(edges_.size());
        this->reserve(edges_);
        for (const auto &e : edges_) _add_edge_with_id(e.from, e.to, _edge_cost(e), e.id);
    }

    int num_vertices() const { return Storage::num_vertices(); }
    int size() const { return num_vertices(); }

    decltype(auto) operator[](int k) {
        if constexpr (requires { std::declval<Storage &>().view(k, &edges); }) {
            return Storage::view(k, &edges);
        } else {
            return Storage::view(k);
        }
    }

    decltype(auto) operator[](int k) const {
        if constexpr (requires { std::declval<const Storage &>().view(k, &edges); }) {
            return std::as_const(static_cast<const Storage &>(*this)).view(k, &edges);
        } else {
            return std::as_const(static_cast<const Storage &>(*this)).view(k);
        }
    }

    auto edge_ids(int k) const
        requires requires { std::declval<const Storage &>().edge_ids(k); }
    {
        return static_cast<const Storage &>(*this).edge_ids(k);
    }

    void swap_edges(int v, int i, int j) { Storage::swap_edges(v, i, j); }
    void edge_clear() { *this = AdjacencyListBase(num_vertices()); }

    template <OutputStream OStream> void debug_output(OStream &os) const {
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

    void add_edge(int from, int to, T cost = T{}) { _add_edge<false>(from, to, cost, num_edges()); }
    void add_vertex(int n = 1) { Storage::add_vertex(n); }

    AdjacencyListBase reverse() const {
        AdjacencyListBase result(num_vertices());
        result.edges.reserve(edges.size());
        result.reserve(edges);
        for (const auto &e : edges) result._add_edge_with_id(e.to, e.from, _edge_cost(e), e.id);
        return result;
    }

  private:
    template <InputStream IStream> void _input(IStream &is, int m, bool oneindexed) {
        edges.clear();
        edges.reserve(m);
        this->reset();
        for (int i = 0; i < m; ++i) {
            int u, v;
            T w{};
            is >> u >> v;
            if constexpr (weighted) is >> w;
            if (oneindexed) --u, --v;
            edges.emplace_back(v, w, u, i);
        }
        this->reserve(edges);
        for (const auto &e : edges) Storage::add_edge(e.from, e.to, _edge_cost(e), e.id);
    }

    template <bool update = false> void _add_edge(int from, int to, T cost, int id) {
        Storage::add_edge(from, to, cost, id);
        if constexpr (update) edges[id] = edge_type(to, cost, from, id);
        else edges.emplace_back(to, cost, from, id);
    }

    void _add_edge_with_id(int from, int to, T cost, int id) {
        Storage::add_edge(from, to, cost, id);
        edges.emplace_back(to, cost, from, id);
    }
};

} // namespace kk2::graph::detail

#endif // KK2_GRAPH_DETAIL_ADJACENCY_LIST_BASE_HPP
