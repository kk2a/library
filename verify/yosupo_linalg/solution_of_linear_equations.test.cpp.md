---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: matrix/matrix_field.hpp
    title: matrix/matrix_field.hpp
  - icon: ':question:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/system_of_linear_equations
    links:
    - https://judge.yosupo.jp/problem/system_of_linear_equations
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
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\
    \n\n#include \"../../matrix/matrix_field.hpp\"\n#include \"../../modint/mont.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int n, m;\n    kin >> n >> m;\n    kk2::MatrixField<kk2::mont998> a(n,\
    \ m), b(n, 1);\n    a.input(kin), b.input(kin);\n    if (const auto res = a.solve(b);\
    \ !res.get_h()) kout << -1 << \"\\n\";\n    else {\n        kout << res.get_h()\
    \ - 1 << \"\\n\";\n        res.output(kout);\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - matrix/matrix_field.hpp
  - modint/mont.hpp
  - type_traits/type_traits.hpp
  - template/template.hpp
  - template/fastio.hpp
  isVerificationFile: true
  path: verify/yosupo_linalg/solution_of_linear_equations.test.cpp
  requiredBy: []
  timestamp: '2024-10-13 04:00:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_linalg/solution_of_linear_equations.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_linalg/solution_of_linear_equations.test.cpp
- /verify/verify/yosupo_linalg/solution_of_linear_equations.test.cpp.html
title: verify/yosupo_linalg/solution_of_linear_equations.test.cpp
---
