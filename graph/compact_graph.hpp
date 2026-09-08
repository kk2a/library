#ifndef KK2_GRAPH_COMPACT_GRAPH_HPP
#define KK2_GRAPH_COMPACT_GRAPH_HPP 1

#include "detail/adjacency_list_base.hpp"
#include "detail/compact_adjacency_storage.hpp"

namespace kk2 {

namespace graph {

template <class T, bool is_directed>
using CompactAdjacencyList =
    detail::AdjacencyListBase<T, is_directed, detail::CompactAdjacencyStorage<T, is_directed>>;

} // namespace graph

template <typename T> using CWAdjList = graph::CompactAdjacencyList<T, false>;
template <typename T> using CDWAdjList = graph::CompactAdjacencyList<T, true>;
using CAdjList = graph::CompactAdjacencyList<graph::empty, false>;
using CDAdjList = graph::CompactAdjacencyList<graph::empty, true>;

} // namespace kk2

#endif // KK2_GRAPH_COMPACT_GRAPH_HPP
