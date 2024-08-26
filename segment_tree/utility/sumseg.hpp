#ifndef SEGMENT_TREE_UTILITY_SUMSEG_HPP
#define SEGMENT_TREE_UTILITY_SUMSEG_HPP 1

#include "../seg.hpp"
#include "../../others/monoid/sum.hpp"

namespace kk2 {

template <class S>
using SumSeg = SegTree<monoid::Sum<S>,
                       monoid::SumOp<S>,
                       monoid::SumUnit<S>>;

} // namespace kk2

#endif // SEGMENT_TREE_UTILITY_SUMSEG_HPP
