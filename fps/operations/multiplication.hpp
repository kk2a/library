#ifndef KK2_FPS_OPERATIONS_MULTIPLICATION_HPP
#define KK2_FPS_OPERATIONS_MULTIPLICATION_HPP 1

#include <utility>

#include "../../convolution/convolution.hpp"
#include "../../convolution/convolution_arb.hpp"
#include "../../type_traits/fps.hpp"
#include "../fps_sparsity_detector.hpp"

namespace kk2::fps::operations {

template <NTTFriendlyFormalPowerSeries FPS> FPS &inplace_dense_mul(FPS &lhs, const FPS &rhs) {
    return inplace_dense_convolution(lhs, rhs);
}

template <ArbitraryModulusFormalPowerSeries FPS> FPS &inplace_dense_mul(FPS &lhs, const FPS &rhs) {
    return inplace_dense_convolution_arb(lhs, rhs);
}

template <UnivariateFormalPowerSeries FPS> FPS dense_mul(const FPS &lhs, const FPS &rhs) {
    FPS result = lhs;
    return inplace_dense_mul(result, rhs);
}

template <UnivariateFormalPowerSeries FPS> FPS sparse_mul(const FPS &lhs, const FPS &rhs) {
    return sparse_convolution(lhs, rhs);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_sparse_mul(FPS &lhs, const FPS &rhs) {
    return lhs = sparse_mul(std::as_const(lhs), rhs);
}

template <UnivariateFormalPowerSeries FPS> FPS mul(const FPS &lhs, const FPS &rhs) {
    if (is_sparse_operation(FPSOperation::CONVOLUTION, NTTFriendlyFormalPowerSeries<FPS>, lhs, rhs))
        return sparse_mul(lhs, rhs);
    return dense_mul(lhs, rhs);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_mul(FPS &lhs, const FPS &rhs) {
    const bool use_sparse =
        is_sparse_operation(FPSOperation::CONVOLUTION, NTTFriendlyFormalPowerSeries<FPS>, lhs, rhs);
    if (use_sparse) return inplace_sparse_mul(lhs, rhs);
    return inplace_dense_mul(lhs, rhs);
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_MULTIPLICATION_HPP
