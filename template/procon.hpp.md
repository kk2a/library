---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/constant.hpp
    title: template/constant.hpp
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
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
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
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef TEMPLATE_PROCON_HPP\n#define TEMPLATE_PROCON_HPP 1\n\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n// #include <chrono>\n\
    // #include <cmath>\n#include <deque>\n#include <fstream>\n#include <functional>\n\
    #include <iostream>\n#include <iterator>\n#include <map>\n#include <numeric>\n\
    #include <optional>\n#include <queue>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n\
    #include <vector>\n\n#include \"type_alias.hpp\"\n#include \"constant.hpp\"\n\
    #include \"function_util.hpp\"\n#include \"macros.hpp\"\n#include \"io_util.hpp\"\
    \n\n#ifndef INPUT_FILE\n#define INPUT_FILE \"in.txt\"\n#endif\n#ifndef OUTPUT_FILE\n\
    #define OUTPUT_FILE \"out.txt\"\n#endif\n\n#ifdef KK2\nstd::ifstream kin(INPUT_FILE);\n\
    std::ofstream kout(OUTPUT_FILE);\nauto (*kendl)(std::ostream &) = std::endl<char,\
    \ std::char_traits<char>>;\n#else\nstruct FastIOSetUp {\n    FastIOSetUp() {\n\
    \        std::ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);  \n\
    \    }\n} fast_io_set_up;\nauto &kin = std::cin;\nauto &kout = std::cout;\nauto\
    \ (*kendl)(std::ostream &) = std::endl<char, std::char_traits<char>>;\n#endif\n\
    \nvoid Yes(bool b = 1) {\n    kout << (b ? \"Yes\\n\" : \"No\\n\");\n}\n\nvoid\
    \ No(bool b = 1) {\n    kout << (b ? \"No\\n\" : \"Yes\\n\");\n}\n\nvoid YES(bool\
    \ b = 1) {\n    kout << (b ? \"YES\\n\" : \"NO\\n\");\n}\n\nvoid NO(bool b = 1)\
    \ {\n    kout << (b ? \"NO\\n\" : \"YES\\n\");\n}\n\nvoid yes(bool b = 1) {\n\
    \    kout << (b ? \"yes\\n\" : \"no\\n\");\n}\n\nvoid no(bool b = 1) {\n    kout\
    \ << (b ? \"no\\n\" : \"yes\\n\");\n}\n\n#endif // TEMPLATE_PROCON_HPP\n"
  dependsOn:
  - template/type_alias.hpp
  - template/constant.hpp
  - template/function_util.hpp
  - template/macros.hpp
  - template/io_util.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: template/procon.hpp
  requiredBy: []
  timestamp: '2024-12-18 13:24:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/procon.hpp
layout: document
redirect_from:
- /library/template/procon.hpp
- /library/template/procon.hpp.html
title: template/procon.hpp
---
