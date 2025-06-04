#ifndef KK2_MATH_MOD_BINOM_TABLE_HPP
#define KK2_MATH_MOD_BINOM_TABLE_HPP 1

#include <vector>

namespace kk2 {

template <class mint> struct BinomTable {
    static inline std::vector<std::vector<mint>> _binom{{1}};

    BinomTable() = delete;

    static void set_upper(int m) {
        int n = (int)_binom.size() - 1;
        if (n >= m) return;
        _binom.resize(m + 1);
        for (int i = n + 1; i <= m; i++) {
            _binom[i].resize(i + 1);
            _binom[i][0] = _binom[i][i] = 1;
            for (int j = 1; j < i; j++) _binom[i][j] = _binom[i - 1][j - 1] + _binom[i - 1][j];
        }
    }

    static mint binom(int n, int k) {
        if (k < 0 || k > n) return 0;
        if ((int)_binom.size() <= n) set_upper(n);
        return _binom[n][k];
    }
};

} // namespace kk2

#endif // KK2_MATH_MOD_BINOM_TABLE_HPP
