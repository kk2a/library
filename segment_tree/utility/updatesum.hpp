#ifndef KK2_SEGMENT_TREE_UTILITY_UPDATESUM_HPP
#define KK2_SEGMENT_TREE_UTILITY_UPDATESUM_HPP 1

#include "../../math/group/sum.hpp"
#include "../../math/homomorphism/update.hpp"
#include "../lazy.hpp"

namespace kk2 {

template <class S>
using UpdateSum = LazySegTree<group::Sum<S>,
                              group::SumOp<S>,
                              group::SumUnit<S>,
                              homomorphism::Update<S>,
                              homomorphism::UpdateMap<S, group::Sum<S>>,
                              homomorphism::UpdateComposition<S>,
                              homomorphism::UpdateUnit<S>>;

} // namespace kk2

#endif // KK2_SEGMENT_TREE_UTILITY_UPDATESUM_HPP
