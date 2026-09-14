#ifndef KK2_FPS_OPERATIONS_POWER_HPP
#define KK2_FPS_OPERATIONS_POWER_HPP 1

#include <tuple>
#include <vector>

#include "../../type_traits/fps.hpp"
#include "../../type_traits/integral.hpp"
#include "../fps_sparsity_detector.hpp"

namespace kk2::fps::operations {

struct PowerPreprocessResult {
    int precision;
    int normalized_precision;
    int shift;
    bool finished;
};

template <UnivariateFormalPowerSeries FPS, Integral T>
PowerPreprocessResult inplace_power_preprocess(FPS &f, T exponent, int precision) {
    using mint = typename FPS::value_type;
    if (precision == -1) precision = static_cast<int>(f.size());
    if (exponent == 0) {
        f.assign(precision, mint(0));
        if (precision > 0) f[0] = mint(1);
        return {precision, 0, 0, true};
    }

    int leading_zeros = 0;
    while (leading_zeros != static_cast<int>(f.size()) && f[leading_zeros] == mint(0))
        ++leading_zeros;
    if (leading_zeros == static_cast<int>(f.size())
        || __int128_t(leading_zeros) * exponent >= precision) {
        f.assign(precision, mint(0));
        return {precision, 0, 0, true};
    }

    const int shift = static_cast<int>(__int128_t(leading_zeros) * exponent);
    if (leading_zeros > 0) f.erase(f.begin(), f.begin() + leading_zeros);
    return {precision, precision - shift, shift, false};
}

template <UnivariateFormalPowerSeries FPS>
FPS &inplace_power_postprocess(FPS &f, const PowerPreprocessResult &preprocessed) {
    using mint = typename FPS::value_type;
    if (preprocessed.shift > 0) f.insert(f.begin(), preprocessed.shift, mint(0));
    f.resize(preprocessed.precision);
    return f;
}

template <UnivariateFormalPowerSeries FPS, Integral T>
FPS &inplace_dense_pow_normalized(FPS &f, T exponent, int precision) {
    const auto leading_coefficient = f[0];
    f *= leading_coefficient.inv();
    f.inplace_dense_log(precision);
    f *= exponent;
    f.inplace_dense_exp(precision);
    f *= leading_coefficient.pow(exponent);
    return f;
}

template <UnivariateFormalPowerSeries FPS, Integral T>
FPS &inplace_sparse_pow_normalized(FPS &f, T exponent, int precision) {
    using mint = typename FPS::value_type;
    const int mod = mint::getmod();
    static std::vector<mint> inverse{1, 1};
    while (static_cast<int>(inverse.size()) <= precision) {
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
    f.assign(precision, mint(0));
    f[0] = constant_term;
    for (int degree = 1; degree < precision; ++degree) {
        for (const auto &[index, coefficient, weighted_coefficient] : support) {
            if (degree < index) break;
            f[degree] += f[degree - index] * (weighted_coefficient - coefficient * degree);
        }
        f[degree] *= constant_inv * inverse[degree];
    }
    return f;
}

template <UnivariateFormalPowerSeries FPS>
bool power_uses_sparse(const FPS &normalized, int normalized_precision) {
    return is_sparse_operation(FPSOperation::POWER,
                               NTTFriendlyFormalPowerSeries<FPS>,
                               normalized,
                               FPS(),
                               normalized_precision);
}

template <UnivariateFormalPowerSeries FPS, Integral T>
FPS &inplace_dense_pow(FPS &f, T exponent, int precision = -1) {
    const PowerPreprocessResult preprocessed = inplace_power_preprocess(f, exponent, precision);
    if (preprocessed.finished) return f;
    inplace_dense_pow_normalized(f, exponent, preprocessed.normalized_precision);
    return inplace_power_postprocess(f, preprocessed);
}

template <UnivariateFormalPowerSeries FPS, Integral T>
FPS dense_pow(const FPS &f, T exponent, int precision = -1) {
    FPS result = f;
    inplace_dense_pow(result, exponent, precision);
    return result;
}

template <UnivariateFormalPowerSeries FPS, Integral T>
FPS &inplace_sparse_pow(FPS &f, T exponent, int precision = -1) {
    const PowerPreprocessResult preprocessed = inplace_power_preprocess(f, exponent, precision);
    if (preprocessed.finished) return f;
    inplace_sparse_pow_normalized(f, exponent, preprocessed.normalized_precision);
    return inplace_power_postprocess(f, preprocessed);
}

template <UnivariateFormalPowerSeries FPS, Integral T>
FPS sparse_pow(const FPS &f, T exponent, int precision = -1) {
    FPS result = f;
    inplace_sparse_pow(result, exponent, precision);
    return result;
}

template <UnivariateFormalPowerSeries FPS, Integral T>
FPS &inplace_pow(FPS &f, T exponent, int precision = -1) {
    const PowerPreprocessResult preprocessed = inplace_power_preprocess(f, exponent, precision);
    if (preprocessed.finished) return f;
    if (power_uses_sparse(f, preprocessed.normalized_precision))
        inplace_sparse_pow_normalized(f, exponent, preprocessed.normalized_precision);
    else inplace_dense_pow_normalized(f, exponent, preprocessed.normalized_precision);
    return inplace_power_postprocess(f, preprocessed);
}

template <UnivariateFormalPowerSeries FPS, Integral T>
FPS pow(const FPS &f, T exponent, int precision = -1) {
    FPS result = f;
    inplace_pow(result, exponent, precision);
    return result;
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_POWER_HPP
