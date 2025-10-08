---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/monoid/max_min_sumwithsize.hpp
    title: math/monoid/max_min_sumwithsize.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/update.hpp
    title: "\u5E38\u306B\u5DE6\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\u30A4\
      \u30C9"
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/action/action.test.cpp
    title: verify/unit_test/math/action/action.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/action/update_max_min_sumwithsize.hpp\"\n\n\n\n#line\
    \ 1 \"math/monoid/max_min_sumwithsize.hpp\"\n\n\n\n#include <functional>\n\n#line\
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
    \ kk2\n\n\n#line 7 \"math/monoid/max_min_sumwithsize.hpp\"\n\nnamespace kk2 {\n\
    \nnamespace monoid {\n\ntemplate <class S, class T, class Compare = std::less<S>>\
    \ struct MaxMinSumWithSize {\n    static constexpr bool commutative = true;\n\
    \    using M = MaxMinSumWithSize;\n    S max, min, sum;\n    T size;\n    bool\
    \ is_unit;\n\n    MaxMinSumWithSize() : is_unit(true) {}\n    MaxMinSumWithSize(S\
    \ a) : max(a), min(a), sum(a), size(1), is_unit(false) {}\n    MaxMinSumWithSize(S\
    \ max_, S min_, S sum_, T size_)\n        : max(max_),\n          min(min_),\n\
    \          sum(sum_),\n          size(size_),\n          is_unit(false) {}\n\n\
    \    inline static M op(M l, M r) {\n        if (l.is_unit or r.is_unit) return\
    \ l.is_unit ? r : l;\n        return M(Compare{}(l.max, r.max) ? r.max : l.max,\n\
    \                 Compare{}(l.min, r.min) ? l.min : r.min,\n                 l.sum\
    \ + r.sum,\n                 l.size + r.size);\n    }\n\n    inline static M unit()\
    \ { return M(); }\n\n    bool operator==(const M &rhs) const {\n        return\
    \ is_unit == rhs.is_unit\n               and (is_unit\n                    or\
    \ (max == rhs.max and min == rhs.min and sum == rhs.sum and size == rhs.size));\n\
    \    }\n\n    bool operator!=(const M &rhs) const {\n        return is_unit !=\
    \ rhs.is_unit\n               or (!is_unit\n                   and (max != rhs.max\
    \ or min != rhs.min or sum != rhs.sum or size != rhs.size));\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const M &x) {\n        if (x.is_unit) os << \"(unit)\";\n        else\n\
    \            os << \"(max:\" << x.max << \", min:\" << x.min << \", sum:\" <<\
    \ x.sum << \", size:\" << x.size\n               << \")\";\n        return os;\n\
    \    }\n\n    template <class IStream, is_istream_t<IStream> * = nullptr>\n  \
    \  friend IStream &operator>>(IStream &is, M &x) {\n        S a;\n        is >>\
    \ a;\n        x = M(a);\n        return is;\n    }\n};\n\n} // namespace monoid\n\
    \n} // namespace kk2\n\n\n#line 1 \"math/monoid/update.hpp\"\n\n\n\n#line 5 \"\
    math/monoid/update.hpp\"\n\nnamespace kk2 {\n\nnamespace monoid {\n\n/**\n * @brief\
    \ \u5E38\u306B\u5DE6\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\u30A4\u30C9\
    \n */\ntemplate <class S> struct Update {\n    static constexpr bool commutative\
    \ = true;\n    using M = Update;\n    S a;\n    bool is_unit;\n\n    Update()\
    \ : is_unit(true) {}\n    Update(S a_) : a(a_), is_unit(false) {}\n    operator\
    \ S() const { return a; }\n    inline static M op(M l, M r) { return l.is_unit\
    \ ? r : l; }\n    inline static M unit() { return M(); }\n\n    bool operator==(const\
    \ M &rhs) const {\n        return is_unit == rhs.is_unit and (is_unit or a ==\
    \ rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const {\n        return\
    \ is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const M &x) {\n        if (x.is_unit) os << \"unit\";\n        else os\
    \ << x.a;\n        return os;\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    friend IStream &operator>>(IStream &is, M &x) {\n        is\
    \ >> x.a;\n        x.is_unit = false;\n        return is;\n    }\n};\n\n} // namespace\
    \ monoid\n\n} // namespace kk2\n\n\n#line 6 \"math/action/update_max_min_sumwithsize.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace action {\n\ntemplate <class T, class U, class\
    \ Compare = std::less<T>> struct UpdateMaxMinSumWithSize {\n    using S = monoid::MaxMinSumWithSize<T,\
    \ U, Compare>;\n    using A = monoid::Update<T>;\n\n    inline static S act(A\
    \ f, S x) { return f.is_unit ? x : S(f.a, f.a, f.a * x.size, x.size); }\n};\n\n\
    } // namespace action\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_ACTION_UPDATE_MAX_MIN_SUMWITHSIZE_HPP\n#define KK2_MATH_ACTION_UPDATE_MAX_MIN_SUMWITHSIZE_HPP\
    \ 1\n\n#include \"../monoid/max_min_sumwithsize.hpp\"\n#include \"../monoid/update.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace action {\n\ntemplate <class T, class U, class\
    \ Compare = std::less<T>> struct UpdateMaxMinSumWithSize {\n    using S = monoid::MaxMinSumWithSize<T,\
    \ U, Compare>;\n    using A = monoid::Update<T>;\n\n    inline static S act(A\
    \ f, S x) { return f.is_unit ? x : S(f.a, f.a, f.a * x.size, x.size); }\n};\n\n\
    } // namespace action\n\n} // namespace kk2\n\n#endif // KK2_MATH_ACTION_UPDATE_MAX_MIN_SUMWITHSIZE_HPP\n"
  dependsOn:
  - math/monoid/max_min_sumwithsize.hpp
  - type_traits/io.hpp
  - math/monoid/update.hpp
  isVerificationFile: false
  path: math/action/update_max_min_sumwithsize.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/action/action.test.cpp
documentation_of: math/action/update_max_min_sumwithsize.hpp
layout: document
redirect_from:
- /library/math/action/update_max_min_sumwithsize.hpp
- /library/math/action/update_max_min_sumwithsize.hpp.html
title: math/action/update_max_min_sumwithsize.hpp
---
