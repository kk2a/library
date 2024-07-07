#ifndef SEGMENT_TREE_UTILITY_SUMSEG_HPP
#define SEGMENT_TREE_UTILITY_SUMSEG_HPP 1

#include "../seg.hpp"
#include "../../others/monoid/sum.hpp"

template <class S>
using SumSeg = SegTree<monoid::Sum<S>,
                       monoid::SumOp<S>,
                       monoid::SumUnit<S>>;

#endif // SEGMENT_TREE_UTILITY_SUMSEG_HPP
