#ifndef KK2_SEGMENT_TREE_UTILITY_MAXSEG_HPP
#define KK2_SEGMENT_TREE_UTILITY_MAXSEG_HPP 1

#include "../../math/monoid/max.hpp"
#include "../seg.hpp"

namespace kk2 {

template <class S> using MaxSeg = SegTree<monoid::Max<S>, monoid::MaxOp<S>, monoid::MaxUnit<S>>;

} // namespace kk2

#endif // KK2_SEGMENT_TREE_UTILITY_MAXSEG_HPP
