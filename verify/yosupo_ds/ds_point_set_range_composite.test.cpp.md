---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  dependencies:
  - files:
    - filename: reverse_args.hpp
      icon: LIBRARY_ALL_AC
      path: functional/reverse_args.hpp
    - filename: affine.hpp
      icon: LIBRARY_ALL_AC
      path: math/monoid/affine.hpp
    - filename: rev_op.hpp
      icon: LIBRARY_ALL_AC
      path: math/monoid/rev_op.hpp
    - filename: mont.hpp
      icon: LIBRARY_ALL_AC
      path: modint/mont.hpp
    - filename: seg.hpp
      icon: LIBRARY_ALL_AC
      path: segment_tree/seg.hpp
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
    - filename: algebra.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/algebra.hpp
    - filename: functional.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/functional.hpp
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
  - functional/reverse_args.hpp
  - math/monoid/affine.hpp
  - math/monoid/rev_op.hpp
  - modint/mont.hpp
  - segment_tree/seg.hpp
  - template/constant.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  - template/template.hpp
  - template/type_alias.hpp
  - type_traits/algebra.hpp
  - type_traits/functional.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite\n\
      \n#include \"../../functional/reverse_args.hpp\"\n#include \"../../math/monoid/affine.hpp\"\
      \n#include \"../../math/monoid/rev_op.hpp\"\n#include \"../../modint/mont.hpp\"\
      \n#include \"../../segment_tree/seg.hpp\"\n#include \"../../template/template.hpp\"\
      \nusing namespace std;\n\nint main() {\n    int n, q;\n    kin >> n >> q;\n\
      \    using M = kk2::monoid::Affine<kk2::mont998>;\n    using RM = kk2::monoid::ReverseOp<M>;\n\
      \    vc<RM> a(n);\n    kin >> a;\n    kk2::SegmentTree<RM> seg(a);\n\n    rep(q)\
      \ {\n        int t;\n        kin >> t;\n        if (t == 0) {\n            int\
      \ p;\n            kk2::mont998 c, d;\n            kin >> p >> c >> d;\n    \
      \        seg.set(p, c, d);\n        }\n        if (t == 1) {\n            int\
      \ l, r;\n            kk2::mont998 x;\n            kin >> l >> r >> x;\n    \
      \        kout << seg.prod(l, r).eval(x) << \"\\n\";\n        }\n    }\n\n  \
      \  return 0;\n}\n"
    name: default
  - code: "#line 1 \"verify/yosupo_ds/ds_point_set_range_composite.test.cpp\"\n//\
      \ competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite\n\
      \n#line 1 \"functional/reverse_args.hpp\"\n\n\n\n#line 1 \"type_traits/functional.hpp\"\
      \n\n\n\n#include <type_traits>\n\nnamespace kk2 {\n\ntemplate <typename T>\n\
      using is_function_pointer =\n    typename std::conditional<std::is_pointer_v<T>\
      \ && std::is_function_v<std::remove_pointer_t<T>>,\n                       \
      \       std::true_type,\n                              std::false_type>::type;\n\
      \ntemplate <typename T> struct is_two_args_function_pointer : std::false_type\
      \ {};\n\ntemplate <typename R, typename T1, typename T2>\nstruct is_two_args_function_pointer<R\
      \ (*)(T1, T2)> : std::true_type {};\n\ntemplate <typename T>\nusing is_two_args_function_pointer_t\
      \ = std::enable_if_t<is_two_args_function_pointer<T>::value>;\n\ntemplate <class\
      \ T>\nconcept FunctionPointer = is_function_pointer<T>::value;\n\ntemplate <class\
      \ T>\nconcept TwoArgsFunctionPointer = is_two_args_function_pointer<T>::value;\n\
      \n} // namespace kk2\n\n\n#line 5 \"functional/reverse_args.hpp\"\n\nnamespace\
      \ kk2 {\n\n// reverse_args<f>(y, x) = f(x, y)\ntemplate <auto f>\n    requires\
      \ TwoArgsFunctionPointer<decltype(f)>\ninline auto reverse_args(auto x, auto\
      \ y) {\n    return f(y, x);\n}\n\n} // namespace kk2\n\n\n#line 1 \"math/monoid/affine.hpp\"\
      \n\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <concepts>\n#include\
      \ <fstream>\n#include <istream>\n#include <ostream>\n#line 9 \"type_traits/io.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct\
      \ ostream_tag {};\n\n} // namespace type_traits\n\ntemplate <typename T>\nusing\
      \ is_standard_istream = typename std::conditional<std::is_same<T, std::istream>::value\n\
      \                                                          || std::is_same<T,\
      \ std::ifstream>::value,\n                                                 \
      \     std::true_type,\n                                                    \
      \  std::false_type>::type;\ntemplate <typename T>\nusing is_standard_ostream\
      \ = typename std::conditional<std::is_same<T, std::ostream>::value\n       \
      \                                                   || std::is_same<T, std::ofstream>::value,\n\
      \                                                      std::true_type,\n   \
      \                                                   std::false_type>::type;\n\
      template <typename T> using is_user_defined_istream = std::is_base_of<type_traits::istream_tag,\
      \ T>;\ntemplate <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
      \ T>;\n\ntemplate <typename T>\nusing is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
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
      \n} // namespace kk2\n\n\n#line 5 \"math/monoid/affine.hpp\"\n\nnamespace kk2\
      \ {\n\nnamespace monoid {\n\ntemplate <class S> struct Affine {\n    static\
      \ constexpr bool commutative = false;\n    using M = Affine;\n    S a, b; //\
      \ x \\mapsto ax + b\n\n    Affine() : a(S(1)), b(S(0)){};\n    Affine(S a, S\
      \ b) : a(a), b(b) {}\n    inline S eval(S x) const { return a * x + b; }\n \
      \   // l \\circ r\n    inline static M op(M l, M r) { return M(l.a * r.a, l.a\
      \ * r.b + l.b); }\n    inline static M unit() { return M(); }\n    inline static\
      \ M inv(M f) { return M(S(1) / f.a, -f.b / f.a); }\n    bool operator==(const\
      \ M &rhs) const { return a == rhs.a and b == rhs.b; }\n    bool operator!=(const\
      \ M &rhs) const { return a != rhs.a or b != rhs.b; }\n\n    template <OutputStream\
      \ OStream> friend OStream &operator<<(OStream &os, const M &x) {\n        return\
      \ os << x.a << \" \" << x.b;\n    }\n\n    template <InputStream IStream> friend\
      \ IStream &operator>>(IStream &is, M &x) {\n        return is >> x.a >> x.b;\n\
      \    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\n\n#line 1 \"math/monoid/rev_op.hpp\"\
      \n\n\n\n#line 5 \"math/monoid/rev_op.hpp\"\n\nnamespace kk2 {\n\nnamespace monoid\
      \ {\n\ntemplate <class T> struct ReverseOp : public T {\n    static constexpr\
      \ bool commutative = T::commutative;\n    using M = ReverseOp;\n    using base\
      \ = T;\n    using T::T;\n    ReverseOp(const T &t) : T(t) {}\n    inline static\
      \ M op(M l, M r) {\n        return static_cast<M>(T::op(static_cast<T>(r), static_cast<T>(l)));\n\
      \    }\n    inline static M unit() { return static_cast<M>(T::unit()); }\n\n\
      \    bool operator==(const M &rhs) const { return static_cast<T>(*this) == static_cast<T>(rhs);\
      \ }\n    bool operator!=(const M &rhs) const { return static_cast<T>(*this)\
      \ != static_cast<T>(rhs); }\n    template <OutputStream OStream> friend OStream\
      \ &operator<<(OStream &os, const M &x) {\n        os << static_cast<T>(x);\n\
      \        return os;\n    }\n    template <InputStream IStream> friend IStream\
      \ &operator>>(IStream &is, M &x) {\n        is >> static_cast<T &>(x);\n   \
      \     return is;\n    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\
      \n\n#line 1 \"modint/mont.hpp\"\n\n\n\n#include <cassert>\n#include <cstdint>\n\
      #include <iostream>\n#line 8 \"modint/mont.hpp\"\n\n#line 1 \"type_traits/integral.hpp\"\
      \n\n\n\n#line 5 \"type_traits/integral.hpp\"\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\
      \ntemplate <typename T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T,\
      \ __int128_t>::value\n                                                     \
      \  or std::is_same<T, __int128>::value,\n                                  \
      \                 std::true_type,\n                                        \
      \           std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_int128\
      \ =\n    typename std::conditional<std::is_same<T, __uint128_t>::value\n   \
      \                               or std::is_same<T, unsigned __int128>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T>\nusing is_integral =\n\
      \    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
      \                                  or is_unsigned_int128<T>::value,\n      \
      \                        std::true_type,\n                              std::false_type>::type;\n\
      \ntemplate <typename T>\nusing is_signed = typename std::conditional<std::is_signed<T>::value\
      \ or is_signed_int128<T>::value,\n                                         \
      \   std::true_type,\n                                            std::false_type>::type;\n\
      \ntemplate <typename T>\nusing is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
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
      \n} // namespace kk2\n\n\n#line 11 \"modint/mont.hpp\"\n\nnamespace kk2 {\n\n\
      template <int p> struct LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n\
      \    using i32 = int32_t;\n    using i64 = int64_t;\n    using u32 = uint32_t;\n\
      \    using u64 = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32\
      \ ret = p;\n        for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;\n      \
      \  return ret;\n    }\n\n    static constexpr u32 r = get_r();\n    static constexpr\
      \ u32 n2 = -u64(p) % p;\n    static_assert(r * p == 1, \"invalid, r * p != 1\"\
      );\n    static_assert(p < (1 << 30), \"invalid, p >= 2 ^ 30\");\n    static_assert((p\
      \ & 1) == 1, \"invalid, p % 2 == 0\");\n\n    u32 _v;\n\n    constexpr LazyMontgomeryModInt()\
      \ : _v(0) {}\n\n    template <Integral T> constexpr LazyMontgomeryModInt(T b)\
      \ : _v(reduce(u64(b % p + p) * n2)) {}\n\n    static constexpr u32 reduce(const\
      \ u64 &b) { return (b + u64(u32(b) * u32(-r)) * p) >> 32; }\n    constexpr mint\
      \ &operator++() { return *this += 1; }\n    constexpr mint &operator--() { return\
      \ *this -= 1; }\n\n    constexpr mint operator++(int) {\n        mint ret =\
      \ *this;\n        *this += 1;\n        return ret;\n    }\n\n    constexpr mint\
      \ operator--(int) {\n        mint ret = *this;\n        *this -= 1;\n      \
      \  return ret;\n    }\n\n    constexpr mint &operator+=(const mint &b) {\n \
      \       if (i32(_v += b._v - 2 * p) < 0) _v += 2 * p;\n        return *this;\n\
      \    }\n\n    constexpr mint &operator-=(const mint &b) {\n        if (i32(_v\
      \ -= b._v) < 0) _v += 2 * p;\n        return *this;\n    }\n\n    constexpr\
      \ mint &operator*=(const mint &b) {\n        _v = reduce(u64(_v) * b._v);\n\
      \        return *this;\n    }\n\n    constexpr mint &operator/=(const mint &b)\
      \ {\n        *this *= b.inv();\n        return *this;\n    }\n\n\n    constexpr\
      \ bool operator==(const mint &b) const {\n        return (_v >= p ? _v - p :\
      \ _v) == (b._v >= p ? b._v - p : b._v);\n    }\n\n    constexpr bool operator!=(const\
      \ mint &b) const {\n        return (_v >= p ? _v - p : _v) != (b._v >= p ? b._v\
      \ - p : b._v);\n    }\n\n    constexpr mint operator-() const { return mint()\
      \ - mint(*this); }\n    constexpr mint operator+() const { return mint(*this);\
      \ }\n    friend constexpr mint operator+(const mint &a, const mint &b) { return\
      \ mint(a) += b; }\n    friend constexpr mint operator-(const mint &a, const\
      \ mint &b) { return mint(a) -= b; }\n    friend constexpr mint operator*(const\
      \ mint &a, const mint &b) { return mint(a) *= b; }\n    friend constexpr mint\
      \ operator/(const mint &a, const mint &b) { return mint(a) /= b; }\n\n    template\
      \ <class T> constexpr mint pow(T n) const {\n        mint ret(1), mul(*this);\n\
      \        while (n > 0) {\n            if (n & 1) ret *= mul;\n            if\
      \ (n >>= 1) mul *= mul;\n        }\n        return ret;\n    }\n\n    constexpr\
      \ mint inv() const {\n        assert(*this != mint(0));\n        return pow(p\
      \ - 2);\n    }\n\n    template <OutputStream OStream> friend OStream &operator<<(OStream\
      \ &os, const mint &x) {\n        return os << x.val();\n    }\n\n    template\
      \ <InputStream IStream> friend IStream &operator>>(IStream &is, mint &x) {\n\
      \        i64 t;\n        is >> t;\n        x = mint(t);\n        return (is);\n\
      \    }\n\n    constexpr u32 val() const {\n        u32 ret = reduce(_v);\n \
      \       return ret >= p ? ret - p : ret;\n    }\n\n    static constexpr u32\
      \ getmod() { return p; }\n};\n\ntemplate <int p> using Mont = LazyMontgomeryModInt<p>;\n\
      \nusing mont998 = Mont<998244353>;\nusing mont107 = Mont<1000000007>;\n\n} //\
      \ namespace kk2\n\n\n#line 1 \"segment_tree/seg.hpp\"\n\n\n\n#line 5 \"segment_tree/seg.hpp\"\
      \n#include <vector>\n\n#line 1 \"type_traits/algebra.hpp\"\n\n\n\n#line 5 \"\
      type_traits/algebra.hpp\"\n\nnamespace kk2 {\n\nnamespace algebra {\n\n// These\
      \ concepts describe the static interface expected by the library.\n// Algebraic\
      \ laws such as associativity cannot be checked by the type system.\n//\n// A\
      \ user-defined monoid therefore needs only:\n//\n//   struct MyMonoid {\n//\
      \       static MyMonoid op(const MyMonoid &, const MyMonoid &);\n//       static\
      \ MyMonoid unit();\n//   };\n//\n// The return types are intentionally exact,\
      \ so a typo such as returning the\n// underlying scalar instead of MyMonoid\
      \ is diagnosed at the concept boundary.\ntemplate <class T>\nconcept Semigroup\
      \ = requires(const T &x, const T &y) {\n    { T::op(x, y) } -> std::same_as<T>;\n\
      };\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> && requires {\n    {\
      \ T::unit() } -> std::same_as<T>;\n};\n\ntemplate <class T>\nconcept Group =\
      \ Monoid<T> && requires(const T &x) {\n    { T::inv(x) } -> std::same_as<T>;\n\
      };\n\ntemplate <class T>\nconcept CommutativeMonoid = Monoid<T> && requires\
      \ {\n    { T::commutative } -> std::convertible_to<bool>;\n} && bool(T::commutative);\n\
      \ntemplate <class T>\nconcept CommutativeGroup = Group<T> && requires {\n  \
      \  { T::commutative } -> std::convertible_to<bool>;\n} && bool(T::commutative);\n\
      \n// An action specification owns the pair of algebraic types and the mapping\n\
      // between them. It is the interface required by lazy propagation structures.\n\
      template <class T>\nconcept Action =\n    requires {\n        typename T::A;\n\
      \        typename T::S;\n    } && Monoid<typename T::A> && Monoid<typename T::S>\n\
      \    && requires(const typename T::A &f, const typename T::S &x) {\n       \
      \    { T::act(f, x) } -> std::same_as<typename T::S>;\n       };\n\n} // namespace\
      \ algebra\n\n} // namespace kk2\n\n\n#line 8 \"segment_tree/seg.hpp\"\n\nnamespace\
      \ kk2 {\n\ntemplate <algebra::Monoid M> struct SegmentTree {\n  public:\n  \
      \  SegmentTree() : SegmentTree(0) {}\n\n    SegmentTree(int n) : _n(n) {\n \
      \       log = 0;\n        while ((1U << log) < (unsigned int)(_n)) log++;\n\
      \        size = 1 << log;\n        d = std::vector<M>(2 * size, M::unit());\n\
      \    }\n\n    template <class... Args>\n    SegmentTree(int n, Args... args)\
      \ : SegmentTree(std::vector<M>(n, M(args...))) {}\n\n    SegmentTree(const std::vector<M>\
      \ &v) : _n(int(v.size())) {\n        log = 0;\n        while ((1U << log) <\
      \ (unsigned int)(_n)) log++;\n        size = 1 << log;\n        d = std::vector<M>(2\
      \ * size, M::unit());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n\
      \        build();\n    }\n\n    void build() {\n        assert(!is_built);\n\
      \        is_built = true;\n        for (int i = size - 1; i >= 1; i--) update(i);\n\
      \    }\n\n    template <class... Args> void init_set(int p, Args... args) {\n\
      \        assert(0 <= p && p < _n);\n        assert(!is_built);\n        d[p\
      \ + size] = M(args...);\n    }\n\n    using Monoid = M;\n\n    static M Op(M\
      \ l, M r) { return M::op(l, r); }\n\n    static M MonoidUnit() { return M::unit();\
      \ }\n\n    template <class... Args> void set(int p, Args... args) {\n      \
      \  assert(0 <= p && p < _n);\n        assert(is_built);\n        p += size;\n\
      \        d[p] = M(args...);\n        for (int i = 1; i <= log; i++) update(p\
      \ >> i);\n    }\n\n    M get(int p) {\n        assert(0 <= p && p < _n);\n \
      \       assert(is_built);\n        return d[p + size];\n    }\n\n    M prod(int\
      \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        assert(is_built);\n\
      \        M sml = M::unit(), smr = M::unit();\n        l += size;\n        r\
      \ += size;\n\n        while (l < r) {\n            if (l & 1) sml = M::op(sml,\
      \ d[l++]);\n            if (r & 1) smr = M::op(d[--r], smr);\n            l\
      \ >>= 1;\n            r >>= 1;\n        }\n        return M::op(sml, smr);\n\
      \    }\n\n    M all_prod() {\n        assert(is_built);\n        return d[1];\n\
      \    }\n\n    template <bool (*f)(M)> int max_right(int l) {\n        return\
      \ max_right(l, [](M x) { return f(x); });\n    }\n\n    template <class F> int\
      \ max_right(int l, F f) {\n        assert(0 <= l && l <= _n);\n        assert(f(M::unit()));\n\
      \        assert(is_built);\n        if (l == _n) return _n;\n        l += size;\n\
      \        M sm = M::unit();\n        do {\n            while (l % 2 == 0) l >>=\
      \ 1;\n            if (!f(M::op(sm, d[l]))) {\n                while (l < size)\
      \ {\n                    l = (2 * l);\n                    if (f(M::op(sm, d[l])))\
      \ {\n                        sm = M::op(sm, d[l]);\n                       \
      \ l++;\n                    }\n                }\n                return l -\
      \ size;\n            }\n            sm = M::op(sm, d[l]);\n            l++;\n\
      \        } while ((l & -l) != l);\n        return _n;\n    }\n\n    template\
      \ <bool (*f)(M)> int min_left(int r) {\n        return min_left(r, [](M x) {\
      \ return f(x); });\n    }\n\n    template <class F> int min_left(int r, F f)\
      \ {\n        assert(0 <= r && r <= _n);\n        assert(f(M::unit()));\n   \
      \     assert(is_built);\n        if (r == 0) return 0;\n        r += size;\n\
      \        M sm = M::unit();\n        do {\n            r--;\n            while\
      \ (r > 1 && (r % 2)) r >>= 1;\n            if (!f(M::op(d[r], sm))) {\n    \
      \            while (r < size) {\n                    r = (2 * r + 1);\n    \
      \                if (f(M::op(d[r], sm))) {\n                        sm = M::op(d[r],\
      \ sm);\n                        r--;\n                    }\n              \
      \  }\n                return r + 1 - size;\n            }\n            sm =\
      \ M::op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n  \
      \  }\n\n  private:\n    int _n, size, log;\n    std::vector<M> d;\n    bool\
      \ is_built = false;\n\n    void update(int k) { d[k] = M::op(d[2 * k], d[2 *\
      \ k + 1]); }\n};\n\n} // namespace kk2\n\n\n#line 1 \"template/template.hpp\"\
      \n\n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#line 8 \"\
      template/template.hpp\"\n#include <chrono>\n#include <cmath>\n#include <deque>\n\
      #include <functional>\n#include <iterator>\n#include <limits>\n#include <map>\n\
      #include <numeric>\n#include <optional>\n#include <queue>\n#include <random>\n\
      #include <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n\
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
      \n\n#line 1 \"template/fastio.hpp\"\n\n\n\n#include <cctype>\n#line 6 \"template/fastio.hpp\"\
      \n#include <cstdio>\n#line 10 \"template/fastio.hpp\"\n\n#line 13 \"template/fastio.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace fastio {\n\nstruct Scanner : type_traits::istream_tag\
      \ {\n  private:\n    static constexpr size_t INPUT_BUF = 1 << 17;\n    size_t\
      \ pos = 0, end = 0;\n    bool is_eof = false;\n    static char buf[INPUT_BUF];\n\
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
      \ const S &b) { return (a > b ? a = b, 1 : 0); }\n\n\n#line 9 \"verify/yosupo_ds/ds_point_set_range_composite.test.cpp\"\
      \nusing namespace std;\n\nint main() {\n    int n, q;\n    kin >> n >> q;\n\
      \    using M = kk2::monoid::Affine<kk2::mont998>;\n    using RM = kk2::monoid::ReverseOp<M>;\n\
      \    vc<RM> a(n);\n    kin >> a;\n    kk2::SegmentTree<RM> seg(a);\n\n    rep(q)\
      \ {\n        int t;\n        kin >> t;\n        if (t == 0) {\n            int\
      \ p;\n            kk2::mont998 c, d;\n            kin >> p >> c >> d;\n    \
      \        seg.set(p, c, d);\n        }\n        if (t == 1) {\n            int\
      \ l, r;\n            kk2::mont998 x;\n            kin >> l >> r >> x;\n    \
      \        kout << seg.prod(l, r).eval(x) << \"\\n\";\n        }\n    }\n\n  \
      \  return 0;\n}\n"
    name: bundled
  isFailed: false
  isVerificationFile: true
  path: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases:
  - elapsed: 0.002587558000016088
    environment: g++
    memory: 3.728
    name: example_00
    status: AC
  - elapsed: 0.8360203750000039
    environment: g++
    memory: 15.78
    name: max_random_00
    status: AC
  - elapsed: 0.8723754309999947
    environment: g++
    memory: 15.78
    name: max_random_01
    status: AC
  - elapsed: 0.8899967330000038
    environment: g++
    memory: 15.784
    name: max_random_02
    status: AC
  - elapsed: 0.8267382699999928
    environment: g++
    memory: 15.812
    name: max_random_03
    status: AC
  - elapsed: 0.7920736049999846
    environment: g++
    memory: 15.776
    name: max_random_04
    status: AC
  - elapsed: 0.6171213890000047
    environment: g++
    memory: 14.996
    name: random_00
    status: AC
  - elapsed: 0.6667168060000108
    environment: g++
    memory: 15.464
    name: random_01
    status: AC
  - elapsed: 0.39485040600001753
    environment: g++
    memory: 5.088
    name: random_02
    status: AC
  - elapsed: 0.1525136570000143
    environment: g++
    memory: 15.064
    name: random_03
    status: AC
  - elapsed: 0.2070249610000019
    environment: g++
    memory: 14.096
    name: random_04
    status: AC
  - elapsed: 0.0026047489999996287
    environment: g++
    memory: 3.836
    name: small_00
    status: AC
  - elapsed: 0.002233437000001004
    environment: g++
    memory: 3.704
    name: small_01
    status: AC
  - elapsed: 0.002203823000002103
    environment: g++
    memory: 3.824
    name: small_02
    status: AC
  - elapsed: 0.0022131970000032197
    environment: g++
    memory: 3.824
    name: small_03
    status: AC
  - elapsed: 0.0022946210000043266
    environment: g++
    memory: 3.828
    name: small_04
    status: AC
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
layout: document
---
