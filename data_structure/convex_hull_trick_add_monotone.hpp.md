---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/frac_floor.hpp
    title: math/frac_floor.hpp
  - icon: ':x:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
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
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef DATA_STRUCTURE_CONVEX_HULL_TRICK_ADD_MONOTONE_HPP\n#define DATA_STRUCTURE_CONVEX_HULL_TRICK_ADD_MONOTONE_HPP\
    \ 1\n\n#include <cmath>\n#include <deque>\n#include <iostream>\n#include <iterator>\n\
    #include <tuple>\n\n#include \"../math/frac_floor.hpp\"\n#include \"../type_traits/type_traits.hpp\"\
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
    \ (is_integral_extended<T>::value) {\n            return kk2::fracfloor(l2.b -\
    \ l1.b, l1.a - l2.a)\n                   >= kk2::fracfloor(l3.b - l2.b, l2.a -\
    \ l3.a);\n        } else {\n            return (l2.b - l1.b) * sgn(l3.a - l2.a)\
    \ / std::abs(l2.a - l1.a)\n                   >= (l3.b - l2.b) * sgn(l2.a - l1.a)\
    \ / std::abs(l3.a - l2.a);\n        }\n    }\n\n    void add(T a, T b) {\n   \
    \     if (!isMin) a = -a, b = -b;\n        Line l(a, b);\n        if (empty())\
    \ {\n            lines.emplace_back(l);\n            return;\n        }\n    \
    \    if (lines.front().a <= a) {\n            if (lines.front().a == a) {\n  \
    \              if (lines.front().b <= b) return;\n                lines.pop_front();\n\
    \            }\n            lines.emplace_front(l);\n            while ((int)lines.size()\
    \ >= 3 and check(std::next(lines.begin()))) {\n                lines.erase(std::next(lines.begin()));\n\
    \            }\n        } else if (lines.back().a >= a) {\n            if (lines.back().a\
    \ == a) {\n                if (lines.back().b <= b) return;\n                lines.pop_back();\n\
    \            }\n            lines.emplace_back(l);\n            while ((int)lines.size()\
    \ >= 3 and check(std::prev(lines.end(), 2))) {\n                lines.erase(std::prev(lines.end(),\
    \ 2));\n            }\n        } else {\n            std::cerr << \"Invalid input\"\
    \ << std::endl;\n            exit(1);\n        }\n    }\n\n    T query(T x) const\
    \ {\n        assert(!empty());\n        int l = -1, r = (int)lines.size() - 1;\n\
    \        while (r - l > 1) {\n            int mid = (l + r) / 2;\n           \
    \ if (lines[mid].eval(x) >= lines[mid + 1].eval(x)) l = mid;\n            else\
    \ r = mid;\n        }\n        if constexpr (isMin) return lines[r].eval(x);\n\
    \        else return -lines[r].eval(x);\n    }\n};\n\n} // namespace kk2\n\n#endif\
    \ // DATA_STRUCTURE_CONVEX_HULL_TRICK_ADD_MONOTONE_HPP\n"
  dependsOn:
  - math/frac_floor.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: data_structure/convex_hull_trick_add_monotone.hpp
  requiredBy: []
  timestamp: '2024-12-08 12:34:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/convex_hull_trick_add_monotone.hpp
layout: document
redirect_from:
- /library/data_structure/convex_hull_trick_add_monotone.hpp
- /library/data_structure/convex_hull_trick_add_monotone.hpp.html
title: data_structure/convex_hull_trick_add_monotone.hpp
---
