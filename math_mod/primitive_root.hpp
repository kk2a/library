#ifndef MOD_PRIMITIVE_ROOT_EXPR_HPP
#define MOD_PRIMITIVE_ROOT_EXPR_HPP 1

#include "pow_mod.hpp"

namespace kk2 {

constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    if (m == 1107296257) return 10;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) { x /= i; }
        }
    }
    if (x > 1) { divs[cnt++] = x; }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod<long long>(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}

template <int m>
static constexpr int primitive_root = primitive_root_constexpr(m);

} // namespace kk2

#endif // MOD_PRIMITIVE_ROOT_EXPR_HPP
