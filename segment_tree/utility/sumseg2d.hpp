#ifndef SEGMENT_TREE_UTILITIY_SUMSEG2D_HPP
#define SEGMENT_TREE_UTILITIY_SUMSEG2D_HPP 1

#include "../../math/group/sum.hpp"
#include "../seg2d.hpp"

namespace kk2 {

template <class S> using SumSeg2D = SegTree2D<group::Sum<S>, group::SumOp<S>, group::SumUnit<S>>;

} // namespace kk2

#endif // SEGMENT_TREE_UTILITIY_SUMSEG2D_HPP
