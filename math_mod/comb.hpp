#ifndef KK2_MATH_MOD_COMB_HPP
#define KK2_MATH_MOD_COMB_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

#include "../type_traits/integral.hpp"

namespace kk2 {

template <class mint> struct Comb {
    static inline std::vector<mint> _fact{1}, _ifact{1}, _inv{1};

    Comb() = delete;

    static void set_upper(int m = -1) {
        int n = (int)_fact.size();
        if (m == -1) m = n << 1;
        if (n > m) return;
        m = std::min<int>(m, mint::getmod() - 1);
        _fact.resize(m + 1);
        _ifact.resize(m + 1);
        _inv.resize(m + 1);
        for (int i = n; i <= m; i++) _fact[i] = _fact[i - 1] * i;
        _ifact[m] = _fact[m].inv();
        _inv[m] = _ifact[m] * _fact[m - 1];
        for (int i = m; i > n; i--) {
            _ifact[i - 1] = _ifact[i] * i;
            _inv[i - 1] = _ifact[i - 1] * _fact[i - 2];
        }
    }

    static mint fact(int n) {
        if (n < 0) return 0;
        if ((int)_fact.size() <= n) set_upper(n);
        return _fact[n];
    }

    static mint ifact(int n) {
        if (n < 0) return 0;
        if ((int)_ifact.size() <= n) set_upper(n);
        return _ifact[n];
    }

    static mint inv(int n) {
        if (n < 0) return -inv(-n);
        if ((int)_inv.size() <= n) set_upper(n);
        return _inv[n];
    }

    static mint binom(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact(n) * ifact(k) * ifact(n - k);
    }

    template <class T> static mint multinomial(const std::vector<T> &r) {
        static_assert(is_integral<T>::value, "T must be integral");
        int n = 0;
        for (auto &x : r) {
            if (x < 0) return 0;
            n += x;
        }
        mint res = fact(n);
        for (auto &x : r) res *= ifact(x);
        return res;
    }

    static mint binom_naive(int n, int k) {
        if (n < 0 || k < 0 || k > n) return 0;
        mint res = 1;
        k = std::min(k, n - k);
        for (int i = 1; i <= k; i++) res *= inv(i) * (n--);
        return res;
    }

    static mint permu(int n, int k) {
        if (n < 0 || k < 0 || k > n) return 0;
        return fact(n) * ifact(n - k);
    }

    static mint homo(int n, int k) {
        if (n < 0 || k < 0) return 0;
        return k == 0 ? 1 : binom(n + k - 1, k);
    }
};

} // namespace kk2

#endif // KK2_MATH_MOD_COMB_HPP
