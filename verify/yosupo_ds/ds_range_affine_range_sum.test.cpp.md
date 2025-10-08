---
data:
  _extendedDependsOn:
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
    path: segment_tree/lazy.hpp
    title: segment_tree/lazy.hpp
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/yosupo_ds/ds_range_affine_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n\
    #line 1 \"modint/mont.hpp\"\n\n\n\n#include <cassert>\n#include <cstdint>\n#include\
    \ <iostream>\n#include <type_traits>\n\n#line 1 \"type_traits/integral.hpp\"\n\
    \n\n\n#line 5 \"type_traits/integral.hpp\"\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\
    \ntemplate <typename T> using is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
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
    \ kk2\n\n\n#line 11 \"modint/mont.hpp\"\n\nnamespace kk2 {\n\ntemplate <int p>\
    \ struct LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n    using\
    \ i32 = int32_t;\n    using i64 = int64_t;\n    using u32 = uint32_t;\n    using\
    \ u64 = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32 ret = p;\n\
    \        for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;\n        return ret;\n\
    \    }\n\n    static constexpr u32 r = get_r();\n    static constexpr u32 n2 =\
    \ -u64(p) % p;\n    static_assert(r * p == 1, \"invalid, r * p != 1\");\n    static_assert(p\
    \ < (1 << 30), \"invalid, p >= 2 ^ 30\");\n    static_assert((p & 1) == 1, \"\
    invalid, p % 2 == 0\");\n\n    u32 _v;\n\n    constexpr LazyMontgomeryModInt()\
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
    segment_tree/lazy.hpp\"\n\n\n\n#line 5 \"segment_tree/lazy.hpp\"\n#include <functional>\n\
    #include <vector>\n\nnamespace kk2 {\n\ntemplate <class S,\n          S (*op)(S,\
    \ S),\n          S (*e)(),\n          class F,\n          S (*mapping)(F, S),\n\
    \          F (*composition)(F, F),\n          F (*id)()>\nstruct LazySegmentTree\
    \ {\n  public:\n    LazySegmentTree() : LazySegmentTree(0) {}\n\n    LazySegmentTree(int\
    \ n) : _n(n) {\n        log = 0;\n        while ((1ll << log) < _n) log++;\n \
    \       size = 1 << log;\n        d = std::vector<S>(2 * size, e());\n       \
    \ lz = std::vector<F>(size, id());\n    }\n\n    template <class... Args> LazySegmentTree(int\
    \ n, Args... args)\n        : LazySegmentTree(std::vector<S>(n, S(args...))) {}\n\
    \n    LazySegmentTree(const std::vector<S> &v) : _n(int(v.size())) {\n       \
    \ log = 0;\n        while ((1ll << log) < _n) log++;\n        size = 1 << log;\n\
    \        d = std::vector<S>(2 * size, e());\n        lz = std::vector<F>(size,\
    \ id());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        build();\n\
    \    }\n\n    void build() {\n        assert(!is_built);\n        is_built = true;\n\
    \        for (int i = size - 1; i >= 1; i--) { update(i); }\n    }\n\n    template\
    \ <class... Args> void init_set(int p, Args... args) {\n        assert(0 <= p\
    \ && p < _n);\n        assert(!is_built);\n        d[p + size] = S(args...);\n\
    \    }\n\n    using Monoid = S;\n\n    static S Op(S l, S r) { return op(l, r);\
    \ }\n\n    static S MonoidUnit() { return e(); }\n\n    using Hom = F;\n\n   \
    \ static S Map(F f, S x) { return mapping(f, x); }\n\n    static F Composition(F\
    \ l, F r) { return composition(l, r); }\n\n    static F HomUnit() { return id();\
    \ }\n\n    template <class... Args> void set(int p, Args... args) {\n        assert(0\
    \ <= p && p < _n);\n        assert(is_built);\n        p += size;\n        for\
    \ (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = S(args...);\n     \
    \   for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int p)\
    \ {\n        assert(0 <= p && p < _n);\n        assert(is_built);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        return\
    \ d[p];\n    }\n\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r\
    \ && r <= _n);\n        assert(is_built);\n        if (l == r) return e();\n\n\
    \        l += size;\n        r += size;\n\n        for (int i = log; i >= 1; i--)\
    \ {\n            if (((l >> i) << i) != l) push(l >> i);\n            if (((r\
    \ >> i) << i) != r) push(r >> i);\n        }\n\n        S sml = e(), smr = e();\n\
    \        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n    \
    \        if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n           \
    \ r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ {\n        assert(is_built);\n        return d[1];\n    }\n\n    template <class...\
    \ Args> void apply_point(int p, Args... args) {\n        assert(0 <= p && p <\
    \ _n);\n        assert(is_built);\n        p += size;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n        d[p] = mapping(F(args...), d[p]);\n    \
    \    for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    template <class...\
    \ Args> void apply_range(int l, int r, Args... args) {\n        assert(0 <= l\
    \ && l <= r && r <= _n);\n        assert(is_built);\n        if (l == r) return;\n\
    \        F f = F(args...);\n\n        l += size;\n        r += size;\n\n     \
    \   for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \n        {\n            int l2 = l, r2 = r;\n            while (l < r) {\n  \
    \              if (l & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2;\n            r = r2;\n        }\n\n        for (int i = 1; i\
    \ <= log; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n    \
    \        if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n\
    \    template <bool (*g)(S)> int max_right(int l) {\n        return max_right(l,\
    \ [](S x) { return g(x); });\n    }\n\n    template <class G> int max_right(int\
    \ l, G g) {\n        assert(0 <= l && l <= _n);\n        assert(g(e()));\n   \
    \     assert(is_built);\n        if (l == _n) return _n;\n        l += size;\n\
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
    \ r && r <= _n);\n        assert(g(e()));\n        assert(is_built);\n       \
    \ if (r == 0) return 0;\n        r += size;\n        for (int i = log; i >= 1;\
    \ i--) push((r - 1) >> i);\n        S sm = e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm)))\
    \ {\n                while (r < size) {\n                    push(r);\n      \
    \              r = (2 * r + 1);\n                    if (g(op(d[r], sm))) {\n\
    \                        sm = op(d[r], sm);\n                        r--;\n  \
    \                  }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\n  private:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    std::vector<F> lz;\n    bool is_built = false;\n\n    void update(int\
    \ k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n\n    void all_apply(int k, F f)\
    \ {\n        d[k] = mapping(f, d[k]);\n        if (k < size) lz[k] = composition(f,\
    \ lz[k]);\n    }\n\n    void push(int k) {\n        all_apply(2 * k, lz[k]);\n\
    \        all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n    }\n};\n\ntemplate\
    \ <class A> using LazySegmentTreeS = LazySegmentTree<typename A::S,\n        \
    \                                                    A::S::op,\n             \
    \                                               A::S::unit,\n                \
    \                                            typename A::A,\n                \
    \                                            A::act,\n                       \
    \                                     A::A::op,\n                            \
    \                                A::A::unit>;\n\n} // namespace kk2\n\n\n#line\
    \ 1 \"template/template.hpp\"\n\n\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#line 8 \"template/template.hpp\"\n#include <chrono>\n#include\
    \ <cmath>\n#include <deque>\n#line 12 \"template/template.hpp\"\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <optional>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#line\
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
    \ <cctype>\n#line 6 \"template/fastio.hpp\"\n#include <cstdio>\n#include <fstream>\n\
    #line 10 \"template/fastio.hpp\"\n\n#line 13 \"template/fastio.hpp\"\n\nnamespace\
    \ kk2 {\n\nnamespace fastio {\n\nstruct Scanner : type_traits::istream_tag {\n\
    \  private:\n    static constexpr size_t INPUT_BUF = 1 << 17;\n    size_t pos\
    \ = 0, end = 0;\n    bool is_eof = false;\n    static char buf[INPUT_BUF];\n \
    \   FILE *fp;\n\n  public:\n    Scanner() : fp(stdin) {}\n\n    Scanner(const\
    \ char *file) : fp(fopen(file, \"r\")) {}\n\n    ~Scanner() {\n        if (fp\
    \ != stdin) fclose(fp);\n    }\n\n    char now() {\n        if (is_eof) return\
    \ '\\0';\n        if (pos == end) {\n            end = fread(buf, 1, INPUT_BUF,\
    \ fp);\n            if (end != INPUT_BUF) buf[end] = '\\0';\n            if (end\
    \ == 0) is_eof = true;\n            pos = 0;\n        }\n        return buf[pos];\n\
    \    }\n\n    void skip_space() {\n        while (isspace(now())) ++pos;\n   \
    \ }\n\n    template <class T, is_unsigned_t<T> * = nullptr> T next_unsigned_integral()\
    \ {\n        skip_space();\n        T res{};\n        while (isdigit(now())) {\n\
    \            res = res * 10 + (now() - '0');\n            ++pos;\n        }\n\
    \        return res;\n    }\n\n    template <class T, is_signed_t<T> * = nullptr>\
    \ T next_signed_integral() {\n        skip_space();\n        if (now() == '-')\
    \ {\n            ++pos;\n            return T(-next_unsigned_integral<typename\
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
    \ { return (a > b ? a = b, 1 : 0); }\n\n\n#line 7 \"verify/yosupo_ds/ds_range_affine_range_sum.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    using A = kk2::action::AffineSumWithSize<kk2::mont998,\
    \ kk2::mont998>;\n    int n, q;\n    kin >> n >> q;\n    vc<A::S> a(n);\n    kin\
    \ >> a;\n    kk2::LazySegmentTreeS<A> seg(a);\n\n    rep (q) {\n        int t;\n\
    \        kin >> t;\n        if (t == 0) {\n            int l, r;\n           \
    \ kk2::mont998 b, c;\n            kin >> l >> r >> b >> c;\n            seg.apply_range(l,\
    \ r, b, c);\n        }\n        if (t == 1) {\n            int l, r;\n       \
    \     kin >> l >> r;\n            kout << seg.prod(l, r).a << \"\\n\";\n     \
    \   }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../../modint/mont.hpp\"\n#include \"../../math/action/affine_sumwithsize.hpp\"\
    \n#include \"../../segment_tree/lazy.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    using A = kk2::action::AffineSumWithSize<kk2::mont998,\
    \ kk2::mont998>;\n    int n, q;\n    kin >> n >> q;\n    vc<A::S> a(n);\n    kin\
    \ >> a;\n    kk2::LazySegmentTreeS<A> seg(a);\n\n    rep (q) {\n        int t;\n\
    \        kin >> t;\n        if (t == 0) {\n            int l, r;\n           \
    \ kk2::mont998 b, c;\n            kin >> l >> r >> b >> c;\n            seg.apply_range(l,\
    \ r, b, c);\n        }\n        if (t == 1) {\n            int l, r;\n       \
    \     kin >> l >> r;\n            kout << seg.prod(l, r).a << \"\\n\";\n     \
    \   }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - modint/mont.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - math/action/affine_sumwithsize.hpp
  - math/group/sum_with_size.hpp
  - type_traits/io.hpp
  - math/monoid/affine.hpp
  - type_traits/io.hpp
  - segment_tree/lazy.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
- /verify/verify/yosupo_ds/ds_range_affine_range_sum.test.cpp.html
title: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
---
