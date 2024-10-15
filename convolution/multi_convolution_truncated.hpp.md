---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/butterfly.hpp
    title: convolution/butterfly.hpp
  - icon: ':question:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':question:'
    path: math_mod/primitive_root.hpp
    title: math_mod/primitive_root.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: fps/multivariate_fps.hpp
    title: fps/multivariate_fps.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_multi_truncated.test.cpp
    title: verify/yosupo_convolution/convolution_multi_truncated.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp
    - https://rushcheyo.blog.uoj.ac/blog/6547
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
    \  [Previous line repeated 2 more times]\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef CONVOLUTION_MULTI_ZERO\n#define CONVOLUTION_MULTI_ZERO 1\n\n#include\
    \ <vector>\n\n#include \"convolution.hpp\"\n\nnamespace kk2 {\n\n// reference:\
    \ https://rushcheyo.blog.uoj.ac/blog/6547\n// \u65E5\u672C\u8A9E:\n// https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp\n\
    template <class FPS, class mint = typename FPS::value_type>\nFPS multi_convolution_truncated(FPS\
    \ &a, const FPS &b, const std::vector<int> &base) {\n    int n = int(a.size());\n\
    \    if (!n) return {};\n    int k = base.size();\n    if (!k) return convolution(a,\
    \ b);\n    // chi[i] = \\sum_{j} \\floor(i / (base[0]...base[j]))\n    std::vector<int>\
    \ chi(n, 0);\n    for (int i = 0; i < n; i++) {\n        int x = i;\n        for\
    \ (int j = 0; j < k - 1; j++) chi[i] += (x /= base[j]);\n        chi[i] %= k;\n\
    \    }\n    int z = 1;\n    while (z < 2 * n - 1) z <<= 1;\n    std::vector<FPS>\
    \ f(k, FPS(z));\n    std::vector<FPS> g(k, FPS(z));\n    for (int i = 0; i < n;\
    \ i++) f[chi[i]][i] = a[i], g[chi[i]][i] = b[i];\n    for (auto &x : f) butterfly(x);\n\
    \    for (auto &x : g) butterfly(x);\n    std::vector<mint> tmp(k);\n    for (int\
    \ ii = 0; ii < z; ii++) {\n        for (int i = 0; i < k; i++) {\n           \
    \ for (int j = 0; j < k; j++) {\n                tmp[i + j - (i + j >= k ? k :\
    \ 0)] += f[i][ii] * g[j][ii];\n            }\n        }\n        for (int i =\
    \ 0; i < k; i++) f[i][ii] = tmp[i], tmp[i] = mint{0};\n    }\n    for (auto &x\
    \ : f) butterfly_inv(x);\n    for (int i = 0; i < n; i++) a[i] = f[chi[i]][i];\n\
    \    return a;\n}\n\n} // namespace kk2\n\n#endif // CONVOLUTION_MULTI_ZERO\n"
  dependsOn:
  - convolution/convolution.hpp
  - convolution/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: convolution/multi_convolution_truncated.hpp
  requiredBy:
  - fps/multivariate_fps.hpp
  timestamp: '2024-10-15 17:47:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_convolution/convolution_multi_truncated.test.cpp
documentation_of: convolution/multi_convolution_truncated.hpp
layout: document
redirect_from:
- /library/convolution/multi_convolution_truncated.hpp
- /library/convolution/multi_convolution_truncated.hpp.html
title: convolution/multi_convolution_truncated.hpp
---
