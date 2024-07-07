#ifndef DATA_STRUCTURE_STATIC_RMQ_HPP
#define DATA_STRUCTURE_STATIC_RMQ_HPP 1

#include "sparse_table.hpp"
#include "../others/monoid/min.hpp"

template <class S>
using StaticRMQ = SparseTable<monoid::Min<S>, monoid::MinOp<S>, monoid::MinUnit<S>>;

#endif // DATA_STRUCTURE_STATIC_RMQ_HPP
