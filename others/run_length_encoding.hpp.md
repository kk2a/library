---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"others/run_length_encoding.hpp\"\n\n\n\n#include <string>\n\
    #include <vector>\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n\
    #include <ostream>\n#include <type_traits>\n\nnamespace kk2 {\n\nnamespace type_traits\
    \ {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\
    \ntemplate <typename T> using is_standard_istream =\n    typename std::conditional<std::is_same<T,\
    \ std::istream>::value\n                                  || std::is_same<T, std::ifstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_standard_ostream =\n\
    \    typename std::conditional<std::is_same<T, std::ostream>::value\n        \
    \                          || std::is_same<T, std::ofstream>::value,\n       \
    \                       std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_user_defined_istream = std::is_base_of<type_traits::istream_tag,\
    \ T>;\ntemplate <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
    \ T>;\n\ntemplate <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
    \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
    \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate <typename\
    \ T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n#line 8 \"others/run_length_encoding.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ run_length_encoding_impl {\n\ntemplate <class T> struct rle_element {\n    T\
    \ value;\n    int length;\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    friend OStream &operator<<(OStream &os, const rle_element\
    \ &rle) {\n        return os << \"(value: \" << rle.value << \", length: \" <<\
    \ rle.length << \")\";\n    }\n};\n\ntemplate <typename C, typename T = typename\
    \ C::value_type>\nstd::vector<rle_element<T>> run_length_encoding(const C &v)\
    \ {\n    std::vector<rle_element<T>> res;\n    for (int i = 0; i < (int)v.size();\
    \ ++i) {\n        if (res.empty() || res.back().value != v[i]) {\n           \
    \ res.emplace_back(v[i], 1);\n        } else {\n            res.back().length++;\n\
    \        }\n    }\n    return res;\n}\n\n} // namespace run_length_encoding_impl\n\
    \nusing run_length_encoding_impl::run_length_encoding;\n\n} // namespace kk2\n\
    \n\n"
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
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/run_length_encoding.hpp
layout: document
redirect_from:
- /library/others/run_length_encoding.hpp
- /library/others/run_length_encoding.hpp.html
title: others/run_length_encoding.hpp
---
