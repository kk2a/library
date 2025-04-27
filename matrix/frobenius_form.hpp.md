---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: matrix/basis.hpp
    title: "\u30D9\u30AF\u30C8\u30EB\u304C\u73FE\u5728\u306E\u57FA\u5E95\u3068\u7DDA\
      \u5F62\u72EC\u7ACB\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B"
  - icon: ':x:'
    path: matrix/matrix_field.hpp
    title: "\u884C\u5217"
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
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
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATRIX_FROBENIUS_FORM_HPP\n#define KK2_MATRIX_FROBENIUS_FORM_HPP\
    \ 1\n\n#include <vector>\n\n#include \"basis.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ linear_algebra {\n\ntemplate <class Matrix, class Poly, class Field> struct\
    \ FrobeniusForm_base {\n    Matrix mat;\n    std::vector<int> deg;\n    std::vector<Poly>\
    \ poly;\n\n    // mat = P_inv frobenius P\n    // P_inv = P^{-1}\n    Matrix frobenius,\
    \ P, P_inv;\n\n    FrobeniusForm_base(const Matrix &mat_) : mat(mat_) {\n    \
    \    int n = mat.get_h();\n        assert(n == mat.get_w());\n        frobenius\
    \ = P = Matrix(n, n);\n        build();\n    }\n\n    void build() {\n       \
    \ int n = mat.get_h();\n        Basis_base<Matrix, Field> basis;\n        // \u4E71\
    \u629E\u3067\u9811\u5F35\u308B\n    }\n};\n\n} // namespace linear_algebra\n\n\
    } // namespace kk2\n\n#endif // KK2_MATRIX_FROBENIUS_FORM_HPP\n"
  dependsOn:
  - matrix/basis.hpp
  - matrix/matrix_field.hpp
  - type_traits/io.hpp
  isVerificationFile: false
  path: matrix/frobenius_form.hpp
  requiredBy: []
  timestamp: '2025-04-27 18:34:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/frobenius_form.hpp
layout: document
redirect_from:
- /library/matrix/frobenius_form.hpp
- /library/matrix/frobenius_form.hpp.html
title: matrix/frobenius_form.hpp
---
