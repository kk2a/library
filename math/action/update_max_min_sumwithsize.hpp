#ifndef KK2_MATH_ACTION_UPDATE_MAX_MIN_SUMWITHSIZE_HPP
#define KK2_MATH_ACTION_UPDATE_MAX_MIN_SUMWITHSIZE_HPP 1

#include "../monoid/max_min_sumwithsize.hpp"
#include "../monoid/update.hpp"

namespace kk2 {

namespace action {

template <class T, class U, class Compare = std::less<T>> struct UpdateMaxMinSumWithSize {
    using A = monoid::Update<T>;
    using S = monoid::MaxMinSumWithSize<T, U, Compare>;

    inline static S act(A f, S x) { return f.is_unit ? x : S(f.a, f.a, f.a * x.size, x.size); }
};

} // namespace action

} // namespace kk2

#endif // KK2_MATH_ACTION_UPDATE_MAX_MIN_SUMWITHSIZE_HPP
