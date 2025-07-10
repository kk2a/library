---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps_base.hpp
    title: fps/fps_base.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps_ntt_friendly.hpp
    title: fps/fps_ntt_friendly.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps_sparsity_detector.hpp
    title: fps/fps_sparsity_detector.hpp
  - icon: ':heavy_check_mark:'
    path: fps/poly_sample_point_shift.hpp
    title: fps/poly_sample_point_shift.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/butterfly.hpp
    title: math_mod/butterfly.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/comb.hpp
    title: math_mod/comb.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/comb.hpp
    title: math_mod/comb.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/comb_large.hpp
    title: math_mod/comb_large.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/inv_table.hpp
    title: "`[1, n]`\u306Emod\u9006\u5143\u3092\u5217\u6319\u3059\u308B\u30C6\u30FC\
      \u30D6\u30EB"
  - icon: ':heavy_check_mark:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/primitive_root.hpp
    title: math_mod/primitive_root.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':heavy_check_mark:'
    path: random/seed.hpp
    title: random/seed.hpp
  - icon: ':heavy_check_mark:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':heavy_check_mark:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':heavy_check_mark:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../../modint/modint.hpp\"\n#include \"../../../math_mod/comb_large.hpp\"\n\
    #include \"../../../math_mod/comb.hpp\"\n#include \"../../../random/gen.hpp\"\n\
    #include \"../../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int a, b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\n    kk2::Comb<kk2::mint107>::set_upper(1e7);\n\
    \    int up = 2000001, lw = 1e7;\n    int t = 2;\n    rep (t) {\n        int n\
    \ = kk2::random::rng(up, lw);\n        auto a = kk2::Comb<kk2::mint107>::fact(n);\n\
    \        auto b = kk2::CombLarge<kk2::mint107>::fact(n);\n        // \u58CA\u308C\
    \u3066\u3044\u308B\u306E\u3067false\u3092\u8FD4\u3059\n        // assert(a ==\
    \ b);\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - modint/modint.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - math_mod/comb_large.hpp
  - fps/fps_ntt_friendly.hpp
  - convolution/convolution.hpp
  - fps/fps_sparsity_detector.hpp
  - bit/bitcount.hpp
  - math_mod/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - fps/fps_base.hpp
  - math_mod/inv_table.hpp
  - fps/poly_sample_point_shift.hpp
  - math_mod/comb.hpp
  - math_mod/comb.hpp
  - random/gen.hpp
  - random/seed.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
  requiredBy: []
  timestamp: '2025-07-08 15:40:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
- /verify/verify/unit_test/math_mod/large_fact_arb_mod.test.cpp.html
title: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
---
