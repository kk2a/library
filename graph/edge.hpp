#ifndef KK2_GRAPH_EDGE_HPP
#define KK2_GRAPH_EDGE_HPP 1

#include <type_traits>
#include <vector>

#include "../type_traits/io.hpp"

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
    _Edge() : from(-1), to(-1), id(-1) {}
    operator int() const { return to; }
    inline _Edge rev() const { return _Edge(from, cost, to, id); }

    template <OutputStream OStream>
    void debug_output(OStream &os) const {
        os << '(' << id << ", " << from << "->" << to;
        if constexpr (!std::is_same_v<T, empty>) os << ":" << cost;
        os << ')';
    }
};

template <> struct _Edge<empty> {
    int from, to, id;

    _Edge(int to_, empty = {}, int from_ = -1, int id_ = -1)
        : from(from_),
          to(to_),
          id(id_) {}
    _Edge() : from(-1), to(-1), id(-1) {}
    operator int() const { return to; }
    inline _Edge rev() const { return _Edge(from, {}, to, id); }

    template <OutputStream OStream>
    void debug_output(OStream &os) const {
        os << '(' << id << ", " << from << "->" << to << ')';
    }
};

template <class T> T _edge_cost(const _Edge<T> &edge) {
    if constexpr (std::is_same_v<T, empty>) return {};
    else return edge.cost;
}

template <class T> struct _Edges : public std::vector<_Edge<T>> {
    using std::vector<_Edge<T>>::vector;

    template <InputStream IStream>
    _Edges(int m, IStream &is, bool is_one_indexed = false)
        : std::vector<_Edge<T>>(m) {
        _input(is, is_one_indexed);
    }

    template <OutputStream OStream>
    void debug_output(OStream &os) const {
        os << '[';
        for (int i = 0; i < (int)this->size(); i++) {
            if (i) os << ", ";
            (*this)[i].debug_output(os);
        }
        os << ']';
    }

    _Edges &add_edge(int from, int to, T cost = T{}) {
        this->emplace_back(to, cost, from, this->size());
        return *this;
    }

    friend _Edges &add_edge(_Edges &edges, int from, int to, T cost = T{}) {
        edges.emplace_back(to, cost, from, edges.size());
        return edges;
    }

  private:
    template <InputStream IStream>
    void _input(IStream &is, bool is_one_indexed) {
        for (int i = 0; i < (int)this->size(); ++i) {
            int u, v;
            T w{};
            is >> u >> v;
            if (is_one_indexed) --u, --v;
            if constexpr (!std::is_same_v<T, empty>) is >> w;
            (*this)[i] = _Edge<T>(v, w, u, i);
        }
    }
};

} // namespace graph

template <typename T> using WEdge = graph::_Edge<T>;
template <typename T> using WEdges = graph::_Edges<T>;
using Edge = graph::_Edge<graph::empty>;
using Edges = graph::_Edges<graph::empty>;

} // namespace kk2

#endif // KK2_GRAPH_EDGE_HPP
