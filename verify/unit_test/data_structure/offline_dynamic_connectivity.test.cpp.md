---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/offline_dynamic_connectivity.hpp
    title: data_structure/offline_dynamic_connectivity.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/seed.hpp
    title: random/seed.hpp
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
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':heavy_check_mark:'
    path: unionfind/rollback.hpp
    title: unionfind/rollback.hpp
  - icon: ':question:'
    path: unionfind/unionfind.hpp
    title: unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#line 1 \"data_structure/offline_dynamic_connectivity.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <unordered_map>\n#include <utility>\n#include\
    \ <vector>\n\n#line 1 \"unionfind/rollback.hpp\"\n\n\n\n#line 6 \"unionfind/rollback.hpp\"\
    \n\nnamespace kk2 {\n\nstruct RollbackableUnionFind {\n    std::vector<int> d;\n\
    \    std::vector<std::pair<int, int>> hist;\n    std::vector<int> snaps;\n\n \
    \   RollbackableUnionFind(int n = 0) : d(n, -1) {}\n\n    bool same(int x, int\
    \ y) { return find(x) == find(y); }\n\n    bool unite(int x, int y) {\n      \
    \  x = find(x), y = find(y);\n        if (x == y) return false;\n        if (d[x]\
    \ > d[y]) std::swap(x, y);\n        hist.emplace_back(x, d[x]);\n        d[x]\
    \ += d[y];\n        hist.emplace_back(y, d[y]);\n        d[y] = x;\n        return\
    \ true;\n    }\n\n    int find(int x) {\n        if (d[x] < 0) return x;\n   \
    \     return find(d[x]);\n    }\n\n    int size(int x) { return -d[find(x)]; }\n\
    \n    void snapshot() { snaps.push_back(hist.size()); }\n\n    void rollback()\
    \ {\n        while (int(hist.size()) > snaps.back()) {\n            auto [i, x]\
    \ = hist.back();\n            hist.pop_back();\n            d[i] = x;\n      \
    \  }\n        snaps.pop_back();\n    }\n};\n\n} // namespace kk2\n\n\n#line 10\
    \ \"data_structure/offline_dynamic_connectivity.hpp\"\n\nnamespace kk2 {\n\nstruct\
    \ OfflineDynamicConnectivity {\n  private:\n    int n, q, sz;\n\n    using E =\
    \ std::pair<int, int>;\n    std::vector<std::pair<E, int>> es;\n    std::vector<E>\
    \ seg;\n    std::vector<int> siz;\n\n    void apply(int l, int r, E e) {\n   \
    \     l += sz, r += sz;\n        while (l < r) {\n            if (l & 1) seg[siz[l++]++]\
    \ = e;\n            if (r & 1) seg[siz[--r]++] = e;\n            l >>= 1, r >>=\
    \ 1;\n        }\n    }\n\n    void apply_pre(int l, int r) {\n        l += sz,\
    \ r += sz;\n        while (l < r) {\n            if (l & 1) siz[l++]++;\n    \
    \        if (r & 1) siz[--r]++;\n            l >>= 1, r >>= 1;\n        }\n  \
    \  }\n\n    void seg_build() {\n        for (int i = 1; i < 2 * sz - 1; i++) siz[i\
    \ + 1] += siz[i];\n        seg.resize(siz[2 * sz - 1]);\n        for (int i =\
    \ 2 * sz - 1; i; --i) siz[i] = siz[i - 1];\n    }\n\n  public:\n    RollbackableUnionFind\
    \ uf;\n\n    OfflineDynamicConnectivity(int n_, int q_) : n(n_), q(q_), sz(1),\
    \ uf(n) {\n        while (sz < n) sz <<= 1;\n        siz.resize(2 * sz, 0);\n\
    \    }\n\n    void add_edge(int t, int a, int b) {\n        es.push_back({\n \
    \           {a, b},\n            2 * t\n        });\n    }\n\n    void del_edge(int\
    \ t, int a, int b) {\n        es.push_back({\n            {a, b},\n          \
    \  2 * t + 1\n        });\n    }\n\n    void build(bool is_sorted = false) {\n\
    \        if (!is_sorted) std::sort(es.begin(), es.end());\n        E pree = {-1,\
    \ -1};\n        int pret = -1;\n        for (auto [e, t] : es) {\n           \
    \ if (pree != e) {\n                if (pret != -1) apply_pre(pret, q);\n    \
    \            pree = e;\n                pret = -1;\n            }\n          \
    \  if (t & 1 and pret != -1) {\n                apply_pre(pret, t / 2);\n    \
    \            pret = -1;\n            } else if (~t & 1 and pret == -1) {\n   \
    \             pret = t / 2;\n            }\n        }\n        if (pret != -1)\
    \ apply_pre(pret, q);\n\n        seg_build();\n        pree = {-1, -1};\n    \
    \    pret = -1;\n        for (auto [e, t] : es) {\n            if (pree != e)\
    \ {\n                if (pret != -1) apply(pret, q, pree);\n                pree\
    \ = e;\n                pret = -1;\n            }\n            if (t & 1 and pret\
    \ != -1) {\n                apply(pret, t / 2, e);\n                pret = -1;\n\
    \            } else if (~t & 1 and pret == -1) {\n                pret = t / 2;\n\
    \            }\n        }\n        if (pret != -1) apply(pret, q, pree);\n   \
    \ }\n\n    template <class Query> void run(const Query &query) {\n        auto\
    \ dfs = [&](auto self, int now) -> void {\n            if (now - sz >= q) return;\n\
    \            uf.snapshot();\n            for (int i = siz[now - 1]; i < siz[now];\
    \ i++) uf.unite(seg[i].first, seg[i].second);\n            if (now >= sz) {\n\
    \                query(now - sz);\n            } else {\n                self(self,\
    \ now * 2);\n                self(self, now * 2 + 1);\n            }\n       \
    \     uf.rollback();\n        };\n        dfs(dfs, 1);\n    }\n};\n\n\n} // namespace\
    \ kk2\n\n\n#line 1 \"unionfind/unionfind.hpp\"\n\n\n\n#line 6 \"unionfind/unionfind.hpp\"\
    \n\nnamespace kk2 {\n\nstruct UnionFind {\n    std::vector<int> d;\n\n    UnionFind(int\
    \ n = 0) : d(n, -1) {}\n\n    bool same(int x, int y) { return find(x) == find(y);\
    \ }\n\n    bool unite(int x, int y) {\n        x = find(x), y = find(y);\n   \
    \     if (x == y) return false;\n        if (-d[x] < -d[y]) std::swap(x, y);\n\
    \        d[x] += d[y];\n        d[y] = x;\n        return true;\n    }\n\n   \
    \ template <class F> bool unite(int x, int y, const F &f) {\n        x = find(x),\
    \ y = find(y);\n        if (x == y) return false;\n        if (-d[x] < -d[y])\
    \ std::swap(x, y);\n        f(x, y);\n        d[x] += d[y];\n        d[y] = x;\n\
    \        return true;\n    }\n\n    int find(int x) {\n        if (d[x] < 0) return\
    \ x;\n        return d[x] = find(d[x]);\n    }\n\n    int size(int x) { return\
    \ -d[find(x)]; }\n};\n\n} // namespace kk2\n\n\n#line 1 \"random/gen.hpp\"\n\n\
    \n\n#line 5 \"random/gen.hpp\"\n#include <cassert>\n#include <numeric>\n#include\
    \ <random>\n#include <unordered_set>\n#line 10 \"random/gen.hpp\"\n\n#line 1 \"\
    random/seed.hpp\"\n\n\n\n#include <chrono>\n\nnamespace kk2 {\n\nnamespace random\
    \ {\n\nusing u64 = unsigned long long;\n\ninline u64 non_deterministic_seed()\
    \ {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n  \
    \                 std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count();\n    seed ^= reinterpret_cast<u64>(&seed);\n   \
    \ seed ^= seed << 5;\n    seed ^= seed >> 41;\n    seed ^= seed << 20;\n    return\
    \ seed;\n}\n\ninline u64 deterministic_seed() { return 5801799128519729247ull;\
    \ }\n\ninline u64 seed() {\n#if defined(KK2_RANDOM_DETERMINISTIC)\n    return\
    \ deterministic_seed();\n#else\n    return non_deterministic_seed();\n#endif\n\
    }\n\n} // namespace random\n\n} // namespace kk2\n\n\n#line 12 \"random/gen.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace random {\n\nusing i64 = long long;\nusing u64\
    \ = unsigned long long;\n\ninline u64 rng() {\n    static std::mt19937_64 mt(kk2::random::seed());\n\
    \    return mt();\n}\n\n// [l, r)\ninline i64 rng(i64 l, i64 r) {\n    assert(l\
    \ < r);\n    return l + rng() % (r - l);\n}\n\n// [l, r)\ntemplate <class T> std::vector<T>\
    \ random_vector(int n, T l, T r) {\n    std::vector<T> res(n);\n    for (int i\
    \ = 0; i < n; i++) res[i] = rng(l, r);\n    return res;\n}\n\n// [l, r)\nstd::vector<i64>\
    \ distinct_rng(i64 l, i64 r, i64 n) {\n    assert(l < r and n <= r - l);\n   \
    \ std::unordered_set<i64> st;\n    for (i64 i = n; i; --i) {\n        i64 m =\
    \ rng(l, r + 1 - i);\n        if (st.find(m) != st.end()) m = r - i;\n       \
    \ st.insert(m);\n    }\n    std::vector<i64> res(st.begin(), st.end());\n    std::sort(res.begin(),\
    \ res.end());\n    return res;\n}\n\ntemplate <class Iter> void shuffle(Iter first,\
    \ Iter last) {\n    if (first == last) return;\n    int len = 1;\n    for (auto\
    \ it = first + 1; it != last; ++it) {\n        len++;\n        int j = rng(0,\
    \ len);\n        if (j != len - 1) std::iter_swap(first + j, it);\n    }\n}\n\n\
    template <class T> std::vector<T> perm(int n) {\n    std::vector<T> res(n);\n\
    \    std::iota(res.begin(), res.end(), T(0));\n    shuffle(res.begin(), res.end());\n\
    \    return res;\n}\n\ntemplate <class T> std::vector<T> choices(int l, int r,\
    \ int k) {\n    assert(l < r and k <= r - l);\n    std::vector<T> res(r - l);\n\
    \    std::iota(res.begin(), res.end(), T(l));\n    shuffle(res.begin(), res.end());\n\
    \    res.resize(k);\n    return res;\n}\n\n} // namespace random\n\n} // namespace\
    \ kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#line 5 \"template/template.hpp\"\
    \n#include <array>\n#include <bitset>\n#line 9 \"template/template.hpp\"\n#include\
    \ <cmath>\n#include <deque>\n#include <functional>\n#include <iterator>\n#include\
    \ <limits>\n#include <map>\n#line 16 \"template/template.hpp\"\n#include <optional>\n\
    #include <queue>\n#line 19 \"template/template.hpp\"\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#line 26 \"template/template.hpp\"\n\n#line 1 \"\
    template/constant.hpp\"\n\n\n\n#line 1 \"template/type_alias.hpp\"\n\n\n\n#line\
    \ 8 \"template/type_alias.hpp\"\n\nusing u32 = unsigned int;\nusing i64 = long\
    \ long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\nusing u128\
    \ = __uint128_t;\n\nusing pi = std::pair<int, int>;\nusing pl = std::pair<i64,\
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
    \n\n#line 1 \"template/fastio.hpp\"\n\n\n\n#include <cctype>\n#include <cstdint>\n\
    #include <cstdio>\n#include <fstream>\n#include <iostream>\n#line 10 \"template/fastio.hpp\"\
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
    \n} // namespace kk2\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n\
    #include <ostream>\n#line 7 \"type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace\
    \ type_traits\n\ntemplate <typename T> using is_standard_istream =\n    typename\
    \ std::conditional<std::is_same<T, std::istream>::value\n                    \
    \              || std::is_same<T, std::ifstream>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
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
    \ kk2\n\n\n#line 13 \"template/fastio.hpp\"\n\nnamespace kk2 {\n\nnamespace fastio\
    \ {\n\nstruct Scanner : type_traits::istream_tag {\n  private:\n    static constexpr\
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
    \ { return (a > b ? a = b, 1 : 0); }\n\n\n#line 7 \"verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int a, b;\n    kin >> a >> b;\n  \
    \  kout << a + b << kendl;\n\n    rep (200) {\n        int n = 10000;\n      \
    \  int q = 1000;\n        vc<array<int, 3>> query(q);\n        vc<pi> insert_query;\n\
    \        rep (i, q) {\n            int t = kk2::random::rng(0, 4);\n         \
    \   query[i][0] = t;\n            if (t == 0) {\n                int a = kk2::random::rng(0,\
    \ n - 1);\n                int b = kk2::random::rng(a, n);\n                query[i][1]\
    \ = a;\n                query[i][2] = b;\n                insert_query.emplace_back(a,\
    \ b);\n            } else if (t == 1) {\n                if (insert_query.empty()\
    \ or kk2::random::rng(0, 2)) {\n                    int a = kk2::random::rng(0,\
    \ n - 1);\n                    int b = kk2::random::rng(a, n);\n             \
    \       query[i][1] = a;\n                    query[i][2] = b;\n             \
    \   } else {\n                    int idx = kk2::random::rng(0, (int)insert_query.size());\n\
    \                    query[i][1] = insert_query[idx].first;\n                \
    \    query[i][2] = insert_query[idx].second;\n                }\n            }\
    \ else if (t == 2) {\n                int a = kk2::random::rng(0, n);\n      \
    \          query[i][1] = a;\n            } else if (t == 3) {\n              \
    \  int a = kk2::random::rng(0, n - 1);\n                int b = kk2::random::rng(a,\
    \ n);\n                query[i][1] = a;\n                query[i][2] = b;\n  \
    \          }\n        }\n    \n        vc<int> res(q);\n        kk2::OfflineDynamicConnectivity\
    \ odc(n, q);\n        rep (i, q) {\n            if (query[i][0] == 0) odc.add_edge(i,\
    \ query[i][1], query[i][2]);\n            if (query[i][0] == 1) odc.del_edge(i,\
    \ query[i][1], query[i][2]);\n        }\n        odc.build();\n        odc.run([&](int\
    \ i) {\n            if (query[i][0] == 2) res[i] = odc.uf.size(query[i][1]);\n\
    \            if (query[i][0] == 3) res[i] = odc.uf.same(query[i][1], query[i][2]);\n\
    \        });\n    \n        std::set<pi> edges;\n        vc<int> res2(q);\n  \
    \      rep (i, q) {\n            if (query[i][0] == 0) {\n                edges.emplace(query[i][1],\
    \ query[i][2]);\n            } else if (query[i][0] == 1) {\n                edges.erase(pi(query[i][1],\
    \ query[i][2]));\n            } else if (query[i][0] == 2) {\n               \
    \ kk2::UnionFind uf(n);\n                for (auto [a, b] : edges) {\n       \
    \             uf.unite(a, b);\n                }\n                res2[i] = uf.size(query[i][1]);\n\
    \            } else {\n                kk2::UnionFind uf(n);\n               \
    \ for (auto [a, b] : edges) {\n                    uf.unite(a, b);\n         \
    \       }\n                res2[i] = uf.same(query[i][1], query[i][2]);\n    \
    \        }\n        }\n        assert(res == res2);\n    }\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../../data_structure/offline_dynamic_connectivity.hpp\"\n#include \"../../../unionfind/unionfind.hpp\"\
    \n#include \"../../../random/gen.hpp\"\n#include \"../../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int a, b;\n    kin >> a >> b;\n  \
    \  kout << a + b << kendl;\n\n    rep (200) {\n        int n = 10000;\n      \
    \  int q = 1000;\n        vc<array<int, 3>> query(q);\n        vc<pi> insert_query;\n\
    \        rep (i, q) {\n            int t = kk2::random::rng(0, 4);\n         \
    \   query[i][0] = t;\n            if (t == 0) {\n                int a = kk2::random::rng(0,\
    \ n - 1);\n                int b = kk2::random::rng(a, n);\n                query[i][1]\
    \ = a;\n                query[i][2] = b;\n                insert_query.emplace_back(a,\
    \ b);\n            } else if (t == 1) {\n                if (insert_query.empty()\
    \ or kk2::random::rng(0, 2)) {\n                    int a = kk2::random::rng(0,\
    \ n - 1);\n                    int b = kk2::random::rng(a, n);\n             \
    \       query[i][1] = a;\n                    query[i][2] = b;\n             \
    \   } else {\n                    int idx = kk2::random::rng(0, (int)insert_query.size());\n\
    \                    query[i][1] = insert_query[idx].first;\n                \
    \    query[i][2] = insert_query[idx].second;\n                }\n            }\
    \ else if (t == 2) {\n                int a = kk2::random::rng(0, n);\n      \
    \          query[i][1] = a;\n            } else if (t == 3) {\n              \
    \  int a = kk2::random::rng(0, n - 1);\n                int b = kk2::random::rng(a,\
    \ n);\n                query[i][1] = a;\n                query[i][2] = b;\n  \
    \          }\n        }\n    \n        vc<int> res(q);\n        kk2::OfflineDynamicConnectivity\
    \ odc(n, q);\n        rep (i, q) {\n            if (query[i][0] == 0) odc.add_edge(i,\
    \ query[i][1], query[i][2]);\n            if (query[i][0] == 1) odc.del_edge(i,\
    \ query[i][1], query[i][2]);\n        }\n        odc.build();\n        odc.run([&](int\
    \ i) {\n            if (query[i][0] == 2) res[i] = odc.uf.size(query[i][1]);\n\
    \            if (query[i][0] == 3) res[i] = odc.uf.same(query[i][1], query[i][2]);\n\
    \        });\n    \n        std::set<pi> edges;\n        vc<int> res2(q);\n  \
    \      rep (i, q) {\n            if (query[i][0] == 0) {\n                edges.emplace(query[i][1],\
    \ query[i][2]);\n            } else if (query[i][0] == 1) {\n                edges.erase(pi(query[i][1],\
    \ query[i][2]));\n            } else if (query[i][0] == 2) {\n               \
    \ kk2::UnionFind uf(n);\n                for (auto [a, b] : edges) {\n       \
    \             uf.unite(a, b);\n                }\n                res2[i] = uf.size(query[i][1]);\n\
    \            } else {\n                kk2::UnionFind uf(n);\n               \
    \ for (auto [a, b] : edges) {\n                    uf.unite(a, b);\n         \
    \       }\n                res2[i] = uf.same(query[i][1], query[i][2]);\n    \
    \        }\n        }\n        assert(res == res2);\n    }\n\n    return 0;\n\
    }\n"
  dependsOn:
  - data_structure/offline_dynamic_connectivity.hpp
  - unionfind/rollback.hpp
  - unionfind/unionfind.hpp
  - random/gen.hpp
  - random/seed.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
- /verify/verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp.html
title: verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
---
