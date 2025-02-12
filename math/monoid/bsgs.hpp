#ifndef KK2_MATH_MONOID_BSGS_HPP
#define KK2_MATH_MONOID_BSGS_HPP 1

#include <cmath>
#include <unordered_set>

#include "pow.hpp"

namespace kk2 {

// if there exists 0 <= l < n s.t. s^l = t, return min{0 <= l < n : s^l = t}
// otherwise, return -1
template <class M,
          M (*op)(M, M),
          M (*e)(),
          class S,
          S (*act)(M, S),
          class Set = std::unordered_set<S>>
long long bsgs(S s, S t, M x, long long n) {
    if (n <= 0) return -1;
    if (s == t) return 0;
    // ここは適当
    long long m = std::sqrt(n);
    Set set;
    S now = t;
    for (long long i = 0; i < m; i++) {
        now = act(x, now);
        set.insert(now);
    }
    M x_mth_pw = pow<M, op, e>(x, m);
    now = s;
    for (long long i = 0; i * m < n; i++) {
        S next = act(x_mth_pw, now);
        if (set.count(next)) {
            S tmp = now;
            for (long long j = 0; j < m; j++) {
                if (tmp == t) return i * m + j;
                if (j != m - 1) tmp = act(x, tmp);
            }
        }
        now = next;
    }
    return -1;
}

} // namespace kk2

#endif // KK2_MATH_MONOID_BSGS_HPP
