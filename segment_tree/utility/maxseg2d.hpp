#ifndef SEGMENT_TREE_UTILITY_MAXSEG2D_HPP
#define SEGMENT_TREE_UTILITY_MAXSEG2D_HPP 1

#include "../../math/monoid/max.hpp"
#include "../seg2d.hpp"

namespace kk2 {

template <class S>
using MaxSeg2D = SegTree2D<monoid::Max<S>, monoid::MaxOp<S>, monoid::MaxUnit<S>>;

} // namespace kk2

#endif // SEGMENT_TREE_UTILITY_MAXSEG2D_HPP