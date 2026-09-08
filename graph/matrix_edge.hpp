#ifndef KK2_GRAPH_MATRIX_EDGE_HPP
#define KK2_GRAPH_MATRIX_EDGE_HPP 1

#include <span>
#include <type_traits>

#include "edge.hpp"

namespace kk2::graph {

template <class T, bool is_const> struct _MatrixEdgeProxy {
  private:
    using id_reference = std::conditional_t<is_const, const int &, int &>;
    using cost_reference = std::conditional_t<is_const, const T &, T &>;

  public:
    int from, to;
    id_reference id;
    cost_reference cost;

    _MatrixEdgeProxy(int from_, int to_, id_reference id_, cost_reference cost_)
        : from(from_),
          to(to_),
          id(id_),
          cost(cost_) {}

    operator int() const { return to; }

    template <class OStream>
    void debug_output(OStream &os) const {
        os << '(' << id << ", " << from << "->" << to;
        if constexpr (!std::is_same_v<T, empty>) os << ":" << cost;
        os << ')';
    }
};

template <class T, bool is_const> class _MatrixRowView {
    using edge_collection = _Edges<T>;
    using slot_span = std::conditional_t<is_const, std::span<const int>, std::span<int>>;
    using edge_pointer = std::conditional_t<is_const, const edge_collection *, edge_collection *>;
    using cost_pointer = std::conditional_t<is_const, const T *, T *>;

    slot_span slots;
    edge_pointer edges;
    cost_pointer null_cost;
    int from;

  public:
    using value_type = _MatrixEdgeProxy<T, is_const>;

    _MatrixRowView(slot_span slots_, edge_pointer edges_, cost_pointer null_cost_, int from_)
        : slots(slots_),
          edges(edges_),
          null_cost(null_cost_),
          from(from_) {}

  private:
    cost_pointer get_cost(int id) const {
        if constexpr (std::is_same_v<T, empty>) return null_cost;
        else return id == -1 ? null_cost : &(*edges)[id].cost;
    }

  public:
    value_type operator[](int to) const {
        const int id = slots[to];
        return {from, to, slots[to], *get_cost(id)};
    }
    int size() const { return slots.size(); }
};

} // namespace kk2::graph

#endif // KK2_GRAPH_MATRIX_EDGE_HPP
