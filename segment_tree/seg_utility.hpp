#ifndef SEG_UTILITY_HPP
#define SEG_UTILITY_HPP 1

#include "seg.hpp"
#include "lazy.hpp"
#include "../others/homomorphism/add.hpp"
#include "../others/homomorphism/affine.hpp"
#include "../others/homomorphism/update.hpp"
#include "../others/monoid/max.hpp"
#include "../others/monoid/min.hpp"
#include "../others/monoid/sum.hpp"

namespace seg_utility {

using namespace homomorphism;
using namespace monoid;

// seg
template <class S>
using MaxSeg = SegTree<Max<S>, MaxOp<S>, MaxUnit<S>>;
template <class S>
using MinSeg = SegTree<Min<S>, MinOp<S>, MinUnit<S>>;
template <class S>
using SumSeg = SegTree<Sum<S>, SumOp<S>, SumUnit<S>>;

// lazy 
template <class S>
using AddMax = LazySegTree<Max<S>, MaxOp<S>, MaxUnit<S>,
                           Add<S>, AddMap<S, Max<S>>, AddComposition<S>, AddUnit<S>>;
template <class S>
using AddMin = LazySegTree<Min<S>, MinOp<S>, MinUnit<S>,
                           Add<S>, AddMap<S, Min<S>>, AddComposition<S>, AddUnit<S>>;
template <class S>
using AddSum = LazySegTree<Sum<S>, SumOp<S>, SumUnit<S>,
                           Add<S>, AddMap<S, Sum<S>>, AddComposition<S>, AddUnit<S>>;
template <class S>
using UpdateMax = LazySegTree<Max<S>, MaxOp<S>, MaxUnit<S>,
                              Update<S>, UpdateMap<S, Max<S>>, UpdateComposition<S>, UpdateUnit<S>>;
template <class S>
using UpdateMin = LazySegTree<Min<S>, MinOp<S>, MinUnit<S>,
                              Update<S>, UpdateMap<S, Min<S>>, UpdateComposition<S>, UpdateUnit<S>>;
template <class S>
using UpdateSum = LazySegTree<Sum<S>, SumOp<S>, SumUnit<S>,
                              Update<S>, UpdateMap<S, Sum<S>>, UpdateComposition<S>, UpdateUnit<S>>;
template <class S>
using AffineSum = LazySegTree<Sum<S>, SumOp<S>, SumUnit<S>,
                              Affine<S>, AffineMap<S, Sum<S>>, AffineComposition<S>, AffineUnit<S>>;

template <class S, class... Args>
vector<S> GetVector(int n, Args... args) { return vector<S>(n, S(args...)); }

template <class S, class... Args>
vector<Max<S>> GetVecMax(int n, Args... args) { return vector<Max<S>>(n, Max<S>(args...)); }

template <class S, class... Args>
vector<Min<S>> GetVecMin(int n, Args... args) { return vector<Min<S>>(n, Min<S>(args...)); }

template <class S, class... Args>
vector<Sum<S>> GetVecSum(int n, Args... args) { return vector<Sum<S>>(n, Sum<S>(args...)); }

} // namespace seg_utility

using seg_utility::MaxSeg;
using seg_utility::MinSeg;
using seg_utility::SumSeg;

using seg_utility::AddMax;
using seg_utility::AddMin;
using seg_utility::AddSum;
using seg_utility::UpdateMax;
using seg_utility::UpdateMin;
using seg_utility::UpdateSum;
using seg_utility::AffineSum;

using seg_utility::GetVecMax;
using seg_utility::GetVecMin;
using seg_utility::GetVecSum;

#endif // SEG_UTILITY_HPP
