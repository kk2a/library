#ifndef SEGMENT_TREE_UTILITY_MINSEG_HPP
#define SEGMENT_TREE_UTILITY_MINSEG_HPP 1

#include "../seg.hpp"
#include "../../others/monoid/min.hpp"

namespace kk2 {

template <class S>
using MinSeg = SegTree<monoid::Min<S>,
                       monoid::MinOp<S>,
                       monoid::MinUnit<S>>;

} // namespace kk2

#endif // SEGMENT_TREE_UTILITY_MINSEG_HPP
