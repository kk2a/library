#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP
#define KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP 1

#include "../pow.hpp"

namespace kk2 {

long long mobius(long long p, long long e) {
    return e == 1 ? -1 : 0;
}

long long sigma0(long long p, long long e) {
    return e + 1;
}

long long sigma1(long long p, long long e) {
    return (pow<long long>(p, e + 1) - 1) / (p - 1);
}

long long euler_phi(long long p, long long e) {
    return pow(p, e) - pow(p, e - 1);
}

} // namespace kk2

#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP
