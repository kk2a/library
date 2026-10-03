#ifndef KK2_FPS_DETAIL_POLY_SAMPLE_POINT_SHIFT_HPP
#define KK2_FPS_DETAIL_POLY_SAMPLE_POINT_SHIFT_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

#include "../../common/type_alias.hpp"
#include "../../math_mod/comb.hpp"
#include "../../type_traits/modint.hpp"
#include "../poly_sample_point_evaluate.hpp"

namespace kk2::detail {

template <modint::Modular mint>
using SamplePointShiftConvolution = std::vector<mint> (*)(const std::vector<mint> &,
                                                          const std::vector<mint> &,
                                                          int);

template <modint::Modular mint>
std::vector<mint> sample_point_shift_impl(const std::vector<mint> &y,
                                          mint t,
                                          i32 m,
                                          SamplePointShiftConvolution<mint> convolve) {
    if (m == 0) return {};
    if (m == 1) return {sample_point_evaluate(y, t)};
    if (y.empty()) return std::vector<mint>(m);
    i64 tval = static_cast<i64>(t.val());
    i32 k = static_cast<i32>(y.size()) - 1;
    if (tval <= k) {
        std::vector<mint> ret(m);
        i32 ptr = 0;
        for (i64 i = tval; i <= k and ptr < m; i++) { ret[ptr++] = y[i]; }
        if (k + 1 < tval + m) {
            auto suf = sample_point_shift_impl(y, mint(k + 1), m - ptr, convolve);
            for (i64 i = k + 1; i < tval + m; i++) { ret[ptr++] = suf[i - (k + 1)]; }
        }
        return ret;
    }
    const i64 modulus = static_cast<i64>(mint::getmod());
    if (tval + m > modulus) {
        auto pref = sample_point_shift_impl(y, t, static_cast<i32>(modulus - tval), convolve);
        auto suf =
            sample_point_shift_impl(y, mint(0), static_cast<i32>(m + tval - modulus), convolve);
        std::ranges::copy(suf, std::back_inserter(pref));
        return pref;
    }

    std::vector<mint> d(k + 1);
    Comb<mint>::set_upper(k);
    for (i32 i = 0; i <= k; i++) {
        d[i] = Comb<mint>::ifact(i) * Comb<mint>::ifact(k - i) * y[i];
        if ((k - i) & 1) d[i] = -d[i];
    }

    std::vector<mint> h(m + k);
    mint product = 1;
    for (i32 i = 0; i < m + k; i++) {
        h[i] = product;
        product *= t - k + i;
    }
    product = product.inv();
    for (i32 i = m + k - 1; i >= 0; i--) {
        h[i] *= product;
        product *= t - k + i;
    }

    std::vector<mint> dh = convolve(d, h, -1);

    std::vector<mint> ret(m);
    mint cur = t;
    for (i32 i = 1; i <= k; i++) cur *= t - i;
    for (i32 i = 0; i < m; i++) {
        ret[i] = cur * dh[k + i];
        cur *= t + i + 1;
        cur *= h[i];
    }
    return ret;
}

template <modint::Modular mint>
std::vector<mint> sample_point_shift(const std::vector<mint> &y,
                                     mint t,
                                     i32 m,
                                     SamplePointShiftConvolution<mint> convolve) {
    if (m == -1) m = y.size();
    assert(m >= 0);
    return sample_point_shift_impl(y, t, m, convolve);
}

} // namespace kk2::detail

#endif // KK2_FPS_DETAIL_POLY_SAMPLE_POINT_SHIFT_HPP
