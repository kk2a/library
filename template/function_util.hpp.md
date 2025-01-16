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
    \ C &c) {\n    return c.size();\n}\n\n// T: comutative monoid\ntemplate <class\
    \ T, class U> U all_sum(const std::vector<T> &v, U init, U = U()) {\n    U res\
    \ = init;\n    for (const auto &x : v) res += x;\n    return res;\n}\n\ntemplate\
    \ <class T, class U> U all_sum(const std::vector<std::vector<T>> &v, U init, U\
    \ unit = U()) {\n    U res = init;\n    for (const auto &u : v) res += all_sum(u,\
    \ unit, unit);\n    return res;\n}\n\n// T: commutative monoid, F: (U, T) -> U\n\
    template <class T, class U, class F> U all_prod(const std::vector<T> &v, U init,\
    \ const F &f, U = U()) {\n    U res = init;\n    for (const auto &x : v) res =\
    \ f(res, x);\n    return res;\n}\n\ntemplate <class T, class U, class F>\nU all_prod(const\
    \ std::vector<std::vector<T>> &v, U init, const F &f, U unit) {\n    U res = init;\n\
    \    for (const auto &u : v) res = f(res, all_prod(u, unit, f, unit));\n    return\
    \ res;\n}\n\ntemplate <class T> T all_min(const std::vector<T> &v) {\n    if (v.empty())\
    \ return T();\n    T res = v[0];\n    for (const auto &x : v) res = res > x ?\
    \ x : res;\n    return res;\n}\n\ntemplate <class T>\nT all_min(const std::vector<std::vector<T>>\
    \ &v) {\n    T res{};\n    bool first = true;\n    for (const auto &u : v) {\n\
    \        if (u.empty()) continue;\n        if (first) {\n            res = all_min(u);\n\
    \            first = false;\n        } else {\n            T tmp = all_min(u);\n\
    \            res = res > tmp ? tmp : res;\n        }\n    }\n    return res;\n\
    }\n\ntemplate <class T> T all_max(const std::vector<T> &v) {\n    if (v.empty())\
    \ return T();\n    T res = v[0];\n    for (const auto &x : v) res = res < x ?\
    \ x : res;\n    return res;\n}\n\ntemplate <class T>\nT all_max(const std::vector<std::vector<T>>\
    \ &v) {\n    T res{};\n    bool first = true;\n    for (const auto &u : v) {\n\
    \        if (u.empty()) continue;\n        if (first) {\n            res = all_max(u);\n\
    \            first = false;\n        } else {\n            T tmp = all_max(u);\n\
    \            res = res < tmp ? tmp : res;\n        }\n    }\n    return res;\n\
    }\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_TEMPLATE_FUNCTION_UTIL_HPP\n#define KK2_TEMPLATE_FUNCTION_UTIL_HPP\
    \ 1\n\n#include <algorithm>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate\
    \ <class T, class... Sizes> auto make_vector(int first, Sizes... sizes) {\n  \
    \  if constexpr (sizeof...(sizes) == 0) {\n        return std::vector<T>(first);\n\
    \    } else {\n        return std::vector<decltype(make_vector<T>(sizes...))>(first,\
    \ make_vector<T>(sizes...));\n    }\n}\n\ntemplate <class T, class U> void fill_all(std::vector<T>\
    \ &v, const U &x) {\n    std::fill(std::begin(v), std::end(v), T(x));\n}\n\ntemplate\
    \ <class T, class U> void fill_all(std::vector<std::vector<T>> &v, const U &x)\
    \ {\n    for (auto &u : v) fill_all(u, x);\n}\n\ntemplate <class C> int mysize(const\
    \ C &c) {\n    return c.size();\n}\n\n// T: comutative monoid\ntemplate <class\
    \ T, class U> U all_sum(const std::vector<T> &v, U init, U = U()) {\n    U res\
    \ = init;\n    for (const auto &x : v) res += x;\n    return res;\n}\n\ntemplate\
    \ <class T, class U> U all_sum(const std::vector<std::vector<T>> &v, U init, U\
    \ unit = U()) {\n    U res = init;\n    for (const auto &u : v) res += all_sum(u,\
    \ unit, unit);\n    return res;\n}\n\n// T: commutative monoid, F: (U, T) -> U\n\
    template <class T, class U, class F> U all_prod(const std::vector<T> &v, U init,\
    \ const F &f, U = U()) {\n    U res = init;\n    for (const auto &x : v) res =\
    \ f(res, x);\n    return res;\n}\n\ntemplate <class T, class U, class F>\nU all_prod(const\
    \ std::vector<std::vector<T>> &v, U init, const F &f, U unit) {\n    U res = init;\n\
    \    for (const auto &u : v) res = f(res, all_prod(u, unit, f, unit));\n    return\
    \ res;\n}\n\ntemplate <class T> T all_min(const std::vector<T> &v) {\n    if (v.empty())\
    \ return T();\n    T res = v[0];\n    for (const auto &x : v) res = res > x ?\
    \ x : res;\n    return res;\n}\n\ntemplate <class T>\nT all_min(const std::vector<std::vector<T>>\
    \ &v) {\n    T res{};\n    bool first = true;\n    for (const auto &u : v) {\n\
    \        if (u.empty()) continue;\n        if (first) {\n            res = all_min(u);\n\
    \            first = false;\n        } else {\n            T tmp = all_min(u);\n\
    \            res = res > tmp ? tmp : res;\n        }\n    }\n    return res;\n\
    }\n\ntemplate <class T> T all_max(const std::vector<T> &v) {\n    if (v.empty())\
    \ return T();\n    T res = v[0];\n    for (const auto &x : v) res = res < x ?\
    \ x : res;\n    return res;\n}\n\ntemplate <class T>\nT all_max(const std::vector<std::vector<T>>\
    \ &v) {\n    T res{};\n    bool first = true;\n    for (const auto &u : v) {\n\
    \        if (u.empty()) continue;\n        if (first) {\n            res = all_max(u);\n\
    \            first = false;\n        } else {\n            T tmp = all_max(u);\n\
    \            res = res < tmp ? tmp : res;\n        }\n    }\n    return res;\n\
    }\n\n} // namespace kk2\n\n#endif // KK2_TEMPLATE_FUNCTION_UTIL_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: template/function_util.hpp
  requiredBy:
  - template/procon.hpp
  timestamp: '2025-01-16 14:05:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/function_util.hpp
layout: document
redirect_from:
- /library/template/function_util.hpp
- /library/template/function_util.hpp.html
title: template/function_util.hpp
---
