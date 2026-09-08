#ifndef KK2_GRAPH_COMPACT_EDGE_HPP
#define KK2_GRAPH_COMPACT_EDGE_HPP 1

#include <compare>
#include <iterator>
#include <span>
#include <type_traits>
#include <utility>

#include "edge.hpp"

namespace kk2::graph {

template <class T, bool is_const> struct _AdjacencyEdgeProxy {
  private:
    using edge_type = _Edge<T>;
    using edge_reference = std::conditional_t<is_const, const edge_type &, edge_type &>;
    using id_reference = std::conditional_t<is_const, const int &, int &>;
    using cost_reference = std::conditional_t<is_const, const T &, T &>;

  public:
    int from;
    int to;
    id_reference id;
    cost_reference cost;

  private:
    static cost_reference get_cost(edge_reference edge) {
        if constexpr (std::is_same_v<T, empty>) {
            static T unused{};
            return unused;
        } else {
            return edge.cost;
        }
    }

  public:
    _AdjacencyEdgeProxy(int from_, id_reference id_, edge_reference edge)
        : from(from_),
          to(edge.from == from_ ? edge.to : edge.from),
          id(id_),
          cost(get_cost(edge)) {}

    operator int() const { return to; }

    template <class OStream> void debug_output(OStream &os) const {
        os << '(' << id << ", " << from << "->" << to;
        if constexpr (!std::is_same_v<T, empty>) os << ":" << cost;
        os << ')';
    }

    friend bool operator==(const _AdjacencyEdgeProxy &lhs, const _AdjacencyEdgeProxy &rhs) {
        return lhs.id == rhs.id;
    }

    friend void swap(_AdjacencyEdgeProxy &lhs, _AdjacencyEdgeProxy &rhs) {
        std::swap(lhs.id, rhs.id);
    }
};

template <class T, bool is_const> class _AdjacencyView;

template <class T, bool is_const> class _AdjacencyEdgeIterator {
    using edge_collection = _Edges<T>;
    using slot_span = std::conditional_t<is_const, std::span<const int>, std::span<int>>;

  public:
    using difference_type = std::ptrdiff_t;
    using value_type = _AdjacencyEdgeProxy<T, is_const>;
    using reference = value_type;
    using iterator_category = std::random_access_iterator_tag;
    using iterator_concept = std::random_access_iterator_tag;

  private:
    using slot_iterator = decltype(std::declval<slot_span>().begin());
    using edge_pointer = std::conditional_t<is_const, const edge_collection *, edge_collection *>;

    slot_iterator it;
    int from;
    edge_pointer edges;

    _AdjacencyEdgeIterator(slot_iterator it_, int from_, edge_pointer edges_)
        : it(it_),
          from(from_),
          edges(edges_) {}

    friend class _AdjacencyView<T, is_const>;

  public:
    _AdjacencyEdgeIterator() = default;
    _AdjacencyEdgeIterator(const _AdjacencyEdgeIterator &) = default;

    struct arrow_proxy {
        value_type value;
        value_type *operator->() { return &value; }
        const value_type *operator->() const { return &value; }
    };

    value_type operator*() const {
        const int id = *it;
        return {from, *it, (*edges)[id]};
    }
    arrow_proxy operator->() const { return {operator*()}; }

    _AdjacencyEdgeIterator &operator++() {
        ++it;
        return *this;
    }
    _AdjacencyEdgeIterator operator++(int) {
        auto result = *this;
        ++*this;
        return result;
    }
    _AdjacencyEdgeIterator &operator--() {
        --it;
        return *this;
    }
    _AdjacencyEdgeIterator operator--(int) {
        auto result = *this;
        --*this;
        return result;
    }
    _AdjacencyEdgeIterator &operator+=(difference_type n) {
        it += n;
        return *this;
    }
    _AdjacencyEdgeIterator &operator-=(difference_type n) {
        it -= n;
        return *this;
    }
    value_type operator[](difference_type n) const {
        auto result = *this;
        result += n;
        return *result;
    }

    friend _AdjacencyEdgeIterator operator+(_AdjacencyEdgeIterator it, difference_type n) {
        it += n;
        return it;
    }
    friend _AdjacencyEdgeIterator operator+(difference_type n, _AdjacencyEdgeIterator it) {
        it += n;
        return it;
    }
    friend _AdjacencyEdgeIterator operator-(_AdjacencyEdgeIterator it, difference_type n) {
        it -= n;
        return it;
    }
    friend difference_type operator-(const _AdjacencyEdgeIterator &lhs,
                                     const _AdjacencyEdgeIterator &rhs) {
        return lhs.it - rhs.it;
    }
    friend bool operator==(const _AdjacencyEdgeIterator &lhs, const _AdjacencyEdgeIterator &rhs) {
        return lhs.it == rhs.it;
    }
    friend auto operator<=>(const _AdjacencyEdgeIterator &lhs, const _AdjacencyEdgeIterator &rhs) {
        return lhs.it <=> rhs.it;
    }
};

template <class T, bool is_const> class _AdjacencyView {
    using edge_collection = _Edges<T>;
    using slot_span = std::conditional_t<is_const, std::span<const int>, std::span<int>>;
    using edge_pointer = std::conditional_t<is_const, const edge_collection *, edge_collection *>;

  public:
    using value_type = _AdjacencyEdgeProxy<T, is_const>;
    using const_value_type = _AdjacencyEdgeProxy<T, true>;
    using iterator = _AdjacencyEdgeIterator<T, is_const>;
    using const_iterator = _AdjacencyEdgeIterator<T, true>;

  private:
    slot_span slots;
    edge_pointer edges;
    int from;

  public:
    _AdjacencyView(slot_span slots_, edge_pointer edges_, int from_)
        : slots(slots_),
          edges(edges_),
          from(from_) {}

    iterator begin() { return iterator(slots.begin(), from, edges); }
    iterator end() { return iterator(slots.end(), from, edges); }
    const_iterator begin() const {
        return const_iterator(std::span<const int>(slots).begin(), from, edges);
    }
    const_iterator end() const {
        return const_iterator(std::span<const int>(slots).end(), from, edges);
    }
    int size() const { return slots.size(); }
    bool empty() const { return slots.empty(); }

    value_type operator[](int i) {
        const int id = slots[i];
        return value_type(from, slots[i], (*edges)[id]);
    }
    const_value_type operator[](int i) const {
        const int id = slots[i];
        return const_value_type(from, slots[i], (*edges)[id]);
    }

    void swap(int i, int j)
        requires(!is_const)
    {
        std::swap(slots[i], slots[j]);
    }
};

} // namespace kk2::graph

#endif // KK2_GRAPH_COMPACT_EDGE_HPP
