---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/procon.hpp
    title: template/procon.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/function_util.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <vector>\n\nnamespace kk2 {\n\ntemplate <class T, class... Sizes> auto\
    \ make_vector(int first, Sizes... sizes) {\n    if constexpr (sizeof...(sizes)\
    \ == 0) {\n        return std::vector<T>(first);\n    } else {\n        return\
    \ std::vector<decltype(make_vector<T>(sizes...))>(first, make_vector<T>(sizes...));\n\
    \    }\n}\n\ntemplate <class T, class U> void fill_all(std::vector<T> &v, const\
    \ U &x) {\n    std::fill(std::begin(v), std::end(v), T(x));\n}\n\ntemplate <class\
    \ T, class U> void fill_all(std::vector<std::vector<T>> &v, const U &x) {\n  \
    \  for (auto &u : v) fill_all(u, x);\n}\n\ntemplate <class C> int mysize(const\
    \ C &c) { return size(c); }\n\n// T: comutative monoid\ntemplate <class T, class\
    \ U> U all_sum(const std::vector<T> &v, U unit = U()) {\n    U res = unit;\n \
    \   for (const auto &x : v) res += x;\n    return res;\n}\n\ntemplate <class T,\
    \ class U> U all_sum(const std::vector<std::vector<T>> &v, U unit = U()) {\n \
    \   U res = unit;\n    for (const auto &u : v) res += all_sum(u, unit);\n    return\
    \ res;\n}\n\n// T: commutative monoid, F: (U, T) -> U\ntemplate <class T, class\
    \ U, class F>\nU all_monoid_prod(const std::vector<T> &v, U unit, const F &f)\
    \ {\n    U res = unit;\n    for (const auto &x : v) res = f(res, x);\n    return\
    \ res;\n}\n\ntemplate <class T, class U, class F>\nU all_monoid_prod(const std::vector<std::vector<T>>\
    \ &v, U unit, const F &f) {\n    U res = unit;\n    for (const auto &u : v) res\
    \ = f(res, all_monoid_prod(u, unit, f));\n    return res;\n}\n\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_TEMPLATE_FUNCTION_UTIL_HPP\n#define KK2_TEMPLATE_FUNCTION_UTIL_HPP\
    \ 1\n\n#include <algorithm>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate\
    \ <class T, class... Sizes> auto make_vector(int first, Sizes... sizes) {\n  \
    \  if constexpr (sizeof...(sizes) == 0) {\n        return std::vector<T>(first);\n\
    \    } else {\n        return std::vector<decltype(make_vector<T>(sizes...))>(first,\
    \ make_vector<T>(sizes...));\n    }\n}\n\ntemplate <class T, class U> void fill_all(std::vector<T>\
    \ &v, const U &x) {\n    std::fill(std::begin(v), std::end(v), T(x));\n}\n\ntemplate\
    \ <class T, class U> void fill_all(std::vector<std::vector<T>> &v, const U &x)\
    \ {\n    for (auto &u : v) fill_all(u, x);\n}\n\ntemplate <class C> int mysize(const\
    \ C &c) { return size(c); }\n\n// T: comutative monoid\ntemplate <class T, class\
    \ U> U all_sum(const std::vector<T> &v, U unit = U()) {\n    U res = unit;\n \
    \   for (const auto &x : v) res += x;\n    return res;\n}\n\ntemplate <class T,\
    \ class U> U all_sum(const std::vector<std::vector<T>> &v, U unit = U()) {\n \
    \   U res = unit;\n    for (const auto &u : v) res += all_sum(u, unit);\n    return\
    \ res;\n}\n\n// T: commutative monoid, F: (U, T) -> U\ntemplate <class T, class\
    \ U, class F>\nU all_monoid_prod(const std::vector<T> &v, U unit, const F &f)\
    \ {\n    U res = unit;\n    for (const auto &x : v) res = f(res, x);\n    return\
    \ res;\n}\n\ntemplate <class T, class U, class F>\nU all_monoid_prod(const std::vector<std::vector<T>>\
    \ &v, U unit, const F &f) {\n    U res = unit;\n    for (const auto &u : v) res\
    \ = f(res, all_monoid_prod(u, unit, f));\n    return res;\n}\n\n\n} // namespace\
    \ kk2\n\n#endif // KK2_TEMPLATE_FUNCTION_UTIL_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: template/function_util.hpp
  requiredBy:
  - template/procon.hpp
  timestamp: '2025-04-05 10:48:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/function_util.hpp
layout: document
redirect_from:
- /library/template/function_util.hpp
- /library/template/function_util.hpp.html
title: template/function_util.hpp
---
