#ifndef KK2_FPS_POLY_SAMPLE_POINT_EVALUATE_HPP
#define KK2_FPS_POLY_SAMPLE_POINT_EVALUATE_HPP 1

#include <cassert>
#include <vector>

#include "../common/type_alias.hpp"
#include "../math_mod/comb.hpp"
#include "../type_traits/modint.hpp"

namespace kk2 {

/**
 * @brief Return `f(t)`, where `f(i) = y[i]` for `i = 0, ..., y.size() - 1`.
 */
template <modint::Modular mint> mint sample_point_evaluate(const std::vector<mint> &y, mint t) {
    if (y.empty()) return 0;
    assert(y.size() <= static_cast<usize>(mint::getmod()));

    const usize tval = static_cast<usize>(t.val());
    if (tval < y.size()) return y[tval];

    const i32 degree = static_cast<i32>(y.size()) - 1;
    Comb<mint>::set_upper(degree);

    std::vector<mint> prefix(y.size() + 1, mint(1));
    for (usize i = 0; i < y.size(); i++) prefix[i + 1] = prefix[i] * (t - mint(i));

    mint result = 0;
    mint suffix = 1;
    for (usize i = y.size(); i-- > 0;) {
        mint term = y[i] * Comb<mint>::ifact(static_cast<i32>(i))
                    * Comb<mint>::ifact(degree - static_cast<i32>(i));
        if ((degree - static_cast<i32>(i)) & 1) term = -term;
        result += term * prefix[i] * suffix;
        suffix *= t - mint(i);
    }
    return result;
}

} // namespace kk2

#endif // KK2_FPS_POLY_SAMPLE_POINT_EVALUATE_HPP
