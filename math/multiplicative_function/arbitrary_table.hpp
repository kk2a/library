#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_ARBITRARY_TABLE_HPP
#define KK2_MATH_MULTIPLICATIVE_FUNCTION_ARBITRARY_TABLE_HPP 1

#include <vector>

#include "../../common/type_alias.hpp"
#include "../../type_traits/functional.hpp"
#include "../lpf_power_table.hpp"
#include "../lpf_table.hpp"
#include "../pow.hpp"

namespace kk2 {

template <class T, auto f>
    requires UnsignedTwoArgsFunctionPointer<decltype(f)> && requires(u32 p, u32 e) {
        { f(p, e) } -> std::convertible_to<T>;
    }
struct MultiplicativeFunctionTable {
  private:
    static inline std::vector<T> _table{0, 1};

  public:
    MultiplicativeFunctionTable() = delete;

    static void set_upper(usize m) {
        if (_table.size() > m) return;
        usize start = _table.size();

        LPFTable::set_upper(m);
        LPFPowerTable::set_upper(m);

        _table.resize(m + 1);

        for (usize n = start; n <= m; ++n) {
            const u32 value = static_cast<u32>(n);
            u32 p = LPFTable::lpf(value);
            if (p == value) {
                _table[n] = f(p, 1);
            } else {
                u32 p_pw = LPFPowerTable::lpf_pow(value);
                usize q = n / p_pw;
                if (q == 1) {
                    _table[n] = f(p, LPFPowerTable::v_lpf(value));
                } else {
                    _table[n] = _table[q] * _table[p_pw];
                }
            }
        }
    }

    static T val(u32 n) {
        const usize index = static_cast<usize>(n);
        if (_table.size() <= index) set_upper(index);
        return _table[n];
    }
};

} // namespace kk2

#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_ARBITRARY_TABLE_HPP
