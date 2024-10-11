---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/group/sum.hpp
    title: math/group/sum.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/seg.hpp
    title: segment_tree/seg.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/utility/sumseg.hpp
    title: segment_tree/utility/sumseg.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/yosupo_ds/ds_point_add_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line 1 \"\
    segment_tree/utility/sumseg.hpp\"\n\n\n\n#line 1 \"math/group/sum.hpp\"\n\n\n\n\
    #include <iostream>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace group {\n\
    \ntemplate <class S> struct Sum {\n    S a;\n    int size;\n\n    constexpr Sum()\
    \ : a(S()), size(0) {}\n\n    constexpr Sum(S a, S size = 1) : a(a), size(size)\
    \ {}\n\n    operator S() const { return a; }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Sum &sum) {\n        os << sum.a;\n        return os;\n    }\n\n\
    \    friend std::istream &operator>>(std::istream &is, Sum &sum) {\n        is\
    \ >> sum.a;\n        sum.size = 1;\n        return is;\n    }\n\n    constexpr\
    \ Sum &operator=(const S &rhs) {\n        a = rhs;\n        size = 1;\n      \
    \  return *this;\n    }\n\n    constexpr Sum &add(const S &rhs) {\n        a +=\
    \ rhs * size;\n        return *this;\n    }\n\n    constexpr Sum &update(const\
    \ S &rhs) {\n        a = rhs * size;\n        return *this;\n    }\n\n    constexpr\
    \ Sum &multiply(const S &rhs) {\n        a *= rhs;\n        return *this;\n  \
    \  }\n};\n\ntemplate <class S> constexpr Sum<S> SumOp(Sum<S> l, Sum<S> r) {\n\
    \    l.a += r.a;\n    l.size += r.size;\n    return l;\n}\n\ntemplate <class S>\
    \ Sum<S> SumUnit() {\n    constexpr static Sum<S> e = Sum<S>();\n    return e;\n\
    }\n\ntemplate <class S> constexpr Sum<S> SumInv(Sum<S> x) {\n    x.a = -x.a;\n\
    \    x.size = -x.size;\n    return x;\n}\n\n} // namespace group\n\ntemplate <class\
    \ S, class... Args>\nstd::vector<group::Sum<S>> GetVecSum(int n, Args... args)\
    \ {\n    return std::vector<group::Sum<S>>(n, group::Sum<S>(args...));\n}\n\n\
    template <class S, class... Args>\nstd::vector<std::vector<group::Sum<S>>> GetVecSum2D(int\
    \ h, int w, Args... args) {\n    return std::vector<std::vector<group::Sum<S>>>(h,\
    \ GetVecSum<S>(w, args...));\n}\n\n} // namespace kk2\n\n\n#line 1 \"segment_tree/seg.hpp\"\
    \n\n\n\n#include <cassert>\n#include <functional>\n#line 7 \"segment_tree/seg.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct SegTree\
    \ {\n  public:\n    SegTree() : SegTree(0) {}\n\n    SegTree(int n) : SegTree(std::vector<S>(n,\
    \ e())) {}\n\n    template <class... Args>\n    SegTree(int n, Args... args) :\
    \ SegTree(std::vector<S>(n, S(args...))){};\n\n    SegTree(const std::vector<S>\
    \ &v) : _n(int(v.size())) {\n        log = 0;\n        while ((1U << log) < (unsigned\
    \ int)(_n)) log++;\n        size = 1 << log;\n        d = std::vector<S>(2 * size,\
    \ e());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for\
    \ (int i = size - 1; i >= 1; i--) { update(i); }\n    }\n\n    using Monoid =\
    \ S;\n\n    static S Op(S l, S r) { return op(l, r); }\n\n    static S MonoidUnit()\
    \ { return e(); }\n\n    void set(int p, S x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n    }\n\n    template <class... Args> void emplace_set(int\
    \ p, Args... args) { set(p, S(args...)); }\n\n    S get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        return d[p + size];\n    }\n\n    S prod(int l, int\
    \ r) {\n        assert(0 <= l && l <= r && r <= _n);\n        S sml = e(), smr\
    \ = e();\n        l += size;\n        r += size;\n\n        while (l < r) {\n\
    \            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ op(sml, smr);\n    }\n\n    S all_prod() { return d[1]; }\n\n    // return r\
    \ s.t.\n    // r = l or f(op(a[l], a[l+1], ..., a[r-1])) == true\n    // r = n\
    \ or f(op(a[l], a[l+1], ..., a[r]))   == false\n    template <bool (*f)(S)> int\
    \ max_right(int l) {\n        return max_right(l, [](S x) { return f(x); });\n\
    \    }\n\n    template <class F> int max_right(int l, F f) {\n        assert(0\
    \ <= l && l <= _n);\n        assert(f(e()));\n        if (l == _n) return _n;\n\
    \        l += size;\n        S sm = e();\n        do {\n            while (l %\
    \ 2 == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n                while\
    \ (l < size) {\n                    l = (2 * l);\n                    if (f(op(sm,\
    \ d[l]))) {\n                        sm = op(sm, d[l]);\n                    \
    \    l++;\n                    }\n                }\n                return l\
    \ - size;\n            }\n            sm = op(sm, d[l]);\n            l++;\n \
    \       } while ((l & -l) != l);\n        return _n;\n    }\n\n    // return l\
    \ s.t.\n    // l = r or f(op(a[l], a[l], ..., a[r-1]))   == true\n    // l = 0\
    \ or f(op(a[l-1], a[l], ..., a[r-1])) == false\n    template <bool (*f)(S)> int\
    \ min_left(int r) {\n        return min_left(r, [](S x) { return f(x); });\n \
    \   }\n\n    template <class F> int min_left(int r, F f) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(f(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        S sm = e();\n        do {\n            r--;\n      \
    \      while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n\
    \                while (r < size) {\n                    r = (2 * r + 1);\n  \
    \                  if (f(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n\
    \    int _n, size, log;\n    std::vector<S> d;\n\n    void update(int k) { d[k]\
    \ = op(d[2 * k], d[2 * k + 1]); }\n};\n\n} // namespace kk2\n\n\n#line 6 \"segment_tree/utility/sumseg.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S> using SumSeg = SegTree<group::Sum<S>,\
    \ group::SumOp<S>, group::SumUnit<S>>;\n\n} // namespace kk2\n\n\n#line 1 \"template/template.hpp\"\
    \n\n\n\n#pragma GCC optimize(\"O3,unroll-loops\")\n\n// #include <bits/stdc++.h>\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#line 11 \"template/template.hpp\"\
    \n#include <chrono>\n#include <cmath>\n#include <cstring>\n#include <deque>\n\
    #include <fstream>\n#line 17 \"template/template.hpp\"\n#include <iomanip>\n#line\
    \ 19 \"template/template.hpp\"\n#include <iterator>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <optional>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#line 36 \"template/template.hpp\"\n\nusing u32 = unsigned\
    \ int;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\nusing u128 = __uint128_t;\n\nusing pi = std::pair<int, int>;\n\
    using pl = std::pair<i64, i64>;\nusing pil = std::pair<int, i64>;\nusing pli =\
    \ std::pair<i64, int>;\n\ntemplate <class T> using vc = std::vector<T>;\ntemplate\
    \ <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using vvvc = std::vector<vvc<T>>;\n\
    template <class T> using vvvvc = std::vector<vvvc<T>>;\n\ntemplate <class T> using\
    \ pq = std::priority_queue<T>;\ntemplate <class T> using pqi = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\ntemplate <class T> constexpr T infty =\
    \ 0;\ntemplate <> constexpr int infty<int> = (1 << 30) - 123;\ntemplate <> constexpr\
    \ i64 infty<i64> = (1ll << 62) - (1ll << 31);\ntemplate <> constexpr i128 infty<i128>\
    \ = (i128(1) << 126) - (i128(1) << 63);\ntemplate <> constexpr u32 infty<u32>\
    \ = infty<int>;\ntemplate <> constexpr u64 infty<u64> = infty<i64>;\ntemplate\
    \ <> constexpr u128 infty<u128> = infty<i128>;\ntemplate <> constexpr double infty<double>\
    \ = infty<i64>;\ntemplate <> constexpr long double infty<long double> = infty<i64>;\n\
    \nconstexpr int mod = 998244353;\nconstexpr int modu = 1e9 + 7;\nconstexpr long\
    \ double PI = 3.14159265358979323846;\n\nnamespace kk2 {\n\ntemplate <class T,\
    \ class... Sizes> auto make_vector(int first, Sizes... sizes) {\n    if constexpr\
    \ (sizeof...(sizes) == 0) {\n        return std::vector<T>(first);\n    } else\
    \ {\n        return std::vector<decltype(make_vector(sizes...))>(first, make_vector(sizes...));\n\
    \    }\n}\n\ntemplate <class T, class U> void fill_all(std::vector<T> &v, const\
    \ U &x) {\n    std::fill(std::begin(v), std::end(v), T(x));\n}\n\ntemplate <class\
    \ T, class U> void fill_all(std::vector<std::vector<T>> &v, const U &x) {\n  \
    \  for (auto &u : v) fill_all(u, x);\n}\n\n} // namespace kk2\n\ntemplate <class\
    \ T, class S> inline bool chmax(T &a, const S &b) {\n    return (a < b ? a = b,\
    \ 1 : 0);\n}\n\ntemplate <class T, class S> inline bool chmin(T &a, const S &b)\
    \ {\n    return (a > b ? a = b, 1 : 0);\n}\n\nvoid Yes(bool b = 1) {\n    std::cout\
    \ << (b ? \"Yes\\n\" : \"No\\n\");\n}\n\nvoid No(bool b = 1) {\n    std::cout\
    \ << (b ? \"No\\n\" : \"Yes\\n\");\n}\n\nvoid YES(bool b = 1) {\n    std::cout\
    \ << (b ? \"YES\\n\" : \"NO\\n\");\n}\n\nvoid NO(bool b = 1) {\n    std::cout\
    \ << (b ? \"NO\\n\" : \"YES\\n\");\n}\n\nvoid yes(bool b = 1) {\n    std::cout\
    \ << (b ? \"yes\\n\" : \"no\\n\");\n}\n\nvoid no(bool b = 1) {\n    std::cout\
    \ << (b ? \"no\\n\" : \"yes\\n\");\n}\n\n#define rep1(a) for (i64 _ = 0; _ < (i64)(a);\
    \ ++_)\n#define rep2(i, a) for (i64 i = 0; i < (i64)(a); ++i)\n#define rep3(i,\
    \ a, b) for (i64 i = (a); i < (i64)(b); ++i)\n#define repi2(i, a) for (i64 i =\
    \ (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (i64 i = (a) - 1; i >= (i64)(b);\
    \ --i)\n#define overload3(a, b, c, d, ...) d\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\n#define repi(...) overload3(__VA_ARGS__, repi3,\
    \ repi2, rep1)(__VA_ARGS__)\n\n#define fi first\n#define se second\n#define all(p)\
    \ std::begin(p), std::end(p)\n\nstruct IoSetUp {\n    IoSetUp() {\n        std::cin.tie(nullptr);\n\
    \        std::ios::sync_with_stdio(false);\n    }\n} iosetup;\n\ntemplate <class\
    \ OStream, class T, class U>\nOStream &operator<<(OStream &os, const std::pair<T,\
    \ U> &p) {\n    os << p.first << ' ' << p.second;\n    return os;\n}\n\ntemplate\
    \ <class IStream, class T, class U> IStream &operator>>(IStream &is, std::pair<T,\
    \ U> &p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class\
    \ OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &v)\
    \ {\n    for (int i = 0; i < (int)v.size(); i++) { os << v[i] << (i + 1 == (int)v.size()\
    \ ? \"\" : \" \"); }\n    return os;\n}\n\ntemplate <class IStream, class T> IStream\
    \ &operator>>(IStream &is, std::vector<T> &v) {\n    for (auto &x : v) is >> x;\n\
    \    return is;\n}\n\n\n#line 5 \"verify/yosupo_ds/ds_point_add_range_sum.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n  \
    \  auto a = kk2::GetVecSum<i64>(n);\n    cin >> a;\n    kk2::SumSeg<i64> seg(a);\n\
    \n    rep (q) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n  \
    \          int p, x;\n            cin >> p >> x;\n            seg.emplace_set(p,\
    \ seg.get(p).a + x);\n        }\n        if (t == 1) {\n            int l, r;\n\
    \            cin >> l >> r;\n            cout << seg.prod(l, r).a << \"\\n\";\n\
    \        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../segment_tree/utility/sumseg.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n  \
    \  auto a = kk2::GetVecSum<i64>(n);\n    cin >> a;\n    kk2::SumSeg<i64> seg(a);\n\
    \n    rep (q) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n  \
    \          int p, x;\n            cin >> p >> x;\n            seg.emplace_set(p,\
    \ seg.get(p).a + x);\n        }\n        if (t == 1) {\n            int l, r;\n\
    \            cin >> l >> r;\n            cout << seg.prod(l, r).a << \"\\n\";\n\
    \        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - segment_tree/utility/sumseg.hpp
  - math/group/sum.hpp
  - segment_tree/seg.hpp
  - template/template.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-10-11 23:06:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_point_add_range_sum.test.cpp
- /verify/verify/yosupo_ds/ds_point_add_range_sum.test.cpp.html
title: verify/yosupo_ds/ds_point_add_range_sum.test.cpp
---
