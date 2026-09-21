---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  dependencies:
  - files:
    - filename: bitcount.hpp
      icon: LIBRARY_ALL_AC
      path: bit/bitcount.hpp
    - filename: convolution_gcd.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution_gcd.hpp
    - filename: divisor_multiple_transform.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/divisor_multiple_transform.hpp
    - filename: my_bitset.hpp
      icon: LIBRARY_ALL_AC
      path: data_structure/my_bitset.hpp
    - filename: frac_floor.hpp
      icon: LIBRARY_ALL_AC
      path: math/frac_floor.hpp
    - filename: isprime_table.hpp
      icon: LIBRARY_ALL_AC
      path: math/isprime_table.hpp
    - filename: prime_table.hpp
      icon: LIBRARY_ALL_AC
      path: math/prime_table.hpp
    - filename: sqrt_floor.hpp
      icon: LIBRARY_ALL_AC
      path: math/sqrt_floor.hpp
    - filename: mont.hpp
      icon: LIBRARY_ALL_AC
      path: modint/mont.hpp
    - filename: constant.hpp
      icon: LIBRARY_ALL_AC
      path: template/constant.hpp
    - filename: fastio.hpp
      icon: LIBRARY_ALL_AC
      path: template/fastio.hpp
    - filename: io_util.hpp
      icon: LIBRARY_ALL_AC
      path: template/io_util.hpp
    - filename: macros.hpp
      icon: LIBRARY_ALL_AC
      path: template/macros.hpp
    - filename: template.hpp
      icon: LIBRARY_ALL_AC
      path: template/template.hpp
    - filename: type_alias.hpp
      icon: LIBRARY_ALL_AC
      path: template/type_alias.hpp
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn:
  - bit/bitcount.hpp
  - convolution/convolution_gcd.hpp
  - convolution/divisor_multiple_transform.hpp
  - data_structure/my_bitset.hpp
  - math/frac_floor.hpp
  - math/isprime_table.hpp
  - math/prime_table.hpp
  - math/sqrt_floor.hpp
  - modint/mont.hpp
  - template/constant.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  - template/template.hpp
  - template/type_alias.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/gcd_convolution\n\
      \n#include \"../../convolution/convolution_gcd.hpp\"\n\n#include \"../../modint/mont.hpp\"\
      \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
      \ {\n    int n;\n    kin >> n;\n    vc<kk2::mont998> a(n + 1), b(n + 1);\n \
      \   rep(i, n) kin >> a[i + 1];\n    rep(i, n) kin >> b[i + 1];\n    kk2::convolution_gcd(a,\
      \ b);\n    rep(i, n) kout << a[i + 1] << \" \\n\"[i == n - 1];\n\n    return\
      \ 0;\n}\n"
    name: default
  - code: "#line 1 \"verify/yosupo_convolution/convolution_gcd.test.cpp\"\n// competitive-verifier:\
      \ PROBLEM https://judge.yosupo.jp/problem/gcd_convolution\n\n#line 1 \"convolution/convolution_gcd.hpp\"\
      \n\n\n\n#include <cassert>\n\n#line 1 \"convolution/divisor_multiple_transform.hpp\"\
      \n\n\n\n#line 1 \"math/prime_table.hpp\"\n\n\n\n#line 1 \"math/isprime_table.hpp\"\
      \n\n\n\n#include <algorithm>\n#include <array>\n#include <bit>\n#line 8 \"math/isprime_table.hpp\"\
      \n#include <cstdint>\n#include <iterator>\n#include <vector>\n\n#line 1 \"data_structure/my_bitset.hpp\"\
      \n\n\n\n#line 6 \"data_structure/my_bitset.hpp\"\n#include <bitset>\n#line 9\
      \ \"data_structure/my_bitset.hpp\"\n#include <iostream>\n#line 11 \"data_structure/my_bitset.hpp\"\
      \n#include <string>\n#include <utility>\n#line 14 \"data_structure/my_bitset.hpp\"\
      \n\n#line 1 \"bit/bitcount.hpp\"\n\n\n\n#line 5 \"bit/bitcount.hpp\"\n\n#line\
      \ 1 \"type_traits/integral.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace\
      \ kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T>\nusing is_signed_int128\
      \ = typename std::conditional<std::is_same<T, __int128_t>::value\n         \
      \                                              or std::is_same<T, __int128>::value,\n\
      \                                                   std::true_type,\n      \
      \                                             std::false_type>::type;\n\ntemplate\
      \ <typename T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __uint128_t>::value\n                                  or std::is_same<T,\
      \ unsigned __int128>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_integral =\n    typename std::conditional<std::is_integral<T>::value\
      \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T>\nusing is_signed = typename\
      \ std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n\
      \                                            std::true_type,\n             \
      \                               std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
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
      \ }\n};\n\n} // namespace kk2\n\n\n#line 1 \"math/sqrt_floor.hpp\"\n\n\n\n#include\
      \ <cmath>\n\n#line 1 \"math/frac_floor.hpp\"\n\n\n\n#line 5 \"math/frac_floor.hpp\"\
      \n\nnamespace kk2 {\n\n// floor(x) = ceil(x) - 1 (for all x not in Z) ...(1)\n\
      // floor(x) = -ceil(-x)   (for all x)          ...(2)\n\n// return floor(a /\
      \ b)\ntemplate <typename T, typename U> constexpr T fracfloor(T a, U b) {\n\
      \    assert(b != 0);\n    if (a % b == 0) return a / b;\n    if (a >= 0) return\
      \ a / b;\n\n    // floor(x) = -ceil(-x)      by (2)\n    //          = -floor(-x)\
      \ - 1 by (1)\n    return -((-a) / b) - 1;\n}\n\n// return ceil(a / b)\ntemplate\
      \ <typename T, typename U> constexpr T fracceil(T a, U b) {\n    assert(b !=\
      \ 0);\n    if (a % b == 0) return a / b;\n    if (a >= 0) return a / b + 1;\n\
      \n    // ceil(x) = -floor(-x)      by (2)\n    return -((-a) / b);\n}\n\n} //\
      \ namespace kk2\n\n\n#line 7 \"math/sqrt_floor.hpp\"\n\nnamespace kk2 {\n\n\
      template <typename T> T sqrt_floor(T n) {\n    assert(n >= 0);\n    if (n ==\
      \ T(0)) return 0;\n    T x = std::sqrt(n);\n    if (x == T(0)) ++x;\n    while\
      \ (x > kk2::fracfloor(n, x)) --x;\n    while (x + 1 <= kk2::fracfloor(n, x +\
      \ 1)) ++x;\n    return x;\n}\n\ntemplate <typename T> T sqrt_ceil(T n) {\n \
      \   assert(n >= 0);\n    if (n <= T(1)) return n;\n    T x = std::sqrt(n);\n\
      \    if (x == T(0)) ++x;\n    while (x < kk2::fracceil(n, x)) ++x;\n    while\
      \ (x - 1 >= kk2::fracceil(n, x - 1)) --x;\n    return x;\n}\n\n} // namespace\
      \ kk2\n\n\n#line 14 \"math/isprime_table.hpp\"\n\nnamespace kk2 {\n\nstruct\
      \ IsPrimeTable {\n  private:\n    static constexpr std::array<int, 9> _small_primes{2,\
      \ 3, 5, 7, 11, 13, 17, 19, 23};\n    static inline int _n = 1;\n    static inline\
      \ int _wheel = 1;\n    static inline int _residue_count = 0;\n    static inline\
      \ int _wheel_prime_count = 0;\n    static inline std::vector<int> _coprimes{};\n\
      \    static inline std::vector<int> _residue_index{};\n    static inline DynamicBitSet::RankSelect\
      \ _prime_candidates{};\n\n    template <int Wheel, int ResidueCount>\n    static\
      \ void set_offsets(int p,\n                            const std::vector<int>\
      \ &coprimes,\n                            const std::vector<int> &residue_index,\n\
      \                            int *offsets) {\n        for (int r = 0; r < ResidueCount;\
      \ ++r) {\n            long long x = 1LL * p * coprimes[r];\n            offsets[r]\
      \ = x / Wheel * ResidueCount + residue_index[x % Wheel];\n        }\n    }\n\
      \n    static int candidate_value(int index) {\n        return index / _residue_count\
      \ * _wheel + _coprimes[index % _residue_count];\n    }\n\n    static int candidate_end(int\
      \ n) {\n        return n / _wheel * _residue_count\n               + (int)(std::upper_bound(_coprimes.begin(),\
      \ _coprimes.end(), n % _wheel)\n                       - _coprimes.begin());\n\
      \    }\n\n    static int candidate_rank(int end) { return _prime_candidates.rank(end);\
      \ }\n\n  public:\n    IsPrimeTable() = delete;\n\n    static void set_upper(int\
      \ m) {\n        if (m <= _n && _residue_count != 0) return;\n        int next_n\
      \ = std::max({m, 2 * _n, 60});\n\n        int sqrt_n = sqrt_floor(next_n);\n\
      \        int wheel = 1;\n        int wheel_prime_count = 0;\n        // A moderately\
      \ larger wheel pays off by reducing the number of sieve candidates.\n      \
      \  while (wheel_prime_count < (int)_small_primes.size()\n               && 4LL\
      \ * wheel * _small_primes[wheel_prime_count] <= 7LL * sqrt_n) {\n          \
      \  wheel *= _small_primes[wheel_prime_count];\n            ++wheel_prime_count;\n\
      \        }\n\n        std::vector<bool> iscoprime(wheel, true);\n        for\
      \ (int i = 0; i < wheel_prime_count; ++i) {\n            for (int j = _small_primes[i];\
      \ j < wheel; j += _small_primes[i]) iscoprime[j] = false;\n        }\n     \
      \   std::vector<int> residue_index(wheel, -1);\n        int residue_count =\
      \ 0;\n        for (int i = 1; i < wheel; ++i) {\n            if (iscoprime[i])\
      \ residue_index[i] = residue_count++;\n        }\n        std::vector<int> coprimes(residue_count);\n\
      \        for (int i = 1; i < wheel; ++i) {\n            if (residue_index[i]\
      \ != -1) coprimes[residue_index[i]] = i;\n        }\n\n        auto val = [&](int\
      \ i) {\n            return i / residue_count * wheel + coprimes[i % residue_count];\n\
      \        };\n\n        int candidate_count = (next_n + wheel - 1) / wheel *\
      \ residue_count;\n        while (candidate_count > 1 && val(candidate_count\
      \ - 1) > next_n) --candidate_count;\n        DynamicBitSet composite(candidate_count);\n\
      \        std::uint64_t *composite_data = composite.data();\n        auto set_composite\
      \ = [&](long long i) {\n            composite_data[i >> 6] |= std::uint64_t(1)\
      \ << (i & 63);\n        };\n        {\n            std::vector<bool> base_isprime(sqrt_n\
      \ + 1, true);\n            base_isprime[0] = base_isprime[1] = false;\n    \
      \        std::vector<int> base_primes;\n            for (int p = 2; p <= sqrt_n;\
      \ ++p) {\n                if (!base_isprime[p]) continue;\n                if\
      \ (p > _small_primes[wheel_prime_count - 1]) base_primes.push_back(p);\n   \
      \             if (1LL * p * p <= sqrt_n) {\n                    for (int q =\
      \ p * p; q <= sqrt_n; q += p) base_isprime[q] = false;\n                }\n\
      \            }\n            constexpr int dense_limit = 112;\n            constexpr\
      \ int dense_mask_bytes = 1 << 20;\n            int dense_count = 0;\n      \
      \      if (wheel == 30030) {\n                std::vector<int> offsets(residue_count);\n\
      \                while (dense_count < (int)base_primes.size()\n            \
      \           && base_primes[dense_count] <= dense_limit) {\n                \
      \    ++dense_count;\n                }\n                for (int group_begin\
      \ = 0; group_begin < dense_count;) {\n                    int product = 1;\n\
      \                    int group_end = group_begin;\n                    while\
      \ (group_end < dense_count\n                           && 1LL * product * base_primes[group_end]\
      \ * residue_count\n                                  <= 8LL * dense_mask_bytes)\
      \ {\n                        product *= base_primes[group_end++];\n        \
      \            }\n                    if (group_end == group_begin) product =\
      \ base_primes[group_end++];\n                    int mask_word_count = product\
      \ * residue_count / 64;\n                    DynamicBitSet mask(mask_word_count\
      \ * 64);\n                    for (int k = group_begin; k < group_end; ++k)\
      \ {\n                        int p = base_primes[k];\n                     \
      \   set_offsets<30030, 5760>(p, coprimes, residue_index, offsets.data());\n\
      \                        int period = p * residue_count;\n                 \
      \       for (int base = 0; base < product * residue_count; base += period) {\n\
      \                            for (int offset : offsets) {\n                \
      \                int index = base + offset;\n                              \
      \  mask.word(index >> 6) |= std::uint64_t(1) << (index & 63);\n            \
      \                }\n                        }\n                    }\n     \
      \               composite.inplace_or_repeated(mask);\n                    for\
      \ (int k = group_begin; k < group_end; ++k) {\n                        int p\
      \ = base_primes[k];\n                        int index = p / wheel * residue_count\
      \ + residue_index[p % wheel];\n                        composite.word(index\
      \ >> 6) &= ~(std::uint64_t(1) << (index & 63));\n                    }\n   \
      \                 group_begin = group_end;\n                }\n            }\n\
      \            int sparse_end = base_primes.size();\n            while (sparse_end\
      \ > dense_count && 1LL * base_primes[sparse_end - 1] * wheel > next_n) {\n \
      \               int p = base_primes[--sparse_end];\n                int begin\
      \ = residue_index[p % wheel];\n                int end = std::upper_bound(coprimes.begin(),\
      \ coprimes.end(), next_n / p)\n                          - coprimes.begin();\n\
      \                for (int r = begin; r < end; ++r) {\n                    long\
      \ long x = 1LL * p * coprimes[r];\n                    set_composite(x / wheel\
      \ * residue_count + residue_index[x % wheel]);\n                }\n        \
      \    }\n            struct SieveState {\n                int residue;\n    \
      \            long long base, step;\n            };\n            int batch_size\
      \ = wheel == 30030 ? 384 : 128;\n            constexpr int segment_size = 1\
      \ << 21;\n            // Keep one candidate segment hot while marking it with\
      \ a batch of primes.\n            std::vector<int> all_offsets((std::size_t)batch_size\
      \ * residue_count);\n            std::vector<SieveState> states(batch_size);\n\
      \            for (int batch_begin = dense_count; batch_begin < sparse_end;\n\
      \                 batch_begin += batch_size) {\n                int size = std::min(batch_size,\
      \ sparse_end - batch_begin);\n                for (int k = 0; k < size; ++k)\
      \ {\n                    int p = base_primes[batch_begin + k];\n           \
      \         int *offsets = all_offsets.data() + (std::size_t)k * residue_count;\n\
      \                    switch (wheel) {\n                        case 6:\n   \
      \                         set_offsets<6, 2>(p, coprimes, residue_index, offsets);\n\
      \                            break;\n                        case 30:\n    \
      \                        set_offsets<30, 8>(p, coprimes, residue_index, offsets);\n\
      \                            break;\n                        case 210:\n   \
      \                         set_offsets<210, 48>(p, coprimes, residue_index, offsets);\n\
      \                            break;\n                        case 2310:\n  \
      \                          set_offsets<2310, 480>(p, coprimes, residue_index,\
      \ offsets);\n                            break;\n                        case\
      \ 30030:\n                            set_offsets<30030, 5760>(p, coprimes,\
      \ residue_index, offsets);\n                            break;\n           \
      \             default:\n                            for (int r = 0; r < residue_count;\
      \ ++r) {\n                                long long x = 1LL * p * coprimes[r];\n\
      \                                offsets[r] = x / wheel * residue_count + residue_index[x\
      \ % wheel];\n                            }\n                    }\n        \
      \            int i = p / wheel * residue_count + residue_index[p % wheel];\n\
      \                    int block = i / residue_count;\n                    states[k]\
      \ = {i % residue_count,\n                                 1LL * p * block *\
      \ residue_count,\n                                 1LL * p * residue_count};\n\
      \                }\n                for (int segment_begin = 0; segment_begin\
      \ < candidate_count;\n                     segment_begin += segment_size) {\n\
      \                    int segment_end = std::min(candidate_count, segment_begin\
      \ + segment_size);\n                    for (int k = 0; k < size; ++k) {\n \
      \                       SieveState &state = states[k];\n                   \
      \     int *offsets = all_offsets.data() + (std::size_t)k * residue_count;\n\
      \                        while (state.base + offsets[residue_count - 1] < segment_end)\
      \ {\n                            int r = state.residue;\n                  \
      \          for (; r + 4 <= residue_count; r += 4) {\n                      \
      \          set_composite(state.base + offsets[r]);\n                       \
      \         set_composite(state.base + offsets[r + 1]);\n                    \
      \            set_composite(state.base + offsets[r + 2]);\n                 \
      \               set_composite(state.base + offsets[r + 3]);\n              \
      \              }\n                            for (; r < residue_count; ++r)\
      \ {\n                                set_composite(state.base + offsets[r]);\n\
      \                            }\n                            state.residue =\
      \ 0;\n                            state.base += state.step;\n              \
      \          }\n                        while (state.residue < residue_count\n\
      \                               && state.base + offsets[state.residue] < segment_end)\
      \ {\n                            set_composite(state.base + offsets[state.residue]);\n\
      \                            ++state.residue;\n                        }\n \
      \                       if (state.residue == residue_count) {\n            \
      \                state.residue = 0;\n                            state.base\
      \ += state.step;\n                        }\n                    }\n       \
      \         }\n            }\n        }\n\n        composite.set(0);\n       \
      \ _n = next_n;\n        _wheel = wheel;\n        _residue_count = residue_count;\n\
      \        _wheel_prime_count = wheel_prime_count;\n        _coprimes = std::move(coprimes);\n\
      \        _residue_index = std::move(residue_index);\n        _prime_candidates\
      \ = DynamicBitSet::RankSelect(std::move(composite), false);\n    }\n\n  private:\n\
      \    struct PrimeAccessor {\n        struct MonotoneCursor {\n          private:\n\
      \            int _size, _prefix_count;\n            int _last_rank = -1;\n \
      \           DynamicBitSet::RankSelect::MonotoneCursor _cursor;\n\n         \
      \ public:\n            MonotoneCursor(int size, int prefix_count)\n        \
      \        : _size(size),\n                  _prefix_count(prefix_count),\n  \
      \                _cursor(_prime_candidates.monotone_cursor()) {}\n\n       \
      \     int operator[](int rank) {\n                assert(0 <= rank && _last_rank\
      \ <= rank && rank < _size);\n                _last_rank = rank;\n          \
      \      if (rank < _prefix_count) {\n                    assert(rank < (int)_small_primes.size());\n\
      \                    return _small_primes[rank];\n                }\n\n    \
      \            return candidate_value(_cursor[rank - _prefix_count]);\n      \
      \      }\n        };\n\n        int _size, _prefix_count;\n\n        int size()\
      \ const { return _size; }\n\n        int operator[](int rank) const {\n    \
      \        assert(0 <= rank && rank < _size);\n            if (rank < _prefix_count)\
      \ return _small_primes[rank];\n            return candidate_value(_prime_candidates[rank\
      \ - _prefix_count]);\n        }\n\n        MonotoneCursor monotone_cursor()\
      \ const { return MonotoneCursor(_size, _prefix_count); }\n    };\n\n  public:\n\
      \    static auto primes(int n) {\n        using Range = MonotoneRankRange<PrimeAccessor>;\n\
      \        if (n >= _n) set_upper(n);\n        if (_residue_count == 0)\n    \
      \        return Range{\n                PrimeAccessor{0, 0}\n            };\n\
      \        int prefix_count =\n            (int)(std::upper_bound(\n         \
      \             _small_primes.begin(), _small_primes.begin() + _wheel_prime_count,\
      \ n)\n                  - _small_primes.begin());\n        int end = candidate_end(n);\n\
      \        return Range{\n            PrimeAccessor{prefix_count + candidate_rank(end),\
      \ prefix_count}\n        };\n    }\n\n    static auto primes() { return primes(_n);\
      \ }\n\n    static bool isprime(int n) {\n        assert(n > 0);\n        if\
      \ (n >= _n) set_upper(n);\n        for (int i = 0; i < _wheel_prime_count; ++i)\
      \ {\n            if (n == _small_primes[i]) return true;\n        }\n      \
      \  int residue = _residue_index[n % _wheel];\n        if (residue == -1) return\
      \ false;\n        int index = n / _wheel * _residue_count + residue;\n     \
      \   return _prime_candidates.contains(index);\n    }\n};\n\n} // namespace kk2\n\
      \n\n#line 5 \"math/prime_table.hpp\"\n\nnamespace kk2 {\n\nstruct PrimeTable\
      \ {\n    PrimeTable() = delete;\n\n    static void set_upper(int m) { IsPrimeTable::set_upper(m);\
      \ }\n\n    static auto primes() { return IsPrimeTable::primes(); }\n\n    static\
      \ auto primes(int n) { return IsPrimeTable::primes(n); }\n};\n\n} // namespace\
      \ kk2\n\n\n#line 5 \"convolution/divisor_multiple_transform.hpp\"\n\nnamespace\
      \ kk2 {\n\ntemplate <class FPS> void multiple_transform(FPS &a) {\n    int n\
      \ = int(a.size());\n    if (!n) return;\n    n--;\n    PrimeTable::set_upper(n);\n\
      \    for (const auto p : PrimeTable::primes()) {\n        if (p > n) break;\n\
      \        for (int i = n / p; i; i--) a[i] += a[i * p];\n    }\n}\n\ntemplate\
      \ <class FPS> void inverse_multiple_transform(FPS &a) {\n    int n = int(a.size());\n\
      \    if (!n) return;\n    n--;\n    PrimeTable::set_upper(n);\n    for (const\
      \ auto p : PrimeTable::primes()) {\n        if (p > n) break;\n        for (int\
      \ i = 1; i <= n / p; i++) a[i] -= a[i * p];\n    }\n}\n\ntemplate <class FPS>\
      \ void divisor_transform(FPS &a) {\n    int n = int(a.size());\n    if (!n)\
      \ return;\n    n--;\n    PrimeTable::set_upper(n);\n    for (const auto p :\
      \ PrimeTable::primes()) {\n        if (p > n) break;\n        for (int i = 1;\
      \ i <= n / p; i++) a[i * p] += a[i];\n    }\n}\n\ntemplate <class FPS> void\
      \ inverse_divisor_transform(FPS &a) {\n    int n = int(a.size());\n    if (!n)\
      \ return;\n    n--;\n    PrimeTable::set_upper(n);\n    for (const auto p :\
      \ PrimeTable::primes()) {\n        if (p > n) break;\n        for (int i = n\
      \ / p; i > 0; i--) a[i * p] -= a[i];\n    }\n}\n\n} // namespace kk2\n\n\n#line\
      \ 7 \"convolution/convolution_gcd.hpp\"\n\nnamespace kk2 {\n\n// 1-indexed\n\
      template <class FPS> FPS convolution_gcd(FPS &a, const FPS &b) {\n    assert(size(a)\
      \ == size(b));\n    int n = int(size(a)); // = int(size(b))\n    if (!n) return\
      \ {};\n    n--;\n    FPS c(b.begin(), b.end());\n\n    multiple_transform(a);\n\
      \    multiple_transform(c);\n    for (int i = 1; i <= n; i++) a[i] *= c[i];\n\
      \    inverse_multiple_transform(a);\n\n    return a;\n}\n\n} // namespace kk2\n\
      \n\n#line 4 \"verify/yosupo_convolution/convolution_gcd.test.cpp\"\n\n#line\
      \ 1 \"modint/mont.hpp\"\n\n\n\n#line 8 \"modint/mont.hpp\"\n\n#line 11 \"modint/mont.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <int p> struct LazyMontgomeryModInt {\n    using\
      \ mint = LazyMontgomeryModInt;\n    using i32 = int32_t;\n    using i64 = int64_t;\n\
      \    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static constexpr\
      \ u32 get_r() {\n        u32 ret = p;\n        for (int i = 0; i < 4; ++i) ret\
      \ *= 2 - p * ret;\n        return ret;\n    }\n\n    static constexpr u32 r\
      \ = get_r();\n    static constexpr u32 n2 = -u64(p) % p;\n    static_assert(r\
      \ * p == 1, \"invalid, r * p != 1\");\n    static_assert(p < (1 << 30), \"invalid,\
      \ p >= 2 ^ 30\");\n    static_assert((p & 1) == 1, \"invalid, p % 2 == 0\");\n\
      \n    u32 _v;\n\n    constexpr LazyMontgomeryModInt() : _v(0) {}\n\n    template\
      \ <Integral T> constexpr LazyMontgomeryModInt(T b) : _v(reduce(u64(b % p + p)\
      \ * n2)) {}\n\n    static constexpr u32 reduce(const u64 &b) { return (b + u64(u32(b)\
      \ * u32(-r)) * p) >> 32; }\n    constexpr mint &operator++() { return *this\
      \ += 1; }\n    constexpr mint &operator--() { return *this -= 1; }\n\n    constexpr\
      \ mint operator++(int) {\n        mint ret = *this;\n        *this += 1;\n \
      \       return ret;\n    }\n\n    constexpr mint operator--(int) {\n       \
      \ mint ret = *this;\n        *this -= 1;\n        return ret;\n    }\n\n   \
      \ constexpr mint &operator+=(const mint &b) {\n        if (i32(_v += b._v -\
      \ 2 * p) < 0) _v += 2 * p;\n        return *this;\n    }\n\n    constexpr mint\
      \ &operator-=(const mint &b) {\n        if (i32(_v -= b._v) < 0) _v += 2 * p;\n\
      \        return *this;\n    }\n\n    constexpr mint &operator*=(const mint &b)\
      \ {\n        _v = reduce(u64(_v) * b._v);\n        return *this;\n    }\n\n\
      \    constexpr mint &operator/=(const mint &b) {\n        *this *= b.inv();\n\
      \        return *this;\n    }\n\n\n    constexpr bool operator==(const mint\
      \ &b) const {\n        return (_v >= p ? _v - p : _v) == (b._v >= p ? b._v -\
      \ p : b._v);\n    }\n\n    constexpr bool operator!=(const mint &b) const {\n\
      \        return (_v >= p ? _v - p : _v) != (b._v >= p ? b._v - p : b._v);\n\
      \    }\n\n    constexpr mint operator-() const { return mint() - mint(*this);\
      \ }\n    constexpr mint operator+() const { return mint(*this); }\n    friend\
      \ constexpr mint operator+(const mint &a, const mint &b) { return mint(a) +=\
      \ b; }\n    friend constexpr mint operator-(const mint &a, const mint &b) {\
      \ return mint(a) -= b; }\n    friend constexpr mint operator*(const mint &a,\
      \ const mint &b) { return mint(a) *= b; }\n    friend constexpr mint operator/(const\
      \ mint &a, const mint &b) { return mint(a) /= b; }\n\n    template <class T>\
      \ constexpr mint pow(T n) const {\n        mint ret(1), mul(*this);\n      \
      \  while (n > 0) {\n            if (n & 1) ret *= mul;\n            if (n >>=\
      \ 1) mul *= mul;\n        }\n        return ret;\n    }\n\n    constexpr mint\
      \ inv() const {\n        assert(*this != mint(0));\n        return pow(p - 2);\n\
      \    }\n\n    template <OutputStream OStream> friend OStream &operator<<(OStream\
      \ &os, const mint &x) {\n        return os << x.val();\n    }\n\n    template\
      \ <InputStream IStream> friend IStream &operator>>(IStream &is, mint &x) {\n\
      \        i64 t;\n        is >> t;\n        x = mint(t);\n        return (is);\n\
      \    }\n\n    constexpr u32 val() const {\n        u32 ret = reduce(_v);\n \
      \       return ret >= p ? ret - p : ret;\n    }\n\n    static constexpr u32\
      \ getmod() { return p; }\n};\n\ntemplate <int p> using Mont = LazyMontgomeryModInt<p>;\n\
      \nusing mont998 = Mont<998244353>;\nusing mont107 = Mont<1000000007>;\n\n} //\
      \ namespace kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#line 8 \"template/template.hpp\"\
      \n#include <chrono>\n#line 10 \"template/template.hpp\"\n#include <deque>\n\
      #include <functional>\n#line 13 \"template/template.hpp\"\n#include <limits>\n\
      #include <map>\n#include <numeric>\n#include <optional>\n#include <queue>\n\
      #include <random>\n#include <set>\n#include <stack>\n#line 22 \"template/template.hpp\"\
      \n#include <unordered_map>\n#include <unordered_set>\n#line 26 \"template/template.hpp\"\
      \n\n#line 1 \"template/constant.hpp\"\n\n\n\n#line 1 \"template/type_alias.hpp\"\
      \n\n\n\n#line 8 \"template/type_alias.hpp\"\n\nusing u32 = unsigned int;\nusing\
      \ i64 = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\n\
      using u128 = __uint128_t;\n\nusing pi = std::pair<int, int>;\nusing pl = std::pair<i64,\
      \ i64>;\nusing pil = std::pair<int, i64>;\nusing pli = std::pair<i64, int>;\n\
      \ntemplate <class T> using vc = std::vector<T>;\ntemplate <class T> using vvc\
      \ = std::vector<vc<T>>;\ntemplate <class T> using vvvc = std::vector<vvc<T>>;\n\
      template <class T> using vvvvc = std::vector<vvvc<T>>;\n\ntemplate <class T>\
      \ using pq = std::priority_queue<T>;\ntemplate <class T> using pqi = std::priority_queue<T,\
      \ std::vector<T>, std::greater<T>>;\n\n\n#line 5 \"template/constant.hpp\"\n\
      \ntemplate <class T> constexpr T infty = 0;\ntemplate <> constexpr int infty<int>\
      \ = (1 << 30) - 123;\ntemplate <> constexpr i64 infty<i64> = (1ll << 62) - (1ll\
      \ << 31);\ntemplate <> constexpr i128 infty<i128> = (i128(1) << 126) - (i128(1)\
      \ << 63);\ntemplate <> constexpr u32 infty<u32> = infty<int>;\ntemplate <> constexpr\
      \ u64 infty<u64> = infty<i64>;\ntemplate <> constexpr u128 infty<u128> = infty<i128>;\n\
      template <> constexpr double infty<double> = infty<i64>;\ntemplate <> constexpr\
      \ long double infty<long double> = infty<i64>;\n\nconstexpr int mod = 998244353;\n\
      constexpr int modu = 1e9 + 7;\nconstexpr long double PI = 3.14159265358979323846;\n\
      \n\n#line 1 \"template/fastio.hpp\"\n\n\n\n#include <cctype>\n#line 6 \"template/fastio.hpp\"\
      \n#include <cstdio>\n#line 10 \"template/fastio.hpp\"\n\n#line 13 \"template/fastio.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace fastio {\n\nstruct Scanner : type_traits::istream_tag\
      \ {\n  private:\n    static constexpr size_t INPUT_BUF = 1 << 17;\n    size_t\
      \ pos = 0, end = 0;\n    bool is_eof = false;\n    static char buf[INPUT_BUF];\n\
      \    FILE *fp;\n\n  public:\n    Scanner() : fp(stdin) {}\n\n    Scanner(const\
      \ char *file) : fp(fopen(file, \"r\")) {}\n\n    ~Scanner() {\n        if (fp\
      \ != stdin) fclose(fp);\n    }\n\n    char now() {\n        if (is_eof) return\
      \ '\\0';\n        if (pos == end) {\n            end = fread(buf, 1, INPUT_BUF,\
      \ fp);\n            if (end != INPUT_BUF) buf[end] = '\\0';\n            if\
      \ (end == 0) is_eof = true;\n            pos = 0;\n        }\n        return\
      \ buf[pos];\n    }\n\n    void skip_space() {\n        while (isspace(now()))\
      \ ++pos;\n    }\n\n    template <UnsignedIntegral T> T next_unsigned_integral()\
      \ {\n        skip_space();\n        T res{};\n        while (isdigit(now()))\
      \ {\n            res = res * 10 + (now() - '0');\n            ++pos;\n     \
      \   }\n        return res;\n    }\n\n    template <SignedIntegral T> T next_signed_integral()\
      \ {\n        skip_space();\n        if (now() == '-') {\n            ++pos;\n\
      \            return T(-next_unsigned_integral<typename to_unsigned<T>::type>());\n\
      \        } else return (T)next_unsigned_integral<typename to_unsigned<T>::type>();\n\
      \    }\n\n    char next_char() {\n        skip_space();\n        auto res =\
      \ now();\n        ++pos;\n        return res;\n    }\n\n    std::string next_string()\
      \ {\n        skip_space();\n        std::string res;\n        while (true) {\n\
      \            char c = now();\n            if (isspace(c) or c == '\\0') break;\n\
      \            res.push_back(now());\n            ++pos;\n        }\n        return\
      \ res;\n    }\n\n    template <UnsignedIntegral T> Scanner &operator>>(T &x)\
      \ {\n        x = next_unsigned_integral<T>();\n        return *this;\n    }\n\
      \n    template <SignedIntegral T> Scanner &operator>>(T &x) {\n        x = next_signed_integral<T>();\n\
      \        return *this;\n    }\n\n    Scanner &operator>>(char &x) {\n      \
      \  x = next_char();\n        return *this;\n    }\n\n    Scanner &operator>>(std::string\
      \ &x) {\n        x = next_string();\n        return *this;\n    }\n};\n\nstruct\
      \ endl_struct_t {};\n\nstruct Printer : type_traits::ostream_tag {\n  private:\n\
      \    static char helper[10000][5];\n    static char leading_zero[10000][5];\n\
      \    constexpr static size_t OUTPUT_BUF = 1 << 17;\n    static char buf[OUTPUT_BUF];\n\
      \    size_t pos = 0;\n    FILE *fp;\n\n    template <class T> static constexpr\
      \ void div_mod(T &a, T &b, T mod) {\n        a = b / mod;\n        b -= a *\
      \ mod;\n    }\n\n    static void init() {\n        buf[0] = '\\0';\n       \
      \ for (size_t i = 0; i < 10000; ++i) {\n            leading_zero[i][0] = i /\
      \ 1000 + '0';\n            leading_zero[i][1] = i / 100 % 10 + '0';\n      \
      \      leading_zero[i][2] = i / 10 % 10 + '0';\n            leading_zero[i][3]\
      \ = i % 10 + '0';\n            leading_zero[i][4] = '\\0';\n\n            size_t\
      \ j = 0;\n            if (i >= 1000) helper[i][j++] = i / 1000 + '0';\n    \
      \        if (i >= 100) helper[i][j++] = i / 100 % 10 + '0';\n            if\
      \ (i >= 10) helper[i][j++] = i / 10 % 10 + '0';\n            helper[i][j++]\
      \ = i % 10 + '0';\n            helper[i][j] = '\\0';\n        }\n    }\n\n \
      \ public:\n    Printer() : fp(stdout) { init(); }\n\n    Printer(const char\
      \ *file) : fp(fopen(file, \"w\")) { init(); }\n\n    ~Printer() {\n        write();\n\
      \        if (fp != stdout) fclose(fp);\n    }\n\n    void write() {\n      \
      \  fwrite(buf, 1, pos, fp);\n        pos = 0;\n    }\n\n    void flush() {\n\
      \        write();\n        fflush(fp);\n    }\n\n    void put_char(char c) {\n\
      \        if (pos == OUTPUT_BUF) write();\n        buf[pos++] = c;\n    }\n\n\
      \    void put_cstr(const char *s) {\n        while (*s) put_char(*(s++));\n\
      \    }\n\n    void put_u32(uint32_t x) {\n        uint32_t y;\n        if (x\
      \ >= 100000000) { // 10^8\n            div_mod<uint32_t>(y, x, 100000000);\n\
      \            put_cstr(helper[y]);\n            div_mod<uint32_t>(y, x, 10000);\n\
      \            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
      \        } else if (x >= 10000) { // 10^4\n            div_mod<uint32_t>(y,\
      \ x, 10000);\n            put_cstr(helper[y]);\n            put_cstr(leading_zero[x]);\n\
      \        } else put_cstr(helper[x]);\n    }\n\n    void put_i32(int32_t x) {\n\
      \        if (x < 0) {\n            put_char('-');\n            put_u32(-x);\n\
      \        } else put_u32(x);\n    }\n\n    void put_u64(uint64_t x) {\n     \
      \   uint64_t y;\n        if (x >= 1000000000000ull) { // 10^12\n           \
      \ div_mod<uint64_t>(y, x, 1000000000000ull);\n            put_u32(y);\n    \
      \        div_mod<uint64_t>(y, x, 100000000ull);\n            put_cstr(leading_zero[y]);\n\
      \            div_mod<uint64_t>(y, x, 10000ull);\n            put_cstr(leading_zero[y]);\n\
      \            put_cstr(leading_zero[x]);\n        } else if (x >= 10000ull) {\
      \ // 10^4\n            div_mod<uint64_t>(y, x, 10000ull);\n            put_u32(y);\n\
      \            put_cstr(leading_zero[x]);\n        } else put_cstr(helper[x]);\n\
      \    }\n\n    void put_i64(int64_t x) {\n        if (x < 0) {\n            put_char('-');\n\
      \            put_u64(-x);\n        } else put_u64(x);\n    }\n\n    void put_u128(__uint128_t\
      \ x) {\n        constexpr static __uint128_t pow10_10 = 10000000000ull;\n  \
      \      constexpr static __uint128_t pow10_20 = pow10_10 * pow10_10;\n\n    \
      \    __uint128_t y;\n        if (x >= pow10_20) { // 10^20\n            div_mod<__uint128_t>(y,\
      \ x, pow10_20);\n            put_u64(uint64_t(y));\n            div_mod<__uint128_t>(y,\
      \ x, __uint128_t(10000000000000000ull));\n            put_cstr(leading_zero[y]);\n\
      \            div_mod<__uint128_t>(y, x, __uint128_t(1000000000000ull));\n  \
      \          put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x,\
      \ __uint128_t(100000000ull));\n            put_cstr(leading_zero[y]);\n    \
      \        div_mod<__uint128_t>(y, x, __uint128_t(10000ull));\n            put_cstr(leading_zero[y]);\n\
      \            put_cstr(leading_zero[x]);\n        } else if (x >= __uint128_t(10000))\
      \ { // 10^4\n            div_mod<__uint128_t>(y, x, __uint128_t(10000));\n \
      \           put_u64(uint64_t(y));\n            put_cstr(leading_zero[x]);\n\
      \        } else put_cstr(helper[x]);\n    }\n\n    void put_i128(__int128_t\
      \ x) {\n        if (x < 0) {\n            put_char('-');\n            put_u128(-x);\n\
      \        } else put_u128(x);\n    }\n\n    template <UnsignedIntegral T> Printer\
      \ &operator<<(T x) {\n        if constexpr (sizeof(T) <= 4) put_u32(x);\n  \
      \      else if constexpr (sizeof(T) <= 8) put_u64(x);\n        else put_u128(x);\n\
      \        return *this;\n    }\n\n    template <SignedIntegral T> Printer &operator<<(T\
      \ x) {\n        if constexpr (sizeof(T) <= 4) put_i32(x);\n        else if constexpr\
      \ (sizeof(T) <= 8) put_i64(x);\n        else put_i128(x);\n        return *this;\n\
      \    }\n\n    Printer &operator<<(char x) {\n        put_char(x);\n        return\
      \ *this;\n    }\n\n    Printer &operator<<(const std::string &x) {\n       \
      \ for (char c : x) put_char(c);\n        return *this;\n    }\n\n    Printer\
      \ &operator<<(const char *x) {\n        put_cstr(x);\n        return *this;\n\
      \    }\n\n    // std::cout << std::endl; \u306F\u95A2\u6570\u30DD\u30A4\u30F3\
      \u30BF\u3092\u6E21\u3057\u3066\u3044\u308B\u3089\u3057\u3044\n    Printer &operator<<(endl_struct_t)\
      \ {\n        put_char('\\n');\n        flush();\n        return *this;\n   \
      \ }\n};\n\nchar Scanner::buf[Scanner::INPUT_BUF];\nchar Printer::buf[Printer::OUTPUT_BUF];\n\
      char Printer::helper[10000][5];\nchar Printer::leading_zero[10000][5];\n\n}\
      \ // namespace fastio\n\n#if defined(INTERACTIVE) || defined(USE_STDIO)\nauto\
      \ &kin = std::cin;\nauto &kout = std::cout;\nauto (*kendl)(std::ostream &) =\
      \ std::endl<char, std::char_traits<char>>;\n#else\nfastio::Scanner kin;\nfastio::Printer\
      \ kout;\nfastio::endl_struct_t kendl;\n#endif\n\n} // namespace kk2\n\n\n#line\
      \ 1 \"template/io_util.hpp\"\n\n\n\n#line 7 \"template/io_util.hpp\"\n\n#line\
      \ 9 \"template/io_util.hpp\"\n\n// \u306A\u3093\u304Boj verify\u306F\u30D7\u30ED\
      \u30C8\u30BF\u30A4\u30D7\u5BA3\u8A00\u304C\u843D\u3061\u308B\n\nnamespace impl\
      \ {\n\nstruct read {\n    template <class IStream, class T> inline static void\
      \ all_read(IStream &is, T &x) { is >> x; }\n\n    template <class IStream, class\
      \ T, class U>\n    inline static void all_read(IStream &is, std::pair<T, U>\
      \ &p) {\n        all_read(is, p.first);\n        all_read(is, p.second);\n \
      \   }\n\n    template <class IStream, class T> inline static void all_read(IStream\
      \ &is, std::vector<T> &v) {\n        for (T &x : v) all_read(is, x);\n    }\n\
      \n    template <class IStream, class T, size_t F>\n    inline static void all_read(IStream\
      \ &is, std::array<T, F> &a) {\n        for (T &x : a) all_read(is, x);\n   \
      \ }\n};\n\nstruct write {\n    template <class OStream, class T> inline static\
      \ void all_write(OStream &os, const T &x) {\n        os << x;\n    }\n\n   \
      \ template <class OStream, class T, class U>\n    inline static void all_write(OStream\
      \ &os, const std::pair<T, U> &p) {\n        all_write(os, p.first);\n      \
      \  all_write(os, ' ');\n        all_write(os, p.second);\n    }\n\n    template\
      \ <class OStream, class T>\n    inline static void all_write(OStream &os, const\
      \ std::vector<T> &v) {\n        for (int i = 0; i < (int)v.size(); ++i) {\n\
      \            if (i) all_write(os, ' ');\n            all_write(os, v[i]);\n\
      \        }\n    }\n\n    template <class OStream, class T, size_t F>\n    inline\
      \ static void all_write(OStream &os, const std::array<T, F> &a) {\n        for\
      \ (int i = 0; i < (int)F; ++i) {\n            if (i) all_write(os, ' ');\n \
      \           all_write(os, a[i]);\n        }\n    }\n};\n\n} // namespace impl\n\
      \ntemplate <kk2::InputStream IStream, class T, class U>\nIStream &operator>>(IStream\
      \ &is, std::pair<T, U> &p) {\n    impl::read::all_read(is, p);\n    return is;\n\
      }\n\ntemplate <kk2::InputStream IStream, class T> IStream &operator>>(IStream\
      \ &is, std::vector<T> &v) {\n    impl::read::all_read(is, v);\n    return is;\n\
      }\n\ntemplate <kk2::InputStream IStream, class T, size_t F>\nIStream &operator>>(IStream\
      \ &is, std::array<T, F> &a) {\n    impl::read::all_read(is, a);\n    return\
      \ is;\n}\n\ntemplate <kk2::OutputStream OStream, class T, class U>\nOStream\
      \ &operator<<(OStream &os, const std::pair<T, U> &p) {\n    impl::write::all_write(os,\
      \ p);\n    return os;\n}\n\ntemplate <kk2::OutputStream OStream, class T>\n\
      OStream &operator<<(OStream &os, const std::vector<T> &v) {\n    impl::write::all_write(os,\
      \ v);\n    return os;\n}\n\ntemplate <kk2::OutputStream OStream, class T, size_t\
      \ F>\nOStream &operator<<(OStream &os, const std::array<T, F> &a) {\n    impl::write::all_write(os,\
      \ a);\n    return os;\n}\n\n\n#line 1 \"template/macros.hpp\"\n\n\n\n#define\
      \ rep1(a) for (long long _ = 0; _ < (long long)(a); ++_)\n#define rep2(i, a)\
      \ for (long long i = 0; i < (long long)(a); ++i)\n#define rep3(i, a, b) for\
      \ (long long i = (a); i < (long long)(b); ++i)\n#define repi2(i, a) for (long\
      \ long i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (long long i =\
      \ (a) - 1; i >= (long long)(b); --i)\n#define overload3(a, b, c, d, ...) d\n\
      #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define\
      \ repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n#define\
      \ fi first\n#define se second\n\n\n#line 32 \"template/template.hpp\"\n\nusing\
      \ kk2::kendl;\nusing kk2::kin;\nusing kk2::kout;\n\nvoid Yes(bool b = 1) { kout\
      \ << (b ? \"Yes\\n\" : \"No\\n\"); }\nvoid No(bool b = 1) { kout << (b ? \"\
      No\\n\" : \"Yes\\n\"); }\nvoid YES(bool b = 1) { kout << (b ? \"YES\\n\" : \"\
      NO\\n\"); }\nvoid NO(bool b = 1) { kout << (b ? \"NO\\n\" : \"YES\\n\"); }\n\
      void yes(bool b = 1) { kout << (b ? \"yes\\n\" : \"no\\n\"); }\nvoid no(bool\
      \ b = 1) { kout << (b ? \"no\\n\" : \"yes\\n\"); }\ntemplate <class T, class\
      \ S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }\n\
      template <class T, class S> inline bool chmin(T &a, const S &b) { return (a\
      \ > b ? a = b, 1 : 0); }\n\n\n#line 7 \"verify/yosupo_convolution/convolution_gcd.test.cpp\"\
      \nusing namespace std;\n\nint main() {\n    int n;\n    kin >> n;\n    vc<kk2::mont998>\
      \ a(n + 1), b(n + 1);\n    rep(i, n) kin >> a[i + 1];\n    rep(i, n) kin >>\
      \ b[i + 1];\n    kk2::convolution_gcd(a, b);\n    rep(i, n) kout << a[i + 1]\
      \ << \" \\n\"[i == n - 1];\n\n    return 0;\n}\n"
    name: bundled
  isFailed: false
  isVerificationFile: true
  path: verify/yosupo_convolution/convolution_gcd.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases:
  - elapsed: 0.0021918579999962162
    environment: g++
    memory: 3.888
    name: all_zero_00
    status: AC
  - elapsed: 0.0018284789999967188
    environment: g++
    memory: 3.912
    name: example_00
    status: AC
  - elapsed: 0.4340038739999983
    environment: g++
    memory: 19.276
    name: max_random_00
    status: AC
  - elapsed: 0.4324747269999989
    environment: g++
    memory: 19.256
    name: max_random_01
    status: AC
  - elapsed: 0.4332211440000009
    environment: g++
    memory: 19.268
    name: near_prime_00
    status: AC
  - elapsed: 0.43231475099999983
    environment: g++
    memory: 19.24
    name: near_prime_01
    status: AC
  - elapsed: 0.43394444599999815
    environment: g++
    memory: 19.272
    name: near_prime_02
    status: AC
  - elapsed: 0.4281614499999975
    environment: g++
    memory: 19.076
    name: near_prime_squared_00
    status: AC
  - elapsed: 0.4279902349999958
    environment: g++
    memory: 19.104
    name: near_prime_squared_01
    status: AC
  - elapsed: 0.42749713499999586
    environment: g++
    memory: 19.092
    name: near_prime_squared_02
    status: AC
  - elapsed: 0.17041278199999965
    environment: g++
    memory: 9.712
    name: random_00
    status: AC
  - elapsed: 0.2041741479999999
    environment: g++
    memory: 10.88
    name: random_01
    status: AC
  - elapsed: 0.25200042899999886
    environment: g++
    memory: 12.672
    name: random_02
    status: AC
  - elapsed: 0.002286454000000049
    environment: g++
    memory: 3.836
    name: small_00
    status: AC
  - elapsed: 0.0018229089999977077
    environment: g++
    memory: 3.84
    name: small_01
    status: AC
  - elapsed: 0.0018717510000030302
    environment: g++
    memory: 3.84
    name: small_02
    status: AC
  - elapsed: 0.0018130039999988412
    environment: g++
    memory: 3.908
    name: small_03
    status: AC
  - elapsed: 0.0017942160000004037
    environment: g++
    memory: 3.912
    name: small_04
    status: AC
  - elapsed: 0.0018583599999999478
    environment: g++
    memory: 3.908
    name: small_05
    status: AC
  - elapsed: 0.0017986520000050632
    environment: g++
    memory: 3.908
    name: small_06
    status: AC
  - elapsed: 0.0017755280000031348
    environment: g++
    memory: 3.852
    name: small_07
    status: AC
  - elapsed: 0.0018410610000003658
    environment: g++
    memory: 3.828
    name: small_08
    status: AC
  - elapsed: 0.0017659179999967023
    environment: g++
    memory: 3.868
    name: small_09
    status: AC
  - elapsed: 0.0018065040000010413
    environment: g++
    memory: 3.908
    name: small_10
    status: AC
  - elapsed: 0.0017986719999996126
    environment: g++
    memory: 3.84
    name: small_11
    status: AC
  - elapsed: 0.0017948369999984948
    environment: g++
    memory: 3.828
    name: small_12
    status: AC
  - elapsed: 0.0018012560000002509
    environment: g++
    memory: 3.908
    name: small_13
    status: AC
  - elapsed: 0.0017754780000061032
    environment: g++
    memory: 3.908
    name: small_14
    status: AC
  - elapsed: 0.0018058730000021228
    environment: g++
    memory: 3.86
    name: small_15
    status: AC
  timestamp: '2026-09-21 19:50:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_convolution/convolution_gcd.test.cpp
layout: document
---
