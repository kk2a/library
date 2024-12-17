#ifndef GRAPH_GRAPH_TEMPLATE_HPP
#define GRAPH_GRAPH_TEMPLATE_HPP 1

#include <cassert>
#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>

#include "../type_traits/type_traits.hpp"

namespace kk2 {

namespace graph {

struct empty {};

template <class T> struct _Edge {
    int from, to, id;
    T cost;

    _Edge(int to_, T cost_, int from_ = -1, int id_ = -1)
        : from(from_),
          to(to_),
          id(id_),
          cost(cost_) {}

    _Edge() : from(-1), to(-1), id(-1), cost() {}

    operator int() const { return to; }

    _Edge rev() const { return _Edge(from, cost, to, id); }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const _Edge &e) {
        if constexpr (std::is_same_v<T, empty>) return os << e.from << " -> " << e.to;
        else return os << e.from << " -> " << e.to << " : " << e.cost;
    }
};
template <class T> using _Edges = std::vector<_Edge<T>>;

template <class T, bool is_directed> struct AdjacencyList : std::vector<_Edges<T>> {
    using value_type = T;
    using edge_type = _Edge<T>;

    constexpr static bool directed() { return is_directed; }

    AdjacencyList() = default;

    AdjacencyList(int n_) : std::vector<_Edges<T>>(n_) {}

    // input を使うことが前提
    AdjacencyList(int n_, int m_) : std::vector<_Edges<T>>(n_), edges(m_) {}

    AdjacencyList(int n_, const _Edges<T> &edges_) : std::vector<_Edges<T>>(n_), edges(edges_) {
        for (auto &&e : edges) {
            (*this)[e.from].emplace_back(e);
            if constexpr (!is_directed) (*this)[e.to].emplace_back(e);
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

  private:
    template <bool update = false>
    void _add_edge(int from, int to, T cost, int id) {
        (*this)[from].emplace_back(to, cost, from, id);
        if constexpr (!is_directed) (*this)[to].emplace_back(from, cost, to, id);
        if constexpr (update) edges[id] = _Edge<T>(to, cost, from, id);
        else edges.emplace_back(to, cost, from, id);
    }
};

template <class T> struct _pair {
    T cost;
    int id;

    _pair(T cost_, int id_) : cost(cost_), id(id_) {}

    _pair() : cost(), id(-1) {}

    operator bool() const { return id != -1; }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const _pair &p) {
        if constexpr (std::is_same_v<T, empty>) return os;
        else return os << p.cost;
    }
};
template <class T> using _pairs = std::vector<_pair<T>>;

template <class T, bool is_directed> struct AdjacencyMatrix : std::vector<_pairs<T>> {
    using value_type = T;
    using edge_type = _pair<T>;

    constexpr static bool directed() { return is_directed; }

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

  private:
    template <bool update = false>
    void _add_edge(int from, int to, T cost, int id) {
        (*this)[from][to] = _pair<T>(cost, id);
        if constexpr (!is_directed) (*this)[to][from] = _pair<T>(cost, id);
        if constexpr (update) edges[id] = _Edge<T>(to, cost, from, id);
        else edges.emplace_back(to, cost, from, id);
    }
};

template <class G>
G reverse(const G &g) {
    G res(g.num_vertices());
    for (auto &&e : g.edges) res.add_edge(e.to, e.from, e.cost);
    return res;
}

template <class T, class IStream, is_istream_t<IStream> * = nullptr>
_Edges<T> &input(IStream &is, _Edges<T>& edges, bool is_one_indexed) {
    for (int i = 0; i < (int)edges.size(); i++) {
        int u, v;
        T w{};
        is >> u >> v;
        if (is_one_indexed) --u, --v;
        if constexpr (!std::is_same_v<T, empty>) is >> w;
        edges[i] = _Edge<T>(v, w, u, i);
    }
    return edges;
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

template <typename T> using WEdge = graph::_Edge<T>;
template <typename T> using WEdges = graph::_Edges<T>;
using Edge = graph::_Edge<graph::empty>;
using Edges = graph::_Edges<graph::empty>;
using graph::input;
using graph::reverse;

} // namespace kk2

#endif // GRAPH_GRAPH_TEMPLATE_HPP
