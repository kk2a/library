#ifndef SEGMENT_TREE_UTILITY_UPDATEMAX_HPP
#define SEGMENT_TREE_UTILITY_UPDATEMAX_HPP 1

#include "../lazy.hpp"
#include "../../others/monoid/max.hpp"
#include "../../others/homomorphism/update.hpp"

template <class S>
using UpdateMax =
    LazySegTree<monoid::Max<S>,
                monoid::MaxOp<S>,
                monoid::MaxUnit<S>,
                homomorphism::Update<S>,
                homomorphism::UpdateMap<S, monoid::Max<S>>,
                homomorphism::UpdateComposition<S>,
                homomorphism::UpdateUnit<S>>;

#endif // SEGMENT_TREE_UTILITY_UPDATEMAX_HPP
