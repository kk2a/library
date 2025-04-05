---
data:
  _extendedDependsOn: []
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
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_CONVOLUTION_CONVOLUTION_HPP\n#define KK2_CONVOLUTION_CONVOLUTION_HPP\
    \ 1\n\n#include <algorithm>\n#include <vector>\n\n#include \"../fps/fps_sparsity_detector.hpp\"\
    \n#include \"../math_mod/butterfly.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
    \ FPS, class mint = typename FPS::value_type> FPS convolution(FPS &a, const FPS\
    \ &b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return\
    \ {};\n    if (is_sparse_operation(FPSOperation::CONVOLUTION, 1, a, b)) {\n  \
    \      std::vector<int> nza(n), nzb(m);\n        int ai = 0, bi = 0;\n       \
    \ for (int i = 0; i < n; i++)\n            if (a[i] != mint(0)) nza[ai++] = i;\n\
    \        for (int i = 0; i < m; i++)\n            if (b[i] != mint(0)) nzb[bi++]\
    \ = i;\n        nza.resize(ai), nzb.resize(bi);\n        FPS res(n + m - 1);\n\
    \        for (int i : nza)\n            for (int j : nzb) res[i + j] += a[i] *\
    \ b[j];\n        return a = res;\n    }\n\n    int z = 1;\n    while (z < n +\
    \ m - 1) z <<= 1;\n    if (a == b) {\n        a.resize(z);\n        butterfly(a);\n\
    \        for (int i = 0; i < z; i++) a[i] *= a[i];\n    } else {\n        a.resize(z);\n\
    \        butterfly(a);\n        FPS t(b.begin(), b.end());\n        t.resize(z);\n\
    \        butterfly(t);\n        for (int i = 0; i < z; i++) a[i] *= t[i];\n  \
    \  }\n    butterfly_inv(a);\n    a.resize(n + m - 1);\n    return a;\n}\n\n} //\
    \ namespace kk2\n\n#endif // KK2_CONVOLUTION_CONVOLUTION_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/convolution.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/convolution.hpp
layout: document
redirect_from:
- /library/convolution/convolution.hpp
- /library/convolution/convolution.hpp.html
title: convolution/convolution.hpp
---
