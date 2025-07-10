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
  code: "#ifndef KK2_OTHERS_RUN_LENGTH_ENCODING_HPP\n#define KK2_OTHERS_RUN_LENGTH_ENCODING_HPP\
    \ 1\n\n#include <string>\n#include <vector>\n\n#include \"../type_traits/io.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace run_length_encoding_impl {\n\ntemplate <class\
    \ T> struct rle_element {\n    T value;\n    int length;\n\n    template <class\
    \ OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const rle_element &rle) {\n        return os << \"(value: \" << rle.value\
    \ << \", length: \" << rle.length << \")\";\n    }\n};\n\ntemplate <typename C,\
    \ typename T = typename C::value_type>\nstd::vector<rle_element<T>> run_length_encoding(const\
    \ C &v) {\n    std::vector<rle_element<T>> res;\n    for (int i = 0; i < (int)v.size();\
    \ ++i) {\n        if (res.empty() || res.back().value != v[i]) {\n           \
    \ res.emplace_back(v[i], 1);\n        } else {\n            res.back().length++;\n\
    \        }\n    }\n    return res;\n}\n\n} // namespace run_length_encoding_impl\n\
    \nusing run_length_encoding_impl::run_length_encoding;\n\n} // namespace kk2\n\
    \n#endif // KK2_OTHERS_RUN_LENGTH_ENCODING_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  isVerificationFile: false
  path: others/run_length_encoding.hpp
  requiredBy: []
  timestamp: '2025-04-05 10:48:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/run_length_encoding.hpp
layout: document
redirect_from:
- /library/others/run_length_encoding.hpp
- /library/others/run_length_encoding.hpp.html
title: others/run_length_encoding.hpp
---
