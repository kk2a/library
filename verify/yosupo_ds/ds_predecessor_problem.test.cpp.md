---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/w_ary_tree.hpp
    title: data_structure/w_ary_tree.hpp
  - icon: ':heavy_check_mark:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':heavy_check_mark:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: template/function_util.hpp
    title: template/function_util.hpp
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
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\" \n\
    \n#include \"../../data_structure/w_ary_tree.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    kin >> n >> q;\n  \
    \  string t;\n    kin >> t;\n    kk2::w_ary_tree wt(t);\n    rep (q) {\n     \
    \   int type, x;\n        kin >> type >> x;\n        if (type == 0) {\n      \
    \      wt.insert(x);\n        } else if (type == 1) {\n            wt.erase(x);\n\
    \        } else if (type == 2) {\n            kout << wt.count(x) << \"\\n\";\n\
    \        } else if (type == 3) {\n            if (auto res = wt.successor(x);\
    \ res) {\n                kout << *res << \"\\n\";\n            } else {\n   \
    \             kout << \"-1\\n\";\n            }\n        } else {\n          \
    \  if (auto res = wt.predecessor(x); res) {\n                kout << *res << \"\
    \\n\";\n            } else {\n                kout << \"-1\\n\";\n           \
    \ }\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - data_structure/w_ary_tree.hpp
  - bit/bitcount.hpp
  - type_traits/type_traits.hpp
  - template/template.hpp
  - template/fastio.hpp
  - template/type_alias.hpp
  - template/constant.hpp
  - template/function_util.hpp
  - template/macros.hpp
  - template/io_util.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_predecessor_problem.test.cpp
  requiredBy: []
  timestamp: '2025-01-02 22:13:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_predecessor_problem.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_predecessor_problem.test.cpp
- /verify/verify/yosupo_ds/ds_predecessor_problem.test.cpp.html
title: verify/yosupo_ds/ds_predecessor_problem.test.cpp
---
