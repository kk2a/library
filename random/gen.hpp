#ifndef KK2_RANDOM_GEN_HPP
#define KK2_RANDOM_GEN_HPP 1

#include <algorithm>
#include <cassert>
#include <numeric>
#include <random>
#include <unordered_set>
#include <vector>

#include "seed.hpp"

namespace kk2 {

namespace random {

using i64 = long long;
using u64 = unsigned long long;

inline u64 rng() {
    static std::mt19937_64 mt(kk2::random::seed());
    return mt();
}

// [l, r)
inline i64 rng(i64 l, i64 r) {
    assert(l < r);
    return l + rng() % (r - l);
}

// [l, r)
template <class T> std::vector<T> random_vector(int n, T l, T r) {
    std::vector<T> res(n);
    for (int i = 0; i < n; i++) res[i] = rng(l, r);
    return res;
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

template <class Iter> void shuffle(Iter first, Iter last) {
    if (first == last) return;
    int len = 1;
    for (auto it = first + 1; it != last; ++it) {
        len++;
        int j = rng(0, len);
        if (j != len - 1) std::iter_swap(first + j, it);
    }
}

template <class T> std::vector<T> perm(int n) {
    std::vector<T> res(n);
    std::iota(res.begin(), res.end(), T(0));
    shuffle(res.begin(), res.end());
    return res;
}

template <class T> std::vector<T> choices(int l, int r, int k) {
    assert(l < r and k <= r - l);
    std::vector<T> res(r - l);
    std::iota(res.begin(), res.end(), T(l));
    shuffle(res.begin(), res.end());
    res.resize(k);
    return res;
}

} // namespace random

} // namespace kk2

#endif // KK2_RANDOM_GEN_HPP
