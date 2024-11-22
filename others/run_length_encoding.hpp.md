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
    \ <class T> struct result {\n    T value;\n    int length;\n};\n\ntemplate <class\
    \ T> std::vector<result<T>> RunLengthEncoding(const std::vector<T> &v) {\n   \
    \ std::vector<result<T>> res;\n    for (int i = 0; i < (int)v.size(); ++i) {\n\
    \        if (res.empty() || res.back().value != v[i]) {\n            res.emplace_back(v[i],\
    \ 1);\n        } else {\n            res.back().length++;\n        }\n    }\n\
    \    return res;\n}\n\nstd::vector<result<char>> RunLengthEncoding(const std::string\
    \ &s) {\n    std::vector<result<char>> res;\n    for (int i = 0; i < (int)s.size();\
    \ ++i) {\n        if (res.empty() || res.back().value != s[i]) {\n           \
    \ res.emplace_back(s[i], 1);\n        } else {\n            res.back().length++;\n\
    \        }\n    }\n    return res;\n}\n\n} // namespace run_length_encoding\n\n\
    using run_length_encoding::RunLengthEncoding;\n\n} // namespace kk2\n\n\n"
  code: "#ifndef OTHERS_RUN_LENGTH_ENCODING_HPP\n#define OTHERS_RUN_LENGTH_ENCODING_HPP\
    \ 1\n\n#include <string>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace run_length_encoding\
    \ {\n\ntemplate <class T> struct result {\n    T value;\n    int length;\n};\n\
    \ntemplate <class T> std::vector<result<T>> RunLengthEncoding(const std::vector<T>\
    \ &v) {\n    std::vector<result<T>> res;\n    for (int i = 0; i < (int)v.size();\
    \ ++i) {\n        if (res.empty() || res.back().value != v[i]) {\n           \
    \ res.emplace_back(v[i], 1);\n        } else {\n            res.back().length++;\n\
    \        }\n    }\n    return res;\n}\n\nstd::vector<result<char>> RunLengthEncoding(const\
    \ std::string &s) {\n    std::vector<result<char>> res;\n    for (int i = 0; i\
    \ < (int)s.size(); ++i) {\n        if (res.empty() || res.back().value != s[i])\
    \ {\n            res.emplace_back(s[i], 1);\n        } else {\n            res.back().length++;\n\
    \        }\n    }\n    return res;\n}\n\n} // namespace run_length_encoding\n\n\
    using run_length_encoding::RunLengthEncoding;\n\n} // namespace kk2\n\n#endif\
    \ // OTHERS_RUN_LENGTH_ENCODING_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: others/run_length_encoding.hpp
  requiredBy: []
  timestamp: '2024-11-22 18:09:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/run_length_encoding.hpp
layout: document
redirect_from:
- /library/others/run_length_encoding.hpp
- /library/others/run_length_encoding.hpp.html
title: others/run_length_encoding.hpp
---
