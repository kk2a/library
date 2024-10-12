#ifndef GRAPH_GRAPH_TEMPLATE_HPP
#define GRAPH_GRAPH_TEMPLATE_HPP 1

#include <cassert>
#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>

namespace kk2 {

template <class T> struct Edge {
    int from, to, id;
    T cost;

    Edge(int to_, T cost_, int from_ = -1, int id_ = -1)
        : from(from_),
          to(to_),
          id(id_),
          cost(cost_) {}

    Edge() : from(-1), to(-1), id(-1), cost(0) {}

    operator int() const { return to; }

    Edge rev() const { return Edge(from, cost, to, id); }

    template <class OStream> friend OStream &operator<<(OStream &os, const Edge &e) {
        return os << e.from << " -> " << e.to << " : " << e.cost;
    }
};
template <class T> using Edges = std::vector<Edge<T>>;

template <class T, bool is_directed, bool is_functional>
struct AdjacencyList : std::vector<Edges<T>> {
    AdjacencyList() = default;

    AdjacencyList(int n_, bool is_one_indexed)
        : std::vector<Edges<T>>(n_),
          n(n_),
          m(0),
          oneindexed(is_one_indexed) {}

    AdjacencyList(int n_, int m_, bool is_one_indexed)
        : std::vector<Edges<T>>(n_),
          n(n_),
          m(m_),
          oneindexed(is_one_indexed) {}

    AdjacencyList(int n_, const Edges<T> &edges_, bool is_one_indexed)
        : std::vector<Edges<T>>(n_),
          n(n_),
          m(0),
          oneindexed(is_one_indexed) {
        for (auto &e : edges_) { _add_edge(e.from, e.to, e.cost, m++); }
    }

    template <class IStream> AdjacencyList &input(IStream &is) {
        if constexpr (is_functional) {
            assert(n == m);
            for (int i = 0; i < n; i++) {
                int u;
                is >> u;
                if (oneindexed) --u;
                _add_edge(i, u, T(), i);
            }
        } else {
            for (int i = 0; i < m; i++) {
                int u, v;
                T w{};
                is >> u >> v;
                if constexpr (!std::is_same_v<T, bool>) is >> w;
                if (oneindexed) --u, --v;
                _add_edge(u, v, w, i);
            }
        }
        return *this;
    }

    using value_type = T;
    using edge_type = Edge<T>;

    constexpr static bool directed() { return is_directed; }

    constexpr static bool functional() { return is_functional; }

    int n, m;
    bool oneindexed;
    Edges<T> edges;

    int num_vertices() const { return n; }

    int num_edges() const { return m; }

    void edge_clear() {
        for (int i = 0; i < n; i++) (*this)[i].clear();
        edges.clear();
        m = 0;
    }

    AdjacencyList &inplace_rev() {
        static_assert(is_directed);
        Edges<T> rev(m);
        for (int i = 0; i < m; i++) rev[i] = edges[i].rev();
        edge_clear();
        for (auto &e : rev) _add_edge(e.from, e.to, e.cost, m++);
        return *this;
    }

    AdjacencyList rev() const {
        static_assert(is_directed);
        AdjacencyList res(n);
        res.m = m;
        for (int i = 0; i < m; i++) res._add_edge(edges[i].to, edges[i].from, edges[i].cost, i);
        return res;
    }

    void add_edge(int from, int to, T cost = T()) {
        if (oneindexed) --from, --to;
        _add_edge(from, to, cost, m++);
    }

    void add_edge_naive(int from, int to, T cost = T()) { _add_edge(from, to, cost, m++); }

  private:
    void _add_edge(int from, int to, T cost, int id) {
        (*this)[from].emplace_back(to, cost, from, id);
        if constexpr (!is_directed) (*this)[to].emplace_back(from, cost, to, id);
        edges.emplace_back(to, cost, from, id);
    }
};

template <class T, bool is_directed, bool is_functional>
struct AdjacencyMatrix : std::vector<Edges<T>> {
    AdjacencyMatrix() = default;

    AdjacencyMatrix(int n_, bool is_one_indexed)
        : std::vector<Edges<T>>(n_, Edges<T>(n_)),
          n(n_),
          m(0),
          oneindexed(is_one_indexed) {}

    AdjacencyMatrix(int n_, int m_, bool is_one_indexed)
        : std::vector<Edges<T>>(n_, Edges<T>(n_)),
          n(n_),
          m(m_),
          oneindexed(is_one_indexed) {}

    AdjacencyMatrix(int n_, const Edges<T> &edges_, bool is_one_indexed)
        : std::vector<Edges<T>>(n_, Edges<T>(n_)),
          n(n_),
          m(0),
          oneindexed(is_one_indexed) {
        for (auto &e : edges_) { _add_edge(e.from, e.to, e.cost, m++); }
    }

    template <class IStream> AdjacencyMatrix &input(IStream &is) {
        if constexpr (is_functional) {
            assert(n == m);
            for (int i = 0; i < n; i++) {
                int u;
                is >> u;
                if (oneindexed) --u;
                _add_edge(i, u, T(), i);
            }
        } else {
            for (int i = 0; i < m; i++) {
                int u, v;
                T w{};
                is >> u >> v;
                if constexpr (!std::is_same_v<T, bool>) is >> w;
                if (oneindexed) --u, --v;
                _add_edge(u, v, w, i);
            }
        }
        return *this;
    }

    using value_type = T;
    using edge_type = Edge<T>;

    constexpr static bool directed() { return is_directed; }

    constexpr static bool functional() { return is_functional; }

    int n, m;
    bool oneindexed;
    Edges<T> edges;

    int num_vertices() const { return n; }

    int num_edges() const { return m; }

    void edge_clear() {
        for (int i = 0; i < n; i++) (*this)[i].clear();
        m = 0;
    }

    AdjacencyMatrix &inplace_rev() {
        static_assert(is_directed);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { std::swap((*this)[i][j], (*this)[j][i]); }
        }
        return *this;
    }

    AdjacencyMatrix rev() const {
        static_assert(is_directed);
        return AdjacencyMatrix(*this).inplace_rev();
    }

    void add_edge(int from, int to, T cost = T()) {
        if (oneindexed) --from, --to;
        _add_edge(from, to, cost, m++);
    }

    void add_edge_naive(int from, int to, T cost = T()) { _add_edge(from, to, cost, m++); }

  private:
    void _add_edge(int from, int to, T cost, int id) {
        (*this)[from][to] = Edge<T>(to, cost, from, id);
        if constexpr (!is_directed) (*this)[to][from] = Edge<T>(from, cost, to, id);
        edges.emplace_back(to, cost, from, id);
    }
};

template <typename T> using WAdjList = AdjacencyList<T, false, false>;
template <typename T> using DWAdjList = AdjacencyList<T, true, false>;
using AdjList = AdjacencyList<bool, false, false>;
using DAdjList = AdjacencyList<bool, true, false>;
using FAdjList = AdjacencyList<bool, true, true>;

template <typename T> using WAdjMat = AdjacencyMatrix<T, false, false>;
template <typename T> using DWAdjMat = AdjacencyMatrix<T, true, false>;
using AdjMat = AdjacencyMatrix<bool, false, false>;
using DAdjMat = AdjacencyMatrix<bool, true, false>;
using FAdjMat = AdjacencyMatrix<bool, true, true>;

} // namespace kk2

#endif // GRAPH_GRAPH_TEMPLATE_HPP
