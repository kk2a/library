#ifndef SEGMENT_TREE_UTILITY_ADDSUM_HPP
#define SEGMENT_TREE_UTILITY_ADDSUM_HPP 1

#include "../lazy.hpp"
#include "../../math/group/sum.hpp"
#include "../../math/homomorphism/add.hpp"

namespace kk2 {

template <class S>
using AddSum =
    LazySegTree<group::Sum<S>,
                group::SumOp<S>,
                group::SumUnit<S>,
                homomorphism::Add<S>,
                homomorphism::AddMap<S, group::Sum<S>>,
                homomorphism::AddComposition<S>,
                homomorphism::AddUnit<S>>;

} // namespace kk2

#endif // SEGMENT_TREE_UTILITY_ADDSUM_HPP
