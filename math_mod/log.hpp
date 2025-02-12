#ifndef KK2_MATH_MOD_LOG_HPP
#define KK2_MATH_MOD_LOG_HPP 1

#include <cmath>
#include <unordered_set>

namespace kk2 {

// if there exists 0 <= l < n s.t. x^l = t, return min{0 <= l < n : x^l = t}
// otherwise, return -1
template <class mint, class HashSet=std::unordered_set<long long>>
long long discrete_logarithm(mint x, mint t) {
    if (t == mint(1)) return 0;
    HashSet set;
    long long m = std::sqrt(mint::getmod());
    mint now = t;
    for (long long i = 0; i < m; i++) {
        now *= x;
        set.insert(now.val());
    }
    mint x_mth_pw = x.pow(m);
    now = 1;
    for (long long i = 0; i * m < mint::getmod(); i++) {
        mint next = now * x_mth_pw;
        if (set.count(next.val())) {
            mint tmp = now;
            for (long long j = 0; j < m; j++) {
                if (tmp == t) return i * m + j;
                if (j != m - 1) tmp *= x;
            }
        }
        now = next;
    }
    return -1;
}

}

#endif // KK2_MATH_MOD_LOG_HPP
