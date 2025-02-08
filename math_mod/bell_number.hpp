#ifndef KK2_MATH_MOD_BELL_NUMBER_HPP
#define KK2_MATH_MOD_BELL_NUMBER_HPP 1

#include <vector>

#include "comb.hpp"

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type>
std::vector<mint> enumerate_bell_number(int n) {
    FPS f(n + 1);
    f[0] = 0;
    kk2::Comb<mint>::set_upper(n);
    for (int i = 1; i <= n; ++i) f[i] = kk2::Comb<mint>::ifact(i);
    f = f.exp(n + 1);
    std::vector<mint> res(n + 1);
    for (int i = 0; i <= n; ++i) res[i] = f[i] * kk2::Comb<mint>::fact(i);
    return res;
}

} // namespace kk2

#endif // KK2_MATH_MOD_BELL_NUMBER_HPP
