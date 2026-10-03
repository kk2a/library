#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP
#define KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP 1

#include "../../common/type_alias.hpp"
#include "../pow.hpp"

namespace kk2 {

namespace mf {

i32 mobius(u32, u32 e) { return e == 1 ? -1 : 0; }

u32 sigma0(u32, u32 e) { return e + 1; }

u64 sigma1(u32 p, u32 e) {
    u64 p_e = pow<u64>(p, e);
    return p_e + (p_e - 1) / (p - 1);
}

u32 euler_phi(u32 p, u32 e) {
    u64 p_e = pow<u64>(p, e);
    return static_cast<u32>(p_e - p_e / p);
}

} // namespace mf

} // namespace kk2

#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP
