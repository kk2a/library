#ifndef KK2_FPS_OPERATIONS_POWER_HPP
#define KK2_FPS_OPERATIONS_POWER_HPP 1

#include <tuple>
#include <vector>

#include "../../type_traits/fps.hpp"
#include "../fps_sparsity_detector.hpp"

namespace kk2::fps::operations {

struct PowerPreprocessResult {
    int deg;
    int normalized_deg;
    int shift;
    bool finished;
};

template <UnivariateFormalPowerSeries FPS, class T>
PowerPreprocessResult inplace_power_preprocess(FPS &f, T exponent, int deg) {
    using mint = typename FPS::value_type;
    if (deg == -1) deg = static_cast<int>(f.size());
    if (exponent == 0) {
        f.assign(deg, mint(0));
        if (deg > 0) f[0] = mint(1);
        return {deg, 0, 0, true};
    }

    int leading_zeros = 0;
    while (leading_zeros != static_cast<int>(f.size()) && f[leading_zeros] == mint(0))
        ++leading_zeros;
    if (leading_zeros == static_cast<int>(f.size())
        || __int128_t(leading_zeros) * exponent >= deg) {
        f.assign(deg, mint(0));
        return {deg, 0, 0, true};
    }

    const int shift = static_cast<int>(__int128_t(leading_zeros) * exponent);
    if (leading_zeros > 0) f.erase(f.begin(), f.begin() + leading_zeros);
    return {deg, deg - shift, shift, false};
}

template <UnivariateFormalPowerSeries FPS>
FPS &inplace_power_postprocess(FPS &f, const PowerPreprocessResult &preprocessed) {
    using mint = typename FPS::value_type;
    if (preprocessed.shift > 0) f.insert(f.begin(), preprocessed.shift, mint(0));
    f.resize(preprocessed.deg);
    return f;
}

template <UnivariateFormalPowerSeries FPS, class T>
FPS &inplace_dense_pow_normalized(FPS &f, T exponent, int deg) {
    const auto leading_coefficient = f[0];
    f *= leading_coefficient.inv();
    f.inplace_dense_log(deg);
    f *= exponent;
    f.inplace_dense_exp(deg);
    f *= leading_coefficient.pow(exponent);
    return f;
}

template <UnivariateFormalPowerSeries FPS, class T>
FPS &inplace_sparse_pow_normalized(FPS &f, T exponent, int deg) {
    using mint = typename FPS::value_type;
    const int mod = mint::getmod();
    static std::vector<mint> inverse{1, 1};
    while (static_cast<int>(inverse.size()) <= deg) {
        const int i = inverse.size();
        inverse.push_back(-inverse[mod % i] * (mod / i));
    }

    const mint constant_term = f[0].pow(exponent);
    exponent %= mod;
    std::vector<std::tuple<int, mint, mint>> support;
    for (int i = 1; i < static_cast<int>(f.size()); ++i) {
        if (f[i] != mint(0)) support.emplace_back(i, f[i], f[i] * mint(i) * (exponent + 1));
    }

    const mint constant_inv = f[0].inv();
    f.assign(deg, mint(0));
    f[0] = constant_term;
    for (int degree = 1; degree < deg; ++degree) {
        for (const auto &[index, coefficient, weighted_coefficient] : support) {
            if (degree < index) break;
            f[degree] += f[degree - index] * (weighted_coefficient - coefficient * degree);
        }
        f[degree] *= constant_inv * inverse[degree];
    }
    return f;
}

template <UnivariateFormalPowerSeries FPS>
bool power_uses_sparse(const FPS &normalized, int normalized_deg) {
    return is_sparse_operation(
        FPSOperation::POWER, NTTFriendlyFormalPowerSeries<FPS>, normalized, FPS(), normalized_deg);
}

template <UnivariateFormalPowerSeries FPS, class T>
FPS &inplace_dense_pow(FPS &f, T exponent, int deg = -1) {
    const PowerPreprocessResult preprocessed = inplace_power_preprocess(f, exponent, deg);
    if (preprocessed.finished) return f;
    inplace_dense_pow_normalized(f, exponent, preprocessed.normalized_deg);
    return inplace_power_postprocess(f, preprocessed);
}

template <UnivariateFormalPowerSeries FPS, class T>
FPS dense_pow(const FPS &f, T exponent, int deg = -1) {
    FPS result = f;
    inplace_dense_pow(result, exponent, deg);
    return result;
}

template <UnivariateFormalPowerSeries FPS, class T>
FPS &inplace_sparse_pow(FPS &f, T exponent, int deg = -1) {
    const PowerPreprocessResult preprocessed = inplace_power_preprocess(f, exponent, deg);
    if (preprocessed.finished) return f;
    inplace_sparse_pow_normalized(f, exponent, preprocessed.normalized_deg);
    return inplace_power_postprocess(f, preprocessed);
}

template <UnivariateFormalPowerSeries FPS, class T>
FPS sparse_pow(const FPS &f, T exponent, int deg = -1) {
    FPS result = f;
    inplace_sparse_pow(result, exponent, deg);
    return result;
}

template <UnivariateFormalPowerSeries FPS, class T>
FPS &inplace_pow(FPS &f, T exponent, int deg = -1) {
    const PowerPreprocessResult preprocessed = inplace_power_preprocess(f, exponent, deg);
    if (preprocessed.finished) return f;
    if (power_uses_sparse(f, preprocessed.normalized_deg))
        inplace_sparse_pow_normalized(f, exponent, preprocessed.normalized_deg);
    else inplace_dense_pow_normalized(f, exponent, preprocessed.normalized_deg);
    return inplace_power_postprocess(f, preprocessed);
}

template <UnivariateFormalPowerSeries FPS, class T>
FPS pow(const FPS &f, T exponent, int deg = -1) {
    FPS result = f;
    inplace_pow(result, exponent, deg);
    return result;
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_POWER_HPP
