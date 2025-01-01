#ifndef GRAPH_GRAPH_TEMPLATE_HPP
#define GRAPH_GRAPH_TEMPLATE_HPP 1

#include <cassert>
#include <type_traits>
#include <utility>
#include <vector>

#include "../type_traits/type_traits.hpp"
#include "edge.hpp"

namespace kk2 {

namespace graph {

template <class T, bool is_directed> struct AdjacencyList : std::vector<_Edges<T>> {
    using value_type = T;
    using edge_type = _Edge<T>;

    using directed = std::integral_constant<bool, is_directed>;
    using weighted = std::integral_constant<bool, !std::is_same_v<T, empty>>;
    using adjacency_list = std::integral_constant<bool, true>;
    using adjacency_matrix = std::integral_constant<bool, false>;
    using static_graph = std::integral_constant<bool, false>;

    AdjacencyList() = default;

    AdjacencyList(int n_) : std::vector<_Edges<T>>(n_) {}

    // input を使うことが前提
    AdjacencyList(int n_, int m_) : std::vector<_Edges<T>>(n_), edges(m_) {}

    AdjacencyList(int n_, const _Edges<T> &edges_) : std::vector<_Edges<T>>(n_), edges(edges_) {
        for (auto &&e : edges) {
            (*this)[e.from].emplace_back(e);
            if constexpr (!is_directed) (*this)[e.to].emplace_back(e.rev());
        }
    }

    _Edges<T> edges;

    int num_vertices() const { return (int)this->size(); }

    int num_edges() const { return (int)edges.size(); }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    AdjacencyList &input(IStream &is, bool oneindexed = false) {
        for (int i = 0; i < num_edges(); i++) {
            int u, v;
            T w{};
            is >> u >> v;
            if constexpr (!std::is_same_v<T, empty>) is >> w;
            if (oneindexed) --u, --v;
            _add_edge<true>(u, v, w, i);
        }
        return *this;
    }

    void edge_clear() {
        for (auto &v : *this) v.clear();
        edges.clear();
    }

    void add_edge(int from, int to, T cost = T{}) { _add_edge<false>(from, to, cost, num_edges()); }

    void add_vertex(int n = 1) { this->insert(this->end(), n, _Edges<T>()); }

  private:
    template <bool update = false> void _add_edge(int from, int to, T cost, int id) {
        (*this)[from].emplace_back(to, cost, from, id);
        if constexpr (!is_directed) {
            if (from != to) (*this)[to].emplace_back(from, cost, to, id);
        }
        if constexpr (update) edges[id] = _Edge<T>(to, cost, from, id);
        else edges.emplace_back(to, cost, from, id);
    }
};

template <class T, bool is_directed> struct AdjacencyMatrix : std::vector<_pairs<T>> {
    using value_type = T;
    using edge_type = _pair<T>;

    using directed = std::integral_constant<bool, is_directed>;
    using weighted = std::integral_constant<bool, !std::is_same_v<T, empty>>;
    using adjacency_list = std::integral_constant<bool, false>;
    using adjacency_matrix = std::integral_constant<bool, true>;
    using static_graph = std::integral_constant<bool, false>;

    AdjacencyMatrix() = default;

    AdjacencyMatrix(int n_) : std::vector<_pairs<T>>(n_, _pairs<T>(n_)) {}

    // input を使うことが前提
    AdjacencyMatrix(int n_, int m_) : std::vector<_pairs<T>>(n_, _pairs<T>(n_)), edges(m_) {}

    AdjacencyMatrix(int n_, const _Edges<T> &edges_)
        : std::vector<_pairs<T>>(n_, _pairs<T>(n_)),
          edges(edges_) {
        for (auto &&e : edges) {
            (*this)[e.from][e.to] = _pair<T>(e.cost, e.id);
            if constexpr (!is_directed) (*this)[e.to][e.from] = _pair<T>(e.cost, e.id);
        }
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    AdjacencyMatrix &input(IStream &is, bool oneindexed = false) {
        for (int i = 0; i < num_edges(); i++) {
            int u, v;
            T w{};
            is >> u >> v;
            if constexpr (!std::is_same_v<T, empty>) is >> w;
            if (oneindexed) --u, --v;
            _add_edge<true>(u, v, w, i);
        }
        return *this;
    }

    _Edges<T> edges;

    int num_vertices() const { return (int)this->size(); }

    int num_edges() const { return (int)edges.size(); }

    void edge_clear() {
        for (auto &&e : edges) {
            (*this)[e.from][e.to] = _pair<T>(e.cost, e.id);
            if constexpr (!is_directed) (*this)[e.to][e.from] = _pair<T>(e.cost, e.id);
        }
        edges.clear();
    }

    void add_edge(int from, int to, T cost = T{}) { _add_edge<false>(from, to, cost, num_edges()); }

    void add_vertex(int n = 1) {
        this->insert(this->end(), n, _pairs<T>());
        for (int i = 0; i < n; i++) (*this)[i].insert((*this)[i].end(), n, _pair<T>());
    }

  private:
    template <bool update = false> void _add_edge(int from, int to, T cost, int id) {
        (*this)[from][to] = _pair<T>(cost, id);
        if constexpr (!is_directed) (*this)[to][from] = _pair<T>(cost, id);
        if constexpr (update) edges[id] = _Edge<T>(to, cost, from, id);
        else edges.emplace_back(to, cost, from, id);
    }
};

template <class G> G reverse(const G &g) {
    G res(g.num_vertices());
    for (auto &&e : g.edges) res.add_edge(e.to, e.from, e.cost);
    return res;
}

} // namespace graph

template <typename T> using WAdjList = graph::AdjacencyList<T, false>;
template <typename T> using DWAdjList = graph::AdjacencyList<T, true>;
using AdjList = graph::AdjacencyList<graph::empty, false>;
using DAdjList = graph::AdjacencyList<graph::empty, true>;

template <typename T> using WAdjMat = graph::AdjacencyMatrix<T, false>;
template <typename T> using DWAdjMat = graph::AdjacencyMatrix<T, true>;
using AdjMat = graph::AdjacencyMatrix<graph::empty, false>;
using DAdjMat = graph::AdjacencyMatrix<graph::empty, true>;

using graph::reverse;

} // namespace kk2

#endif // GRAPH_GRAPH_TEMPLATE_HPP
