---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/monoid/max.hpp
    title: math/monoid/max.hpp
  - icon: ':question:'
    path: math/monoid/min.hpp
    title: math/monoid/min.hpp
  - icon: ':question:'
    path: type_traits/container_traits.hpp
    title: type_traits/container_traits.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: template/procon.hpp
    title: template/procon.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
    title: verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/function_util.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <vector>\n\n#line 1 \"math/monoid/max.hpp\"\n\n\n\n#include <functional>\n\
    \n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n#include <ostream>\n\
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
    \ kk2\n\n\n#line 7 \"math/monoid/max.hpp\"\n\nnamespace kk2 {\n\nnamespace monoid\
    \ {\n\ntemplate <class S, class Compare = std::less<S>> struct Max {\n    static\
    \ constexpr bool commutative = true;\n    using M = Max;\n    S a;\n    bool is_unit;\n\
    \n    Max() : a(S()), is_unit(true) {}\n    Max(S a_) : a(a_), is_unit(false)\
    \ {}\n    operator S() const { return a; }\n\n    inline static M op(M l, M r)\
    \ {\n        if (l.is_unit or r.is_unit) return l.is_unit ? r : l;\n        return\
    \ Compare{}(l.a, r.a) ? r : l;\n    }\n\n    inline static M unit() { return M();\
    \ }\n\n    bool operator==(const M &rhs) const {\n        return is_unit == rhs.is_unit\
    \ and (is_unit or a == rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const\
    \ {\n        return is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n   \
    \ }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend\
    \ OStream &operator<<(OStream &os, const M &x) {\n        if (x.is_unit) os <<\
    \ \"-inf\";\n        else os << x.a;\n        return os;\n    }\n\n    template\
    \ <class IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, M &x) {\n        is >> x.a;\n        x.is_unit = false;\n        return\
    \ is;\n    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\n\n#line 1 \"\
    math/monoid/min.hpp\"\n\n\n\n#line 5 \"math/monoid/min.hpp\"\n\n#line 7 \"math/monoid/min.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace monoid {\n\ntemplate <class S, class Compare\
    \ = std::less<S>> struct Min {\n    static constexpr bool commutative = true;\n\
    \    using M = Min;\n    S a;\n    bool is_unit;\n\n    Min() : a(S()), is_unit(true)\
    \ {}\n    Min(S a_) : a(a_), is_unit(false) {}\n    operator S() const { return\
    \ a; }\n\n    inline static M op(M l, M r) {\n        if (l.is_unit or r.is_unit)\
    \ return l.is_unit ? r : l;\n        return Compare{}(l.a, r.a) ? l : r;\n   \
    \ }\n\n    inline static M unit() { return M(); }\n\n    bool operator==(const\
    \ M &rhs) const {\n        return is_unit == rhs.is_unit and (is_unit or a ==\
    \ rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const {\n        return\
    \ is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const M &x) {\n        if (x.is_unit) os << \"inf\";\n        else os <<\
    \ x.a;\n        return os;\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    friend IStream &operator>>(IStream &is, M &x) {\n        is\
    \ >> x.a;\n        x.is_unit = false;\n        return is;\n    }\n};\n\n} // namespace\
    \ monoid\n\n} // namespace kk2\n\n\n#line 1 \"type_traits/container_traits.hpp\"\
    \n\n\n\n#include <array>\n#include <deque>\n#include <list>\n#include <string>\n\
    #line 10 \"type_traits/container_traits.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename\
    \ T> struct is_vector : std::false_type {};\ntemplate <typename T, typename Alloc>\
    \ struct is_vector<std::vector<T, Alloc>> : std::true_type {};\n\ntemplate <typename\
    \ T> struct is_container : std::false_type {};\ntemplate <typename T, typename\
    \ Alloc> struct is_container<std::vector<T, Alloc>> : std::true_type {\n};\ntemplate\
    \ <typename CharT, typename Traits, typename Alloc>\nstruct is_container<std::basic_string<CharT,\
    \ Traits, Alloc>> : std::true_type {};\ntemplate <typename T, std::size_t N> struct\
    \ is_container<std::array<T, N>> : std::true_type {};\ntemplate <typename T, typename\
    \ Alloc> struct is_container<std::deque<T, Alloc>> : std::true_type {};\ntemplate\
    \ <typename T, typename Alloc> struct is_container<std::list<T, Alloc>> : std::true_type\
    \ {};\ntemplate <typename T> using is_container_t = typename std::enable_if_t<is_container<T>::value>;\n\
    \n} // namespace kk2\n\n\n#line 10 \"template/function_util.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class T, class... Sizes> auto make_vector(int first, Sizes...\
    \ sizes) {\n    if constexpr (sizeof...(sizes) == 0) {\n        return std::vector<T>(first);\n\
    \    } else {\n        return std::vector<decltype(make_vector<T>(sizes...))>(first,\
    \ make_vector<T>(sizes...));\n    }\n}\n\ntemplate <class T, class U> void fill_all(std::vector<T>\
    \ &v, const U &x) {\n    if constexpr (is_vector<T>::value) {\n        for (auto\
    \ &u : v) fill_all(u, x);\n    } else {\n        std::fill(v.begin(), v.end(),\
    \ T(x));\n    }\n}\n\ntemplate <class T, class U> int iota_all(std::vector<T>\
    \ &v, U x, int offset = 0) {\n    if constexpr (is_vector<T>::value) {\n     \
    \   for (auto &u : v) offset += iota_all(u, x + offset);\n    } else {\n     \
    \   for (auto &u : v) u = x++, ++offset;\n    }\n    return offset;\n}\n\ntemplate\
    \ <class C> int mysize(const C &c) { return size(c); }\n\n\n// T: commutative\
    \ monoid, F: (U, T) -> U\ntemplate <class U, class T, class F>\nU all_monoid_prod(const\
    \ std::vector<T> &v, U unit, const F &f) {\n    U res = unit;\n    if constexpr\
    \ (is_vector<T>::value) {\n        for (const auto &x : v) res = f(res, all_monoid_prod(x,\
    \ unit, f));\n    } else {\n        for (const auto &x : v) res = f(res, x);\n\
    \    }\n    return res;\n}\n\ntemplate <class U, class T> U all_sum(const std::vector<T>\
    \ &v, U unit = U()) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return a + b; });\n}\ntemplate <class U, class T> U all_prod(const std::vector<T>\
    \ &v, U unit = U(1)) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return a * b; });\n}\ntemplate <class U, class T> U all_xor(const std::vector<T>\
    \ &v, U unit = U()) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return a ^ b; });\n}\ntemplate <class U, class T> U all_and(const std::vector<T>\
    \ &v, U unit = U(-1)) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return a & b; });\n}\ntemplate <class U, class T> U all_or(const std::vector<T>\
    \ &v, U unit = U()) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return a | b; });\n}\ntemplate <class U, class T> U all_min(const std::vector<T>\
    \ &v) {\n    return all_monoid_prod<monoid::Min<U>, T>(v, monoid::Min<U>::unit(),\
    \ monoid::Min<U>::op);\n}\ntemplate <class U, class T> U all_max(const std::vector<T>\
    \ &v) {\n    return all_monoid_prod<monoid::Max<U>, T>(v, monoid::Max<U>::unit(),\
    \ monoid::Max<U>::op);\n}\ntemplate <class U, class T> U all_gcd(const std::vector<T>\
    \ &v, U unit = U()) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return std::gcd(a, b); });\n}\ntemplate <class U, class T> U all_lcm(const\
    \ std::vector<T> &v, U unit = U(1)) {\n    return all_monoid_prod<U, T>(v, unit,\
    \ [](U a, U b) { return std::lcm(a, b); });\n}\ntemplate <class U, class T> int\
    \ all_count(const std::vector<T> &v, U x) {\n    return all_monoid_prod<int, T>(v,\
    \ 0, [x](int a, U y) { return a + int(x == y); });\n}\n\n} // namespace kk2\n\n\
    \n"
  code: "#ifndef KK2_TEMPLATE_FUNCTION_UTIL_HPP\n#define KK2_TEMPLATE_FUNCTION_UTIL_HPP\
    \ 1\n\n#include <algorithm>\n#include <vector>\n\n#include \"../math/monoid/max.hpp\"\
    \n#include \"../math/monoid/min.hpp\"\n#include \"../type_traits/container_traits.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class T, class... Sizes> auto make_vector(int\
    \ first, Sizes... sizes) {\n    if constexpr (sizeof...(sizes) == 0) {\n     \
    \   return std::vector<T>(first);\n    } else {\n        return std::vector<decltype(make_vector<T>(sizes...))>(first,\
    \ make_vector<T>(sizes...));\n    }\n}\n\ntemplate <class T, class U> void fill_all(std::vector<T>\
    \ &v, const U &x) {\n    if constexpr (is_vector<T>::value) {\n        for (auto\
    \ &u : v) fill_all(u, x);\n    } else {\n        std::fill(v.begin(), v.end(),\
    \ T(x));\n    }\n}\n\ntemplate <class T, class U> int iota_all(std::vector<T>\
    \ &v, U x, int offset = 0) {\n    if constexpr (is_vector<T>::value) {\n     \
    \   for (auto &u : v) offset += iota_all(u, x + offset);\n    } else {\n     \
    \   for (auto &u : v) u = x++, ++offset;\n    }\n    return offset;\n}\n\ntemplate\
    \ <class C> int mysize(const C &c) { return size(c); }\n\n\n// T: commutative\
    \ monoid, F: (U, T) -> U\ntemplate <class U, class T, class F>\nU all_monoid_prod(const\
    \ std::vector<T> &v, U unit, const F &f) {\n    U res = unit;\n    if constexpr\
    \ (is_vector<T>::value) {\n        for (const auto &x : v) res = f(res, all_monoid_prod(x,\
    \ unit, f));\n    } else {\n        for (const auto &x : v) res = f(res, x);\n\
    \    }\n    return res;\n}\n\ntemplate <class U, class T> U all_sum(const std::vector<T>\
    \ &v, U unit = U()) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return a + b; });\n}\ntemplate <class U, class T> U all_prod(const std::vector<T>\
    \ &v, U unit = U(1)) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return a * b; });\n}\ntemplate <class U, class T> U all_xor(const std::vector<T>\
    \ &v, U unit = U()) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return a ^ b; });\n}\ntemplate <class U, class T> U all_and(const std::vector<T>\
    \ &v, U unit = U(-1)) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return a & b; });\n}\ntemplate <class U, class T> U all_or(const std::vector<T>\
    \ &v, U unit = U()) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return a | b; });\n}\ntemplate <class U, class T> U all_min(const std::vector<T>\
    \ &v) {\n    return all_monoid_prod<monoid::Min<U>, T>(v, monoid::Min<U>::unit(),\
    \ monoid::Min<U>::op);\n}\ntemplate <class U, class T> U all_max(const std::vector<T>\
    \ &v) {\n    return all_monoid_prod<monoid::Max<U>, T>(v, monoid::Max<U>::unit(),\
    \ monoid::Max<U>::op);\n}\ntemplate <class U, class T> U all_gcd(const std::vector<T>\
    \ &v, U unit = U()) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return std::gcd(a, b); });\n}\ntemplate <class U, class T> U all_lcm(const\
    \ std::vector<T> &v, U unit = U(1)) {\n    return all_monoid_prod<U, T>(v, unit,\
    \ [](U a, U b) { return std::lcm(a, b); });\n}\ntemplate <class U, class T> int\
    \ all_count(const std::vector<T> &v, U x) {\n    return all_monoid_prod<int, T>(v,\
    \ 0, [x](int a, U y) { return a + int(x == y); });\n}\n\n} // namespace kk2\n\n\
    #endif // KK2_TEMPLATE_FUNCTION_UTIL_HPP\n"
  dependsOn:
  - math/monoid/max.hpp
  - type_traits/io.hpp
  - math/monoid/min.hpp
  - type_traits/container_traits.hpp
  isVerificationFile: false
  path: template/function_util.hpp
  requiredBy:
  - template/procon.hpp
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
documentation_of: template/function_util.hpp
layout: document
redirect_from:
- /library/template/function_util.hpp
- /library/template/function_util.hpp.html
title: template/function_util.hpp
---
