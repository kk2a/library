#ifndef KK2_FPS_OPERATIONS_ARB_MULTIPLICATION_HPP
#define KK2_FPS_OPERATIONS_ARB_MULTIPLICATION_HPP 1

#include "../../../convolution/convolution_arb.hpp"
#include "../../../type_traits/fps.hpp"
#include "../multiplication.hpp"

namespace kk2::fps::operations {

template <ArbitraryModulusFormalPowerSeries FPS>
FPS &inplace_dense_mul(FPS &lhs, const FPS &rhs, int deg) {
    return inplace_dense_convolution_arb(lhs, rhs, deg);
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_ARB_MULTIPLICATION_HPP
