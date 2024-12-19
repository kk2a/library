---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/procon.hpp
    title: template/procon.hpp
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
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef TEMPLATE_SIMPLEIO_HPP\n#define TEMPLATE_SIMPLEIO_HPP 1\n\n#include\
    \ <fstream>\n#include <string>\n\n#include \"../type_traits/type_traits.hpp\"\n\
    \nnamespace kk2 {\n\nstruct SimplePrinter : type_traits::ostream_tag {\n  private:\n\
    \    std::ofstream out;\n\n  public:\n    SimplePrinter(const char *s) : out(s)\
    \ {}\n\n    template <class T> SimplePrinter &operator<<(const T &x) {\n     \
    \   out << x;\n        return *this;\n    }\n\n    SimplePrinter &operator<<(std::ostream\
    \ &(*f)(std::ostream &)) {\n        out << f;\n        return *this;\n    }\n\n\
    \    void flush() { out << std::flush; }\n};\n\n} // namespace kk2\n\n#endif //\
    \ TEMPLATE_SIMPLEIO_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: template/simpleio.hpp
  requiredBy:
  - template/procon.hpp
  timestamp: '2024-12-19 13:46:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/simpleio.hpp
layout: document
redirect_from:
- /library/template/simpleio.hpp
- /library/template/simpleio.hpp.html
title: template/simpleio.hpp
---
