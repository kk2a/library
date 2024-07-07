#ifndef SEGMENT_TREE_UTILITY_MINSEG_HPP
#define SEGMENT_TREE_UTILITY_MINSEG_HPP 1

#include "../seg.hpp"
#include "../../others/monoid/min.hpp"

template <class S>
using MinSeg = SegTree<monoid::Min<S>,
                       monoid::MinOp<S>,
                       monoid::MinUnit<S>>;

#endif // SEGMENT_TREE_UTILITY_MINSEG_HPP
