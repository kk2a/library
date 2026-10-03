#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_POW_TABLE_HPP
#define KK2_MATH_MULTIPLICATIVE_FUNCTION_POW_TABLE_HPP 1

#include <cassert>
#include <limits>
#include <vector>

#include "../../common/type_alias.hpp"
#include "../lpf_table.hpp"
#include "../pow.hpp"

namespace kk2 {

/**
 * @brief Compute the values `0^e, 1^e, ..., n^e.`
 *
 * As usual for formal power series and modular arithmetic, 0^0 is defined
 * to be 1.
 */
template <class T> std::vector<T> pow_table(u32 e, u32 n) {
    std::vector<T> result(static_cast<usize>(n) + 1);

    result[0] = (e == 0 ? T(1) : T(0));
    if (n == 0) return result;
    result[1] = T(1);
    if (n == 1) return result;

    LPFTable::set_upper(static_cast<usize>(n));
    for (usize index = 2; index <= n; ++index) {
        const u32 i = static_cast<u32>(index);
        const u32 p = LPFTable::lpf(i);
        if (p == i) {
            result[index] = pow<T>(T(i), e);
        } else {
            result[index] = result[index / p] * result[p];
        }
    }
    return result;
}

} // namespace kk2

#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_POW_TABLE_HPP
