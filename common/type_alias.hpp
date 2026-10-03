#ifndef KK2_COMMON_TYPE_ALIAS_HPP
#define KK2_COMMON_TYPE_ALIAS_HPP 1

#include <cstddef>
#include <cstdint>

namespace kk2 {

using usize = std::size_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;
using i16 = std::int16_t;
using u16 = std::uint16_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;

#ifndef _MSC_VER
using i128 = __int128_t;
using u128 = __uint128_t;
#endif

} // namespace kk2

#endif // KK2_COMMON_TYPE_ALIAS_HPP
