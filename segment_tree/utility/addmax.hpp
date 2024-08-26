#ifndef SEGMENT_TREE_UTILITY_ADDMAX_HPP
#define SEGMENT_TREE_UTILITY_ADDMAX_HPP 1

#include "../lazy.hpp"
#include "../../others/monoid/max.hpp"
#include "../../others/homomorphism/add.hpp"

namespace kk2 {

template <class S>
using AddMax =
    LazySegTree<monoid::Max<S>,
                monoid::MaxOp<S>,
                monoid::MaxUnit<S>,
                homomorphism::Add<S>,
                homomorphism::AddMap<S, monoid::Max<S>>,
                homomorphism::AddComposition<S>,
                homomorphism::AddUnit<S>>;

} // namespace kk2

#endif // SEGMENT_TREE_UTILITY_ADDMAX_HPP
