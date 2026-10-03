#ifndef KK2_FPS_POLY_SAMPLE_POINT_SHIFT_HPP
#define KK2_FPS_POLY_SAMPLE_POINT_SHIFT_HPP 1

#include <vector>

#include "../convolution/convolution.hpp"
#include "../type_traits/modint.hpp"
#include "detail/poly_sample_point_shift.hpp"

namespace kk2 {

/**
 * @brief `return f(t), ..., f(t + m - 1) where f(i) = y[i]`
 *
 */
template <modint::Modular mint>
std::vector<mint> sample_point_shift(
    const std::vector<mint> &y,
    mint t,
    i32 m = -1,
    detail::SamplePointShiftConvolution<mint> convolve = &convolution<std::vector<mint>>) {
    return detail::sample_point_shift(y, t, m, convolve);
}

} // namespace kk2

#endif // KK2_FPS_POLY_SAMPLE_POINT_SHIFT_HPP
