#ifndef KK2_DATA_STRUCTURE_STATIC_RMQ_HPP
#define KK2_DATA_STRUCTURE_STATIC_RMQ_HPP 1

#include "../math/monoid/min.hpp"
#include "sparse_table.hpp"

namespace kk2 {

template <class S>
using StaticRMQ = SparseTableS<monoid::Min<S>>;

} // namespace kk2

#endif // KK2_DATA_STRUCTURE_STATIC_RMQ_HPP
