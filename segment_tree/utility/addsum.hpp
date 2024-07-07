#ifndef SEGMENT_TREE_UTILITY_ADDSUM_HPP
#define SEGMENT_TREE_UTILITY_ADDSUM_HPP 1

#include "../lazy.hpp"
#include "../../others/monoid/sum.hpp"
#include "../../others/homomorphism/add.hpp"

template <class S>
using AddSum =
    LazySegTree<monoid::Sum<S>,
                monoid::SumOp<S>,
                monoid::SumUnit<S>,
                homomorphism::Add<S>,
                homomorphism::AddMap<S, monoid::Sum<S>>,
                homomorphism::AddComposition<S>,
                homomorphism::AddUnit<S>>;

#endif // SEGMENT_TREE_UTILITY_ADDSUM_HPP
