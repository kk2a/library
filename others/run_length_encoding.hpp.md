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
  bundledCode: "#line 1 \"others/run_length_encoding.hpp\"\n\n\n\n#include <string>\n\
    #include <vector>\n\nnamespace kk2 {\n\nnamespace run_length_encoding {\n\ntemplate\
    \ <class T> struct rle_element {\n    T value;\n    int length;\n};\n\ntemplate\
    \ <typename C, typename T = typename C::value_type>\nstd::vector<rle_element<T>>\
    \ RunLengthEncoding(const C &v) {\n    std::vector<rle_element<T>> res;\n    for\
    \ (int i = 0; i < (int)v.size(); ++i) {\n        if (res.empty() || res.back().value\
    \ != v[i]) {\n            res.emplace_back(v[i], 1);\n        } else {\n     \
    \       res.back().length++;\n        }\n    }\n    return res;\n}\n\n} // namespace\
    \ run_length_encoding\n\nusing run_length_encoding::RunLengthEncoding;\n\n} //\
    \ namespace kk2\n\n\n"
  code: "#ifndef OTHERS_RUN_LENGTH_ENCODING_HPP\n#define OTHERS_RUN_LENGTH_ENCODING_HPP\
    \ 1\n\n#include <string>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace run_length_encoding\
    \ {\n\ntemplate <class T> struct rle_element {\n    T value;\n    int length;\n\
    };\n\ntemplate <typename C, typename T = typename C::value_type>\nstd::vector<rle_element<T>>\
    \ RunLengthEncoding(const C &v) {\n    std::vector<rle_element<T>> res;\n    for\
    \ (int i = 0; i < (int)v.size(); ++i) {\n        if (res.empty() || res.back().value\
    \ != v[i]) {\n            res.emplace_back(v[i], 1);\n        } else {\n     \
    \       res.back().length++;\n        }\n    }\n    return res;\n}\n\n} // namespace\
    \ run_length_encoding\n\nusing run_length_encoding::RunLengthEncoding;\n\n} //\
    \ namespace kk2\n\n#endif // OTHERS_RUN_LENGTH_ENCODING_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: others/run_length_encoding.hpp
  requiredBy: []
  timestamp: '2024-11-29 13:50:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/run_length_encoding.hpp
layout: document
redirect_from:
- /library/others/run_length_encoding.hpp
- /library/others/run_length_encoding.hpp.html
title: others/run_length_encoding.hpp
---