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

template <class T> struct _Edges : public std::vector<_Edge<T>> {
    using std::vector<_Edge<T>>::vector;

    template <class IStream, is_istream_t<IStream> * = nullptr>
    _Edges &input(IStream &is, bool is_one_indexed = false) {
        for (int i = 0; i < (int)this->size(); i++) {
            int u, v;
            T w{};
            is >> u >> v;
            if (is_one_indexed) --u, --v;
            if constexpr (!std::is_same_v<T, empty>) is >> w;
            (*this)[i] = _Edge<T>(v, w, u, i);
        }
        return *this;
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend _Edges &input(_Edges &edges, IStream &is, bool is_one_indexed = false) {
        return edges.input(is, is_one_indexed);
    }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    void debug_output(OStream &os) const {
        os << '[';
        for (int i = 0; i < (int)this->size(); i++) {
            if (i) os << ", ";
            os << (*this)[i];
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
};

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

} // namespace graph

template <typename T> using WEdge = graph::_Edge<T>;
template <typename T> using WEdges = graph::_Edges<T>;
using Edge = graph::_Edge<graph::empty>;
using Edges = graph::_Edges<graph::empty>;

} // namespace kk2

#endif // GRAPH_EDGE_HPP
