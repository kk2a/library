---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/action/add_max.hpp
    title: math/action/add_max.hpp
  - icon: ':warning:'
    path: math/action/update_max.hpp
    title: math/action/update_max.hpp
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATH_MONOID_MAX_HPP\n#define KK2_MATH_MONOID_MAX_HPP 1\n\n#include\
    \ <functional>\n\n#include \"../../type_traits/type_traits.hpp\"\n\nnamespace\
    \ kk2 {\n\nnamespace monoid {\n\ntemplate <class S, class Compare = std::less<S>>\n\
    struct Max {\n    static constexpr bool commutative = true;\n\n    S a;\n    bool\
    \ is_unit;\n\n    Max() : a(S()), is_unit(true) {}\n\n    Max(S a_) : a(a_), is_unit(false)\
    \ {}\n\n    operator S() const { return a; }\n\n    inline static Max op(Max l,\
    \ Max r) {\n        if (l.is_unit or r.is_unit) return l.is_unit ? r : l;\n  \
    \      return Compare{}(l.a, r.a) ? r : l;\n    }\n\n    inline static Max unit()\
    \ { return Max(); }\n\n    template <class OStream, is_ostream_t<OSrteam> * =\
    \ nullptr>\n    friend OStream &operator<<(OStream &os, const Max &max) {\n  \
    \      if (max.is_unit) os << \"-inf\";\n        else os << max.a;\n        return\
    \ os;\n    }\n\n    template <class IStream, is_istream_t<IStream> * = nullptr>\n\
    \    friend IStream &operator>>(IStream &is, Max &max) {\n        is >> max.a;\n\
    \        max.is_unit = false;\n        return is;\n    }\n\n    bool operator==(const\
    \ Max &rhs) const {\n        return is_unit == rhs.is_unit and (is_unit or a ==\
    \ rhs.a);\n    }\n\n    bool operator!=(const Max &rhs) const { return !(*this\
    \ == rhs); }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\n#endif // MATH_MONOID_MAX_H\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: math/monoid/max.hpp
  requiredBy:
  - math/action/add_max.hpp
  - math/action/update_max.hpp
  timestamp: '2025-03-27 00:23:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/monoid/max.hpp
layout: document
redirect_from:
- /library/math/monoid/max.hpp
- /library/math/monoid/max.hpp.html
title: math/monoid/max.hpp
---
