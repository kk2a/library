#ifndef KK2_SEGMENT_TREE_UTILITY_AFFINESUM_HPP
#define KK2_SEGMENT_TREE_UTILITY_AFFINESUM_HPP 1

#include "../../math/group/sum.hpp"
#include "../../math/homomorphism/affine.hpp"
#include "../lazy.hpp"

namespace kk2 {

template <class S>
using AffineSum = LazySegTree<group::Sum<S>,
                              group::SumOp<S>,
                              group::SumUnit<S>,
                              homomorphism::Affine<S>,
                              homomorphism::AffineMap<S, group::Sum<S>>,
                              homomorphism::AffineComposition<S>,
                              homomorphism::AffineUnit<S>>;

} // namespace kk2

#endif // KK2_SEGMENT_TREE_UTILITY_AFFINESUM_HPP
