#ifndef KK2_SEGMENT_TREE_UTILITY_MINSEG_HPP
#define KK2_SEGMENT_TREE_UTILITY_MINSEG_HPP 1

#include "../../math/monoid/min.hpp"
#include "../seg.hpp"

namespace kk2 {

template <class S> using MinSeg = SegTree<monoid::Min<S>, monoid::MinOp<S>, monoid::MinUnit<S>>;

} // namespace kk2

#endif // KK2_SEGMENT_TREE_UTILITY_MINSEG_HPP
