---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/ordered_set
    links:
    - https://judge.yosupo.jp/problem/ordered_set
  dependencies:
  - files:
    - filename: binary_trie.hpp
      icon: LIBRARY_ALL_AC
      path: data_structure/binary_trie.hpp
    - filename: constant.hpp
      icon: LIBRARY_ALL_AC
      path: template/constant.hpp
    - filename: fastio.hpp
      icon: LIBRARY_ALL_AC
      path: template/fastio.hpp
    - filename: io_util.hpp
      icon: LIBRARY_ALL_AC
      path: template/io_util.hpp
    - filename: macros.hpp
      icon: LIBRARY_ALL_AC
      path: template/macros.hpp
    - filename: template.hpp
      icon: LIBRARY_ALL_AC
      path: template/template.hpp
    - filename: type_alias.hpp
      icon: LIBRARY_ALL_AC
      path: template/type_alias.hpp
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn:
  - data_structure/binary_trie.hpp
  - template/constant.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  - template/template.hpp
  - template/type_alias.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/ordered_set\n\
      \n#include \"../../data_structure/binary_trie.hpp\"\n#include \"../../template/template.hpp\"\
      \nusing namespace std;\n\nint main() {\n    int n, q;\n    kin >> n >> q;\n\
      \    vc<int> a(n);\n    kin >> a;\n    kk2::BinaryTrie<int, 30> bt(30 * q +\
      \ 20 * n);\n    rep(i, n) bt.insert(a[i]);\n\n    rep(q) {\n        int type,\
      \ x;\n        kin >> type >> x;\n        if (type == 0) {\n            if (!bt.count(x))\
      \ bt.insert(x);\n        } else if (type == 1) {\n            bt.erase(x);\n\
      \        } else if (type == 2) {\n            auto res = bt.get_kth(x - 1);\n\
      \            if (res) kout << *res << \"\\n\";\n            else kout << -1\
      \ << \"\\n\";\n        } else if (type == 3) {\n            kout << bt.count_not_greater(x)\
      \ << \"\\n\";\n        } else if (type == 4) {\n            auto res = bt.max_not_greater(x);\n\
      \            if (res) kout << *res << \"\\n\";\n            else kout << -1\
      \ << \"\\n\";\n        } else {\n            auto res = bt.min_not_less(x);\n\
      \            if (res) kout << *res << \"\\n\";\n            else kout << -1\
      \ << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
    name: default
  - code: "#line 1 \"verify/yosupo_ds/ds_ordered_set_binary_trie.test.cpp\"\n// competitive-verifier:\
      \ PROBLEM https://judge.yosupo.jp/problem/ordered_set\n\n#line 1 \"data_structure/binary_trie.hpp\"\
      \n\n\n\n#include <cassert>\n#include <optional>\n#include <vector>\n\nnamespace\
      \ kk2 {\n\ntemplate <typename T> struct BinaryTrieNode {\n    int nxt[2];\n\
      \    // \u30CE\u30FC\u30C9\u306B\u5BFE\u5FDC\u3059\u308Bprefix\u3092\u3082\u3064\
      \u8981\u7D20\u306E\u6570\n    // \u81EA\u5206\u81EA\u8EAB\u3082\u542B\u3080\n\
      \    int count;\n\n    BinaryTrieNode() : count(0) { nxt[0] = nxt[1] = -1; }\n\
      \n    template <typename U> friend U &operator<<(U &os, const BinaryTrieNode\
      \ &node) {\n        os << \"count: \" << node.count << \" \";\n        os <<\
      \ \"nxt: \";\n        for (int i = 0; i < 2; ++i) os << node.nxt[i] << \" \"\
      ;\n        return os;\n    }\n};\n\ntemplate <typename T, int MAX_LOG> struct\
      \ BinaryTrie {\n    using Node = BinaryTrieNode<T>;\n\n    T lazy;\n    std::vector<Node>\
      \ nodes;\n    constexpr static int root = 0;\n\n    BinaryTrie() : lazy(T())\
      \ { nodes.emplace_back(); }\n\n    BinaryTrie(int Num) : lazy(T()) {\n     \
      \   nodes.reserve(Num);\n        nodes.emplace_back();\n    }\n\n    int push_node()\
      \ {\n        nodes.emplace_back();\n        return nodes.size() - 1;\n    }\n\
      \n    template <bool isadd> void update_direct(int node) {\n        if constexpr\
      \ (isadd) ++nodes[node].count;\n        else --nodes[node].count;\n    }\n\n\
      \    template <bool isadd> void update_child(int node) {\n        if constexpr\
      \ (isadd) ++nodes[node].count;\n        else --nodes[node].count;\n    }\n\n\
      \    void insert(T x) {\n        x ^= lazy;\n        int now = root;\n     \
      \   for (int i = MAX_LOG - 1; i >= 0; --i) {\n            const int d = (x >>\
      \ i) & 1;\n            if (nodes[now].nxt[d] == -1) nodes[now].nxt[d] = push_node();\n\
      \            update_child<true>(now);\n            now = nodes[now].nxt[d];\n\
      \        }\n        update_direct<true>(now);\n    }\n\n    void erase(T x)\
      \ {\n        x ^= lazy;\n        int now = root;\n        int st[MAX_LOG];\n\
      \        for (int i = MAX_LOG - 1; i >= 0; --i) {\n            const int d =\
      \ (x >> i) & 1;\n            if (nodes[now].nxt[d] == -1) return;\n        \
      \    st[i] = now;\n            now = nodes[now].nxt[d];\n        }\n       \
      \ update_direct<false>(now);\n        for (int i = 0; i < MAX_LOG; ++i) {\n\
      \            update_child<false>(st[i]);\n            if (!nodes[now].count)\
      \ nodes[st[i]].nxt[(x >> i) & 1] = -1;\n            now = st[i];\n        }\n\
      \    }\n\n    void operate_xor(T x) { lazy ^= x; }\n\n    std::optional<T> get_kth(int\
      \ k) const {\n        if (k >= nodes[root].count) return std::nullopt;\n   \
      \     int now = root, less = 0;\n        T res = 0;\n        for (int i = MAX_LOG\
      \ - 1; i >= 0; --i) {\n            const int d = (lazy >> i) & 1;\n        \
      \    if (nodes[now].nxt[d] == -1 or less + nodes[nodes[now].nxt[d]].count <=\
      \ k) {\n                if (nodes[now].nxt[d] != -1) less += nodes[nodes[now].nxt[d]].count;\n\
      \                res |= (T(1) << i);\n                now = nodes[now].nxt[d\
      \ ^ 1];\n            } else {\n                now = nodes[now].nxt[d];\n  \
      \          }\n        }\n        return res;\n    }\n\n    int count_not_greater(T\
      \ x) const {\n        int now = root, res = nodes[root].count;\n        for\
      \ (int i = MAX_LOG - 1; i >= 0; --i) {\n            const int zero = (lazy >>\
      \ i) & 1, d = (x >> i) & 1;\n            if (d == 0 and nodes[now].nxt[zero\
      \ ^ 1] != -1)\n                res -= nodes[nodes[now].nxt[zero ^ 1]].count;\n\
      \            now = nodes[now].nxt[d ^ zero];\n            if (now == -1) break;\n\
      \        }\n        return res;\n    }\n\n    int count_not_less(T x) const\
      \ {\n        int now = root, res = nodes[root].count;\n        for (int i =\
      \ MAX_LOG - 1; i >= 0; --i) {\n            const int zero = (lazy >> i) & 1,\
      \ d = (x >> i) & 1;\n            if (d == 1 and nodes[now].nxt[zero] != -1)\
      \ res -= nodes[nodes[now].nxt[zero]].count;\n            now = nodes[now].nxt[d\
      \ ^ zero];\n            if (now == -1) break;\n        }\n        return res;\n\
      \    }\n\n    int count(T x) const {\n        x ^= lazy;\n        int now =\
      \ root;\n        for (int i = MAX_LOG - 1; i >= 0; --i) {\n            const\
      \ int d = (x >> i) & 1;\n            if (nodes[now].nxt[d] == -1) return 0;\n\
      \            now = nodes[now].nxt[d];\n        }\n        return nodes[now].count;\n\
      \    }\n\n    std::optional<T> max_not_greater(T x) const {\n        if (size()\
      \ == 0) return std::nullopt;\n        x ^= lazy;\n        int now = root;\n\
      \        T res = 0;\n        bool same = true;\n        int st[MAX_LOG];\n \
      \       int i = MAX_LOG - 1;\n\n        for (;; --i) {\n            const int\
      \ d = (x >> i) & 1;\n            st[i] = now;\n            if (same) {\n   \
      \             if (d == 0 and nodes[now].nxt[d] != -1) now = nodes[now].nxt[d];\n\
      \                else if (d == 0 and nodes[now].nxt[d] == -1) break;\n     \
      \           else if (d == 1 and nodes[now].nxt[d] != -1) {\n               \
      \     res |= (T(1) << i);\n                    now = nodes[now].nxt[d];\n  \
      \              } else {\n                    assert(nodes[now].nxt[d ^ 1] !=\
      \ -1);\n                    now = nodes[now].nxt[d ^ 1];\n                 \
      \   same = false;\n                }\n            } else {\n               \
      \ if (nodes[now].nxt[1] != -1) {\n                    res |= (T(1) << i);\n\
      \                    now = nodes[now].nxt[1];\n                } else {\n  \
      \                  now = nodes[now].nxt[0];\n                }\n           \
      \ }\n            if (i == 0) return res;\n        }\n\n        ++i;\n      \
      \  for (;; ++i) {\n            if (i == MAX_LOG) return std::nullopt;\n    \
      \        const int d = (x >> i) & 1;\n            res &= ~(T(1) << i);\n   \
      \         now = st[i];\n            if (d == 1 and nodes[now].nxt[d ^ 1] !=\
      \ -1) {\n                now = nodes[now].nxt[d ^ 1];\n                break;\n\
      \            }\n        }\n\n        --i;\n        for (; i >= 0; --i) {\n \
      \           if (nodes[now].nxt[1] != -1) {\n                res |= (T(1) <<\
      \ i);\n                now = nodes[now].nxt[1];\n            } else {\n    \
      \            now = nodes[now].nxt[0];\n            }\n        }\n        return\
      \ res;\n    }\n\n    std::optional<T> min_not_less(T x) const {\n        if\
      \ (size() == 0) return std::nullopt;\n        x ^= lazy;\n        int now =\
      \ root;\n        T res = 0;\n        bool same = true;\n        int st[MAX_LOG];\n\
      \        int i = MAX_LOG - 1;\n        for (;; --i) {\n            const int\
      \ d = (x >> i) & 1;\n            st[i] = now;\n            if (same) {\n   \
      \             if (d == 1 and nodes[now].nxt[d] != -1) {\n                  \
      \  res |= (T(1) << i);\n                    now = nodes[now].nxt[d];\n     \
      \           } else if (d == 1 and nodes[now].nxt[d] == -1) break;\n        \
      \        else if (d == 0 and nodes[now].nxt[d] != -1) now = nodes[now].nxt[d];\n\
      \                else {\n                    assert(nodes[now].nxt[d ^ 1] !=\
      \ -1);\n                    res |= (T(1) << i);\n                    now = nodes[now].nxt[d\
      \ ^ 1];\n                    same = false;\n                }\n            }\
      \ else {\n                if (nodes[now].nxt[0] != -1) {\n                 \
      \   now = nodes[now].nxt[0];\n                } else {\n                   \
      \ res |= (T(1) << i);\n                    now = nodes[now].nxt[1];\n      \
      \          }\n            }\n            if (i == 0) return res;\n        }\n\
      \n        ++i;\n        for (;; ++i) {\n            if (i == MAX_LOG) return\
      \ std::nullopt;\n            const int d = (x >> i) & 1;\n            res &=\
      \ ~(T(1) << i);\n            now = st[i];\n            if (d == 0 and nodes[now].nxt[d\
      \ ^ 1] != -1) {\n                res |= (T(1) << i);\n                now =\
      \ nodes[now].nxt[d ^ 1];\n                break;\n            }\n        }\n\
      \n        --i;\n        for (; i >= 0; --i) {\n            if (nodes[now].nxt[0]\
      \ != -1) {\n                now = nodes[now].nxt[0];\n            } else {\n\
      \                res |= (T(1) << i);\n                now = nodes[now].nxt[1];\n\
      \            }\n        }\n        return res;\n    }\n\n    int size() const\
      \ { return nodes[root].count; }\n};\n\n} // namespace kk2\n\n\n#line 1 \"template/template.hpp\"\
      \n\n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#line 8 \"\
      template/template.hpp\"\n#include <chrono>\n#include <cmath>\n#include <deque>\n\
      #include <functional>\n#include <iterator>\n#include <limits>\n#include <map>\n\
      #include <numeric>\n#line 17 \"template/template.hpp\"\n#include <queue>\n#include\
      \ <random>\n#include <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n\
      #include <unordered_set>\n#include <utility>\n#line 26 \"template/template.hpp\"\
      \n\n#line 1 \"template/constant.hpp\"\n\n\n\n#line 1 \"template/type_alias.hpp\"\
      \n\n\n\n#line 8 \"template/type_alias.hpp\"\n\nusing u32 = unsigned int;\nusing\
      \ i64 = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\n\
      using u128 = __uint128_t;\n\nusing pi = std::pair<int, int>;\nusing pl = std::pair<i64,\
      \ i64>;\nusing pil = std::pair<int, i64>;\nusing pli = std::pair<i64, int>;\n\
      \ntemplate <class T> using vc = std::vector<T>;\ntemplate <class T> using vvc\
      \ = std::vector<vc<T>>;\ntemplate <class T> using vvvc = std::vector<vvc<T>>;\n\
      template <class T> using vvvvc = std::vector<vvvc<T>>;\n\ntemplate <class T>\
      \ using pq = std::priority_queue<T>;\ntemplate <class T> using pqi = std::priority_queue<T,\
      \ std::vector<T>, std::greater<T>>;\n\n\n#line 5 \"template/constant.hpp\"\n\
      \ntemplate <class T> constexpr T infty = 0;\ntemplate <> constexpr int infty<int>\
      \ = (1 << 30) - 123;\ntemplate <> constexpr i64 infty<i64> = (1ll << 62) - (1ll\
      \ << 31);\ntemplate <> constexpr i128 infty<i128> = (i128(1) << 126) - (i128(1)\
      \ << 63);\ntemplate <> constexpr u32 infty<u32> = infty<int>;\ntemplate <> constexpr\
      \ u64 infty<u64> = infty<i64>;\ntemplate <> constexpr u128 infty<u128> = infty<i128>;\n\
      template <> constexpr double infty<double> = infty<i64>;\ntemplate <> constexpr\
      \ long double infty<long double> = infty<i64>;\n\nconstexpr int mod = 998244353;\n\
      constexpr int modu = 1e9 + 7;\nconstexpr long double PI = 3.14159265358979323846;\n\
      \n\n#line 1 \"template/fastio.hpp\"\n\n\n\n#include <cctype>\n#include <cstdint>\n\
      #include <cstdio>\n#include <fstream>\n#include <iostream>\n#line 10 \"template/fastio.hpp\"\
      \n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace\
      \ kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T>\nusing is_signed_int128\
      \ = typename std::conditional<std::is_same<T, __int128_t>::value\n         \
      \                                              or std::is_same<T, __int128>::value,\n\
      \                                                   std::true_type,\n      \
      \                                             std::false_type>::type;\n\ntemplate\
      \ <typename T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __uint128_t>::value\n                                  or std::is_same<T,\
      \ unsigned __int128>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_integral =\n    typename std::conditional<std::is_integral<T>::value\
      \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T>\nusing is_signed = typename\
      \ std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n\
      \                                            std::true_type,\n             \
      \                               std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
      \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename\
      \ T>\nusing to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
      \                              make_unsigned_int128<T>,\n                  \
      \            typename std::conditional<std::is_signed<T>::value,\n         \
      \                                               std::make_unsigned<T>,\n   \
      \                                                     std::common_type<T>>::type>::type;\n\
      \n#else\n\ntemplate <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
      template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
      template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
      template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
      \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
      template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
      template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
      \ntemplate <class T>\nconcept Integral = is_integral<std::remove_cv_t<T>>::value;\n\
      \ntemplate <class T>\nconcept SignedIntegral = is_signed<std::remove_cv_t<T>>::value;\n\
      \ntemplate <class T>\nconcept UnsignedIntegral = is_unsigned<std::remove_cv_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <concepts>\n\
      #line 6 \"type_traits/io.hpp\"\n#include <istream>\n#include <ostream>\n#line\
      \ 9 \"type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace type_traits {\n\n\
      struct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\
      \ntemplate <typename T>\nusing is_standard_istream = typename std::conditional<std::is_same<T,\
      \ std::istream>::value\n                                                   \
      \       || std::is_same<T, std::ifstream>::value,\n                        \
      \                              std::true_type,\n                           \
      \                           std::false_type>::type;\ntemplate <typename T>\n\
      using is_standard_ostream = typename std::conditional<std::is_same<T, std::ostream>::value\n\
      \                                                          || std::is_same<T,\
      \ std::ofstream>::value,\n                                                 \
      \     std::true_type,\n                                                    \
      \  std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
      \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
      \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
      template <typename T>\nusing is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
      \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
      \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate\
      \ <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\
      \ntemplate <class T>\nconcept StandardInputStream = is_standard_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept StandardOutputStream = is_standard_ostream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept InputStream = is_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept OutputStream = is_ostream<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 13 \"template/fastio.hpp\"\n\nnamespace kk2\
      \ {\n\nnamespace fastio {\n\nstruct Scanner : type_traits::istream_tag {\n \
      \ private:\n    static constexpr size_t INPUT_BUF = 1 << 17;\n    size_t pos\
      \ = 0, end = 0;\n    bool is_eof = false;\n    static char buf[INPUT_BUF];\n\
      \    FILE *fp;\n\n  public:\n    Scanner() : fp(stdin) {}\n\n    Scanner(const\
      \ char *file) : fp(fopen(file, \"r\")) {}\n\n    ~Scanner() {\n        if (fp\
      \ != stdin) fclose(fp);\n    }\n\n    char now() {\n        if (is_eof) return\
      \ '\\0';\n        if (pos == end) {\n            end = fread(buf, 1, INPUT_BUF,\
      \ fp);\n            if (end != INPUT_BUF) buf[end] = '\\0';\n            if\
      \ (end == 0) is_eof = true;\n            pos = 0;\n        }\n        return\
      \ buf[pos];\n    }\n\n    void skip_space() {\n        while (isspace(now()))\
      \ ++pos;\n    }\n\n    template <UnsignedIntegral T> T next_unsigned_integral()\
      \ {\n        skip_space();\n        T res{};\n        while (isdigit(now()))\
      \ {\n            res = res * 10 + (now() - '0');\n            ++pos;\n     \
      \   }\n        return res;\n    }\n\n    template <SignedIntegral T> T next_signed_integral()\
      \ {\n        skip_space();\n        if (now() == '-') {\n            ++pos;\n\
      \            return T(-next_unsigned_integral<typename to_unsigned<T>::type>());\n\
      \        } else return (T)next_unsigned_integral<typename to_unsigned<T>::type>();\n\
      \    }\n\n    char next_char() {\n        skip_space();\n        auto res =\
      \ now();\n        ++pos;\n        return res;\n    }\n\n    std::string next_string()\
      \ {\n        skip_space();\n        std::string res;\n        while (true) {\n\
      \            char c = now();\n            if (isspace(c) or c == '\\0') break;\n\
      \            res.push_back(now());\n            ++pos;\n        }\n        return\
      \ res;\n    }\n\n    template <UnsignedIntegral T> Scanner &operator>>(T &x)\
      \ {\n        x = next_unsigned_integral<T>();\n        return *this;\n    }\n\
      \n    template <SignedIntegral T> Scanner &operator>>(T &x) {\n        x = next_signed_integral<T>();\n\
      \        return *this;\n    }\n\n    Scanner &operator>>(char &x) {\n      \
      \  x = next_char();\n        return *this;\n    }\n\n    Scanner &operator>>(std::string\
      \ &x) {\n        x = next_string();\n        return *this;\n    }\n};\n\nstruct\
      \ endl_struct_t {};\n\nstruct Printer : type_traits::ostream_tag {\n  private:\n\
      \    static char helper[10000][5];\n    static char leading_zero[10000][5];\n\
      \    constexpr static size_t OUTPUT_BUF = 1 << 17;\n    static char buf[OUTPUT_BUF];\n\
      \    size_t pos = 0;\n    FILE *fp;\n\n    template <class T> static constexpr\
      \ void div_mod(T &a, T &b, T mod) {\n        a = b / mod;\n        b -= a *\
      \ mod;\n    }\n\n    static void init() {\n        buf[0] = '\\0';\n       \
      \ for (size_t i = 0; i < 10000; ++i) {\n            leading_zero[i][0] = i /\
      \ 1000 + '0';\n            leading_zero[i][1] = i / 100 % 10 + '0';\n      \
      \      leading_zero[i][2] = i / 10 % 10 + '0';\n            leading_zero[i][3]\
      \ = i % 10 + '0';\n            leading_zero[i][4] = '\\0';\n\n            size_t\
      \ j = 0;\n            if (i >= 1000) helper[i][j++] = i / 1000 + '0';\n    \
      \        if (i >= 100) helper[i][j++] = i / 100 % 10 + '0';\n            if\
      \ (i >= 10) helper[i][j++] = i / 10 % 10 + '0';\n            helper[i][j++]\
      \ = i % 10 + '0';\n            helper[i][j] = '\\0';\n        }\n    }\n\n \
      \ public:\n    Printer() : fp(stdout) { init(); }\n\n    Printer(const char\
      \ *file) : fp(fopen(file, \"w\")) { init(); }\n\n    ~Printer() {\n        write();\n\
      \        if (fp != stdout) fclose(fp);\n    }\n\n    void write() {\n      \
      \  fwrite(buf, 1, pos, fp);\n        pos = 0;\n    }\n\n    void flush() {\n\
      \        write();\n        fflush(fp);\n    }\n\n    void put_char(char c) {\n\
      \        if (pos == OUTPUT_BUF) write();\n        buf[pos++] = c;\n    }\n\n\
      \    void put_cstr(const char *s) {\n        while (*s) put_char(*(s++));\n\
      \    }\n\n    void put_u32(uint32_t x) {\n        uint32_t y;\n        if (x\
      \ >= 100000000) { // 10^8\n            div_mod<uint32_t>(y, x, 100000000);\n\
      \            put_cstr(helper[y]);\n            div_mod<uint32_t>(y, x, 10000);\n\
      \            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
      \        } else if (x >= 10000) { // 10^4\n            div_mod<uint32_t>(y,\
      \ x, 10000);\n            put_cstr(helper[y]);\n            put_cstr(leading_zero[x]);\n\
      \        } else put_cstr(helper[x]);\n    }\n\n    void put_i32(int32_t x) {\n\
      \        if (x < 0) {\n            put_char('-');\n            put_u32(-x);\n\
      \        } else put_u32(x);\n    }\n\n    void put_u64(uint64_t x) {\n     \
      \   uint64_t y;\n        if (x >= 1000000000000ull) { // 10^12\n           \
      \ div_mod<uint64_t>(y, x, 1000000000000ull);\n            put_u32(y);\n    \
      \        div_mod<uint64_t>(y, x, 100000000ull);\n            put_cstr(leading_zero[y]);\n\
      \            div_mod<uint64_t>(y, x, 10000ull);\n            put_cstr(leading_zero[y]);\n\
      \            put_cstr(leading_zero[x]);\n        } else if (x >= 10000ull) {\
      \ // 10^4\n            div_mod<uint64_t>(y, x, 10000ull);\n            put_u32(y);\n\
      \            put_cstr(leading_zero[x]);\n        } else put_cstr(helper[x]);\n\
      \    }\n\n    void put_i64(int64_t x) {\n        if (x < 0) {\n            put_char('-');\n\
      \            put_u64(-x);\n        } else put_u64(x);\n    }\n\n    void put_u128(__uint128_t\
      \ x) {\n        constexpr static __uint128_t pow10_10 = 10000000000ull;\n  \
      \      constexpr static __uint128_t pow10_20 = pow10_10 * pow10_10;\n\n    \
      \    __uint128_t y;\n        if (x >= pow10_20) { // 10^20\n            div_mod<__uint128_t>(y,\
      \ x, pow10_20);\n            put_u64(uint64_t(y));\n            div_mod<__uint128_t>(y,\
      \ x, __uint128_t(10000000000000000ull));\n            put_cstr(leading_zero[y]);\n\
      \            div_mod<__uint128_t>(y, x, __uint128_t(1000000000000ull));\n  \
      \          put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x,\
      \ __uint128_t(100000000ull));\n            put_cstr(leading_zero[y]);\n    \
      \        div_mod<__uint128_t>(y, x, __uint128_t(10000ull));\n            put_cstr(leading_zero[y]);\n\
      \            put_cstr(leading_zero[x]);\n        } else if (x >= __uint128_t(10000))\
      \ { // 10^4\n            div_mod<__uint128_t>(y, x, __uint128_t(10000));\n \
      \           put_u64(uint64_t(y));\n            put_cstr(leading_zero[x]);\n\
      \        } else put_cstr(helper[x]);\n    }\n\n    void put_i128(__int128_t\
      \ x) {\n        if (x < 0) {\n            put_char('-');\n            put_u128(-x);\n\
      \        } else put_u128(x);\n    }\n\n    template <UnsignedIntegral T> Printer\
      \ &operator<<(T x) {\n        if constexpr (sizeof(T) <= 4) put_u32(x);\n  \
      \      else if constexpr (sizeof(T) <= 8) put_u64(x);\n        else put_u128(x);\n\
      \        return *this;\n    }\n\n    template <SignedIntegral T> Printer &operator<<(T\
      \ x) {\n        if constexpr (sizeof(T) <= 4) put_i32(x);\n        else if constexpr\
      \ (sizeof(T) <= 8) put_i64(x);\n        else put_i128(x);\n        return *this;\n\
      \    }\n\n    Printer &operator<<(char x) {\n        put_char(x);\n        return\
      \ *this;\n    }\n\n    Printer &operator<<(const std::string &x) {\n       \
      \ for (char c : x) put_char(c);\n        return *this;\n    }\n\n    Printer\
      \ &operator<<(const char *x) {\n        put_cstr(x);\n        return *this;\n\
      \    }\n\n    // std::cout << std::endl; \u306F\u95A2\u6570\u30DD\u30A4\u30F3\
      \u30BF\u3092\u6E21\u3057\u3066\u3044\u308B\u3089\u3057\u3044\n    Printer &operator<<(endl_struct_t)\
      \ {\n        put_char('\\n');\n        flush();\n        return *this;\n   \
      \ }\n};\n\nchar Scanner::buf[Scanner::INPUT_BUF];\nchar Printer::buf[Printer::OUTPUT_BUF];\n\
      char Printer::helper[10000][5];\nchar Printer::leading_zero[10000][5];\n\n}\
      \ // namespace fastio\n\n#if defined(INTERACTIVE) || defined(USE_STDIO)\nauto\
      \ &kin = std::cin;\nauto &kout = std::cout;\nauto (*kendl)(std::ostream &) =\
      \ std::endl<char, std::char_traits<char>>;\n#else\nfastio::Scanner kin;\nfastio::Printer\
      \ kout;\nfastio::endl_struct_t kendl;\n#endif\n\n} // namespace kk2\n\n\n#line\
      \ 1 \"template/io_util.hpp\"\n\n\n\n#line 7 \"template/io_util.hpp\"\n\n#line\
      \ 9 \"template/io_util.hpp\"\n\n// \u306A\u3093\u304Boj verify\u306F\u30D7\u30ED\
      \u30C8\u30BF\u30A4\u30D7\u5BA3\u8A00\u304C\u843D\u3061\u308B\n\nnamespace impl\
      \ {\n\nstruct read {\n    template <class IStream, class T> inline static void\
      \ all_read(IStream &is, T &x) { is >> x; }\n\n    template <class IStream, class\
      \ T, class U>\n    inline static void all_read(IStream &is, std::pair<T, U>\
      \ &p) {\n        all_read(is, p.first);\n        all_read(is, p.second);\n \
      \   }\n\n    template <class IStream, class T> inline static void all_read(IStream\
      \ &is, std::vector<T> &v) {\n        for (T &x : v) all_read(is, x);\n    }\n\
      \n    template <class IStream, class T, size_t F>\n    inline static void all_read(IStream\
      \ &is, std::array<T, F> &a) {\n        for (T &x : a) all_read(is, x);\n   \
      \ }\n};\n\nstruct write {\n    template <class OStream, class T> inline static\
      \ void all_write(OStream &os, const T &x) {\n        os << x;\n    }\n\n   \
      \ template <class OStream, class T, class U>\n    inline static void all_write(OStream\
      \ &os, const std::pair<T, U> &p) {\n        all_write(os, p.first);\n      \
      \  all_write(os, ' ');\n        all_write(os, p.second);\n    }\n\n    template\
      \ <class OStream, class T>\n    inline static void all_write(OStream &os, const\
      \ std::vector<T> &v) {\n        for (int i = 0; i < (int)v.size(); ++i) {\n\
      \            if (i) all_write(os, ' ');\n            all_write(os, v[i]);\n\
      \        }\n    }\n\n    template <class OStream, class T, size_t F>\n    inline\
      \ static void all_write(OStream &os, const std::array<T, F> &a) {\n        for\
      \ (int i = 0; i < (int)F; ++i) {\n            if (i) all_write(os, ' ');\n \
      \           all_write(os, a[i]);\n        }\n    }\n};\n\n} // namespace impl\n\
      \ntemplate <kk2::InputStream IStream, class T, class U>\nIStream &operator>>(IStream\
      \ &is, std::pair<T, U> &p) {\n    impl::read::all_read(is, p);\n    return is;\n\
      }\n\ntemplate <kk2::InputStream IStream, class T> IStream &operator>>(IStream\
      \ &is, std::vector<T> &v) {\n    impl::read::all_read(is, v);\n    return is;\n\
      }\n\ntemplate <kk2::InputStream IStream, class T, size_t F>\nIStream &operator>>(IStream\
      \ &is, std::array<T, F> &a) {\n    impl::read::all_read(is, a);\n    return\
      \ is;\n}\n\ntemplate <kk2::OutputStream OStream, class T, class U>\nOStream\
      \ &operator<<(OStream &os, const std::pair<T, U> &p) {\n    impl::write::all_write(os,\
      \ p);\n    return os;\n}\n\ntemplate <kk2::OutputStream OStream, class T>\n\
      OStream &operator<<(OStream &os, const std::vector<T> &v) {\n    impl::write::all_write(os,\
      \ v);\n    return os;\n}\n\ntemplate <kk2::OutputStream OStream, class T, size_t\
      \ F>\nOStream &operator<<(OStream &os, const std::array<T, F> &a) {\n    impl::write::all_write(os,\
      \ a);\n    return os;\n}\n\n\n#line 1 \"template/macros.hpp\"\n\n\n\n#define\
      \ rep1(a) for (long long _ = 0; _ < (long long)(a); ++_)\n#define rep2(i, a)\
      \ for (long long i = 0; i < (long long)(a); ++i)\n#define rep3(i, a, b) for\
      \ (long long i = (a); i < (long long)(b); ++i)\n#define repi2(i, a) for (long\
      \ long i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (long long i =\
      \ (a) - 1; i >= (long long)(b); --i)\n#define overload3(a, b, c, d, ...) d\n\
      #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define\
      \ repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n#define\
      \ fi first\n#define se second\n#define all(p) begin(p), end(p)\n\n\n#line 32\
      \ \"template/template.hpp\"\n\nusing kk2::kendl;\nusing kk2::kin;\nusing kk2::kout;\n\
      \nvoid Yes(bool b = 1) { kout << (b ? \"Yes\\n\" : \"No\\n\"); }\nvoid No(bool\
      \ b = 1) { kout << (b ? \"No\\n\" : \"Yes\\n\"); }\nvoid YES(bool b = 1) { kout\
      \ << (b ? \"YES\\n\" : \"NO\\n\"); }\nvoid NO(bool b = 1) { kout << (b ? \"\
      NO\\n\" : \"YES\\n\"); }\nvoid yes(bool b = 1) { kout << (b ? \"yes\\n\" : \"\
      no\\n\"); }\nvoid no(bool b = 1) { kout << (b ? \"no\\n\" : \"yes\\n\"); }\n\
      template <class T, class S> inline bool chmax(T &a, const S &b) { return (a\
      \ < b ? a = b, 1 : 0); }\ntemplate <class T, class S> inline bool chmin(T &a,\
      \ const S &b) { return (a > b ? a = b, 1 : 0); }\n\n\n#line 5 \"verify/yosupo_ds/ds_ordered_set_binary_trie.test.cpp\"\
      \nusing namespace std;\n\nint main() {\n    int n, q;\n    kin >> n >> q;\n\
      \    vc<int> a(n);\n    kin >> a;\n    kk2::BinaryTrie<int, 30> bt(30 * q +\
      \ 20 * n);\n    rep(i, n) bt.insert(a[i]);\n\n    rep(q) {\n        int type,\
      \ x;\n        kin >> type >> x;\n        if (type == 0) {\n            if (!bt.count(x))\
      \ bt.insert(x);\n        } else if (type == 1) {\n            bt.erase(x);\n\
      \        } else if (type == 2) {\n            auto res = bt.get_kth(x - 1);\n\
      \            if (res) kout << *res << \"\\n\";\n            else kout << -1\
      \ << \"\\n\";\n        } else if (type == 3) {\n            kout << bt.count_not_greater(x)\
      \ << \"\\n\";\n        } else if (type == 4) {\n            auto res = bt.max_not_greater(x);\n\
      \            if (res) kout << *res << \"\\n\";\n            else kout << -1\
      \ << \"\\n\";\n        } else {\n            auto res = bt.min_not_less(x);\n\
      \            if (res) kout << *res << \"\\n\";\n            else kout << -1\
      \ << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
    name: bundled
  isFailed: false
  isVerificationFile: true
  path: verify/yosupo_ds/ds_ordered_set_binary_trie.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases:
  - elapsed: 0.002184995000050094
    environment: g++
    memory: 3.844
    name: example_00
    status: AC
  - elapsed: 0.0017696860000455672
    environment: g++
    memory: 3.844
    name: example_01
    status: AC
  - elapsed: 0.12684167500003696
    environment: g++
    memory: 4.456
    name: max_random_00
    status: AC
  - elapsed: 0.12443466900003841
    environment: g++
    memory: 4.112
    name: max_random_01
    status: AC
  - elapsed: 0.08022901500004309
    environment: g++
    memory: 4.224
    name: max_random_02
    status: AC
  - elapsed: 0.08885699899997235
    environment: g++
    memory: 4.132
    name: max_random_03
    status: AC
  - elapsed: 0.16126093599996238
    environment: g++
    memory: 4.1
    name: max_random_04
    status: AC
  - elapsed: 0.09134531699999116
    environment: g++
    memory: 4.1
    name: max_random_05
    status: AC
  - elapsed: 0.1110452149999901
    environment: g++
    memory: 4.076
    name: max_random_06
    status: AC
  - elapsed: 0.11657509600001958
    environment: g++
    memory: 4.1
    name: max_random_07
    status: AC
  - elapsed: 0.17617298600004005
    environment: g++
    memory: 15.792
    name: max_random_08
    status: AC
  - elapsed: 0.16899381999996876
    environment: g++
    memory: 4.2
    name: max_random_09
    status: AC
  - elapsed: 0.08761748699998861
    environment: g++
    memory: 4.96
    name: max_random_10
    status: AC
  - elapsed: 0.05968754399998488
    environment: g++
    memory: 5.224
    name: max_random_11
    status: AC
  - elapsed: 0.1991606600000182
    environment: g++
    memory: 4.456
    name: max_random_12
    status: AC
  - elapsed: 0.1003709830000048
    environment: g++
    memory: 4.32
    name: max_random_13
    status: AC
  - elapsed: 0.17134877300003382
    environment: g++
    memory: 4.328
    name: max_random_14
    status: AC
  - elapsed: 0.16322326900001372
    environment: g++
    memory: 4.364
    name: max_random_15
    status: AC
  - elapsed: 0.3726398359999621
    environment: g++
    memory: 24.264
    name: max_random_16
    status: AC
  - elapsed: 0.367977322999991
    environment: g++
    memory: 24.144
    name: max_random_17
    status: AC
  - elapsed: 0.34379279800003815
    environment: g++
    memory: 26.16
    name: max_random_18
    status: AC
  - elapsed: 0.35209037300001
    environment: g++
    memory: 22.08
    name: max_random_19
    status: AC
  - elapsed: 0.440509569000028
    environment: g++
    memory: 22.08
    name: max_random_20
    status: AC
  - elapsed: 0.2688972239999998
    environment: g++
    memory: 22.216
    name: max_random_21
    status: AC
  - elapsed: 0.333070140000018
    environment: g++
    memory: 22.216
    name: max_random_22
    status: AC
  - elapsed: 0.3033549120000316
    environment: g++
    memory: 22.228
    name: max_random_23
    status: AC
  - elapsed: 0.5896074899999917
    environment: g++
    memory: 83.536
    name: max_random_24
    status: AC
  - elapsed: 0.6054510939999886
    environment: g++
    memory: 83.54
    name: max_random_25
    status: AC
  - elapsed: 0.5374636329999589
    environment: g++
    memory: 99.888
    name: max_random_26
    status: AC
  - elapsed: 0.47017627500002845
    environment: g++
    memory: 77.236
    name: max_random_27
    status: AC
  - elapsed: 0.6251423809999892
    environment: g++
    memory: 77.396
    name: max_random_28
    status: AC
  - elapsed: 0.5373587589999715
    environment: g++
    memory: 77.296
    name: max_random_29
    status: AC
  - elapsed: 0.735203815000034
    environment: g++
    memory: 77.388
    name: max_random_30
    status: AC
  - elapsed: 0.7427791759999991
    environment: g++
    memory: 77.372
    name: max_random_31
    status: AC
  - elapsed: 0.10131003499998315
    environment: g++
    memory: 19.78
    name: small_00
    status: AC
  - elapsed: 0.10700154199997769
    environment: g++
    memory: 11.588
    name: small_01
    status: AC
  - elapsed: 0.10936067199997979
    environment: g++
    memory: 9.54
    name: small_02
    status: AC
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_ordered_set_binary_trie.test.cpp
layout: document
---
