---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn:
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_OTHERS_RUN_LENGTH_ENCODING_HPP\n#define KK2_OTHERS_RUN_LENGTH_ENCODING_HPP\
      \ 1\n\n#include <string>\n#include <vector>\n\n#include \"../type_traits/io.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace run_length_encoding_impl {\n\ntemplate <class\
      \ T> struct rle_element {\n    T value;\n    int length;\n\n    template <OutputStream\
      \ OStream>\n    friend OStream &operator<<(OStream &os, const rle_element &rle)\
      \ {\n        return os << \"(value: \" << rle.value << \", length: \" << rle.length\
      \ << \")\";\n    }\n};\n\ntemplate <typename C, typename T = typename C::value_type>\n\
      std::vector<rle_element<T>> run_length_encoding(const C &v) {\n    std::vector<rle_element<T>>\
      \ res;\n    for (int i = 0; i < (int)v.size(); ++i) {\n        if (res.empty()\
      \ || res.back().value != v[i]) {\n            res.emplace_back(v[i], 1);\n \
      \       } else {\n            res.back().length++;\n        }\n    }\n    return\
      \ res;\n}\n\n} // namespace run_length_encoding_impl\n\nusing run_length_encoding_impl::run_length_encoding;\n\
      \n} // namespace kk2\n\n#endif // KK2_OTHERS_RUN_LENGTH_ENCODING_HPP\n"
    name: default
  - code: "#line 1 \"others/run_length_encoding.hpp\"\n\n\n\n#include <string>\n#include\
      \ <vector>\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <concepts>\n#include\
      \ <fstream>\n#include <istream>\n#include <ostream>\n#include <type_traits>\n\
      \nnamespace kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct\
      \ ostream_tag {};\n\n} // namespace type_traits\n\ntemplate <typename T> using\
      \ is_standard_istream =\n    typename std::conditional<std::is_same<T, std::istream>::value\n\
      \                                  || std::is_same<T, std::ifstream>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\ntemplate <typename T> using is_standard_ostream\
      \ =\n    typename std::conditional<std::is_same<T, std::ostream>::value\n  \
      \                                || std::is_same<T, std::ofstream>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
      \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
      \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
      template <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
      \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
      \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate\
      \ <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\
      \ntemplate <class T>\nconcept StandardInputStream = is_standard_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept StandardOutputStream = is_standard_ostream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept InputStream = is_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept OutputStream = is_ostream<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 8 \"others/run_length_encoding.hpp\"\n\nnamespace\
      \ kk2 {\n\nnamespace run_length_encoding_impl {\n\ntemplate <class T> struct\
      \ rle_element {\n    T value;\n    int length;\n\n    template <OutputStream\
      \ OStream>\n    friend OStream &operator<<(OStream &os, const rle_element &rle)\
      \ {\n        return os << \"(value: \" << rle.value << \", length: \" << rle.length\
      \ << \")\";\n    }\n};\n\ntemplate <typename C, typename T = typename C::value_type>\n\
      std::vector<rle_element<T>> run_length_encoding(const C &v) {\n    std::vector<rle_element<T>>\
      \ res;\n    for (int i = 0; i < (int)v.size(); ++i) {\n        if (res.empty()\
      \ || res.back().value != v[i]) {\n            res.emplace_back(v[i], 1);\n \
      \       } else {\n            res.back().length++;\n        }\n    }\n    return\
      \ res;\n}\n\n} // namespace run_length_encoding_impl\n\nusing run_length_encoding_impl::run_length_encoding;\n\
      \n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: others/run_length_encoding.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 22:58:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/run_length_encoding.hpp
layout: document
---
