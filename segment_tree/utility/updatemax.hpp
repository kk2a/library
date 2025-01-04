#ifndef KK2_SEGMENT_TREE_UTILITY_UPDATEMAX_HPP
#define KK2_SEGMENT_TREE_UTILITY_UPDATEMAX_HPP 1

#include "../../math/homomorphism/update.hpp"
#include "../../math/monoid/max.hpp"
#include "../lazy.hpp"

namespace kk2 {

template <class S>
using UpdateMax = LazySegTree<monoid::Max<S>,
                              monoid::MaxOp<S>,
                              monoid::MaxUnit<S>,
                              homomorphism::Update<S>,
                              homomorphism::UpdateMap<S, monoid::Max<S>>,
                              homomorphism::UpdateComposition<S>,
                              homomorphism::UpdateUnit<S>>;

} // namespace kk2

#endif // KK2_SEGMENT_TREE_UTILITY_UPDATEMAX_HPP
