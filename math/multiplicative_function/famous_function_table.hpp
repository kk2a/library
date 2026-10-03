#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_TABLE_HPP
#define KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_TABLE_HPP 1

#include <algorithm>
#include <vector>

#include "../../common/type_alias.hpp"
#include "../lpf_power_table.hpp"
#include "../lpf_table.hpp"
#include "../pow.hpp"

namespace kk2 {

struct FamousFunctionTable {
  private:
    static inline std::vector<i32> _mobius{0, 1};
    static inline std::vector<u32> _sigma0{0, 1}, _euler_phi{0, 1};
    static inline std::vector<u64> _sigma1{0, 1};

  public:
    FamousFunctionTable() = delete;

    static void set_upper(usize m) {
        if (_mobius.size() > m) return;
        usize start = _mobius.size();

        LPFTable::set_upper(m);
        LPFPowerTable::set_upper(m);

        _mobius.resize(m + 1, 1);
        _sigma0.resize(m + 1, 1);
        _sigma1.resize(m + 1, 1);
        _euler_phi.resize(m + 1, 1);

        for (usize n = start; n <= m; ++n) {
            const u32 value = static_cast<u32>(n);
            u32 p = LPFTable::lpf(value);
            if (p == value) {
                _mobius[n] = -1;
                _sigma0[n] = 2;
                _sigma1[n] = p + 1;
                _euler_phi[n] = p - 1;
            } else {
                u32 p_pw = LPFPowerTable::lpf_pow(value);
                usize q = n / p_pw;
                if (q == 1) {
                    _mobius[n] = 0;
                    _sigma0[n] = _sigma0[n / p] + 1;
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

    static i32 mobius(u32 n) {
        const usize index = static_cast<usize>(n);
        if (_mobius.size() <= index) set_upper(index);
        return _mobius[n];
    }

    static u32 sigma0(u32 n) {
        const usize index = static_cast<usize>(n);
        if (_sigma0.size() <= index) set_upper(index);
        return _sigma0[n];
    }

    static u64 sigma1(u32 n) {
        const usize index = static_cast<usize>(n);
        if (_sigma1.size() <= index) set_upper(index);
        return _sigma1[n];
    }

    static u32 euler_phi(u32 n) {
        const usize index = static_cast<usize>(n);
        if (_euler_phi.size() <= index) set_upper(index);
        return _euler_phi[n];
    }
};

} // namespace kk2

#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_TABLE_HPP
