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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_CONVOLUTION_CONVOLUTION_ARB_HPP\n#define KK2_CONVOLUTION_CONVOLUTION_ARB_HPP\
    \ 1\n\n#include <algorithm>\n#include <vector>\n\n#include \"../math_mod/garner.hpp\"\
    \n#include \"../modint/mont.hpp\"\n#include \"convolution.hpp\"\n\nnamespace kk2\
    \ {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\nFPS convolution_arb(FPS\
    \ &a, const FPS &b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n\
    \ || !m) return {};\n    if (is_sparse_operation(FPSOperation::CONVOLUTION, 0,\
    \ a, b)) {\n        std::vector<int> nza(n), nzb(m);\n        int ai = 0, bi =\
    \ 0;\n        for (int i = 0; i < n; i++)\n            if (a[i] != mint(0)) nza[ai++]\
    \ = i;\n        for (int i = 0; i < m; i++)\n            if (b[i] != mint(0))\
    \ nzb[bi++] = i;\n        nza.resize(ai), nzb.resize(bi);\n        FPS res(n +\
    \ m - 1);\n        for (int i : nza)\n            for (int j : nzb) res[i + j]\
    \ += a[i] * b[j];\n        return a = res;\n    }\n\n    static constexpr long\
    \ long MOD1 = 754974721; // 2^24\n    static constexpr long long MOD2 = 167772161;\
    \ // 2^25\n    static constexpr long long MOD3 = 469762049; // 2^26\n    using\
    \ mint1 = LazyMontgomeryModInt<MOD1>;\n    using mint2 = LazyMontgomeryModInt<MOD2>;\n\
    \    using mint3 = LazyMontgomeryModInt<MOD3>;\n\n    std::vector<long long> a0(n),\
    \ b0(m);\n    for (int i = 0; i < n; i++) a0[i] = a[i].val();\n    for (int i\
    \ = 0; i < m; i++) b0[i] = b[i].val();\n    auto a1 = std::vector<mint1>(a0.begin(),\
    \ a0.end());\n    auto b1 = std::vector<mint1>(b0.begin(), b0.end());\n    convolution(a1,\
    \ b1);\n    auto a2 = std::vector<mint2>(a0.begin(), a0.end());\n    auto b2 =\
    \ std::vector<mint2>(b0.begin(), b0.end());\n    convolution(a2, b2);\n    auto\
    \ a3 = std::vector<mint3>(a0.begin(), a0.end());\n    auto b3 = std::vector<mint3>(b0.begin(),\
    \ b0.end());\n    convolution(a3, b3);\n    const std::vector<long long> ps =\
    \ {MOD1, MOD2, MOD3, mint::getmod()};\n    a.resize(n + m - 1);\n    for (int\
    \ i = 0; i < n + m - 1; i++) {\n        a[i] = mint(garner({a1[i].val(), a2[i].val(),\
    \ a3[i].val()}, ps));\n    }\n    return a;\n}\n\n} // namespace kk2\n\n#endif\
    \ // KK2_CONVOLUTION_CONVOLUTION_ARB_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/convolution_arb.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/convolution_arb.hpp
layout: document
redirect_from:
- /library/convolution/convolution_arb.hpp
- /library/convolution/convolution_arb.hpp.html
title: convolution/convolution_arb.hpp
---
