#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_ARBITRARY_TABLE_HPP
#define KK2_MATH_MULTIPLICATIVE_FUNCTION_ARBITRARY_TABLE_HPP 1

#include <cassert>
#include <vector>

#include "../lpf_table.hpp"
#include "../pow.hpp"

namespace kk2 {

template <class T, T (*f)(long long, long long)>
struct MultiplicativeFunctionTable {
  private:
    static inline std::vector<int> _v_lpf{0, 0};
    static inline std::vector<T> _table{0, 1};

  public:
    MultiplicativeFunctionTable() = delete;

    static void set_upper(int m) {
        if ((int)_table.size() > m) return;
        int start = _table.size();

        LPFTable::set_upper(m);

        _v_lpf.resize(m + 1, 0);
        _table.resize(m + 1);

        for (int n = start; n <= m; ++n) {
            int p = LPFTable::lpf(n);
            if (p == n) {
                _v_lpf[n] = 1;
                _table[n] = f(p, 1);
            } else {
                if (n / p % p == 0) _v_lpf[n] = _v_lpf[n / p] + 1;
                else _v_lpf[n] = 1;

                int p_pw = pow<int>(p, _v_lpf[n]);
                int q = n / p_pw;
                T p_pw_val = f(p, _v_lpf[n]);
                if (q == 1) {
                    _table[n] = p_pw_val;
                } else {
                    _table[n] = _table[q] * p_pw_val;
                }
            }
        }
    }

    static T val(int n) {
        assert(n > 0);
        if ((int)_table.size() <= n) set_upper(n);
        return _table[n];
    }
};

} // namespace kk2

#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_ARBITRARY_TABLE_HPP
