#ifndef KK2_FPS_OPERATIONS_MULTIPLICATION_HPP
#define KK2_FPS_OPERATIONS_MULTIPLICATION_HPP 1

#include "../../convolution/convolution.hpp"
#include "../../type_traits/fps.hpp"
#include "../fps_sparsity_detector.hpp"

namespace kk2::fps::operations {

template <NTTFriendlyFormalPowerSeries FPS>
FPS &inplace_dense_mul(FPS &lhs, const FPS &rhs, int deg = -1) {
    return inplace_dense_convolution(lhs, rhs, deg);
}

template <ArbitraryModulusFormalPowerSeries FPS>
FPS &inplace_dense_mul(FPS &lhs, const FPS &rhs, int deg = -1);

template <UnivariateFormalPowerSeries FPS>
FPS dense_mul(const FPS &lhs, const FPS &rhs, int deg = -1) {
    FPS result = lhs;
    inplace_dense_mul(result, rhs, deg);
    return result;
}

template <UnivariateFormalPowerSeries FPS>
FPS &inplace_sparse_mul(FPS &lhs, const FPS &rhs, int deg = -1) {
    return inplace_sparse_convolution(lhs, rhs, deg);
}

template <UnivariateFormalPowerSeries FPS>
FPS sparse_mul(const FPS &lhs, const FPS &rhs, int deg = -1) {
    FPS result = lhs;
    inplace_sparse_mul(result, rhs, deg);
    return result;
}

template <UnivariateFormalPowerSeries FPS> FPS mul(const FPS &lhs, const FPS &rhs, int deg = -1) {
    if (is_sparse_operation(
            FPSOperation::CONVOLUTION, NTTFriendlyFormalPowerSeries<FPS>, lhs, rhs, deg))
        return sparse_mul(lhs, rhs, deg);
    return dense_mul(lhs, rhs, deg);
}

template <UnivariateFormalPowerSeries FPS>
FPS &inplace_mul(FPS &lhs, const FPS &rhs, int deg = -1) {
    const bool use_sparse = is_sparse_operation(
        FPSOperation::CONVOLUTION, NTTFriendlyFormalPowerSeries<FPS>, lhs, rhs, deg);
    if (use_sparse) return inplace_sparse_mul(lhs, rhs, deg);
    return inplace_dense_mul(lhs, rhs, deg);
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_MULTIPLICATION_HPP
