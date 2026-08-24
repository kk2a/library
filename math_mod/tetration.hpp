#ifndef KK2_MATH_MOD_TETRATION_HPP
#define KK2_MATH_MOD_TETRATION_HPP 1

#include "pow_mod.hpp"
#include "../math/multiplicative_function/euler_phi.hpp"

namespace kk2 {

// a^^b (mod m)
template <class T> T tetration(T a, T b, T m) {
    if (m == 1) return 0;
    if (a == 0) return ~b & 1;
    if (b == 0) return 1;
    if (m == 2) return a & 1;
    // n >= 3, phi(phi(n)) < n / 2
    return pow_mod<T>(a, tetration(a, b - 1, euler_phi(m)), m);
}

}

#endif // KK2_MATH_MOD_TETRATION_HPP
