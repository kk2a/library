#ifndef KK2_MATH_MOD_COMB_HPP
#define KK2_MATH_MOD_COMB_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

#include "../common/type_alias.hpp"
#include "../type_traits/integral.hpp"
#include "../type_traits/modint.hpp"
#include "inv_table.hpp"

namespace kk2 {

template <modint::Modular mint> struct Comb {
    static inline std::vector<mint> _fact{1}, _ifact{1};

    Comb() = delete;

  private:
    static void extend(usize m) {
        const usize n = _fact.size();
        m = std::min<usize>(m, mint::getmod() - 1);
        _fact.reserve(m + 1);
        _ifact.resize(m + 1);
        auto &_invs = InvTable<mint>::_invs;
        if (_invs.size() <= m) _invs.resize(m + 1);
        for (usize i = n; i <= m; i++) _fact.emplace_back(_fact.back() * i);
        _ifact[m] = _fact[m].inv();
        _invs[m] = _ifact[m] * _fact[m - 1];
        for (usize i = m; i > n; i--) {
            _ifact[i - 1] = _ifact[i] * i;
            _invs[i - 1] = _ifact[i - 1] * _fact[i - 2];
        }
    }

    static void ensure(usize n) {
        assert(n < mint::getmod());
        if (_fact.size() > n) return;
        extend(std::max<usize>(n, _fact.size() * 2));
    }

  public:
    static void set_upper(usize n) {
        ensure(std::min<usize>(n, static_cast<usize>(mint::getmod() - 1)));
    }

    static mint fact(u32 n) {
        ensure(static_cast<usize>(n));
        return _fact[n];
    }

    static mint ifact(u32 n) {
        ensure(static_cast<usize>(n));
        return _ifact[n];
    }

    static mint inv(i32 n) {
        assert(n != 0);
        return InvTable<mint>::inv(n);
    }

    static mint binom(u32 n, u32 k) {
        if (k > n) return 0;
        return fact(n) * ifact(k) * ifact(n - k);
    }

    template <UnsignedIntegral T> static mint multinomial(const std::vector<T> &r) {
        u64 n = 0;
        for (const T x : r) n += x;
        assert(n < mint::getmod());
        mint res = fact(static_cast<u32>(n));
        for (const T x : r) res *= ifact(static_cast<u32>(x));
        return res;
    }

    static mint binom_naive(u32 n, u32 k) {
        if (k > n) return 0;
        mint res = 1;
        k = std::min(k, n - k);
        for (u32 i = 1; i <= k; i++) res *= inv(i) * (n--);
        return res;
    }

    static mint permu(u32 n, u32 k) {
        if (k > n) return 0;
        return fact(n) * ifact(n - k);
    }

    static mint homo(u32 n, u32 k) { return k == 0 ? 1 : binom(n + k - 1, k); }
};

} // namespace kk2

#endif // KK2_MATH_MOD_COMB_HPP
