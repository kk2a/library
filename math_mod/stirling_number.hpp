#ifndef KK2_MATH_MOD_STIRLING_NUMBER_HPP
#define KK2_MATH_MOD_STIRLING_NUMBER_HPP 1

#include <vector>

#include "../fps/product.hpp"

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type>
std::vector<mint> enumerate_stirling_number_of_the_first_kind(int n) {
    std::vector<FPS> a(n);
    for (int i = 0; i < n; ++i) { a[i] = FPS{-i, 1}; }
    return all_prod(a);
}

} // namespace kk2

#endif // KK2_MATH_MOD_STIRLING_NUMBER_HPP
