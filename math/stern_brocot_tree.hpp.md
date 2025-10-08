---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_math/rational_approximation.test.cpp
    title: verify/yosupo_math/rational_approximation.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/stern_brocot_tree.test.cpp
    title: verify/yosupo_math/stern_brocot_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Stern-Brocot tree
    links: []
  bundledCode: "#line 1 \"math/stern_brocot_tree.hpp\"\n\n\n\n#include <algorithm>\n\
    \nnamespace kk2 {\n\ntemplate <class T> struct SternBrocotTreeNode {\n    T lnum,\
    \ lden;\n    T rnum, rden;\n    // even: right, odd: left\n    std::vector<T>\
    \ path;\n    T dep;\n\n    SternBrocotTreeNode() : lnum(0), lden(1), rnum(1),\
    \ rden(0), path({0}), dep(0) {}\n    SternBrocotTreeNode(T x, T y) : lnum(0),\
    \ lden(1), rnum(1), rden(0), path({0}), dep(0) {\n        assert(x > 0 and y >\
    \ 0);\n        bool left = false;\n        for (; y; left = !left) {\n       \
    \     T q = x / y, r = x - q * y;\n            go_down(left, q - (r == 0));\n\
    \            x = y, y = r;\n        }\n    }\n    SternBrocotTreeNode(const std::vector<T>\
    \ &p) : lnum(0), lden(1), rnum(1), rden(0), path({0}) {\n        for (auto d :\
    \ p) go_down(path.size() & 1, d);\n    }\n    SternBrocotTreeNode(const std::vector<std::pair<char,\
    \ T>> &p)\n        : lnum(0),\n          lden(1),\n          rnum(1),\n      \
    \    rden(0),\n          path({0}) {\n        for (auto [c, d] : p) go_down(c\
    \ == 'L', d);\n    }\n\n    void go_down(bool left, T d = 1) {\n        assert(d\
    \ >= 0);\n        dep += d;\n        if (left) rnum += d * lnum, rden += d * lden;\n\
    \        else lnum += d * rnum, lden += d * rden;\n        if ((path.size() &\
    \ 1) == left) path.emplace_back(d);\n        else path.back() += d;\n    }\n\n\
    \    bool go_up(T d = 1) {\n        if (d < 0 or dep < d) return false;\n    \
    \    while (d) {\n            T step = std::min(d, path.back());\n           \
    \ dep -= step, d -= step;\n            if (path.size() & 1) lnum -= step * rnum,\
    \ lden -= step * rden;\n            else rnum -= step * lnum, rden -= step * lden;\n\
    \            if (path.back() == step) path.pop_back();\n            else path.back()\
    \ -= step;\n        }\n        if (path.empty()) path.emplace_back(0);\n     \
    \   return true;\n    }\n\n    std::pair<T, T> val() const { return {lnum + rnum,\
    \ lden + rden}; }\n    std::tuple<T, T, T, T> range() const { return {lnum, lden,\
    \ rnum, rden}; }\n    const std::vector<T> &get_path() const { return path; }\n\
    \    T get_depth() const { return dep; }\n};\n\n/**\n * @brief Stern-Brocot tree\n\
    \ *\n * @tparam T \u639B\u3051\u7B97\u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u3057\u306A\u3044\u3088\u3046\u306B\u8A2D\u5B9A\u3059\u308B\u3053\u3068\
    \n */\ntemplate <class T> struct SternBrocotTree {\n    using Node = SternBrocotTreeNode<T>;\n\
    \    inline static Node root = Node();\n\n    static Node lca(const Node &u, const\
    \ Node &v) {\n        Node res = root;\n        T len = std::min(u.path.size(),\
    \ v.path.size());\n        for (T i = 0; i < len; i++) {\n            T d = std::min(u.path[i],\
    \ v.path[i]);\n            res.go_down(i & 1, d);\n            if (u.path[i] !=\
    \ v.path[i]) break;\n        }\n        return res;\n    }\n\n    /**\n     *\
    \ @brief Stern-Brocot tree \u4E0A\u3067\u4E8C\u5206\u63A2\u7D22\u3092\u3059\u308B\
    \n     *\n     * @param f \u5224\u5B9A\u95A2\u6570`f(num, den)->bool`, \u5358\u8ABF\
    \u3067`f(0, 1)=true, f(1, 0)=false`\n     * @param N \u5206\u6BCD\u3068\u5206\u5B50\
    \u306F\u3068\u3082\u306B`N`\u4EE5\u4E0B\uFF0E`2N`\u304C\u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC\u3057\u306A\u3044\u3053\u3068\u3092\u4FDD\u8A3C\u3059\u308B\
    \u3053\u3068\n     *\n     * @return `std::tuple<T, T, T, T>`\n     *\n     *\
    \ - `lnum/lden = max{x/y : f(x, y) = true, max(x, y) <= N}`\n     *\n     * -\
    \ `rnum/rden = min{x/y : f(x, y) = false, max(x, y) <= N}`\n     *\n     * - `return\
    \ {lnum, lden, rnum, rden}`\n     */\n    template <class F> static std::tuple<T,\
    \ T, T, T> binary_search(T N, F f) {\n        assert(N > 0);\n        assert(f(0,\
    \ 1) and !f(1, 0));\n\n        T num1 = 0, den1 = 1, num2 = 1, den2 = 0;\n   \
    \     bool left = false;\n        while (num1 + num2 <= N and den1 + den2 <= N)\
    \ {\n            for (int i = 0;; ++i) {\n                T num = num1 + (num2\
    \ << i), den = den1 + (den2 << i);\n                if (num > N or den > N or\
    \ f(num, den) == left) {\n                    while (i--) {\n                \
    \        num = num1 + (num2 << i), den = den1 + (den2 << i);\n               \
    \         if (num <= N and den <= N and f(num, den) != left) num1 = num, den1\
    \ = den;\n                    }\n                    break;\n                }\n\
    \            }\n            std::swap(num1, num2), std::swap(den1, den2), left\
    \ = !left;\n        }\n        if (left) std::swap(num1, num2), std::swap(den1,\
    \ den2);\n        return {num1, den1, num2, den2};\n    }\n};\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_MATH_STERN_BROCOT_TREE_HPP\n#define KK2_MATH_STERN_BROCOT_TREE_HPP\
    \ 1\n\n#include <algorithm>\n\nnamespace kk2 {\n\ntemplate <class T> struct SternBrocotTreeNode\
    \ {\n    T lnum, lden;\n    T rnum, rden;\n    // even: right, odd: left\n   \
    \ std::vector<T> path;\n    T dep;\n\n    SternBrocotTreeNode() : lnum(0), lden(1),\
    \ rnum(1), rden(0), path({0}), dep(0) {}\n    SternBrocotTreeNode(T x, T y) :\
    \ lnum(0), lden(1), rnum(1), rden(0), path({0}), dep(0) {\n        assert(x >\
    \ 0 and y > 0);\n        bool left = false;\n        for (; y; left = !left) {\n\
    \            T q = x / y, r = x - q * y;\n            go_down(left, q - (r ==\
    \ 0));\n            x = y, y = r;\n        }\n    }\n    SternBrocotTreeNode(const\
    \ std::vector<T> &p) : lnum(0), lden(1), rnum(1), rden(0), path({0}) {\n     \
    \   for (auto d : p) go_down(path.size() & 1, d);\n    }\n    SternBrocotTreeNode(const\
    \ std::vector<std::pair<char, T>> &p)\n        : lnum(0),\n          lden(1),\n\
    \          rnum(1),\n          rden(0),\n          path({0}) {\n        for (auto\
    \ [c, d] : p) go_down(c == 'L', d);\n    }\n\n    void go_down(bool left, T d\
    \ = 1) {\n        assert(d >= 0);\n        dep += d;\n        if (left) rnum +=\
    \ d * lnum, rden += d * lden;\n        else lnum += d * rnum, lden += d * rden;\n\
    \        if ((path.size() & 1) == left) path.emplace_back(d);\n        else path.back()\
    \ += d;\n    }\n\n    bool go_up(T d = 1) {\n        if (d < 0 or dep < d) return\
    \ false;\n        while (d) {\n            T step = std::min(d, path.back());\n\
    \            dep -= step, d -= step;\n            if (path.size() & 1) lnum -=\
    \ step * rnum, lden -= step * rden;\n            else rnum -= step * lnum, rden\
    \ -= step * lden;\n            if (path.back() == step) path.pop_back();\n   \
    \         else path.back() -= step;\n        }\n        if (path.empty()) path.emplace_back(0);\n\
    \        return true;\n    }\n\n    std::pair<T, T> val() const { return {lnum\
    \ + rnum, lden + rden}; }\n    std::tuple<T, T, T, T> range() const { return {lnum,\
    \ lden, rnum, rden}; }\n    const std::vector<T> &get_path() const { return path;\
    \ }\n    T get_depth() const { return dep; }\n};\n\n/**\n * @brief Stern-Brocot\
    \ tree\n *\n * @tparam T \u639B\u3051\u7B97\u304C\u30AA\u30FC\u30D0\u30FC\u30D5\
    \u30ED\u30FC\u3057\u306A\u3044\u3088\u3046\u306B\u8A2D\u5B9A\u3059\u308B\u3053\
    \u3068\n */\ntemplate <class T> struct SternBrocotTree {\n    using Node = SternBrocotTreeNode<T>;\n\
    \    inline static Node root = Node();\n\n    static Node lca(const Node &u, const\
    \ Node &v) {\n        Node res = root;\n        T len = std::min(u.path.size(),\
    \ v.path.size());\n        for (T i = 0; i < len; i++) {\n            T d = std::min(u.path[i],\
    \ v.path[i]);\n            res.go_down(i & 1, d);\n            if (u.path[i] !=\
    \ v.path[i]) break;\n        }\n        return res;\n    }\n\n    /**\n     *\
    \ @brief Stern-Brocot tree \u4E0A\u3067\u4E8C\u5206\u63A2\u7D22\u3092\u3059\u308B\
    \n     *\n     * @param f \u5224\u5B9A\u95A2\u6570`f(num, den)->bool`, \u5358\u8ABF\
    \u3067`f(0, 1)=true, f(1, 0)=false`\n     * @param N \u5206\u6BCD\u3068\u5206\u5B50\
    \u306F\u3068\u3082\u306B`N`\u4EE5\u4E0B\uFF0E`2N`\u304C\u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC\u3057\u306A\u3044\u3053\u3068\u3092\u4FDD\u8A3C\u3059\u308B\
    \u3053\u3068\n     *\n     * @return `std::tuple<T, T, T, T>`\n     *\n     *\
    \ - `lnum/lden = max{x/y : f(x, y) = true, max(x, y) <= N}`\n     *\n     * -\
    \ `rnum/rden = min{x/y : f(x, y) = false, max(x, y) <= N}`\n     *\n     * - `return\
    \ {lnum, lden, rnum, rden}`\n     */\n    template <class F> static std::tuple<T,\
    \ T, T, T> binary_search(T N, F f) {\n        assert(N > 0);\n        assert(f(0,\
    \ 1) and !f(1, 0));\n\n        T num1 = 0, den1 = 1, num2 = 1, den2 = 0;\n   \
    \     bool left = false;\n        while (num1 + num2 <= N and den1 + den2 <= N)\
    \ {\n            for (int i = 0;; ++i) {\n                T num = num1 + (num2\
    \ << i), den = den1 + (den2 << i);\n                if (num > N or den > N or\
    \ f(num, den) == left) {\n                    while (i--) {\n                \
    \        num = num1 + (num2 << i), den = den1 + (den2 << i);\n               \
    \         if (num <= N and den <= N and f(num, den) != left) num1 = num, den1\
    \ = den;\n                    }\n                    break;\n                }\n\
    \            }\n            std::swap(num1, num2), std::swap(den1, den2), left\
    \ = !left;\n        }\n        if (left) std::swap(num1, num2), std::swap(den1,\
    \ den2);\n        return {num1, den1, num2, den2};\n    }\n};\n\n} // namespace\
    \ kk2\n\n#endif // KK2_MATH_STERN_BROCOT_TREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/stern_brocot_tree.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:19:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_math/rational_approximation.test.cpp
  - verify/yosupo_math/stern_brocot_tree.test.cpp
documentation_of: math/stern_brocot_tree.hpp
layout: document
redirect_from:
- /library/math/stern_brocot_tree.hpp
- /library/math/stern_brocot_tree.hpp.html
title: Stern-Brocot tree
---
