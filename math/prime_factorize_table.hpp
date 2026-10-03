#ifndef KK2_MATH_PRIME_FACTORIZE_TABLE_HPP
#define KK2_MATH_PRIME_FACTORIZE_TABLE_HPP 1

#include <algorithm>
#include <vector>

#include "../common/type_alias.hpp"
#include "lpf_table.hpp"

namespace kk2 {

struct FactorizeTable {
  private:
    static inline std::vector<std::vector<std::pair<u32, u32>>> _factorize{{}};

  public:
    FactorizeTable() = delete;

    static void set_upper(usize m) {
        if (_factorize.size() > m) return;
        usize start = std::max<usize>(2, _factorize.size());

        LPFTable::set_upper(m);

        _factorize.resize(m + 1);
        for (usize n = start; n <= m; ++n) {
            const u32 value = static_cast<u32>(n);
            u32 p = LPFTable::lpf(value);
            if (p == value) {
                _factorize[n] = {
                    {p, 1}
                };
            } else if (n / p % p == 0) {
                _factorize[n] = _factorize[n / p];
                _factorize[n][0].second++;
            } else {
                _factorize[n] = _factorize[n / p];
                _factorize[n].insert(_factorize[n].begin(), {p, 1});
            }
        }
    }

    static const std::vector<std::pair<u32, u32>> &factorize(u32 n) {
        const usize index = static_cast<usize>(n);
        if (_factorize.size() <= index) set_upper(index);
        return _factorize[n];
    }

    static std::vector<u32> divisors(u32 n) {
        const usize index = static_cast<usize>(n);
        if (_factorize.size() <= index) set_upper(index);
        std::vector<u32> res = {1};
        for (auto [p, k] : _factorize[index]) {
            const usize sz = res.size();
            for (usize i = 0; i < sz; ++i) {
                u32 mul = 1;
                for (u32 j = 0; j < k; ++j) {
                    mul *= p;
                    res.push_back(res[i] * mul);
                }
            }
        }
        std::sort(res.begin(), res.end());
        return res;
    }
};

} // namespace kk2

#endif // KK2_MATH_PRIME_FACTORIZE_TABLE_HPP
