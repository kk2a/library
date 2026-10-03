#ifndef KK2_MATH_LPF_POWER_TABLE_HPP
#define KK2_MATH_LPF_POWER_TABLE_HPP 1

#include <cassert>
#include <vector>

#include "../common/type_alias.hpp"
#include "lpf_table.hpp"

namespace kk2 {

struct LPFPowerTable {
  private:
    static inline std::vector<u32> _lpf_pow{0, 1, 2}, _v_lpf{0, 1, 1};

  public:
    LPFPowerTable() = delete;

    static void set_upper(usize m) {
        if (_lpf_pow.size() > m) return;
        const usize start = _lpf_pow.size();

        LPFTable::set_upper(m);
        _lpf_pow.resize(m + 1);
        _v_lpf.resize(m + 1);

        for (usize n = start; n <= m; ++n) {
            const u32 value = static_cast<u32>(n);
            const u32 p = LPFTable::lpf(value);
            const usize quotient = n / p;
            if (quotient > 1 && LPFTable::lpf(static_cast<u32>(quotient)) == p) {
                _lpf_pow[n] = _lpf_pow[quotient] * p;
                _v_lpf[n] = _v_lpf[quotient] + 1;
            } else {
                _lpf_pow[n] = p;
                _v_lpf[n] = 1;
            }
        }
    }

    static u32 lpf_pow(u32 n) {
        assert(n > 1);
        const usize index = static_cast<usize>(n);
        if (_lpf_pow.size() <= index) set_upper(index);
        return _lpf_pow[index];
    }

    static u32 v_lpf(u32 n) {
        assert(n > 1);
        const usize index = static_cast<usize>(n);
        if (_v_lpf.size() <= index) set_upper(index);
        return _v_lpf[index];
    }
};

} // namespace kk2

#endif // KK2_MATH_LPF_POWER_TABLE_HPP
