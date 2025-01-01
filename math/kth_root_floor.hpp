#ifndef MATH_KTH_ROOT_FLOOR_HPP
#define MATH_KTH_ROOT_FLOOR_HPP 1

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>

namespace kk2 {

uint64_t kth_root_floor_inner(uint64_t a, int k) {
    if (a <= 1 || k == 1) return a;
    if (64 <= k) return 1;
    auto check = [&](uint64_t x) {
        uint64_t p = 1, q = x;
        for (int b = k; b;) {
            if (b & 1) {
                if (a / p < q) return false;
                p *= q;
            }
            if (b >>= 1) {
                if (a / q < q) return false;
                q *= q;
            }
        }
        return p <= a;
    };
    uint64_t x = std::pow(a, 1.0 / k);
    while (!check(x)) --x;
    while (check(x + 1)) ++x;
    return x;
}

// return floor(a ^ {1/k})
template <class return_type = uint64_t, class T, class U> return_type kth_root_floor(T a, U k) {
    return (return_type)kth_root_floor_inner((uint64_t)a, (int)k);
}

uint64_t kth_root_ceil_inner(uint64_t a, int k) {
    if (a <= 1 || k == 1) return a;
    if (64 <= k) return 2;
    auto check = [&](uint64_t x) {
        uint64_t p = 1, q = x;
        for (int b = k; b;) {
            if (b & 1) p *= q;
            if (b >>= 1) q *= q;
        }
        return p == a;
    };
    uint64_t x = kth_root_floor_inner(a, k);
    return check(x) ? x : x + 1;
}

// return ceil(a ^ {1/k})
template <class return_type = uint64_t, class T, class U> return_type kth_root_ceil(T a, U k) {
    return (return_type)kth_root_ceil_inner((uint64_t)a, (int)k);
}

} // namespace kk2

#endif // MATH_KTH_ROOT_FLOOR_HPP
