---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: frac_floor.hpp
      icon: LIBRARY_ALL_AC
      path: math/frac_floor.hpp
    - filename: prime_table.hpp
      icon: LIBRARY_ALL_AC
      path: math/prime_table.hpp
    - filename: sqrt_floor.hpp
      icon: LIBRARY_ALL_AC
      path: math/sqrt_floor.hpp
    type: Depends on
  - files:
    - filename: convolution_gcd.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution_gcd.hpp
    - filename: convolution_lcm.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution_lcm.hpp
    type: Required by
  - files:
    - filename: convolution_gcd.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_gcd.test.cpp
    - filename: convolution_lcm.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_lcm.test.cpp
    type: Verified with
  dependsOn:
  - math/frac_floor.hpp
  - math/prime_table.hpp
  - math/sqrt_floor.hpp
  embedded:
  - code: "#ifndef KK2_CONVLUTION_DIVISOR_MULTIPLE_TRANSFORM_HPP\n#define KK2_CONVLUTION_DIVISOR_MULTIPLE_TRANSFORM_HPP\
      \ 1\n\n#include \"../math/prime_table.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
      \ FPS> void multiple_transform(FPS &a) {\n    int n = int(a.size());\n    if\
      \ (!n) return;\n    n--;\n    PrimeTable::set_upper(n);\n    for (const auto\
      \ p : PrimeTable::primes()) {\n        if (p > n) break;\n        for (int i\
      \ = n / p; i; i--) a[i] += a[i * p];\n    }\n}\n\ntemplate <class FPS> void\
      \ inverse_multiple_transform(FPS &a) {\n    int n = int(a.size());\n    if (!n)\
      \ return;\n    n--;\n    PrimeTable::set_upper(n);\n    for (const auto p :\
      \ PrimeTable::primes()) {\n        if (p > n) break;\n        for (int i = 1;\
      \ i <= n / p; i++) a[i] -= a[i * p];\n    }\n}\n\ntemplate <class FPS> void\
      \ divisor_transform(FPS &a) {\n    int n = int(a.size());\n    if (!n) return;\n\
      \    n--;\n    PrimeTable::set_upper(n);\n    for (const auto p : PrimeTable::primes())\
      \ {\n        if (p > n) break;\n        for (int i = 1; i <= n / p; i++) a[i\
      \ * p] += a[i];\n    }\n}\n\ntemplate <class FPS> void inverse_divisor_transform(FPS\
      \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    n--;\n    PrimeTable::set_upper(n);\n\
      \    for (const auto p : PrimeTable::primes()) {\n        if (p > n) break;\n\
      \        for (int i = n / p; i > 0; i--) a[i * p] -= a[i];\n    }\n}\n\n} //\
      \ namespace kk2\n\n#endif // KK2_CONVLUTION_DIVISOR_MULTIPLE_TRANSFORM_HPP\n"
    name: default
  - code: "#line 1 \"convolution/divisor_multiple_transform.hpp\"\n\n\n\n#line 1 \"\
      math/prime_table.hpp\"\n\n\n\n#include <algorithm>\n#include <vector>\n\n#line\
      \ 1 \"math/sqrt_floor.hpp\"\n\n\n\n#include <cmath>\n\n#line 1 \"math/frac_floor.hpp\"\
      \n\n\n\n#include <cassert>\n\nnamespace kk2 {\n\n// floor(x) = ceil(x) - 1 (for\
      \ all x not in Z) ...(1)\n// floor(x) = -ceil(-x)   (for all x)          ...(2)\n\
      \n// return floor(a / b)\ntemplate <typename T, typename U> constexpr T fracfloor(T\
      \ a, U b) {\n    assert(b != 0);\n    if (a % b == 0) return a / b;\n    if\
      \ (a >= 0) return a / b;\n\n    // floor(x) = -ceil(-x)      by (2)\n    //\
      \          = -floor(-x) - 1 by (1)\n    return -((-a) / b) - 1;\n}\n\n// return\
      \ ceil(a / b)\ntemplate <typename T, typename U> constexpr T fracceil(T a, U\
      \ b) {\n    assert(b != 0);\n    if (a % b == 0) return a / b;\n    if (a >=\
      \ 0) return a / b + 1;\n\n    // ceil(x) = -floor(-x)      by (2)\n    return\
      \ -((-a) / b);\n}\n\n} // namespace kk2\n\n\n#line 7 \"math/sqrt_floor.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <typename T> T sqrt_floor(T n) {\n    assert(n\
      \ >= 0);\n    if (n == T(0)) return 0;\n    T x = std::sqrt(n);\n    if (x ==\
      \ T(0)) ++x;\n    while (x > kk2::fracfloor(n, x)) --x;\n    while (x + 1 <=\
      \ kk2::fracfloor(n, x + 1)) ++x;\n    return x;\n}\n\ntemplate <typename T>\
      \ T sqrt_ceil(T n) {\n    assert(n >= 0);\n    if (n <= T(1)) return n;\n  \
      \  T x = std::sqrt(n);\n    if (x == T(0)) ++x;\n    while (x < kk2::fracceil(n,\
      \ x)) ++x;\n    while (x - 1 >= kk2::fracceil(n, x - 1)) --x;\n    return x;\n\
      }\n\n} // namespace kk2\n\n\n#line 8 \"math/prime_table.hpp\"\n\nnamespace kk2\
      \ {\n\nstruct PrimeTable {\n  private:\n    static inline int _n = 30;\n   \
      \ static inline std::vector<int> _primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};\n\
      \n  public:\n    PrimeTable() = delete;\n\n    // wheel sieve\n    // reference:\
      \ https://37zigen.com/wheel-sieve/\n    static void set_upper(int m, int reserve_size\
      \ = 26355867) {\n        if (m <= _n) return;\n        _n = std::max(m, 2 *\
      \ _n);\n        int sqrt_n = sqrt_floor(_n);\n        int w = 1;\n        std::vector<bool>\
      \ iscoprime(sqrt_n, true);\n        for (int i = 0; i < 9; i++) {\n        \
      \    if (w * _primes[i] > sqrt_n) break;\n            w *= _primes[i];\n   \
      \         for (int j = _primes[i]; j < sqrt_n; j += _primes[i]) iscoprime[j]\
      \ = false;\n        }\n\n        std::vector<int> idx_(w, -1);\n        int\
      \ s = 0;\n        for (int i = 1; i < w; i++) {\n            if (iscoprime[i])\
      \ idx_[i] = s++;\n        }\n        std::vector<int> coprimes(s);\n       \
      \ for (int i = 1; i < w; i++) {\n            if (idx_[i] != -1) coprimes[idx_[i]]\
      \ = i;\n        }\n\n        auto idx = [&](long long x) -> long long {\n  \
      \          if (idx_[x % w] == -1) return -1;\n            return x / w * s +\
      \ idx_[x % w];\n        };\n\n        auto val = [&](int i) {\n            return\
      \ i / s * w + coprimes[i % s];\n        };\n\n        int n = (_n + w - 1) /\
      \ w * s;\n        std::vector<int> _primes2;\n        _primes2.reserve(reserve_size);\n\
      \        std::vector<int> lpf(n, 0);\n        for (int i = 1; i < n; i++) {\n\
      \            int v = val(i);\n            if (lpf[i] == 0) {\n             \
      \   lpf[i] = v;\n                _primes2.push_back(lpf[i]);\n            }\n\
      \n            for (const long long p : _primes2) {\n                long long\
      \ j = idx(p * v);\n                if (j >= n) break;\n                if (lpf[i]\
      \ < p) break;\n                lpf[j] = p;\n            }\n        }\n\n   \
      \     std::vector<int> tmp;\n        tmp.reserve(_primes.size() + _primes2.size());\n\
      \        std::set_union(_primes.begin(),\n                       _primes.end(),\n\
      \                       _primes2.begin(),\n                       _primes2.end(),\n\
      \                       std::back_inserter(tmp));\n        _primes = std::move(tmp);\n\
      \    }\n\n    static const std::vector<int> &primes() { return _primes; }\n\n\
      \    template <typename It> struct PrimeIt {\n        It bg, ed;\n        PrimeIt(It\
      \ bg_, It ed_) : bg(bg_), ed(ed_) {}\n        It begin() const { return bg;\
      \ }\n        It end() const { return ed; }\n        int size() const { return\
      \ ed - bg; }\n        int operator[](int i) const { return bg[i]; }\n      \
      \  std::vector<int> to_vec() const { return std::vector<int>(bg, ed); }\n  \
      \  };\n\n    static auto primes(int n) {\n        if (n >= _n) set_upper(n);\n\
      \        return PrimeIt(_primes.begin(), std::upper_bound(_primes.begin(), _primes.end(),\
      \ n));\n    }\n};\n\n} // namespace kk2\n\n\n#line 5 \"convolution/divisor_multiple_transform.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <class FPS> void multiple_transform(FPS &a)\
      \ {\n    int n = int(a.size());\n    if (!n) return;\n    n--;\n    PrimeTable::set_upper(n);\n\
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
      \ / p; i > 0; i--) a[i * p] -= a[i];\n    }\n}\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: convolution/divisor_multiple_transform.hpp
  pathExtension: hpp
  requiredBy:
  - convolution/convolution_gcd.hpp
  - convolution/convolution_lcm.hpp
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_convolution/convolution_gcd.test.cpp
  - verify/yosupo_convolution/convolution_lcm.test.cpp
documentation_of: convolution/divisor_multiple_transform.hpp
layout: document
---
