#ifndef KK2_MATH_ACTION_UPDATE_SUMWITHSIZE_HPP
#define KK2_MATH_ACTION_UPDATE_SUMWITHSIZE_HPP 1

#include "../group/sum_with_size.hpp"
#include "../monoid/update.hpp"

namespace kk2 {

namespace action {

template <class T, class U> struct UpdateSumWithSize {
    using S = group::SumWithSize<T, U>;
    using A = monoid::Update<T>;

    inline static S act(A f, S x) { return f.is_unit ? x : S(f.a * x.size, x.size); }
};

} // namespace action

} // namespace kk2

#endif // KK2_MATH_ACTION_UPDATE_SUMWITHSIZE_HPP
