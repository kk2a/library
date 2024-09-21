#ifndef RANDOM_GEN_HPP
#define RANDOM_GEN_HPP 1

#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <vector>

#include "seed.hpp"

namespace kk2 {

namespace random {

using i64 = long long;
using u64 = unsigned long long;

u64 xorshift128plus(u64 &x, u64 &y) {
    u64 t = x;
    t ^= t << 23;
    t ^= t >> 17;
    t ^= y ^ (y >> 26);
    x = y;
    y = t;
    return x + y;
}

constexpr int iterations = 100;
void warm_up(u64 &x, u64 &y) {
    for (int i = 0; i < iterations; i++) xorshift128plus(x, y);
}

u64 rng() {
    static bool first = true;
    static u64 x = seed(), y = seed();
    if (first) {
        warm_up(x, y);
        first = false;
    }
    return xorshift128plus(x, y);
}

// [l, r)
i64 rng(i64 l, i64 r) {
    assert(l < r);
    return l + rng() % (r - l);
}

// [l, r)
std::vector<i64> distinct_rng(i64 l, i64 r, i64 n) {
    assert(l < r and n <= r - l);
    std::unordered_set<i64> st;
    for (i64 i = n; i; --i) {
        i64 m = rng(l, r + 1 - i);
        if (st.find(m) != st.end()) m = r - i;
        st.insert(m);
    }
    std::vector<i64> res(st.begin(), st.end());
    std::sort(res.begin(), res.end());
    return res;
}

} // namespace random

} // namespace kk2

#endif // RANDOM_GEN_HPP
