---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/monoid/max.hpp
    title: math/monoid/max.hpp
  - icon: ':question:'
    path: math/monoid/min.hpp
    title: math/monoid/min.hpp
  - icon: ':warning:'
    path: type_traits/container_traits.hpp
    title: type_traits/container_traits.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
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
    \ [](U a, U b) { return std::lcm(a, b); });\n}\n\n} // namespace kk2\n\n#endif\
    \ // KK2_TEMPLATE_FUNCTION_UTIL_HPP\n"
  dependsOn:
  - math/monoid/max.hpp
  - type_traits/io.hpp
  - math/monoid/min.hpp
  - type_traits/container_traits.hpp
  isVerificationFile: false
  path: template/function_util.hpp
  requiredBy:
  - template/procon.hpp
  timestamp: '2025-04-06 13:01:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/function_util.hpp
layout: document
redirect_from:
- /library/template/function_util.hpp
- /library/template/function_util.hpp.html
title: template/function_util.hpp
---
