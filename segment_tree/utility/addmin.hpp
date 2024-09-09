#ifndef SEGMENT_TREE_UTILITY_ADDMIN_HPP
#define SEGMENT_TREE_UTILITY_ADDMIN_HPP 1

#include "../../math/homomorphism/add.hpp"
#include "../../math/monoid/min.hpp"
#include "../lazy.hpp"

namespace kk2 {

template <class S>
using AddMin = LazySegTree<monoid::Min<S>,
                           monoid::MinOp<S>,
                           monoid::MinUnit<S>,
                           homomorphism::Add<S>,
                           homomorphism::AddMap<S, monoid::Min<S>>,
                           homomorphism::AddComposition<S>,
                           homomorphism::AddUnit<S>>;

} // namespace kk2

#endif // SEGMENT_TREE_UTILITY_ADDMIN_HPP
