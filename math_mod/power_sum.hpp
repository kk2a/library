#ifndef KK2_MATH_MOD_POWER_SUM_HPP
#define KK2_MATH_MOD_POWER_SUM_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <ranges>
#include <utility>
#include <vector>

#include "../common/type_alias.hpp"
#include "../fps/poly_sample_point_evaluate.hpp"
#include "../math/multiplicative_function/pow_table.hpp"
#include "../math_mod/comb.hpp"
#include "../math_mod/inv_table.hpp"
#include "../type_traits/integral.hpp"
#include "../type_traits/modint.hpp"

namespace kk2 {

/**
 * @brief Return `sum_{i=0}^{n-1} i^k`.
 * @see https://kk2a.github.io/library/math_mod/power_sum.hpp.html#sum-of-monomial
 */
template <modint::Modular mint, UnsignedIntegral T1, UnsignedIntegral T2>
mint sum_of_monomial(T1 n, T2 k) {
    if (n == 0) return 0;
    if (k == 0) return mint(n);
    std::vector<mint> value = pow_table<mint>(k, k);
    std::vector<mint> sum(static_cast<usize>(k) + 2);
    for (usize i = 0; i <= k; ++i) sum[i + 1] = sum[i] + value[i];
    return sample_point_evaluate(sum, mint(n));
}

/**
 * @brief Return `sum_{i=0}^{n-1} f(i)` from the samples `f(0), ..., f(k)`.
 * @see https://kk2a.github.io/library/math_mod/power_sum.hpp.html#sum-of-polynomial-samples
 */
template <modint::Modular mint, UnsignedIntegral T>
mint sum_of_polynomial_samples(const std::vector<mint> &samples, T n) {
    assert(!samples.empty());
    assert(samples.size() < static_cast<usize>(mint::getmod()));

    if (n <= samples.size()) {
        return std::ranges::fold_left(
            samples | std::views::take(static_cast<usize>(n)), mint(0), std::plus{});
    }

    std::vector<mint> prefix_sum(samples.size() + 1);
    for (usize i = 0; i < samples.size(); ++i) prefix_sum[i + 1] = prefix_sum[i] + samples[i];

    return sample_point_evaluate(prefix_sum, mint(n));
}

/**
 * @brief Return the rational-function value of `sum_{i=0}^infty r^i f(i)` from its samples.
 * @see
 * https://kk2a.github.io/library/math_mod/power_sum.hpp.html#sum-of-geometric-polynomial-samples-infinite
 */
template <modint::Modular mint>
mint sum_of_geometric_polynomial_samples(mint r, const std::vector<mint> &samples) {
    assert(!samples.empty());
    assert(samples.size() < static_cast<usize>(mint::getmod()));
    assert(r != mint(1));
    if (r == mint(0)) return samples[0];

    const usize k = samples.size() - 1;
    const usize m = k + 1;
    InvTable<mint>::set_upper(m);

    const mint minus_r = -r;
    const mint inverse_minus_r = minus_r.inv();
    mint denominator_coefficient = mint(m) * minus_r.pow(k);
    mint denominator_prefix = (mint(1) - r).pow(m) - minus_r.pow(m);
    mint r_power = 1;
    mint numerator = 0;
    for (usize i = 0; i <= k; ++i, r_power *= r) {
        numerator += samples[i] * r_power * denominator_prefix;
        if (i != k) {
            const usize j = k - i;
            denominator_prefix -= denominator_coefficient;
            denominator_coefficient *=
                mint(j) * InvTable<mint>::inv_unchecked(m - j + 1) * inverse_minus_r;
        }
    }
    return numerator / (mint(1) - r).pow(m);
}

/**
 * @brief Return `sum_{i=0}^{n-1} r^i f(i)` from the samples `f(0), ..., f(k)`.
 * @see
 * https://kk2a.github.io/library/math_mod/power_sum.hpp.html#sum-of-geometric-polynomial-samples-finite
 */
template <modint::Modular mint, UnsignedIntegral T>
mint sum_of_geometric_polynomial_samples(mint r, T n, const std::vector<mint> &samples) {
    assert(!samples.empty());
    assert(samples.size() < static_cast<usize>(mint::getmod()));
    if (n == 0) return mint(0);
    if (r == mint(0)) return samples[0];
    if (r == mint(1)) return sum_of_polynomial_samples<mint>(samples, n);

    if (n <= samples.size()) {
        mint res = 0;
        mint rp = 1;
        for (usize i = 0; i < static_cast<usize>(n); ++i, rp *= r) res += rp * samples[i];
        return res;
    }

    Comb<mint>::set_upper(samples.size());
    const mint infinite_sum = sum_of_geometric_polynomial_samples(r, samples);
    const mint ir = r.inv();
    std::vector<mint> tail_samples(samples.size());
    tail_samples[0] = -infinite_sum;
    for (usize i = 0; i + 1 < samples.size(); ++i) {
        tail_samples[i + 1] = ir * (tail_samples[i] + samples[i]);
    }

    return infinite_sum + r.pow(n) * sample_point_evaluate(tail_samples, mint(n));
}

/**
 * @brief Return `sum_{i=0}^{n-1} r^i i^k`.
 * @see https://kk2a.github.io/library/math_mod/power_sum.hpp.html#sum-of-geometric-monomial-finite
 */
template <modint::Modular mint, UnsignedIntegral T1, UnsignedIntegral T2>
mint sum_of_geometric_monomial(mint r, T1 n, T2 k) {
    return sum_of_geometric_polynomial_samples(r, n, pow_table<mint>(k, k));
}

/**
 * @brief Return the rational-function value of `sum_{i=0}^infty r^i i^k`.
 * @see
 * https://kk2a.github.io/library/math_mod/power_sum.hpp.html#sum-of-geometric-monomial-infinite
 */
template <modint::Modular mint, UnsignedIntegral T> mint sum_of_geometric_monomial(mint r, T k) {
    return sum_of_geometric_polynomial_samples(r, pow_table<mint>(k, k));
}

} // namespace kk2

#endif // KK2_MATH_MOD_POWER_SUM_HPP
