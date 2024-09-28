#ifndef SEGMNET_TREE_UTILITY_MAX_MIN_SUM_HPP
#define SEGMNET_TREE_UTILITY_MAX_MIN_SUM_HPP 1

#include "../../math/monoid/max_min_sum.hpp"
#include "../seg.hpp"

namespace kk2 {

template <class S>
using MaxMinSumSeg = SegTree<monoid::MaxMinSum<S>,
                             monoid::MaxMinSumOp<S>,
                             monoid::MaxMinSumUnit<S>>;

} // namespace kk2  

#endif // SEGMNET_TREE_UTILITY_MAX_MIN_SUM_HPP
