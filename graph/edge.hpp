#ifndef GRAPH_EDGE_HPP
#define GRAPH_EDGE_HPP 1

#include <type_traits>
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

template <class T, class IStream, is_istream_t<IStream> * = nullptr>
_Edges<T> &input(IStream &is, _Edges<T> &edges, bool is_one_indexed = false) {
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

template <class T, std::enable_if_t<std::is_same_v<T, empty>> * = nullptr>
void add_edge(_Edges<T> &edges, int from, int to) {
    edges.emplace_back(to, empty{}, from, (int)edges.size());
}

template <class T, std::enable_if_t<!std::is_same_v<T, empty>> * = nullptr>
void add_edge(_Edges<T> &edges, int from, int to, T cost) {
    edges.emplace_back(to, cost, from, (int)edges.size());
}

} // namespace graph

template <typename T> using WEdge = graph::_Edge<T>;
template <typename T> using WEdges = graph::_Edges<T>;
using Edge = graph::_Edge<graph::empty>;
using Edges = graph::_Edges<graph::empty>;
using graph::add_edge;
using graph::input;


} // namespace kk2

#endif // GRAPH_EDGE_HPP
