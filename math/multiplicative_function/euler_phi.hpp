#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_EULER_PHI_HPP
#define KK2_MATH_MULTIPLICATIVE_FUNCTION_EULER_PHI_HPP 1

#include <cassert>

#include "../../type_traits/integral.hpp"
#include "../prime_factorize.hpp"

namespace kk2 {

template <class T, is_integral_t<T> * = nullptr> T euler_phi(T n) {
    assert(n > 0);
    for (auto [p, k] : factorize(static_cast<long long>(n))) n -= n / p;
    return n;
}

} // namespace kk2

#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_EULER_PHI_HPP
