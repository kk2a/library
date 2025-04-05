#ifndef KK2_MATH_ACTION_ADD_MAX_MIN_SUMWITHSIZE_HPP
#define KK2_MATH_ACTION_ADD_MAX_MIN_SUMWITHSIZE_HPP 1

#include "../group/add.hpp"
#include "../monoid/max_min_sumwithsize.hpp"

namespace kk2 {

namespace action {

template <class T, class U, class Compare = std::less<T>> struct AddMaxMinSumWithSize {
    using A = group::Add<T>;
    using S = monoid::MaxMinSumWithSize<T, U, Compare>;

    inline static S act(A f, S x) {
        return x.is_unit ? x : S(x.max + f.a, x.min + f.a, x.sum + f.a * x.size, x.size);
    }
};

} // namespace action

} // namespace kk2

#endif // KK2_MATH_ACTION_ADD_MAX_MIN_SUMWITHSIZE_HPP
