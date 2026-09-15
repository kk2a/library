#ifndef KK2_FPS_OPERATIONS_SQRT_HPP
#define KK2_FPS_OPERATIONS_SQRT_HPP 1

#include <cassert>
#include <utility>

#include "../../math_mod/detail/mod_sqrt.hpp"
#include "../../type_traits/fps.hpp"
#include "../fps_sparsity_detector.hpp"
#include "power.hpp"

namespace kk2::fps::operations {

template <UnivariateFormalPowerSeries FPS> FPS dense_sqrt(const FPS &f, int precision = -1) {
    using mint = typename FPS::value_type;
    if (precision == -1) precision = static_cast<int>(f.size());
    if (f.empty()) return FPS(precision, mint(0));
    if (f[0] == mint(0)) {
        for (int i = 1; i < static_cast<int>(f.size()); ++i) {
            if (f[i] == mint(0)) continue;
            if (i & 1) return {};
            if (precision - i / 2 <= 0) break;
            FPS result = dense_sqrt(f >> i, precision - i / 2);
            if (result.empty()) return {};
            result <<= i / 2;
            if (static_cast<int>(result.size()) < precision) result.resize(precision, mint(0));
            return result;
        }
        return FPS(precision, mint(0));
    }

    const long long root = mod_sqrt_detail::mod_sqrt<NTTFriendlyFormalPowerSeries<FPS>>(f[0]);
    if (root == -1) return {};
    assert(root * root % mint::getmod() == f[0].val());
    FPS result{mint(root)};
    const mint inverse_two = mint(2).inv();
    for (int d = 1; d < precision; d <<= 1) {
        result = (result + f.pre(d << 1).dense_mul(result.dense_inv(d << 1))) * inverse_two;
    }
    return result.pre(precision);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_dense_sqrt(FPS &f, int precision = -1) {
    if (precision == -1) precision = static_cast<int>(f.size());
    return f = dense_sqrt(std::as_const(f), precision);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_sparse_sqrt(FPS &f, int precision = -1) {
    using mint = typename FPS::value_type;
    if (precision == -1) precision = static_cast<int>(f.size());
    if (f.empty()) {
        f.assign(precision, mint(0));
        return f;
    }
    if (f[0] == mint(0)) {
        for (int i = 1; i < static_cast<int>(f.size()); ++i) {
            if (f[i] == mint(0)) continue;
            if (i & 1) {
                f.clear();
                return f;
            }
            if (precision - i / 2 <= 0) break;
            f >>= i;
            inplace_sparse_sqrt(f, precision - i / 2);
            if (f.empty()) return f;
            f <<= i / 2;
            if (static_cast<int>(f.size()) < precision) f.resize(precision, mint(0));
            return f;
        }
        f.assign(precision, mint(0));
        return f;
    }

    const long long root = mod_sqrt_detail::mod_sqrt<NTTFriendlyFormalPowerSeries<FPS>>(f[0]);
    if (root == -1) {
        f.clear();
        return f;
    }
    return inplace_sparse_pow(f, (mint::getmod() + 1) >> 1, precision) *= mint(root).inv();
}

template <UnivariateFormalPowerSeries FPS> FPS sparse_sqrt(const FPS &f, int precision = -1) {
    FPS result = f;
    return inplace_sparse_sqrt(result, precision);
}

template <UnivariateFormalPowerSeries FPS> FPS sqrt(const FPS &f, int precision = -1) {
    using mint = typename FPS::value_type;
    if (!f.empty() && f[0] != mint(0)
        && is_sparse_operation(
            FPSOperation::SQRT, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), precision))
        return sparse_sqrt(f, precision);
    return dense_sqrt(f, precision);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_sqrt(FPS &f, int precision = -1) {
    using mint = typename FPS::value_type;
    const bool use_sparse =
        !f.empty() && f[0] != mint(0)
        && is_sparse_operation(
            FPSOperation::SQRT, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), precision);
    if (use_sparse) return inplace_sparse_sqrt(f, precision);
    return inplace_dense_sqrt(f, precision);
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_SQRT_HPP
