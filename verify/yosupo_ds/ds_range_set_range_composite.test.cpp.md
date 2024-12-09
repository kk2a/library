---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':question:'
    path: segment_tree/lazy.hpp
    title: segment_tree/lazy.hpp
  - icon: ':question:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/function_util.hpp
    title: template/function_util.hpp
  - icon: ':question:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':question:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/range_set_range_composite
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_set_range_composite\"\
    \n\n#include \"../../modint/mont.hpp\"\n#include \"../../segment_tree/lazy.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nstruct S {\n\
    \    kk2::mont998 a, b;\n    int size;\n};\n\ntemplate <class IStream> IStream\
    \ &operator>>(IStream &is, S &s) {\n    is >> s.a >> s.b;\n    s.size = 1;\n \
    \   return is;\n}\n\nS op(S l, S r) {\n    return S{r.a * l.a, r.a * l.b + r.b,\
    \ l.size + r.size};\n}\n\nS e() {\n    return S{1, 0, 0};\n}\n\nstruct F {\n \
    \   S a;\n    bool id;\n};\n\nS mapping(F f, S x) {\n    if (f.id) return x;\n\
    \    if (f.a.a == kk2::mont998(1)) return S{kk2::mont998(1), f.a.b * x.size, x.size};\n\
    \    kk2::mont998 p = f.a.a.pow(x.size);\n    return S{p, f.a.b * (p - 1) * (f.a.a\
    \ - 1).inv(), x.size};\n}\n\nF composition(F l, F r) {\n    if (l.id) return r;\n\
    \    return l;\n}\n\nF id() {\n    return F{S{1, 0, 0}, true};\n}\n\nint main()\
    \ {\n    int n, q;\n    kin >> n >> q;\n    vector<S> a(n);\n    kin >> a;\n\n\
    \    kk2::LazySegTree<S, op, e, F, mapping, composition, id> seg(a);\n\n    rep\
    \ (q) {\n        int t;\n        kin >> t;\n        if (t == 0) {\n          \
    \  int l, r;\n            kk2::mont998 c, d;\n            kin >> l >> r >> c >>\
    \ d;\n            seg.apply(l, r, F{S{c, d, 1}, false});\n        }\n        if\
    \ (t == 1) {\n            int l, r;\n            kk2::mont998 x;\n           \
    \ kin >> l >> r >> x;\n            auto f = seg.prod(l, r);\n            kout\
    \ << f.a * x + f.b << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - modint/mont.hpp
  - type_traits/type_traits.hpp
  - segment_tree/lazy.hpp
  - template/template.hpp
  - template/fastio.hpp
  - template/type_alias.hpp
  - template/constant.hpp
  - template/function_util.hpp
  - template/macros.hpp
  - template/io_util.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_range_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2024-12-09 19:28:50+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_range_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_range_set_range_composite.test.cpp
- /verify/verify/yosupo_ds/ds_range_set_range_composite.test.cpp.html
title: verify/yosupo_ds/ds_range_set_range_composite.test.cpp
---
