#ifndef KK2_FPS_OPERATIONS_SQRT_HPP
#define KK2_FPS_OPERATIONS_SQRT_HPP 1

#include <cassert>
#include <utility>

#include "../../math_mod/mod_sqrt.hpp"
#include "../../type_traits/fps.hpp"
#include "../fps_sparsity_detector.hpp"
#include "power.hpp"

namespace kk2::fps::operations {

template <UnivariateFormalPowerSeries FPS> FPS dense_sqrt(const FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    if (deg == -1) deg = static_cast<int>(f.size());
    if (f.empty()) return FPS(deg, mint(0));
    if (f[0] == mint(0)) {
        for (int i = 1; i < static_cast<int>(f.size()); ++i) {
            if (f[i] == mint(0)) continue;
            if (i & 1) return {};
            if (deg - i / 2 <= 0) break;
            FPS result = dense_sqrt(f >> i, deg - i / 2);
            if (result.empty()) return {};
            result <<= i / 2;
            if (static_cast<int>(result.size()) < deg) result.resize(deg, mint(0));
            return result;
        }
        return FPS(deg, mint(0));
    }

    const long long root = mod_sqrt(f[0].val(), mint::getmod());
    if (root == -1) return {};
    assert(root * root % mint::getmod() == f[0].val());
    FPS result{mint(root)};
    const mint inverse_two = mint(2).inv();
    for (int d = 1; d < deg; d <<= 1) {
        result = (result + f.pre(d << 1).dense_mul(result.dense_inv(d << 1))) * inverse_two;
    }
    return result.pre(deg);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_dense_sqrt(FPS &f, int deg = -1) {
    if (deg == -1) deg = static_cast<int>(f.size());
    return f = dense_sqrt(std::as_const(f), deg);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_sparse_sqrt(FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    if (deg == -1) deg = static_cast<int>(f.size());
    if (f.empty()) {
        f.assign(deg, mint(0));
        return f;
    }
    if (f[0] == mint(0)) {
        for (int i = 1; i < static_cast<int>(f.size()); ++i) {
            if (f[i] == mint(0)) continue;
            if (i & 1) {
                f.clear();
                return f;
            }
            if (deg - i / 2 <= 0) break;
            f >>= i;
            inplace_sparse_sqrt(f, deg - i / 2);
            if (f.empty()) return f;
            f <<= i / 2;
            if (static_cast<int>(f.size()) < deg) f.resize(deg, mint(0));
            return f;
        }
        f.assign(deg, mint(0));
        return f;
    }

    const long long root = mod_sqrt(f[0].val(), mint::getmod());
    if (root == -1) {
        f.clear();
        return f;
    }
    return inplace_sparse_pow(f, (mint::getmod() + 1) >> 1, deg) *= mint(root).inv();
}

template <UnivariateFormalPowerSeries FPS> FPS sparse_sqrt(const FPS &f, int deg = -1) {
    FPS result = f;
    return inplace_sparse_sqrt(result, deg);
}

template <UnivariateFormalPowerSeries FPS> FPS sqrt(const FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    if (!f.empty() && f[0] != mint(0)
        && is_sparse_operation(
            FPSOperation::SQRT, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), deg))
        return sparse_sqrt(f, deg);
    return dense_sqrt(f, deg);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_sqrt(FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    const bool use_sparse =
        !f.empty() && f[0] != mint(0)
        && is_sparse_operation(
            FPSOperation::SQRT, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), deg);
    if (use_sparse) return inplace_sparse_sqrt(f, deg);
    return inplace_dense_sqrt(f, deg);
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_SQRT_HPP
