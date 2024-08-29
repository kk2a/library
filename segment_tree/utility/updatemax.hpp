#ifndef SEGMENT_TREE_UTILITY_UPDATEMAX_HPP
#define SEGMENT_TREE_UTILITY_UPDATEMAX_HPP 1

#include "../lazy.hpp"
#include "../../math/monoid/max.hpp"
#include "../../math/homomorphism/update.hpp"

namespace kk2 {

template <class S>
using UpdateMax =
    LazySegTree<monoid::Max<S>,
                monoid::MaxOp<S>,
                monoid::MaxUnit<S>,
                homomorphism::Update<S>,
                homomorphism::UpdateMap<S, monoid::Max<S>>,
                homomorphism::UpdateComposition<S>,
                homomorphism::UpdateUnit<S>>;

} // namespace kk2

#endif // SEGMENT_TREE_UTILITY_UPDATEMAX_HPP
