#ifndef KK2_FPS_POWER_SUM_HPP
#define KK2_FPS_POWER_SUM_HPP 1

#include <utility>
#include <vector>

#include "../common/type_alias.hpp"
#include "../math_mod/comb.hpp"
#include "../math_mod/power_sum.hpp"
#include "../type_traits/fps.hpp"
#include "../type_traits/integral.hpp"
#include "../type_traits/modint.hpp"

namespace kk2 {

/**
 * @brief Enumerate `sum_{i=0}^{n-1} i^l` for `l = 0, ..., k`.
 * @see https://kk2a.github.io/library/fps/power_sum.hpp.html#sum-of-monomial-enumerate
 */
template <fps::ModularUnivariateFormalPowerSeries FPS, UnsignedIntegral T1, UnsignedIntegral T2>
FPS sum_of_monomial_enumerate(T1 n, T2 k) {
    using mint = FPS::value_type;
    using comb = Comb<mint>;
    comb::set_upper(k + 1);
    FPS f(k + 1), g(k + 1);
    mint tmp = n;
    for (usize i = 1; i < k + 2; ++i, tmp *= n) {
        f[i - 1] = comb::ifact(i) * tmp;
        g[i - 1] = comb::ifact(i);
    }
    f.inplace_div(g);
    for (usize i = 1; i <= k; ++i) f[i] *= comb::fact(i);
    return f;
}

/**
 * @brief Return `sum_{i=0}^{n-1} f(i)` from the coefficients of `f`.
 * @see https://kk2a.github.io/library/fps/power_sum.hpp.html#sum-of-polynomial
 */
template <fps::ModularUnivariateFormalPowerSeries FPS,
          modint::Modular mint = typename FPS::value_type,
          UnsignedIntegral T>
mint sum_of_polynomial(const FPS &f, T n) {
    auto tmp = sum_of_monomial_enumerate<FPS>(n, f.size());
    mint res = 0;
    for (usize i = 0; i < f.size(); ++i) res += f[i] * tmp[i];
    return res;
}

/**
 * @brief Construct the polynomial `g` satisfying `g(n) = sum_{i=0}^n f(i)`.
 * @see https://kk2a.github.io/library/fps/power_sum.hpp.html#prefix-sum-of-polynomial
 */
template <fps::ModularUnivariateFormalPowerSeries FPS> FPS prefix_sum_of_polynomial(const FPS &f) {
    using mint = FPS::value_type;
    using comb = Comb<mint>;
    const usize n = f.size();
    comb::set_upper(n);
    FPS g(n);
    for (usize i = 0; i < n; ++i) g[i] = comb::ifact(i + 1);
    g.inplace_inv(n);
    FPS f_egf(f);
    for (usize i = 0; i < n; ++i) f_egf[i] *= comb::fact(i);
    f_egf.inplace_rev().inplace_mul(g, n).inplace_rev() <<= 1;
    FPS result = std::move(f_egf);
    for (usize i = 1; i <= n; ++i) result[i] *= comb::ifact(i);
    return result;
}

} // namespace kk2

#endif // KK2_FPS_POWER_SUM_HPP
