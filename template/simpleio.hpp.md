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
  - code: "#ifndef KK2_TEMPLATE_SIMPLEIO_HPP\n#define KK2_TEMPLATE_SIMPLEIO_HPP 1\n\
      \n#include <fstream>\n\n#include \"../type_traits/io.hpp\"\n\nnamespace kk2\
      \ {\n\nstruct SimplePrinter : type_traits::ostream_tag {\n  private:\n    std::ofstream\
      \ out;\n\n  public:\n    SimplePrinter(const char *s) : out(s) {}\n\n    template\
      \ <class T> SimplePrinter &operator<<(const T &x) {\n        out << x;\n   \
      \     return *this;\n    }\n\n    SimplePrinter &operator<<(std::ostream &(*f)(std::ostream\
      \ &)) {\n        out << f;\n        return *this;\n    }\n\n    void flush()\
      \ { out << std::flush; }\n};\n\n} // namespace kk2\n\n#endif // KK2_TEMPLATE_SIMPLEIO_HPP\n"
    name: default
  - code: "#line 1 \"template/simpleio.hpp\"\n\n\n\n#include <fstream>\n\n#line 1\
      \ \"type_traits/io.hpp\"\n\n\n\n#include <concepts>\n#line 6 \"type_traits/io.hpp\"\
      \n#include <istream>\n#include <ostream>\n#include <type_traits>\n\nnamespace\
      \ kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag\
      \ {};\n\n} // namespace type_traits\n\ntemplate <typename T>\nusing is_standard_istream\
      \ = typename std::conditional<std::is_same<T, std::istream>::value\n       \
      \                                                   || std::is_same<T, std::ifstream>::value,\n\
      \                                                      std::true_type,\n   \
      \                                                   std::false_type>::type;\n\
      template <typename T>\nusing is_standard_ostream = typename std::conditional<std::is_same<T,\
      \ std::ostream>::value\n                                                   \
      \       || std::is_same<T, std::ofstream>::value,\n                        \
      \                              std::true_type,\n                           \
      \                           std::false_type>::type;\ntemplate <typename T> using\
      \ is_user_defined_istream = std::is_base_of<type_traits::istream_tag, T>;\n\
      template <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
      \ T>;\n\ntemplate <typename T>\nusing is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
      \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
      \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate\
      \ <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\
      \ntemplate <class T>\nconcept StandardInputStream = is_standard_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept StandardOutputStream = is_standard_ostream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept InputStream = is_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept OutputStream = is_ostream<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 7 \"template/simpleio.hpp\"\n\nnamespace kk2\
      \ {\n\nstruct SimplePrinter : type_traits::ostream_tag {\n  private:\n    std::ofstream\
      \ out;\n\n  public:\n    SimplePrinter(const char *s) : out(s) {}\n\n    template\
      \ <class T> SimplePrinter &operator<<(const T &x) {\n        out << x;\n   \
      \     return *this;\n    }\n\n    SimplePrinter &operator<<(std::ostream &(*f)(std::ostream\
      \ &)) {\n        out << f;\n        return *this;\n    }\n\n    void flush()\
      \ { out << std::flush; }\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: template/simpleio.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/simpleio.hpp
layout: document
---
