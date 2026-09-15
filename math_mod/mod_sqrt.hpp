#ifndef KK2_MATH_MOD_MOD_SQRT_HPP
#define KK2_MATH_MOD_MOD_SQRT_HPP 1

#include <cassert>

#include "../modint/mont_arb.hpp"
#include "detail/mod_sqrt.hpp"

namespace kk2 {

// ref: https://37zigen.com/tonelli-shanks-algorithm/
template <class T, class U> long long mod_sqrt(const T &a, const U &p) {
    assert(0 <= a && a < p);
    if (a < 2) return a;
    using Mint = ArbitraryLazyMontgomeryModInt<54105064>;
    Mint::setmod(p);
    return mod_sqrt_detail::mod_sqrt(Mint(a));
}

} // namespace kk2

#endif // KK2_MATH_MOD_MOD_SQRT_HPP
