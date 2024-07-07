#ifndef SEGMENT_TREE_UTILITY_ADDMIN_HPP
#define SEGMENT_TREE_UTILITY_ADDMIN_HPP 1

#include "../lazy.hpp"
#include "../../others/monoid/min.hpp"
#include "../../others/homomorphism/add.hpp"

template <class S>
using AddMin =
    LazySegTree<monoid::Min<S>,
                monoid::MinOp<S>,
                monoid::MinUnit<S>,
                homomorphism::Add<S>,
                homomorphism::AddMap<S, monoid::Min<S>>,
                homomorphism::AddComposition<S>,
                homomorphism::AddUnit<S>>;

#endif // SEGMENT_TREE_UTILITY_ADDMIN_HPP
