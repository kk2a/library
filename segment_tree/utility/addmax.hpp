#ifndef KK2_SEGMENT_TREE_UTILITY_ADDMAX_HPP
#define KK2_SEGMENT_TREE_UTILITY_ADDMAX_HPP 1

#include "../../math/homomorphism/add.hpp"
#include "../../math/monoid/max.hpp"
#include "../lazy.hpp"

namespace kk2 {

template <class S>
using AddMax = LazySegTree<monoid::Max<S>,
                           monoid::MaxOp<S>,
                           monoid::MaxUnit<S>,
                           homomorphism::Add<S>,
                           homomorphism::AddMap<S, monoid::Max<S>>,
                           homomorphism::AddComposition<S>,
                           homomorphism::AddUnit<S>>;

} // namespace kk2

#endif // KK2_SEGMENT_TREE_UTILITY_ADDMAX_HPP
