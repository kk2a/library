---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/group/sum.hpp
    title: math/group/sum.hpp
  - icon: ':x:'
    path: math/homomorphism/affine.hpp
    title: math/homomorphism/affine.hpp
  - icon: ':question:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':x:'
    path: segment_tree/lazy.hpp
    title: segment_tree/lazy.hpp
  - icon: ':x:'
    path: segment_tree/utility/affinesum.hpp
    title: segment_tree/utility/affinesum.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/yosupo_ds/ds_range_affine_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n\
    #line 1 \"modint/mont.hpp\"\n\n\n\n#include <cassert>\n#include <cstdint>\n#include\
    \ <iostream>\n#include <type_traits>\n\n#line 1 \"type_traits/type_traits.hpp\"\
    \n\n\n\n#line 5 \"type_traits/type_traits.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <typename T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T,\
    \ __int128_t>::value\n                                                       or\
    \ std::is_same<T, __int128>::value,\n                                        \
    \           std::true_type,\n                                                \
    \   std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __uint128_t>::value\n     \
    \                             or std::is_same<T, unsigned __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_integral_extended\
    \ =\n    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
    \                                  or is_unsigned_int128<T>::value,\n        \
    \                      std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T>\nusing is_signed_extended =\n    typename std::conditional<std::is_signed<T>::value\
    \ or is_signed_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\n\
    using is_unsigned_extended =\n    typename std::conditional<std::is_unsigned<T>::value\
    \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\n} // namespace kk2\n\
    \n\n#line 10 \"modint/mont.hpp\"\n\nnamespace kk2 {\n\ntemplate <int p> struct\
    \ LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n    using i32\
    \ = int32_t;\n    using i64 = int64_t;\n    using u32 = uint32_t;\n    using u64\
    \ = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32 ret = p;\n  \
    \      for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;\n        return ret;\n\
    \    }\n\n    static constexpr u32 r = get_r();\n    static constexpr u32 n2 =\
    \ -u64(p) % p;\n    static_assert(r * p == 1, \"invalid, r * p != 1\");\n    static_assert(p\
    \ < (1 << 30), \"invalid, p >= 2 ^ 30\");\n    static_assert((p & 1) == 1, \"\
    invalid, p % 2 == 0\");\n\n    u32 _v;\n\n    operator int() const { return val();\
    \ }\n\n    constexpr LazyMontgomeryModInt() : _v(0) {}\n\n    template <typename\
    \ T, std::enable_if_t<kk2::is_integral_extended<T>::value> * = nullptr>\n    constexpr\
    \ LazyMontgomeryModInt(T b) : _v(reduce(u64(b % p + p) * n2)) {}\n\n    static\
    \ constexpr u32 reduce(const u64 &b) { return (b + u64(u32(b) * u32(-r)) * p)\
    \ >> 32; }\n\n    constexpr mint &operator++() { return *this += 1; }\n\n    constexpr\
    \ mint &operator--() { return *this -= 1; }\n\n    constexpr mint operator++(int)\
    \ {\n        mint ret = *this;\n        *this += 1;\n        return ret;\n   \
    \ }\n\n    constexpr mint operator--(int) {\n        mint ret = *this;\n     \
    \   *this -= 1;\n        return ret;\n    }\n\n    constexpr mint &operator+=(const\
    \ mint &b) {\n        if (i32(_v += b._v - 2 * p) < 0) _v += 2 * p;\n        return\
    \ *this;\n    }\n\n    constexpr mint &operator-=(const mint &b) {\n        if\
    \ (i32(_v -= b._v) < 0) _v += 2 * p;\n        return *this;\n    }\n\n    constexpr\
    \ mint &operator*=(const mint &b) {\n        _v = reduce(u64(_v) * b._v);\n  \
    \      return *this;\n    }\n\n    constexpr mint &operator/=(const mint &b) {\n\
    \        *this *= b.inv();\n        return *this;\n    }\n\n    constexpr mint\
    \ operator-() const { return mint() - mint(*this); }\n\n    constexpr bool operator==(const\
    \ mint &b) const {\n        return (_v >= p ? _v - p : _v) == (b._v >= p ? b._v\
    \ - p : b._v);\n    }\n\n    constexpr bool operator!=(const mint &b) const {\n\
    \        return (_v >= p ? _v - p : _v) != (b._v >= p ? b._v - p : b._v);\n  \
    \  }\n\n    friend constexpr mint operator+(const mint &a, const mint &b) { return\
    \ mint(a) += b; }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator+(const mint &a, T b) {\n  \
    \      return mint(a) += mint(b);\n    }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator+(T a, const mint &b) {\n  \
    \      return mint(a) += b;\n    }\n\n    friend constexpr mint operator-(const\
    \ mint &a, const mint &b) { return mint(a) -= b; }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator-(const mint &a, T b) {\n  \
    \      return mint(a) -= mint(b);\n    }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator-(T a, const mint &b) {\n  \
    \      return mint(a) -= b;\n    }\n\n    friend constexpr mint operator*(const\
    \ mint &a, const mint &b) { return mint(a) *= b; }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator*(const mint &a, T b) {\n  \
    \      return mint(a) *= mint(b);\n    }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator*(T a, const mint &b) {\n  \
    \      return mint(a) *= b;\n    }\n\n    friend constexpr mint operator/(const\
    \ mint &a, const mint &b) { return mint(a) /= b; }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator/(const mint &a, T b) {\n  \
    \      return mint(a) /= mint(b);\n    }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator/(T a, const mint &b) {\n  \
    \      return mint(a) /= b;\n    }\n\n    template <class T> constexpr mint pow(T\
    \ n) const {\n        mint ret(1), mul(*this);\n        while (n > 0) {\n    \
    \        if (n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n\n    constexpr mint inv() const { return\
    \ pow(p - 2); }\n\n    friend std::ostream &operator<<(std::ostream &os, const\
    \ mint &x) { return os << x.val(); }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &x) {\n        i64 t;\n        is >> t;\n        x = mint(t);\n  \
    \      return (is);\n    }\n\n    constexpr u32 val() const {\n        u32 ret\
    \ = reduce(_v);\n        return ret >= p ? ret - p : ret;\n    }\n\n    static\
    \ constexpr u32 getmod() { return p; }\n};\n\ntemplate <int p> using Mont = LazyMontgomeryModInt<p>;\n\
    \n\nusing mont998 = Mont<998244353>;\nusing mont107 = Mont<1000000007>;\n\n} //\
    \ namespace kk2\n\n\n#line 1 \"segment_tree/utility/affinesum.hpp\"\n\n\n\n#line\
    \ 1 \"math/group/sum.hpp\"\n\n\n\n#line 5 \"math/group/sum.hpp\"\n#include <vector>\n\
    \nnamespace kk2 {\n\nnamespace group {\n\ntemplate <class S> struct Sum {\n  \
    \  S a;\n    int size;\n\n    constexpr Sum() : a(S()), size(0) {}\n\n    constexpr\
    \ Sum(S a, S size = 1) : a(a), size(size) {}\n\n    operator S() const { return\
    \ a; }\n\n    friend std::ostream &operator<<(std::ostream &os, const Sum &sum)\
    \ {\n        os << sum.a;\n        return os;\n    }\n\n    friend std::istream\
    \ &operator>>(std::istream &is, Sum &sum) {\n        is >> sum.a;\n        sum.size\
    \ = 1;\n        return is;\n    }\n\n    constexpr Sum &operator=(const S &rhs)\
    \ {\n        a = rhs;\n        size = 1;\n        return *this;\n    }\n\n   \
    \ constexpr Sum &add(const S &rhs) {\n        a += rhs * size;\n        return\
    \ *this;\n    }\n\n    constexpr Sum &update(const S &rhs) {\n        a = rhs\
    \ * size;\n        return *this;\n    }\n\n    constexpr Sum &multiply(const S\
    \ &rhs) {\n        a *= rhs;\n        return *this;\n    }\n};\n\ntemplate <class\
    \ S> constexpr Sum<S> SumOp(Sum<S> l, Sum<S> r) {\n    l.a += r.a;\n    l.size\
    \ += r.size;\n    return l;\n}\n\ntemplate <class S> Sum<S> SumUnit() {\n    constexpr\
    \ static Sum<S> e = Sum<S>();\n    return e;\n}\n\ntemplate <class S> constexpr\
    \ Sum<S> SumInv(Sum<S> x) {\n    x.a = -x.a;\n    x.size = -x.size;\n    return\
    \ x;\n}\n\n} // namespace group\n\ntemplate <class S, class... Args>\nstd::vector<group::Sum<S>>\
    \ GetVecSum(int n, Args... args) {\n    return std::vector<group::Sum<S>>(n, group::Sum<S>(args...));\n\
    }\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<group::Sum<S>>>\
    \ GetVecSum2D(int h, int w, Args... args) {\n    return std::vector<std::vector<group::Sum<S>>>(h,\
    \ GetVecSum<S>(w, args...));\n}\n\n} // namespace kk2\n\n\n#line 1 \"math/homomorphism/affine.hpp\"\
    \n\n\n\n#line 5 \"math/homomorphism/affine.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ homomorphism {\n\ntemplate <class S> struct Affine {\n    S a, b; // x \\mapsto\
    \ ax + b\n    constexpr Affine() : a(1), b(0) {};\n\n    constexpr Affine(S a,\
    \ S b) : a(a), b(b) {}\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const Affine &aff) {\n        os << aff.a << \" \" << aff.b;\n        return\
    \ os;\n    }\n};\n\ntemplate <class S, class T> constexpr T AffineMap(Affine<S>\
    \ f, T x) {\n    return x.multiply(f.a).add(f.b);\n}\n\ntemplate <class S> constexpr\
    \ Affine<S> AffineComposition(Affine<S> l, Affine<S> r) {\n    l.b = l.a * r.b\
    \ + l.b;\n    l.a = l.a * r.a;\n    return l;\n}\n\ntemplate <class S> constexpr\
    \ Affine<S> AffineUnit() {\n    constexpr static Affine<S> e = Affine<S>();\n\
    \    return e;\n}\n\n} // namespace homomorphism\n\n} // namespace kk2\n\n\n#line\
    \ 1 \"segment_tree/lazy.hpp\"\n\n\n\n#line 5 \"segment_tree/lazy.hpp\"\n#include\
    \ <functional>\n#line 7 \"segment_tree/lazy.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class S,\n          S (*op)(S, S),\n          S (*e)(),\n          class F,\n\
    \          S (*mapping)(F, S),\n          F (*composition)(F, F),\n          F\
    \ (*id)()>\nstruct LazySegTree {\n  public:\n    LazySegTree() : LazySegTree(0)\
    \ {}\n\n    LazySegTree(int n) : LazySegTree(std::vector<S>(n, e())) {}\n\n  \
    \  template <class... Args>\n    LazySegTree(int n, Args... args) : LazySegTree(std::vector<S>(n,\
    \ S(args...))) {}\n\n    LazySegTree(const std::vector<S> &v) : _n(int(v.size()))\
    \ {\n        log = 0;\n        while ((1ll << log) < _n) log++;\n        size\
    \ = 1 << log;\n        d = std::vector<S>(2 * size, e());\n        lz = std::vector<F>(size,\
    \ id());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for\
    \ (int i = size - 1; i >= 1; i--) { update(i); }\n    }\n\n    using Monoid =\
    \ S;\n\n    static S Op(S l, S r) { return op(l, r); }\n\n    static S MonoidUnit()\
    \ { return e(); }\n\n    using Hom = F;\n\n    static S Map(F f, S x) { return\
    \ mapping(f, x); }\n\n    static F Composition(F l, F r) { return composition(l,\
    \ r); }\n\n    static F HomUnit() { return id(); }\n\n    void set(int p, S x)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n        for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n    }\n\n    template <class... Args> void emplace_set(int\
    \ p, Args... args) { set(p, S(args...)); }\n\n    S get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        return d[p];\n    }\n\n    S prod(int l, int r) {\n \
    \       assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return e();\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push(r >> i);\n        }\n\n        S sml = e(), smr\
    \ = e();\n        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n\
    \            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ { return d[1]; }\n\n    void apply(int p, F f) {\n        assert(0 <= p && p\
    \ < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n        d[p] = mapping(f, d[p]);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    template <class... Args> void emplace_apply_point(int\
    \ p, Args... args) { apply(p, F(args...)); }\n\n    void apply(int l, int r, F\
    \ f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return;\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n       \
    \     int l2 = l, r2 = r;\n            while (l < r) {\n                if (l\
    \ & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r, f);\n   \
    \             l >>= 1;\n                r >>= 1;\n            }\n            l\
    \ = l2;\n            r = r2;\n        }\n\n        for (int i = 1; i <= log; i++)\
    \ {\n            if (((l >> i) << i) != l) update(l >> i);\n            if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n    template <class...\
    \ Args> void emplace_apply_range(int l, int r, Args... args) {\n        apply(l,\
    \ r, F(args...));\n    }\n\n    template <bool (*g)(S)> int max_right(int l) {\n\
    \        return max_right(l, [](S x) { return g(x); });\n    }\n\n    template\
    \ <class G> int max_right(int l, G g) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(g(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        for (int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n \
    \       do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (g(op(sm, d[l]))) {\n\
    \                        sm = op(sm, d[l]);\n                        l++;\n  \
    \                  }\n                }\n                return l - size;\n  \
    \          }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*g)(S)> int\
    \ min_left(int r) {\n        return min_left(r, [](S x) { return g(x); });\n \
    \   }\n\n    template <class G> int min_left(int r, G g) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(g(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    push(r);\n                    r = (2 * r +\
    \ 1);\n                    if (g(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - size;\n            }\n         \
    \   sm = op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n\n  private:\n    int _n, size, log;\n    std::vector<S> d;\n    std::vector<F>\
    \ lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n\n   \
    \ void all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n        if (k\
    \ < size) lz[k] = composition(f, lz[k]);\n    }\n\n    void push(int k) {\n  \
    \      all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n      \
    \  lz[k] = id();\n    }\n};\n\n} // namespace kk2\n\n\n#line 7 \"segment_tree/utility/affinesum.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S>\nusing AffineSum = LazySegTree<group::Sum<S>,\n\
    \                              group::SumOp<S>,\n                            \
    \  group::SumUnit<S>,\n                              homomorphism::Affine<S>,\n\
    \                              homomorphism::AffineMap<S, group::Sum<S>>,\n  \
    \                            homomorphism::AffineComposition<S>,\n           \
    \                   homomorphism::AffineUnit<S>>;\n\n} // namespace kk2\n\n\n\
    #line 1 \"template/template.hpp\"\n\n\n\n#pragma GCC optimize(\"O3,unroll-loops\"\
    )\n\n// #include <bits/stdc++.h>\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#line 11 \"template/template.hpp\"\n#include <chrono>\n#include <cmath>\n\
    #include <cstring>\n#include <deque>\n#include <fstream>\n#line 17 \"template/template.hpp\"\
    \n#include <iomanip>\n#line 19 \"template/template.hpp\"\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <optional>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#line 32 \"template/template.hpp\"\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#line 36 \"template/template.hpp\"\
    \n\nusing u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi = std::pair<int,\
    \ int>;\nusing pl = std::pair<i64, i64>;\nusing pil = std::pair<int, i64>;\nusing\
    \ pli = std::pair<i64, int>;\n\ntemplate <class T> using vc = std::vector<T>;\n\
    template <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using vvvc\
    \ = std::vector<vvc<T>>;\ntemplate <class T> using vvvvc = std::vector<vvvc<T>>;\n\
    \ntemplate <class T> using pq = std::priority_queue<T>;\ntemplate <class T> using\
    \ pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\ntemplate <class\
    \ T> constexpr T infty = 0;\ntemplate <> constexpr int infty<int> = (1 << 30)\
    \ - 123;\ntemplate <> constexpr i64 infty<i64> = (1ll << 62) - (1ll << 31);\n\
    template <> constexpr i128 infty<i128> = (i128(1) << 126) - (i128(1) << 63);\n\
    template <> constexpr u32 infty<u32> = infty<int>;\ntemplate <> constexpr u64\
    \ infty<u64> = infty<i64>;\ntemplate <> constexpr u128 infty<u128> = infty<i128>;\n\
    template <> constexpr double infty<double> = infty<i64>;\ntemplate <> constexpr\
    \ long double infty<long double> = infty<i64>;\n\nconstexpr int mod = 998244353;\n\
    constexpr int modu = 1e9 + 7;\nconstexpr long double PI = 3.14159265358979323846;\n\
    \nnamespace kk2 {\n\ntemplate <class T, class... Sizes> auto make_vector(int first,\
    \ Sizes... sizes) {\n    if constexpr (sizeof...(sizes) == 0) {\n        return\
    \ std::vector<T>(first);\n    } else {\n        return std::vector<decltype(make_vector(sizes...))>(first,\
    \ make_vector(sizes...));\n    }\n}\n\ntemplate <class T, class U> void fill_all(std::vector<T>\
    \ &v, const U &x) {\n    std::fill(std::begin(v), std::end(v), T(x));\n}\n\ntemplate\
    \ <class T, class U> void fill_all(std::vector<std::vector<T>> &v, const U &x)\
    \ {\n    for (auto &u : v) fill_all(u, x);\n}\n\n} // namespace kk2\n\ntemplate\
    \ <class T, class S> inline bool chmax(T &a, const S &b) {\n    return (a < b\
    \ ? a = b, 1 : 0);\n}\n\ntemplate <class T, class S> inline bool chmin(T &a, const\
    \ S &b) {\n    return (a > b ? a = b, 1 : 0);\n}\n\nvoid Yes(bool b = 1) {\n \
    \   std::cout << (b ? \"Yes\\n\" : \"No\\n\");\n}\n\nvoid No(bool b = 1) {\n \
    \   std::cout << (b ? \"No\\n\" : \"Yes\\n\");\n}\n\nvoid YES(bool b = 1) {\n\
    \    std::cout << (b ? \"YES\\n\" : \"NO\\n\");\n}\n\nvoid NO(bool b = 1) {\n\
    \    std::cout << (b ? \"NO\\n\" : \"YES\\n\");\n}\n\nvoid yes(bool b = 1) {\n\
    \    std::cout << (b ? \"yes\\n\" : \"no\\n\");\n}\n\nvoid no(bool b = 1) {\n\
    \    std::cout << (b ? \"no\\n\" : \"yes\\n\");\n}\n\n#define rep1(a) for (i64\
    \ _ = 0; _ < (i64)(a); ++_)\n#define rep2(i, a) for (i64 i = 0; i < (i64)(a);\
    \ ++i)\n#define rep3(i, a, b) for (i64 i = (a); i < (i64)(b); ++i)\n#define repi2(i,\
    \ a) for (i64 i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (i64 i = (a)\
    \ - 1; i >= (i64)(b); --i)\n#define overload3(a, b, c, d, ...) d\n#define rep(...)\
    \ overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define repi(...) overload3(__VA_ARGS__,\
    \ repi3, repi2, rep1)(__VA_ARGS__)\n\n#define fi first\n#define se second\n#define\
    \ all(p) std::begin(p), std::end(p)\n\nstruct IoSetUp {\n    IoSetUp() {\n   \
    \     std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n    }\n\
    } iosetup;\n\ntemplate <class OStream, class T, class U>\nOStream &operator<<(OStream\
    \ &os, const std::pair<T, U> &p) {\n    os << p.first << ' ' << p.second;\n  \
    \  return os;\n}\n\ntemplate <class IStream, class T, class U> IStream &operator>>(IStream\
    \ &is, std::pair<T, U> &p) {\n    is >> p.first >> p.second;\n    return is;\n\
    }\n\ntemplate <class OStream, class T> OStream &operator<<(OStream &os, const\
    \ std::vector<T> &v) {\n    for (int i = 0; i < (int)v.size(); i++) { os << v[i]\
    \ << (i + 1 == (int)v.size() ? \"\" : \" \"); }\n    return os;\n}\n\ntemplate\
    \ <class IStream, class T> IStream &operator>>(IStream &is, std::vector<T> &v)\
    \ {\n    for (auto &x : v) is >> x;\n    return is;\n}\n\n\n#line 6 \"verify/yosupo_ds/ds_range_affine_range_sum.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n  \
    \  auto a = kk2::GetVecSum<kk2::mont998>(n);\n    cin >> a;\n    kk2::AffineSum<kk2::mont998>\
    \ seg(a);\n\n    rep (q) {\n        int t;\n        cin >> t;\n        if (t ==\
    \ 0) {\n            int l, r;\n            kk2::mont998 b, c;\n            cin\
    \ >> l >> r >> b >> c;\n            seg.emplace_apply_range(l, r, b, c);\n   \
    \     }\n        if (t == 1) {\n            int l, r;\n            cin >> l >>\
    \ r;\n            cout << seg.prod(l, r).a << \"\\n\";\n        }\n    }\n\n \
    \   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../../modint/mont.hpp\"\n#include \"../../segment_tree/utility/affinesum.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int n, q;\n    cin >> n >> q;\n    auto a = kk2::GetVecSum<kk2::mont998>(n);\n\
    \    cin >> a;\n    kk2::AffineSum<kk2::mont998> seg(a);\n\n    rep (q) {\n  \
    \      int t;\n        cin >> t;\n        if (t == 0) {\n            int l, r;\n\
    \            kk2::mont998 b, c;\n            cin >> l >> r >> b >> c;\n      \
    \      seg.emplace_apply_range(l, r, b, c);\n        }\n        if (t == 1) {\n\
    \            int l, r;\n            cin >> l >> r;\n            cout << seg.prod(l,\
    \ r).a << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - modint/mont.hpp
  - type_traits/type_traits.hpp
  - segment_tree/utility/affinesum.hpp
  - math/group/sum.hpp
  - math/homomorphism/affine.hpp
  - segment_tree/lazy.hpp
  - template/template.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-10-11 23:06:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
- /verify/verify/yosupo_ds/ds_range_affine_range_sum.test.cpp.html
title: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
---
