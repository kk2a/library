#ifndef KK2_MATH_ACTION_UPDATE_AFFINE_HPP
#define KK2_MATH_ACTION_UPDATE_AFFINE_HPP 1

#include "../monoid/affine.hpp"
#include "../monoid/update.hpp"

namespace kk2 {

namespace action {

template <class T> struct UpdateAffine {
    using A = monoid::Update<monoid::Affine<T>>;
    using S = monoid::Affine<T>;

    inline static S act(A f, S x) { return f.is_unit ? x : S(f.a); }
}

} // namespace action

} // namespace kk2

#endif // KK2_MATH_ACTION_UPDATE_AFFINE_HPP
