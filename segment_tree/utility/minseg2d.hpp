#ifndef SEGMENT_TREE_UTILITY_MINSEG2D_HPP
#define SEGMENT_TREE_UTILITY_MINSEG2D_HPP 1

#include "../../math/monoid/min.hpp"
#include "../seg2d.hpp"

namespace kk2 {

template <class S>
using MinSeg2D = SegTree2D<monoid::Min<S>, monoid::MinOp<S>, monoid::MinUnit<S>>;

} // namespace kk2

#endif // SEGMENT_TREE_UTILITY_MINSEG2D_HPP
