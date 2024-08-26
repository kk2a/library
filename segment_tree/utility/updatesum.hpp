#ifndef SEGMENT_TREE_UTILITY_UPDATESUM_HPP
#define SEGMENT_TREE_UTILITY_UPDATESUM_HPP 1

#include "../lazy.hpp"
#include "../../others/monoid/sum.hpp"
#include "../../others/homomorphism/update.hpp"

namespace kk2 {

template <class S>
using UpdateSum =
    LazySegTree<monoid::Sum<S>,
                monoid::SumOp<S>,
                monoid::SumUnit<S>,
                homomorphism::Update<S>,
                homomorphism::UpdateMap<S, monoid::Sum<S>>,
                homomorphism::UpdateComposition<S>,
                homomorphism::UpdateUnit<S>>;

} // namespace kk2

#endif // SEGMENT_TREE_UTILITY_UPDATESUM_HPP
