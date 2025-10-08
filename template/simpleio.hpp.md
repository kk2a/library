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
  bundledCode: "#line 1 \"template/simpleio.hpp\"\n\n\n\n#include <fstream>\n\n#line\
    \ 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n#include <ostream>\n#include\
    \ <type_traits>\n\nnamespace kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag\
    \ {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\ntemplate <typename\
    \ T> using is_standard_istream =\n    typename std::conditional<std::is_same<T,\
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
    \ kk2\n\n\n#line 7 \"template/simpleio.hpp\"\n\nnamespace kk2 {\n\nstruct SimplePrinter\
    \ : type_traits::ostream_tag {\n  private:\n    std::ofstream out;\n\n  public:\n\
    \    SimplePrinter(const char *s) : out(s) {}\n\n    template <class T> SimplePrinter\
    \ &operator<<(const T &x) {\n        out << x;\n        return *this;\n    }\n\
    \n    SimplePrinter &operator<<(std::ostream &(*f)(std::ostream &)) {\n      \
    \  out << f;\n        return *this;\n    }\n\n    void flush() { out << std::flush;\
    \ }\n};\n\n} // namespace kk2\n\n\n"
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
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/simpleio.hpp
layout: document
redirect_from:
- /library/template/simpleio.hpp
- /library/template/simpleio.hpp.html
title: template/simpleio.hpp
---
