#ifndef KK2_GRAPH_STATIC_GRAPH_HPP
#define KK2_GRAPH_STATIC_GRAPH_HPP 1

#include <cassert>
#include <type_traits>
#include <vector>

#include "../type_traits/type_traits.hpp"
#include "edge.hpp"

namespace kk2 {

namespace graph {

template <class T, bool is_directed> struct StaticAdjacencyList {
    using value_type = T;
    using edge_type = _Edge<T>;
    using edge_container = _Edges<T>;

    static constexpr bool directed = is_directed;
    static constexpr bool weighted = !std::is_same_v<T, empty>;
    static constexpr bool adjacency_list = true;
    static constexpr bool adjacency_matrix = false;
    static constexpr bool static_graph = true;

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

    int num_vertices() const { return head.size(); }

    int size() const { return head.size(); }

    int num_edges() const { return edges.size(); }

    template <class It> struct Es {
        It b, e;

        It begin() const { return b; }

        It end() const { return e; }

        int size() const { return int(e - b); }

        auto &&operator[](int k) const { return b[k]; }
    };

    Es<typename _Edges<T>::iterator> operator[](int k) {
        if (!is_built) build();
        if (k == (int)head.size() - 1)
            return Es<typename _Edges<T>::iterator>{data.begin() + head[k], data.end()};
        return Es<typename _Edges<T>::iterator>{data.begin() + head[k], data.begin() + head[k + 1]};
    }

    const Es<typename _Edges<T>::const_iterator> operator[](int k) const {
        assert(is_built);
        if (k == (int)head.size() - 1)
            return Es<typename _Edges<T>::const_iterator>{data.begin() + head[k], data.end()};
        return Es<typename _Edges<T>::const_iterator>{data.begin() + head[k],
                                                      data.begin() + head[k + 1]};
    }

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

    void build() {
        is_built = true;
        for (unsigned int i = 1; i < head.size(); ++i) head[i] += head[i - 1];
        data.resize(head.back());
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
        if constexpr (!is_directed) {
            if (from != to) head[to]++;
        }
        if constexpr (update) edges[id] = _Edge<T>(to, cost, from, id);
        else edges.emplace_back(to, cost, from, id);
    }

  public:
    StaticAdjacencyList reverse() const {
        StaticAdjacencyList res(num_vertices(), num_edges());
        for (auto &&e : edges) { res._add_edge<true>(e.to, e.from, e.cost, e.id); }
        res.build();
        return res;
    }
};

template <class G, std::enable_if_t<G::static_graph> * = nullptr> G reverse(const G &g) {
    return g.reverse();
}

} // namespace graph

template <typename T> using SWAdjList = graph::StaticAdjacencyList<T, false>;
template <typename T> using SDWAdjList = graph::StaticAdjacencyList<T, true>;
using SAdjList = graph::StaticAdjacencyList<graph::empty, false>;
using SDAdjList = graph::StaticAdjacencyList<graph::empty, true>;

using graph::reverse;

} // namespace kk2

#endif // KK2_GRAPH_STATIC_GRAPH_HPP
