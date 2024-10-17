---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: matrix/basis.hpp
    title: matrix/basis.hpp
  - icon: ':x:'
    path: matrix/matrix_field.hpp
    title: matrix/matrix_field.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef MATRIX_FROBENIUS_FORM_HPP\n#define MATRIX_FROBENIUS_FORM_HPP 1\n\n\
    #include <vector>\n\n#include \"basis.hpp\"\n\nnamespace kk2 {\n\nnamespace linear_algebra\
    \ {\n\ntemplate <class Matrix, class Poly, class Field>\nstruct FrobeniusForm_base\
    \ {\n    Matrix mat;\n    std::vector<int> deg;\n    std::vector<Poly> poly;\n\
    \n    // mat = P_inv frobenius P\n    // P_inv = P^{-1}\n    Matrix frobenius,\
    \ P, P_inv;\n\n    FrobeniusForm_base(const Matrix &mat_) : mat(mat_) {\n    \
    \    int n = mat.get_h();\n        assert(n == mat.get_w());\n        frobenius\
    \ = P = Matrix(n, n);\n        build();\n    }\n\n    void build() {\n       \
    \ int n = mat.get_h();\n        Basis_base<Matrix, Field> basis;\n        // \u4E71\
    \u629E\u3067\u9811\u5F35\u308B\n    }\n};\n\n}\n\n} // namespace kk2\n\n#endif\
    \ // MATRIX_FROBENIUS_FORM_HPP\n"
  dependsOn:
  - matrix/basis.hpp
  - matrix/matrix_field.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: matrix/frobenius_form.hpp
  requiredBy: []
  timestamp: '2024-10-17 14:04:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/frobenius_form.hpp
layout: document
redirect_from:
- /library/matrix/frobenius_form.hpp
- /library/matrix/frobenius_form.hpp.html
title: matrix/frobenius_form.hpp
---