---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/base/red_black_tree_base.hpp
    title: "\u8D64\u9ED2\u6728\u306E\u57FA\u672C\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: others/vector_pool.hpp
    title: others/vector_pool.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_ordered_set_max_right.test.cpp
    title: verify/yosupo_ds/ds_ordered_set_max_right.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_ordered_set_min_left.test.cpp
    title: verify/yosupo_ds/ds_ordered_set_min_left.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
    title: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_BBST_RED_BLACK_TREE_HPP\n#define KK2_BBST_RED_BLACK_TREE_HPP\
    \ 1\n\n#include <cassert>\n#include <memory>\n#include <string>\n#include <utility>\n\
    #include <vector>\n\n#include \"../type_traits/io.hpp\"\n#include \"base/red_black_tree_base.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace rbtree {\n\ntemplate <class M> struct RedBlackTreeNode\
    \ {\n    using NodePtr = typename RedBlackTreeBase<RedBlackTreeNode>::NodePtr;\n\
    \    using action_type = void;\n    using S = M;\n    using A = int;\n    static\
    \ S s_op(S a, S b) { return S::op(a, b); }\n    static S s_unit() { return S::unit();\
    \ }\n    static S sa_act(A, S) { return S(); }\n    static A a_op(A, A) { return\
    \ 0; }\n    static A a_unit() { return 0; }\n\n    NodePtr left, right;\n    int\
    \ rank, count;\n    bool is_red, is_rev;\n    S val;\n\n    RedBlackTreeNode(S\
    \ val_ = s_unit())\n        : left(nullptr),\n          right(nullptr),\n    \
    \      rank(0),\n          count(1),\n          is_red(false),\n          is_rev(false),\n\
    \          val(val_) {}\n\n    RedBlackTreeNode(NodePtr l, NodePtr r) : left(l),\
    \ right(r), is_red(true), is_rev(false) {}\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    void debug_output(OStream &os) const {\n        std::vector<std::string>\
    \ a;\n        a.push_back(\"[\");\n        auto dfs = [&](auto self, NodePtr t,\
    \ int dep) -> void {\n            if (!t) return;\n            if ((int)a.size()\
    \ <= dep + 1) a.resize(dep + 2);\n            a[dep + 1] += (t->is_red ? \"(R\"\
    \ : \"(B\");\n            a[dep + 1] += \" val:\" + std::to_string(t->val);\n\
    \            a[dep + 1] += \" is_rev:\" + std::to_string(t->is_rev);\n       \
    \     a[dep + 1] += \" rank:\" + std::to_string(t->rank);\n            a[dep +\
    \ 1] += \" cnt:\" + std::to_string(t->count);\n            a[dep + 1] += \") \"\
    ;\n            self(self, t->left, dep + 1);\n            self(self, t->right,\
    \ dep + 1);\n        };\n        dfs(dfs, NodePtr(this), 0);\n        for (auto\
    \ &s : a) s.push_back('\\n');\n        a.push_back(\"]\");\n        for (auto\
    \ &s : a) os << s;\n    }\n};\n\ntemplate <class M> struct RedBlackTree : RedBlackTreeBase<RedBlackTreeNode<M>>\
    \ {\n    using base = RedBlackTreeBase<RedBlackTreeNode<M>>;\n    using base::RedBlackTreeBase;\n\
    \    using base::s_op;\n    using base::size;\n    using typename base::NodePtr;\n\
    \    using typename base::S;\n\n  protected:\n    NodePtr update(NodePtr t) override\
    \ {\n        t->count = size(t->left) + size(t->right) + (t->left == nullptr);\n\
    \        t->rank = t->left ? t->left->rank + !t->left->is_red : 1;\n        t->val\
    \ = (t->left ? s_op(t->left->val, t->right->val) : t->val);\n        return t;\n\
    \    }\n\n    NodePtr push(NodePtr t) override {\n        if (t->is_rev) {\n \
    \           std::swap(t->left, t->right);\n            if (t->left) t->left->is_rev\
    \ ^= 1;\n            if (t->right) t->right->is_rev ^= 1;\n            t->is_rev\
    \ = false;\n        }\n        return t;\n    }\n};\n\n} // namespace rbtree\n\
    \nusing rbtree::RedBlackTree;\n\n} // namespace kk2\n\n\n#endif // KK2_BBST_RED_BLACK_TREE_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  - bbst/base/red_black_tree_base.hpp
  - others/vector_pool.hpp
  isVerificationFile: false
  path: bbst/red_black_tree.hpp
  requiredBy: []
  timestamp: '2025-06-19 13:39:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_ordered_set_min_left.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  - verify/yosupo_ds/ds_ordered_set_max_right.test.cpp
documentation_of: bbst/red_black_tree.hpp
layout: document
redirect_from:
- /library/bbst/red_black_tree.hpp
- /library/bbst/red_black_tree.hpp.html
title: bbst/red_black_tree.hpp
---
