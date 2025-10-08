---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_segment_add_get_min.test.cpp
    title: verify/yosupo_ds/ds_segment_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_segment_add_get_min2.test.cpp
    title: verify/yosupo_ds/ds_segment_add_get_min2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "get min(max) \u30AF\u30A8\u30EA\u304C\u5148\u8AAD\u307F\u3067\
      \u304D\u308B Li-Chao Tree"
    links: []
  bundledCode: "#line 1 \"segment_tree/li_chao_tree.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <numeric>\n#include <optional>\n#include <vector>\n\
    \n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n#include <ostream>\n\
    #include <type_traits>\n\nnamespace kk2 {\n\nnamespace type_traits {\n\nstruct\
    \ istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\ntemplate\
    \ <typename T> using is_standard_istream =\n    typename std::conditional<std::is_same<T,\
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
    \ kk2\n\n\n#line 11 \"segment_tree/li_chao_tree.hpp\"\n\nnamespace kk2 {\n\n/**\n\
    \ * @brief get min(max) \u30AF\u30A8\u30EA\u304C\u5148\u8AAD\u307F\u3067\u304D\
    \u308B Li-Chao Tree\n *\n * @tparam X x\u5EA7\u6A19\u306E\u578B\n * @tparam T\
    \ \u50BE\u304D\u3068\u5207\u7247\u306E\u578B\uFF0E\u639B\u3051\u7B97\u304C\u3067\
    \u304D\u306A\u3044\u3068\u3044\u3051\u306A\u3044\uFF0E\n * @tparam IsMin \u30AF\
    \u30A8\u30EA\u304Cmin\u304Bmax\u304B\n */\ntemplate <class X, class T, bool isMin\
    \ = true> struct LiChaoTree {\n    struct Line {\n        T a, b; // y = ax +\
    \ b\n        bool is_unit;\n        Line() : a(0), b(0), is_unit(true) {}\n  \
    \      Line(T a_, T b_) : a(isMin ? a_ : -a_), b(isMin ? b_ : -b_), is_unit(false)\
    \ {}\n        auto eval(X x) const { return a * x + b; }\n    };\n\n    using\
    \ value_type = decltype(std::declval<Line>().eval(std::declval<X>()));\n\n   \
    \ LiChaoTree(int n_) : n(n_) {\n        if (n == 0) return;\n        lg = 0;\n\
    \        while ((1 << lg) < n) ++lg;\n        siz = 1 << lg;\n        xs.resize(siz);\n\
    \        std::iota(xs.begin(), xs.end(), 0);\n        d.resize(siz * 2, Line());\n\
    \    }\n\n    LiChaoTree(const std::vector<X> &xs_) : xs(xs_) {\n        std::sort(xs.begin(),\
    \ xs.end());\n        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n\
    \        n = xs.size();\n        if (n == 0) return;\n        lg = 0;\n      \
    \  while ((1 << lg) < n) ++lg;\n        siz = 1 << lg;\n        xs.resize(siz);\n\
    \        std::iota(xs.begin() + n, xs.end(), xs[n - 1] + 1);\n        d.resize(siz\
    \ * 2, Line());\n    }\n\n    void add_line(T a, T b) { inner_add(1, lg, Line(a,\
    \ b)); }\n\n    void add_seg(X l, X r, T a, T b) {\n        int ll = std::lower_bound(xs.begin(),\
    \ xs.end(), l) - xs.begin();\n        int rr = std::lower_bound(xs.begin(), xs.end(),\
    \ r) - xs.begin();\n        assert(ll <= rr);\n\n        ll += siz, rr += siz;\n\
    \        Line line(a, b);\n        for (int i = 0; i <= lg and ll < rr; ++i, ll\
    \ >>= 1, rr >>= 1) {\n            if (ll & 1) inner_add(ll, i, line), ++ll;\n\
    \            if (rr & 1) --rr, inner_add(rr, i, line);\n        }\n    }\n\n \
    \   std::optional<value_type> get(X x) const {\n        int pos = std::lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n        assert(0 <= pos and pos < n);\n        assert(xs[pos]\
    \ == x);\n\n        pos += siz;\n        value_type res{};\n        bool has_value\
    \ = false;\n\n        for (; pos; pos >>= 1) {\n            if (d[pos].is_unit)\
    \ continue;\n            if (!has_value) has_value = true, res = d[pos].eval(x);\n\
    \            else if (res > d[pos].eval(x)) res = d[pos].eval(x);\n        }\n\
    \        if (!isMin) res = -res;\n\n        return has_value ? std::optional<value_type>(res)\
    \ : std::nullopt;\n    }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    void debug_output(OStream &os) const {\n        os << \"LiChaoTree:\
    \ n = \" << n << \", lg = \" << lg << \", siz = \" << siz << \"\\n\";\n      \
    \  os << \"Lines:\";\n        for (size_t i = 1; i < d.size(); ++i) {\n      \
    \      if ((i & -i) == i) os << \"\\n[\";\n            os << \" \";\n        \
    \    if (d[i].is_unit) os << \"unit\";\n            else if (isMin) os << d[i].a\
    \ << \"x+\" << d[i].b << \"\";\n            else os << -d[i].a << \"x+\" << -d[i].b\
    \ << \"\";\n            if (((i + 1) & (-i - 1)) == (i + 1)) os << \" ]\";\n\n\
    \            else os << \", \";\n        }\n        os << \"\\nxs: [ \";\n   \
    \     for (const auto &x : xs) os << x << \" \";\n\n        os << \"]\\n\";\n\
    \    }\n\n  private:\n    int n, lg, siz;\n    std::vector<Line> d;\n    std::vector<X>\
    \ xs;\n\n    void inner_add(int k, int h, Line line) {\n        if (n == 0) return;\n\
    \        int l = (k << h) - siz, r = l + (1 << h);\n        while (1) {\n    \
    \        if (d[k].is_unit) {\n                d[k] = line;\n                return;\n\
    \            }\n\n            int mid = (l + r) / 2;\n            auto left_diff\
    \ = d[k].eval(xs[l]) - line.eval(xs[l]);\n            if (k >= siz) {\n      \
    \          if (left_diff > 0) d[k] = line;\n                return;\n        \
    \    }\n            auto right_diff = d[k].eval(xs[r - 1]) - line.eval(xs[r -\
    \ 1]);\n            if (left_diff == right_diff) {\n                if (left_diff\
    \ > 0) d[k] = line;\n                return;\n            }\n            auto\
    \ mid_diff = d[k].eval(xs[mid]) - line.eval(xs[mid]);\n            if (mid_diff\
    \ >= 0) std::swap(d[k], line);\n            if ((left_diff >= 0) == (right_diff\
    \ >= 0)) return;\n            if ((left_diff >= 0) == (mid_diff >= 0)) k = k <<\
    \ 1 | 1, l = mid;\n            else k = k << 1, r = mid;\n        }\n    }\n};\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_SEGMENT_TREE_LI_CHAO_TREE_HPP\n#define KK2_SEGMENT_TREE_LI_CHAO_TREE_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n#include\
    \ <optional>\n#include <vector>\n\n#include \"../type_traits/io.hpp\"\n\nnamespace\
    \ kk2 {\n\n/**\n * @brief get min(max) \u30AF\u30A8\u30EA\u304C\u5148\u8AAD\u307F\
    \u3067\u304D\u308B Li-Chao Tree\n *\n * @tparam X x\u5EA7\u6A19\u306E\u578B\n\
    \ * @tparam T \u50BE\u304D\u3068\u5207\u7247\u306E\u578B\uFF0E\u639B\u3051\u7B97\
    \u304C\u3067\u304D\u306A\u3044\u3068\u3044\u3051\u306A\u3044\uFF0E\n * @tparam\
    \ IsMin \u30AF\u30A8\u30EA\u304Cmin\u304Bmax\u304B\n */\ntemplate <class X, class\
    \ T, bool isMin = true> struct LiChaoTree {\n    struct Line {\n        T a, b;\
    \ // y = ax + b\n        bool is_unit;\n        Line() : a(0), b(0), is_unit(true)\
    \ {}\n        Line(T a_, T b_) : a(isMin ? a_ : -a_), b(isMin ? b_ : -b_), is_unit(false)\
    \ {}\n        auto eval(X x) const { return a * x + b; }\n    };\n\n    using\
    \ value_type = decltype(std::declval<Line>().eval(std::declval<X>()));\n\n   \
    \ LiChaoTree(int n_) : n(n_) {\n        if (n == 0) return;\n        lg = 0;\n\
    \        while ((1 << lg) < n) ++lg;\n        siz = 1 << lg;\n        xs.resize(siz);\n\
    \        std::iota(xs.begin(), xs.end(), 0);\n        d.resize(siz * 2, Line());\n\
    \    }\n\n    LiChaoTree(const std::vector<X> &xs_) : xs(xs_) {\n        std::sort(xs.begin(),\
    \ xs.end());\n        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n\
    \        n = xs.size();\n        if (n == 0) return;\n        lg = 0;\n      \
    \  while ((1 << lg) < n) ++lg;\n        siz = 1 << lg;\n        xs.resize(siz);\n\
    \        std::iota(xs.begin() + n, xs.end(), xs[n - 1] + 1);\n        d.resize(siz\
    \ * 2, Line());\n    }\n\n    void add_line(T a, T b) { inner_add(1, lg, Line(a,\
    \ b)); }\n\n    void add_seg(X l, X r, T a, T b) {\n        int ll = std::lower_bound(xs.begin(),\
    \ xs.end(), l) - xs.begin();\n        int rr = std::lower_bound(xs.begin(), xs.end(),\
    \ r) - xs.begin();\n        assert(ll <= rr);\n\n        ll += siz, rr += siz;\n\
    \        Line line(a, b);\n        for (int i = 0; i <= lg and ll < rr; ++i, ll\
    \ >>= 1, rr >>= 1) {\n            if (ll & 1) inner_add(ll, i, line), ++ll;\n\
    \            if (rr & 1) --rr, inner_add(rr, i, line);\n        }\n    }\n\n \
    \   std::optional<value_type> get(X x) const {\n        int pos = std::lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n        assert(0 <= pos and pos < n);\n        assert(xs[pos]\
    \ == x);\n\n        pos += siz;\n        value_type res{};\n        bool has_value\
    \ = false;\n\n        for (; pos; pos >>= 1) {\n            if (d[pos].is_unit)\
    \ continue;\n            if (!has_value) has_value = true, res = d[pos].eval(x);\n\
    \            else if (res > d[pos].eval(x)) res = d[pos].eval(x);\n        }\n\
    \        if (!isMin) res = -res;\n\n        return has_value ? std::optional<value_type>(res)\
    \ : std::nullopt;\n    }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    void debug_output(OStream &os) const {\n        os << \"LiChaoTree:\
    \ n = \" << n << \", lg = \" << lg << \", siz = \" << siz << \"\\n\";\n      \
    \  os << \"Lines:\";\n        for (size_t i = 1; i < d.size(); ++i) {\n      \
    \      if ((i & -i) == i) os << \"\\n[\";\n            os << \" \";\n        \
    \    if (d[i].is_unit) os << \"unit\";\n            else if (isMin) os << d[i].a\
    \ << \"x+\" << d[i].b << \"\";\n            else os << -d[i].a << \"x+\" << -d[i].b\
    \ << \"\";\n            if (((i + 1) & (-i - 1)) == (i + 1)) os << \" ]\";\n\n\
    \            else os << \", \";\n        }\n        os << \"\\nxs: [ \";\n   \
    \     for (const auto &x : xs) os << x << \" \";\n\n        os << \"]\\n\";\n\
    \    }\n\n  private:\n    int n, lg, siz;\n    std::vector<Line> d;\n    std::vector<X>\
    \ xs;\n\n    void inner_add(int k, int h, Line line) {\n        if (n == 0) return;\n\
    \        int l = (k << h) - siz, r = l + (1 << h);\n        while (1) {\n    \
    \        if (d[k].is_unit) {\n                d[k] = line;\n                return;\n\
    \            }\n\n            int mid = (l + r) / 2;\n            auto left_diff\
    \ = d[k].eval(xs[l]) - line.eval(xs[l]);\n            if (k >= siz) {\n      \
    \          if (left_diff > 0) d[k] = line;\n                return;\n        \
    \    }\n            auto right_diff = d[k].eval(xs[r - 1]) - line.eval(xs[r -\
    \ 1]);\n            if (left_diff == right_diff) {\n                if (left_diff\
    \ > 0) d[k] = line;\n                return;\n            }\n            auto\
    \ mid_diff = d[k].eval(xs[mid]) - line.eval(xs[mid]);\n            if (mid_diff\
    \ >= 0) std::swap(d[k], line);\n            if ((left_diff >= 0) == (right_diff\
    \ >= 0)) return;\n            if ((left_diff >= 0) == (mid_diff >= 0)) k = k <<\
    \ 1 | 1, l = mid;\n            else k = k << 1, r = mid;\n        }\n    }\n};\n\
    \n} // namespace kk2\n\n#endif // KK2_SEGMENT_TREE_LI_CHAO_TREE_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  isVerificationFile: false
  path: segment_tree/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_segment_add_get_min2.test.cpp
  - verify/yosupo_ds/ds_segment_add_get_min.test.cpp
documentation_of: segment_tree/li_chao_tree.hpp
layout: document
redirect_from:
- /library/segment_tree/li_chao_tree.hpp
- /library/segment_tree/li_chao_tree.hpp.html
title: "get min(max) \u30AF\u30A8\u30EA\u304C\u5148\u8AAD\u307F\u3067\u304D\u308B\
  \ Li-Chao Tree"
---
