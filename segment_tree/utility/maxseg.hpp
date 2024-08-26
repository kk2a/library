#ifndef SEGMENT_TREE_UTILITY_MAXSEG_HPP
#define SEGMENT_TREE_UTILITY_MAXSEG_HPP 1

#include "../seg.hpp"
#include "../../others/monoid/max.hpp"

namespace kk2 {

template <class S>
using MaxSeg = SegTree<monoid::Max<S>,
                       monoid::MaxOp<S>,
                       monoid::MaxUnit<S>>;

} // namespace kk2

#endif // SEGMENT_TREE_UTILITY_MAXSEG_HPP
