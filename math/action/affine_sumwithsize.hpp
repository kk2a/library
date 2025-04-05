#ifndef KK2_MATH_ACTION_AFFINE_SUMWITHSIZE_HPP
#define KK2_MATH_ACTION_AFFINE_SUMWITHSIZE_HPP 1

#include "../group/sum_with_size.hpp"
#include "../monoid/affine.hpp"

namespace kk2 {

namespace action {

template <class T, class U> struct AffineSumWithSize {
    using A = monoid::Affine<T>;
    using S = group::SumWithSize<T, U>;

    inline static S act(A f, S x) { return S(f.a * x.a + f.b * x.size, x.size); }
};

} // namespace action

} // namespace kk2

#endif // KK2_MATH_ACTION_AFFINE_SUMWITHSIZE_HPP
