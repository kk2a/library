#ifndef KK2_MATH_ACTION_ADD_SUMWITHSIZE_HPP
#define KK2_MATH_ACTION_ADD_SUMWITHSIZE_HPP 1

#include "../group/add.hpp"
#include "../group/sum_with_size.hpp"

namespace kk2 {

namespace action {

template <class T, class U> struct AddSumWithSize {
    using A = group::Add<T>;
    using S = group::SumWithSize<T, U>;

    inline static S act(A f, S x) { return S(x.a + f.a * x.size, x.size); }
};

} // namespace action

} // namespace kk2

#endif // KK2_MATH_ACTION_ADD_SUMWITHSIZE_HPP
