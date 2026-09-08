#ifndef KK2_GRAPH_GRAPH_HPP
#define KK2_GRAPH_GRAPH_HPP 1

#include "detail/adjacency_list_base.hpp"
#include "detail/direct_adjacency_storage.hpp"

namespace kk2 {

namespace graph {

template <class T, bool is_directed>
using AdjacencyList = detail::AdjacencyListBase<T, is_directed,
                                                detail::DirectAdjacencyStorage<T, is_directed>>;

} // namespace graph

template <typename T> using WAdjList = graph::AdjacencyList<T, false>;
template <typename T> using DWAdjList = graph::AdjacencyList<T, true>;
using AdjList = graph::AdjacencyList<graph::empty, false>;
using DAdjList = graph::AdjacencyList<graph::empty, true>;

} // namespace kk2

#endif // KK2_GRAPH_GRAPH_HPP
