---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/monoid/max.hpp
    title: math/monoid/max.hpp
  - icon: ':question:'
    path: math/monoid/min.hpp
    title: math/monoid/min.hpp
  - icon: ':question:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':x:'
    path: template/function_util.hpp
    title: template/function_util.hpp
  - icon: ':question:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':question:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':question:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':x:'
    path: type_traits/container_traits.hpp
    title: type_traits/container_traits.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
    title: verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  code: "#ifndef KK2_TEMPLATE_PROCON_HPP\n#define KK2_TEMPLATE_PROCON_HPP 1\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <iterator>\n#include <map>\n#include <numeric>\n#include\
    \ <optional>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <vector>\n\n#include \"constant.hpp\"\n#include \"function_util.hpp\"\n#include\
    \ \"io_util.hpp\"\n#include \"macros.hpp\"\n#include \"type_alias.hpp\"\n\nstruct\
    \ FastIOSetUp {\n    FastIOSetUp() {\n        std::ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n    }\n} fast_io_set_up;\n\nauto &kin = std::cin;\n\
    auto &kout = std::cout;\nauto (*kendl)(std::ostream &) = std::endl<char, std::char_traits<char>>;\n\
    \nvoid Yes(bool b = 1) { kout << (b ? \"Yes\\n\" : \"No\\n\"); }\nvoid No(bool\
    \ b = 1) { kout << (b ? \"No\\n\" : \"Yes\\n\"); }\nvoid YES(bool b = 1) { kout\
    \ << (b ? \"YES\\n\" : \"NO\\n\"); }\nvoid NO(bool b = 1) { kout << (b ? \"NO\\\
    n\" : \"YES\\n\"); }\nvoid yes(bool b = 1) { kout << (b ? \"yes\\n\" : \"no\\\
    n\"); }\nvoid no(bool b = 1) { kout << (b ? \"no\\n\" : \"yes\\n\"); }\ntemplate\
    \ <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a =\
    \ b, 1 : 0); }\ntemplate <class T, class S> inline bool chmin(T &a, const S &b)\
    \ { return (a > b ? a = b, 1 : 0); }\n\nstd::istream &operator>>(std::istream\
    \ &is, u128 &x) {\n    std::string s;\n    is >> s;\n    x = 0;\n    for (char\
    \ c : s) {\n        assert('0' <= c && c <= '9');\n        x = x * 10 + c - '0';\n\
    \    }\n    return is;\n}\n\nstd::istream &operator>>(std::istream &is, i128 &x)\
    \ {\n    std::string s;\n    is >> s;\n    bool neg = s[0] == '-';\n    x = 0;\n\
    \    for (int i = neg; i < (int)s.size(); i++) {\n        assert('0' <= s[i] &&\
    \ s[i] <= '9');\n        x = x * 10 + s[i] - '0';\n    }\n    if (neg) x = -x;\n\
    \    return is;\n}\n\nstd::ostream &operator<<(std::ostream &os, u128 x) {\n \
    \   if (x == 0) return os << '0';\n    std::string s;\n    while (x) {\n     \
    \   s.push_back('0' + x % 10);\n        x /= 10;\n    }\n    std::reverse(s.begin(),\
    \ s.end());\n    return os << s;\n}\n\nstd::ostream &operator<<(std::ostream &os,\
    \ i128 x) {\n    if (x == 0) return os << '0';\n    if (x < 0) {\n        os <<\
    \ '-';\n        x = -x;\n    }\n    std::string s;\n    while (x) {\n        s.push_back('0'\
    \ + x % 10);\n        x /= 10;\n    }\n    std::reverse(s.begin(), s.end());\n\
    \    return os << s;\n}\n\n#endif // KK2_TEMPLATE_PROCON_HPP\n"
  dependsOn:
  - template/constant.hpp
  - template/type_alias.hpp
  - template/function_util.hpp
  - math/monoid/max.hpp
  - type_traits/io.hpp
  - math/monoid/min.hpp
  - type_traits/container_traits.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: false
  path: template/procon.hpp
  requiredBy: []
  timestamp: '2025-06-06 17:43:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
documentation_of: template/procon.hpp
layout: document
redirect_from:
- /library/template/procon.hpp
- /library/template/procon.hpp.html
title: template/procon.hpp
---
