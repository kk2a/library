#ifndef KK2_GRAPH_COMPACT_STATIC_GRAPH_HPP
#define KK2_GRAPH_COMPACT_STATIC_GRAPH_HPP 1

#include "detail/compact_static_adjacency_storage.hpp"
#include "detail/static_adjacency_list_base.hpp"

namespace kk2 {

namespace graph {

template <class T, bool is_directed>
using CompactStaticAdjacencyList = detail::StaticAdjacencyListBase<
    T, is_directed, detail::CompactStaticAdjacencyStorage<T, is_directed>>;

} // namespace graph

template <typename T> using CSWAdjList = graph::CompactStaticAdjacencyList<T, false>;
template <typename T> using CSDWAdjList = graph::CompactStaticAdjacencyList<T, true>;
using CSAdjList = graph::CompactStaticAdjacencyList<graph::empty, false>;
using CSDAdjList = graph::CompactStaticAdjacencyList<graph::empty, true>;

} // namespace kk2

#endif // KK2_GRAPH_COMPACT_STATIC_GRAPH_HPP
