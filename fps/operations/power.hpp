#ifndef KK2_FPS_OPERATIONS_POWER_HPP
#define KK2_FPS_OPERATIONS_POWER_HPP 1

#include <tuple>
#include <vector>

#include "../../type_traits/fps.hpp"
#include "../fps_sparsity_detector.hpp"

namespace kk2::fps::operations {

template <UnivariateFormalPowerSeries FPS, class T>
FPS &inplace_dense_pow(FPS &f, T exponent, int deg = -1) {
    using mint = typename FPS::value_type;
    const int size = f.size();
    if (deg == -1) deg = size;
    if (exponent == 0) {
        f.assign(deg, mint(0));
        if (deg > 0) f[0] = mint(1);
        return f;
    }

    for (int i = 0; i < size; ++i) {
        if (f[i] != mint(0)) {
            const mint leading_coefficient = f[i];
            f *= leading_coefficient.inv();
            f >>= i;
            f.inplace_dense_log(deg);
            f *= exponent;
            f.inplace_dense_exp(deg);
            f *= leading_coefficient.pow(exponent);
            f <<= i * exponent;
            f.inplace_pre(deg);
            return f;
        }
        if (__int128_t(i + 1) * exponent >= deg) {
            f.assign(deg, mint(0));
            return f;
        }
    }
    f.assign(deg, mint(0));
    return f;
}

template <UnivariateFormalPowerSeries FPS, class T>
FPS dense_pow(const FPS &f, T exponent, int deg = -1) {
    FPS result = f;
    return inplace_dense_pow(result, exponent, deg);
}

template <UnivariateFormalPowerSeries FPS, class T>
FPS &inplace_sparse_pow(FPS &f, T exponent, int deg = -1) {
    using mint = typename FPS::value_type;
    if (deg == -1) deg = static_cast<int>(f.size());
    if (exponent == 0) {
        f.assign(deg, mint(0));
        if (deg > 0) f[0] = mint(1);
        return f;
    }

    int leading_zeros = 0;
    while (leading_zeros != static_cast<int>(f.size()) && f[leading_zeros] == mint(0))
        ++leading_zeros;
    if (leading_zeros == static_cast<int>(f.size())
        || __int128_t(leading_zeros) * exponent >= deg) {
        f.assign(deg, mint(0));
        return f;
    }
    if (leading_zeros != 0) {
        const int shift = leading_zeros * exponent;
        f.erase(f.begin(), f.begin() + leading_zeros);
        inplace_sparse_pow(f, exponent, deg - shift);
        f.insert(f.begin(), shift, mint(0));
        return f;
    }

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
    if (deg > 0) f[0] = constant_term;
    for (int degree = 1; degree < deg; ++degree) {
        for (const auto &[index, coefficient, weighted_coefficient] : support) {
            if (degree < index) break;
            f[degree] += f[degree - index] * (weighted_coefficient - coefficient * degree);
        }
        f[degree] *= constant_inv * inverse[degree];
    }
    return f;
}

template <UnivariateFormalPowerSeries FPS, class T>
FPS sparse_pow(const FPS &f, T exponent, int deg = -1) {
    FPS result = f;
    return inplace_sparse_pow(result, exponent, deg);
}

template <UnivariateFormalPowerSeries FPS, class T>
bool power_uses_sparse(const FPS &f, T exponent, int deg) {
    using mint = typename FPS::value_type;
    if (deg == -1) deg = static_cast<int>(f.size());
    if (exponent == 0) return false;

    int leading_zeros = 0;
    while (leading_zeros != static_cast<int>(f.size()) && f[leading_zeros] == mint(0))
        ++leading_zeros;
    if (leading_zeros == static_cast<int>(f.size()) || __int128_t(leading_zeros) * exponent >= deg)
        return false;
    if (leading_zeros == 0)
        return is_sparse_operation(
            FPSOperation::POWER, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), deg);

    FPS normalized(f.begin() + leading_zeros, f.end());
    const int normalized_deg = deg - int(__int128_t(leading_zeros) * exponent);
    return is_sparse_operation(
        FPSOperation::POWER, NTTFriendlyFormalPowerSeries<FPS>, normalized, FPS(), normalized_deg);
}

template <UnivariateFormalPowerSeries FPS, class T>
FPS pow(const FPS &f, T exponent, int deg = -1) {
    if (power_uses_sparse(f, exponent, deg)) return sparse_pow(f, exponent, deg);
    return dense_pow(f, exponent, deg);
}

template <UnivariateFormalPowerSeries FPS, class T>
FPS &inplace_pow(FPS &f, T exponent, int deg = -1) {
    const bool use_sparse = power_uses_sparse(f, exponent, deg);
    if (use_sparse) return inplace_sparse_pow(f, exponent, deg);
    return inplace_dense_pow(f, exponent, deg);
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_POWER_HPP
