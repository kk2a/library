#ifndef KK2_GRAPH_STATIC_GRAPH_HPP
#define KK2_GRAPH_STATIC_GRAPH_HPP 1

#include "detail/direct_static_adjacency_storage.hpp"
#include "detail/static_adjacency_list_base.hpp"

namespace kk2 {

namespace graph {

template <class T, bool is_directed>
using StaticAdjacencyList = detail::
    StaticAdjacencyListBase<T, is_directed, detail::DirectStaticAdjacencyStorage<T, is_directed>>;

} // namespace graph

template <typename T> using SWAdjList = graph::StaticAdjacencyList<T, false>;
template <typename T> using SDWAdjList = graph::StaticAdjacencyList<T, true>;
using SAdjList = graph::StaticAdjacencyList<graph::empty, false>;
using SDAdjList = graph::StaticAdjacencyList<graph::empty, true>;

} // namespace kk2

#endif // KK2_GRAPH_STATIC_GRAPH_HPP
