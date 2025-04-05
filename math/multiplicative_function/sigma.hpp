#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_SIGMA_HPP
#define KK2_MATH_MULTIPLICATIVE_FUNCTION_SIGMA_HPP 1

#include <cassert>

#include "../../type_traits/integral.hpp"
#include "../pow.hpp"
#include "../prime_factorize.hpp"

namespace kk2 {

template <class T, is_integral_t<T> * = nullptr> T sigma0(T n) {
    assert(n > 0);
    T res = 1;
    for (auto [p, k] : factorize(static_cast<long long>(n))) res *= k + 1;
    return res;
}

template <class T, is_integral_t<T> * = nullptr> T sigma1(T n) {
    assert(n > 0);
    T res = 1;
    for (auto [p, k] : factorize(static_cast<long long>(n))) {
        T p_k = pow<T>(p, k);
        res *= p_k + (p_k - 1) / (p - 1);
    }
    return res;
}

} // namespace kk2

#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_SIGMA_HPP
