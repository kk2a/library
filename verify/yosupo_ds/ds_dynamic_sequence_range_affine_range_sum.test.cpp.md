---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/base/lazy_red_black_tree_node.hpp
    title: bbst/base/lazy_red_black_tree_node.hpp
  - icon: ':heavy_check_mark:'
    path: bbst/base/red_black_tree_base.hpp
    title: "\u8D64\u9ED2\u6728\u306E\u57FA\u672C\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: bbst/lazy_red_black_tree.hpp
    title: bbst/lazy_red_black_tree.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/affine_sumwithsize.hpp
    title: math/action/affine_sumwithsize.hpp
  - icon: ':heavy_check_mark:'
    path: math/group/sum_with_size.hpp
    title: math/group/sum_with_size.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/affine.hpp
    title: math/monoid/affine.hpp
  - icon: ':question:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':heavy_check_mark:'
    path: others/vector_pool.hpp
    title: others/vector_pool.hpp
  - icon: ':question:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':question:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#line 1 \"bbst/lazy_red_black_tree.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <memory>\n#include <string>\n#include <utility>\n#include <vector>\n\n#line\
    \ 1 \"bbst/base/lazy_red_black_tree_node.hpp\"\n\n\n\n#line 1 \"type_traits/io.hpp\"\
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
    \ kk2\n\n\n#line 5 \"bbst/base/lazy_red_black_tree_node.hpp\"\n\nnamespace kk2\
    \ {\n\nnamespace rbtree {\n\ntemplate <class A_> struct LazyRedBlackTreeNode {\n\
    \    using LazyRedBlackTreeNode_t = LazyRedBlackTreeNode<A_>;\n    using NodePtr\
    \ = LazyRedBlackTreeNode_t *;\n    using action_type = A_;\n    using S = typename\
    \ A_::S;\n    using A = typename A_::A;\n    static S s_op(S a, S b) { return\
    \ S::op(a, b); }\n    static S s_unit() { return S::unit(); }\n    static S sa_act(A\
    \ f, S x) { return action_type::act(f, x); }\n    static A a_op(A f, A g) { return\
    \ A::op(f, g); }\n    static A a_unit() { return A::unit(); }\n\n    NodePtr left,\
    \ right;\n    int rank, count;\n    bool is_red, is_rev;\n    S val;\n    A lazy;\n\
    \n    LazyRedBlackTreeNode(S val_ = s_unit(), A lazy_ = a_unit())\n        : left(nullptr),\n\
    \          right(nullptr),\n          rank(0),\n          count(1),\n        \
    \  is_red(false),\n          is_rev(false),\n          val(val_),\n          lazy(lazy_)\
    \ {}\n\n    LazyRedBlackTreeNode(NodePtr l, NodePtr r) : left(l), right(r), is_red(true),\
    \ is_rev(false) {}\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n\
    \    void debug_output(OStream &os) const {\n        os << \"[\\n\";\n\n     \
    \   // BFS\u7528\u306E\u30AD\u30E5\u30FC\uFF1A(\u30CE\u30FC\u30C9, \u6DF1\u5EA6\
    )\u306E\u30DA\u30A2\n        std::vector<std::pair<NodePtr, int>> queue;\n   \
    \     queue.emplace_back(NodePtr(const_cast<LazyRedBlackTreeNode *>(this)), 0);\n\
    \n        int current_depth = -1;\n\n        for (size_t i = 0; i < queue.size();\
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
    \ << \" lazy:\";\n                if constexpr (requires { os << node->lazy; })\
    \ {\n                    os << node->lazy;\n                } else {\n       \
    \             os << \"[unprintable]\";\n                }\n                os\
    \ << \" is_rev:\" << (node->is_rev ? \"T\" : \"F\");\n                os << \"\
    \ rank:\" << node->rank;\n                os << \" cnt:\" << node->count;\n  \
    \              os << \")\";\n\n                // \u5B50\u30CE\u30FC\u30C9\u3092\
    \u30AD\u30E5\u30FC\u306B\u8FFD\u52A0\uFF08nullptr\u3082\u542B\u3081\u308B\uFF09\
    \n                queue.emplace_back(node->left, depth + 1);\n               \
    \ queue.emplace_back(node->right, depth + 1);\n            }\n        }\n\n  \
    \      os << \"\\n]\\n\";\n    }\n};\n\n} // namespace rbtree\n\n} // namespace\
    \ kk2\n\n\n#line 1 \"bbst/base/red_black_tree_base.hpp\"\n\n\n\n#line 9 \"bbst/base/red_black_tree_base.hpp\"\
    \n\n#line 1 \"others/vector_pool.hpp\"\n\n\n\n#line 6 \"others/vector_pool.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename T> struct VectorPool {\n  private:\n\
    \    static constexpr size_t CHUNK_SIZE = 1 << 11;\n    std::vector<std::unique_ptr<T[]>>\
    \ chunks; // \u56FA\u5B9A\u30B5\u30A4\u30BA\u914D\u5217\u306E\u30DD\u30A4\u30F3\
    \u30BF\n    std::vector<T *> free_ptrs;\n    size_t pos = 0;\n\n  public:\n  \
    \  VectorPool() = default;\n    VectorPool(int n) { reserve(n); }\n\n    inline\
    \ T *alloc() {\n        if (pos >= free_ptrs.size()) { expand(); }\n        return\
    \ free_ptrs[pos++];\n    }\n\n    inline void free(T *ptr) { free_ptrs[--pos]\
    \ = ptr; }\n\n    void clear() {\n        pos = 0;\n        size_t idx = 0;\n\
    \        for (auto &chunk : chunks) {\n            for (size_t i = 0; i < CHUNK_SIZE;\
    \ i++) { free_ptrs[idx++] = &chunk[i]; }\n        }\n    }\n\n    void reserve(int\
    \ n) {\n        size_t needed_chunks = (n + CHUNK_SIZE - 1) / CHUNK_SIZE;\n  \
    \      size_t current_chunks = chunks.size();\n\n        if (needed_chunks <=\
    \ current_chunks) return;\n\n        chunks.reserve(needed_chunks);\n        free_ptrs.reserve(n);\n\
    \n        // \u4E00\u5EA6\u306B\u5FC5\u8981\u306A\u5206\u306E\u30C1\u30E3\u30F3\
    \u30AF\u3092\u78BA\u4FDD\n        size_t old_free_size = free_ptrs.size();\n \
    \       size_t new_chunks_count = needed_chunks - current_chunks;\n        free_ptrs.resize(old_free_size\
    \ + new_chunks_count * CHUNK_SIZE);\n\n        for (size_t chunk_idx = 0; chunk_idx\
    \ < new_chunks_count; ++chunk_idx) {\n            auto new_chunk = std::make_unique<T[]>(CHUNK_SIZE);\n\
    \            T *chunk_ptr = new_chunk.get();\n            chunks.push_back(std::move(new_chunk));\n\
    \n            size_t base_idx = old_free_size + chunk_idx * CHUNK_SIZE;\n    \
    \        for (size_t i = 0; i < CHUNK_SIZE; ++i) { free_ptrs[base_idx + i] = &chunk_ptr[i];\
    \ }\n        }\n    }\n\n  private:\n    void expand() { add_chunk(); }\n\n  \
    \  void add_chunk() {\n        auto new_chunk = std::make_unique<T[]>(CHUNK_SIZE);\n\
    \        T *chunk_ptr = new_chunk.get();\n        chunks.push_back(std::move(new_chunk));\n\
    \n        size_t old_size = free_ptrs.size();\n        free_ptrs.resize(old_size\
    \ + CHUNK_SIZE);\n\n        for (size_t i = 0; i < CHUNK_SIZE; i++) { free_ptrs[old_size\
    \ + i] = &chunk_ptr[i]; }\n    }\n\n  public:\n    size_t size() const { return\
    \ chunks.size() * CHUNK_SIZE; }\n\n    size_t available() const { return free_ptrs.size()\
    \ - pos; }\n};\n\n} // namespace kk2\n\n\n#line 11 \"bbst/base/red_black_tree_base.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace rbtree {\n\n// base\u306B\u5FC5\u8981\u306A\u30E1\
    \u30F3\u30D0\n// NodePtr left, right;\n// int rank, count;\n// bool is_red;\n\
    // S val;\n\n/**\n * @brief \u8D64\u9ED2\u6728\u306E\u57FA\u672C\u30AF\u30E9\u30B9\
    \n *\n */\ntemplate <typename Derived, typename Node> struct RedBlackTreeBase\
    \ {\n    using NodePtr = Node::NodePtr;\n    using action_type = typename Node::action_type;\n\
    \    using S = typename Node::S;\n    using A = typename Node::A;\n    static\
    \ S s_op(S a, S b) { return Node::s_op(a, b); }\n    static S s_unit() { return\
    \ Node::s_unit(); }\n    static S sa_act(A f, S x) { return Node::sa_act(f, x);\
    \ }\n    static A a_op(A f, A g) { return Node::a_op(f, g); }\n    static A a_unit()\
    \ { return Node::a_unit(); }\n\n    VectorPool<Node> pool;\n\n    RedBlackTreeBase()\
    \ : pool() {}\n    RedBlackTreeBase(int sz) : pool(sz) {}\n\n    template <typename...\
    \ Args> NodePtr alloc(Args... args) {\n        NodePtr t = &(*pool.alloc() = Node(args...));\n\
    \        return static_cast<Derived *>(this)->update(t);\n    }\n\n    NodePtr\
    \ make_tree() { return nullptr; }\n\n    void free(NodePtr t) { pool.free(t);\
    \ }\n\n    void clear(NodePtr t) {\n        if (!t) return;\n        clear(t->left);\n\
    \        clear(t->right);\n        free(t);\n    }\n\n    NodePtr build(const\
    \ std::vector<S> &v) {\n        auto dfs = [&](auto self, int l, int r) -> NodePtr\
    \ {\n            if (l == r) return nullptr;\n            if (l + 1 == r) return\
    \ alloc(v[l]);\n            int m = (l + r) / 2;\n            return merge(self(self,\
    \ l, m), self(self, m, r));\n        };\n        return dfs(dfs, 0, (int)v.size());\n\
    \    }\n\n    NodePtr merge(NodePtr l, NodePtr r) {\n        if (!l or !r) return\
    \ l ? l : r;\n        NodePtr c = submerge(l, r);\n        c->is_red = false;\n\
    \        return c;\n    }\n\n    std::pair<NodePtr, NodePtr> split(NodePtr t,\
    \ int k) {\n        assert(0 <= k and k <= size(t));\n        if (!t) return {nullptr,\
    \ nullptr};\n        if (k == 0) return {nullptr, as_root(t)};\n        if (k\
    \ == size(t)) return {as_root(t), nullptr};\n        t = static_cast<Derived *>(this)->push(t);\n\
    \        NodePtr l = as_root(t->left), r = as_root(t->right);\n        free(t);\n\
    \        if (k < size(l)) {\n            auto [ll, rr] = split(l, k);\n      \
    \      return {ll, merge(rr, r)};\n        }\n        if (k > size(l)) {\n   \
    \         auto [ll, rr] = split(r, k - size(l));\n            return {merge(l,\
    \ ll), rr};\n        }\n        return {l, r};\n    }\n\n    struct NodePtr3 {\n\
    \        NodePtr x, y, z;\n    };\n\n    NodePtr3 split3(NodePtr t, int a, int\
    \ b) {\n        assert(0 <= a and a <= b and b <= size(t));\n        auto [x,\
    \ y] = split(t, a);\n        auto [y1, z] = split(y, b - a);\n        return {x,\
    \ y1, z};\n    }\n\n    template <typename... Args> void insert(NodePtr &t, int\
    \ k, Args... args) {\n        assert(0 <= k and k <= size(t));\n        auto [l,\
    \ r] = split(t, k);\n        t = merge(merge(l, alloc(S(args...))), r);\n    }\n\
    \n    void erase(NodePtr &t, int k) {\n        assert(0 <= k and k < size(t));\n\
    \        auto [l, r] = split(t, k);\n        auto [ll, rr] = split(r, 1);\n  \
    \      free(ll);\n        t = merge(l, rr);\n    }\n\n    template <typename...\
    \ Args> void set(NodePtr t, int k, Args... args) {\n        assert(0 <= k and\
    \ k < size(t));\n        NodePtr now = t;\n        auto dfs = [&](auto self, NodePtr\
    \ now, int k) -> void {\n            if (!now->left) {\n                now->val\
    \ = S(args...);\n                return;\n            }\n            now = static_cast<Derived\
    \ *>(this)->push(now);\n            if (size(now->left) > k) self(self, now->left,\
    \ k);\n            else self(self, now->right, k - size(now->left));\n       \
    \     now = static_cast<Derived *>(this)->update(now);\n        };\n        dfs(dfs,\
    \ now, k);\n    }\n\n    S get(NodePtr t, int k) {\n        assert(0 <= k and\
    \ k < size(t));\n        NodePtr now = t;\n        while (now->left) {\n     \
    \       now = static_cast<Derived *>(this)->push(now);\n            if (size(now->left)\
    \ > k) now = now->left;\n            else {\n                k -= size(now->left);\n\
    \                now = now->right;\n            }\n        }\n        return now->val;\n\
    \    }\n\n    S prod(NodePtr &t, int l, int r) {\n        assert(0 <= l and l\
    \ <= r and r <= size(t));\n        auto [t1, t2, t3] = split3(t, l, r);\n    \
    \    S res = (t2 ? t2->val : s_unit());\n        t = merge(merge(t1, t2), t3);\n\
    \        return res;\n    }\n\n    void reverse(NodePtr &t, int l, int r) {\n\
    \        assert(0 <= l and l <= r and r <= size(t));\n        auto [t1, t2, t3]\
    \ = split3(t, l, r);\n        if (t2) t2->is_rev ^= 1;\n        t = merge(merge(t1,\
    \ t2), t3);\n    }\n\n    template <typename... Args> void push_front(NodePtr\
    \ &t, Args... args) {\n        t = merge(alloc(S(args...)), t);\n    }\n\n   \
    \ template <typename... Args> void push_back(NodePtr &t, Args... args) {\n   \
    \     t = merge(t, alloc(S(args...)));\n    }\n\n    void pop_front(NodePtr &t)\
    \ {\n        auto [l, r] = split(t, 1);\n        t = r;\n    }\n\n    void pop_back(NodePtr\
    \ &t) {\n        auto [l, r] = split(t, size(t) - 1);\n        t = l;\n    }\n\
    \n    struct bb_result {\n        int s;\n        S prod;\n        NodePtr t;\n\
    \    };\n\n    /**\n     * @brief \u4E8C\u5206\u63A2\u7D22\uFF08\u53F3\u65B9\u5411\
    \uFF09\n     *\n     * \u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u5927\u306E\
    k\u3092\u6C42\u3081\u308B\u4E8C\u5206\u63A2\u7D22\u3092\u884C\u3044\u307E\u3059\
    \u3002\n     *\n     * \u4EE5\u4E0B\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\
    k\u3092\u8FD4\u3057\u307E\u3059\uFF1A\n     *\n     * - k = l \u307E\u305F\u306F\
    \ (k \u2260 l \u304B\u3064 g(prod(l, k)) = true)\n     *\n     * - k = size(t)\
    \ \u307E\u305F\u306F (k \u2260 size(t) \u304B\u3064 g(prod(l, k+1)) = false)\n\
    \     *\n     * @tparam G \u8FF0\u8A9E\u95A2\u6570\u306E\u578B\u3002bool operator()(S)\u3092\
    \u6301\u3064\u5FC5\u8981\u304C\u3042\u308A\u307E\u3059\n     * @param t \u63A2\
    \u7D22\u5BFE\u8C61\u306E\u6728\uFF08\u53C2\u7167\u6E21\u3057\u3001\u64CD\u4F5C\
    \u5F8C\u306B\u5FA9\u5143\u3055\u308C\u307E\u3059\uFF09\n     * @param l \u63A2\
    \u7D22\u958B\u59CB\u4F4D\u7F6E\uFF080-indexed\uFF09\n     * @param g \u5224\u5B9A\
    \u95A2\u6570\u3002S\u3092\u53D7\u3051\u53D6\u308Abool\u3092\u8FD4\u3059\u95A2\u6570\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n     * @return bb_result \u69CB\u9020\u4F53\
    \n     *\n     *         - s: \u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u5927\
    \u306Ek\n     *\n     *         - prod: prod(l, k)\u306E\u5024\n     *\n     *\
    \         - t: k\u756A\u76EE\u306E\u30CE\u30FC\u30C9\u3078\u306E\u30DD\u30A4\u30F3\
    \u30BF\uFF08\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306Fnullptr\uFF09\n  \
    \   *\n     * @pre 0 <= l <= size(t)\n     * @pre g(s_unit()) == true\n     */\n\
    \    template <class G> bb_result max_right(NodePtr &t, int l, const G &g) {\n\
    \        assert(0 <= l and l <= size(t));\n        assert(g(s_unit()));\n    \
    \    auto [t1, t2] = split(t, l);\n        if (!t2) {\n            t = merge(t1,\
    \ t2);\n            return {l, s_unit(), nullptr};\n        }\n        if (g(t2->val))\
    \ {\n            t = merge(t1, t2);\n            return {size(t), t2->val, nullptr};\n\
    \        }\n\n        int k = l;\n        S x = s_unit();\n        NodePtr now\
    \ = t2;\n\n        while (now->left) {\n            now = static_cast<Derived\
    \ *>(this)->push(now);\n            S y = s_op(x, now->left->val);\n         \
    \   if (g(y)) {\n                x = y;\n                k += size(now->left);\n\
    \                now = now->right;\n            } else {\n                now\
    \ = now->left;\n            }\n        }\n        t = merge(t1, t2);\n       \
    \ return {k, x, now};\n    }\n\n    /**\n     * @brief \u4E8C\u5206\u63A2\u7D22\
    \uFF08\u5DE6\u65B9\u5411\uFF09\n     *\n     * \u6761\u4EF6\u3092\u6E80\u305F\u3059\
    \u6700\u5C0F\u306Ek\u3092\u6C42\u3081\u308B\u4E8C\u5206\u63A2\u7D22\u3092\u884C\
    \u3044\u307E\u3059\u3002\n     *\n     * \u4EE5\u4E0B\u306E\u6761\u4EF6\u3092\u6E80\
    \u305F\u3059k\u3092\u8FD4\u3057\u307E\u3059\uFF1A\n     *\n     * - k = r \u307E\
    \u305F\u306F (k \u2260 r \u304B\u3064 g(prod(k, r)) = true)\n     *\n     * -\
    \ k = 0 \u307E\u305F\u306F (k \u2260 0 \u304B\u3064 g(prod(k-1, r)) = false)\n\
    \     *\n     * @tparam G \u8FF0\u8A9E\u95A2\u6570\u306E\u578B\u3002bool operator()(S)\u3092\
    \u6301\u3064\u5FC5\u8981\u304C\u3042\u308A\u307E\u3059\n     * @param t \u63A2\
    \u7D22\u5BFE\u8C61\u306E\u6728\uFF08\u53C2\u7167\u6E21\u3057\u3001\u64CD\u4F5C\
    \u5F8C\u306B\u5FA9\u5143\u3055\u308C\u307E\u3059\uFF09\n     * @param r \u63A2\
    \u7D22\u7D42\u4E86\u4F4D\u7F6E\uFF080-indexed\uFF09\n     * @param g \u5224\u5B9A\
    \u95A2\u6570\u3002S\u3092\u53D7\u3051\u53D6\u308Abool\u3092\u8FD4\u3059\u95A2\u6570\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n     * @return bb_result \u69CB\u9020\u4F53\
    \n     *\n     *         - s: \u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u5C0F\
    \u306Ek\n     *\n     *         - prod: prod(k, r)\u306E\u5024\n     *\n     *\
    \         - t: k-1\u756A\u76EE\u306E\u30CE\u30FC\u30C9\u3078\u306E\u30DD\u30A4\
    \u30F3\u30BF\uFF08\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306Fnullptr\uFF09\
    \n     *\n     * @pre 0 <= r <= size(t)\n     * @pre g(s_unit()) == true\n   \
    \  */\n    template <class G> bb_result min_left(NodePtr &t, int r, const G &g)\
    \ {\n        assert(0 <= r and r <= size(t));\n        assert(g(s_unit()));\n\
    \        auto [t1, t2] = split(t, r);\n        if (!t1) {\n            t = merge(t1,\
    \ t2);\n            return {r, s_unit(), nullptr};\n        }\n        if (g(t1->val))\
    \ {\n            t = merge(t1, t2);\n            return {0, t1->val, nullptr};\n\
    \        }\n\n        int k = r;\n        S x = s_unit();\n        NodePtr now\
    \ = t1;\n\n        while (now->right) {\n            now = static_cast<Derived\
    \ *>(this)->push(now);\n            S y = s_op(now->right->val, x);\n        \
    \    if (g(y)) {\n                x = y;\n                k -= size(now->right);\n\
    \                now = now->left;\n            } else {\n                now =\
    \ now->right;\n            }\n        }\n        t = merge(t1, t2);\n        return\
    \ {k, x, now};\n    }\n\n    inline int size(NodePtr t) const { return t ? t->count\
    \ : 0; }\n\n  protected:\n    NodePtr rotate(NodePtr t, bool left) {\n       \
    \ t = static_cast<Derived *>(this)->push(t);\n        NodePtr s;\n        if (left)\
    \ {\n            s = static_cast<Derived *>(this)->push(t->left);\n          \
    \  t->left = s->right;\n            s->right = t;\n        } else {\n        \
    \    s = static_cast<Derived *>(this)->push(t->right);\n            t->right =\
    \ s->left;\n            s->left = t;\n        }\n        static_cast<Derived *>(this)->update(t);\n\
    \        return static_cast<Derived *>(this)->update(s);\n    }\n\n    NodePtr\
    \ submerge(NodePtr l, NodePtr r) {\n        if (l->rank < r->rank) {\n       \
    \     r = static_cast<Derived *>(this)->push(r);\n            NodePtr c = submerge(l,\
    \ r->left);\n            r->left = c;\n            if (c->is_red and c->left->is_red)\
    \ {\n                c->is_red = 0, r->is_red = 1;\n                if (!r->right->is_red)\
    \ return rotate(r, true);\n                r->right->is_red = 0;\n           \
    \ }\n            return static_cast<Derived *>(this)->update(r);\n        } else\
    \ if (l->rank > r->rank) {\n            l = static_cast<Derived *>(this)->push(l);\n\
    \            NodePtr c = submerge(l->right, r);\n            l->right = c;\n \
    \           if (c->is_red and c->right->is_red) {\n                c->is_red =\
    \ 0, l->is_red = 1;\n                if (!l->left->is_red) return rotate(l, false);\n\
    \                l->left->is_red = 0;\n            }\n            return static_cast<Derived\
    \ *>(this)->update(l);\n        } else {\n            return alloc(l, r);\n  \
    \      }\n    }\n\n    NodePtr as_root(NodePtr t) {\n        if (!t) return t;\n\
    \        t->is_red = false;\n        return t;\n    }\n};\n\n} // namespace rbtree\n\
    \n} // namespace kk2\n\n\n#line 12 \"bbst/lazy_red_black_tree.hpp\"\n\nnamespace\
    \ kk2 {\n\nnamespace rbtree {\n\ntemplate <class A_> struct LazyRedBlackTree\n\
    \    : RedBlackTreeBase<LazyRedBlackTree<A_>, LazyRedBlackTreeNode<A_>> {\n  \
    \  using base = RedBlackTreeBase<LazyRedBlackTree<A_>, LazyRedBlackTreeNode<A_>>;\n\
    \    using base::a_op;\n    using base::a_unit;\n    using base::merge;\n    using\
    \ base::RedBlackTreeBase;\n    using base::s_op;\n    using base::sa_act;\n  \
    \  using base::size;\n    using base::split;\n    using base::split3;\n    using\
    \ typename base::A;\n    using typename base::NodePtr;\n    using typename base::S;\n\
    \n    template <class... Args> void apply(NodePtr &t, int l, int r, Args... args)\
    \ {\n        assert(0 <= l and l <= r and r <= size(t));\n        auto [t1, t2,\
    \ t3] = split3(t, l, r);\n        all_apply(t2, A(args...));\n        t = merge(merge(t1,\
    \ t2), t3);\n    }\n\n    NodePtr update(NodePtr t) {\n        t->count = size(t->left)\
    \ + size(t->right) + (t->left == nullptr);\n        t->rank = t->left ? t->left->rank\
    \ + !t->left->is_red : 1;\n        t->val = (t->left ? s_op(t->left->val, t->right->val)\
    \ : t->val);\n        return t;\n    }\n\n    void all_apply(NodePtr &t, A f)\
    \ {\n        if (!t) return;\n        t->val = sa_act(f, t->val);\n        if\
    \ (t->left) t->lazy = a_op(f, t->lazy);\n    }\n\n    NodePtr push(NodePtr t)\
    \ {\n        if (t->is_rev) {\n            std::swap(t->left, t->right);\n   \
    \         if (t->left) t->left->is_rev ^= 1;\n            if (t->right) t->right->is_rev\
    \ ^= 1;\n            t->is_rev = false;\n        }\n\n        if (t->lazy != a_unit())\
    \ {\n            all_apply(t->left, t->lazy);\n            all_apply(t->right,\
    \ t->lazy);\n            t->lazy = a_unit();\n        }\n        return t;\n \
    \   }\n};\n\n} // namespace rbtree\n\nusing rbtree::LazyRedBlackTree;\n\n} //\
    \ namespace kk2\n\n\n#line 1 \"modint/mont.hpp\"\n\n\n\n#line 5 \"modint/mont.hpp\"\
    \n#include <cstdint>\n#include <iostream>\n#line 8 \"modint/mont.hpp\"\n\n#line\
    \ 1 \"type_traits/integral.hpp\"\n\n\n\n#line 5 \"type_traits/integral.hpp\"\n\
    \nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T> using is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value\n      \
    \                            or std::is_same<T, __int128>::value,\n          \
    \                    std::true_type,\n                              std::false_type>::type;\n\
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
    \n} // namespace kk2\n\n\n#line 11 \"modint/mont.hpp\"\n\nnamespace kk2 {\n\n\
    template <int p> struct LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n\
    \    using i32 = int32_t;\n    using i64 = int64_t;\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32\
    \ ret = p;\n        for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;\n        return\
    \ ret;\n    }\n\n    static constexpr u32 r = get_r();\n    static constexpr u32\
    \ n2 = -u64(p) % p;\n    static_assert(r * p == 1, \"invalid, r * p != 1\");\n\
    \    static_assert(p < (1 << 30), \"invalid, p >= 2 ^ 30\");\n    static_assert((p\
    \ & 1) == 1, \"invalid, p % 2 == 0\");\n\n    u32 _v;\n\n    constexpr LazyMontgomeryModInt()\
    \ : _v(0) {}\n\n    template <typename T, is_integral_t<T> * = nullptr> constexpr\
    \ LazyMontgomeryModInt(T b)\n        : _v(reduce(u64(b % p + p) * n2)) {}\n\n\
    \    static constexpr u32 reduce(const u64 &b) { return (b + u64(u32(b) * u32(-r))\
    \ * p) >> 32; }\n    constexpr mint &operator++() { return *this += 1; }\n   \
    \ constexpr mint &operator--() { return *this -= 1; }\n\n    constexpr mint operator++(int)\
    \ {\n        mint ret = *this;\n        *this += 1;\n        return ret;\n   \
    \ }\n\n    constexpr mint operator--(int) {\n        mint ret = *this;\n     \
    \   *this -= 1;\n        return ret;\n    }\n\n    constexpr mint &operator+=(const\
    \ mint &b) {\n        if (i32(_v += b._v - 2 * p) < 0) _v += 2 * p;\n        return\
    \ *this;\n    }\n\n    constexpr mint &operator-=(const mint &b) {\n        if\
    \ (i32(_v -= b._v) < 0) _v += 2 * p;\n        return *this;\n    }\n\n    constexpr\
    \ mint &operator*=(const mint &b) {\n        _v = reduce(u64(_v) * b._v);\n  \
    \      return *this;\n    }\n\n    constexpr mint &operator/=(const mint &b) {\n\
    \        *this *= b.inv();\n        return *this;\n    }\n\n\n    constexpr bool\
    \ operator==(const mint &b) const {\n        return (_v >= p ? _v - p : _v) ==\
    \ (b._v >= p ? b._v - p : b._v);\n    }\n\n    constexpr bool operator!=(const\
    \ mint &b) const {\n        return (_v >= p ? _v - p : _v) != (b._v >= p ? b._v\
    \ - p : b._v);\n    }\n\n    constexpr mint operator-() const { return mint()\
    \ - mint(*this); }\n    constexpr mint operator+() const { return mint(*this);\
    \ }\n    friend constexpr mint operator+(const mint &a, const mint &b) { return\
    \ mint(a) += b; }\n    friend constexpr mint operator-(const mint &a, const mint\
    \ &b) { return mint(a) -= b; }\n    friend constexpr mint operator*(const mint\
    \ &a, const mint &b) { return mint(a) *= b; }\n    friend constexpr mint operator/(const\
    \ mint &a, const mint &b) { return mint(a) /= b; }\n\n    template <class T> constexpr\
    \ mint pow(T n) const {\n        mint ret(1), mul(*this);\n        while (n >\
    \ 0) {\n            if (n & 1) ret *= mul;\n            if (n >>= 1) mul *= mul;\n\
    \        }\n        return ret;\n    }\n\n    constexpr mint inv() const {\n \
    \       assert(*this != mint(0));\n        return pow(p - 2);\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const mint &x) {\n        return os << x.val();\n    }\n\n    template\
    \ <class IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, mint &x) {\n        i64 t;\n        is >> t;\n        x = mint(t);\n  \
    \      return (is);\n    }\n\n    constexpr u32 val() const {\n        u32 ret\
    \ = reduce(_v);\n        return ret >= p ? ret - p : ret;\n    }\n\n    static\
    \ constexpr u32 getmod() { return p; }\n};\n\ntemplate <int p> using Mont = LazyMontgomeryModInt<p>;\n\
    \nusing mont998 = Mont<998244353>;\nusing mont107 = Mont<1000000007>;\n\n} //\
    \ namespace kk2\n\n\n#line 1 \"math/action/affine_sumwithsize.hpp\"\n\n\n\n#line\
    \ 1 \"math/group/sum_with_size.hpp\"\n\n\n\n#line 5 \"math/group/sum_with_size.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace group {\n\ntemplate <class S, class T = S> struct\
    \ SumWithSize {\n    static constexpr bool commutative = true;\n    using M =\
    \ SumWithSize;\n    S a;\n    T size;\n\n    SumWithSize() : a(S()), size(0) {}\n\
    \    SumWithSize(S a_, S size_ = T(1)) : a(a_), size(size_) {}\n    operator S()\
    \ const { return a; }\n    inline static M op(M l, M r) { return M(l.a + r.a,\
    \ l.size + r.size); }\n    inline static M inv(M x) { return M(-x.a, -x.size);\
    \ }\n    inline static M unit() { return M(); }\n    bool operator==(const M &rhs)\
    \ const { return a == rhs.a and size == rhs.size; }\n    bool operator!=(const\
    \ M &rhs) const { return a != rhs.a or size != rhs.size; }\n\n    template <class\
    \ OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const M &x) {\n        return os << x.a << \" \" << x.size;\n    }\n\n\
    \    template <class IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream\
    \ &operator>>(IStream &is, M &x) {\n        is >> x.a;\n        x.size = T(1);\n\
    \        return is;\n    }\n};\n\n} // namespace group\n\n} // namespace kk2\n\
    \n\n#line 1 \"math/monoid/affine.hpp\"\n\n\n\n#line 5 \"math/monoid/affine.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace monoid {\n\ntemplate <class S> struct Affine\
    \ {\n    static constexpr bool commutative = false;\n    using M = Affine;\n \
    \   S a, b; // x \\mapsto ax + b\n\n    Affine() : a(S(1)), b(S(0)) {};\n    Affine(S\
    \ a, S b) : a(a), b(b) {}\n    inline S eval(S x) const { return a * x + b; }\n\
    \    // l \\circ r\n    inline static M op(M l, M r) { return M(l.a * r.a, l.a\
    \ * r.b + l.b); }\n    inline static M unit() { return M(); }\n    inline static\
    \ M inv(M f) { return M(S(1) / f.a, -f.b / f.a); }\n    bool operator==(const\
    \ M &rhs) const { return a == rhs.a and b == rhs.b; }\n    bool operator!=(const\
    \ M &rhs) const { return a != rhs.a or b != rhs.b; }\n\n    template <class OStream,\
    \ is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream &os,\
    \ const M &x) {\n        return os << x.a << \" \" << x.b;\n    }\n\n    template\
    \ <class IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, M &x) {\n        return is >> x.a >> x.b;\n    }\n};\n\n} // namespace\
    \ monoid\n\n} // namespace kk2\n\n\n#line 6 \"math/action/affine_sumwithsize.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace action {\n\ntemplate <class T, class U> struct\
    \ AffineSumWithSize {\n    using A = monoid::Affine<T>;\n    using S = group::SumWithSize<T,\
    \ U>;\n\n    inline static S act(A f, S x) { return S(f.a * x.a + f.b * x.size,\
    \ x.size); }\n};\n\n} // namespace action\n\n} // namespace kk2\n\n\n#line 1 \"\
    template/template.hpp\"\n\n\n\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#line 8 \"template/template.hpp\"\n#include <chrono>\n#include <cmath>\n\
    #include <deque>\n#include <functional>\n#include <iterator>\n#include <limits>\n\
    #include <map>\n#include <numeric>\n#include <optional>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <stack>\n#line 22 \"template/template.hpp\"\
    \n#include <unordered_map>\n#include <unordered_set>\n#line 26 \"template/template.hpp\"\
    \n\n#line 1 \"template/constant.hpp\"\n\n\n\n#line 1 \"template/type_alias.hpp\"\
    \n\n\n\n#line 8 \"template/type_alias.hpp\"\n\nusing u32 = unsigned int;\nusing\
    \ i64 = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\nusing pi = std::pair<int, int>;\nusing pl = std::pair<i64,\
    \ i64>;\nusing pil = std::pair<int, i64>;\nusing pli = std::pair<i64, int>;\n\n\
    template <class T> using vc = std::vector<T>;\ntemplate <class T> using vvc =\
    \ std::vector<vc<T>>;\ntemplate <class T> using vvvc = std::vector<vvc<T>>;\n\
    template <class T> using vvvvc = std::vector<vvvc<T>>;\n\ntemplate <class T> using\
    \ pq = std::priority_queue<T>;\ntemplate <class T> using pqi = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\n\n#line 5 \"template/constant.hpp\"\n\n\
    template <class T> constexpr T infty = 0;\ntemplate <> constexpr int infty<int>\
    \ = (1 << 30) - 123;\ntemplate <> constexpr i64 infty<i64> = (1ll << 62) - (1ll\
    \ << 31);\ntemplate <> constexpr i128 infty<i128> = (i128(1) << 126) - (i128(1)\
    \ << 63);\ntemplate <> constexpr u32 infty<u32> = infty<int>;\ntemplate <> constexpr\
    \ u64 infty<u64> = infty<i64>;\ntemplate <> constexpr u128 infty<u128> = infty<i128>;\n\
    template <> constexpr double infty<double> = infty<i64>;\ntemplate <> constexpr\
    \ long double infty<long double> = infty<i64>;\n\nconstexpr int mod = 998244353;\n\
    constexpr int modu = 1e9 + 7;\nconstexpr long double PI = 3.14159265358979323846;\n\
    \n\n#line 1 \"template/fastio.hpp\"\n\n\n\n#include <cctype>\n#line 6 \"template/fastio.hpp\"\
    \n#include <cstdio>\n#include <fstream>\n#line 10 \"template/fastio.hpp\"\n\n\
    #line 13 \"template/fastio.hpp\"\n\nnamespace kk2 {\n\nnamespace fastio {\n\n\
    struct Scanner : type_traits::istream_tag {\n  private:\n    static constexpr\
    \ size_t INPUT_BUF = 1 << 17;\n    size_t pos = 0, end = 0;\n    bool is_eof =\
    \ false;\n    static char buf[INPUT_BUF];\n    FILE *fp;\n\n  public:\n    Scanner()\
    \ : fp(stdin) {}\n\n    Scanner(const char *file) : fp(fopen(file, \"r\")) {}\n\
    \n    ~Scanner() {\n        if (fp != stdin) fclose(fp);\n    }\n\n    char now()\
    \ {\n        if (is_eof) return '\\0';\n        if (pos == end) {\n          \
    \  end = fread(buf, 1, INPUT_BUF, fp);\n            if (end != INPUT_BUF) buf[end]\
    \ = '\\0';\n            if (end == 0) is_eof = true;\n            pos = 0;\n \
    \       }\n        return buf[pos];\n    }\n\n    void skip_space() {\n      \
    \  while (isspace(now())) ++pos;\n    }\n\n    template <class T, is_unsigned_t<T>\
    \ * = nullptr> T next_unsigned_integral() {\n        skip_space();\n        T\
    \ res{};\n        while (isdigit(now())) {\n            res = res * 10 + (now()\
    \ - '0');\n            ++pos;\n        }\n        return res;\n    }\n\n    template\
    \ <class T, is_signed_t<T> * = nullptr> T next_signed_integral() {\n        skip_space();\n\
    \        if (now() == '-') {\n            ++pos;\n            return T(-next_unsigned_integral<typename\
    \ to_unsigned<T>::type>());\n        } else return (T)next_unsigned_integral<typename\
    \ to_unsigned<T>::type>();\n    }\n\n    char next_char() {\n        skip_space();\n\
    \        auto res = now();\n        ++pos;\n        return res;\n    }\n\n   \
    \ std::string next_string() {\n        skip_space();\n        std::string res;\n\
    \        while (true) {\n            char c = now();\n            if (isspace(c)\
    \ or c == '\\0') break;\n            res.push_back(now());\n            ++pos;\n\
    \        }\n        return res;\n    }\n\n    template <class T, is_unsigned_t<T>\
    \ * = nullptr> Scanner &operator>>(T &x) {\n        x = next_unsigned_integral<T>();\n\
    \        return *this;\n    }\n\n    template <class T, is_signed_t<T> * = nullptr>\
    \ Scanner &operator>>(T &x) {\n        x = next_signed_integral<T>();\n      \
    \  return *this;\n    }\n\n    Scanner &operator>>(char &x) {\n        x = next_char();\n\
    \        return *this;\n    }\n\n    Scanner &operator>>(std::string &x) {\n \
    \       x = next_string();\n        return *this;\n    }\n};\n\nstruct endl_struct_t\
    \ {};\n\nstruct Printer : type_traits::ostream_tag {\n  private:\n    static char\
    \ helper[10000][5];\n    static char leading_zero[10000][5];\n    constexpr static\
    \ size_t OUTPUT_BUF = 1 << 17;\n    static char buf[OUTPUT_BUF];\n    size_t pos\
    \ = 0;\n    FILE *fp;\n\n    template <class T> static constexpr void div_mod(T\
    \ &a, T &b, T mod) {\n        a = b / mod;\n        b -= a * mod;\n    }\n\n \
    \   static void init() {\n        buf[0] = '\\0';\n        for (size_t i = 0;\
    \ i < 10000; ++i) {\n            leading_zero[i][0] = i / 1000 + '0';\n      \
    \      leading_zero[i][1] = i / 100 % 10 + '0';\n            leading_zero[i][2]\
    \ = i / 10 % 10 + '0';\n            leading_zero[i][3] = i % 10 + '0';\n     \
    \       leading_zero[i][4] = '\\0';\n\n            size_t j = 0;\n           \
    \ if (i >= 1000) helper[i][j++] = i / 1000 + '0';\n            if (i >= 100) helper[i][j++]\
    \ = i / 100 % 10 + '0';\n            if (i >= 10) helper[i][j++] = i / 10 % 10\
    \ + '0';\n            helper[i][j++] = i % 10 + '0';\n            helper[i][j]\
    \ = '\\0';\n        }\n    }\n\n  public:\n    Printer() : fp(stdout) { init();\
    \ }\n\n    Printer(const char *file) : fp(fopen(file, \"w\")) { init(); }\n\n\
    \    ~Printer() {\n        write();\n        if (fp != stdout) fclose(fp);\n \
    \   }\n\n    void write() {\n        fwrite(buf, 1, pos, fp);\n        pos = 0;\n\
    \    }\n\n    void flush() {\n        write();\n        fflush(fp);\n    }\n\n\
    \    void put_char(char c) {\n        if (pos == OUTPUT_BUF) write();\n      \
    \  buf[pos++] = c;\n    }\n\n    void put_cstr(const char *s) {\n        while\
    \ (*s) put_char(*(s++));\n    }\n\n    void put_u32(uint32_t x) {\n        uint32_t\
    \ y;\n        if (x >= 100000000) { // 10^8\n            div_mod<uint32_t>(y,\
    \ x, 100000000);\n            put_cstr(helper[y]);\n            div_mod<uint32_t>(y,\
    \ x, 10000);\n            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= 10000) { // 10^4\n            div_mod<uint32_t>(y, x,\
    \ 10000);\n            put_cstr(helper[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_cstr(helper[x]);\n    }\n\n    void put_i32(int32_t x) {\n\
    \        if (x < 0) {\n            put_char('-');\n            put_u32(-x);\n\
    \        } else put_u32(x);\n    }\n\n    void put_u64(uint64_t x) {\n       \
    \ uint64_t y;\n        if (x >= 1000000000000ull) { // 10^12\n            div_mod<uint64_t>(y,\
    \ x, 1000000000000ull);\n            put_u32(y);\n            div_mod<uint64_t>(y,\
    \ x, 100000000ull);\n            put_cstr(leading_zero[y]);\n            div_mod<uint64_t>(y,\
    \ x, 10000ull);\n            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= 10000ull) { // 10^4\n            div_mod<uint64_t>(y,\
    \ x, 10000ull);\n            put_u32(y);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_cstr(helper[x]);\n    }\n\n    void put_i64(int64_t x) {\n\
    \        if (x < 0) {\n            put_char('-');\n            put_u64(-x);\n\
    \        } else put_u64(x);\n    }\n\n    void put_u128(__uint128_t x) {\n   \
    \     constexpr static __uint128_t pow10_10 = 10000000000ull;\n        constexpr\
    \ static __uint128_t pow10_20 = pow10_10 * pow10_10;\n\n        __uint128_t y;\n\
    \        if (x >= pow10_20) { // 10^20\n            div_mod<__uint128_t>(y, x,\
    \ pow10_20);\n            put_u64(uint64_t(y));\n            div_mod<__uint128_t>(y,\
    \ x, __uint128_t(10000000000000000ull));\n            put_cstr(leading_zero[y]);\n\
    \            div_mod<__uint128_t>(y, x, __uint128_t(1000000000000ull));\n    \
    \        put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x, __uint128_t(100000000ull));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x,\
    \ __uint128_t(10000ull));\n            put_cstr(leading_zero[y]);\n          \
    \  put_cstr(leading_zero[x]);\n        } else if (x >= __uint128_t(10000)) { //\
    \ 10^4\n            div_mod<__uint128_t>(y, x, __uint128_t(10000));\n        \
    \    put_u64(uint64_t(y));\n            put_cstr(leading_zero[x]);\n        }\
    \ else put_cstr(helper[x]);\n    }\n\n    void put_i128(__int128_t x) {\n    \
    \    if (x < 0) {\n            put_char('-');\n            put_u128(-x);\n   \
    \     } else put_u128(x);\n    }\n\n    template <class T, is_unsigned_t<T> *\
    \ = nullptr> Printer &operator<<(T x) {\n        if constexpr (sizeof(T) <= 4)\
    \ put_u32(x);\n        else if constexpr (sizeof(T) <= 8) put_u64(x);\n      \
    \  else put_u128(x);\n        return *this;\n    }\n\n    template <class T, is_signed_t<T>\
    \ * = nullptr> Printer &operator<<(T x) {\n        if constexpr (sizeof(T) <=\
    \ 4) put_i32(x);\n        else if constexpr (sizeof(T) <= 8) put_i64(x);\n   \
    \     else put_i128(x);\n        return *this;\n    }\n\n    Printer &operator<<(char\
    \ x) {\n        put_char(x);\n        return *this;\n    }\n\n    Printer &operator<<(const\
    \ std::string &x) {\n        for (char c : x) put_char(c);\n        return *this;\n\
    \    }\n\n    Printer &operator<<(const char *x) {\n        put_cstr(x);\n   \
    \     return *this;\n    }\n\n    // std::cout << std::endl; \u306F\u95A2\u6570\
    \u30DD\u30A4\u30F3\u30BF\u3092\u6E21\u3057\u3066\u3044\u308B\u3089\u3057\u3044\
    \n    Printer &operator<<(endl_struct_t) {\n        put_char('\\n');\n       \
    \ flush();\n        return *this;\n    }\n};\n\nchar Scanner::buf[Scanner::INPUT_BUF];\n\
    char Printer::buf[Printer::OUTPUT_BUF];\nchar Printer::helper[10000][5];\nchar\
    \ Printer::leading_zero[10000][5];\n\n} // namespace fastio\n\n#if defined(INTERACTIVE)\
    \ || defined(USE_STDIO)\nauto &kin = std::cin;\nauto &kout = std::cout;\nauto\
    \ (*kendl)(std::ostream &) = std::endl<char, std::char_traits<char>>;\n#else\n\
    fastio::Scanner kin;\nfastio::Printer kout;\nfastio::endl_struct_t kendl;\n#endif\n\
    \n} // namespace kk2\n\n\n#line 1 \"template/io_util.hpp\"\n\n\n\n#line 7 \"template/io_util.hpp\"\
    \n\n#line 9 \"template/io_util.hpp\"\n\n// \u306A\u3093\u304Boj verify\u306F\u30D7\
    \u30ED\u30C8\u30BF\u30A4\u30D7\u5BA3\u8A00\u304C\u843D\u3061\u308B\n\nnamespace\
    \ impl {\n\nstruct read {\n    template <class IStream, class T> inline static\
    \ void all_read(IStream &is, T &x) { is >> x; }\n\n    template <class IStream,\
    \ class T, class U>\n    inline static void all_read(IStream &is, std::pair<T,\
    \ U> &p) {\n        all_read(is, p.first);\n        all_read(is, p.second);\n\
    \    }\n\n    template <class IStream, class T> inline static void all_read(IStream\
    \ &is, std::vector<T> &v) {\n        for (T &x : v) all_read(is, x);\n    }\n\n\
    \    template <class IStream, class T, size_t F>\n    inline static void all_read(IStream\
    \ &is, std::array<T, F> &a) {\n        for (T &x : a) all_read(is, x);\n    }\n\
    };\n\nstruct write {\n    template <class OStream, class T> inline static void\
    \ all_write(OStream &os, const T &x) {\n        os << x;\n    }\n\n    template\
    \ <class OStream, class T, class U>\n    inline static void all_write(OStream\
    \ &os, const std::pair<T, U> &p) {\n        all_write(os, p.first);\n        all_write(os,\
    \ ' ');\n        all_write(os, p.second);\n    }\n\n    template <class OStream,\
    \ class T>\n    inline static void all_write(OStream &os, const std::vector<T>\
    \ &v) {\n        for (int i = 0; i < (int)v.size(); ++i) {\n            if (i)\
    \ all_write(os, ' ');\n            all_write(os, v[i]);\n        }\n    }\n\n\
    \    template <class OStream, class T, size_t F>\n    inline static void all_write(OStream\
    \ &os, const std::array<T, F> &a) {\n        for (int i = 0; i < (int)F; ++i)\
    \ {\n            if (i) all_write(os, ' ');\n            all_write(os, a[i]);\n\
    \        }\n    }\n};\n\n} // namespace impl\n\ntemplate <class IStream, class\
    \ T, class U, kk2::is_istream_t<IStream> * = nullptr>\nIStream &operator>>(IStream\
    \ &is, std::pair<T, U> &p) {\n    impl::read::all_read(is, p);\n    return is;\n\
    }\n\ntemplate <class IStream, class T, kk2::is_istream_t<IStream> * = nullptr>\n\
    IStream &operator>>(IStream &is, std::vector<T> &v) {\n    impl::read::all_read(is,\
    \ v);\n    return is;\n}\n\ntemplate <class IStream, class T, size_t F, kk2::is_istream_t<IStream>\
    \ * = nullptr>\nIStream &operator>>(IStream &is, std::array<T, F> &a) {\n    impl::read::all_read(is,\
    \ a);\n    return is;\n}\n\ntemplate <class OStream, class T, class U, kk2::is_ostream_t<OStream>\
    \ * = nullptr>\nOStream &operator<<(OStream &os, const std::pair<T, U> &p) {\n\
    \    impl::write::all_write(os, p);\n    return os;\n}\n\ntemplate <class OStream,\
    \ class T, kk2::is_ostream_t<OStream> * = nullptr>\nOStream &operator<<(OStream\
    \ &os, const std::vector<T> &v) {\n    impl::write::all_write(os, v);\n    return\
    \ os;\n}\n\ntemplate <class OStream, class T, size_t F, kk2::is_ostream_t<OStream>\
    \ * = nullptr>\nOStream &operator<<(OStream &os, const std::array<T, F> &a) {\n\
    \    impl::write::all_write(os, a);\n    return os;\n}\n\n\n#line 1 \"template/macros.hpp\"\
    \n\n\n\n#define rep1(a) for (long long _ = 0; _ < (long long)(a); ++_)\n#define\
    \ rep2(i, a) for (long long i = 0; i < (long long)(a); ++i)\n#define rep3(i, a,\
    \ b) for (long long i = (a); i < (long long)(b); ++i)\n#define repi2(i, a) for\
    \ (long long i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (long long\
    \ i = (a) - 1; i >= (long long)(b); --i)\n#define overload3(a, b, c, d, ...) d\n\
    #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define\
    \ repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n#define\
    \ fi first\n#define se second\n#define all(p) begin(p), end(p)\n\n\n#line 32 \"\
    template/template.hpp\"\n\nusing kk2::kendl;\nusing kk2::kin;\nusing kk2::kout;\n\
    \nvoid Yes(bool b = 1) { kout << (b ? \"Yes\\n\" : \"No\\n\"); }\nvoid No(bool\
    \ b = 1) { kout << (b ? \"No\\n\" : \"Yes\\n\"); }\nvoid YES(bool b = 1) { kout\
    \ << (b ? \"YES\\n\" : \"NO\\n\"); }\nvoid NO(bool b = 1) { kout << (b ? \"NO\\\
    n\" : \"YES\\n\"); }\nvoid yes(bool b = 1) { kout << (b ? \"yes\\n\" : \"no\\\
    n\"); }\nvoid no(bool b = 1) { kout << (b ? \"no\\n\" : \"yes\\n\"); }\ntemplate\
    \ <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a =\
    \ b, 1 : 0); }\ntemplate <class T, class S> inline bool chmin(T &a, const S &b)\
    \ { return (a > b ? a = b, 1 : 0); }\n\n\n#line 7 \"verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp\"\
    \nusing namespace std;\n\nusing mint = kk2::mont998;\n\nusing A = kk2::action::AffineSumWithSize<mint,\
    \ mint>;\n\nint main() {\n    int n, q;\n    kin >> n >> q;\n    vc<A::S> a(n);\n\
    \    kin >> a;\n    kk2::LazyRedBlackTree<A> rbt(2 * (n + q));\n    auto t = rbt.build(a);\n\
    \    rep (i, q) {\n        int type;\n        kin >> type;\n        if (type ==\
    \ 0) {\n            int p, x;\n            kin >> p >> x;\n            rbt.insert(t,\
    \ p, mint(x), mint(1));\n        }\n        if (type == 1) {\n            int\
    \ p;\n            kin >> p;\n            rbt.erase(t, p);\n        }\n       \
    \ if (type == 2) {\n            int l, r;\n            kin >> l >> r;\n      \
    \      rbt.reverse(t, l, r);\n        }\n        if (type == 3) {\n          \
    \  int l, r;\n            mint b, c;\n            kin >> l >> r >> b >> c;\n \
    \           rbt.apply(t, l, r, b, c);\n        }\n        if (type == 4) {\n \
    \           int l, r;\n            kin >> l >> r;\n            kout << rbt.prod(t,\
    \ l, r).a << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include \"../../bbst/lazy_red_black_tree.hpp\"\n#include \"../../modint/mont.hpp\"\
    \n#include \"../../math/action/affine_sumwithsize.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nusing mint = kk2::mont998;\n\nusing A = kk2::action::AffineSumWithSize<mint,\
    \ mint>;\n\nint main() {\n    int n, q;\n    kin >> n >> q;\n    vc<A::S> a(n);\n\
    \    kin >> a;\n    kk2::LazyRedBlackTree<A> rbt(2 * (n + q));\n    auto t = rbt.build(a);\n\
    \    rep (i, q) {\n        int type;\n        kin >> type;\n        if (type ==\
    \ 0) {\n            int p, x;\n            kin >> p >> x;\n            rbt.insert(t,\
    \ p, mint(x), mint(1));\n        }\n        if (type == 1) {\n            int\
    \ p;\n            kin >> p;\n            rbt.erase(t, p);\n        }\n       \
    \ if (type == 2) {\n            int l, r;\n            kin >> l >> r;\n      \
    \      rbt.reverse(t, l, r);\n        }\n        if (type == 3) {\n          \
    \  int l, r;\n            mint b, c;\n            kin >> l >> r >> b >> c;\n \
    \           rbt.apply(t, l, r, b, c);\n        }\n        if (type == 4) {\n \
    \           int l, r;\n            kin >> l >> r;\n            kout << rbt.prod(t,\
    \ l, r).a << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - bbst/lazy_red_black_tree.hpp
  - bbst/base/lazy_red_black_tree_node.hpp
  - type_traits/io.hpp
  - bbst/base/red_black_tree_base.hpp
  - others/vector_pool.hpp
  - modint/mont.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - math/action/affine_sumwithsize.hpp
  - math/group/sum_with_size.hpp
  - type_traits/io.hpp
  - math/monoid/affine.hpp
  - type_traits/io.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
- /verify/verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp.html
title: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
---
