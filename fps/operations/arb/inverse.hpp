#ifndef KK2_FPS_OPERATIONS_ARB_INVERSE_HPP
#define KK2_FPS_OPERATIONS_ARB_INVERSE_HPP 1

#include <cassert>

#include "../../../type_traits/fps.hpp"
#include "../inverse.hpp"

namespace kk2::fps::operations {

template <ArbitraryModulusFormalPowerSeries FPS> FPS dense_inv(const FPS &f, int deg) {
    using mint = typename FPS::value_type;
    assert(!f.empty() && f[0] != mint(0));
    if (deg == -1) deg = static_cast<int>(f.size());
    if (deg == 0) return {};

    FPS result{f[0].inv()};
    for (int d = 1; d < deg; d <<= 1) {
        result = (result + result - f.pre(d << 1).dense_mul(result.dense_mul(result))).pre(d << 1);
    }
    return result.pre(deg);
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_ARB_INVERSE_HPP
