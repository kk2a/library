---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: sum_with_size.hpp
      icon: LIBRARY_ALL_AC
      path: math/group/sum_with_size.hpp
    - filename: update.hpp
      icon: LIBRARY_ALL_AC
      path: math/monoid/update.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: action.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/action/action.test.cpp
    type: Verified with
  dependsOn:
  - math/group/sum_with_size.hpp
  - math/monoid/update.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_MATH_ACTION_UPDATE_SUMWITHSIZE_HPP\n#define KK2_MATH_ACTION_UPDATE_SUMWITHSIZE_HPP\
      \ 1\n\n#include \"../group/sum_with_size.hpp\"\n#include \"../monoid/update.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace action {\n\ntemplate <class T, class U> struct\
      \ UpdateSumWithSize {\n    using S = group::SumWithSize<T, U>;\n    using A\
      \ = monoid::Update<T>;\n\n    inline static S act(A f, S x) { return f.is_unit\
      \ ? x : S(f.a * x.size, x.size); }\n};\n\n} // namespace action\n\n} // namespace\
      \ kk2\n\n#endif // KK2_MATH_ACTION_UPDATE_SUMWITHSIZE_HPP\n"
    name: default
  - code: "#line 1 \"math/action/update_sumwithsize.hpp\"\n\n\n\n#line 1 \"math/group/sum_with_size.hpp\"\
      \n\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <concepts>\n#include\
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
      \n} // namespace kk2\n\n\n#line 5 \"math/group/sum_with_size.hpp\"\n\nnamespace\
      \ kk2 {\n\nnamespace group {\n\ntemplate <class S, class T = S> struct SumWithSize\
      \ {\n    static constexpr bool commutative = true;\n    using M = SumWithSize;\n\
      \    S a;\n    T size;\n\n    SumWithSize() : a(S()), size(0) {}\n    SumWithSize(S\
      \ a_, S size_ = T(1)) : a(a_), size(size_) {}\n    operator S() const { return\
      \ a; }\n    inline static M op(M l, M r) { return M(l.a + r.a, l.size + r.size);\
      \ }\n    inline static M inv(M x) { return M(-x.a, -x.size); }\n    inline static\
      \ M unit() { return M(); }\n    bool operator==(const M &rhs) const { return\
      \ a == rhs.a and size == rhs.size; }\n    bool operator!=(const M &rhs) const\
      \ { return a != rhs.a or size != rhs.size; }\n\n    template <OutputStream OStream>\n\
      \    friend OStream &operator<<(OStream &os, const M &x) {\n        return os\
      \ << x.a << \" \" << x.size;\n    }\n\n    template <InputStream IStream>\n\
      \    friend IStream &operator>>(IStream &is, M &x) {\n        is >> x.a;\n \
      \       x.size = T(1);\n        return is;\n    }\n};\n\n} // namespace group\n\
      \n} // namespace kk2\n\n\n#line 1 \"math/monoid/update.hpp\"\n\n\n\n#line 5\
      \ \"math/monoid/update.hpp\"\n\nnamespace kk2 {\n\nnamespace monoid {\n\n/**\n\
      \ * @brief \u5E38\u306B\u5DE6\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\
      \u30A4\u30C9\n */\ntemplate <class S> struct Update {\n    static constexpr\
      \ bool commutative = true;\n    using M = Update;\n    S a;\n    bool is_unit;\n\
      \n    Update() : is_unit(true) {}\n    Update(S a_) : a(a_), is_unit(false)\
      \ {}\n    operator S() const { return a; }\n    inline static M op(M l, M r)\
      \ { return l.is_unit ? r : l; }\n    inline static M unit() { return M(); }\n\
      \n    bool operator==(const M &rhs) const {\n        return is_unit == rhs.is_unit\
      \ and (is_unit or a == rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const\
      \ {\n        return is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n \
      \   }\n\n    template <OutputStream OStream>\n    friend OStream &operator<<(OStream\
      \ &os, const M &x) {\n        if (x.is_unit) os << \"unit\";\n        else os\
      \ << x.a;\n        return os;\n    }\n\n    template <InputStream IStream>\n\
      \    friend IStream &operator>>(IStream &is, M &x) {\n        is >> x.a;\n \
      \       x.is_unit = false;\n        return is;\n    }\n};\n\n} // namespace\
      \ monoid\n\n} // namespace kk2\n\n\n#line 6 \"math/action/update_sumwithsize.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace action {\n\ntemplate <class T, class U> struct\
      \ UpdateSumWithSize {\n    using S = group::SumWithSize<T, U>;\n    using A\
      \ = monoid::Update<T>;\n\n    inline static S act(A f, S x) { return f.is_unit\
      \ ? x : S(f.a * x.size, x.size); }\n};\n\n} // namespace action\n\n} // namespace\
      \ kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/action/update_sumwithsize.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/action/action.test.cpp
documentation_of: math/action/update_sumwithsize.hpp
layout: document
---
