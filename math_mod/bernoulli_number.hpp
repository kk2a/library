#ifndef KK2_MATH_MOD_BERNOULLI_NUMBER_HPP
#define KK2_MATH_MOD_BERNOULLI_NUMBER_HPP 1

#include <vector>

#include "comb.hpp"

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type>
std::vector<mint> enumerate_bernoulli_number(int n) {
    FPS f(n + 1);
    using comb = Comb<mint>;
    comb::set_upper(n + 1);
    for (int i = 0; i <= n; ++i) f[i] = comb::ifact(i + 1);
    f.inplace_inv(n + 1);
    std::vector<mint> res(n + 1);
    for (int i = 0; i <= n; ++i) res[i] = f[i] * comb::fact(i);
    return res;
}

} // namespace kk2

#endif // KK2_MATH_MOD_BERNOULLI_NUMBER_HPP
