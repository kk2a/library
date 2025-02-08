#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_TABLE_HPP
#define KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_TABLE_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

#include "../lpf_table.hpp"
#include "../pow.hpp"

namespace kk2 {

struct FamousFunctionTable {
  private:
    static inline std::vector<int> _v_lpf{0, 0}, _mobius{0, 1}, _sigma0{0, 1}, _euler_phi{0, 1};
    static inline std::vector<long long> _sigma1{0, 1};

  public:
    FamousFunctionTable() = delete;

    static void set_upper(int m) {
        if ((int)_mobius.size() > m) return;
        int start = _mobius.size();

        LPFTable::set_upper(m);

        _v_lpf.resize(m + 1, 0);
        _mobius.resize(m + 1, 1);
        _sigma0.resize(m + 1, 1);
        _sigma1.resize(m + 1, 1);
        _euler_phi.resize(m + 1, 1);

        for (int n = start; n <= m; ++n) {
            int p = LPFTable::lpf(n);
            if (p == n) {
                _v_lpf[n] = 1;
                _mobius[n] = -1;
                _sigma0[n] = 2;
                _sigma1[n] = p + 1;
                _euler_phi[n] = p - 1;
            } else {
                if (n / p % p == 0) _v_lpf[n] = _v_lpf[n / p] + 1;
                else _v_lpf[n] = 1;

                int p_pw = pow(p, _v_lpf[n]);
                int q = n / p_pw;
                if (q == 1) {
                    _mobius[n] = 0;
                    _sigma0[n] = _v_lpf[n] + 1;
                    _sigma1[n] = _sigma1[n / p] + p_pw;
                    _euler_phi[n] = p_pw - p_pw / p;
                } else {
                    _mobius[n] = _mobius[q] * _mobius[p_pw];
                    _sigma0[n] = _sigma0[q] * _sigma0[p_pw];
                    _sigma1[n] = _sigma1[q] * _sigma1[p_pw];
                    _euler_phi[n] = _euler_phi[q] * _euler_phi[p_pw];
                }
            }
        }
    }

    static int mobius(int n) {
        assert(n >= 0);
        if ((int)_mobius.size() <= n) set_upper(n);
        return _mobius[n];
    }

    static int sigma0(int n) {
        assert(n > 0);
        if ((int)_sigma0.size() <= n) set_upper(n);
        return _sigma0[n];
    }

    static long long sigma1(int n) {
        assert(n > 0);
        if ((int)_sigma1.size() <= n) set_upper(n);
        return _sigma1[n];
    }

    static int phi(int n) {
        assert(n > 0);
        if ((int)_euler_phi.size() <= n) set_upper(n);
        return _euler_phi[n];
    }
};

} // namespace kk2

#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_TABLE_HPP
