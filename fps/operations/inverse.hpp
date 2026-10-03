#ifndef KK2_FPS_OPERATIONS_INVERSE_HPP
#define KK2_FPS_OPERATIONS_INVERSE_HPP 1

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

#include "../../type_traits/fps.hpp"
#include "../fps_sparsity_detector.hpp"

namespace kk2::fps::operations {

template <UnivariateNTTFriendlyFormalPowerSeries FPS>
FPS dense_inv(const FPS &f, int precision = -1) {
    using mint = typename FPS::value_type;
    assert(!f.empty() && f[0] != mint(0));
    if (precision == -1) precision = static_cast<int>(f.size());

    FPS result(precision);
    if (precision == 0) return result;
    result[0] = mint(1) / f[0];
    for (int d = 1; d < precision; d <<= 1) {
        FPS lhs(2 * d), rhs(2 * d);
        std::copy_n(f.begin(), std::min(static_cast<int>(f.size()), 2 * d), lhs.begin());
        std::copy_n(result.begin(), d, rhs.begin());
        lhs.but();
        rhs.but();
        lhs.inplace_dot(rhs);
        lhs.ibut();
        std::fill_n(lhs.begin(), d, mint(0));
        lhs.but();
        lhs.inplace_dot(rhs);
        lhs.ibut();
        const int next_precision = std::min(2 * d, precision);
        std::transform(lhs.begin() + d,
                       lhs.begin() + next_precision,
                       result.begin() + d,
                       [](const mint &coefficient) { return -coefficient; });
    }
    return result;
}

template <UnivariateArbitraryModulusFormalPowerSeries FPS>
FPS dense_inv(const FPS &f, int precision = -1);

template <UnivariateFormalPowerSeries FPS> FPS &inplace_dense_inv(FPS &f, int precision = -1) {
    if (precision == -1) precision = static_cast<int>(f.size());
    return f = dense_inv(std::as_const(f), precision);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_sparse_inv(FPS &f, int precision = -1) {
    using mint = typename FPS::value_type;
    assert(!f.empty() && f[0] != mint(0));
    if (precision == -1) precision = static_cast<int>(f.size());

    std::vector<std::pair<int, mint>> support;
    for (int i = 1; i < static_cast<int>(f.size()); ++i) {
        if (f[i] != mint(0)) support.emplace_back(i, f[i]);
    }
    const mint constant_inv = f[0].inv();
    f.resize(precision);
    if (precision > 0) f[0] = constant_inv;
    for (int k = 1; k < precision; ++k) {
        f[k] = mint(0);
        for (const auto &[index, coefficient] : support) {
            if (k < index) break;
            f[k] += f[k - index] * coefficient;
        }
        f[k] *= -constant_inv;
    }
    return f;
}

template <UnivariateFormalPowerSeries FPS> FPS sparse_inv(const FPS &f, int precision = -1) {
    FPS result = f;
    return inplace_sparse_inv(result, precision);
}

template <UnivariateFormalPowerSeries FPS> FPS inv(const FPS &f, int precision = -1) {
    using mint = typename FPS::value_type;
    assert(!f.empty() && f[0] != mint(0));
    if (is_sparse_operation(
            FPSOperation::INVERSE, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), precision))
        return sparse_inv(f, precision);
    return dense_inv(f, precision);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_inv(FPS &f, int precision = -1) {
    using mint = typename FPS::value_type;
    assert(!f.empty() && f[0] != mint(0));
    const bool use_sparse = is_sparse_operation(
        FPSOperation::INVERSE, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), precision);
    if (use_sparse) return inplace_sparse_inv(f, precision);
    return inplace_dense_inv(f, precision);
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_INVERSE_HPP
