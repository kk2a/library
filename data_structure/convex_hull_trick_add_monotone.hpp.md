---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/frac_floor.hpp
    title: math/frac_floor.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/convex_hull_trick_add_monotone.hpp\"\n\n\n\
    \n#include <cmath>\n#include <deque>\n#include <iostream>\n#include <iterator>\n\
    #include <tuple>\n\n#line 1 \"math/frac_floor.hpp\"\n\n\n\n#include <cassert>\n\
    \nnamespace kk2 {\n\n// floor(x) = ceil(x) - 1 (for all x not in Z) ...(1)\n//\
    \ floor(x) = -ceil(-x)   (for all x)          ...(2)\n\n// return floor(a / b)\n\
    template <typename T, typename U> constexpr T fracfloor(T a, U b) {\n    assert(b\
    \ != 0);\n    if (a % b == 0) return a / b;\n    if (a >= 0) return a / b;\n\n\
    \    // floor(x) = -ceil(-x)      by (2)\n    //          = -floor(-x) - 1 by\
    \ (1)\n    return -((-a) / b) - 1;\n}\n\n// return ceil(a / b)\ntemplate <typename\
    \ T, typename U> constexpr T fracceil(T a, U b) {\n    assert(b != 0);\n    if\
    \ (a % b == 0) return a / b;\n    if (a >= 0) return a / b + 1;\n\n    // ceil(x)\
    \ = -floor(-x)      by (2)\n    return -((-a) / b);\n}\n\n} // namespace kk2\n\
    \n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace\
    \ kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T> using is_signed_int128 =\n\
    \    typename std::conditional<std::is_same<T, __int128_t>::value\n          \
    \                        or std::is_same<T, __int128>::value,\n              \
    \                std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value\n                                  or std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <typename T> using is_integral\
    \ =\n    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
    \                                  or is_unsigned_int128<T>::value,\n        \
    \                      std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_signed =\n    typename std::conditional<std::is_signed<T>::value\
    \ or is_signed_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
    \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename T>\
    \ using to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
    \                              make_unsigned_int128<T>,\n                    \
    \          typename std::conditional<std::is_signed<T>::value,\n             \
    \                                           std::make_unsigned<T>,\n         \
    \                                               std::common_type<T>>::type>::type;\n\
    \n#else\n\ntemplate <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
    template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
    template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
    template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
    \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
    template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
    template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
    \n} // namespace kk2\n\n\n#line 12 \"data_structure/convex_hull_trick_add_monotone.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename T, bool isMin = true> struct CHTAddMonotone\
    \ {\n    struct Line {\n        // ax + b\n        T a, b;\n\n        Line(T a_,\
    \ T b_) : a(a_), b(b_) {}\n\n        T eval(T x) const { return a * x + b; }\n\
    \    };\n\n    std::deque<Line> lines;\n\n    CHTAddMonotone() = default;\n\n\
    \    bool empty() const { return lines.empty(); }\n\n    void clear() { lines.clear();\
    \ }\n\n    static constexpr int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1 : 1);\
    \ }\n\n    template <typename Iterators> static constexpr bool check(Iterators\
    \ mid) {\n        auto [l1, l2, l3] = std::tie(*std::prev(mid), *mid, *std::next(mid));\n\
    \        if (l2.b == l1.b or l3.b == l2.b)\n            return sgn(l2.a - l1.a)\
    \ * sgn(l3.b - l2.b) >= sgn(l3.a - l2.a) * sgn(l2.b - l1.b);\n        if constexpr\
    \ (is_integral<T>::value) {\n            return kk2::fracfloor(l2.b - l1.b, l1.a\
    \ - l2.a)\n                   >= kk2::fracfloor(l3.b - l2.b, l2.a - l3.a);\n \
    \       } else {\n            return (l2.b - l1.b) * sgn(l3.a - l2.a) / std::abs(l2.a\
    \ - l1.a)\n                   >= (l3.b - l2.b) * sgn(l2.a - l1.a) / std::abs(l3.a\
    \ - l2.a);\n        }\n    }\n\n    void add(T a, T b) {\n        if (!isMin)\
    \ a = -a, b = -b;\n        Line l(a, b);\n        if (empty()) {\n           \
    \ lines.emplace_back(l);\n            return;\n        }\n        if (lines.front().a\
    \ <= a) {\n            if (lines.front().a == a) {\n                if (lines.front().b\
    \ <= b) return;\n                lines.pop_front();\n            }\n         \
    \   lines.emplace_front(l);\n            while ((int)lines.size() >= 3 and check(std::next(lines.begin())))\
    \ {\n                lines.erase(std::next(lines.begin()));\n            }\n \
    \       } else if (lines.back().a >= a) {\n            if (lines.back().a == a)\
    \ {\n                if (lines.back().b <= b) return;\n                lines.pop_back();\n\
    \            }\n            lines.emplace_back(l);\n            while ((int)lines.size()\
    \ >= 3 and check(std::prev(lines.end(), 2))) {\n                lines.erase(std::prev(lines.end(),\
    \ 2));\n            }\n        } else {\n            std::cerr << \"Invalid input\"\
    \ << std::endl;\n            exit(1);\n        }\n    }\n\n    T query(T x) const\
    \ {\n        assert(!empty());\n        int l = -1, r = (int)lines.size() - 1;\n\
    \        while (r - l > 1) {\n            int mid = (l + r) / 2;\n           \
    \ if (lines[mid].eval(x) >= lines[mid + 1].eval(x)) l = mid;\n            else\
    \ r = mid;\n        }\n        if constexpr (isMin) return lines[r].eval(x);\n\
    \        else return -lines[r].eval(x);\n    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_DATA_STRUCTURE_CONVEX_HULL_TRICK_ADD_MONOTONE_HPP\n#define KK2_DATA_STRUCTURE_CONVEX_HULL_TRICK_ADD_MONOTONE_HPP\
    \ 1\n\n#include <cmath>\n#include <deque>\n#include <iostream>\n#include <iterator>\n\
    #include <tuple>\n\n#include \"../math/frac_floor.hpp\"\n#include \"../type_traits/integral.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename T, bool isMin = true> struct CHTAddMonotone\
    \ {\n    struct Line {\n        // ax + b\n        T a, b;\n\n        Line(T a_,\
    \ T b_) : a(a_), b(b_) {}\n\n        T eval(T x) const { return a * x + b; }\n\
    \    };\n\n    std::deque<Line> lines;\n\n    CHTAddMonotone() = default;\n\n\
    \    bool empty() const { return lines.empty(); }\n\n    void clear() { lines.clear();\
    \ }\n\n    static constexpr int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1 : 1);\
    \ }\n\n    template <typename Iterators> static constexpr bool check(Iterators\
    \ mid) {\n        auto [l1, l2, l3] = std::tie(*std::prev(mid), *mid, *std::next(mid));\n\
    \        if (l2.b == l1.b or l3.b == l2.b)\n            return sgn(l2.a - l1.a)\
    \ * sgn(l3.b - l2.b) >= sgn(l3.a - l2.a) * sgn(l2.b - l1.b);\n        if constexpr\
    \ (is_integral<T>::value) {\n            return kk2::fracfloor(l2.b - l1.b, l1.a\
    \ - l2.a)\n                   >= kk2::fracfloor(l3.b - l2.b, l2.a - l3.a);\n \
    \       } else {\n            return (l2.b - l1.b) * sgn(l3.a - l2.a) / std::abs(l2.a\
    \ - l1.a)\n                   >= (l3.b - l2.b) * sgn(l2.a - l1.a) / std::abs(l3.a\
    \ - l2.a);\n        }\n    }\n\n    void add(T a, T b) {\n        if (!isMin)\
    \ a = -a, b = -b;\n        Line l(a, b);\n        if (empty()) {\n           \
    \ lines.emplace_back(l);\n            return;\n        }\n        if (lines.front().a\
    \ <= a) {\n            if (lines.front().a == a) {\n                if (lines.front().b\
    \ <= b) return;\n                lines.pop_front();\n            }\n         \
    \   lines.emplace_front(l);\n            while ((int)lines.size() >= 3 and check(std::next(lines.begin())))\
    \ {\n                lines.erase(std::next(lines.begin()));\n            }\n \
    \       } else if (lines.back().a >= a) {\n            if (lines.back().a == a)\
    \ {\n                if (lines.back().b <= b) return;\n                lines.pop_back();\n\
    \            }\n            lines.emplace_back(l);\n            while ((int)lines.size()\
    \ >= 3 and check(std::prev(lines.end(), 2))) {\n                lines.erase(std::prev(lines.end(),\
    \ 2));\n            }\n        } else {\n            std::cerr << \"Invalid input\"\
    \ << std::endl;\n            exit(1);\n        }\n    }\n\n    T query(T x) const\
    \ {\n        assert(!empty());\n        int l = -1, r = (int)lines.size() - 1;\n\
    \        while (r - l > 1) {\n            int mid = (l + r) / 2;\n           \
    \ if (lines[mid].eval(x) >= lines[mid + 1].eval(x)) l = mid;\n            else\
    \ r = mid;\n        }\n        if constexpr (isMin) return lines[r].eval(x);\n\
    \        else return -lines[r].eval(x);\n    }\n};\n\n} // namespace kk2\n\n#endif\
    \ // KK2_DATA_STRUCTURE_CONVEX_HULL_TRICK_ADD_MONOTONE_HPP\n"
  dependsOn:
  - math/frac_floor.hpp
  - type_traits/integral.hpp
  isVerificationFile: false
  path: data_structure/convex_hull_trick_add_monotone.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/convex_hull_trick_add_monotone.hpp
layout: document
redirect_from:
- /library/data_structure/convex_hull_trick_add_monotone.hpp
- /library/data_structure/convex_hull_trick_add_monotone.hpp.html
title: data_structure/convex_hull_trick_add_monotone.hpp
---
