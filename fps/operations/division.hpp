#ifndef KK2_FPS_OPERATIONS_DIVISION_HPP
#define KK2_FPS_OPERATIONS_DIVISION_HPP 1

#include <cassert>
#include <memory>
#include <utility>
#include <vector>

#include "../../type_traits/fps.hpp"
#include "../fps_sparsity_detector.hpp"

namespace kk2::fps::operations {

template <UnivariateFormalPowerSeries FPS>
FPS &inplace_dense_div(FPS &dividend, const FPS &divisor, int deg = -1) {
    using mint = typename FPS::value_type;
    assert(!divisor.empty() && divisor[0] != mint(0));
    if (deg == -1) deg = static_cast<int>(dividend.size());

    FPS inverse = divisor.dense_inv(deg);
    return dividend.inplace_pre(deg).inplace_dense_mul(inverse).inplace_pre(deg);
}

template <UnivariateFormalPowerSeries FPS>
FPS dense_div(const FPS &dividend, const FPS &divisor, int deg = -1) {
    FPS result = dividend;
    return inplace_dense_div(result, divisor, deg);
}

template <UnivariateFormalPowerSeries FPS>
FPS &inplace_sparse_div(FPS &dividend, const FPS &divisor, int deg = -1) {
    using mint = typename FPS::value_type;
    assert(!divisor.empty() && divisor[0] != mint(0));
    if (deg == -1) deg = static_cast<int>(dividend.size());

    const mint constant_inv = divisor[0].inv();
    std::vector<std::pair<int, mint>> support;
    for (int i = 1; i < static_cast<int>(divisor.size()); ++i) {
        if (divisor[i] != mint(0)) support.emplace_back(i, divisor[i] * constant_inv);
    }
    dividend *= constant_inv;
    dividend.resize(deg);
    for (int i = 0; i < deg; ++i) {
        for (const auto &[index, coefficient] : support) {
            if (i + index >= deg) break;
            dividend[i + index] -= dividend[i] * coefficient;
        }
    }
    return dividend;
}

template <UnivariateFormalPowerSeries FPS>
FPS sparse_div(const FPS &dividend, const FPS &divisor, int deg = -1) {
    FPS result = dividend;
    return inplace_sparse_div(result, divisor, deg);
}

template <UnivariateFormalPowerSeries FPS>
FPS div(const FPS &dividend, const FPS &divisor, int deg = -1) {
    using mint = typename FPS::value_type;
    assert(!divisor.empty() && divisor[0] != mint(0));
    if (is_sparse_operation(
            FPSOperation::DIVISION, NTTFriendlyFormalPowerSeries<FPS>, dividend, divisor, deg))
        return sparse_div(dividend, divisor, deg);
    return dense_div(dividend, divisor, deg);
}

template <UnivariateFormalPowerSeries FPS>
FPS &inplace_div(FPS &dividend, const FPS &divisor, int deg = -1) {
    using mint = typename FPS::value_type;
    assert(!divisor.empty() && divisor[0] != mint(0));
    const bool use_sparse = is_sparse_operation(
        FPSOperation::DIVISION, NTTFriendlyFormalPowerSeries<FPS>, dividend, divisor, deg);
    if (use_sparse) return inplace_sparse_div(dividend, divisor, deg);
    return inplace_dense_div(dividend, divisor, deg);
}

template <UnivariateFormalPowerSeries FPS>
FPS &inplace_dense_quo(FPS &dividend, const FPS &divisor) {
    assert(!divisor.empty());
    if (dividend.size() < divisor.size()) {
        dividend.clear();
        return dividend;
    }
    if (std::addressof(dividend) == std::addressof(divisor)) {
        dividend = FPS{1};
        return dividend;
    }

    const int quotient_size = dividend.size() - divisor.size() + 1;
    FPS reversed_inverse = divisor.rev().dense_inv(quotient_size);
    return dividend.inplace_rev()
        .inplace_pre(quotient_size)
        .inplace_dense_mul(reversed_inverse)
        .inplace_pre(quotient_size)
        .inplace_rev();
}

template <UnivariateFormalPowerSeries FPS> FPS dense_quo(const FPS &dividend, const FPS &divisor) {
    FPS result = dividend;
    return inplace_dense_quo(result, divisor);
}

template <UnivariateFormalPowerSeries FPS>
FPS &inplace_sparse_quo(FPS &dividend, const FPS &divisor) {
    using mint = typename FPS::value_type;
    assert(!divisor.empty());
    if (dividend.size() < divisor.size()) {
        dividend.clear();
        return dividend;
    }
    if (std::addressof(dividend) == std::addressof(divisor)) {
        dividend = FPS{1};
        return dividend;
    }

    const int quotient_size = dividend.size() - divisor.size() + 1;
    const mint leading_inv = divisor.back().inv();
    std::vector<std::pair<int, mint>> support;
    for (int i = static_cast<int>(divisor.size()) - 2; i >= 0; --i) {
        if (divisor[i] != mint(0))
            support.emplace_back(divisor.size() - 1 - i, divisor[i] * leading_inv);
    }
    FPS reversed_quotient(quotient_size);
    for (int k = 0; k < quotient_size; ++k) {
        reversed_quotient[k] = dividend[dividend.size() - 1 - k] * leading_inv;
        for (const auto &[offset, coefficient] : support) {
            if (offset > k) break;
            reversed_quotient[k] -= reversed_quotient[k - offset] * coefficient;
        }
    }
    reversed_quotient.inplace_rev();
    return dividend = std::move(reversed_quotient);
}

template <UnivariateFormalPowerSeries FPS> FPS sparse_quo(const FPS &dividend, const FPS &divisor) {
    FPS result = dividend;
    return inplace_sparse_quo(result, divisor);
}

template <UnivariateFormalPowerSeries FPS> FPS quo(const FPS &dividend, const FPS &divisor) {
    assert(!divisor.empty());
    if (dividend.size() < divisor.size()) return {};
    const int quotient_size = dividend.size() - divisor.size() + 1;
    if (is_sparse_operation(FPSOperation::POLYNOMIAL_DIVISION,
                            NTTFriendlyFormalPowerSeries<FPS>,
                            dividend,
                            divisor,
                            quotient_size))
        return sparse_quo(dividend, divisor);
    return dense_quo(dividend, divisor);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_quo(FPS &dividend, const FPS &divisor) {
    assert(!divisor.empty());
    if (dividend.size() < divisor.size()) {
        dividend.clear();
        return dividend;
    }
    const int quotient_size = dividend.size() - divisor.size() + 1;
    const bool use_sparse = is_sparse_operation(FPSOperation::POLYNOMIAL_DIVISION,
                                                NTTFriendlyFormalPowerSeries<FPS>,
                                                dividend,
                                                divisor,
                                                quotient_size);
    if (use_sparse) return inplace_sparse_quo(dividend, divisor);
    return inplace_dense_quo(dividend, divisor);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_mod(FPS &dividend, const FPS &divisor) {
    assert(!divisor.empty());
    if (std::addressof(dividend) == std::addressof(divisor)) {
        dividend.clear();
        return dividend;
    }
    FPS product = quo(dividend, divisor);
    return (dividend -= product.inplace_mul(divisor)).shrink();
}

template <UnivariateFormalPowerSeries FPS> FPS mod(const FPS &dividend, const FPS &divisor) {
    FPS result = dividend;
    return inplace_mod(result, divisor);
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_DIVISION_HPP
