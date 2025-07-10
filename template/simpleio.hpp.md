---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_TEMPLATE_SIMPLEIO_HPP\n#define KK2_TEMPLATE_SIMPLEIO_HPP 1\n\n\
    #include <fstream>\n\n#include \"../type_traits/io.hpp\"\n\nnamespace kk2 {\n\n\
    struct SimplePrinter : type_traits::ostream_tag {\n  private:\n    std::ofstream\
    \ out;\n\n  public:\n    SimplePrinter(const char *s) : out(s) {}\n\n    template\
    \ <class T> SimplePrinter &operator<<(const T &x) {\n        out << x;\n     \
    \   return *this;\n    }\n\n    SimplePrinter &operator<<(std::ostream &(*f)(std::ostream\
    \ &)) {\n        out << f;\n        return *this;\n    }\n\n    void flush() {\
    \ out << std::flush; }\n};\n\n} // namespace kk2\n\n#endif // KK2_TEMPLATE_SIMPLEIO_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  isVerificationFile: false
  path: template/simpleio.hpp
  requiredBy: []
  timestamp: '2025-04-05 10:48:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/simpleio.hpp
layout: document
redirect_from:
- /library/template/simpleio.hpp
- /library/template/simpleio.hpp.html
title: template/simpleio.hpp
---
