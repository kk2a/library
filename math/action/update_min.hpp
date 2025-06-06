#ifndef KK2_MATH_ACTION_UPDATE_MIN_HPP
#define KK2_MATH_ACTION_UPDATE_MIN_HPP 1

#include "../monoid/min.hpp"
#include "../monoid/update.hpp"

namespace kk2 {

namespace action {

template <class T, class Compare = std::less<T>> struct UpdateMin {
    using S = monoid::Min<T, Compare>;
    using A = monoid::Update<S>;

    inline static S act(A f, S x) { return f.is_unit ? x : f.a; }
};

} // namespace action

} // namespace kk2

#endif // KK2_MATH_ACTION_UPDATE_MIN_HPP
