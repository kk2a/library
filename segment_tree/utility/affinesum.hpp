#ifndef SEGMENT_TREE_UTILITY_AFFINESUM_HPP
#define SEGMENT_TREE_UTILITY_AFFINESUM_HPP 1

#include "../lazy.hpp"
#include "../../others/monoid/sum.hpp"
#include "../../others/homomorphism/affine.hpp"

namespace kk2 {

template <class S>
using AffineSum =
    LazySegTree<monoid::Sum<S>,
                monoid::SumOp<S>,
                monoid::SumUnit<S>,
                homomorphism::Affine<S>,
                homomorphism::AffineMap<S, monoid::Sum<S>>,
                homomorphism::AffineComposition<S>,
                homomorphism::AffineUnit<S>>;

} // namespace kk2

#endif // SEGMENT_TREE_UTILITY_AFFINESUM_HPP
