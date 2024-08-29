#ifndef SEGMENT_TREE_UTILITY_UPDATESUM_HPP
#define SEGMENT_TREE_UTILITY_UPDATESUM_HPP 1

#include "../lazy.hpp"
#include "../../math/group/sum.hpp"
#include "../../math/homomorphism/update.hpp"

namespace kk2 {

template <class S>
using UpdateSum =
    LazySegTree<group::Sum<S>,
                group::SumOp<S>,
                group::SumUnit<S>,
                homomorphism::Update<S>,
                homomorphism::UpdateMap<S, group::Sum<S>>,
                homomorphism::UpdateComposition<S>,
                homomorphism::UpdateUnit<S>>;

} // namespace kk2

#endif // SEGMENT_TREE_UTILITY_UPDATESUM_HPP
