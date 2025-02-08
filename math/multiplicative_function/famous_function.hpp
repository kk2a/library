#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP
#define KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP 1

#include "../pow.hpp"

namespace kk2 {

namespace mf {

long long mobius(long long, long long e) {
    return e == 1 ? -1 : 0;
}

long long sigma0(long long, long long e) {
    return e + 1;
}

long long sigma1(long long p, long long e) {
    long long p_e = pow<long long>(p, e);
    return p_e + (p_e - 1) / (p - 1);
}

long long euler_phi(long long p, long long e) {
    long long p_e = pow<long long>(p, e);
    return p_e - p_e / p;
}

} // namespace mf

} // namespace kk2

#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP
