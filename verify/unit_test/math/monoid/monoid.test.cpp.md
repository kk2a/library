---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/monoid/affine.hpp
    title: math/monoid/affine.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/hold.hpp
    title: "\u5E38\u306B\u53F3\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\u30A4\
      \u30C9"
  - icon: ':question:'
    path: math/monoid/max.hpp
    title: math/monoid/max.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/max_min_sumwithsize.hpp
    title: math/monoid/max_min_sumwithsize.hpp
  - icon: ':question:'
    path: math/monoid/min.hpp
    title: math/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/update.hpp
    title: "\u5E38\u306B\u5DE6\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\u30A4\
      \u30C9"
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/seed.hpp
    title: random/seed.hpp
  - icon: ':question:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':question:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/math/monoid/monoid.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"math/monoid/affine.hpp\"\
    \n\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n#include <ostream>\n\
    #include <type_traits>\n\nnamespace kk2 {\n\nnamespace type_traits {\n\nstruct\
    \ istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\ntemplate\
    \ <typename T> using is_standard_istream =\n    typename std::conditional<std::is_same<T,\
    \ std::istream>::value\n                                  || std::is_same<T, std::ifstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_standard_ostream =\n\
    \    typename std::conditional<std::is_same<T, std::ostream>::value\n        \
    \                          || std::is_same<T, std::ofstream>::value,\n       \
    \                       std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_user_defined_istream = std::is_base_of<type_traits::istream_tag,\
    \ T>;\ntemplate <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
    \ T>;\n\ntemplate <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
    \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
    \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate <typename\
    \ T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n#line 5 \"math/monoid/affine.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ monoid {\n\ntemplate <class S> struct Affine {\n    static constexpr bool commutative\
    \ = false;\n    using M = Affine;\n    S a, b; // x \\mapsto ax + b\n\n    Affine()\
    \ : a(S(1)), b(S(0)) {};\n    Affine(S a, S b) : a(a), b(b) {}\n    inline S eval(S\
    \ x) const { return a * x + b; }\n    // l \\circ r\n    inline static M op(M\
    \ l, M r) { return M(l.a * r.a, l.a * r.b + l.b); }\n    inline static M unit()\
    \ { return M(); }\n    inline static M inv(M f) { return M(S(1) / f.a, -f.b /\
    \ f.a); }\n    bool operator==(const M &rhs) const { return a == rhs.a and b ==\
    \ rhs.b; }\n    bool operator!=(const M &rhs) const { return a != rhs.a or b !=\
    \ rhs.b; }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n\
    \    friend OStream &operator<<(OStream &os, const M &x) {\n        return os\
    \ << x.a << \" \" << x.b;\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    friend IStream &operator>>(IStream &is, M &x) {\n        return\
    \ is >> x.a >> x.b;\n    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\
    \n\n#line 1 \"math/monoid/hold.hpp\"\n\n\n\n#line 5 \"math/monoid/hold.hpp\"\n\
    \nnamespace kk2 {\n\nnamespace monoid {\n\n/**\n * @brief \u5E38\u306B\u53F3\u5074\
    \u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\u30A4\u30C9\n */\ntemplate <class S>\
    \ struct Hold {\n    static constexpr bool commutative = true;\n    using M =\
    \ Hold;\n\n    S a;\n    bool is_unit;\n\n    Hold() : is_unit(true) {}\n    Hold(S\
    \ a_) : a(a_), is_unit(false) {}\n    operator S() const { return a; }\n    inline\
    \ static M op(M l, M r) { return r.is_unit ? l : r; }\n    inline static M unit()\
    \ { return M(); }\n\n    bool operator==(const M &rhs) const {\n        return\
    \ is_unit == rhs.is_unit and (is_unit or a == rhs.a);\n    }\n\n    bool operator!=(const\
    \ M &rhs) const {\n        return is_unit != rhs.is_unit or (!is_unit and a !=\
    \ rhs.a);\n    }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n\
    \    friend OStream &operator<<(OStream &os, const M &x) {\n        if (x.is_unit)\
    \ os << \"unit\";\n        else os << x.a;\n        return os;\n    }\n\n    template\
    \ <class IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, M &x) {\n        is >> x.a;\n        x.is_unit = false;\n        return\
    \ is;\n    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\n\n#line 1 \"\
    math/monoid/max.hpp\"\n\n\n\n#include <functional>\n\n#line 7 \"math/monoid/max.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace monoid {\n\ntemplate <class S, class Compare\
    \ = std::less<S>> struct Max {\n    static constexpr bool commutative = true;\n\
    \    using M = Max;\n    S a;\n    bool is_unit;\n\n    Max() : a(S()), is_unit(true)\
    \ {}\n    Max(S a_) : a(a_), is_unit(false) {}\n    operator S() const { return\
    \ a; }\n\n    inline static M op(M l, M r) {\n        if (l.is_unit or r.is_unit)\
    \ return l.is_unit ? r : l;\n        return Compare{}(l.a, r.a) ? r : l;\n   \
    \ }\n\n    inline static M unit() { return M(); }\n\n    bool operator==(const\
    \ M &rhs) const {\n        return is_unit == rhs.is_unit and (is_unit or a ==\
    \ rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const {\n        return\
    \ is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const M &x) {\n        if (x.is_unit) os << \"-inf\";\n        else os\
    \ << x.a;\n        return os;\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    friend IStream &operator>>(IStream &is, M &x) {\n        is\
    \ >> x.a;\n        x.is_unit = false;\n        return is;\n    }\n};\n\n} // namespace\
    \ monoid\n\n} // namespace kk2\n\n\n#line 1 \"math/monoid/max_min_sumwithsize.hpp\"\
    \n\n\n\n#line 5 \"math/monoid/max_min_sumwithsize.hpp\"\n\n#line 7 \"math/monoid/max_min_sumwithsize.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace monoid {\n\ntemplate <class S, class T, class\
    \ Compare = std::less<S>> struct MaxMinSumWithSize {\n    static constexpr bool\
    \ commutative = true;\n    using M = MaxMinSumWithSize;\n    S max, min, sum;\n\
    \    T size;\n    bool is_unit;\n\n    MaxMinSumWithSize() : is_unit(true) {}\n\
    \    MaxMinSumWithSize(S a) : max(a), min(a), sum(a), size(1), is_unit(false)\
    \ {}\n    MaxMinSumWithSize(S max_, S min_, S sum_, T size_)\n        : max(max_),\n\
    \          min(min_),\n          sum(sum_),\n          size(size_),\n        \
    \  is_unit(false) {}\n\n    inline static M op(M l, M r) {\n        if (l.is_unit\
    \ or r.is_unit) return l.is_unit ? r : l;\n        return M(Compare{}(l.max, r.max)\
    \ ? r.max : l.max,\n                 Compare{}(l.min, r.min) ? l.min : r.min,\n\
    \                 l.sum + r.sum,\n                 l.size + r.size);\n    }\n\n\
    \    inline static M unit() { return M(); }\n\n    bool operator==(const M &rhs)\
    \ const {\n        return is_unit == rhs.is_unit\n               and (is_unit\n\
    \                    or (max == rhs.max and min == rhs.min and sum == rhs.sum\
    \ and size == rhs.size));\n    }\n\n    bool operator!=(const M &rhs) const {\n\
    \        return is_unit != rhs.is_unit\n               or (!is_unit\n        \
    \           and (max != rhs.max or min != rhs.min or sum != rhs.sum or size !=\
    \ rhs.size));\n    }\n\n    template <class OStream, is_ostream_t<OStream> * =\
    \ nullptr>\n    friend OStream &operator<<(OStream &os, const M &x) {\n      \
    \  if (x.is_unit) os << \"(unit)\";\n        else\n            os << \"(max:\"\
    \ << x.max << \", min:\" << x.min << \", sum:\" << x.sum << \", size:\" << x.size\n\
    \               << \")\";\n        return os;\n    }\n\n    template <class IStream,\
    \ is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream &is,\
    \ M &x) {\n        S a;\n        is >> a;\n        x = M(a);\n        return is;\n\
    \    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\n\n#line 1 \"math/monoid/min.hpp\"\
    \n\n\n\n#line 5 \"math/monoid/min.hpp\"\n\n#line 7 \"math/monoid/min.hpp\"\n\n\
    namespace kk2 {\n\nnamespace monoid {\n\ntemplate <class S, class Compare = std::less<S>>\
    \ struct Min {\n    static constexpr bool commutative = true;\n    using M = Min;\n\
    \    S a;\n    bool is_unit;\n\n    Min() : a(S()), is_unit(true) {}\n    Min(S\
    \ a_) : a(a_), is_unit(false) {}\n    operator S() const { return a; }\n\n   \
    \ inline static M op(M l, M r) {\n        if (l.is_unit or r.is_unit) return l.is_unit\
    \ ? r : l;\n        return Compare{}(l.a, r.a) ? l : r;\n    }\n\n    inline static\
    \ M unit() { return M(); }\n\n    bool operator==(const M &rhs) const {\n    \
    \    return is_unit == rhs.is_unit and (is_unit or a == rhs.a);\n    }\n\n   \
    \ bool operator!=(const M &rhs) const {\n        return is_unit != rhs.is_unit\
    \ or (!is_unit and a != rhs.a);\n    }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    friend OStream &operator<<(OStream &os, const M &x) {\n  \
    \      if (x.is_unit) os << \"inf\";\n        else os << x.a;\n        return\
    \ os;\n    }\n\n    template <class IStream, is_istream_t<IStream> * = nullptr>\n\
    \    friend IStream &operator>>(IStream &is, M &x) {\n        is >> x.a;\n   \
    \     x.is_unit = false;\n        return is;\n    }\n};\n\n} // namespace monoid\n\
    \n} // namespace kk2\n\n\n#line 1 \"math/monoid/update.hpp\"\n\n\n\n#line 5 \"\
    math/monoid/update.hpp\"\n\nnamespace kk2 {\n\nnamespace monoid {\n\n/**\n * @brief\
    \ \u5E38\u306B\u5DE6\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\u30A4\u30C9\
    \n */\ntemplate <class S> struct Update {\n    static constexpr bool commutative\
    \ = true;\n    using M = Update;\n    S a;\n    bool is_unit;\n\n    Update()\
    \ : is_unit(true) {}\n    Update(S a_) : a(a_), is_unit(false) {}\n    operator\
    \ S() const { return a; }\n    inline static M op(M l, M r) { return l.is_unit\
    \ ? r : l; }\n    inline static M unit() { return M(); }\n\n    bool operator==(const\
    \ M &rhs) const {\n        return is_unit == rhs.is_unit and (is_unit or a ==\
    \ rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const {\n        return\
    \ is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const M &x) {\n        if (x.is_unit) os << \"unit\";\n        else os\
    \ << x.a;\n        return os;\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    friend IStream &operator>>(IStream &is, M &x) {\n        is\
    \ >> x.a;\n        x.is_unit = false;\n        return is;\n    }\n};\n\n} // namespace\
    \ monoid\n\n} // namespace kk2\n\n\n#line 1 \"random/gen.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <numeric>\n#include <random>\n#include\
    \ <unordered_set>\n#include <vector>\n\n#line 1 \"random/seed.hpp\"\n\n\n\n#include\
    \ <chrono>\n\nnamespace kk2 {\n\nnamespace random {\n\nusing u64 = unsigned long\
    \ long;\n\ninline u64 non_deterministic_seed() {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n\
    \                   std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count();\n    seed ^= reinterpret_cast<u64>(&seed);\n   \
    \ seed ^= seed << 5;\n    seed ^= seed >> 41;\n    seed ^= seed << 20;\n    return\
    \ seed;\n}\n\ninline u64 deterministic_seed() { return 5801799128519729247ull;\
    \ }\n\ninline u64 seed() {\n#if defined(KK2_RANDOM_DETERMINISTIC)\n    return\
    \ deterministic_seed();\n#else\n    return non_deterministic_seed();\n#endif\n\
    }\n\n} // namespace random\n\n} // namespace kk2\n\n\n#line 12 \"random/gen.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace random {\n\nusing i64 = long long;\nusing u64\
    \ = unsigned long long;\n\ninline u64 rng() {\n    static std::mt19937_64 mt(kk2::random::seed());\n\
    \    return mt();\n}\n\n// [l, r)\ninline i64 rng(i64 l, i64 r) {\n    assert(l\
    \ < r);\n    return l + rng() % (r - l);\n}\n\n// [l, r)\ntemplate <class T> std::vector<T>\
    \ random_vector(int n, T l, T r) {\n    std::vector<T> res(n);\n    for (int i\
    \ = 0; i < n; i++) res[i] = rng(l, r);\n    return res;\n}\n\n// [l, r)\nstd::vector<i64>\
    \ distinct_rng(i64 l, i64 r, i64 n) {\n    assert(l < r and n <= r - l);\n   \
    \ std::unordered_set<i64> st;\n    for (i64 i = n; i; --i) {\n        i64 m =\
    \ rng(l, r + 1 - i);\n        if (st.find(m) != st.end()) m = r - i;\n       \
    \ st.insert(m);\n    }\n    std::vector<i64> res(st.begin(), st.end());\n    std::sort(res.begin(),\
    \ res.end());\n    return res;\n}\n\ntemplate <class Iter> void shuffle(Iter first,\
    \ Iter last) {\n    if (first == last) return;\n    int len = 1;\n    for (auto\
    \ it = first + 1; it != last; ++it) {\n        len++;\n        int j = rng(0,\
    \ len);\n        if (j != len - 1) std::iter_swap(first + j, it);\n    }\n}\n\n\
    template <class T> std::vector<T> perm(int n) {\n    std::vector<T> res(n);\n\
    \    std::iota(res.begin(), res.end(), T(0));\n    shuffle(res.begin(), res.end());\n\
    \    return res;\n}\n\ntemplate <class T> std::vector<T> choices(int l, int r,\
    \ int k) {\n    assert(l < r and k <= r - l);\n    std::vector<T> res(r - l);\n\
    \    std::iota(res.begin(), res.end(), T(l));\n    shuffle(res.begin(), res.end());\n\
    \    res.resize(k);\n    return res;\n}\n\n} // namespace random\n\n} // namespace\
    \ kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#line 5 \"template/template.hpp\"\
    \n#include <array>\n#include <bitset>\n#line 9 \"template/template.hpp\"\n#include\
    \ <cmath>\n#include <deque>\n#line 12 \"template/template.hpp\"\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#line 16 \"template/template.hpp\"\n#include\
    \ <optional>\n#include <queue>\n#line 19 \"template/template.hpp\"\n#include <set>\n\
    #include <stack>\n#include <string>\n#include <unordered_map>\n#line 24 \"template/template.hpp\"\
    \n#include <utility>\n#line 26 \"template/template.hpp\"\n\n#line 1 \"template/constant.hpp\"\
    \n\n\n\n#line 1 \"template/type_alias.hpp\"\n\n\n\n#line 8 \"template/type_alias.hpp\"\
    \n\nusing u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi = std::pair<int,\
    \ int>;\nusing pl = std::pair<i64, i64>;\nusing pil = std::pair<int, i64>;\nusing\
    \ pli = std::pair<i64, int>;\n\ntemplate <class T> using vc = std::vector<T>;\n\
    template <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using vvvc\
    \ = std::vector<vvc<T>>;\ntemplate <class T> using vvvvc = std::vector<vvvc<T>>;\n\
    \ntemplate <class T> using pq = std::priority_queue<T>;\ntemplate <class T> using\
    \ pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\n\n#line 5\
    \ \"template/constant.hpp\"\n\ntemplate <class T> constexpr T infty = 0;\ntemplate\
    \ <> constexpr int infty<int> = (1 << 30) - 123;\ntemplate <> constexpr i64 infty<i64>\
    \ = (1ll << 62) - (1ll << 31);\ntemplate <> constexpr i128 infty<i128> = (i128(1)\
    \ << 126) - (i128(1) << 63);\ntemplate <> constexpr u32 infty<u32> = infty<int>;\n\
    template <> constexpr u64 infty<u64> = infty<i64>;\ntemplate <> constexpr u128\
    \ infty<u128> = infty<i128>;\ntemplate <> constexpr double infty<double> = infty<i64>;\n\
    template <> constexpr long double infty<long double> = infty<i64>;\n\nconstexpr\
    \ int mod = 998244353;\nconstexpr int modu = 1e9 + 7;\nconstexpr long double PI\
    \ = 3.14159265358979323846;\n\n\n#line 1 \"template/fastio.hpp\"\n\n\n\n#include\
    \ <cctype>\n#include <cstdint>\n#include <cstdio>\n#include <fstream>\n#include\
    \ <iostream>\n#line 10 \"template/fastio.hpp\"\n\n#line 1 \"type_traits/integral.hpp\"\
    \n\n\n\n#line 5 \"type_traits/integral.hpp\"\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\
    \ntemplate <typename T> using is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value\n                                  or std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T> using is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value\n         \
    \                         or std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_integral =\n    typename std::conditional<std::is_integral<T>::value\
    \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T> using is_signed =\n    typename\
    \ std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n \
    \                             std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
    \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename T>\
    \ using to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
    \                              make_unsigned_int128<T>,\n                    \
    \          typename std::conditional<std::is_signed<T>::value,\n             \
    \                                           std::make_unsigned<T>,\n         \
    \                                               std::common_type<T>>::type>::type;\n\
    \n#else\n\ntemplate <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
    template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
    template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
    template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
    \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
    template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
    template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
    \n} // namespace kk2\n\n\n#line 13 \"template/fastio.hpp\"\n\nnamespace kk2 {\n\
    \nnamespace fastio {\n\nstruct Scanner : type_traits::istream_tag {\n  private:\n\
    \    static constexpr size_t INPUT_BUF = 1 << 17;\n    size_t pos = 0, end = 0;\n\
    \    bool is_eof = false;\n    static char buf[INPUT_BUF];\n    FILE *fp;\n\n\
    \  public:\n    Scanner() : fp(stdin) {}\n\n    Scanner(const char *file) : fp(fopen(file,\
    \ \"r\")) {}\n\n    ~Scanner() {\n        if (fp != stdin) fclose(fp);\n    }\n\
    \n    char now() {\n        if (is_eof) return '\\0';\n        if (pos == end)\
    \ {\n            end = fread(buf, 1, INPUT_BUF, fp);\n            if (end != INPUT_BUF)\
    \ buf[end] = '\\0';\n            if (end == 0) is_eof = true;\n            pos\
    \ = 0;\n        }\n        return buf[pos];\n    }\n\n    void skip_space() {\n\
    \        while (isspace(now())) ++pos;\n    }\n\n    template <class T, is_unsigned_t<T>\
    \ * = nullptr> T next_unsigned_integral() {\n        skip_space();\n        T\
    \ res{};\n        while (isdigit(now())) {\n            res = res * 10 + (now()\
    \ - '0');\n            ++pos;\n        }\n        return res;\n    }\n\n    template\
    \ <class T, is_signed_t<T> * = nullptr> T next_signed_integral() {\n        skip_space();\n\
    \        if (now() == '-') {\n            ++pos;\n            return T(-next_unsigned_integral<typename\
    \ to_unsigned<T>::type>());\n        } else return (T)next_unsigned_integral<typename\
    \ to_unsigned<T>::type>();\n    }\n\n    char next_char() {\n        skip_space();\n\
    \        auto res = now();\n        ++pos;\n        return res;\n    }\n\n   \
    \ std::string next_string() {\n        skip_space();\n        std::string res;\n\
    \        while (true) {\n            char c = now();\n            if (isspace(c)\
    \ or c == '\\0') break;\n            res.push_back(now());\n            ++pos;\n\
    \        }\n        return res;\n    }\n\n    template <class T, is_unsigned_t<T>\
    \ * = nullptr> Scanner &operator>>(T &x) {\n        x = next_unsigned_integral<T>();\n\
    \        return *this;\n    }\n\n    template <class T, is_signed_t<T> * = nullptr>\
    \ Scanner &operator>>(T &x) {\n        x = next_signed_integral<T>();\n      \
    \  return *this;\n    }\n\n    Scanner &operator>>(char &x) {\n        x = next_char();\n\
    \        return *this;\n    }\n\n    Scanner &operator>>(std::string &x) {\n \
    \       x = next_string();\n        return *this;\n    }\n};\n\nstruct endl_struct_t\
    \ {};\n\nstruct Printer : type_traits::ostream_tag {\n  private:\n    static char\
    \ helper[10000][5];\n    static char leading_zero[10000][5];\n    constexpr static\
    \ size_t OUTPUT_BUF = 1 << 17;\n    static char buf[OUTPUT_BUF];\n    size_t pos\
    \ = 0;\n    FILE *fp;\n\n    template <class T> static constexpr void div_mod(T\
    \ &a, T &b, T mod) {\n        a = b / mod;\n        b -= a * mod;\n    }\n\n \
    \   static void init() {\n        buf[0] = '\\0';\n        for (size_t i = 0;\
    \ i < 10000; ++i) {\n            leading_zero[i][0] = i / 1000 + '0';\n      \
    \      leading_zero[i][1] = i / 100 % 10 + '0';\n            leading_zero[i][2]\
    \ = i / 10 % 10 + '0';\n            leading_zero[i][3] = i % 10 + '0';\n     \
    \       leading_zero[i][4] = '\\0';\n\n            size_t j = 0;\n           \
    \ if (i >= 1000) helper[i][j++] = i / 1000 + '0';\n            if (i >= 100) helper[i][j++]\
    \ = i / 100 % 10 + '0';\n            if (i >= 10) helper[i][j++] = i / 10 % 10\
    \ + '0';\n            helper[i][j++] = i % 10 + '0';\n            helper[i][j]\
    \ = '\\0';\n        }\n    }\n\n  public:\n    Printer() : fp(stdout) { init();\
    \ }\n\n    Printer(const char *file) : fp(fopen(file, \"w\")) { init(); }\n\n\
    \    ~Printer() {\n        write();\n        if (fp != stdout) fclose(fp);\n \
    \   }\n\n    void write() {\n        fwrite(buf, 1, pos, fp);\n        pos = 0;\n\
    \    }\n\n    void flush() {\n        write();\n        fflush(fp);\n    }\n\n\
    \    void put_char(char c) {\n        if (pos == OUTPUT_BUF) write();\n      \
    \  buf[pos++] = c;\n    }\n\n    void put_cstr(const char *s) {\n        while\
    \ (*s) put_char(*(s++));\n    }\n\n    void put_u32(uint32_t x) {\n        uint32_t\
    \ y;\n        if (x >= 100000000) { // 10^8\n            div_mod<uint32_t>(y,\
    \ x, 100000000);\n            put_cstr(helper[y]);\n            div_mod<uint32_t>(y,\
    \ x, 10000);\n            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= 10000) { // 10^4\n            div_mod<uint32_t>(y, x,\
    \ 10000);\n            put_cstr(helper[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_cstr(helper[x]);\n    }\n\n    void put_i32(int32_t x) {\n\
    \        if (x < 0) {\n            put_char('-');\n            put_u32(-x);\n\
    \        } else put_u32(x);\n    }\n\n    void put_u64(uint64_t x) {\n       \
    \ uint64_t y;\n        if (x >= 1000000000000ull) { // 10^12\n            div_mod<uint64_t>(y,\
    \ x, 1000000000000ull);\n            put_u32(y);\n            div_mod<uint64_t>(y,\
    \ x, 100000000ull);\n            put_cstr(leading_zero[y]);\n            div_mod<uint64_t>(y,\
    \ x, 10000ull);\n            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= 10000ull) { // 10^4\n            div_mod<uint64_t>(y,\
    \ x, 10000ull);\n            put_u32(y);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_cstr(helper[x]);\n    }\n\n    void put_i64(int64_t x) {\n\
    \        if (x < 0) {\n            put_char('-');\n            put_u64(-x);\n\
    \        } else put_u64(x);\n    }\n\n    void put_u128(__uint128_t x) {\n   \
    \     constexpr static __uint128_t pow10_10 = 10000000000ull;\n        constexpr\
    \ static __uint128_t pow10_20 = pow10_10 * pow10_10;\n\n        __uint128_t y;\n\
    \        if (x >= pow10_20) { // 10^20\n            div_mod<__uint128_t>(y, x,\
    \ pow10_20);\n            put_u64(uint64_t(y));\n            div_mod<__uint128_t>(y,\
    \ x, __uint128_t(10000000000000000ull));\n            put_cstr(leading_zero[y]);\n\
    \            div_mod<__uint128_t>(y, x, __uint128_t(1000000000000ull));\n    \
    \        put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x, __uint128_t(100000000ull));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x,\
    \ __uint128_t(10000ull));\n            put_cstr(leading_zero[y]);\n          \
    \  put_cstr(leading_zero[x]);\n        } else if (x >= __uint128_t(10000)) { //\
    \ 10^4\n            div_mod<__uint128_t>(y, x, __uint128_t(10000));\n        \
    \    put_u64(uint64_t(y));\n            put_cstr(leading_zero[x]);\n        }\
    \ else put_cstr(helper[x]);\n    }\n\n    void put_i128(__int128_t x) {\n    \
    \    if (x < 0) {\n            put_char('-');\n            put_u128(-x);\n   \
    \     } else put_u128(x);\n    }\n\n    template <class T, is_unsigned_t<T> *\
    \ = nullptr> Printer &operator<<(T x) {\n        if constexpr (sizeof(T) <= 4)\
    \ put_u32(x);\n        else if constexpr (sizeof(T) <= 8) put_u64(x);\n      \
    \  else put_u128(x);\n        return *this;\n    }\n\n    template <class T, is_signed_t<T>\
    \ * = nullptr> Printer &operator<<(T x) {\n        if constexpr (sizeof(T) <=\
    \ 4) put_i32(x);\n        else if constexpr (sizeof(T) <= 8) put_i64(x);\n   \
    \     else put_i128(x);\n        return *this;\n    }\n\n    Printer &operator<<(char\
    \ x) {\n        put_char(x);\n        return *this;\n    }\n\n    Printer &operator<<(const\
    \ std::string &x) {\n        for (char c : x) put_char(c);\n        return *this;\n\
    \    }\n\n    Printer &operator<<(const char *x) {\n        put_cstr(x);\n   \
    \     return *this;\n    }\n\n    // std::cout << std::endl; \u306F\u95A2\u6570\
    \u30DD\u30A4\u30F3\u30BF\u3092\u6E21\u3057\u3066\u3044\u308B\u3089\u3057\u3044\
    \n    Printer &operator<<(endl_struct_t) {\n        put_char('\\n');\n       \
    \ flush();\n        return *this;\n    }\n};\n\nchar Scanner::buf[Scanner::INPUT_BUF];\n\
    char Printer::buf[Printer::OUTPUT_BUF];\nchar Printer::helper[10000][5];\nchar\
    \ Printer::leading_zero[10000][5];\n\n} // namespace fastio\n\n#if defined(INTERACTIVE)\
    \ || defined(USE_STDIO)\nauto &kin = std::cin;\nauto &kout = std::cout;\nauto\
    \ (*kendl)(std::ostream &) = std::endl<char, std::char_traits<char>>;\n#else\n\
    fastio::Scanner kin;\nfastio::Printer kout;\nfastio::endl_struct_t kendl;\n#endif\n\
    \n} // namespace kk2\n\n\n#line 1 \"template/io_util.hpp\"\n\n\n\n#line 7 \"template/io_util.hpp\"\
    \n\n#line 9 \"template/io_util.hpp\"\n\n// \u306A\u3093\u304Boj verify\u306F\u30D7\
    \u30ED\u30C8\u30BF\u30A4\u30D7\u5BA3\u8A00\u304C\u843D\u3061\u308B\n\nnamespace\
    \ impl {\n\nstruct read {\n    template <class IStream, class T> inline static\
    \ void all_read(IStream &is, T &x) { is >> x; }\n\n    template <class IStream,\
    \ class T, class U>\n    inline static void all_read(IStream &is, std::pair<T,\
    \ U> &p) {\n        all_read(is, p.first);\n        all_read(is, p.second);\n\
    \    }\n\n    template <class IStream, class T> inline static void all_read(IStream\
    \ &is, std::vector<T> &v) {\n        for (T &x : v) all_read(is, x);\n    }\n\n\
    \    template <class IStream, class T, size_t F>\n    inline static void all_read(IStream\
    \ &is, std::array<T, F> &a) {\n        for (T &x : a) all_read(is, x);\n    }\n\
    };\n\nstruct write {\n    template <class OStream, class T> inline static void\
    \ all_write(OStream &os, const T &x) {\n        os << x;\n    }\n\n    template\
    \ <class OStream, class T, class U>\n    inline static void all_write(OStream\
    \ &os, const std::pair<T, U> &p) {\n        all_write(os, p.first);\n        all_write(os,\
    \ ' ');\n        all_write(os, p.second);\n    }\n\n    template <class OStream,\
    \ class T>\n    inline static void all_write(OStream &os, const std::vector<T>\
    \ &v) {\n        for (int i = 0; i < (int)v.size(); ++i) {\n            if (i)\
    \ all_write(os, ' ');\n            all_write(os, v[i]);\n        }\n    }\n\n\
    \    template <class OStream, class T, size_t F>\n    inline static void all_write(OStream\
    \ &os, const std::array<T, F> &a) {\n        for (int i = 0; i < (int)F; ++i)\
    \ {\n            if (i) all_write(os, ' ');\n            all_write(os, a[i]);\n\
    \        }\n    }\n};\n\n} // namespace impl\n\ntemplate <class IStream, class\
    \ T, class U, kk2::is_istream_t<IStream> * = nullptr>\nIStream &operator>>(IStream\
    \ &is, std::pair<T, U> &p) {\n    impl::read::all_read(is, p);\n    return is;\n\
    }\n\ntemplate <class IStream, class T, kk2::is_istream_t<IStream> * = nullptr>\n\
    IStream &operator>>(IStream &is, std::vector<T> &v) {\n    impl::read::all_read(is,\
    \ v);\n    return is;\n}\n\ntemplate <class IStream, class T, size_t F, kk2::is_istream_t<IStream>\
    \ * = nullptr>\nIStream &operator>>(IStream &is, std::array<T, F> &a) {\n    impl::read::all_read(is,\
    \ a);\n    return is;\n}\n\ntemplate <class OStream, class T, class U, kk2::is_ostream_t<OStream>\
    \ * = nullptr>\nOStream &operator<<(OStream &os, const std::pair<T, U> &p) {\n\
    \    impl::write::all_write(os, p);\n    return os;\n}\n\ntemplate <class OStream,\
    \ class T, kk2::is_ostream_t<OStream> * = nullptr>\nOStream &operator<<(OStream\
    \ &os, const std::vector<T> &v) {\n    impl::write::all_write(os, v);\n    return\
    \ os;\n}\n\ntemplate <class OStream, class T, size_t F, kk2::is_ostream_t<OStream>\
    \ * = nullptr>\nOStream &operator<<(OStream &os, const std::array<T, F> &a) {\n\
    \    impl::write::all_write(os, a);\n    return os;\n}\n\n\n#line 1 \"template/macros.hpp\"\
    \n\n\n\n#define rep1(a) for (long long _ = 0; _ < (long long)(a); ++_)\n#define\
    \ rep2(i, a) for (long long i = 0; i < (long long)(a); ++i)\n#define rep3(i, a,\
    \ b) for (long long i = (a); i < (long long)(b); ++i)\n#define repi2(i, a) for\
    \ (long long i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (long long\
    \ i = (a) - 1; i >= (long long)(b); --i)\n#define overload3(a, b, c, d, ...) d\n\
    #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define\
    \ repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n#define\
    \ fi first\n#define se second\n#define all(p) begin(p), end(p)\n\n\n#line 32 \"\
    template/template.hpp\"\n\nusing kk2::kendl;\nusing kk2::kin;\nusing kk2::kout;\n\
    \nvoid Yes(bool b = 1) { kout << (b ? \"Yes\\n\" : \"No\\n\"); }\nvoid No(bool\
    \ b = 1) { kout << (b ? \"No\\n\" : \"Yes\\n\"); }\nvoid YES(bool b = 1) { kout\
    \ << (b ? \"YES\\n\" : \"NO\\n\"); }\nvoid NO(bool b = 1) { kout << (b ? \"NO\\\
    n\" : \"YES\\n\"); }\nvoid yes(bool b = 1) { kout << (b ? \"yes\\n\" : \"no\\\
    n\"); }\nvoid no(bool b = 1) { kout << (b ? \"no\\n\" : \"yes\\n\"); }\ntemplate\
    \ <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a =\
    \ b, 1 : 0); }\ntemplate <class T, class S> inline bool chmin(T &a, const S &b)\
    \ { return (a > b ? a = b, 1 : 0); }\n\n\n#line 11 \"verify/unit_test/math/monoid/monoid.test.cpp\"\
    \nusing namespace std;\n\nvoid test_monoid() {\n    // Update monoid test\n  \
    \  {\n        using M = kk2::monoid::Update<int>;\n        M unit = M::unit();\n\
    \n        rep(10000) {\n            int val1 = kk2::random::rng(1, 1001);\n  \
    \          int val2 = kk2::random::rng(1, 1001);\n            M a(val1), b(val2);\n\
    \n            assert(M::op(unit, a) == a);\n            assert(M::op(a, unit)\
    \ == a);\n            assert(M::op(a, b) == a); // \u5DE6\u5074\u3092\u4FDD\u6301\
    \n            assert(M::op(b, a) == b);\n        }\n        cerr << \"Update:\
    \ 10000 random tests passed!\" << endl;\n    }\n\n    // Min monoid test\n   \
    \ {\n        using M = kk2::monoid::Min<int>;\n        M unit = M::unit();\n\n\
    \        rep(10000) {\n            int val1 = kk2::random::rng(1, 1001);\n   \
    \         int val2 = kk2::random::rng(1, 1001);\n            int val3 = kk2::random::rng(1,\
    \ 1001);\n            M a(val1), b(val2), c(val3);\n\n            assert(M::op(unit,\
    \ a) == a);\n            assert(M::op(a, unit) == a);\n\n            // min\u6F14\
    \u7B97\u306E\u691C\u8A3C\n            int min_ab = min(val1, val2);\n        \
    \    int min_bc = min(val2, val3);\n            int min_ac = min(val1, val3);\n\
    \            assert(M::op(a, b).a == min_ab);\n            assert(M::op(b, c).a\
    \ == min_bc);\n            assert(M::op(a, c).a == min_ac);\n\n            //\
    \ \u7D50\u5408\u5F8B\u306E\u691C\u8A3C\n            assert(M::op(M::op(a, b),\
    \ c) == M::op(a, M::op(b, c)));\n        }\n        cerr << \"Min: 10000 random\
    \ tests passed!\" << endl;\n    }\n\n    // Max monoid test\n    {\n        using\
    \ M = kk2::monoid::Max<int>;\n        M unit = M::unit();\n\n        rep(10000)\
    \ {\n            int val1 = kk2::random::rng(1, 1001);\n            int val2 =\
    \ kk2::random::rng(1, 1001);\n            int val3 = kk2::random::rng(1, 1001);\n\
    \            M a(val1), b(val2), c(val3);\n\n            assert(M::op(unit, a)\
    \ == a);\n            assert(M::op(a, unit) == a);\n\n            // max\u6F14\
    \u7B97\u306E\u691C\u8A3C\n            int max_ab = max(val1, val2);\n        \
    \    int max_bc = max(val2, val3);\n            int max_ac = max(val1, val3);\n\
    \            assert(M::op(a, b).a == max_ab);\n            assert(M::op(b, c).a\
    \ == max_bc);\n            assert(M::op(a, c).a == max_ac);\n\n            //\
    \ \u7D50\u5408\u5F8B\u306E\u691C\u8A3C\n            assert(M::op(M::op(a, b),\
    \ c) == M::op(a, M::op(b, c)));\n        }\n        cerr << \"Max: 10000 random\
    \ tests passed!\" << endl;\n    }\n\n    // MaxMinSumWithSize test\n    {\n  \
    \      using M = kk2::monoid::MaxMinSumWithSize<int, int>;\n        M unit = M::unit();\n\
    \n        rep(10000) {\n            int val1 = kk2::random::rng(1, 1001);\n  \
    \          int val2 = kk2::random::rng(1, 1001);\n            M a(val1), b(val2);\n\
    \n            assert(M::op(unit, a) == a);\n\n            auto ab = M::op(a, b);\n\
    \            assert(ab.max == max(val1, val2));\n            assert(ab.min ==\
    \ min(val1, val2));\n            assert(ab.sum == val1 + val2);\n            assert(ab.size\
    \ == 2);\n        }\n        cerr << \"MaxMinSumWithSize: 10000 random tests passed!\"\
    \ << endl;\n    }\n\n    // Hold monoid test\n    {\n        using M = kk2::monoid::Hold<int>;\n\
    \        M unit = M::unit();\n\n        rep(10000) {\n            int val1 = kk2::random::rng(1,\
    \ 1001);\n            int val2 = kk2::random::rng(1, 1001);\n            M a(val1),\
    \ b(val2);\n\n            assert(M::op(unit, a) == a);\n            assert(M::op(a,\
    \ unit) == a);\n            assert(M::op(a, b) == b); // \u53F3\u5074\u3092\u4FDD\
    \u6301\n            assert(M::op(b, a) == a);\n        }\n        cerr << \"Hold:\
    \ 10000 random tests passed!\" << endl;\n    }\n\n    // Affine monoid test\n\
    \    {\n        using M = kk2::monoid::Affine<int>;\n        M unit = M::unit();\n\
    \n        rep(10000) {\n            int a1 = kk2::random::rng(1, 11), b1 = kk2::random::rng(1,\
    \ 11);\n            int a2 = kk2::random::rng(1, 11), b2 = kk2::random::rng(1,\
    \ 11);\n            int x = kk2::random::rng(1, 101);\n\n            M f(a1, b1),\
    \ g(a2, b2);\n\n            assert(M::op(unit, f) == f);\n            assert(M::op(f,\
    \ unit) == f);\n\n            assert(f.eval(x) == a1 * x + b1);\n            assert(g.eval(x)\
    \ == a2 * x + b2);\n\n            // \u5408\u6210\u306E\u691C\u8A3C f(g(x)) =\
    \ f(a2*x + b2) = a1*(a2*x + b2) + b1 = a1*a2*x + a1*b2 + b1\n            auto\
    \ fg = M::op(f, g);\n            assert(fg.a == a1 * a2);\n            assert(fg.b\
    \ == a1 * b2 + b1);\n            assert(fg.eval(x) == a1 * (a2 * x + b2) + b1);\n\
    \n            // \u7D50\u5408\u5F8B\u306E\u691C\u8A3C\n            int a3 = kk2::random::rng(1,\
    \ 11), b3 = kk2::random::rng(1, 11);\n            M h(a3, b3);\n            assert(M::op(M::op(f,\
    \ g), h) == M::op(f, M::op(g, h)));\n        }\n        cerr << \"Affine: 10000\
    \ random tests passed!\" << endl;\n    }\n}\n\n\n\nvoid test() {\n    test_monoid();\n\
    \n    // \u5168\u30C6\u30B9\u30C8\u901A\u904E\n    cerr << \"All monoid tests\
    \ passed!\" << endl;\n}\n\nint main() {\n    int a, b;\n    kin >> a >> b;\n \
    \   kout << a + b << kendl;\n\n    test();\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../../math/monoid/affine.hpp\"\n#include \"../../../../math/monoid/hold.hpp\"\
    \n#include \"../../../../math/monoid/max.hpp\"\n#include \"../../../../math/monoid/max_min_sumwithsize.hpp\"\
    \n#include \"../../../../math/monoid/min.hpp\"\n#include \"../../../../math/monoid/update.hpp\"\
    \n#include \"../../../../random/gen.hpp\"\n#include \"../../../../template/template.hpp\"\
    \nusing namespace std;\n\nvoid test_monoid() {\n    // Update monoid test\n  \
    \  {\n        using M = kk2::monoid::Update<int>;\n        M unit = M::unit();\n\
    \n        rep(10000) {\n            int val1 = kk2::random::rng(1, 1001);\n  \
    \          int val2 = kk2::random::rng(1, 1001);\n            M a(val1), b(val2);\n\
    \n            assert(M::op(unit, a) == a);\n            assert(M::op(a, unit)\
    \ == a);\n            assert(M::op(a, b) == a); // \u5DE6\u5074\u3092\u4FDD\u6301\
    \n            assert(M::op(b, a) == b);\n        }\n        cerr << \"Update:\
    \ 10000 random tests passed!\" << endl;\n    }\n\n    // Min monoid test\n   \
    \ {\n        using M = kk2::monoid::Min<int>;\n        M unit = M::unit();\n\n\
    \        rep(10000) {\n            int val1 = kk2::random::rng(1, 1001);\n   \
    \         int val2 = kk2::random::rng(1, 1001);\n            int val3 = kk2::random::rng(1,\
    \ 1001);\n            M a(val1), b(val2), c(val3);\n\n            assert(M::op(unit,\
    \ a) == a);\n            assert(M::op(a, unit) == a);\n\n            // min\u6F14\
    \u7B97\u306E\u691C\u8A3C\n            int min_ab = min(val1, val2);\n        \
    \    int min_bc = min(val2, val3);\n            int min_ac = min(val1, val3);\n\
    \            assert(M::op(a, b).a == min_ab);\n            assert(M::op(b, c).a\
    \ == min_bc);\n            assert(M::op(a, c).a == min_ac);\n\n            //\
    \ \u7D50\u5408\u5F8B\u306E\u691C\u8A3C\n            assert(M::op(M::op(a, b),\
    \ c) == M::op(a, M::op(b, c)));\n        }\n        cerr << \"Min: 10000 random\
    \ tests passed!\" << endl;\n    }\n\n    // Max monoid test\n    {\n        using\
    \ M = kk2::monoid::Max<int>;\n        M unit = M::unit();\n\n        rep(10000)\
    \ {\n            int val1 = kk2::random::rng(1, 1001);\n            int val2 =\
    \ kk2::random::rng(1, 1001);\n            int val3 = kk2::random::rng(1, 1001);\n\
    \            M a(val1), b(val2), c(val3);\n\n            assert(M::op(unit, a)\
    \ == a);\n            assert(M::op(a, unit) == a);\n\n            // max\u6F14\
    \u7B97\u306E\u691C\u8A3C\n            int max_ab = max(val1, val2);\n        \
    \    int max_bc = max(val2, val3);\n            int max_ac = max(val1, val3);\n\
    \            assert(M::op(a, b).a == max_ab);\n            assert(M::op(b, c).a\
    \ == max_bc);\n            assert(M::op(a, c).a == max_ac);\n\n            //\
    \ \u7D50\u5408\u5F8B\u306E\u691C\u8A3C\n            assert(M::op(M::op(a, b),\
    \ c) == M::op(a, M::op(b, c)));\n        }\n        cerr << \"Max: 10000 random\
    \ tests passed!\" << endl;\n    }\n\n    // MaxMinSumWithSize test\n    {\n  \
    \      using M = kk2::monoid::MaxMinSumWithSize<int, int>;\n        M unit = M::unit();\n\
    \n        rep(10000) {\n            int val1 = kk2::random::rng(1, 1001);\n  \
    \          int val2 = kk2::random::rng(1, 1001);\n            M a(val1), b(val2);\n\
    \n            assert(M::op(unit, a) == a);\n\n            auto ab = M::op(a, b);\n\
    \            assert(ab.max == max(val1, val2));\n            assert(ab.min ==\
    \ min(val1, val2));\n            assert(ab.sum == val1 + val2);\n            assert(ab.size\
    \ == 2);\n        }\n        cerr << \"MaxMinSumWithSize: 10000 random tests passed!\"\
    \ << endl;\n    }\n\n    // Hold monoid test\n    {\n        using M = kk2::monoid::Hold<int>;\n\
    \        M unit = M::unit();\n\n        rep(10000) {\n            int val1 = kk2::random::rng(1,\
    \ 1001);\n            int val2 = kk2::random::rng(1, 1001);\n            M a(val1),\
    \ b(val2);\n\n            assert(M::op(unit, a) == a);\n            assert(M::op(a,\
    \ unit) == a);\n            assert(M::op(a, b) == b); // \u53F3\u5074\u3092\u4FDD\
    \u6301\n            assert(M::op(b, a) == a);\n        }\n        cerr << \"Hold:\
    \ 10000 random tests passed!\" << endl;\n    }\n\n    // Affine monoid test\n\
    \    {\n        using M = kk2::monoid::Affine<int>;\n        M unit = M::unit();\n\
    \n        rep(10000) {\n            int a1 = kk2::random::rng(1, 11), b1 = kk2::random::rng(1,\
    \ 11);\n            int a2 = kk2::random::rng(1, 11), b2 = kk2::random::rng(1,\
    \ 11);\n            int x = kk2::random::rng(1, 101);\n\n            M f(a1, b1),\
    \ g(a2, b2);\n\n            assert(M::op(unit, f) == f);\n            assert(M::op(f,\
    \ unit) == f);\n\n            assert(f.eval(x) == a1 * x + b1);\n            assert(g.eval(x)\
    \ == a2 * x + b2);\n\n            // \u5408\u6210\u306E\u691C\u8A3C f(g(x)) =\
    \ f(a2*x + b2) = a1*(a2*x + b2) + b1 = a1*a2*x + a1*b2 + b1\n            auto\
    \ fg = M::op(f, g);\n            assert(fg.a == a1 * a2);\n            assert(fg.b\
    \ == a1 * b2 + b1);\n            assert(fg.eval(x) == a1 * (a2 * x + b2) + b1);\n\
    \n            // \u7D50\u5408\u5F8B\u306E\u691C\u8A3C\n            int a3 = kk2::random::rng(1,\
    \ 11), b3 = kk2::random::rng(1, 11);\n            M h(a3, b3);\n            assert(M::op(M::op(f,\
    \ g), h) == M::op(f, M::op(g, h)));\n        }\n        cerr << \"Affine: 10000\
    \ random tests passed!\" << endl;\n    }\n}\n\n\n\nvoid test() {\n    test_monoid();\n\
    \n    // \u5168\u30C6\u30B9\u30C8\u901A\u904E\n    cerr << \"All monoid tests\
    \ passed!\" << endl;\n}\n\nint main() {\n    int a, b;\n    kin >> a >> b;\n \
    \   kout << a + b << kendl;\n\n    test();\n\n    return 0;\n}\n"
  dependsOn:
  - math/monoid/affine.hpp
  - type_traits/io.hpp
  - math/monoid/hold.hpp
  - math/monoid/max.hpp
  - math/monoid/max_min_sumwithsize.hpp
  - math/monoid/min.hpp
  - math/monoid/update.hpp
  - random/gen.hpp
  - random/seed.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/unit_test/math/monoid/monoid.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math/monoid/monoid.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/monoid/monoid.test.cpp
- /verify/verify/unit_test/math/monoid/monoid.test.cpp.html
title: verify/unit_test/math/monoid/monoid.test.cpp
---
