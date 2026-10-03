#ifndef KK2_FPS_OPERATIONS_MULTIVARIATE_MULTIPLICATION_HPP
#define KK2_FPS_OPERATIONS_MULTIVARIATE_MULTIPLICATION_HPP 1

#include <cassert>

#include "../../../convolution/multi_convolution_truncated.hpp"
#include "../../../convolution/multi_convolution_truncated_arb.hpp"
#include "../../../type_traits/fps.hpp"

namespace kk2::fps::operations {

template <Multivariate FPS> FPS &inplace_dense_mul(FPS &lhs, const FPS &rhs) {
    assert(lhs.base == rhs.base && lhs.f.size() == rhs.f.size());
    if constexpr (ArbitraryModulusFormalPowerSeries<typename FPS::fps>) {
        inplace_multi_convolution_truncated_arb(lhs.f, rhs.f, lhs.base);
    } else {
        inplace_multi_convolution_truncated(lhs.f, rhs.f, lhs.base);
    }
    return lhs;
}

template <Multivariate FPS> FPS dense_mul(const FPS &lhs, const FPS &rhs) {
    FPS result = lhs;
    return inplace_dense_mul(result, rhs);
}

template <Multivariate FPS> FPS &inplace_sparse_mul(FPS &lhs, const FPS &rhs) {
    assert(lhs.base == rhs.base && lhs.f.size() == rhs.f.size());
    inplace_multi_convolution_truncated_sparse(lhs.f, rhs.f, lhs.base);
    return lhs;
}

template <Multivariate FPS> FPS sparse_mul(const FPS &lhs, const FPS &rhs) {
    FPS result = lhs;
    return inplace_sparse_mul(result, rhs);
}

template <Multivariate FPS> FPS mul(const FPS &lhs, const FPS &rhs) { return dense_mul(lhs, rhs); }

template <Multivariate FPS> FPS &inplace_mul(FPS &lhs, const FPS &rhs) {
    return inplace_dense_mul(lhs, rhs);
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_MULTIVARIATE_MULTIPLICATION_HPP
