---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: modint/modint.hpp
    title: modint/modint.hpp
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
  - icon: ':x:'
    path: unionfind/potentialized.hpp
    title: unionfind/potentialized.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group\"\
    \ \n\n#include \"../../modint/modint.hpp\"\n#include \"../../unionfind/potentialized.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nstruct A {\n\
    \    kk2::mint998 a00, a01, a10, a11;\n    bool operator==(const A& r) const {\n\
    \        return a00 == r.a00 && a01 == r.a01 && a10 == r.a10 && a11 == r.a11;\n\
    \    }\n};\n\nA op(A l, A r) {\n    return A{\n        l.a00 * r.a00 + l.a01 *\
    \ r.a10,\n        l.a00 * r.a01 + l.a01 * r.a11,\n        l.a10 * r.a00 + l.a11\
    \ * r.a10,\n        l.a10 * r.a01 + l.a11 * r.a11\n    };\n}\n\nA e() {\n    return\
    \ A{1, 0, 0, 1};\n}\n\nA inv(A a) {\n    return A{a.a11, -a.a01, -a.a10, a.a00};\n\
    }\n\nusing Ab = kk2::EasyAbelianGroup<A, op, e, inv>;\n\nint main() {\n    int\
    \ n, q;\n    kin >> n >> q;\n    kk2::PotentializedUnionFind<Ab, false> puf(n);\n\
    \n    rep (i, q) {\n        int type;\n        kin >> type;\n        if (type\
    \ == 0) {\n            int u, v;\n            kin >> u >> v;\n            A x;\n\
    \            kin >> x.a00 >> x.a01 >> x.a10 >> x.a11;\n            if (puf.same(v,\
    \ u)) {\n                kout << (puf.diff(v, u).val == x) << \"\\n\";\n     \
    \       } else {\n                kout << \"1\\n\";\n                puf.unite(v,\
    \ u, x);\n            }\n        } else {\n            int u, v;\n           \
    \ kin >> u >> v;\n            if (!puf.same(v, u)) {\n                kout <<\
    \ \"-1\\n\";\n            } else {\n                A x = puf.diff(v, u).val;\n\
    \                kout << x.a00 << \" \" << x.a01 << \" \" << x.a10 << \" \" <<\
    \ x.a11 << \"\\n\";\n            }\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - modint/modint.hpp
  - type_traits/type_traits.hpp
  - unionfind/potentialized.hpp
  - template/template.hpp
  - template/fastio.hpp
  - template/type_alias.hpp
  - template/constant.hpp
  - template/function_util.hpp
  - template/macros.hpp
  - template/io_util.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_potentiailized_uf_non_commutattive.test.cpp
  requiredBy: []
  timestamp: '2024-12-15 15:04:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_potentiailized_uf_non_commutattive.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_potentiailized_uf_non_commutattive.test.cpp
- /verify/verify/yosupo_ds/ds_potentiailized_uf_non_commutattive.test.cpp.html
title: verify/yosupo_ds/ds_potentiailized_uf_non_commutattive.test.cpp
---
