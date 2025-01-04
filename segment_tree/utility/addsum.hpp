#ifndef KK2_SEGMENT_TREE_UTILITY_ADDSUM_HPP
#define KK2_SEGMENT_TREE_UTILITY_ADDSUM_HPP 1

#include "../../math/group/sum.hpp"
#include "../../math/homomorphism/add.hpp"
#include "../lazy.hpp"

namespace kk2 {

template <class S>
using AddSum = LazySegTree<group::Sum<S>,
                           group::SumOp<S>,
                           group::SumUnit<S>,
                           homomorphism::Add<S>,
                           homomorphism::AddMap<S, group::Sum<S>>,
                           homomorphism::AddComposition<S>,
                           homomorphism::AddUnit<S>>;

} // namespace kk2

#endif // KK2_SEGMENT_TREE_UTILITY_ADDSUM_HPP
