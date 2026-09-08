#ifndef KK2_GRAPH_GRAPH_HPP
#define KK2_GRAPH_GRAPH_HPP 1

#include <cassert>
#include <type_traits>
#include <utility>
#include <vector>

#include "../type_traits/io.hpp"
#include "edge.hpp"

namespace kk2 {

namespace graph {

template <class T, bool is_directed> struct AdjacencyList {
    using value_type = T;
    using out_edge_type = _Edge<T>;
    using out_edges = _Edges<T>;
    using adjacency_container = std::vector<out_edges>;
    using edge_type = _Edge<T>;
    using edge_collection = _Edges<T>;

    static constexpr bool directed = is_directed;
    static constexpr bool weighted = !std::is_same_v<T, empty>;
    static constexpr bool adjacency_list = true;
    static constexpr bool adjacency_matrix = false;
    static constexpr bool static_graph = false;

    adjacency_container data;
    edge_collection edges;

    AdjacencyList() = default;
    AdjacencyList(int n_) : data(n_) {}
    template <InputStream IStream>
    AdjacencyList(int n_, int m_, IStream &is, bool oneindexed = false)
        : data(n_) {
        edges.reserve(m_);
        _input(is, m_, oneindexed);
    }
    AdjacencyList(int n_, const edge_collection &edges_) : data(n_) {
        edges.reserve(edges_.size());
        _reserve_adjacency(edges_);
        for (auto &&e : edges_) _add_edge_with_id(e.from, e.to, e.cost, e.id);
    }

    inline int num_vertices() const { return data.size(); }
    inline int size() const { return data.size(); }
    inline int num_edges() const { return edges.size(); }
    out_edges &operator[](int k) { return data[k]; }
    const out_edges &operator[](int k) const { return data[k]; }
    void edge_clear() { *this = AdjacencyList(num_vertices()); }
    void add_edge(int from, int to, T cost = T{}) {
        _add_edge<false>(from, to, cost, num_edges());
    }
    void add_vertex(int n = 1) { data.insert(data.end(), n, out_edges()); }

    template <InputStream IStream>
    AdjacencyList &input(IStream &is, bool oneindexed = false) {
        _input(is, edges.size(), oneindexed);
        return *this;
    }

    template <InputStream IStream>
    void _input(IStream &is, int m, bool oneindexed) {
        edges.clear();
        edges.reserve(m);
        std::vector<int> degree(num_vertices());
        for (int i = 0; i < m; i++) {
            int u, v;
            T w{};
            is >> u >> v;
            if constexpr (weighted) is >> w;
            if (oneindexed) --u, --v;
            edges.emplace_back(v, w, u, i);
            ++degree[u];
            if constexpr (!is_directed) {
                if (u != v) ++degree[v];
            }
        }
        for (int i = 0; i < num_vertices(); ++i) data[i].reserve(data[i].size() + degree[i]);
        for (auto &&e : edges) {
            data[e.from].emplace_back(e.to, e.cost, e.from, e.id);
            if constexpr (!is_directed) {
                if (e.from != e.to) data[e.to].emplace_back(e.from, e.cost, e.to, e.id);
            }
        }
    }

    template <OutputStream OStream>
    void debug_output(OStream &os) const {
        os << "[\n";
        for (int i = 0; i < num_vertices(); i++) {
            os << "  " << i << ": [";
            for (size_t j = 0; j < data[i].size(); j++) {
                if (j) os << ", ";
                data[i][j].debug_output(os);
            }
            os << "]\n";
        }
        os << "]\n";
    }

  private:
    void _reserve_adjacency(const edge_collection &es) {
        std::vector<int> degree(num_vertices());
        for (auto &&e : es) {
            ++degree[e.from];
            if constexpr (!is_directed) {
                if (e.from != e.to) ++degree[e.to];
            }
        }
        for (int i = 0; i < num_vertices(); ++i) data[i].reserve(data[i].size() + degree[i]);
    }

    template <bool update = false> void _add_edge(int from, int to, T cost, int id) {
        data[from].emplace_back(to, cost, from, id);
        if (!is_directed and from != to) data[to].emplace_back(from, cost, to, id);
        if constexpr (update) edges[id] = edge_type(to, cost, from, id);
        else edges.emplace_back(to, cost, from, id);
    }

    void _add_edge_with_id(int from, int to, T cost, int id) {
        data[from].emplace_back(to, cost, from, id);
        if (!is_directed and from != to) data[to].emplace_back(from, cost, to, id);
        edges.emplace_back(to, cost, from, id);
    }

  public:
    AdjacencyList reverse() const {
        AdjacencyList res(num_vertices());
        res.edges.reserve(edges.size());
        res._reserve_adjacency(edges);
        for (auto &&e : edges) res._add_edge_with_id(e.to, e.from, e.cost, e.id);
        return res;
    }
};

template <class T, bool is_directed> struct AdjacencyMatrix {
    using value_type = T;
    using out_edge_type = _pair<T>;
    using out_edges = _pairs<T>;
    using adjacency_container = std::vector<out_edges>;
    using edge_type = _Edge<T>;
    using edge_collection = _Edges<T>;

    static constexpr bool directed = is_directed;
    static constexpr bool weighted = !std::is_same_v<T, empty>;
    static constexpr bool adjacency_list = false;
    static constexpr bool adjacency_matrix = true;
    static constexpr bool static_graph = false;

    adjacency_container data;
    edge_collection edges;

    AdjacencyMatrix() = default;
    AdjacencyMatrix(int n_) : data(n_, out_edges(n_)) {}
    template <InputStream IStream>
    AdjacencyMatrix(int n_, int m_, IStream &is, bool oneindexed = false)
        : data(n_, out_edges(n_)) {
        edges.reserve(m_);
        _input(is, m_, oneindexed);
    }
    AdjacencyMatrix(int n_, const edge_collection &edges_) : data(n_, out_edges(n_)) {
        edges.reserve(edges_.size());
        for (auto &&e : edges_) _add_edge_with_id(e.from, e.to, e.cost, e.id);
    }

    inline int num_vertices() const { return data.size(); }
    inline int size() const { return data.size(); }
    inline int num_edges() const { return edges.size(); }
    out_edges &operator[](int k) { return data[k]; }
    const out_edges &operator[](int k) const { return data[k]; }
    void edge_clear() { *this = AdjacencyMatrix(num_vertices()); }
    void add_edge(int from, int to, T cost = T{}) { _add_edge<false>(from, to, cost, num_edges()); }
    void add_vertex(int n = 1) {
        int now = num_vertices();
        data.resize(now + n);
        for (auto &&d : data) d.resize(now + n);
    }

    template <InputStream IStream>
    AdjacencyMatrix &input(IStream &is, bool oneindexed = false) {
        for (int i = 0; i < num_edges(); i++) {
            int u, v;
            T w{};
            is >> u >> v;
            if constexpr (weighted) is >> w;
            if (oneindexed) --u, --v;
            _add_edge<true>(u, v, w, i);
        }
        return *this;
    }

    template <InputStream IStream>
    void _input(IStream &is, int m, bool oneindexed) {
        for (int i = 0; i < m; i++) {
            int u, v;
            T w{};
            is >> u >> v;
            if constexpr (weighted) is >> w;
            if (oneindexed) --u, --v;
            _add_edge<false>(u, v, w, i);
        }
    }

    template <OutputStream OStream>
    void debug_output(OStream &os) const {
        os << "[\n";
        for (int i = 0; i < num_vertices(); i++) {
            os << "  " << i << ": [";
            for (size_t j = 0; j < data[i].size(); j++) {
                if (j) os << ", ";
                os << "(" << data[i][j].id << ", " << i << "->" << j;
                if constexpr (weighted) os << ": " << data[i][j].cost;
                os << ")";
            }
            os << "]\n";
        }
        os << "]\n";
    }

  private:
    template <bool update = false> void _add_edge(int from, int to, T cost, int id) {
        data[from][to] = out_edge_type(cost, id);
        if constexpr (!is_directed) data[to][from] = out_edge_type(cost, id);
        if constexpr (update) edges[id] = edge_type(to, cost, from, id);
        else edges.emplace_back(to, cost, from, id);
    }

    void _add_edge_with_id(int from, int to, T cost, int id) {
        data[from][to] = out_edge_type(cost, id);
        if constexpr (!is_directed) data[to][from] = out_edge_type(cost, id);
        edges.emplace_back(to, cost, from, id);
    }

  public:
    AdjacencyMatrix reverse() const {
        AdjacencyMatrix res(num_vertices());
        res.edges.reserve(edges.size());
        for (auto &&e : edges) res._add_edge_with_id(e.to, e.from, e.cost, e.id);
        return res;
    }
};

} // namespace graph

template <typename T> using WAdjList = graph::AdjacencyList<T, false>;
template <typename T> using DWAdjList = graph::AdjacencyList<T, true>;
using AdjList = graph::AdjacencyList<graph::empty, false>;
using DAdjList = graph::AdjacencyList<graph::empty, true>;

template <typename T> using WAdjMat = graph::AdjacencyMatrix<T, false>;
template <typename T> using DWAdjMat = graph::AdjacencyMatrix<T, true>;
using AdjMat = graph::AdjacencyMatrix<graph::empty, false>;
using DAdjMat = graph::AdjacencyMatrix<graph::empty, true>;

} // namespace kk2

#endif // KK2_GRAPH_GRAPH_HPP
