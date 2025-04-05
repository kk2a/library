---
data:
  _extendedDependsOn: []
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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../type_traits/functional.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef KK2_FUNCTIONAL_REVERSE_ARGS_HPP\n#define KK2_FUNCTIONAL_REVERSE_ARGS_HPP\
    \ 1\n\n#include \"../type_traits/functional.hpp\"\n\nnamespace kk2 {\n\n// reverse_args<f>(y,\
    \ x) = f(x, y)\ntemplate <auto f, is_two_args_function_pointer_t<decltype(f)>\
    \ * = nullptr>\ninline auto reverse_args(auto x, auto y) {\n    return f(y, x);\n\
    }\n\n} // namespace kk2\n\n#endif // KK2_FUNCTIONAL_REVERSE_ARGS_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: functional/reverse_args.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: functional/reverse_args.hpp
layout: document
redirect_from:
- /library/functional/reverse_args.hpp
- /library/functional/reverse_args.hpp.html
title: functional/reverse_args.hpp
---
