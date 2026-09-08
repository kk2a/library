---
data:
  attributes:
    STANDALONE: ''
    links: []
  dependencies:
  - files:
    - filename: add_sumwithsize.hpp
      icon: LIBRARY_ALL_AC
      path: math/action/add_sumwithsize.hpp
    - filename: affine_sumwithsize.hpp
      icon: LIBRARY_ALL_AC
      path: math/action/affine_sumwithsize.hpp
    - filename: add.hpp
      icon: LIBRARY_ALL_AC
      path: math/group/add.hpp
    - filename: sum_with_size.hpp
      icon: LIBRARY_ALL_AC
      path: math/group/sum_with_size.hpp
    - filename: affine.hpp
      icon: LIBRARY_ALL_AC
      path: math/monoid/affine.hpp
    - filename: min.hpp
      icon: LIBRARY_ALL_AC
      path: math/monoid/min.hpp
    - filename: mont.hpp
      icon: LIBRARY_ALL_AC
      path: modint/mont.hpp
    - filename: lazy.hpp
      icon: LIBRARY_ALL_AC
      path: segment_tree/lazy.hpp
    - filename: seg.hpp
      icon: LIBRARY_ALL_AC
      path: segment_tree/seg.hpp
    - filename: algebra.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/algebra.hpp
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
  - math/action/add_sumwithsize.hpp
  - math/action/affine_sumwithsize.hpp
  - math/group/add.hpp
  - math/group/sum_with_size.hpp
  - math/monoid/affine.hpp
  - math/monoid/min.hpp
  - modint/mont.hpp
  - segment_tree/lazy.hpp
  - segment_tree/seg.hpp
  - type_traits/algebra.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "// competitive-verifier: STANDALONE\n\n#include \"../../../../type_traits/algebra.hpp\"\
      \n\n#include \"../../../../math/action/add_sumwithsize.hpp\"\n#include \"../../../../math/action/affine_sumwithsize.hpp\"\
      \n#include \"../../../../math/group/add.hpp\"\n#include \"../../../../math/monoid/affine.hpp\"\
      \n#include \"../../../../math/monoid/min.hpp\"\n#include \"../../../../modint/mont.hpp\"\
      \n#include \"../../../../segment_tree/lazy.hpp\"\n#include \"../../../../segment_tree/seg.hpp\"\
      \n\nstruct CustomMonoid {\n    int value;\n\n    CustomMonoid(int value_ = 0)\
      \ : value(value_) {}\n\n    static CustomMonoid op(const CustomMonoid &l, const\
      \ CustomMonoid &r) {\n        return CustomMonoid(l.value + r.value);\n    }\n\
      \n    static CustomMonoid unit() { return CustomMonoid(0); }\n};\n\nstruct CustomGroup\
      \ {\n    int value;\n\n    CustomGroup(int value_ = 0) : value(value_) {}\n\n\
      \    static CustomGroup op(const CustomGroup &l, const CustomGroup &r) {\n \
      \       return CustomGroup(l.value + r.value);\n    }\n\n    static CustomGroup\
      \ unit() { return CustomGroup(0); }\n    static CustomGroup inv(const CustomGroup\
      \ &x) { return CustomGroup(-x.value); }\n};\n\nstruct CustomAction {\n    using\
      \ S = CustomMonoid;\n\n    struct Add {\n        int value;\n        Add(int\
      \ value_ = 0) : value(value_) {}\n        static Add op(const Add &l, const\
      \ Add &r) { return Add(l.value + r.value); }\n        static Add unit() { return\
      \ Add(0); }\n    };\n\n    using A = Add;\n\n    static S act(const A &f, const\
      \ S &x) { return S(x.value + f.value); }\n};\n\nstruct MissingUnit {\n    static\
      \ MissingUnit op(const MissingUnit &, const MissingUnit &) { return {}; }\n\
      };\n\nstruct MissingAction {\n    using S = CustomMonoid;\n    using A = CustomGroup;\n\
      };\n\nusing Add = kk2::group::Add<int>;\nusing Min = kk2::monoid::Min<int>;\n\
      using Affine = kk2::monoid::Affine<kk2::mont998>;\nusing SumAction = kk2::action::AddSumWithSize<int,\
      \ int>;\nusing AffineAction = kk2::action::AffineSumWithSize<int, int>;\n\n\
      static_assert(kk2::algebra::Monoid<CustomMonoid>);\nstatic_assert(kk2::algebra::Group<CustomGroup>);\n\
      static_assert(kk2::algebra::Action<CustomAction>);\nstatic_assert(!kk2::algebra::Monoid<MissingUnit>);\n\
      static_assert(!kk2::algebra::Action<MissingAction>);\nstatic_assert(kk2::algebra::Semigroup<Add>);\n\
      static_assert(kk2::algebra::Monoid<Add>);\nstatic_assert(kk2::algebra::Group<Add>);\n\
      static_assert(kk2::algebra::CommutativeGroup<Add>);\nstatic_assert(kk2::algebra::CommutativeMonoid<Min>);\n\
      static_assert(kk2::algebra::Monoid<Affine>);\nstatic_assert(kk2::algebra::Group<Affine>);\n\
      static_assert(kk2::algebra::Action<SumAction>);\nstatic_assert(kk2::algebra::Action<AffineAction>);\n\
      \nint main() {\n    kk2::SegmentTree<CustomMonoid> seg(std::vector<CustomMonoid>{{1},\
      \ {2}});\n    kk2::LazySegmentTree<CustomAction> lazy(std::vector<CustomMonoid>{{1},\
      \ {2}});\n    return seg.all_prod().value == 3 && lazy.all_prod().value == 3\
      \ ? 0 : 1;\n}\n"
    name: default
  - code: "#line 1 \"verify/unit_test/type_traits/algebra/algebra.test.cpp\"\n// competitive-verifier:\
      \ STANDALONE\n\n#line 1 \"type_traits/algebra.hpp\"\n\n\n\n#include <concepts>\n\
      \nnamespace kk2 {\n\nnamespace algebra {\n\n// These concepts describe the static\
      \ interface expected by the library.\n// Algebraic laws such as associativity\
      \ cannot be checked by the type system.\n//\n// A user-defined monoid therefore\
      \ needs only:\n//\n//   struct MyMonoid {\n//       static MyMonoid op(const\
      \ MyMonoid &, const MyMonoid &);\n//       static MyMonoid unit();\n//   };\n\
      //\n// The return types are intentionally exact, so a typo such as returning\
      \ the\n// underlying scalar instead of MyMonoid is diagnosed at the concept\
      \ boundary.\ntemplate <class T>\nconcept Semigroup = requires(const T &x, const\
      \ T &y) {\n    { T::op(x, y) } -> std::same_as<T>;\n};\n\ntemplate <class T>\n\
      concept Monoid = Semigroup<T> && requires {\n    { T::unit() } -> std::same_as<T>;\n\
      };\n\ntemplate <class T>\nconcept Group = Monoid<T> && requires(const T &x)\
      \ {\n    { T::inv(x) } -> std::same_as<T>;\n};\n\ntemplate <class T>\nconcept\
      \ CommutativeMonoid = Monoid<T> && requires {\n    { T::commutative } -> std::convertible_to<bool>;\n\
      } && bool(T::commutative);\n\ntemplate <class T>\nconcept CommutativeGroup =\
      \ Group<T> && requires {\n    { T::commutative } -> std::convertible_to<bool>;\n\
      } && bool(T::commutative);\n\n// An action specification owns the pair of algebraic\
      \ types and the mapping\n// between them. It is the interface required by lazy\
      \ propagation structures.\ntemplate <class T>\nconcept Action =\n    requires\
      \ {\n        typename T::A;\n        typename T::S;\n    } && Monoid<typename\
      \ T::A> && Monoid<typename T::S>\n    && requires(const typename T::A &f, const\
      \ typename T::S &x) {\n           { T::act(f, x) } -> std::same_as<typename\
      \ T::S>;\n       };\n\n} // namespace algebra\n\n} // namespace kk2\n\n\n#line\
      \ 4 \"verify/unit_test/type_traits/algebra/algebra.test.cpp\"\n\n#line 1 \"\
      math/action/add_sumwithsize.hpp\"\n\n\n\n#line 1 \"math/group/add.hpp\"\n\n\n\
      \n#line 1 \"type_traits/io.hpp\"\n\n\n\n#line 5 \"type_traits/io.hpp\"\n#include\
      \ <fstream>\n#include <istream>\n#include <ostream>\n#include <type_traits>\n\
      \nnamespace kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct\
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
      \n} // namespace kk2\n\n\n#line 5 \"math/group/add.hpp\"\n\nnamespace kk2 {\n\
      \nnamespace group {\n\ntemplate <class S> struct Add {\n    static constexpr\
      \ bool commutative = true;\n    using M = Add;\n    S a;\n\n    Add() : a(S())\
      \ {}\n    Add(S a_) : a(a_) {}\n    operator S() const { return a; }\n    inline\
      \ static M op(M l, M r) { return M(l.a + r.a); }\n    inline static M inv(M\
      \ x) { return M(-x.a); }\n    inline static M unit() { return M(); }\n    bool\
      \ operator==(const M &rhs) const { return a == rhs.a; }\n    bool operator!=(const\
      \ M &rhs) const { return a != rhs.a; }\n\n    template <OutputStream OStream>\
      \ friend OStream &operator<<(OStream &os, const M &x) {\n        return os <<\
      \ x.a;\n    }\n\n    template <InputStream IStream> friend IStream &operator>>(IStream\
      \ &is, M &x) {\n        return is >> x.a;\n    }\n};\n\n} // namespace group\n\
      \n} // namespace kk2\n\n\n#line 1 \"math/group/sum_with_size.hpp\"\n\n\n\n#line\
      \ 5 \"math/group/sum_with_size.hpp\"\n\nnamespace kk2 {\n\nnamespace group {\n\
      \ntemplate <class S, class T = S> struct SumWithSize {\n    static constexpr\
      \ bool commutative = true;\n    using M = SumWithSize;\n    S a;\n    T size;\n\
      \n    SumWithSize() : a(S()), size(0) {}\n    SumWithSize(S a_, S size_ = T(1))\
      \ : a(a_), size(size_) {}\n    operator S() const { return a; }\n    inline\
      \ static M op(M l, M r) { return M(l.a + r.a, l.size + r.size); }\n    inline\
      \ static M inv(M x) { return M(-x.a, -x.size); }\n    inline static M unit()\
      \ { return M(); }\n    bool operator==(const M &rhs) const { return a == rhs.a\
      \ and size == rhs.size; }\n    bool operator!=(const M &rhs) const { return\
      \ a != rhs.a or size != rhs.size; }\n\n    template <OutputStream OStream> friend\
      \ OStream &operator<<(OStream &os, const M &x) {\n        return os << x.a <<\
      \ \" \" << x.size;\n    }\n\n    template <InputStream IStream> friend IStream\
      \ &operator>>(IStream &is, M &x) {\n        is >> x.a;\n        x.size = T(1);\n\
      \        return is;\n    }\n};\n\n} // namespace group\n\n} // namespace kk2\n\
      \n\n#line 6 \"math/action/add_sumwithsize.hpp\"\n\nnamespace kk2 {\n\nnamespace\
      \ action {\n\ntemplate <class T, class U> struct AddSumWithSize {\n    using\
      \ A = group::Add<T>;\n    using S = group::SumWithSize<T, U>;\n\n    inline\
      \ static S act(A f, S x) { return S(x.a + f.a * x.size, x.size); }\n};\n\n}\
      \ // namespace action\n\n} // namespace kk2\n\n\n#line 1 \"math/action/affine_sumwithsize.hpp\"\
      \n\n\n\n#line 1 \"math/monoid/affine.hpp\"\n\n\n\n#line 5 \"math/monoid/affine.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace monoid {\n\ntemplate <class S> struct Affine\
      \ {\n    static constexpr bool commutative = false;\n    using M = Affine;\n\
      \    S a, b; // x \\mapsto ax + b\n\n    Affine() : a(S(1)), b(S(0)){};\n  \
      \  Affine(S a, S b) : a(a), b(b) {}\n    inline S eval(S x) const { return a\
      \ * x + b; }\n    // l \\circ r\n    inline static M op(M l, M r) { return M(l.a\
      \ * r.a, l.a * r.b + l.b); }\n    inline static M unit() { return M(); }\n \
      \   inline static M inv(M f) { return M(S(1) / f.a, -f.b / f.a); }\n    bool\
      \ operator==(const M &rhs) const { return a == rhs.a and b == rhs.b; }\n   \
      \ bool operator!=(const M &rhs) const { return a != rhs.a or b != rhs.b; }\n\
      \n    template <OutputStream OStream> friend OStream &operator<<(OStream &os,\
      \ const M &x) {\n        return os << x.a << \" \" << x.b;\n    }\n\n    template\
      \ <InputStream IStream> friend IStream &operator>>(IStream &is, M &x) {\n  \
      \      return is >> x.a >> x.b;\n    }\n};\n\n} // namespace monoid\n\n} //\
      \ namespace kk2\n\n\n#line 6 \"math/action/affine_sumwithsize.hpp\"\n\nnamespace\
      \ kk2 {\n\nnamespace action {\n\ntemplate <class T, class U> struct AffineSumWithSize\
      \ {\n    using A = monoid::Affine<T>;\n    using S = group::SumWithSize<T, U>;\n\
      \n    inline static S act(A f, S x) { return S(f.a * x.a + f.b * x.size, x.size);\
      \ }\n};\n\n} // namespace action\n\n} // namespace kk2\n\n\n#line 1 \"math/monoid/min.hpp\"\
      \n\n\n\n#include <functional>\n\n#line 7 \"math/monoid/min.hpp\"\n\nnamespace\
      \ kk2 {\n\nnamespace monoid {\n\ntemplate <class S, class Compare = std::less<S>>\
      \ struct Min {\n    static constexpr bool commutative = true;\n    using M =\
      \ Min;\n    S a;\n    bool is_unit;\n\n    Min() : a(S()), is_unit(true) {}\n\
      \    Min(S a_) : a(a_), is_unit(false) {}\n    operator S() const { return a;\
      \ }\n\n    inline static M op(M l, M r) {\n        if (l.is_unit or r.is_unit)\
      \ return l.is_unit ? r : l;\n        return Compare{}(l.a, r.a) ? l : r;\n \
      \   }\n\n    inline static M unit() { return M(); }\n\n    bool operator==(const\
      \ M &rhs) const {\n        return is_unit == rhs.is_unit and (is_unit or a ==\
      \ rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const {\n        return\
      \ is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n    }\n\n    template\
      \ <OutputStream OStream> friend OStream &operator<<(OStream &os, const M &x)\
      \ {\n        if (x.is_unit) os << \"inf\";\n        else os << x.a;\n      \
      \  return os;\n    }\n\n    template <InputStream IStream> friend IStream &operator>>(IStream\
      \ &is, M &x) {\n        is >> x.a;\n        x.is_unit = false;\n        return\
      \ is;\n    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\n\n#line 1\
      \ \"modint/mont.hpp\"\n\n\n\n#include <cassert>\n#include <cstdint>\n#include\
      \ <iostream>\n#line 8 \"modint/mont.hpp\"\n\n#line 1 \"type_traits/integral.hpp\"\
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
      \ namespace kk2\n\n\n#line 1 \"segment_tree/lazy.hpp\"\n\n\n\n#line 5 \"segment_tree/lazy.hpp\"\
      \n#include <vector>\n\n#line 8 \"segment_tree/lazy.hpp\"\n\nnamespace kk2 {\n\
      \ntemplate <algebra::Action Action> struct LazySegmentTree {\n    using S =\
      \ typename Action::S;\n    using F = typename Action::A;\n\n  public:\n    LazySegmentTree()\
      \ : LazySegmentTree(0) {}\n\n    LazySegmentTree(int n) : _n(n) {\n        log\
      \ = 0;\n        while ((1ll << log) < _n) log++;\n        size = 1 << log;\n\
      \        d = std::vector<S>(2 * size, S::unit());\n        lz = std::vector<F>(size,\
      \ F::unit());\n    }\n\n    template <class... Args>\n    LazySegmentTree(int\
      \ n, Args... args) : LazySegmentTree(std::vector<S>(n, S(args...))) {}\n\n \
      \   LazySegmentTree(const std::vector<S> &v) : _n(int(v.size())) {\n       \
      \ log = 0;\n        while ((1ll << log) < _n) log++;\n        size = 1 << log;\n\
      \        d = std::vector<S>(2 * size, S::unit());\n        lz = std::vector<F>(size,\
      \ F::unit());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n  \
      \      build();\n    }\n\n    void build() {\n        assert(!is_built);\n \
      \       is_built = true;\n        for (int i = size - 1; i >= 1; i--) update(i);\n\
      \    }\n\n    template <class... Args> void init_set(int p, Args... args) {\n\
      \        assert(0 <= p && p < _n);\n        assert(!is_built);\n        d[p\
      \ + size] = S(args...);\n    }\n\n    using Monoid = S;\n    static S Op(S l,\
      \ S r) { return S::op(l, r); }\n    static S MonoidUnit() { return S::unit();\
      \ }\n\n    using Hom = F;\n    static S Map(F f, S x) { return Action::act(f,\
      \ x); }\n    static F Composition(F l, F r) { return F::op(l, r); }\n    static\
      \ F HomUnit() { return F::unit(); }\n\n    template <class... Args> void set(int\
      \ p, Args... args) {\n        assert(0 <= p && p < _n);\n        assert(is_built);\n\
      \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n\
      \        d[p] = S(args...);\n        for (int i = 1; i <= log; i++) update(p\
      \ >> i);\n    }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n \
      \       assert(is_built);\n        p += size;\n        for (int i = log; i >=\
      \ 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    S prod(int l, int\
      \ r) {\n        assert(0 <= l && l <= r && r <= _n);\n        assert(is_built);\n\
      \        if (l == r) return S::unit();\n        l += size;\n        r += size;\n\
      \        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
      \ l) push(l >> i);\n            if (((r >> i) << i) != r) push(r >> i);\n  \
      \      }\n        S sml = S::unit(), smr = S::unit();\n        while (l < r)\
      \ {\n            if (l & 1) sml = S::op(sml, d[l++]);\n            if (r & 1)\
      \ smr = S::op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n  \
      \      }\n        return S::op(sml, smr);\n    }\n\n    S all_prod() {\n   \
      \     assert(is_built);\n        return d[1];\n    }\n\n    template <class...\
      \ Args> void apply_point(int p, Args... args) {\n        assert(0 <= p && p\
      \ < _n);\n        assert(is_built);\n        p += size;\n        for (int i\
      \ = log; i >= 1; i--) push(p >> i);\n        d[p] = Action::act(F(args...),\
      \ d[p]);\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n\
      \    template <class... Args> void apply_range(int l, int r, Args... args) {\n\
      \        assert(0 <= l && l <= r && r <= _n);\n        assert(is_built);\n \
      \       if (l == r) return;\n        F f = F(args...);\n        l += size;\n\
      \        r += size;\n        for (int i = log; i >= 1; i--) {\n            if\
      \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
      \ push((r - 1) >> i);\n        }\n        {\n            int l2 = l, r2 = r;\n\
      \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
      \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n \
      \               r >>= 1;\n            }\n            l = l2;\n            r\
      \ = r2;\n        }\n        for (int i = 1; i <= log; i++) {\n            if\
      \ (((l >> i) << i) != l) update(l >> i);\n            if (((r >> i) << i) !=\
      \ r) update((r - 1) >> i);\n        }\n    }\n\n    template <bool (*g)(S)>\
      \ int max_right(int l) {\n        return max_right(l, [](S x) { return g(x);\
      \ });\n    }\n\n    template <class G> int max_right(int l, G g) {\n       \
      \ assert(0 <= l && l <= _n);\n        assert(g(S::unit()));\n        assert(is_built);\n\
      \        if (l == _n) return _n;\n        l += size;\n        for (int i = log;\
      \ i >= 1; i--) push(l >> i);\n        S sm = S::unit();\n        do {\n    \
      \        while (l % 2 == 0) l >>= 1;\n            if (!g(S::op(sm, d[l]))) {\n\
      \                while (l < size) {\n                    push(l);\n        \
      \            l = 2 * l;\n                    if (g(S::op(sm, d[l]))) {\n   \
      \                     sm = S::op(sm, d[l]);\n                        l++;\n\
      \                    }\n                }\n                return l - size;\n\
      \            }\n            sm = S::op(sm, d[l]);\n            l++;\n      \
      \  } while ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool\
      \ (*g)(S)> int min_left(int r) {\n        return min_left(r, [](S x) { return\
      \ g(x); });\n    }\n\n    template <class G> int min_left(int r, G g) {\n  \
      \      assert(0 <= r && r <= _n);\n        assert(g(S::unit()));\n        assert(is_built);\n\
      \        if (r == 0) return 0;\n        r += size;\n        for (int i = log;\
      \ i >= 1; i--) push((r - 1) >> i);\n        S sm = S::unit();\n        do {\n\
      \            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n         \
      \   if (!g(S::op(d[r], sm))) {\n                while (r < size) {\n       \
      \             push(r);\n                    r = 2 * r + 1;\n               \
      \     if (g(S::op(d[r], sm))) {\n                        sm = S::op(d[r], sm);\n\
      \                        r--;\n                    }\n                }\n  \
      \              return r + 1 - size;\n            }\n            sm = S::op(d[r],\
      \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n\
      \    int _n, size, log;\n    std::vector<S> d;\n    std::vector<F> lz;\n   \
      \ bool is_built = false;\n\n    void update(int k) { d[k] = S::op(d[2 * k],\
      \ d[2 * k + 1]); }\n\n    void all_apply(int k, const F &f) {\n        d[k]\
      \ = Action::act(f, d[k]);\n        if (k < size) lz[k] = F::op(f, lz[k]);\n\
      \    }\n\n    void push(int k) {\n        all_apply(2 * k, lz[k]);\n       \
      \ all_apply(2 * k + 1, lz[k]);\n        lz[k] = F::unit();\n    }\n};\n\n} //\
      \ namespace kk2\n\n\n#line 1 \"segment_tree/seg.hpp\"\n\n\n\n#line 6 \"segment_tree/seg.hpp\"\
      \n\n#line 8 \"segment_tree/seg.hpp\"\n\nnamespace kk2 {\n\ntemplate <algebra::Monoid\
      \ M> struct SegmentTree {\n  public:\n    SegmentTree() : SegmentTree(0) {}\n\
      \n    SegmentTree(int n) : _n(n) {\n        log = 0;\n        while ((1U <<\
      \ log) < (unsigned int)(_n)) log++;\n        size = 1 << log;\n        d = std::vector<M>(2\
      \ * size, M::unit());\n    }\n\n    template <class... Args>\n    SegmentTree(int\
      \ n, Args... args) : SegmentTree(std::vector<M>(n, M(args...))) {}\n\n    SegmentTree(const\
      \ std::vector<M> &v) : _n(int(v.size())) {\n        log = 0;\n        while\
      \ ((1U << log) < (unsigned int)(_n)) log++;\n        size = 1 << log;\n    \
      \    d = std::vector<M>(2 * size, M::unit());\n        for (int i = 0; i < _n;\
      \ i++) d[size + i] = v[i];\n        build();\n    }\n\n    void build() {\n\
      \        assert(!is_built);\n        is_built = true;\n        for (int i =\
      \ size - 1; i >= 1; i--) update(i);\n    }\n\n    template <class... Args> void\
      \ init_set(int p, Args... args) {\n        assert(0 <= p && p < _n);\n     \
      \   assert(!is_built);\n        d[p + size] = M(args...);\n    }\n\n    using\
      \ Monoid = M;\n\n    static M Op(M l, M r) { return M::op(l, r); }\n\n    static\
      \ M MonoidUnit() { return M::unit(); }\n\n    template <class... Args> void\
      \ set(int p, Args... args) {\n        assert(0 <= p && p < _n);\n        assert(is_built);\n\
      \        p += size;\n        d[p] = M(args...);\n        for (int i = 1; i <=\
      \ log; i++) update(p >> i);\n    }\n\n    M get(int p) {\n        assert(0 <=\
      \ p && p < _n);\n        assert(is_built);\n        return d[p + size];\n  \
      \  }\n\n    M prod(int l, int r) {\n        assert(0 <= l && l <= r && r <=\
      \ _n);\n        assert(is_built);\n        M sml = M::unit(), smr = M::unit();\n\
      \        l += size;\n        r += size;\n\n        while (l < r) {\n       \
      \     if (l & 1) sml = M::op(sml, d[l++]);\n            if (r & 1) smr = M::op(d[--r],\
      \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
      \ M::op(sml, smr);\n    }\n\n    M all_prod() {\n        assert(is_built);\n\
      \        return d[1];\n    }\n\n    template <bool (*f)(M)> int max_right(int\
      \ l) {\n        return max_right(l, [](M x) { return f(x); });\n    }\n\n  \
      \  template <class F> int max_right(int l, F f) {\n        assert(0 <= l &&\
      \ l <= _n);\n        assert(f(M::unit()));\n        assert(is_built);\n    \
      \    if (l == _n) return _n;\n        l += size;\n        M sm = M::unit();\n\
      \        do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(M::op(sm,\
      \ d[l]))) {\n                while (l < size) {\n                    l = (2\
      \ * l);\n                    if (f(M::op(sm, d[l]))) {\n                   \
      \     sm = M::op(sm, d[l]);\n                        l++;\n                \
      \    }\n                }\n                return l - size;\n            }\n\
      \            sm = M::op(sm, d[l]);\n            l++;\n        } while ((l &\
      \ -l) != l);\n        return _n;\n    }\n\n    template <bool (*f)(M)> int min_left(int\
      \ r) {\n        return min_left(r, [](M x) { return f(x); });\n    }\n\n   \
      \ template <class F> int min_left(int r, F f) {\n        assert(0 <= r && r\
      \ <= _n);\n        assert(f(M::unit()));\n        assert(is_built);\n      \
      \  if (r == 0) return 0;\n        r += size;\n        M sm = M::unit();\n  \
      \      do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n\
      \            if (!f(M::op(d[r], sm))) {\n                while (r < size) {\n\
      \                    r = (2 * r + 1);\n                    if (f(M::op(d[r],\
      \ sm))) {\n                        sm = M::op(d[r], sm);\n                 \
      \       r--;\n                    }\n                }\n                return\
      \ r + 1 - size;\n            }\n            sm = M::op(d[r], sm);\n        }\
      \ while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n    int _n,\
      \ size, log;\n    std::vector<M> d;\n    bool is_built = false;\n\n    void\
      \ update(int k) { d[k] = M::op(d[2 * k], d[2 * k + 1]); }\n};\n\n} // namespace\
      \ kk2\n\n\n#line 13 \"verify/unit_test/type_traits/algebra/algebra.test.cpp\"\
      \n\nstruct CustomMonoid {\n    int value;\n\n    CustomMonoid(int value_ = 0)\
      \ : value(value_) {}\n\n    static CustomMonoid op(const CustomMonoid &l, const\
      \ CustomMonoid &r) {\n        return CustomMonoid(l.value + r.value);\n    }\n\
      \n    static CustomMonoid unit() { return CustomMonoid(0); }\n};\n\nstruct CustomGroup\
      \ {\n    int value;\n\n    CustomGroup(int value_ = 0) : value(value_) {}\n\n\
      \    static CustomGroup op(const CustomGroup &l, const CustomGroup &r) {\n \
      \       return CustomGroup(l.value + r.value);\n    }\n\n    static CustomGroup\
      \ unit() { return CustomGroup(0); }\n    static CustomGroup inv(const CustomGroup\
      \ &x) { return CustomGroup(-x.value); }\n};\n\nstruct CustomAction {\n    using\
      \ S = CustomMonoid;\n\n    struct Add {\n        int value;\n        Add(int\
      \ value_ = 0) : value(value_) {}\n        static Add op(const Add &l, const\
      \ Add &r) { return Add(l.value + r.value); }\n        static Add unit() { return\
      \ Add(0); }\n    };\n\n    using A = Add;\n\n    static S act(const A &f, const\
      \ S &x) { return S(x.value + f.value); }\n};\n\nstruct MissingUnit {\n    static\
      \ MissingUnit op(const MissingUnit &, const MissingUnit &) { return {}; }\n\
      };\n\nstruct MissingAction {\n    using S = CustomMonoid;\n    using A = CustomGroup;\n\
      };\n\nusing Add = kk2::group::Add<int>;\nusing Min = kk2::monoid::Min<int>;\n\
      using Affine = kk2::monoid::Affine<kk2::mont998>;\nusing SumAction = kk2::action::AddSumWithSize<int,\
      \ int>;\nusing AffineAction = kk2::action::AffineSumWithSize<int, int>;\n\n\
      static_assert(kk2::algebra::Monoid<CustomMonoid>);\nstatic_assert(kk2::algebra::Group<CustomGroup>);\n\
      static_assert(kk2::algebra::Action<CustomAction>);\nstatic_assert(!kk2::algebra::Monoid<MissingUnit>);\n\
      static_assert(!kk2::algebra::Action<MissingAction>);\nstatic_assert(kk2::algebra::Semigroup<Add>);\n\
      static_assert(kk2::algebra::Monoid<Add>);\nstatic_assert(kk2::algebra::Group<Add>);\n\
      static_assert(kk2::algebra::CommutativeGroup<Add>);\nstatic_assert(kk2::algebra::CommutativeMonoid<Min>);\n\
      static_assert(kk2::algebra::Monoid<Affine>);\nstatic_assert(kk2::algebra::Group<Affine>);\n\
      static_assert(kk2::algebra::Action<SumAction>);\nstatic_assert(kk2::algebra::Action<AffineAction>);\n\
      \nint main() {\n    kk2::SegmentTree<CustomMonoid> seg(std::vector<CustomMonoid>{{1},\
      \ {2}});\n    kk2::LazySegmentTree<CustomAction> lazy(std::vector<CustomMonoid>{{1},\
      \ {2}});\n    return seg.all_prod().value == 3 && lazy.all_prod().value == 3\
      \ ? 0 : 1;\n}\n"
    name: bundled
  isFailed: false
  isVerificationFile: true
  path: verify/unit_test/type_traits/algebra/algebra.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases: []
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/type_traits/algebra/algebra.test.cpp
layout: document
---
