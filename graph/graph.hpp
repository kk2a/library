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

    friend std::ostream &operator<<(std::ostream &os, const WeightedEdge &e) {
        if (std::is_same_v<T, bool>) return os << e.from << "->" << e.to;
        return os << e.from << "->" << e.to << ":" << e.cost;
    }
};
template <class T> using WeightedEdges = std::vector<WeightedEdge<T>>;

template <class T, bool is_directed = false>
struct WeightedGraph : std::vector<WeightedEdges<T>> {
    WeightedGraph(int n_ = 0, bool is_one_indexed = true)
        : std::vector<WeightedEdges<T>>(n_),
          n(n_),
          m(0),
          oneindexed(is_one_indexed) {}

    WeightedGraph(int n_, int m_, bool is_one_indexed = true)
        : std::vector<WeightedEdges<T>>(n_),
          n(n_),
          m(m_),
          oneindexed(is_one_indexed) {
        input();
    }

    WeightedGraph(int n_,
                  const WeightedEdges<T> &edges_,
                  bool is_one_indexed = true)
        : std::vector<WeightedEdges<T>>(n_),
          n(n_),
          m(0),
          oneindexed(is_one_indexed) {
        for (auto &e : edges_) { _add_edge(e.from, e.to, e.cost, m++); }
    }

    using value_type = T;
    using edge_type = WeightedEdge<T>;

    constexpr static bool directed() { return is_directed; }

    int n, m;
    bool oneindexed;
    WeightedEdges<T> edges;

    int num_vertices() const { return n; }

    int num_edges() const { return m; }

    void clear() {
        for (int i = 0; i < n; i++) (*this)[i].clear();
        edges.clear();
        m = 0;
    }

    WeightedGraph &inplace_rev() {
        static_assert(is_directed);
        WeightedEdges<T> rev(m);
        for (int i = 0; i < m; i++) { rev[i] = edges[i].rev(); }
        clear();
        for (auto &e : rev) _add_edge(e.from, e.to, e.cost, m++);
        return *this;
    }

    WeightedGraph rev() const {
        static_assert(is_directed);
        WeightedGraph res(n);
        res.m = m;
        for (int i = 0; i < m; i++) {
            res._add_edge(edges[i].to, edges[i].from, edges[i].cost, i);
        }
        return res;
    }

  private:
    void input() {
        for (int i = 0; i < m; i++) {
            int u, v;
            T w;
            std::cin >> u >> v >> w;
            if (oneindexed) {
                u--;
                v--;
            }
            _add_edge(u, v, w, i);
        }
    }

  public:
    void add_edge(int from, int to, T cost) {
        if (oneindexed) {
            from--;
            to--;
        }
        _add_edge(from, to, cost, m++);
    }

    void add_edge_naive(int from, int to, T cost) {
        _add_edge(from, to, cost, m++);
    }

  private:
    void _add_edge(int from, int to, T cost, int id) {
        (*this)[from].emplace_back(to, cost, from, id);
        if constexpr (!is_directed)
            (*this)[to].emplace_back(from, cost, to, id);
        edges.emplace_back(to, cost, from, id);
    }
};

struct UnWeightedEdge {
    int from, to, id;

    UnWeightedEdge(int to_, int from_ = -1, int id_ = -1)
        : from(from_),
          to(to_),
          id(id_) {}

    UnWeightedEdge() : from(-1), to(-1), id(-1) {}

    operator int() const { return to; }

    UnWeightedEdge rev() const { return UnWeightedEdge(from, to, id); }

    friend std::ostream &operator<<(std::ostream &os, const UnWeightedEdge &e) {
        return os << e.from << "->" << e.to;
    }
};

using UnWeightedEdges = std::vector<UnWeightedEdge>;

template <bool is_directed = false, bool is_functional = false>
struct UnWeightedGraph : std::vector<UnWeightedEdges> {
    UnWeightedGraph(int n_ = 0, bool is_one_indexed = true)
        : std::vector<UnWeightedEdges>(n_),
          n(n_),
          m(0),
          oneindexed(is_one_indexed) {}

    UnWeightedGraph(int n_, int m_, bool is_one_indexed = true)
        : std::vector<UnWeightedEdges>(n_),
          n(n_),
          m(m_),
          oneindexed(is_one_indexed) {
        input();
    }

    UnWeightedGraph(int n_,
                    const UnWeightedEdges &edges_,
                    bool is_one_indexed = true)
        : std::vector<UnWeightedEdges>(n_),
          n(n_),
          m(0),
          oneindexed(is_one_indexed) {
        for (auto &e : edges_) { _add_edge(e.from, e.to, m++); }
    }

    constexpr static bool directed() { return is_directed; }

    constexpr static bool functional() { return is_functional; }

    using edge_type = UnWeightedEdge;

    int n, m;
    bool oneindexed;
    UnWeightedEdges edges;

    int num_vertices() const { return n; }

    int num_edges() const { return m; }

    void clear() {
        for (int i = 0; i < n; i++) (*this)[i].clear();
        edges.clear();
        m = 0;
    }

    UnWeightedGraph &inplace_rev() {
        static_assert(is_directed);
        std::vector<std::pair<int, int>> rev(m);
        for (int i = 0; i < m; i++) { rev[i] = {edges[i].to, edges[i].from}; }
        clear();
        for (auto &&[u, v] : rev) _add_edge(u, v, m++);
        return *this;
    }

    UnWeightedGraph rev() const {
        static_assert(is_directed);
        UnWeightedGraph res(n);
        res.m = m;
        for (int i = 0; i < m; i++) {
            res._add_edge(edges[i].to, edges[i].from, i);
        }
        return res;
    }

  private:
    void input() {
        if constexpr (is_functional) {
            functional_graph();
            return;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            if (oneindexed) {
                u--;
                v--;
            }
            _add_edge(u, v, i);
        }
    }

    void functional_graph() {
        static_assert(is_directed);
        assert(n == m);
        for (int i = 0; i < n; i++) {
            int u;
            std::cin >> u;
            if (oneindexed) u--;
            _add_edge(i, u, i);
        }
    }

  public:
    void add_edge(int from, int to) {
        if (oneindexed) {
            from--;
            to--;
        }
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


template <class T, bool is_directed = false>
using WGraph = WeightedGraph<T, is_directed>;
template <bool is_directed = false, bool is_functional = false>
using Graph = UnWeightedGraph<is_directed, is_functional>;

} // namespace kk2

#endif // GRAPH_GRAPH_TEMPLATE_HPP
