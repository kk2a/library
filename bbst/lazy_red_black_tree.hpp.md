---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/base/red_black_tree_base.hpp
    title: bbst/base/red_black_tree_base.hpp
  - icon: ':heavy_check_mark:'
    path: others/vector_pool.hpp
    title: others/vector_pool.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
    title: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
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
  code: "#ifndef KK2_BBST_LAZY_RED_BLACK_TREE_HPP\n#define KK2_BBST_LAZY_RED_BLACK_TREE_HPP\
    \ 1\n\n#include <cassert>\n#include <memory>\n#include <string>\n#include <utility>\n\
    #include <vector>\n\n#include \"../type_traits/io.hpp\"\n#include \"base/red_black_tree_base.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace rbtree {\n\ntemplate <class S,\n          S (*op)(S,\
    \ S),\n          S (*e)(),\n          class F,\n          S (*mapping)(F, S),\n\
    \          F (*composition)(F, F),\n          F (*id)()>\nstruct LazyRedBlackTreeNode\
    \ {\n    using NodePtr = typename RedBlackTreeBase<LazyRedBlackTreeNode>::NodePtr;\n\
    \    using Monoid = S;\n\n    static Monoid MonoidOp(Monoid a, Monoid b) { return\
    \ op(a, b); }\n\n    static Monoid MonoidUnit() { return e(); }\n\n    using Action\
    \ = F;\n\n    static Monoid Map(Action f, Monoid x) { return mapping(f, x); }\n\
    \n    static Action ActionOp(Action f, Action g) { return composition(f, g); }\n\
    \n    static Action ActionUnit() { return id(); }\n\n    NodePtr left, right;\n\
    \    int rank, count;\n    bool is_red, is_rev;\n    S val;\n    F lazy;\n\n \
    \   LazyRedBlackTreeNode(S val_ = e(), F lazy_ = id())\n        : left(nullptr),\n\
    \          right(nullptr),\n          rank(0),\n          count(1),\n        \
    \  is_red(false),\n          is_rev(false),\n          val(val_),\n          lazy(lazy_)\
    \ {}\n\n    LazyRedBlackTreeNode(NodePtr l, NodePtr r) : left(l), right(r), is_red(true),\
    \ is_rev(false) {}\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n\
    \    void debug_output(OStream &os) const {\n        std::vector<std::string>\
    \ a;\n        a.push_back(\"[\");\n        auto dfs = [&](auto self, NodePtr t,\
    \ int dep) -> void {\n            if (!t) return;\n            if ((int)a.size()\
    \ <= dep + 1) a.resize(dep + 2);\n            a[dep + 1] += (t->is_red ? \"(R\"\
    \ : \"(B\");\n            a[dep + 1] += \" val:\" + std::to_string(t->val);\n\
    \            a[dep + 1] += \" lazy:\" + std::to_string(t->lazy);\n           \
    \ a[dep + 1] += \" is_rev:\" + std::to_string(t->is_rev);\n            a[dep +\
    \ 1] += \" rank:\" + std::to_string(t->rank);\n            a[dep + 1] += \" cnt:\"\
    \ + std::to_string(t->count);\n            a[dep + 1] += \") \";\n           \
    \ self(self, t->left, dep + 1);\n            self(self, t->right, dep + 1);\n\
    \        };\n        dfs(dfs, NodePtr(this), 0);\n        for (auto &s : a) s.push_back('\\\
    n');\n        a.push_back(\"]\");\n        for (auto &s : a) os << s;\n    }\n\
    };\n\ntemplate <class S,\n          S (*op)(S, S),\n          S (*e)(),\n    \
    \      class F,\n          S (*mapping)(F, S),\n          F (*composition)(F,\
    \ F),\n          F (*id)()>\nstruct LazyRedBlackTree\n    : RedBlackTreeBase<LazyRedBlackTreeNode<S,\
    \ op, e, F, mapping, composition, id>> {\n    using base = RedBlackTreeBase<LazyRedBlackTreeNode<S,\
    \ op, e, F, mapping, composition, id>>;\n    using base::ActionOp;\n    using\
    \ base::Map;\n    using base::merge;\n    using base::RedBlackTreeBase;\n    using\
    \ base::size;\n    using base::split;\n    using base::split3;\n    using typename\
    \ base::NodePtr;\n\n    template <class... Args> void apply(NodePtr &t, int l,\
    \ int r, Args... args) {\n        assert(0 <= l and l <= r and r <= size(t));\n\
    \        auto [t1, t2, t3] = split3(t, l, r);\n        all_apply(t2, F(args...));\n\
    \        t = merge(merge(t1, t2), t3);\n    }\n\n  protected:\n    NodePtr update(NodePtr\
    \ t) override {\n        t->count = size(t->left) + size(t->right) + (t->left\
    \ == nullptr);\n        t->rank = t->left ? t->left->rank + !t->left->is_red :\
    \ 1;\n        t->val = (t->left ? op(t->left->val, t->right->val) : t->val);\n\
    \        return t;\n    }\n\n    void all_apply(NodePtr &t, F f) {\n        if\
    \ (!t) return;\n        t->val = Map(f, t->val);\n        if (t->left) t->lazy\
    \ = ActionOp(f, t->lazy);\n    }\n\n    NodePtr push(NodePtr t) override {\n \
    \       if (t->is_rev) {\n            std::swap(t->left, t->right);\n        \
    \    if (t->left) t->left->is_rev ^= 1;\n            if (t->right) t->right->is_rev\
    \ ^= 1;\n            t->is_rev = false;\n        }\n\n        if (t->lazy != id())\
    \ {\n            all_apply(t->left, t->lazy);\n            all_apply(t->right,\
    \ t->lazy);\n            t->lazy = id();\n        }\n        return t;\n    }\n\
    };\n\ntemplate <class A> using LazyRedBlackTreeS = LazyRedBlackTree<typename A::S,\n\
    \                                                              A::S::op,\n   \
    \                                                           A::S::unit,\n    \
    \                                                          typename A::A,\n  \
    \                                                            A::act,\n       \
    \                                                       A::A::op,\n          \
    \                                                    A::A::unit>;\n\n} // namespace\
    \ rbtree\n\nusing rbtree::LazyRedBlackTree;\nusing rbtree::LazyRedBlackTreeS;\n\
    \n} // namespace kk2\n\n#endif // KK2_BBST_LAZY_RED_BLACK_TREE_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  - bbst/base/red_black_tree_base.hpp
  - others/vector_pool.hpp
  isVerificationFile: false
  path: bbst/lazy_red_black_tree.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
documentation_of: bbst/lazy_red_black_tree.hpp
layout: document
redirect_from:
- /library/bbst/lazy_red_black_tree.hpp
- /library/bbst/lazy_red_black_tree.hpp.html
title: bbst/lazy_red_black_tree.hpp
---
