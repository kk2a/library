---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: data_structure/static_rmq.hpp
    title: data_structure/static_rmq.hpp
  - icon: ':warning:'
    path: graph/tree/euler_tour.hpp
    title: graph/tree/euler_tour.hpp
  - icon: ':warning:'
    path: math/action/add_min.hpp
    title: math/action/add_min.hpp
  - icon: ':warning:'
    path: math/action/update_min.hpp
    title: math/action/update_min.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/monoid.test.cpp
    title: verify/unit_test/monoid.test.cpp
  - icon: ':x:'
    path: verify/yosupo_ds/ds_static_rmq.test.cpp
    title: verify/yosupo_ds/ds_static_rmq.test.cpp
  - icon: ':x:'
    path: verify/yosupo_ds/ds_static_rmq_2.test.cpp
    title: verify/yosupo_ds/ds_static_rmq_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATH_MONOID_MIN_HPP\n#define KK2_MATH_MONOID_MIN_HPP 1\n\n#include\
    \ <functional>\n\n#include \"../../type_traits/io.hpp\"\n\nnamespace kk2 {\n\n\
    namespace monoid {\n\ntemplate <class S, class Compare = std::less<S>> struct\
    \ Min {\n    static constexpr bool commutative = true;\n    S a;\n    bool is_unit;\n\
    \n    Min() : a(S()), is_unit(true) {}\n\n    Min(S a_) : a(a_), is_unit(false)\
    \ {}\n\n    operator S() const { return a; }\n\n    inline static Min op(Min l,\
    \ Min r) {\n        if (l.is_unit or r.is_unit) return l.is_unit ? r : l;\n  \
    \      return Compare{}(l.a, r.a) ? l : r;\n    }\n\n    inline static Min unit()\
    \ { return Min(); }\n\n    template <class OStream, is_ostream_t<OStream> * =\
    \ nullptr>\n    friend OStream &operator<<(OStream &os, const Min &min) {\n  \
    \      if (min.is_unit) os << \"inf\";\n        else os << min.a;\n        return\
    \ os;\n    }\n\n    template <class IStream, is_istream_t<IStream> * = nullptr>\n\
    \    friend IStream &operator>>(IStream &is, Min &min) {\n        is >> min.a;\n\
    \        min.is_unit = false;\n        return is;\n    }\n\n    bool operator==(const\
    \ Min &rhs) const {\n        return is_unit == rhs.is_unit and (is_unit or a ==\
    \ rhs.a);\n    }\n\n    bool operator!=(const Min &rhs) const { return !(*this\
    \ == rhs); }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\n#endif // KK2_MATH_MONOID_MIN_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  isVerificationFile: false
  path: math/monoid/min.hpp
  requiredBy:
  - math/action/update_min.hpp
  - math/action/add_min.hpp
  - graph/tree/euler_tour.hpp
  - data_structure/static_rmq.hpp
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_ds/ds_static_rmq_2.test.cpp
  - verify/yosupo_ds/ds_static_rmq.test.cpp
  - verify/unit_test/monoid.test.cpp
documentation_of: math/monoid/min.hpp
layout: document
redirect_from:
- /library/math/monoid/min.hpp
- /library/math/monoid/min.hpp.html
title: math/monoid/min.hpp
---
