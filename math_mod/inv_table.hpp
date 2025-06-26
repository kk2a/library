#ifndef KK2_MATH_MOD_INV_TABLE_HPP
#define KK2_MATH_MOD_INV_TABLE_HPP 1

#include <vector>

namespace kk2 {

/**
 * @brief `[1, n]`のmod逆元を列挙するテーブル
 *
 * @tparam mint
 */
template <class mint> struct InvTable {
    static inline std::vector<mint> _invs{0, 1};
    static inline auto _mod = mint::getmod();
    InvTable() = delete;

    static void set_upper(int m) {
        if ((int)_invs.size() > m) return;
        int start = _invs.size();
        _invs.resize(m + 1);
        // p = q * i + r
        // - q / r = 1 / i (mod p)
        for (int i = start; i <= m; ++i) _invs[i] = (-_invs[_mod % i]) * (_mod / i);
    }

    static inline mint inv(int n) {
        bool neg = n < 0;
        if (neg) n = -n;
        if (n >= (int)_invs.size()) set_upper(n);
        return neg ? -_invs[n] : _invs[n];
    }
};

} // namespace kk2

#endif // KK2_MATH_MOD_INV_TABLE_HPP
