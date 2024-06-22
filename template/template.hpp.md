---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_exp.test.cpp
    title: verify/yosupo_fps/fps_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_inv.test.cpp
    title: verify/yosupo_fps/fps_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_log.test.cpp
    title: verify/yosupo_fps/fps_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_pow.test.cpp
    title: verify/yosupo_fps/fps_pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/template.hpp\"\n\n\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing u32 = unsigned int;\nusing i64 = long long;\nusing\
    \ u64 = unsigned long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    \nusing pi = pair<int, int>;\nusing pl = pair<i64, i64>;\nusing pil = pair<int,\
    \ i64>;\nusing pli = pair<i64, int>;\n\ntemplate <class T>\nconstexpr T infty\
    \ = 0;\ntemplate <>\nconstexpr int infty<int> = (1 << 30) - 123;\ntemplate <>\n\
    constexpr i64 infty<i64> = (1ll << 62) - (1ll << 31);\ntemplate <>\nconstexpr\
    \ i128 infty<i128> = i128(infty<i64>) * infty<i64>;\ntemplate <>\nconstexpr u32\
    \ infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<i64>;\n\
    template <>\nconstexpr double infty<double> = infty<i64>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<i64>;\nconstexpr int mod = 998244353;\n\
    constexpr int modu = 1e9 + 7;\nconstexpr long double PI = 3.14159265358979323846;\n\
    \ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\n\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqi = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S\
    \ &b) {\n    return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\n\
    inline bool chmin(T &a, const S &b) {\n    return (a > b ? a = b, 1 : 0);\n}\n\
    \n# define rep1(a) for (i64 _ = 0; _ < i64(a); _++)\n# define rep2(i, a) for (i64\
    \ i = 0; i < i64(a); i++)\n# define rep3(i, a, b) for (i64 i = (a); i < i64(b);\
    \ i++)\n# define repi2(i, a) for (i64 i = (a) - 1; i >= 0; i--)\n# define repi3(i,\
    \ a, b) for (i64 i = (a) - 1; i >= (b); i--)\n# define overload3(a, b, c, d, ...)\
    \ d\n# define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n\
    # define repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n\
    # define pb push_back\n# define eb emplace_back\n# define fi first\n# define se\
    \ second\n# define all(p) begin(p), end(p)\n\nvoid YES(bool b = 1) { cout << (b\
    \ ? \"YES\" : \"NO\") << '\\n'; }\nvoid NO(bool b = 1) { cout << (b ? \"NO\" :\
    \ \"YES\") << '\\n'; }\nvoid YESflush(bool b = 1) { cout << (b ? \"YES\" : \"\
    NO\") << endl; }\nvoid NOflush(bool b = 1) { cout << (b ? \"NO\" : \"YES\") <<\
    \ endl; }\nvoid Yes(bool b = 1) { cout << (b ? \"Yes\" : \"No\") << '\\n'; }\n\
    void No(bool b = 1) { cout << (b ? \"No\" : \"Yes\") << '\\n'; }\nvoid Yesflush(bool\
    \ b = 1) { cout << (b ? \"Yes\" : \"No\") << endl; }\nvoid Noflush(bool b = 1)\
    \ { cout << (b ? \"No\" : \"Yes\") << endl; }\nvoid yes(bool b = 1) { cout <<\
    \ (b ? \"yes\" : \"no\") << '\\n'; }\nvoid no(bool b = 1) { cout << (b ? \"no\"\
    \ : \"yes\") << '\\n'; }\nvoid yesflush(bool b = 1) { cout << (b ? \"yes\" : \"\
    no\") << endl; }\nvoid noflush(bool b = 1) { cout << (b ? \"no\" : \"yes\") <<\
    \ endl; }\n\n\n"
  code: "#ifndef TEMPLATE\n#define TEMPLATE 1\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned\
    \ long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\nusing\
    \ pi = pair<int, int>;\nusing pl = pair<i64, i64>;\nusing pil = pair<int, i64>;\n\
    using pli = pair<i64, int>;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate\
    \ <>\nconstexpr int infty<int> = (1 << 30) - 123;\ntemplate <>\nconstexpr i64\
    \ infty<i64> = (1ll << 62) - (1ll << 31);\ntemplate <>\nconstexpr i128 infty<i128>\
    \ = i128(infty<i64>) * infty<i64>;\ntemplate <>\nconstexpr u32 infty<u32> = infty<int>;\n\
    template <>\nconstexpr u64 infty<u64> = infty<i64>;\ntemplate <>\nconstexpr double\
    \ infty<double> = infty<i64>;\ntemplate <>\nconstexpr long double infty<long double>\
    \ = infty<i64>;\nconstexpr int mod = 998244353;\nconstexpr int modu = 1e9 + 7;\n\
    constexpr long double PI = 3.14159265358979323846;\n\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\n\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqi = priority_queue<T, vector<T>, greater<T>>;\n\n\
    template <class T, class S>\ninline bool chmax(T &a, const S &b) {\n    return\
    \ (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T\
    \ &a, const S &b) {\n    return (a > b ? a = b, 1 : 0);\n}\n\n# define rep1(a)\
    \ for (i64 _ = 0; _ < i64(a); _++)\n# define rep2(i, a) for (i64 i = 0; i < i64(a);\
    \ i++)\n# define rep3(i, a, b) for (i64 i = (a); i < i64(b); i++)\n# define repi2(i,\
    \ a) for (i64 i = (a) - 1; i >= 0; i--)\n# define repi3(i, a, b) for (i64 i =\
    \ (a) - 1; i >= (b); i--)\n# define overload3(a, b, c, d, ...) d\n# define rep(...)\
    \ overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n# define repi(...) overload3(__VA_ARGS__,\
    \ repi3, repi2, rep1)(__VA_ARGS__)\n\n# define pb push_back\n# define eb emplace_back\n\
    # define fi first\n# define se second\n# define all(p) begin(p), end(p)\n\nvoid\
    \ YES(bool b = 1) { cout << (b ? \"YES\" : \"NO\") << '\\n'; }\nvoid NO(bool b\
    \ = 1) { cout << (b ? \"NO\" : \"YES\") << '\\n'; }\nvoid YESflush(bool b = 1)\
    \ { cout << (b ? \"YES\" : \"NO\") << endl; }\nvoid NOflush(bool b = 1) { cout\
    \ << (b ? \"NO\" : \"YES\") << endl; }\nvoid Yes(bool b = 1) { cout << (b ? \"\
    Yes\" : \"No\") << '\\n'; }\nvoid No(bool b = 1) { cout << (b ? \"No\" : \"Yes\"\
    ) << '\\n'; }\nvoid Yesflush(bool b = 1) { cout << (b ? \"Yes\" : \"No\") << endl;\
    \ }\nvoid Noflush(bool b = 1) { cout << (b ? \"No\" : \"Yes\") << endl; }\nvoid\
    \ yes(bool b = 1) { cout << (b ? \"yes\" : \"no\") << '\\n'; }\nvoid no(bool b\
    \ = 1) { cout << (b ? \"no\" : \"yes\") << '\\n'; }\nvoid yesflush(bool b = 1)\
    \ { cout << (b ? \"yes\" : \"no\") << endl; }\nvoid noflush(bool b = 1) { cout\
    \ << (b ? \"no\" : \"yes\") << endl; }\n\n#endif // TEMPLATE\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy: []
  timestamp: '2024-06-13 16:57:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
  - verify/yosupo_fps/fps_exp.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
