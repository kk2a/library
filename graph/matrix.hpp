#ifndef KK2_GRAPH_MATRIX_HPP
#define KK2_GRAPH_MATRIX_HPP 1

#include <span>
#include <vector>

#include "detail/graph_base.hpp"
#include "matrix_edge.hpp"

namespace kk2 {

namespace graph {

template <class T, bool is_directed>
struct AdjacencyMatrix
    : detail::GraphBase<T, is_directed, false, false> {
    using base = detail::GraphBase<T, is_directed, false, false>;
    using base::edges;
    using base::num_edges;
    using base::weighted;

    using value_type = T;
    using out_edge_type = _MatrixEdgeProxy<T, false>;
    using out_edges = std::vector<int>;
    using adjacency_container = std::vector<out_edges>;
    using edge_type = _Edge<T>;
    using edge_collection = _Edges<T>;

    adjacency_container data;
    mutable T null_cost{};

    AdjacencyMatrix() = default;
    AdjacencyMatrix(int n_) : data(n_, out_edges(n_, -1)) {}
    template <InputStream IStream>
    AdjacencyMatrix(int n_, int m_, IStream &is, bool oneindexed = false)
        : data(n_, out_edges(n_, -1)) {
        edges.reserve(m_);
        _input(is, m_, oneindexed);
    }
    AdjacencyMatrix(int n_, const edge_collection &edges_) : data(n_, out_edges(n_, -1)) {
        edges.reserve(edges_.size());
        for (const auto &e : edges_) _add_edge_with_id(e.from, e.to, _edge_cost(e), e.id);
    }

    int num_vertices() const { return data.size(); }
    int size() const { return num_vertices(); }
    _MatrixRowView<T, false> operator[](int k) {
        return {std::span<int>(data[k]), &edges, &null_cost, k};
    }
    _MatrixRowView<T, true> operator[](int k) const {
        return {std::span<const int>(data[k]), &edges, &null_cost, k};
    }
    void edge_clear() { *this = AdjacencyMatrix(num_vertices()); }
    void add_edge(int from, int to, T cost = T{}) { _add_edge<false>(from, to, cost, num_edges()); }
    void add_vertex(int n = 1) {
        int now = num_vertices();
        data.resize(now + n, out_edges(now + n, -1));
        for (auto &d : data) d.resize(now + n, -1);
    }

    template <InputStream IStream>
    AdjacencyMatrix &input(IStream &is, bool oneindexed = false) {
        for (int i = 0; i < num_edges(); ++i) {
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
        for (int i = 0; i < m; ++i) {
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
        for (int i = 0; i < num_vertices(); ++i) {
            os << "  " << i << ": [";
            for (int j = 0; j < (int)data[i].size(); ++j) {
                if (j) os << ", ";
                (*this)[i][j].debug_output(os);
            }
            os << "]\n";
        }
        os << "]\n";
    }

  private:
    template <bool update = false> void _add_edge(int from, int to, T cost, int id) {
        data[from][to] = id;
        if constexpr (!is_directed) data[to][from] = id;
        if constexpr (update) edges[id] = edge_type(to, cost, from, id);
        else edges.emplace_back(to, cost, from, id);
    }

    void _add_edge_with_id(int from, int to, T cost, int id) {
        data[from][to] = id;
        if constexpr (!is_directed) data[to][from] = id;
        edges.emplace_back(to, cost, from, id);
    }

  public:
    AdjacencyMatrix reverse() const {
        AdjacencyMatrix result(num_vertices());
        result.edges.reserve(edges.size());
        for (const auto &e : edges) result._add_edge_with_id(e.to, e.from, _edge_cost(e), e.id);
        return result;
    }

};

} // namespace graph

template <typename T> using WAdjMat = graph::AdjacencyMatrix<T, false>;
template <typename T> using DWAdjMat = graph::AdjacencyMatrix<T, true>;
using AdjMat = graph::AdjacencyMatrix<graph::empty, false>;
using DAdjMat = graph::AdjacencyMatrix<graph::empty, true>;

} // namespace kk2

#endif // KK2_GRAPH_MATRIX_HPP
