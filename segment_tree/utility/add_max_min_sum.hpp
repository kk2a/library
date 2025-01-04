#ifndef KK2_SEGMENT_TREE_UTILITY_ADD_MAX_MIN_SUM_HPP
#define KK2_SEGMENT_TREE_UTILITY_ADD_MAX_MIN_SUM_HPP 1

#include "../../math/homomorphism/add.hpp"
#include "../../math/monoid/max_min_sum.hpp"
#include "../lazy.hpp"

namespace kk2 {

template <class S>
using AddMaxMinSum = LazySegTree<monoid::MaxMinSum<S>,
                                 monoid::MaxMinSumOp<S>,
                                 monoid::MaxMinSumUnit<S>,
                                 homomorphism::Add<S>,
                                 homomorphism::AddMap<S, monoid::MaxMinSum<S>>,
                                 homomorphism::AddComposition<S>,
                                 homomorphism::AddUnit<S>>;

} // namespace kk2

#endif // KK2_SEGMENT_TREE_UTILITY_ADD_MAX_MIN_SUM_HPP
