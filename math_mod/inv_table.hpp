#ifndef KK2_MATH_MOD_INV_TABLE_HPP
#define KK2_MATH_MOD_INV_TABLE_HPP 1

#include <type_traits>
#include <vector>

#include "../common/type_alias.hpp"
#include "../type_traits/integral.hpp"

namespace kk2 {

/**
 * @brief `[1, n]`のmod逆元を列挙するテーブル
 *
 * @tparam mint
 */
template <class mint> struct InvTable {
    static inline std::vector<mint> _invs{0, 1};
    InvTable() = delete;

    static void set_upper(usize m) {
        if (_invs.size() > m) return;
        using index_type = std::make_unsigned_t<std::remove_cv_t<decltype(mint::getmod())>>;
        const index_type start = static_cast<index_type>(_invs.size());
        const index_type upper = static_cast<index_type>(m);
        const index_type mod = static_cast<index_type>(mint::getmod());
        _invs.resize(m + 1);
        // p = q * i + r
        // - q / r = 1 / i (mod p)
        for (index_type i = start; i <= upper; ++i) _invs[i] = (-_invs[mod % i]) * (mod / i);
    }

    template <UnsignedIntegral T> static inline mint inv(T n) {
        const usize index = static_cast<usize>(n);
        if (index >= _invs.size()) set_upper(index);
        return _invs[index];
    }

    template <SignedIntegral T> static inline mint inv(T n) {
        using U = std::make_unsigned_t<T>;
        if (n < 0) {
            // n + 1 is representable even when n is the minimum value.
            const U magnitude = static_cast<U>(-(n + 1)) + U(1);
            return -inv(magnitude);
        }
        return inv(static_cast<U>(n));
    }

    static inline mint inv_unchecked(usize n) { return _invs[n]; }
};

} // namespace kk2

#endif // KK2_MATH_MOD_INV_TABLE_HPP
