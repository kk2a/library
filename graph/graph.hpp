#ifndef GRAPH_GRAPH_TEMPLATE_HPP
#define GRAPH_GRAPH_TEMPLATE_HPP 1

#include <cassert>
#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>

namespace kk2 {

template <class T> struct WeightedEdge {
    int from, to, id;
    T cost;

    WeightedEdge(int to_, T cost_, int from_ = -1, int id_ = -1)
        : from(from_),
          to(to_),
          id(id_),
          cost(cost_) {}

    WeightedEdge() : from(-1), to(-1), id(-1), cost(0) {}

    operator int() const { return to; }

    WeightedEdge rev() const { return WeightedEdge(from, cost, to, id); }

    template <class OStream> friend OStream &operator<<(OStream &os, const WeightedEdge &e) {
        return os << e.from << " -> " << e.to << " : " << e.cost;
    }
};
template <class T> using WeightedEdges = std::vector<WeightedEdge<T>>;

template <class T, bool is_directed = false>
struct WeightedAdjacencyList : std::vector<WeightedEdges<T>> {
    WeightedAdjacencyList() = default;

    WeightedAdjacencyList(int n_, bool is_one_indexed)
        : std::vector<WeightedEdges<T>>(n_),
          n(n_),
          m(0),
          oneindexed(is_one_indexed) {}

    WeightedAdjacencyList(int n_, int m_, bool is_one_indexed)
        : std::vector<WeightedEdges<T>>(n_),
          n(n_),
          m(m_),
          oneindexed(is_one_indexed) {}

    WeightedAdjacencyList(int n_, const WeightedEdges<T> &edges_, bool is_one_indexed)
        : std::vector<WeightedEdges<T>>(n_),
          n(n_),
          m(0),
          oneindexed(is_one_indexed) {
        for (auto &e : edges_) { _add_edge(e.from, e.to, e.cost, m++); }
    }

    template <class IStream> WeightedAdjacencyList &input(IStream &is) {
        for (int i = 0; i < m; i++) {
            int u, v;
            T w;
            is >> u >> v >> w;
            if (oneindexed) --u, --v;
            _add_edge(u, v, w, i);
        }
        return *this;
    }

    using value_type = T;
    using edge_type = WeightedEdge<T>;

    constexpr static bool directed() { return is_directed; }

    int n, m;
    bool oneindexed;
    WeightedEdges<T> edges;

    int num_vertices() const { return n; }

    int num_edges() const { return m; }

    void edge_clear() {
        for (int i = 0; i < n; i++) (*this)[i].clear();
        edges.clear();
        m = 0;
    }

    WeightedAdjacencyList &inplace_rev() {
        static_assert(is_directed);
        WeightedEdges<T> rev(m);
        for (int i = 0; i < m; i++) rev[i] = edges[i].rev();
        edge_clear();
        for (auto &e : rev) _add_edge(e.from, e.to, e.cost, m++);
        return *this;
    }

    WeightedAdjacencyList rev() const {
        static_assert(is_directed);
        WeightedAdjacencyList res(n);
        res.m = m;
        for (int i = 0; i < m; i++) res._add_edge(edges[i].to, edges[i].from, edges[i].cost, i);
        return res;
    }

    void add_edge(int from, int to, T cost) {
        if (oneindexed) --from, --to;
        _add_edge(from, to, cost, m++);
    }

    void add_edge_naive(int from, int to, T cost) { _add_edge(from, to, cost, m++); }

  private:
    void _add_edge(int from, int to, T cost, int id) {
        (*this)[from].emplace_back(to, cost, from, id);
        if constexpr (!is_directed) (*this)[to].emplace_back(from, cost, to, id);
        edges.emplace_back(to, cost, from, id);
    }
};

struct UnWeightedEdge {
    int from, to, id;

    UnWeightedEdge(int to_, int from_ = -1, int id_ = -1) : from(from_), to(to_), id(id_) {}

