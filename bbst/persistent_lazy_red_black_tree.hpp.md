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
    path: others/vector_pool.hpp
    title: others/vector_pool.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bbst/persistent_lazy_red_black_tree.hpp\"\n\n\n\n#line 1\
    \ \"bbst/base/lazy_red_black_tree_node.hpp\"\n\n\n\n#line 1 \"type_traits/io.hpp\"\
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
    \ kk2\n\n\n#line 1 \"bbst/base/red_black_tree_base.hpp\"\n\n\n\n#include <cassert>\n\
    #include <memory>\n#include <string>\n#include <utility>\n#include <vector>\n\n\
    #line 1 \"others/vector_pool.hpp\"\n\n\n\n#line 6 \"others/vector_pool.hpp\"\n\
    \nnamespace kk2 {\n\ntemplate <typename T> struct VectorPool {\n  private:\n \
    \   static constexpr size_t CHUNK_SIZE = 1 << 11;\n    std::vector<std::unique_ptr<T[]>>\
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
    \n} // namespace kk2\n\n\n#line 6 \"bbst/persistent_lazy_red_black_tree.hpp\"\n\
    \nnamespace kk2 {\n\nnamespace rbtree {\n\ntemplate <class A_> struct PersistentLazyRedBlackTree\n\
    \    : RedBlackTreeBase<PersistentLazyRedBlackTree<A_>, LazyRedBlackTreeNode<A_>>\
    \ {\n    using base = RedBlackTreeBase<PersistentLazyRedBlackTree<A_>, LazyRedBlackTreeNode<A_>>;\n\
    \    using base::a_op;\n    using base::a_unit;\n    using base::alloc;\n    using\
    \ base::merge;\n    using base::RedBlackTreeBase;\n    using base::s_op;\n   \
    \ using base::sa_act;\n    using base::size;\n    using base::split;\n    using\
    \ base::split3;\n    using typename base::A;\n    using typename base::NodePtr;\n\
    \    using typename base::S;\n\n    template <class... Args> void apply(NodePtr\
    \ &t, int l, int r, Args... args) {\n        assert(0 <= l and l <= r and r <=\
    \ size(t));\n        auto [t1, t2, t3] = split3(t, l, r);\n        all_apply(t2,\
    \ A(args...));\n        t = merge(merge(t1, t2), t3);\n    }\n\n    NodePtr update(NodePtr\
    \ t) {\n        t->count = size(t->left) + size(t->right) + (t->left == nullptr);\n\
    \        t->rank = t->left ? t->left->rank + !t->left->is_red : 1;\n        t->val\
    \ = (t->left ? s_op(t->left->val, t->right->val) : t->val);\n        return t;\n\
    \    }\n\n    void all_apply(NodePtr &t, A f) {\n        if (!t) return;\n   \
    \     t = alloc(*t);\n        t->val = sa_act(f, t->val);\n        if (t->left)\
    \ t->lazy = a_op(f, t->lazy);\n    }\n\n    NodePtr push(NodePtr t) {\n      \
    \  t = alloc(*t);\n        if (t->is_rev) {\n            std::swap(t->left, t->right);\n\
    \            // \u3053\u3053\u3067\u5B50\u4F9B\u3092\u8907\u88FD\u3057\u306A\u3044\
    \u3068\u3044\u3051\u306A\u3044\uFF0E\n            if (t->left) t->left->is_rev\
    \ ^= 1;\n            if (t->right) t->right->is_rev ^= 1;\n            t->is_rev\
    \ = false;\n        }\n\n        if (t->lazy != a_unit()) {\n            all_apply(t->left,\
    \ t->lazy);\n            all_apply(t->right, t->lazy);\n            t->lazy =\
    \ a_unit();\n        }\n        return t;\n    }\n};\n\n} // namespace rbtree\n\
    \nusing rbtree::PersistentLazyRedBlackTree;\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_BBST_PERSISTENT_LAZY_RED_BLACK_TREE_HPP\n#define KK2_BBST_PERSISTENT_LAZY_RED_BLACK_TREE_HPP\
    \ 1\n\n#include \"base/lazy_red_black_tree_node.hpp\"\n#include \"base/red_black_tree_base.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace rbtree {\n\ntemplate <class A_> struct PersistentLazyRedBlackTree\n\
    \    : RedBlackTreeBase<PersistentLazyRedBlackTree<A_>, LazyRedBlackTreeNode<A_>>\
    \ {\n    using base = RedBlackTreeBase<PersistentLazyRedBlackTree<A_>, LazyRedBlackTreeNode<A_>>;\n\
    \    using base::a_op;\n    using base::a_unit;\n    using base::alloc;\n    using\
    \ base::merge;\n    using base::RedBlackTreeBase;\n    using base::s_op;\n   \
    \ using base::sa_act;\n    using base::size;\n    using base::split;\n    using\
    \ base::split3;\n    using typename base::A;\n    using typename base::NodePtr;\n\
    \    using typename base::S;\n\n    template <class... Args> void apply(NodePtr\
    \ &t, int l, int r, Args... args) {\n        assert(0 <= l and l <= r and r <=\
    \ size(t));\n        auto [t1, t2, t3] = split3(t, l, r);\n        all_apply(t2,\
    \ A(args...));\n        t = merge(merge(t1, t2), t3);\n    }\n\n    NodePtr update(NodePtr\
    \ t) {\n        t->count = size(t->left) + size(t->right) + (t->left == nullptr);\n\
    \        t->rank = t->left ? t->left->rank + !t->left->is_red : 1;\n        t->val\
    \ = (t->left ? s_op(t->left->val, t->right->val) : t->val);\n        return t;\n\
    \    }\n\n    void all_apply(NodePtr &t, A f) {\n        if (!t) return;\n   \
    \     t = alloc(*t);\n        t->val = sa_act(f, t->val);\n        if (t->left)\
    \ t->lazy = a_op(f, t->lazy);\n    }\n\n    NodePtr push(NodePtr t) {\n      \
    \  t = alloc(*t);\n        if (t->is_rev) {\n            std::swap(t->left, t->right);\n\
    \            // \u3053\u3053\u3067\u5B50\u4F9B\u3092\u8907\u88FD\u3057\u306A\u3044\
    \u3068\u3044\u3051\u306A\u3044\uFF0E\n            if (t->left) t->left->is_rev\
    \ ^= 1;\n            if (t->right) t->right->is_rev ^= 1;\n            t->is_rev\
    \ = false;\n        }\n\n        if (t->lazy != a_unit()) {\n            all_apply(t->left,\
    \ t->lazy);\n            all_apply(t->right, t->lazy);\n            t->lazy =\
    \ a_unit();\n        }\n        return t;\n    }\n};\n\n} // namespace rbtree\n\
    \nusing rbtree::PersistentLazyRedBlackTree;\n\n} // namespace kk2\n\n#endif //\
    \ KK2_BBST_PERSISTENT_LAZY_RED_BLACK_TREE_HPP\n"
  dependsOn:
  - bbst/base/lazy_red_black_tree_node.hpp
  - type_traits/io.hpp
  - bbst/base/red_black_tree_base.hpp
  - others/vector_pool.hpp
  isVerificationFile: false
  path: bbst/persistent_lazy_red_black_tree.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bbst/persistent_lazy_red_black_tree.hpp
layout: document
redirect_from:
- /library/bbst/persistent_lazy_red_black_tree.hpp
- /library/bbst/persistent_lazy_red_black_tree.hpp.html
title: bbst/persistent_lazy_red_black_tree.hpp
---
