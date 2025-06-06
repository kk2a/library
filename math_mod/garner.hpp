#ifndef KK2_MATH_MOD_GARNER_HPP
#define KK2_MATH_MOD_GARNER_HPP 1

#include <cassert>
#include <vector>

#include "inv.hpp"

namespace kk2 {

template <class T> T garner(const std::vector<T> &d, const std::vector<T> &p) {
    assert(d.size() + 1 == p.size());
    int nm = d.size();
    std::vector<T> kp(nm + 1, 0), rmult(nm + 1, 1);
    for (int ii = 0; ii < nm; ii++) {
        long long x = (d[ii] - kp[ii]) * mod_inversion(rmult[ii], p[ii]) % p[ii];
        if (x < 0) x += p[ii];
        for (int iii = ii + 1; iii < nm + 1; iii++) {
            kp[iii] = (kp[iii] + rmult[iii] * x) % p[iii];
            rmult[iii] = (rmult[iii] * p[ii]) % p[iii];
        }
    }
    return kp[nm];
}

} // namespace kk2

#endif // KK2_MATH_MOD_GARNER_HPP
