#ifndef SEGMENT_TREE_UTILITY_UPDATEMIN_HPP
#define SEGMENT_TREE_UTILITY_UPDATEMIN_HPP 1

#include "../lazy.hpp"
#include "../../others/monoid/min.hpp"
#include "../../others/homomorphism/update.hpp"

template <class S>
using UpdateMin =
    LazySegTree<monoid::Min<S>,
                monoid::MinOp<S>,
                monoid::MinUnit<S>,
                homomorphism::Update<S>,
                homomorphism::UpdateMap<S, monoid::Min<S>>,
                homomorphism::UpdateComposition<S>,
                homomorphism::UpdateUnit<S>>;

#endif // SEGMENT_TREE_UTILITY_UPDATEMIN_HPP
