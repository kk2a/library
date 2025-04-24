#ifndef KK2_BIGINT_INT256_HPP
#define KK2_BIGINT_INT256_HPP 1

#include <cstdint>
#include <string>

#include "../type_traits/integral.hpp"
#include "../type_traits/io.hpp"

namespace kk2 {

namespace bigint {

struct uint256 {
    using u64 = uint64_t;
    using u128 = __uint128_t;
    using u256 = uint256;

    constexpr uint256() { _v[0] = _v[1] = 0; }
    template <class T, is_integral_t<T> * = nullptr> constexpr uint256(T x) {
        _v[0] = x, _v[1] = 0;
    }

    constexpr uint256 &operator+=(const uint256 &r) {
        _v[1] += r._v[1];
        bool a = _v[0] >> 127;
        bool b = r._v[0] >> 127;
        _v[0] = ((_v[0] << 1) >> 1) + ((r._v[0] << 1) >> 1);
        bool c = _v[0] >> 127;
        if ((a and b) or (b and c) or (c and a)) ++_v[1];
        _v[0] = _v[0] ^ (u128(a) << 127) ^ (u128(b) << 127);
        return *this;
    }

  private:
    u128 _v[2];
};

} // namespace bigint

using u256 = bigint::uint256;

} // namespace kk2


#endif // KK2_BIGINT_INT256_HPP
