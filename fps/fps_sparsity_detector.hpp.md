---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
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
  code: "#ifndef KK2_FPS_FPS_SPARSITY_DETECTOR_HPP\n#define KK2_FPS_FPS_SPARSITY_DETECTOR_HPP\
    \ 1\n\n#include \"../bit/bitcount.hpp\"\n\nnamespace kk2 {\n\nenum class FPSOperation\
    \ { CONVOLUTION };\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    bool is_sparse_operation(FPSOperation op, bool is_ntt_friendly, const FPS &a,\
    \ const FPS &b) {\n    int n = a.size(), m = b.size();\n    long long not_zero_a\
    \ = 0, not_zero_b = 0;\n    for (int i = 0; i < n; i++) not_zero_a += a[i] !=\
    \ mint(0);\n    for (int i = 0; i < m; i++) not_zero_b += b[i] != mint(0);\n\n\
    \    if (op == FPSOperation::CONVOLUTION) {\n        // NTT-friendly -> 3 * FFT\n\
    \        // Arbitrary    -> 9 * FFT\n        // Sparse       -> not_zero(a) *\
    \ not_zero(b)\n        int lg = msb(n + m) / 2 + 1;\n        return (n + m) *\
    \ lg * (is_ntt_friendly ? 3 : 7) > not_zero_a * not_zero_b;\n    }\n    return\
    \ false;\n}\n\n} // namespace kk2\n\n#endif // KK2_FPS_FPS_SPARSITY_DETECTOR_HPP\n"
  dependsOn:
  - bit/bitcount.hpp
  - type_traits/integral.hpp
  isVerificationFile: false
  path: fps/fps_sparsity_detector.hpp
  requiredBy: []
  timestamp: '2025-04-05 10:48:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/fps_sparsity_detector.hpp
layout: document
redirect_from:
- /library/fps/fps_sparsity_detector.hpp
- /library/fps/fps_sparsity_detector.hpp.html
title: fps/fps_sparsity_detector.hpp
---
