#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_MOBIUS_HPP
#define KK2_MATH_MULTIPLICATIVE_FUNCTION_MOBIUS_HPP 1

#include <cassert>

#include "../../type_traits/integral.hpp"
#include "../prime_factorize.hpp"

namespace kk2 {

template <Integral T> int mobius(T n) {
    assert(n >= 0);
    if (n == 0) return 0;
    int res = 1;
    for (auto [p, k] : factorize(static_cast<long long>(n))) {
        if (k > 1) return 0;
        res = -res;
    }
    return res;
}

} // namespace kk2

#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_MOBIUS_HPP
