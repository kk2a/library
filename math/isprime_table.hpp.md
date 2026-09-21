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
    - filename: frac_floor.hpp
      icon: LIBRARY_ALL_AC
      path: math/frac_floor.hpp
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
  - files:
    - filename: convolution_gcd.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution_gcd.hpp
    - filename: convolution_lcm.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution_lcm.hpp
    - filename: divisor_multiple_transform.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/divisor_multiple_transform.hpp
    - filename: prefix_sum.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/prefix_sum.hpp
    - filename: prime_table.hpp
      icon: LIBRARY_ALL_AC
      path: math/prime_table.hpp
    type: Required by
  - files:
    - filename: isprime_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/isprime_table_extend.test.cpp
    - filename: prime_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/prime_table_extend.test.cpp
    - filename: wheel_sieve.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/wheel_sieve.test.cpp
    - filename: convolution_gcd.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_gcd.test.cpp
    - filename: convolution_lcm.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_lcm.test.cpp
    - filename: enumerate_primes.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_primes.test.cpp
    - filename: prefix_sum_of_multiplicative_function.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
    - filename: sum_of_totient_function.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/sum_of_totient_function.test.cpp
    type: Verified with
  dependsOn:
  - bit/bitcount.hpp
  - data_structure/my_bitset.hpp
  - math/frac_floor.hpp
  - math/sqrt_floor.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_MATH_ISPRIME_TABLE_HPP\n#define KK2_MATH_ISPRIME_TABLE_HPP\
      \ 1\n\n#include <algorithm>\n#include <array>\n#include <bit>\n#include <cassert>\n\
      #include <cstdint>\n#include <iterator>\n#include <vector>\n\n#include \"../data_structure/my_bitset.hpp\"\
      \n#include \"sqrt_floor.hpp\"\n\nnamespace kk2 {\n\nstruct IsPrimeTable {\n\
      \  private:\n    static constexpr std::array<int, 9> _small_primes{2, 3, 5,\
      \ 7, 11, 13, 17, 19, 23};\n    static inline int _n = 1;\n    static inline\
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
      \n#endif // KK2_MATH_ISPRIME_TABLE_HPP\n"
    name: default
  - code: "#line 1 \"math/isprime_table.hpp\"\n\n\n\n#include <algorithm>\n#include\
      \ <array>\n#include <bit>\n#include <cassert>\n#include <cstdint>\n#include\
      \ <iterator>\n#include <vector>\n\n#line 1 \"data_structure/my_bitset.hpp\"\n\
      \n\n\n#line 6 \"data_structure/my_bitset.hpp\"\n#include <bitset>\n#line 9 \"\
      data_structure/my_bitset.hpp\"\n#include <iostream>\n#line 11 \"data_structure/my_bitset.hpp\"\
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
      \n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/isprime_table.hpp
  pathExtension: hpp
  requiredBy:
  - convolution/convolution_gcd.hpp
  - convolution/convolution_lcm.hpp
  - convolution/divisor_multiple_transform.hpp
  - math/multiplicative_function/prefix_sum.hpp
  - math/prime_table.hpp
  timestamp: '2026-09-21 19:50:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/isprime_table_extend.test.cpp
  - verify/unit_test/math/prime_table_extend.test.cpp
  - verify/unit_test/math/wheel_sieve.test.cpp
  - verify/yosupo_convolution/convolution_gcd.test.cpp
  - verify/yosupo_convolution/convolution_lcm.test.cpp
  - verify/yosupo_math/enumerate_primes.test.cpp
  - verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
  - verify/yosupo_math/sum_of_totient_function.test.cpp
documentation_of: math/isprime_table.hpp
layout: document
---
