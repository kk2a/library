#ifndef KK2_MATH_ACTION_ADD_MAX_HPP
#define KK2_MATH_ACTION_ADD_MAX_HPP 1

#include "../group/add.hpp"
#include "../monoid/max.hpp"

namespace kk2 {

namespace action {

template <class T, class Compare = std::less<T>>
struct AddMax {
    using A = group::Add<T>;
    using S = monoid::Max<T, Compare>;

    inline static S act(A f, S x) { return x.is_unit ? x : S(x.a + f.a); }
};

} // namespace action

} // namespace kk2

#endif // KK2_MATH_ACTION_ADD_MAX_HPP
