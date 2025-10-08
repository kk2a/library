---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"verify/yosupo_string/string_number_of_substrings.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\" \n\n\
    #line 1 \"string/suffix_array.hpp\"\n\n\n\n#include <algorithm>\n#include <functional>\n\
    #include <numeric>\n#include <string>\n#include <vector>\n\nnamespace kk2 {\n\n\
    struct SuffixArray {\n    SuffixArray() = default;\n\n    SuffixArray(const std::string\
    \ &s_) : _n(s_.size()), _s((int)s_.size()) {\n        for (int i = 0; i < _n;\
    \ ++i) _s[i] = s_[i];\n        _upper = 255;\n        init();\n    }\n\n    //\
    \ all elements of s_ must be in [0, upper]\n    SuffixArray(const std::vector<int>\
    \ &s_, int upper_)\n        : _n((int)s_.size()),\n          _upper(upper_),\n\
    \          _s(s_) {\n        init();\n    }\n\n    template <class T> SuffixArray(const\
    \ std::vector<T> &s_)\n        : _n((int)s_.size()),\n          _s((int)s_.size())\
    \ {\n        std::vector<int> idx(_n);\n        std::iota(std::begin(idx), std::end(idx),\
    \ 0);\n        std::sort(std::begin(idx), std::end(idx), [&](int l, int r) { return\
    \ s_[l] < s_[r]; });\n        _upper = 0;\n        for (int i = 0; i < _n; ++i)\
    \ {\n            if (i && s_[idx[i - 1]] != s_[idx[i]]) _upper++;\n          \
    \  _s[idx[i]] = _upper;\n        }\n        init();\n    }\n\n    const std::vector<int>\
    \ &get_sa() const { return _sa; }\n\n    const std::vector<int> &get_s() const\
    \ { return _s; }\n\n    int operator[](int i) const { return _sa[i]; }\n\n   \
    \ int size() const { return _n; }\n\n    int upper() const { return _upper; }\n\
    \n    bool op(int i, const std::string &t) const {\n        int off = _sa[i];\n\
    \        int m = std::min(_n - off, (int)t.size());\n        for (int j = 0; j\
    \ < m; ++j) {\n            if (_s[off + j] != t[j]) return _s[off + j] < t[j];\n\
    \        }\n        return _n - off < (int)t.size();\n    }\n\n    bool op(int\
    \ i, const std::vector<int> &t) const {\n        int off = _sa[i];\n        int\
    \ m = std::min(_n - off, (int)t.size());\n        for (int j = 0; j < m; ++j)\
    \ {\n            if (_s[off + j] != t[j]) return _s[off + j] < t[j];\n       \
    \ }\n        return _n - off < (int)t.size();\n    }\n\n    // return the smallest\
    \ index i s.t. s[sa[i]:] >= t\n    int lower_bound(const std::vector<int> &t)\
    \ const {\n        int l = -1, r = _n;\n        while (r - l > 1) {\n        \
    \    int m = (l + r) / 2;\n            if (op(m, t)) l = m;\n            else\
    \ r = m;\n        }\n        return r;\n    }\n\n    int lower_bound(const std::string\
    \ &t) const {\n        int l = -1, r = _n;\n        while (r - l > 1) {\n    \
    \        int m = (l + r) / 2;\n            if (op(m, t)) l = m;\n            else\
    \ r = m;\n        }\n        return r;\n    }\n\n  private:\n    int _n, _upper;\n\
    \    std::vector<int> _sa, _s;\n\n    std::vector<int> sa_naive(const std::vector<int>\
    \ &s) {\n        int n = (int)s.size();\n        std::vector<int> sa(n);\n   \
    \     std::iota(std::begin(sa), std::end(sa), 0);\n        std::sort(std::begin(sa),\
    \ std::end(sa), [&](int l, int r) {\n            if (l == r) return false;\n \
    \           while (l < n && r < n) {\n                if (s[l] != s[r]) return\
    \ s[l] < s[r];\n                l++;\n                r++;\n            }\n  \
    \          return l == n;\n        });\n        return sa;\n    }\n\n    std::vector<int>\
    \ sa_doubling(const std::vector<int> &s) {\n        int n = (int)s.size();\n \
    \       std::vector<int> sa(n), cpy = s, tmp(n);\n        std::iota(std::begin(sa),\
    \ std::end(sa), 0);\n        for (int len = 1; len < n; len <<= 1) {\n       \
    \     auto Compare = [&](int x, int y) {\n                if (cpy[x] != cpy[y])\
    \ return cpy[x] < cpy[y];\n                int rx = x + len < n ? cpy[x + len]\
    \ : -1;\n                int ry = y + len < n ? cpy[y + len] : -1;\n         \
    \       return rx < ry;\n            };\n            std::sort(std::begin(sa),\
    \ std::end(sa), Compare);\n            tmp[sa[0]] = 0;\n            for (int i\
    \ = 1; i < n; i++) {\n                tmp[sa[i]] = tmp[sa[i - 1]] + (Compare(sa[i\
    \ - 1], sa[i]) ? 1 : 0);\n            }\n            std::swap(cpy, tmp);\n  \
    \      }\n        return sa;\n    }\n\n    template <int THRESHOLD_NAIVE = 10,\
    \ int THRESHOLD_DOUBLING = 40>\n    std::vector<int> sa_is(const std::vector<int>\
    \ &s, int upper) {\n        int n = (int)s.size();\n        if (n == 0) return\
    \ {};\n        if (n == 1) return {0};\n        if (n == 2) {\n            if\
    \ (s[0] < s[1]) return {0, 1};\n            else return {1, 0};\n        }\n \
    \       if (n < THRESHOLD_NAIVE) return sa_naive(s);\n        if (n < THRESHOLD_DOUBLING)\
    \ return sa_doubling(s);\n\n        std::vector<int> sa(n);\n        std::vector<bool>\
    \ ls(n);\n        for (int i = n - 2; i >= 0; i--) {\n            ls[i] = (s[i]\
    \ == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);\n        }\n        std::vector<int>\
    \ sum_l(upper + 1), sum_s(upper + 1);\n        for (int i = 0; i < n; i++) {\n\
    \            if (!ls[i]) sum_s[s[i]]++;\n            else sum_l[s[i] + 1]++;\n\
    \        }\n        for (int i = 0; i <= upper; i++) {\n            sum_s[i] +=\
    \ sum_l[i];\n            if (i < upper) sum_l[i + 1] += sum_s[i];\n        }\n\
    \n        auto induce = [&](const std::vector<int> &lms) {\n            std::fill(std::begin(sa),\
    \ std::end(sa), -1);\n            std::vector<int> buf(upper + 1);\n         \
    \   std::copy(std::begin(sum_s), std::end(sum_s), std::begin(buf));\n        \
    \    for (auto d : lms) {\n                if (d == n) continue;\n           \
    \     sa[buf[s[d]]++] = d;\n            }\n            std::copy(std::begin(sum_l),\
    \ std::end(sum_l), std::begin(buf));\n            sa[buf[s[n - 1]]++] = n - 1;\n\
    \            for (int i = 0; i < n; i++) {\n                int v = sa[i];\n \
    \               if (v >= 1 && !ls[v - 1]) { sa[buf[s[v - 1]]++] = v - 1; }\n \
    \           }\n            std::copy(std::begin(sum_l), std::end(sum_l), std::begin(buf));\n\
    \            for (int i = n - 1; i >= 0; i--) {\n                int v = sa[i];\n\
    \                if (v >= 1 && ls[v - 1]) { sa[--buf[s[v - 1] + 1]] = v - 1; }\n\
    \            }\n        };\n\n        std::vector<int> lms_map(n + 1, -1);\n \
    \       int m = 0;\n        for (int i = 1; i < n; i++) {\n            if (!ls[i\
    \ - 1] && ls[i]) lms_map[i] = m++;\n        }\n        std::vector<int> lms;\n\
    \        lms.reserve(m);\n        for (int i = 1; i < n; i++) {\n            if\
    \ (!ls[i - 1] && ls[i]) { lms.push_back(i); }\n        }\n\n        induce(lms);\n\
    \n        if (m) {\n            std::vector<int> sorted_lms;\n            sorted_lms.reserve(m);\n\
    \            for (int v : sa) {\n                if (lms_map[v] != -1) sorted_lms.push_back(v);\n\
    \            }\n            std::vector<int> rec_s(m);\n            int rec_upper\
    \ = 0;\n            rec_s[lms_map[sorted_lms[0]]] = 0;\n            for (int i\
    \ = 1; i < m; i++) {\n                int l = sorted_lms[i - 1], r = sorted_lms[i];\n\
    \                int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;\n\
    \                int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;\n\
    \                bool same = true;\n                if (end_l - l != end_r - r)\
    \ {\n                    same = false;\n                } else {\n           \
    \         while (l < end_l) {\n                        if (s[l] != s[r]) break;\n\
    \                        l++;\n                        r++;\n                \
    \    }\n                    if (l == n || s[l] != s[r]) same = false;\n      \
    \          }\n                if (!same) rec_upper++;\n                rec_s[lms_map[sorted_lms[i]]]\
    \ = rec_upper;\n            }\n\n            std::vector<int> rec_sa = sa_is<THRESHOLD_NAIVE,\
    \ THRESHOLD_DOUBLING>(rec_s, rec_upper);\n\n            for (int i = 0; i < m;\
    \ i++) { sorted_lms[i] = lms[rec_sa[i]]; }\n            induce(sorted_lms);\n\
    \        }\n        return sa;\n    }\n\n    void init() { _sa = sa_is(_s, _upper);\
    \ }\n};\n\nstruct LCPArray {\n    const SuffixArray &sa;\n    std::vector<int>\
    \ lcp, rank;\n\n    // lcp[i] = lcp(s[sa[i]:], s[sa[i + 1]:])\n\n    LCPArray(const\
    \ SuffixArray &sa_) : sa(sa_) {\n        lcp.resize(sa.size());\n        rank.resize(sa.size());\n\
    \        for (int i = 0; i < sa.size(); ++i) rank[sa[i]] = i;\n        const std::vector<int>\
    \ &s = sa.get_s();\n        lcp[sa.size() - 1] = 0;\n        for (int i = 0, l\
    \ = 0; i < sa.size(); ++i) {\n            if (l > 0) l--;\n            if (rank[i]\
    \ == sa.size() - 1) continue;\n            int j = sa[rank[i] + 1];\n        \
    \    for (; i + l < sa.size() && j + l < sa.size(); ++l) {\n                if\
    \ (s[i + l] != s[j + l]) break;\n            }\n            lcp[rank[i]] = l;\n\
    \        }\n    }\n};\n\n} // namespace kk2\n\n\n#line 1 \"template/template.hpp\"\
    \n\n\n\n#line 5 \"template/template.hpp\"\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <chrono>\n#include <cmath>\n#include <deque>\n#line\
    \ 12 \"template/template.hpp\"\n#include <iterator>\n#include <limits>\n#include\
    \ <map>\n#line 16 \"template/template.hpp\"\n#include <optional>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <stack>\n#line 22 \"template/template.hpp\"\
    \n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#line\
    \ 26 \"template/template.hpp\"\n\n#line 1 \"template/constant.hpp\"\n\n\n\n#line\
    \ 1 \"template/type_alias.hpp\"\n\n\n\n#line 8 \"template/type_alias.hpp\"\n\n\
    using u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned long long;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi = std::pair<int,\
    \ int>;\nusing pl = std::pair<i64, i64>;\nusing pil = std::pair<int, i64>;\nusing\
    \ pli = std::pair<i64, int>;\n\ntemplate <class T> using vc = std::vector<T>;\n\
    template <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using vvvc\
    \ = std::vector<vvc<T>>;\ntemplate <class T> using vvvvc = std::vector<vvvc<T>>;\n\
    \ntemplate <class T> using pq = std::priority_queue<T>;\ntemplate <class T> using\
    \ pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\n\n#line 5\
    \ \"template/constant.hpp\"\n\ntemplate <class T> constexpr T infty = 0;\ntemplate\
    \ <> constexpr int infty<int> = (1 << 30) - 123;\ntemplate <> constexpr i64 infty<i64>\
    \ = (1ll << 62) - (1ll << 31);\ntemplate <> constexpr i128 infty<i128> = (i128(1)\
    \ << 126) - (i128(1) << 63);\ntemplate <> constexpr u32 infty<u32> = infty<int>;\n\
    template <> constexpr u64 infty<u64> = infty<i64>;\ntemplate <> constexpr u128\
    \ infty<u128> = infty<i128>;\ntemplate <> constexpr double infty<double> = infty<i64>;\n\
    template <> constexpr long double infty<long double> = infty<i64>;\n\nconstexpr\
    \ int mod = 998244353;\nconstexpr int modu = 1e9 + 7;\nconstexpr long double PI\
    \ = 3.14159265358979323846;\n\n\n#line 1 \"template/fastio.hpp\"\n\n\n\n#include\
    \ <cctype>\n#include <cstdint>\n#include <cstdio>\n#include <fstream>\n#include\
    \ <iostream>\n#line 10 \"template/fastio.hpp\"\n\n#line 1 \"type_traits/integral.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate\
    \ <typename T> using is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value\n                                  or std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T> using is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value\n         \
    \                         or std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_integral =\n    typename std::conditional<std::is_integral<T>::value\
    \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T> using is_signed =\n    typename\
    \ std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n \
    \                             std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
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
    \ { return (a > b ? a = b, 1 : 0); }\n\n\n#line 5 \"verify/yosupo_string/string_number_of_substrings.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    string s;\n    kin >> s;\n    kk2::SuffixArray\
    \ sa(s);\n    kk2::LCPArray lcp(sa);\n    kout << s.size() * (s.size() + 1) /\
    \ 2 - accumulate(all(lcp.lcp), 0ll) << kendl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\
    \ \n\n#include \"../../string/suffix_array.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    string s;\n    kin >> s;\n    kk2::SuffixArray\
    \ sa(s);\n    kk2::LCPArray lcp(sa);\n    kout << s.size() * (s.size() + 1) /\
    \ 2 - accumulate(all(lcp.lcp), 0ll) << kendl;\n\n    return 0;\n}\n"
  dependsOn:
  - string/suffix_array.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_string/string_number_of_substrings.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_string/string_number_of_substrings.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_string/string_number_of_substrings.test.cpp
- /verify/verify/yosupo_string/string_number_of_substrings.test.cpp.html
title: verify/yosupo_string/string_number_of_substrings.test.cpp
---
