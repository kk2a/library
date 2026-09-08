#ifndef KK2_GRAPH_STATIC_GRAPH_HPP
#define KK2_GRAPH_STATIC_GRAPH_HPP 1

#include <cassert>
#include <span>
#include <type_traits>
#include <vector>

#include "../type_traits/io.hpp"
#include "edge.hpp"

namespace kk2 {

namespace graph {

template <class T, bool is_directed> struct StaticAdjacencyList {
    using value_type = T;
    using out_edge_type = _Edge<T>;
    using out_edges = _Edges<T>;
    using adjacency_container = _Edges<T>;
    using edge_type = _Edge<T>;
    using edge_collection = _Edges<T>;

    static constexpr bool directed = is_directed;
    static constexpr bool weighted = !std::is_same_v<T, empty>;
    static constexpr bool adjacency_list = true;
    static constexpr bool adjacency_matrix = false;
    static constexpr bool static_graph = true;

    std::vector<int> head;
    edge_collection edges;
    adjacency_container data;
    bool is_built = false;

    StaticAdjacencyList() = default;
    StaticAdjacencyList(int n_) : head(n_) {}
    template <InputStream IStream>
    StaticAdjacencyList(int n_, int m_, IStream &is, bool oneindexed = false)
        : head(n_) {
        edges.reserve(m_);
        _input(is, m_, oneindexed);
        build();
    }
    StaticAdjacencyList(int n_, const edge_collection &edges_) : head(n_) {
        edges.reserve(edges_.size());
        for (auto &&e : edges_) _add_edge_with_id(e.from, e.to, e.cost, e.id);
        build();
    }

    inline int num_vertices() const { return head.size(); }
    inline int size() const { return head.size(); }
    inline int num_edges() const { return edges.size(); }
    void add_edge(int from, int to, T cost = T{}) {
        assert(!is_built);
        _add_edge<false>(from, to, cost, num_edges());
    }
    void add_vertex(int n = 1) {
        assert(!is_built);
        head.insert(head.end(), n, 0);
    }
    void edge_clear() { *this = StaticAdjacencyList(num_vertices()); }

    std::span<edge_type> operator[](int k) {
        assert(is_built);
        int e = k == (int)head.size() - 1 ? data.size() : head[k + 1];
        auto *begin = data.empty() ? nullptr : data.data() + head[k];
        return {begin, static_cast<size_t>(e - head[k])};
    }

    std::span<const edge_type> operator[](int k) const {
        assert(is_built);
        int e = k == (int)head.size() - 1 ? data.size() : head[k + 1];
        auto *begin = data.empty() ? nullptr : data.data() + head[k];
        return {begin, static_cast<size_t>(e - head[k])};
    }

    template <InputStream IStream>
    StaticAdjacencyList &input(IStream &is, bool oneindexed = false) {
        assert(!is_built);
        _input(is, edges.size(), oneindexed);
        build();
        return *this;
    }

    template <InputStream IStream>
    void _input(IStream &is, int m, bool oneindexed) {
        edges.clear();
        edges.reserve(m);
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
        assert(is_built);
        os << "[\n";
        for (int i = 0; i < num_vertices(); i++) {
            os << "  " << i << ": [";
            for (int j = 0;
                 j < (i == num_vertices() - 1 ? (int)data.size() : head[i + 1]) - head[i];
                 j++) {
                if (j) os << ", ";
                data[head[i] + j].debug_output(os);
            }
            os << "]\n";
        }
        os << "]\n";
    }

    void build() {
        if (is_built) return;
        is_built = true;
        for (unsigned int i = 1; i < head.size(); ++i) head[i] += head[i - 1];
        data.resize(head.empty() ? 0 : head.back());
        for (auto &&e : edges) {
            data[--head[e.from]] = e;
            if constexpr (!is_directed) {
                if (e.from != e.to) data[--head[e.to]] = e.rev();
            }
        }
    }

  private:
    template <bool update = false> void _add_edge(int from, int to, T cost, int id) {
        head[from]++;
        if (!is_directed and from != to) head[to]++;
        if constexpr (update) edges[id] = _Edge<T>(to, cost, from, id);
        else edges.emplace_back(to, cost, from, id);
    }

    void _add_edge_with_id(int from, int to, T cost, int id) {
        head[from]++;
        if (!is_directed and from != to) head[to]++;
        edges.emplace_back(to, cost, from, id);
    }

  public:
    StaticAdjacencyList reverse() const {
        StaticAdjacencyList res(num_vertices());
        res.edges.reserve(edges.size());
        for (auto &&e : edges) res._add_edge_with_id(e.to, e.from, e.cost, e.id);
        res.build();
        return res;
    }
};

} // namespace graph

template <typename T> using SWAdjList = graph::StaticAdjacencyList<T, false>;
template <typename T> using SDWAdjList = graph::StaticAdjacencyList<T, true>;
using SAdjList = graph::StaticAdjacencyList<graph::empty, false>;
using SDAdjList = graph::StaticAdjacencyList<graph::empty, true>;

} // namespace kk2

#endif // KK2_GRAPH_STATIC_GRAPH_HPP
