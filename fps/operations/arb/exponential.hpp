#ifndef KK2_FPS_OPERATIONS_ARB_EXPONENTIAL_HPP
#define KK2_FPS_OPERATIONS_ARB_EXPONENTIAL_HPP 1

#include <cassert>

#include "../../../type_traits/fps.hpp"
#include "../exponential.hpp"

namespace kk2::fps::operations {

template <UnivariateArbitraryModulusFormalPowerSeries FPS>
FPS dense_exp(const FPS &f, int precision) {
    using mint = typename FPS::value_type;
    assert(f.empty() || f[0] == mint(0));
    if (precision == -1) precision = static_cast<int>(f.size());

    FPS result{mint(1)};
    for (int d = 1; d < precision; d <<= 1) {
        result = result.dense_mul(f.pre(d << 1) + mint(1) - result.dense_log(d << 1)).pre(d << 1);
    }
    return result.pre(precision);
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_ARB_EXPONENTIAL_HPP
