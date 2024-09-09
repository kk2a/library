#ifndef SEGMENT_TREE_UTILITY_UPDATEMIN_HPP
#define SEGMENT_TREE_UTILITY_UPDATEMIN_HPP 1

#include "../../math/homomorphism/update.hpp"
#include "../../math/monoid/min.hpp"
#include "../lazy.hpp"

namespace kk2 {

template <class S>
using UpdateMin = LazySegTree<monoid::Min<S>,
                              monoid::MinOp<S>,
                              monoid::MinUnit<S>,
                              homomorphism::Update<S>,
                              homomorphism::UpdateMap<S, monoid::Min<S>>,
                              homomorphism::UpdateComposition<S>,
                              homomorphism::UpdateUnit<S>>;

} // namespace kk2

#endif // SEGMENT_TREE_UTILITY_UPDATEMIN_HPP