    UnWeightedEdge() : from(-1), to(-1), id(-1) {}

    operator int() const { return to; }

    UnWeightedEdge rev() const { return UnWeightedEdge(from, to, id); }

    friend std::ostream &operator<<(std::ostream &os, const UnWeightedEdge &e) {
        return os << e.from << "->" << e.to;
    }
};

using UnWeightedEdges = std::vector<UnWeightedEdge>;

template <bool is_directed = false, bool is_functional = false>
struct UnWeightedAdjacencyList : std::vector<UnWeightedEdges> {
    UnWeightedAdjacencyList() = default;

    UnWeightedAdjacencyList(int n_, bool is_one_indexed)
        : std::vector<UnWeightedEdges>(n_),
          n(n_),
          m(0),
          oneindexed(is_one_indexed) {}

    UnWeightedAdjacencyList(int n_, int m_, bool is_one_indexed)
        : std::vector<UnWeightedEdges>(n_),
          n(n_),
          m(m_),
          oneindexed(is_one_indexed) {}

    UnWeightedAdjacencyList(int n_, const UnWeightedEdges &edges_, bool is_one_indexed)
        : std::vector<UnWeightedEdges>(n_),
          n(n_),
          m(0),
          oneindexed(is_one_indexed) {
        for (auto &e : edges_) { _add_edge(e.from, e.to, m++); }
    }

    template <class IStream> UnWeightedAdjacencyList &input(IStream &is) {
        if constexpr (is_functional) {
            assert(n == m);
            for (int i = 0; i < n; i++) {
                int u;
                is >> u;
                if (oneindexed) --u;
                _add_edge(i, u, i);
            }
        } else {
            for (int i = 0; i < m; i++) {
                int u, v;
                is >> u >> v;
                if (oneindexed) --u, --v;
                _add_edge(u, v, i);
            }
        }
        return *this;
    }

    constexpr static bool directed() { return is_directed; }

    constexpr static bool functional() { return is_functional; }

    using edge_type = UnWeightedEdge;

    int n, m;
    bool oneindexed;
    UnWeightedEdges edges;

    int num_vertices() const { return n; }

    int num_edges() const { return m; }

    void edge_clear() {
        for (int i = 0; i < n; i++) (*this)[i].clear();
        edges.clear();
        m = 0;
    }

    UnWeightedAdjacencyList &inplace_rev() {
        static_assert(is_directed);
        std::vector<std::pair<int, int>> rev(m);
        for (int i = 0; i < m; i++) rev[i] = {edges[i].to, edges[i].from};
        edge_clear();
        for (auto &&[u, v] : rev) _add_edge(u, v, m++);
        return *this;
    }

    UnWeightedAdjacencyList rev() const {
        static_assert(is_directed);
        UnWeightedAdjacencyList res(n);
        res.m = m;
        for (int i = 0; i < m; i++) res._add_edge(edges[i].to, edges[i].from, i);
        return res;
    }

    void add_edge(int from, int to) {
        if (oneindexed) --from, --to;
        _add_edge(from, to, m++);
    }

    void add_edge_naive(int from, int to) { _add_edge(from, to, m++); }

  private:
    void _add_edge(int from, int to, int id) {
        (*this)[from].emplace_back(to, from, id);
        if constexpr (!is_directed) (*this)[to].emplace_back(from, to, id);
        edges.emplace_back(to, from, id);
    }
};

template <typename T> using WAdjList = WeightedAdjacencyList<T, false>;
template <typename T> using DWAdjList = WeightedAdjacencyList<T, true>;

using AdjList = UnWeightedAdjacencyList<false, false>;
using DAdjList = UnWeightedAdjacencyList<true, false>;
using FAdjList = UnWeightedAdjacencyList<true, true>;

} // namespace kk2

#endif // GRAPH_GRAPH_TEMPLATE_HPP
