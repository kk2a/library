#ifndef KK2_MATH_PRIME_FACTORIZE_TABLE_HPP
#define KK2_MATH_PRIME_FACTORIZE_TABLE_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

#include "lpf_table.hpp"

namespace kk2 {

struct FactorizeTable {
  private:
    static inline std::vector<std::vector<std::pair<int, int>>> _factorize{{}};

  public:
    FactorizeTable() = delete;

    static void set_upper(int m) {
        if ((int)_factorize.size() > m) return;
        int start = std::max<int>(2, _factorize.size());

        LPFTable::set_upper(m);

        _factorize.resize(m + 1);
        for (int n = start; n <= m; ++n) {
            int p = LPFTable::lpf(n);
            if (p == n) {
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

    static const std::vector<std::pair<int, int>> &factorize(int n) {
        assert(n > 0);
        if ((int)_factorize.size() <= n) set_upper(n);
        return _factorize[n];
    }

    static std::vector<int> divisors(int n) {
        assert(n > 0);
        if ((int)_factorize.size() <= n) set_upper(n);
        std::vector<int> res = {1};
        for (auto [p, k] : _factorize[n]) {
            int sz = res.size();
            for (int i = 0; i < sz; ++i) {
                int mul = 1;
                for (int j = 0; j < k; ++j) {
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
