#ifndef KK2_FPS_OPERATIONS_INVERSE_HPP
#define KK2_FPS_OPERATIONS_INVERSE_HPP 1

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

#include "../../type_traits/fps.hpp"
#include "../fps_sparsity_detector.hpp"

namespace kk2::fps::operations {

template <NTTFriendlyFormalPowerSeries FPS> FPS dense_inv(const FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    assert(!f.empty() && f[0] != mint(0));
    if (deg == -1) deg = static_cast<int>(f.size());

    FPS result(deg);
    if (deg == 0) return result;
    result[0] = mint(1) / f[0];
    for (int d = 1; d < deg; d <<= 1) {
        FPS lhs(2 * d), rhs(2 * d);
        std::copy(f.begin(), f.begin() + std::min(static_cast<int>(f.size()), 2 * d), lhs.begin());
        std::copy(result.begin(), result.begin() + d, rhs.begin());
        lhs.but();
        rhs.but();
        lhs.inplace_dot(rhs);
        lhs.ibut();
        std::fill(lhs.begin(), lhs.begin() + d, mint(0));
        lhs.but();
        lhs.inplace_dot(rhs);
        lhs.ibut();
        for (int j = d; j < std::min(2 * d, deg); ++j) result[j] = -lhs[j];
    }
    return result;
}

template <ArbitraryModulusFormalPowerSeries FPS> FPS dense_inv(const FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    assert(!f.empty() && f[0] != mint(0));
    if (deg == -1) deg = static_cast<int>(f.size());
    if (deg == 0) return {};

    FPS result{f[0].inv()};
    for (int d = 1; d < deg; d <<= 1) {
        result = (result + result - f.pre(d << 1).dense_mul(result.dense_mul(result))).pre(d << 1);
    }
    return result.pre(deg);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_dense_inv(FPS &f, int deg = -1) {
    if (deg == -1) deg = static_cast<int>(f.size());
    return f = dense_inv(std::as_const(f), deg);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_sparse_inv(FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    assert(!f.empty() && f[0] != mint(0));
    if (deg == -1) deg = static_cast<int>(f.size());

    std::vector<std::pair<int, mint>> support;
    for (int i = 1; i < static_cast<int>(f.size()); ++i) {
        if (f[i] != mint(0)) support.emplace_back(i, f[i]);
    }
    const mint constant_inv = f[0].inv();
    f.resize(deg);
    if (deg > 0) f[0] = constant_inv;
    for (int k = 1; k < deg; ++k) {
        f[k] = mint(0);
        for (const auto &[index, coefficient] : support) {
            if (k < index) break;
            f[k] += f[k - index] * coefficient;
        }
        f[k] *= -constant_inv;
    }
    return f;
}

template <UnivariateFormalPowerSeries FPS> FPS sparse_inv(const FPS &f, int deg = -1) {
    FPS result = f;
    return inplace_sparse_inv(result, deg);
}

template <UnivariateFormalPowerSeries FPS> FPS inv(const FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    assert(!f.empty() && f[0] != mint(0));
    if (is_sparse_operation(
            FPSOperation::INVERSE, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), deg))
        return sparse_inv(f, deg);
    return dense_inv(f, deg);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_inv(FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    assert(!f.empty() && f[0] != mint(0));
    const bool use_sparse = is_sparse_operation(
        FPSOperation::INVERSE, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), deg);
    if (use_sparse) return inplace_sparse_inv(f, deg);
    return inplace_dense_inv(f, deg);
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_INVERSE_HPP
