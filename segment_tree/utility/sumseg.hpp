#ifndef KK2_SEGMENT_TREE_UTILITY_SUMSEG_HPP
#define KK2_SEGMENT_TREE_UTILITY_SUMSEG_HPP 1

#include "../../math/group/sum.hpp"
#include "../seg.hpp"

namespace kk2 {

template <class S> using SumSeg = SegTree<group::Sum<S>, group::SumOp<S>, group::SumUnit<S>>;

} // namespace kk2

#endif // KK2_SEGMENT_TREE_UTILITY_SUMSEG_HPP
