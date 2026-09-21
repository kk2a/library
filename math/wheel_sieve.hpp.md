---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: bitcount.hpp
      icon: LIBRARY_ALL_AC
      path: bit/bitcount.hpp
    - filename: my_bitset.hpp
      icon: LIBRARY_ALL_AC
      path: data_structure/my_bitset.hpp
    - filename: enumerate_quotients.hpp
      icon: LIBRARY_ALL_AC
      path: math/enumerate_quotients.hpp
    - filename: frac_floor.hpp
      icon: LIBRARY_ALL_AC
      path: math/frac_floor.hpp
    - filename: prime_counting.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/prime_counting.hpp
    - filename: sqrt_floor.hpp
      icon: LIBRARY_ALL_AC
      path: math/sqrt_floor.hpp
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: wheel_sieve.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/wheel_sieve.test.cpp
    type: Verified with
  dependsOn:
  - bit/bitcount.hpp
  - data_structure/my_bitset.hpp
  - math/enumerate_quotients.hpp
  - math/frac_floor.hpp
  - math/multiplicative_function/prime_counting.hpp
  - math/sqrt_floor.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_MATH_WHEEL_SIEVE_HPP\n#define KK2_MATH_WHEEL_SIEVE_HPP 1\n\n\
      #include <algorithm>\n#include <array>\n#include <cstdint>\n#include <vector>\n\
      \n#include \"multiplicative_function/prime_counting.hpp\"\n#include \"sqrt_floor.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace number_theory {\n\ninline std::vector<int>\
      \ wheel_sieve(int n) {\n    constexpr std::array<int, 10> seed_primes{2, 3,\
      \ 5, 7, 11, 13, 17, 19, 23, 29};\n    if (n < 30) {\n        return std::vector<int>(seed_primes.begin(),\n\
      \                                std::upper_bound(seed_primes.begin(), seed_primes.end(),\
      \ n));\n    }\n\n    int sqrt_n = sqrt_floor(n);\n    int w = 1;\n    std::vector<bool>\
      \ iscoprime(sqrt_n, true);\n    int wheel_prime_count = 0;\n    while (wheel_prime_count\
      \ < 9 && w * seed_primes[wheel_prime_count] <= sqrt_n) {\n        w *= seed_primes[wheel_prime_count];\n\
      \        for (int j = seed_primes[wheel_prime_count]; j < sqrt_n;\n        \
      \     j += seed_primes[wheel_prime_count]) {\n            iscoprime[j] = false;\n\
      \        }\n        ++wheel_prime_count;\n    }\n\n    std::vector<int> idx_(w,\
      \ -1);\n    int s = 0;\n    for (int i = 1; i < w; ++i) {\n        if (iscoprime[i])\
      \ idx_[i] = s++;\n    }\n    std::vector<int> coprimes(s);\n    for (int i =\
      \ 1; i < w; ++i) {\n        if (idx_[i] != -1) coprimes[idx_[i]] = i;\n    }\n\
      \n    auto idx = [&](long long x) -> long long {\n        if (idx_[x % w] ==\
      \ -1) return -1;\n        return x / w * s + idx_[x % w];\n    };\n    auto\
      \ val = [&](int i) {\n        return i / s * w + coprimes[i % s];\n    };\n\n\
      \    int candidate_count = (n + w - 1) / w * s;\n    while (candidate_count\
      \ > 1 && val(candidate_count - 1) > n) --candidate_count;\n\n    std::vector<int>\
      \ primes;\n    primes.reserve(prime_counting(n));\n    for (int i = 0; i < wheel_prime_count;\
      \ ++i) primes.push_back(seed_primes[i]);\n\n    // A composite number not exceeding\
      \ an int has a prime factor below 2^16.\n    std::vector<std::uint16_t> lpf(candidate_count,\
      \ 0);\n    for (int i = 1; i < candidate_count; ++i) {\n        int v = val(i);\n\
      \        int least_prime = lpf[i] == 0 ? v : lpf[i];\n        if (lpf[i] ==\
      \ 0) primes.push_back(v);\n\n        for (int j = wheel_prime_count; j < (int)primes.size();\
      \ ++j) {\n            int p = primes[j];\n            long long index = idx(1LL\
      \ * p * v);\n            if (index >= candidate_count) break;\n            if\
      \ (least_prime < p) break;\n            lpf[index] = static_cast<std::uint16_t>(p);\n\
      \        }\n    }\n    return primes;\n}\n\n} // namespace number_theory\n\n\
      using number_theory::wheel_sieve;\n\n} // namespace kk2\n\n#endif // KK2_MATH_WHEEL_SIEVE_HPP\n"
    name: default
  - code: "#line 1 \"math/wheel_sieve.hpp\"\n\n\n\n#include <algorithm>\n#include\
      \ <array>\n#include <cstdint>\n#include <vector>\n\n#line 1 \"math/multiplicative_function/prime_counting.hpp\"\
      \n\n\n\n#line 5 \"math/multiplicative_function/prime_counting.hpp\"\n\n#line\
      \ 1 \"data_structure/my_bitset.hpp\"\n\n\n\n#line 5 \"data_structure/my_bitset.hpp\"\
      \n#include <bit>\n#include <bitset>\n#include <cassert>\n#line 9 \"data_structure/my_bitset.hpp\"\
      \n#include <iostream>\n#include <iterator>\n#include <string>\n#include <utility>\n\
      #line 14 \"data_structure/my_bitset.hpp\"\n\n#line 1 \"bit/bitcount.hpp\"\n\n\
      \n\n#line 5 \"bit/bitcount.hpp\"\n\n#line 1 \"type_traits/integral.hpp\"\n\n\
      \n\n#include <type_traits>\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate\
      \ <typename T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T,\
      \ __int128_t>::value\n                                                     \
      \  or std::is_same<T, __int128>::value,\n                                  \
      \                 std::true_type,\n                                        \
      \           std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_int128\
      \ =\n    typename std::conditional<std::is_same<T, __uint128_t>::value\n   \
      \                               or std::is_same<T, unsigned __int128>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T>\nusing is_integral =\n\
      \    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
      \                                  or is_unsigned_int128<T>::value,\n      \
      \                        std::true_type,\n                              std::false_type>::type;\n\
      \ntemplate <typename T>\nusing is_signed = typename std::conditional<std::is_signed<T>::value\
      \ or is_signed_int128<T>::value,\n                                         \
      \   std::true_type,\n                                            std::false_type>::type;\n\
      \ntemplate <typename T>\nusing is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
      \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename\
      \ T>\nusing to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
      \                              make_unsigned_int128<T>,\n                  \
      \            typename std::conditional<std::is_signed<T>::value,\n         \
      \                                               std::make_unsigned<T>,\n   \
      \                                                     std::common_type<T>>::type>::type;\n\
      \n#else\n\ntemplate <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
      template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
      template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
      template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
      \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
      template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
      template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
      \ntemplate <class T>\nconcept Integral = is_integral<std::remove_cv_t<T>>::value;\n\
      \ntemplate <class T>\nconcept SignedIntegral = is_signed<std::remove_cv_t<T>>::value;\n\
      \ntemplate <class T>\nconcept UnsignedIntegral = is_unsigned<std::remove_cv_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 7 \"bit/bitcount.hpp\"\n\nnamespace kk2 {\n\n\
      template <Integral T> constexpr int ctz(T x) {\n    assert(x != T(0));\n\n \
      \   if constexpr (sizeof(T) <= 4) {\n        return __builtin_ctz(x);\n    }\
      \ else if constexpr (sizeof(T) <= 8) {\n        return __builtin_ctzll(x);\n\
      \    } else {\n        if (x & 0xffffffffffffffff)\n            return __builtin_ctzll((unsigned\
      \ long long)(x & 0xffffffffffffffff));\n        return 64 + __builtin_ctzll((unsigned\
      \ long long)(x >> 64));\n    }\n}\n\ntemplate <Integral T> constexpr int lsb(T\
      \ x) {\n    assert(x != T(0));\n\n    return ctz(x);\n}\n\ntemplate <Integral\
      \ T> constexpr int clz(T x) {\n    assert(x != T(0));\n\n    if constexpr (sizeof(T)\
      \ <= 4) {\n        return __builtin_clz(x);\n    } else if constexpr (sizeof(T)\
      \ <= 8) {\n        return __builtin_clzll(x);\n    } else {\n        if (x >>\
      \ 64) return __builtin_clzll((unsigned long long)(x >> 64));\n        return\
      \ 64 + __builtin_clzll((unsigned long long)(x & 0xffffffffffffffff));\n    }\n\
      }\n\ntemplate <Integral T> constexpr int msb(T x) {\n    assert(x != T(0));\n\
      \n    return sizeof(T) * 8 - 1 - clz(x);\n}\n\ntemplate <Integral T> constexpr\
      \ int popcount(T x) {\n\n    if constexpr (sizeof(T) <= 4) {\n        return\
      \ __builtin_popcount(x);\n    } else if constexpr (sizeof(T) <= 8) {\n     \
      \   return __builtin_popcountll(x);\n    } else {\n        return __builtin_popcountll((unsigned\
      \ long long)(x >> 64))\n               + __builtin_popcountll((unsigned long\
      \ long)(x & 0xffffffffffffffff));\n    }\n}\n\n}; // namespace kk2\n\n\n#line\
      \ 1 \"type_traits/io.hpp\"\n\n\n\n#include <concepts>\n#include <fstream>\n\
      #include <istream>\n#include <ostream>\n#line 9 \"type_traits/io.hpp\"\n\nnamespace\
      \ kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag\
      \ {};\n\n} // namespace type_traits\n\ntemplate <typename T>\nusing is_standard_istream\
      \ = typename std::conditional<std::is_same<T, std::istream>::value\n       \
      \                                                   || std::is_same<T, std::ifstream>::value,\n\
      \                                                      std::true_type,\n   \
      \                                                   std::false_type>::type;\n\
      template <typename T>\nusing is_standard_ostream = typename std::conditional<std::is_same<T,\
      \ std::ostream>::value\n                                                   \
      \       || std::is_same<T, std::ofstream>::value,\n                        \
      \                              std::true_type,\n                           \
      \                           std::false_type>::type;\ntemplate <typename T> using\
      \ is_user_defined_istream = std::is_base_of<type_traits::istream_tag, T>;\n\
      template <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
      \ T>;\n\ntemplate <typename T>\nusing is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
      \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
      \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate\
      \ <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\
      \ntemplate <class T>\nconcept StandardInputStream = is_standard_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept StandardOutputStream = is_standard_ostream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept InputStream = is_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept OutputStream = is_ostream<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 17 \"data_structure/my_bitset.hpp\"\n\nnamespace\
      \ kk2 {\n\ntemplate <class Accessor> struct MonotoneRankRange {\n    Accessor\
      \ _accessor;\n\n    struct StrideRange {\n        Accessor _accessor;\n    \
      \    int _start, _end, _step;\n\n        struct Iterator {\n            using\
      \ value_type = int;\n            using difference_type = std::ptrdiff_t;\n \
      \           using iterator_category = std::forward_iterator_tag;\n         \
      \   using reference = int;\n            using pointer = void;\n\n          \
      \  int rank, end, step;\n            mutable typename Accessor::MonotoneCursor\
      \ cursor;\n\n            Iterator(int rank_, int end_, int step_, const Accessor\
      \ &accessor)\n                : rank(rank_),\n                  end(end_),\n\
      \                  step(step_),\n                  cursor(accessor.monotone_cursor())\
      \ {}\n\n            int operator*() const { return cursor[rank]; }\n\n     \
      \       Iterator &operator++() {\n                rank = step < end - rank ?\
      \ rank + step : end;\n                return *this;\n            }\n\n     \
      \       Iterator operator++(int) {\n                Iterator result = *this;\n\
      \                ++*this;\n                return result;\n            }\n\n\
      \            bool operator==(const Iterator &other) const { return rank == other.rank;\
      \ }\n        };\n\n        Iterator begin() const { return Iterator(_start,\
      \ _end, _step, _accessor); }\n        Iterator end() const { return Iterator(_end,\
      \ _end, _step, _accessor); }\n\n        int size() const {\n            if (_start\
      \ == _end) return 0;\n            return (_end - _start - 1) / _step + 1;\n\
      \        }\n\n        std::vector<int> to_vec() const {\n            std::vector<int>\
      \ result;\n            result.reserve(size());\n            for (int value :\
      \ *this) result.push_back(value);\n            return result;\n        }\n \
      \   };\n\n    auto begin() const { return stride(0, 1).begin(); }\n    auto\
      \ end() const { return stride(0, 1).end(); }\n    int size() const { return\
      \ _accessor.size(); }\n\n    int operator[](int rank) const { return _accessor[rank];\
      \ }\n\n    auto monotone_cursor() const { return _accessor.monotone_cursor();\
      \ }\n\n    StrideRange stride(int start, int step) const { return stride(start,\
      \ step, size()); }\n\n    StrideRange stride(int start, int step, int end) const\
      \ {\n        assert(0 <= start && start <= end && end <= size() && step > 0);\n\
      \        return StrideRange{_accessor, start, end, step};\n    }\n\n    std::vector<int>\
      \ to_vec() const {\n        std::vector<int> result;\n        result.reserve(size());\n\
      \        for (int value : *this) result.push_back(value);\n        return result;\n\
      \    }\n};\n\nstruct DynamicBitSet {\n    struct RankSelect;\n\n    using T\
      \ = DynamicBitSet;\n    using UInt = std::uint64_t;\n    constexpr static int\
      \ BLOCK_SIZE = sizeof(UInt) * 8;\n    constexpr static int BLOCK_SIZE_LOG =\
      \ __builtin_ctz(BLOCK_SIZE);\n    constexpr static int BLOCK_MASK = BLOCK_SIZE\
      \ - 1;\n    constexpr static UInt ONE = 1;\n    int n;\n    std::vector<UInt>\
      \ block;\n\n    DynamicBitSet(int n_ = 0, bool x = 0) : n(n_) {\n        UInt\
      \ val = x ? -1 : 0;\n        block.assign((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG,\
      \ val);\n        if (n & BLOCK_MASK) block.back() >>= BLOCK_SIZE - (n & BLOCK_MASK);\n\
      \        // fit the last block\n    }\n\n    DynamicBitSet(const std::string\
      \ &s) : n(s.size()) {\n        block.resize((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n\
      \        set(s);\n    }\n\n    inline int size() const { return n; }\n\n   \
      \ int word_count() const { return block.size(); }\n\n    UInt &word(int i) {\n\
      \        assert(0 <= i && i < word_count());\n        return block[i];\n   \
      \ }\n\n    const UInt &word(int i) const {\n        assert(0 <= i && i < word_count());\n\
      \        return block[i];\n    }\n\n    UInt *data() { return block.data();\
      \ }\n\n    const UInt *data() const { return block.data(); }\n\n    T &clear_unused_bits()\
      \ {\n        if ((n & BLOCK_MASK) && !block.empty()) block.back() &= (ONE <<\
      \ (n & BLOCK_MASK)) - 1;\n        return *this;\n    }\n\n    T &inplace_combine_top(const\
      \ T &rhs) {\n        if (this == &rhs) {\n            T copy = rhs;\n      \
      \      return inplace_combine_top(copy);\n        }\n        int old_n = n;\n\
      \        n += rhs.n;\n        block.resize((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n\
      \        int offset = old_n & BLOCK_MASK;\n        int word_offset = old_n >>\
      \ BLOCK_SIZE_LOG;\n        if (offset == 0) {\n            std::copy(rhs.block.begin(),\
      \ rhs.block.end(), block.begin() + word_offset);\n        } else {\n       \
      \     for (int i = 0; i < rhs.word_count(); ++i) {\n                block[word_offset\
      \ + i] |= rhs.block[i] << offset;\n                if (word_offset + i + 1 <\
      \ word_count()) {\n                    block[word_offset + i + 1] = rhs.block[i]\
      \ >> (BLOCK_SIZE - offset);\n                }\n            }\n        }\n \
      \       return *this;\n    }\n\n    T combine_top(const T &rhs) const { return\
      \ T(*this).inplace_combine_top(rhs); }\n\n    T &inplace_combine_bottom(const\
      \ T &rhs) {\n        T result = rhs;\n        result.inplace_combine_top(*this);\n\
      \        *this = std::move(result);\n        return *this;\n    }\n\n    T combine_bottom(const\
      \ T &rhs) const { return T(*this).inplace_combine_bottom(rhs); }\n\n    void\
      \ set(int i, bool x = true) {\n        assert(0 <= i && i < n);\n        if\
      \ (x) block[i >> BLOCK_SIZE_LOG] |= ONE << (i & BLOCK_MASK);\n        else block[i\
      \ >> BLOCK_SIZE_LOG] &= ~(ONE << (i & BLOCK_MASK));\n    }\n\n    void reset(int\
      \ i) { set(i, false); }\n\n    T &set_all(bool x = true) {\n        std::fill(block.begin(),\
      \ block.end(), x ? ~UInt(0) : UInt(0));\n        if (x && (n & BLOCK_MASK))\
      \ block.back() &= (ONE << (n & BLOCK_MASK)) - 1;\n        return *this;\n  \
      \  }\n\n    T &reset_all() { return set_all(false); }\n\n    void set(const\
      \ std::string &s) {\n        assert((int)s.size() == n);\n        for (int i\
      \ = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n            int r\
      \ = n - (i << BLOCK_SIZE_LOG), l = std::max(0, r - BLOCK_SIZE);\n          \
      \  block[i] = 0;\n            for (int j = l; j < r; j++) block[i] = (block[i]\
      \ << 1) | (s[j] - '0');\n        }\n    }\n\n    void set_reversed(const std::string\
      \ &s) {\n        assert((int)s.size() == n);\n        for (int i = 0; i < (n\
      \ + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n            int l = i << BLOCK_SIZE_LOG,\
      \ r = std::min(n, l + BLOCK_SIZE);\n            block[i] = 0;\n            for\
      \ (int j = r - 1; j >= l; --j) block[i] = (block[i] << 1) | (s[j] - '0');\n\
      \        }\n    }\n\n    struct BitReference {\n        std::vector<UInt> &block;\n\
      \        int idx;\n\n      public:\n        BitReference(std::vector<UInt> &block_,\
      \ int idx_) : block(block_), idx(idx_) {}\n\n        operator bool() const {\
      \ return (block[idx >> BLOCK_SIZE_LOG] >> (idx & BLOCK_MASK)) & 1; }\n\n   \
      \     template <InputStream IStream> friend IStream &operator>>(IStream &is,\
      \ BitReference a) {\n            bool c;\n            is >> c;\n           \
      \ a = c;\n            return is;\n        }\n\n        BitReference &operator=(bool\
      \ x) {\n            if (x) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);\n\
      \            else block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));\n\
      \            return *this;\n        }\n\n        BitReference &operator=(const\
      \ BitReference &other) {\n            if (other) block[idx >> BLOCK_SIZE_LOG]\
      \ |= ONE << (idx & BLOCK_MASK);\n            else block[idx >> BLOCK_SIZE_LOG]\
      \ &= ~(ONE << (idx & BLOCK_MASK));\n            return *this;\n        }\n\n\
      \        BitReference &operator&=(bool x) {\n            if (!x) block[idx >>\
      \ BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));\n            return *this;\n\
      \        }\n\n        BitReference &operator&=(const BitReference &other) {\n\
      \            if (!other) block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));\n\
      \            return *this;\n        }\n\n        BitReference &operator|=(bool\
      \ x) {\n            if (x) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);\n\
      \            return *this;\n        }\n\n        BitReference &operator|=(const\
      \ BitReference &other) {\n            if (other) block[idx >> BLOCK_SIZE_LOG]\
      \ |= ONE << (idx & BLOCK_MASK);\n            return *this;\n        }\n\n  \
      \      BitReference &operator^=(bool x) {\n            if (x) block[idx >> BLOCK_SIZE_LOG]\
      \ ^= ONE << (idx & BLOCK_MASK);\n            return *this;\n        }\n\n  \
      \      BitReference &operator^=(const BitReference &other) {\n            if\
      \ (other) block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);\n     \
      \       return *this;\n        }\n\n        BitReference &flip() {\n       \
      \     block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);\n         \
      \   return *this;\n        }\n\n        BitReference &operator~() {\n      \
      \      block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);\n        \
      \    return *this;\n        }\n\n        bool val() const { return (block[idx\
      \ >> BLOCK_SIZE_LOG] >> (idx & BLOCK_MASK)) & 1; }\n    };\n\n    BitReference\
      \ operator[](int i) {\n        assert(0 <= i && i < n);\n        return BitReference(block,\
      \ i);\n    }\n\n    bool operator[](int i) const {\n        assert(0 <= i &&\
      \ i < n);\n        return (block[i >> BLOCK_SIZE_LOG] >> (i & BLOCK_MASK)) &\
      \ 1;\n    }\n\n    bool is_pinned(int i) const {\n        assert(0 <= i && i\
      \ < n);\n        return (block[i >> BLOCK_SIZE_LOG] >> (i & BLOCK_MASK)) & 1;\n\
      \    }\n\n    T &operator=(const std::string &s) {\n        set(s);\n      \
      \  return *this;\n    }\n\n    T &flip() {\n        for (UInt &x : block) x\
      \ = ~x;\n        if (n & BLOCK_MASK) block.back() &= (ONE << (n & BLOCK_MASK))\
      \ - 1;\n        return *this;\n    }\n\n    T &flip(int i) {\n        assert(0\
      \ <= i && i < n);\n        block[i >> BLOCK_SIZE_LOG] ^= ONE << (i & BLOCK_MASK);\n\
      \        return *this;\n    }\n\n    int ctz() const { return find_next(0);\
      \ }\n\n    int clz() const {\n        int last = find_prev(n - 1);\n       \
      \ return last == -1 ? n : n - 1 - last;\n    }\n\n    int find_next(int i) const\
      \ {\n        if (i < 0) i = 0;\n        if (i >= n) return n;\n        int j\
      \ = i >> BLOCK_SIZE_LOG;\n        UInt bits = block[j] & (~UInt(0) << (i & BLOCK_MASK));\n\
      \        while (true) {\n            if (bits) return std::min(n, j * BLOCK_SIZE\
      \ + (int)std::countr_zero(bits));\n            if (++j == word_count()) return\
      \ n;\n            bits = block[j];\n        }\n    }\n\n    int find_next_zero(int\
      \ i) const {\n        if (i < 0) i = 0;\n        if (i >= n) return n;\n   \
      \     int j = i >> BLOCK_SIZE_LOG;\n        UInt bits = ~block[j] & (~UInt(0)\
      \ << (i & BLOCK_MASK));\n        while (true) {\n            if (bits) return\
      \ std::min(n, j * BLOCK_SIZE + (int)std::countr_zero(bits));\n            if\
      \ (++j == word_count()) return n;\n            bits = ~block[j];\n        }\n\
      \    }\n\n    int find_prev(int i) const {\n        if (i >= n) i = n - 1;\n\
      \        if (i < 0) return -1;\n        int j = i >> BLOCK_SIZE_LOG;\n     \
      \   int offset = i & BLOCK_MASK;\n        UInt bits = block[j] & (~UInt(0) >>\
      \ (BLOCK_MASK - offset));\n        while (true) {\n            if (bits) return\
      \ j * BLOCK_SIZE + (BLOCK_MASK - std::countl_zero(bits));\n            if (j--\
      \ == 0) return -1;\n            bits = block[j];\n        }\n    }\n\n    int\
      \ popcount() const {\n        int res = 0;\n        for (int i = 0; i < (n +\
      \ BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n            res += kk2::popcount(block[i]);\n\
      \        }\n        return res;\n    }\n\n    T &operator~() { return flip();\
      \ }\n\n    T &operator&=(const T &other) {\n        assert(n == other.n);\n\
      \        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n\
      \            block[i] &= other.block[i];\n        }\n        return *this;\n\
      \    }\n\n    T &operator|=(const T &other) {\n        assert(n == other.n);\n\
      \        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n\
      \            block[i] |= other.block[i];\n        }\n        return *this;\n\
      \    }\n\n    T &operator^=(const T &other) {\n        assert(n == other.n);\n\
      \        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n\
      \            block[i] ^= other.block[i];\n        }\n        return *this;\n\
      \    }\n\n    T &inplace_or_repeated(const T &pattern) {\n        assert(pattern.n\
      \ > 0 && (pattern.n & BLOCK_MASK) == 0);\n        int pattern_words = pattern.word_count();\n\
      \        for (int begin = 0; begin < word_count(); begin += pattern_words) {\n\
      \            int size = std::min(pattern_words, word_count() - begin);\n   \
      \         for (int i = 0; i < size; ++i) block[begin + i] |= pattern.block[i];\n\
      \        }\n        return clear_unused_bits();\n    }\n\n    friend T operator&(const\
      \ T &lhs, const T &rhs) { return T(lhs) &= rhs; }\n\n    friend T operator|(const\
      \ T &lhs, const T &rhs) { return T(lhs) |= rhs; }\n\n    friend T operator^(const\
      \ T &lhs, const T &rhs) { return T(lhs) ^= rhs; }\n\n    friend bool operator==(const\
      \ T &lhs, const T &rhs) {\n        if (lhs.n != rhs.n) return false;\n     \
      \   for (int i = 0; i < (lhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n\
      \            if (lhs.block[i] != rhs.block[i]) return false;\n        }\n  \
      \      return true;\n    }\n\n    friend bool operator!=(const T &lhs, const\
      \ T &rhs) { return !(lhs == rhs); }\n\n    operator bool() const {\n       \
      \ for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n     \
      \       if (block[i]) return true;\n        }\n        return false;\n    }\n\
      \n    std::string to_string(UInt x) const { return std::bitset<BLOCK_SIZE>(x).to_string();\
      \ }\n\n    std::string to_string() const {\n        std::vector<std::string>\
      \ tmp((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n        for (int i = 0; i <\
      \ (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n            tmp[i] = to_string(block[i]);\n\
      \        }\n        if (n & BLOCK_MASK) {\n            std::reverse(std::begin(tmp.back()),\
      \ std::end(tmp.back()));\n            tmp.back().resize(n & BLOCK_MASK);\n \
      \           std::reverse(std::begin(tmp.back()), std::end(tmp.back()));\n  \
      \      }\n        std::string res;\n        for (int i = (n + BLOCK_SIZE - 1)\
      \ >> BLOCK_SIZE_LOG; i--;) { res += tmp[i]; }\n        return res;\n    }\n\n\
      \    std::string to_reversed_string() const {\n        std::vector<std::string>\
      \ tmp((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);\n        for (int i = 0; i <\
      \ (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {\n            tmp[i] = to_string(block[i]);\n\
      \        }\n        if (n & BLOCK_MASK) {\n            std::reverse(std::begin(tmp.back()),\
      \ std::end(tmp.back()));\n            tmp.back().resize(n & BLOCK_MASK);\n \
      \           std::reverse(std::begin(tmp.back()), std::end(tmp.back()));\n  \
      \      }\n        std::string res;\n        for (int i = 0; i < (n + BLOCK_SIZE\
      \ - 1) >> BLOCK_SIZE_LOG; i++) {\n            std::reverse(std::begin(tmp[i]),\
      \ std::end(tmp[i]));\n            res += tmp[i];\n        }\n        return\
      \ res;\n    }\n\n    template <OutputStream OStream> friend OStream &operator<<(OStream\
      \ &os, const T &bs) {\n        return os << bs.to_string();\n    }\n\n    template\
      \ <InputStream IStream> friend IStream &operator>>(IStream &is, T &bs) {\n \
      \       std::string s;\n        is >> s;\n        bs.set_reversed(s);\n    \
      \    return is;\n    }\n};\n\nstruct DynamicBitSet::RankSelect {\n  private:\n\
      \    DynamicBitSet _bits;\n    std::vector<int> _prefix;\n\n    UInt selected_word(int\
      \ word) const { return _bits.word(word); }\n\n  public:\n    RankSelect() :\
      \ _prefix(1) {}\n\n    explicit RankSelect(DynamicBitSet bits, bool value =\
      \ true)\n        : _bits(std::move(bits)),\n          _prefix(_bits.word_count()\
      \ + 1) {\n        for (int word = 0; word < _bits.word_count(); ++word) {\n\
      \            UInt selected = value ? _bits.word(word) : ~_bits.word(word);\n\
      \            if (word + 1 == _bits.word_count() && (_bits.size() & BLOCK_MASK))\
      \ {\n                selected &= (ONE << (_bits.size() & BLOCK_MASK)) - 1;\n\
      \            }\n            _bits.word(word) = selected;\n            _prefix[word\
      \ + 1] = _prefix[word] + std::popcount(selected);\n        }\n    }\n\n    int\
      \ bit_size() const { return _bits.size(); }\n\n    bool contains(int index)\
      \ const {\n        assert(0 <= index && index < bit_size());\n        return\
      \ _bits[index];\n    }\n\n    int rank(int end) const {\n        assert(0 <=\
      \ end && end <= bit_size());\n        int word = end >> BLOCK_SIZE_LOG;\n  \
      \      int result = _prefix[word];\n        if (end & BLOCK_MASK) {\n      \
      \      UInt mask = (ONE << (end & BLOCK_MASK)) - 1;\n            result += std::popcount(selected_word(word)\
      \ & mask);\n        }\n        return result;\n    }\n\n    int select(int rank)\
      \ const {\n        assert(0 <= rank && rank < size());\n        int word =\n\
      \            (int)(std::upper_bound(_prefix.begin(), _prefix.end(), rank) -\
      \ _prefix.begin()) - 1;\n        UInt selected = selected_word(word);\n    \
      \    int local_rank = rank - _prefix[word];\n        while (local_rank--) selected\
      \ &= selected - 1;\n        return word * BLOCK_SIZE + std::countr_zero(selected);\n\
      \    }\n\n    int find_next(int index) const { return _bits.find_next(index);\
      \ }\n\n    struct MonotoneCursor {\n      private:\n        const RankSelect\
      \ *_index;\n        int _last_rank = -1;\n        int _word = 0;\n\n      public:\n\
      \        explicit MonotoneCursor(const RankSelect &index) : _index(&index) {}\n\
      \n        int operator[](int rank) {\n            assert(0 <= rank && _last_rank\
      \ <= rank && rank < _index->size());\n            _last_rank = rank;\n     \
      \       while (_index->_prefix[_word + 1] <= rank) ++_word;\n            UInt\
      \ selected = _index->selected_word(_word);\n            int local_rank = rank\
      \ - _index->_prefix[_word];\n            while (local_rank--) selected &= selected\
      \ - 1;\n            return _word * BLOCK_SIZE + std::countr_zero(selected);\n\
      \        }\n    };\n\n    int size() const { return _prefix.back(); }\n\n  \
      \  int operator[](int rank) const { return select(rank); }\n\n    MonotoneCursor\
      \ monotone_cursor() const & { return MonotoneCursor(*this); }\n    MonotoneCursor\
      \ monotone_cursor() const && = delete;\n\n    struct RangeAccessor {\n     \
      \   const RankSelect *index;\n\n        using MonotoneCursor = RankSelect::MonotoneCursor;\n\
      \n        int size() const { return index->size(); }\n        int operator[](int\
      \ rank) const { return (*index)[rank]; }\n        MonotoneCursor monotone_cursor()\
      \ const { return index->monotone_cursor(); }\n    };\n\n    using Range = MonotoneRankRange<RangeAccessor>;\n\
      \n    Range range() const & { return Range{RangeAccessor{this}}; }\n    Range\
      \ range() const && = delete;\n\n    auto begin() const { return range().begin();\
      \ }\n    auto end() const { return range().end(); }\n    auto stride(int start,\
      \ int step) const & { return range().stride(start, step); }\n    auto stride(int\
      \ start, int step, int end) const & { return range().stride(start, step, end);\
      \ }\n    auto stride(int, int) const && = delete;\n    auto stride(int, int,\
      \ int) const && = delete;\n    std::vector<int> to_vec() const { return range().to_vec();\
      \ }\n};\n\n} // namespace kk2\n\n\n#line 1 \"math/enumerate_quotients.hpp\"\n\
      \n\n\n#include <numeric>\n#line 6 \"math/enumerate_quotients.hpp\"\n\n#line\
      \ 1 \"math/sqrt_floor.hpp\"\n\n\n\n#include <cmath>\n\n#line 1 \"math/frac_floor.hpp\"\
      \n\n\n\n#line 5 \"math/frac_floor.hpp\"\n\nnamespace kk2 {\n\n// floor(x) =\
      \ ceil(x) - 1 (for all x not in Z) ...(1)\n// floor(x) = -ceil(-x)   (for all\
      \ x)          ...(2)\n\n// return floor(a / b)\ntemplate <typename T, typename\
      \ U> constexpr T fracfloor(T a, U b) {\n    assert(b != 0);\n    if (a % b ==\
      \ 0) return a / b;\n    if (a >= 0) return a / b;\n\n    // floor(x) = -ceil(-x)\
      \      by (2)\n    //          = -floor(-x) - 1 by (1)\n    return -((-a) /\
      \ b) - 1;\n}\n\n// return ceil(a / b)\ntemplate <typename T, typename U> constexpr\
      \ T fracceil(T a, U b) {\n    assert(b != 0);\n    if (a % b == 0) return a\
      \ / b;\n    if (a >= 0) return a / b + 1;\n\n    // ceil(x) = -floor(-x)   \
      \   by (2)\n    return -((-a) / b);\n}\n\n} // namespace kk2\n\n\n#line 7 \"\
      math/sqrt_floor.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename T> T sqrt_floor(T\
      \ n) {\n    assert(n >= 0);\n    if (n == T(0)) return 0;\n    T x = std::sqrt(n);\n\
      \    if (x == T(0)) ++x;\n    while (x > kk2::fracfloor(n, x)) --x;\n    while\
      \ (x + 1 <= kk2::fracfloor(n, x + 1)) ++x;\n    return x;\n}\n\ntemplate <typename\
      \ T> T sqrt_ceil(T n) {\n    assert(n >= 0);\n    if (n <= T(1)) return n;\n\
      \    T x = std::sqrt(n);\n    if (x == T(0)) ++x;\n    while (x < kk2::fracceil(n,\
      \ x)) ++x;\n    while (x - 1 >= kk2::fracceil(n, x - 1)) --x;\n    return x;\n\
      }\n\n} // namespace kk2\n\n\n#line 8 \"math/enumerate_quotients.hpp\"\n\nnamespace\
      \ kk2 {\n\ntemplate <class T> struct EnumerateQuotients {\n    T n;\n    int\
      \ sqrt_n;\n    std::vector<T> res;\n\n    EnumerateQuotients(T n) : n(n), sqrt_n(sqrt_floor(n))\
      \ {\n        res.resize(sqrt_n + n / (sqrt_n + 1));\n        std::iota(res.begin(),\
      \ res.begin() + sqrt_n, 1);\n        for (T i = n / (sqrt_n + 1), j = sqrt_n;\
      \ i; --i, ++j) res[j] = n / i;\n    }\n\n    const std::vector<T> &get() const\
      \ { return res; }\n\n    int size() const { return res.size(); }\n\n    const\
      \ T &operator[](int i) const { return res[i]; }\n\n    int idx(T x) const {\n\
      \        if (x <= sqrt_n) return x - 1;\n        return size() - n / x;\n  \
      \  }\n};\n\n} // namespace kk2\n\n\n#line 8 \"math/multiplicative_function/prime_counting.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace internal {\n\ninline std::vector<int> prime_counting_base_primes(int\
      \ n) {\n    DynamicBitSet composite(n + 1);\n    std::vector<int> primes;\n\
      \    for (int p = 2; p <= n; ++p) {\n        if (composite[p]) continue;\n \
      \       primes.push_back(p);\n        if (1LL * p * p <= n) {\n            for\
      \ (long long q = 1LL * p * p; q <= n; q += p) composite.set((int)q);\n     \
      \   }\n    }\n    return primes;\n}\n\n} // namespace internal\n\nlong long\
      \ prime_counting(long long n) {\n    if (n < 2) return 0;\n    EnumerateQuotients<long\
      \ long> eq(n);\n    std::vector<int> primes = internal::prime_counting_base_primes(eq.sqrt_n);\n\
      \    std::vector<long long> dp(eq.size());\n    for (int i = 0; i < eq.size();\
      \ ++i) dp[i] = eq[i] - 1;\n    for (const long long p : primes) {\n        for\
      \ (int i = eq.size() - 1;; --i) {\n            if (eq[i] < p * p) break;\n \
      \           dp[i] -= dp[eq.idx(eq[i] / p)] - dp[p - 2];\n        }\n    }\n\
      \    return dp.back();\n}\n\n} // namespace kk2\n\n\n#line 11 \"math/wheel_sieve.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace number_theory {\n\ninline std::vector<int>\
      \ wheel_sieve(int n) {\n    constexpr std::array<int, 10> seed_primes{2, 3,\
      \ 5, 7, 11, 13, 17, 19, 23, 29};\n    if (n < 30) {\n        return std::vector<int>(seed_primes.begin(),\n\
      \                                std::upper_bound(seed_primes.begin(), seed_primes.end(),\
      \ n));\n    }\n\n    int sqrt_n = sqrt_floor(n);\n    int w = 1;\n    std::vector<bool>\
      \ iscoprime(sqrt_n, true);\n    int wheel_prime_count = 0;\n    while (wheel_prime_count\
      \ < 9 && w * seed_primes[wheel_prime_count] <= sqrt_n) {\n        w *= seed_primes[wheel_prime_count];\n\
      \        for (int j = seed_primes[wheel_prime_count]; j < sqrt_n;\n        \
      \     j += seed_primes[wheel_prime_count]) {\n            iscoprime[j] = false;\n\
      \        }\n        ++wheel_prime_count;\n    }\n\n    std::vector<int> idx_(w,\
      \ -1);\n    int s = 0;\n    for (int i = 1; i < w; ++i) {\n        if (iscoprime[i])\
      \ idx_[i] = s++;\n    }\n    std::vector<int> coprimes(s);\n    for (int i =\
      \ 1; i < w; ++i) {\n        if (idx_[i] != -1) coprimes[idx_[i]] = i;\n    }\n\
      \n    auto idx = [&](long long x) -> long long {\n        if (idx_[x % w] ==\
      \ -1) return -1;\n        return x / w * s + idx_[x % w];\n    };\n    auto\
      \ val = [&](int i) {\n        return i / s * w + coprimes[i % s];\n    };\n\n\
      \    int candidate_count = (n + w - 1) / w * s;\n    while (candidate_count\
      \ > 1 && val(candidate_count - 1) > n) --candidate_count;\n\n    std::vector<int>\
      \ primes;\n    primes.reserve(prime_counting(n));\n    for (int i = 0; i < wheel_prime_count;\
      \ ++i) primes.push_back(seed_primes[i]);\n\n    // A composite number not exceeding\
      \ an int has a prime factor below 2^16.\n    std::vector<std::uint16_t> lpf(candidate_count,\
      \ 0);\n    for (int i = 1; i < candidate_count; ++i) {\n        int v = val(i);\n\
      \        int least_prime = lpf[i] == 0 ? v : lpf[i];\n        if (lpf[i] ==\
      \ 0) primes.push_back(v);\n\n        for (int j = wheel_prime_count; j < (int)primes.size();\
      \ ++j) {\n            int p = primes[j];\n            long long index = idx(1LL\
      \ * p * v);\n            if (index >= candidate_count) break;\n            if\
      \ (least_prime < p) break;\n            lpf[index] = static_cast<std::uint16_t>(p);\n\
      \        }\n    }\n    return primes;\n}\n\n} // namespace number_theory\n\n\
      using number_theory::wheel_sieve;\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/wheel_sieve.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-21 19:50:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/wheel_sieve.test.cpp
documentation_of: math/wheel_sieve.hpp
layout: document
---
