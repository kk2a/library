---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/binary_trie.hpp
    title: data_structure/binary_trie.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/ordered_set
    links:
    - https://judge.yosupo.jp/problem/ordered_set
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/ordered_set\" \n\n#include\
    \ \"../../data_structure/binary_trie.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    kin >> n >> q;\n  \
    \  vc<int> a(n);\n    kin >> a;\n    kk2::BinaryTrie<int, 30> bt(30 * q + 20 *\
    \ n);\n    rep (i, n) bt.insert(a[i]);\n\n    rep (q) {\n        int type, x;\n\
    \        kin >> type >> x;\n        if (type == 0) {\n            if (!bt.count(x))\
    \ bt.insert(x);\n        } else if (type == 1) {\n            bt.erase(x);\n \
    \       } else if (type == 2) {\n            auto res = bt.get_kth(x - 1);\n \
    \           if (res) kout << *res << \"\\n\";\n            else kout << -1 <<\
    \ \"\\n\";\n        } else if (type == 3) {\n            kout << bt.count_not_greater(x)\
    \ << \"\\n\";\n        } else if (type == 4) {\n            auto res = bt.max_not_greater(x);\n\
    \            if (res) kout << *res << \"\\n\";\n            else kout << -1 <<\
    \ \"\\n\";\n        } else {\n            auto res = bt.min_not_less(x);\n   \
    \         if (res) kout << *res << \"\\n\";\n            else kout << -1 << \"\
    \\n\";\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - data_structure/binary_trie.hpp
  - template/template.hpp
  - template/fastio.hpp
  - type_traits/type_traits.hpp
  - template/type_alias.hpp
  - template/constant.hpp
  - template/function_util.hpp
  - template/macros.hpp
  - template/io_util.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_ordered_set_binary_trie.test.cpp
  requiredBy: []
  timestamp: '2024-12-17 23:15:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_ordered_set_binary_trie.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_ordered_set_binary_trie.test.cpp
- /verify/verify/yosupo_ds/ds_ordered_set_binary_trie.test.cpp.html
title: verify/yosupo_ds/ds_ordered_set_binary_trie.test.cpp
---
