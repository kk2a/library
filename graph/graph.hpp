#ifndef GRAPH_GRAPH_TEMPLATE_HPP
#define GRAPH_GRAPH_TEMPLATE_HPP 1

#include <cassert>
#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>

namespace kk2 {

namespace graph {

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

    template <class OStream> friend OStream &operator<<(OStream &os, const _Edge &e) {
        return os << e.from << " -> " << e.to << " : " << e.cost;
    }
};
template <class T> using _Edges = std::vector<_Edge<T>>;

struct empty {};

template <class T, bool is_directed> struct AdjacencyList : std::vector<_Edges<T>> {
    AdjacencyList() = default;

    AdjacencyList(int n_, bool is_one_indexed)
        : std::vector<_Edges<T>>(n_),
          n(n_),
          m(0),
          oneindexed(is_one_indexed) {}

    AdjacencyList(int n_, int m_, bool is_one_indexed)
        : std::vector<_Edges<T>>(n_),
          n(n_),
          m(m_),
          oneindexed(is_one_indexed) {}

    AdjacencyList(int n_, const _Edges<T> &edges_, bool is_one_indexed)
        : std::vector<_Edges<T>>(n_),
          n(n_),
          m(0),
          oneindexed(is_one_indexed) {
        for (auto &e : edges_) { _add_edge(e.from, e.to, e.cost, m++); }
    }

    template <class IStream> AdjacencyList &input(IStream &is) {
        for (int i = 0; i < m; i++) {
            int u, v;
            T w{};
            is >> u >> v;
            if constexpr (!std::is_same_v<T, empty>) is >> w;
            if (oneindexed) --u, --v;
            _add_edge(u, v, w, i);
        }
        return *this;
    }

    using value_type = T;
    using edge_type = _Edge<T>;

    constexpr static bool directed() { return is_directed; }

    int n, m;
    bool oneindexed;
    _Edges<T> edges;

    int num_vertices() const { return n; }

    int num_edges() const { return m; }

    void edge_clear() {
        for (int i = 0; i < n; i++) (*this)[i].clear();
        edges.clear();
        m = 0;
    }

    void add_edge(int from, int to, T cost = T{}) {
        if (oneindexed) --from, --to;
        _add_edge(from, to, cost, m++);
    }

    void add_edge_naive(int from, int to, T cost = T{}) { _add_edge(from, to, cost, m++); }

  private:
    void _add_edge(int from, int to, T cost, int id) {
        (*this)[from].emplace_back(to, cost, from, id);
        if constexpr (!is_directed) (*this)[to].emplace_back(from, cost, to, id);
        edges.emplace_back(to, cost, from, id);
    }
};

template <class T, bool is_directed> struct AdjacencyMatrix : std::vector<_Edges<T>> {
    AdjacencyMatrix() = default;

    AdjacencyMatrix(int n_, bool is_one_indexed)
        : std::vector<_Edges<T>>(n_, _Edges<T>(n_)),
          n(n_),
          m(0),
          oneindexed(is_one_indexed) {}

    AdjacencyMatrix(int n_, int m_, bool is_one_indexed)
        : std::vector<_Edges<T>>(n_, _Edges<T>(n_)),
          n(n_),
          m(m_),
          oneindexed(is_one_indexed) {}

    AdjacencyMatrix(int n_, const _Edges<T> &edges_, bool is_one_indexed)
        : std::vector<_Edges<T>>(n_, _Edges<T>(n_)),
          n(n_),
          m(0),
          oneindexed(is_one_indexed) {
        for (auto &e : edges_) { _add_edge(e.from, e.to, e.cost, m++); }
    }

    template <class IStream> AdjacencyMatrix &input(IStream &is) {
        for (int i = 0; i < m; i++) {
            int u, v;
            T w{};
            is >> u >> v;
            if constexpr (!std::is_same_v<T, empty>) is >> w;
            if (oneindexed) --u, --v;
            _add_edge(u, v, w, i);
        }
        return *this;
    }

    using value_type = T;
    using edge_type = _Edge<T>;

    constexpr static bool directed() { return is_directed; }

    int n, m;
    bool oneindexed;
    _Edges<T> edges;

    int num_vertices() const { return n; }

    int num_edges() const { return m; }

    void edge_clear() {
        for (int i = 0; i < n; i++) (*this)[i].clear();
        m = 0;
    }

    void add_edge(int from, int to, T cost = T{}) {
        if (oneindexed) --from, --to;
        _add_edge(from, to, cost, m++);
    }

    void add_edge_naive(int from, int to, T cost = T{}) { _add_edge(from, to, cost, m++); }

  private:
    void _add_edge(int from, int to, T cost, int id) {
        (*this)[from][to] = _Edge<T>(to, cost, from, id);
        if constexpr (!is_directed) (*this)[to][from] = _Edge<T>(from, cost, to, id);
        edges.emplace_back(to, cost, from, id);
    }
};

template <class T, class IStream>
_Edges<T> &input(_Edges<T> &edges, bool is_one_indexed, IStream &is) {
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

} // namespace kk2

#endif // GRAPH_GRAPH_TEMPLATE_HPP
