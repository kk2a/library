---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: bbst/red_black_tree.hpp
    title: bbst/red_black_tree.hpp
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
  bundledCode: "#line 1 \"bbst/base/red_black_tree_node.hpp\"\n\n\n\n#line 1 \"type_traits/io.hpp\"\
    \n\n\n\n#include <istream>\n#include <ostream>\n#include <type_traits>\n\nnamespace\
    \ kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag\
    \ {};\n\n} // namespace type_traits\n\ntemplate <typename T> using is_standard_istream\
    \ =\n    typename std::conditional<std::is_same<T, std::istream>::value\n    \
    \                              || std::is_same<T, std::ifstream>::value,\n   \
    \                           std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_standard_ostream =\n    typename std::conditional<std::is_same<T,\
    \ std::ostream>::value\n                                  || std::is_same<T, std::ofstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
    \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
    \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
    template <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
    \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
    \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate <typename\
    \ T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n#line 5 \"bbst/base/red_black_tree_node.hpp\"\n\nnamespace kk2 {\n\n\
    namespace rbtree {\n\ntemplate <class M> struct RedBlackTreeNode {\n    using\
    \ RedBlackTreeNode_t = RedBlackTreeNode<M>;\n    using NodePtr = RedBlackTreeNode_t\
    \ *;\n    using action_type = void;\n    using S = M;\n    using A = int;\n  \
    \  static S s_op(S a, S b) { return S::op(a, b); }\n    static S s_unit() { return\
    \ S::unit(); }\n    static S sa_act(A, S) { return S(); }\n    static A a_op(A,\
    \ A) { return 0; }\n    static A a_unit() { return 0; }\n\n    NodePtr left, right;\n\
    \    int rank, count;\n    bool is_red, is_rev;\n    S val;\n\n    RedBlackTreeNode(S\
    \ val_ = s_unit())\n        : left(nullptr),\n          right(nullptr),\n    \
    \      rank(0),\n          count(1),\n          is_red(false),\n          is_rev(false),\n\
    \          val(val_) {}\n\n    RedBlackTreeNode(NodePtr l, NodePtr r) : left(l),\
    \ right(r), is_red(true), is_rev(false) {}\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    void debug_output(OStream &os) const {\n        os << \"[\\\
    n\";\n\n        // BFS\u7528\u306E\u30AD\u30E5\u30FC\uFF1A(\u30CE\u30FC\u30C9\
    , \u6DF1\u5EA6)\u306E\u30DA\u30A2\n        std::vector<std::pair<NodePtr, int>>\
    \ queue;\n        queue.emplace_back(NodePtr(const_cast<RedBlackTreeNode *>(this)),\
    \ 0);\n\n        int current_depth = -1;\n\n        for (size_t i = 0; i < queue.size();\
    \ i++) {\n            auto [node, depth] = queue[i];\n\n            // \u65B0\u3057\
    \u3044\u6DF1\u5EA6\u306B\u5165\u3063\u305F\u3089\u30EC\u30D9\u30EB\u60C5\u5831\
    \u3092\u51FA\u529B\n            if (depth != current_depth) {\n              \
    \  if (current_depth >= 0) os << \"\\n\";\n                os << \"  Level \"\
    \ << depth << \": \";\n                current_depth = depth;\n            } else\
    \ {\n                os << \" | \";\n            }\n\n            if (!node) {\n\
    \                // nullptr\u306E\u5834\u5408\n                os << \"(null)\"\
    ;\n            } else {\n                // \u30CE\u30FC\u30C9\u60C5\u5831\u306E\
    \u51FA\u529B\n                os << (node->is_red ? \"(R\" : \"(B\");\n      \
    \          os << \" val:\";\n                if constexpr (requires { os << node->val;\
    \ }) {\n                    os << node->val;\n                } else {\n     \
    \               os << \"[unprintable]\";\n                }\n                os\
    \ << \" is_rev:\" << (node->is_rev ? \"T\" : \"F\");\n                os << \"\
    \ rank:\" << node->rank;\n                os << \" cnt:\" << node->count;\n  \
    \              os << \")\";\n\n                // \u5B50\u30CE\u30FC\u30C9\u3092\
    \u30AD\u30E5\u30FC\u306B\u8FFD\u52A0\uFF08nullptr\u3082\u542B\u3081\u308B\uFF09\
    \n                queue.emplace_back(node->left, depth + 1);\n               \
    \ queue.emplace_back(node->right, depth + 1);\n            }\n        }\n\n  \
    \      os << \"\\n]\\n\";\n    }\n};\n\n} // namespace rbtree\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_BBST_BASE_RED_BLACK_TREE_NODE_HPP\n#define KK2_BBST_BASE_RED_BLACK_TREE_NODE_HPP\
    \ 1\n\n#include \"../../type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace rbtree\
    \ {\n\ntemplate <class M> struct RedBlackTreeNode {\n    using RedBlackTreeNode_t\
    \ = RedBlackTreeNode<M>;\n    using NodePtr = RedBlackTreeNode_t *;\n    using\
    \ action_type = void;\n    using S = M;\n    using A = int;\n    static S s_op(S\
    \ a, S b) { return S::op(a, b); }\n    static S s_unit() { return S::unit(); }\n\
    \    static S sa_act(A, S) { return S(); }\n    static A a_op(A, A) { return 0;\
    \ }\n    static A a_unit() { return 0; }\n\n    NodePtr left, right;\n    int\
    \ rank, count;\n    bool is_red, is_rev;\n    S val;\n\n    RedBlackTreeNode(S\
    \ val_ = s_unit())\n        : left(nullptr),\n          right(nullptr),\n    \
    \      rank(0),\n          count(1),\n          is_red(false),\n          is_rev(false),\n\
    \          val(val_) {}\n\n    RedBlackTreeNode(NodePtr l, NodePtr r) : left(l),\
    \ right(r), is_red(true), is_rev(false) {}\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    void debug_output(OStream &os) const {\n        os << \"[\\\
    n\";\n\n        // BFS\u7528\u306E\u30AD\u30E5\u30FC\uFF1A(\u30CE\u30FC\u30C9\
    , \u6DF1\u5EA6)\u306E\u30DA\u30A2\n        std::vector<std::pair<NodePtr, int>>\
    \ queue;\n        queue.emplace_back(NodePtr(const_cast<RedBlackTreeNode *>(this)),\
    \ 0);\n\n        int current_depth = -1;\n\n        for (size_t i = 0; i < queue.size();\
    \ i++) {\n            auto [node, depth] = queue[i];\n\n            // \u65B0\u3057\
    \u3044\u6DF1\u5EA6\u306B\u5165\u3063\u305F\u3089\u30EC\u30D9\u30EB\u60C5\u5831\
    \u3092\u51FA\u529B\n            if (depth != current_depth) {\n              \
    \  if (current_depth >= 0) os << \"\\n\";\n                os << \"  Level \"\
    \ << depth << \": \";\n                current_depth = depth;\n            } else\
    \ {\n                os << \" | \";\n            }\n\n            if (!node) {\n\
    \                // nullptr\u306E\u5834\u5408\n                os << \"(null)\"\
    ;\n            } else {\n                // \u30CE\u30FC\u30C9\u60C5\u5831\u306E\
    \u51FA\u529B\n                os << (node->is_red ? \"(R\" : \"(B\");\n      \
    \          os << \" val:\";\n                if constexpr (requires { os << node->val;\
    \ }) {\n                    os << node->val;\n                } else {\n     \
    \               os << \"[unprintable]\";\n                }\n                os\
    \ << \" is_rev:\" << (node->is_rev ? \"T\" : \"F\");\n                os << \"\
    \ rank:\" << node->rank;\n                os << \" cnt:\" << node->count;\n  \
    \              os << \")\";\n\n                // \u5B50\u30CE\u30FC\u30C9\u3092\
    \u30AD\u30E5\u30FC\u306B\u8FFD\u52A0\uFF08nullptr\u3082\u542B\u3081\u308B\uFF09\
    \n                queue.emplace_back(node->left, depth + 1);\n               \
    \ queue.emplace_back(node->right, depth + 1);\n            }\n        }\n\n  \
    \      os << \"\\n]\\n\";\n    }\n};\n\n} // namespace rbtree\n\n} // namespace\
    \ kk2\n\n#endif // KK2_BBST_BASE_RED_BLACK_TREE_NODE_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  isVerificationFile: false
  path: bbst/base/red_black_tree_node.hpp
  requiredBy:
  - bbst/red_black_tree.hpp
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  - verify/yosupo_ds/ds_ordered_set_max_right.test.cpp
  - verify/yosupo_ds/ds_ordered_set_min_left.test.cpp
documentation_of: bbst/base/red_black_tree_node.hpp
layout: document
redirect_from:
- /library/bbst/base/red_black_tree_node.hpp
- /library/bbst/base/red_black_tree_node.hpp.html
title: bbst/base/red_black_tree_node.hpp
---
