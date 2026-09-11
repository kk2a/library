#ifndef KK2_FPS_OPERATIONS_EXPONENTIAL_HPP
#define KK2_FPS_OPERATIONS_EXPONENTIAL_HPP 1

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

#include "../../type_traits/fps.hpp"
#include "../fps_sparsity_detector.hpp"

namespace kk2::fps::operations {

template <NTTFriendlyFormalPowerSeries FPS> FPS dense_exp(const FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    assert(f.empty() || f[0] == mint(0));
    if (deg == -1) deg = static_cast<int>(f.size());

    FPS result{1, 1 < static_cast<int>(f.size()) ? f[1] : mint(0)};
    FPS inverse{1}, transformed_inverse, previous_transformed_inverse{1, 1};
    for (int m = 2; m < deg; m <<= 1) {
        FPS transformed_result = result;
        transformed_result.resize(m << 1);
        transformed_result.but();
        transformed_inverse = previous_transformed_inverse;
        FPS correction(m);
        correction = transformed_result.dot(transformed_inverse);
        correction.ibut();
        std::fill(correction.begin(), correction.begin() + (m >> 1), mint(0));
        correction.but();
        correction.inplace_dot(-transformed_inverse);
        correction.ibut();
        inverse.insert(inverse.end(), correction.begin() + (m >> 1), correction.end());
        previous_transformed_inverse = inverse;
        previous_transformed_inverse.resize(m << 1);
        previous_transformed_inverse.but();

        FPS delta(f.begin(), f.begin() + std::min(static_cast<int>(f.size()), m));
        delta.resize(m);
        delta.inplace_diff();
        delta.push_back(mint(0));
        delta.but();
        delta.inplace_dot(transformed_result);
        delta.ibut();
        delta -= result.diff();
        delta.resize(m << 1);
        for (int i = 0; i < m - 1; ++i) {
            delta[m + i] = delta[i];
            delta[i] = mint(0);
        }
        delta.but();
        delta.inplace_dot(previous_transformed_inverse);
        delta.ibut();
        delta.pop_back();
        delta.inplace_int();
        for (int i = m; i < std::min(static_cast<int>(f.size()), m << 1); ++i) delta[i] += f[i];
        std::fill(delta.begin(), delta.begin() + m, mint(0));
        delta.but();
        delta.inplace_dot(transformed_result);
        delta.ibut();
        result.insert(result.end(), delta.begin() + m, delta.end());
    }
    return FPS(result.begin(), result.begin() + deg);
}

template <ArbitraryModulusFormalPowerSeries FPS> FPS dense_exp(const FPS &f, int deg = -1);

template <UnivariateFormalPowerSeries FPS> FPS &inplace_dense_exp(FPS &f, int deg = -1) {
    if (deg == -1) deg = static_cast<int>(f.size());
    return f = dense_exp(std::as_const(f), deg);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_sparse_exp(FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    assert(f.empty() || f[0] == mint(0));
    if (deg == -1) deg = static_cast<int>(f.size());

    std::vector<std::pair<int, mint>> support;
    for (int i = 1; i < static_cast<int>(f.size()); ++i) {
        if (f[i] != mint(0)) support.emplace_back(i, f[i] * i);
    }

    const int mod = mint::getmod();
    static std::vector<mint> inverse{1, 1};
    const int old_size = inverse.size();
    inverse.resize(std::max(old_size, deg + 1));
    for (int i = old_size; i <= deg; ++i) inverse[i] = -inverse[mod % i] * (mod / i);

    f.assign(deg, mint(0));
    if (deg > 0) f[0] = mint(1);
    for (int k = 0; k < deg - 1; ++k) {
        for (const auto &[index, derivative_coefficient] : support) {
            const int derivative_index = index - 1;
            if (k < derivative_index) break;
            f[k + 1] += f[k - derivative_index] * derivative_coefficient;
        }
        f[k + 1] *= inverse[k + 1];
    }
    return f;
}

template <UnivariateFormalPowerSeries FPS> FPS sparse_exp(const FPS &f, int deg = -1) {
    FPS result = f;
    return inplace_sparse_exp(result, deg);
}

template <UnivariateFormalPowerSeries FPS> FPS exp(const FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    assert(f.empty() || f[0] == mint(0));
    if (is_sparse_operation(FPSOperation::EXP, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), deg))
        return sparse_exp(f, deg);
    return dense_exp(f, deg);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_exp(FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    assert(f.empty() || f[0] == mint(0));
    const bool use_sparse =
        is_sparse_operation(FPSOperation::EXP, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), deg);
    if (use_sparse) return inplace_sparse_exp(f, deg);
    return inplace_dense_exp(f, deg);
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_EXPONENTIAL_HPP
