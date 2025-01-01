#ifndef GRAPH_STATIC_GRAPH_HPP
#define GRAPH_STATIC_GRAPH_HPP 1

#include <type_traits>
#include <vector>

#include "../type_traits/type_traits.hpp"
#include "edge.hpp"

namespace kk2 {

namespace graph {

template <class T, bool is_directed> struct StaticAdjacencyList {
    using value_type = T;
    using edge_type = _Edge<T>;

    using directed = std::integral_constant<bool, is_directed>;
    using weighted = std::integral_constant<bool, !std::is_same_v<T, empty>>;
    using adjacency_list = std::integral_constant<bool, true>;
    using adjacency_matrix = std::integral_constant<bool, false>;
    using static_graph = std::integral_constant<bool, true>;

    template <class It> struct Es {
        It b, e;

        It begin() const { return b; }

        It end() const { return e; }

        int size() const { return int(e - b); }

        auto &&operator[](int k) const { return b[k]; }
    };

    StaticAdjacencyList() = default;

    StaticAdjacencyList(int n_) : head(n_) {}

    StaticAdjacencyList(int n_, int m_) : head(n_), edges(m_) {}

    StaticAdjacencyList(int n_, const _Edges<T> &edges_) : head(n_), edges(edges_) {
        for (auto &&e : edges) {
            head[e.from]++;
            if constexpr (!is_directed) {
                if (e.from != e.to) head[e.to]++;
            }
        }
        build();
    }

    std::vector<int> head;
    _Edges<T> edges, data;
    bool is_built = false;

    template <class IStream, is_istream_t<IStream> * = nullptr>
    StaticAdjacencyList &input(IStream &is, bool oneindexed = false) {
        for (int i = 0; i < num_edges(); i++) {
            int u, v;
            T w{};
            is >> u >> v;
            if constexpr (!std::is_same_v<T, empty>) is >> w;
            if (oneindexed) --u, --v;
            _add_edge<true>(u, v, w, i);
        }

        build();
        return *this;
    }

    void add_edge(int from, int to, T cost = T{}) { _add_edge<false>(from, to, cost, num_edges()); }

    void add_vertex(int n = 1) { head.insert(head.end(), n, 0); }

    int num_vertices() const { return (int)head.size(); }

    int size() const { return (int)head.size(); }

    int num_edges() const { return (int)edges.size(); }

    void build() {
        is_built = true;
        for (int i = 1; i < (int)head.size(); ++i) head[i] += head[i - 1];
        data.resize(head.back());
        for (auto &&e : edges) {
            data[--head[e.from]] = e;
            if constexpr (!is_directed) {
                if (e.from != e.to) data[--head[e.to]] = e.rev();
            }
        }
    }

    Es<typename _Edges<T>::iterator> operator[](int k) {
        if (!is_built) build();
        if (k == (int)head.size() - 1)
            return Es<typename _Edges<T>::iterator>{data.begin() + head[k], data.end()};
        return Es<typename _Edges<T>::iterator>{data.begin() + head[k], data.begin() + head[k + 1]};
    }

    const Es<typename _Edges<T>::const_iterator> operator[](int k) const {
        if (k == (int)head.size() - 1)
            return Es<typename _Edges<T>::const_iterator>{data.begin() + head[k], data.end()};
        return Es<typename _Edges<T>::const_iterator>{data.begin() + head[k], data.begin() + head[k + 1]};
    }

  private:
    template <bool update = false> void _add_edge(int from, int to, T cost, int id) {
        if constexpr (update) edges[id] = _Edge<T>(to, cost, from, id);
        else edges.emplace_back(to, cost, from, id);
        head[from]++;
        if constexpr (!is_directed) {
            if (from != to) head[to]++;
        }
    }
};

template <class G, std::enable_if_t<G::static_graph::value> * = nullptr> G reverse(const G &g) {
    G res(g.num_vertices());
    for (auto &&e : g.edges) res.add_edge(e.to, e.from, e.cost);
    res.build();
    return res;
}

} // namespace graph

template <typename T> using SWAdjList = graph::StaticAdjacencyList<T, false>;
template <typename T> using SDWAdjList = graph::StaticAdjacencyList<T, true>;
using SAdjList = graph::StaticAdjacencyList<graph::empty, false>;
using SDAdjList = graph::StaticAdjacencyList<graph::empty, true>;

using graph::reverse;

} // namespace kk2

#endif // GRAPH_STATIC_GRAPH_HPP