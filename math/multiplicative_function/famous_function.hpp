#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP
#define KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP 1

#include "../pow.hpp"

namespace kk2 {

namespace mf {

using i64 = long long;

i64 mobius(i64, i64 e) { return e == 1 ? -1 : 0; }

i64 sigma0(i64, i64 e) { return e + 1; }

i64 sigma1(i64 p, i64 e) {
    i64 p_e = pow<i64>(p, e);
    return p_e + (p_e - 1) / (p - 1);
}

i64 euler_phi(i64 p, i64 e) {
    i64 p_e = pow<i64>(p, e);
    return p_e - p_e / p;
}

} // namespace mf

} // namespace kk2

#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP
