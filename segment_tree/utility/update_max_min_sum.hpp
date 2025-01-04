#ifndef KK2_SEGMENT_TREE_UTILITY_UPDATE_MAX_MIN_SUM_HPP
#define KK2_SEGMENT_TREE_UTILITY_UPDATE_MAX_MIN_SUM_HPP 1

#include "../../math/homomorphism/update.hpp"
#include "../../math/monoid/max_min_sum.hpp"
#include "../lazy.hpp"

namespace kk2 {

template <class S>
using UpdateMaxMinSum = LazySegTree<monoid::MaxMinSum<S>,
                                    monoid::MaxMinSumOp<S>,
                                    monoid::MaxMinSumUnit<S>,
                                    homomorphism::Update<S>,
                                    homomorphism::UpdateMap<S, monoid::MaxMinSum<S>>,
                                    homomorphism::UpdateComposition<S>,
                                    homomorphism::UpdateUnit<S>>;

} // namespace kk2

#endif // KK2_SEGMENT_TREE_UTILITY_UPDATE_MAX_MIN_SUM_HPP
