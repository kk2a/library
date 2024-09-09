#ifndef MOD_GARNER_HPP
#define MOD_GARNER_HPP 1

#include <vector>

#include "inv.hpp"

namespace kk2 {

long long garner(const std::vector<long long> &d,
                 const std::vector<long long> &p) {
    static int nm = d.size();
    std::vector<long long> kp(nm + 1, 0), rmult(nm + 1, 1);
    for (int ii = 0; ii < nm; ii++) {
        long long x =
            (d[ii] - kp[ii]) * mod_inversion(rmult[ii], p[ii]) % p[ii];
        if (x < 0) x += p[ii];
        for (int iii = ii + 1; iii < nm + 1; iii++) {
            kp[iii] = (kp[iii] + rmult[iii] * x) % p[iii];
            rmult[iii] = (rmult[iii] * p[ii]) % p[iii];
        }
    }
    return kp[nm];
}

} // namespace kk2

#endif // MOD_GARNER_HPP
