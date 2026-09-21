---
data:
  attributes:
    STANDALONE: ''
    links: []
  dependencies:
  - files:
    - filename: mod_sqrt.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/detail/mod_sqrt.hpp
    - filename: mod_sqrt.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/mod_sqrt.hpp
    - filename: pow_mod.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/pow_mod.hpp
    - filename: primitive_root.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/primitive_root.hpp
    - filename: modint.hpp
      icon: LIBRARY_ALL_AC
      path: modint/modint.hpp
    - filename: mont.hpp
      icon: LIBRARY_ALL_AC
      path: modint/mont.hpp
    - filename: mont_arb.hpp
      icon: LIBRARY_ALL_AC
      path: modint/mont_arb.hpp
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
  - math_mod/detail/mod_sqrt.hpp
  - math_mod/mod_sqrt.hpp
  - math_mod/pow_mod.hpp
  - math_mod/primitive_root.hpp
  - modint/modint.hpp
  - modint/mont.hpp
  - modint/mont_arb.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "// competitive-verifier: STANDALONE\n\n#include \"../../../math_mod/mod_sqrt.hpp\"\
      \n\n#include <cassert>\n\n#include \"../../../math_mod/detail/mod_sqrt.hpp\"\
      \n#include \"../../../modint/modint.hpp\"\n#include \"../../../modint/mont.hpp\"\
      \n\nnamespace {\n\ntemplate <class mint, bool ntt_friendly = false> void test_all_residues()\
      \ {\n    const int mod = mint::getmod();\n    for (int a = 0; a < mod; ++a)\
      \ {\n        const long long root = kk2::mod_sqrt_detail::mod_sqrt<ntt_friendly>(mint(a));\n\
      \        bool has_root = false;\n        for (int x = 0; x < mod; ++x) {\n \
      \           if (static_cast<long long>(x) * x % mod == a) {\n              \
      \  has_root = true;\n                break;\n            }\n        }\n    \
      \    assert((root != -1) == has_root);\n        if (root != -1) assert(root\
      \ * root % mod == a);\n\n        const long long generic_root = kk2::mod_sqrt(a,\
      \ mod);\n        assert((generic_root != -1) == has_root);\n        if (generic_root\
      \ != -1) assert(generic_root * generic_root % mod == a);\n    }\n}\n\n} // namespace\n\
      \nint main() {\n    test_all_residues<kk2::Mont<19>>();\n    test_all_residues<kk2::Mont<17>,\
      \ true>();\n    kk2::ModInt<0>::setmod(19);\n    test_all_residues<kk2::ModInt<0>>();\n\
      \n    using mint = kk2::mont998;\n    assert(kk2::mod_sqrt_detail::mod_sqrt<true>(mint(0))\
      \ == 0);\n    assert(kk2::mod_sqrt_detail::mod_sqrt<true>(mint(1)) == 1);\n\
      \    assert(kk2::mod_sqrt_detail::mod_sqrt<true>(mint(3)) == -1);\n    for (int\
      \ x = 2; x < 1000; ++x) {\n        const mint square = mint(x) * x;\n      \
      \  const long long root = kk2::mod_sqrt_detail::mod_sqrt<true>(square);\n  \
      \      assert(root != -1);\n        assert(mint(root) * root == square);\n \
      \   }\n}\n"
    name: default
  - code: "#line 1 \"verify/unit_test/math_mod/mod_sqrt.test.cpp\"\n// competitive-verifier:\
      \ STANDALONE\n\n#line 1 \"math_mod/mod_sqrt.hpp\"\n\n\n\n#include <cassert>\n\
      \n#line 1 \"modint/mont_arb.hpp\"\n\n\n\n#line 5 \"modint/mont_arb.hpp\"\n#include\
      \ <iostream>\n#include <utility>\n\n#line 1 \"type_traits/integral.hpp\"\n\n\
      \n\n#include <type_traits>\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate\
      \ <typename T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T,\
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
      \n} // namespace kk2\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <concepts>\n\
      #include <fstream>\n#include <istream>\n#include <ostream>\n#line 9 \"type_traits/io.hpp\"\
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
      \n} // namespace kk2\n\n\n#line 10 \"modint/mont_arb.hpp\"\n\nnamespace kk2\
      \ {\n\ntemplate <typename Int, typename UInt, typename Long, typename ULong,\
      \ int id>\nstruct ArbitraryLazyMontgomeryModIntBase {\n    using mint = ArbitraryLazyMontgomeryModIntBase;\n\
      \n    inline static UInt mod;\n    inline static UInt r;\n    inline static\
      \ UInt n2;\n    static constexpr int bit_length = sizeof(UInt) * 8;\n\n    static\
      \ UInt get_r() {\n        UInt ret = mod;\n        while (mod * ret != 1) ret\
      \ *= UInt(2) - mod * ret;\n        return ret;\n    }\n\n    static void setmod(UInt\
      \ m) {\n        assert(m < (UInt(1u) << (bit_length - 2)));\n        assert(m\
      \ & 1);\n        mod = m, n2 = -ULong(m) % m, r = get_r();\n    }\n\n    UInt\
      \ _v;\n\n    ArbitraryLazyMontgomeryModIntBase() : _v(0) {}\n\n    template\
      \ <Integral T>\n    ArbitraryLazyMontgomeryModIntBase(const T &b) : _v(reduce(ULong(b\
      \ % (Int)mod + mod) * n2)) {}\n\n    static UInt reduce(const ULong &b) {\n\
      \        return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n    }\n\
      \n    mint &operator+=(const mint &b) {\n        if (Int(_v += b._v - 2 * mod)\
      \ < 0) _v += 2 * mod;\n        return *this;\n    }\n\n    mint &operator-=(const\
      \ mint &b) {\n        if (Int(_v -= b._v) < 0) _v += 2 * mod;\n        return\
      \ *this;\n    }\n\n    mint &operator*=(const mint &b) {\n        _v = reduce(ULong(_v)\
      \ * b._v);\n        return *this;\n    }\n\n    mint &operator/=(const mint\
      \ &b) {\n        *this *= b.inv();\n        return *this;\n    }\n\n    mint\
      \ operator-() const { return mint(0) - mint(*this); }\n    mint operator+()\
      \ const { return mint(*this); }\n    friend mint operator+(const mint &a, const\
      \ mint &b) { return mint(a) += b; }\n    friend mint operator-(const mint &a,\
      \ const mint &b) { return mint(a) -= b; }\n    friend mint operator*(const mint\
      \ &a, const mint &b) { return mint(a) *= b; }\n    friend mint operator/(const\
      \ mint &a, const mint &b) { return mint(a) /= b; }\n\n    bool operator==(const\
      \ mint &b) const {\n        return (_v >= mod ? _v - mod : _v) == (b._v >= mod\
      \ ? b._v - mod : b._v);\n    }\n\n    bool operator!=(const mint &b) const {\n\
      \        return (_v >= mod ? _v - mod : _v) != (b._v >= mod ? b._v - mod : b._v);\n\
      \    }\n\n    template <class T> mint pow(T n) const {\n        mint ret(1),\
      \ mul(*this);\n        n %= (Long)getmod() - 1;\n        while (n > 0) {\n \
      \           if (n & 1) ret *= mul;\n            if (n >>= 1) mul *= mul;\n \
      \       }\n        return ret;\n    }\n\n    mint inv() const {\n        Int\
      \ s = getmod(), t = val(), m0 = 0, m1 = 1;\n        while (t) {\n          \
      \  Int u = s / t;\n            std::swap(s -= t * u, t);\n            std::swap(m0\
      \ -= m1 * u, m1);\n        }\n        if (m0 < 0) m0 += getmod();\n        return\
      \ mint(m0);\n    }\n\n    template <OutputStream OStream> friend OStream &operator<<(OStream\
      \ &os, const mint &x) {\n        return os << x.val();\n    }\n\n    template\
      \ <InputStream IStream> friend IStream &operator>>(IStream &is, mint &x) {\n\
      \        Long t;\n        is >> t;\n        x = mint(t);\n        return (is);\n\
      \    }\n\n    UInt val() const {\n        UInt ret = reduce(_v);\n        return\
      \ ret >= mod ? ret - mod : ret;\n    }\n\n    static UInt getmod() { return\
      \ mod; }\n};\n\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt =\n \
      \   ArbitraryLazyMontgomeryModIntBase<int, unsigned int, long long, unsigned\
      \ long long, id>;\n\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt64bit\
      \ =\n    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t,\
      \ __uint128_t, id>;\n\n} // namespace kk2\n\n\n#line 1 \"math_mod/detail/mod_sqrt.hpp\"\
      \n\n\n\n#line 1 \"math_mod/primitive_root.hpp\"\n\n\n\n#line 1 \"math_mod/pow_mod.hpp\"\
      \n\n\n\n#line 5 \"math_mod/pow_mod.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
      \ S, class T, class U> constexpr S pow_mod(T x, U n, T m) {\n    assert(n >=\
      \ 0);\n    if (m == 1) return S(0);\n    S _m = m, r = 1;\n    S y = x % _m;\n\
      \    if (y < 0) y += _m;\n    while (n) {\n        if (n & 1) r = (r * y) %\
      \ _m;\n        if (n >>= 1) y = (y * y) % _m;\n    }\n    return r;\n}\n\n}\
      \ // namespace kk2\n\n\n#line 5 \"math_mod/primitive_root.hpp\"\n\nnamespace\
      \ kk2 {\n\nconstexpr int primitive_root_constexpr(int m) {\n    if (m == 2)\
      \ return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049) return\
      \ 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return 3;\n\
      \    if (m == 1107296257) return 10;\n    int divs[20] = {};\n    divs[0] =\
      \ 2;\n    int cnt = 1;\n    int x = (m - 1) / 2;\n    while (x % 2 == 0) x /=\
      \ 2;\n    for (int i = 3; (long long)(i)*i <= x; i += 2) {\n        if (x %\
      \ i == 0) {\n            divs[cnt++] = i;\n            while (x % i == 0) {\
      \ x /= i; }\n        }\n    }\n    if (x > 1) { divs[cnt++] = x; }\n    for\
      \ (int g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i <\
      \ cnt; i++) {\n            if (pow_mod<long long>(g, (m - 1) / divs[i], m) ==\
      \ 1) {\n                ok = false;\n                break;\n            }\n\
      \        }\n        if (ok) return g;\n    }\n}\n\ntemplate <int m> static constexpr\
      \ int primitive_root = primitive_root_constexpr(m);\n\n} // namespace kk2\n\n\
      \n#line 5 \"math_mod/detail/mod_sqrt.hpp\"\n\nnamespace kk2::mod_sqrt_detail\
      \ {\n\ntemplate <class Mint> long long tonelli_shanks(const Mint &a, Mint z,\
      \ long long m, long long e) {\n    Mint x = a.pow((m - 1) / 2);\n    Mint y\
      \ = a * x * x;\n    x *= a;\n    while (y != Mint(1)) {\n        long long j\
      \ = 0;\n        Mint t = y;\n        while (t != Mint(1)) {\n            j++;\n\
      \            t *= t;\n        }\n        z = z.pow(1LL << (e - j - 1));\n  \
      \      x *= z;\n        z *= z;\n        y *= z;\n        e = j;\n    }\n  \
      \  return x.val();\n}\n\ntemplate <bool ntt_friendly = false, class mint> long\
      \ long mod_sqrt(const mint &a) {\n    const auto p = mint::getmod();\n    if\
      \ (a.val() < 2) return a.val();\n\n    // Euler's criterion\n    if (a.pow((p\
      \ - 1) / 2) != mint(1)) return -1;\n\n    mint b;\n    if constexpr (ntt_friendly)\
      \ {\n        b = primitive_root<mint::getmod()>;\n    } else {\n        // Find\
      \ a quadratic non-residue.\n        b = 1;\n        while (b.pow((p - 1) / 2)\
      \ == mint(1)) b += 1;\n    }\n\n    long long m = p - 1, e = 0;\n    while (m\
      \ % 2 == 0) m >>= 1, e++;\n\n    mint z = b.pow(m);\n    return tonelli_shanks(a,\
      \ z, m, e);\n}\n\n} // namespace kk2::mod_sqrt_detail\n\n\n#line 8 \"math_mod/mod_sqrt.hpp\"\
      \n\nnamespace kk2 {\n\n// ref: https://37zigen.com/tonelli-shanks-algorithm/\n\
      template <class T, class U> long long mod_sqrt(const T &a, const U &p) {\n \
      \   assert(0 <= a && a < p);\n    if (a < 2) return a;\n    using Mint = ArbitraryLazyMontgomeryModInt<54105064>;\n\
      \    Mint::setmod(p);\n    return mod_sqrt_detail::mod_sqrt(Mint(a));\n}\n\n\
      } // namespace kk2\n\n\n#line 4 \"verify/unit_test/math_mod/mod_sqrt.test.cpp\"\
      \n\n#line 6 \"verify/unit_test/math_mod/mod_sqrt.test.cpp\"\n\n#line 1 \"modint/modint.hpp\"\
      \n\n\n\n#line 8 \"modint/modint.hpp\"\n\n#line 11 \"modint/modint.hpp\"\n\n\
      namespace kk2 {\n\ntemplate <int p> struct ModInt {\n    using mint = ModInt;\n\
      \n  public:\n    static int Mod;\n\n    constexpr static unsigned int getmod()\
      \ {\n        if (p > 0) return p;\n        else return Mod;\n    }\n\n    static\
      \ void setmod(int Mod_) {\n        assert(1 <= Mod_);\n        Mod = Mod_;\n\
      \    }\n\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n\
      \        return x;\n    }\n\n    constexpr ModInt() : _v(0) {}\n\n    template\
      \ <Integral T> constexpr ModInt(T v) {\n        if constexpr (SignedIntegral<T>)\
      \ {\n            v = v % (long long)(getmod());\n            if (v < 0) v +=\
      \ getmod();\n            _v = v;\n        } else if constexpr (UnsignedIntegral<T>)\
      \ {\n            _v = v %= getmod();\n        } else {\n            ModInt();\n\
      \        }\n    }\n\n    unsigned int val() const { return _v; }\n\n    mint\
      \ &operator++() {\n        _v++;\n        if (_v == getmod()) _v = 0;\n    \
      \    return *this;\n    }\n\n    mint &operator--() {\n        if (_v == 0)\
      \ _v = getmod();\n        _v--;\n        return *this;\n    }\n\n    mint operator++(int)\
      \ {\n        mint result = *this;\n        ++*this;\n        return result;\n\
      \    }\n\n    mint operator--(int) {\n        mint result = *this;\n       \
      \ --*this;\n        return result;\n    }\n\n    mint &operator+=(const mint\
      \ &rhs) {\n        _v += rhs._v;\n        if (_v >= getmod()) _v -= getmod();\n\
      \        return *this;\n    }\n\n    mint &operator-=(const mint &rhs) {\n \
      \       _v += getmod() - rhs._v;\n        if (_v >= getmod()) _v -= getmod();\n\
      \        return *this;\n    }\n\n    mint &operator*=(const mint &rhs) {\n \
      \       unsigned long long z = _v;\n        z *= rhs._v;\n        z %= getmod();\n\
      \        _v = z;\n        return *this;\n    }\n\n    mint &operator/=(const\
      \ mint &rhs) { return *this = *this * rhs.inv(); }\n    mint operator+() const\
      \ { return *this; }\n    mint operator-() const { return mint() - *this; }\n\
      \    friend mint operator+(const mint &lhs, const mint &rhs) { return mint(lhs)\
      \ += rhs; }\n    friend mint operator-(const mint &lhs, const mint &rhs) { return\
      \ mint(lhs) -= rhs; }\n    friend mint operator*(const mint &lhs, const mint\
      \ &rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const mint &lhs,\
      \ const mint &rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
      \ mint &lhs, const mint &rhs) { return lhs._v == rhs._v; }\n    friend bool\
      \ operator!=(const mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }\n\
      \n    mint pow(long long n) const {\n        assert(0 <= n);\n        mint x\
      \ = *this, r = 1;\n        while (n) {\n            if (n & 1) r *= x;\n   \
      \         x *= x;\n            n >>= 1;\n        }\n        return r;\n    }\n\
      \n    mint inv() const {\n        long long s = getmod(), t = _v;\n        long\
      \ long m0 = 0, m1 = 1;\n\n        while (t) {\n            long long u = s /\
      \ t;\n            s -= t * u;\n            m0 -= m1 * u;\n\n            std::swap(s,\
      \ t);\n            std::swap(m0, m1);\n        }\n        if (m0 < 0) m0 +=\
      \ getmod() / s;\n        return m0;\n    }\n\n    template <OutputStream OStream>\
      \ friend OStream &operator<<(OStream &os, const mint &mint_) {\n        os <<\
      \ mint_._v;\n        return os;\n    }\n\n    template <InputStream IStream>\
      \ friend IStream &operator>>(IStream &is, mint &mint_) {\n        long long\
      \ x;\n        is >> x;\n        mint_ = mint(x);\n        return is;\n    }\n\
      \n  private:\n    unsigned int _v;\n};\n\ntemplate <int p> int ModInt<p>::Mod\
      \ = 998244353;\n\nusing mint998 = ModInt<998244353>;\nusing mint107 = ModInt<1000000007>;\n\
      \n} // namespace kk2\n\n\n#line 1 \"modint/mont.hpp\"\n\n\n\n#line 5 \"modint/mont.hpp\"\
      \n#include <cstdint>\n#line 8 \"modint/mont.hpp\"\n\n#line 11 \"modint/mont.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <int p> struct LazyMontgomeryModInt {\n    using\
      \ mint = LazyMontgomeryModInt;\n    using i32 = int32_t;\n    using i64 = int64_t;\n\
      \    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static constexpr\
      \ u32 get_r() {\n        u32 ret = p;\n        for (int i = 0; i < 4; ++i) ret\
      \ *= 2 - p * ret;\n        return ret;\n    }\n\n    static constexpr u32 r\
      \ = get_r();\n    static constexpr u32 n2 = -u64(p) % p;\n    static_assert(r\
      \ * p == 1, \"invalid, r * p != 1\");\n    static_assert(p < (1 << 30), \"invalid,\
      \ p >= 2 ^ 30\");\n    static_assert((p & 1) == 1, \"invalid, p % 2 == 0\");\n\
      \n    u32 _v;\n\n    constexpr LazyMontgomeryModInt() : _v(0) {}\n\n    template\
      \ <Integral T> constexpr LazyMontgomeryModInt(T b) : _v(reduce(u64(b % p + p)\
      \ * n2)) {}\n\n    static constexpr u32 reduce(const u64 &b) { return (b + u64(u32(b)\
      \ * u32(-r)) * p) >> 32; }\n    constexpr mint &operator++() { return *this\
      \ += 1; }\n    constexpr mint &operator--() { return *this -= 1; }\n\n    constexpr\
      \ mint operator++(int) {\n        mint ret = *this;\n        *this += 1;\n \
      \       return ret;\n    }\n\n    constexpr mint operator--(int) {\n       \
      \ mint ret = *this;\n        *this -= 1;\n        return ret;\n    }\n\n   \
      \ constexpr mint &operator+=(const mint &b) {\n        if (i32(_v += b._v -\
      \ 2 * p) < 0) _v += 2 * p;\n        return *this;\n    }\n\n    constexpr mint\
      \ &operator-=(const mint &b) {\n        if (i32(_v -= b._v) < 0) _v += 2 * p;\n\
      \        return *this;\n    }\n\n    constexpr mint &operator*=(const mint &b)\
      \ {\n        _v = reduce(u64(_v) * b._v);\n        return *this;\n    }\n\n\
      \    constexpr mint &operator/=(const mint &b) {\n        *this *= b.inv();\n\
      \        return *this;\n    }\n\n\n    constexpr bool operator==(const mint\
      \ &b) const {\n        return (_v >= p ? _v - p : _v) == (b._v >= p ? b._v -\
      \ p : b._v);\n    }\n\n    constexpr bool operator!=(const mint &b) const {\n\
      \        return (_v >= p ? _v - p : _v) != (b._v >= p ? b._v - p : b._v);\n\
      \    }\n\n    constexpr mint operator-() const { return mint() - mint(*this);\
      \ }\n    constexpr mint operator+() const { return mint(*this); }\n    friend\
      \ constexpr mint operator+(const mint &a, const mint &b) { return mint(a) +=\
      \ b; }\n    friend constexpr mint operator-(const mint &a, const mint &b) {\
      \ return mint(a) -= b; }\n    friend constexpr mint operator*(const mint &a,\
      \ const mint &b) { return mint(a) *= b; }\n    friend constexpr mint operator/(const\
      \ mint &a, const mint &b) { return mint(a) /= b; }\n\n    template <class T>\
      \ constexpr mint pow(T n) const {\n        mint ret(1), mul(*this);\n      \
      \  while (n > 0) {\n            if (n & 1) ret *= mul;\n            if (n >>=\
      \ 1) mul *= mul;\n        }\n        return ret;\n    }\n\n    constexpr mint\
      \ inv() const {\n        assert(*this != mint(0));\n        return pow(p - 2);\n\
      \    }\n\n    template <OutputStream OStream> friend OStream &operator<<(OStream\
      \ &os, const mint &x) {\n        return os << x.val();\n    }\n\n    template\
      \ <InputStream IStream> friend IStream &operator>>(IStream &is, mint &x) {\n\
      \        i64 t;\n        is >> t;\n        x = mint(t);\n        return (is);\n\
      \    }\n\n    constexpr u32 val() const {\n        u32 ret = reduce(_v);\n \
      \       return ret >= p ? ret - p : ret;\n    }\n\n    static constexpr u32\
      \ getmod() { return p; }\n};\n\ntemplate <int p> using Mont = LazyMontgomeryModInt<p>;\n\
      \nusing mont998 = Mont<998244353>;\nusing mont107 = Mont<1000000007>;\n\n} //\
      \ namespace kk2\n\n\n#line 10 \"verify/unit_test/math_mod/mod_sqrt.test.cpp\"\
      \n\nnamespace {\n\ntemplate <class mint, bool ntt_friendly = false> void test_all_residues()\
      \ {\n    const int mod = mint::getmod();\n    for (int a = 0; a < mod; ++a)\
      \ {\n        const long long root = kk2::mod_sqrt_detail::mod_sqrt<ntt_friendly>(mint(a));\n\
      \        bool has_root = false;\n        for (int x = 0; x < mod; ++x) {\n \
      \           if (static_cast<long long>(x) * x % mod == a) {\n              \
      \  has_root = true;\n                break;\n            }\n        }\n    \
      \    assert((root != -1) == has_root);\n        if (root != -1) assert(root\
      \ * root % mod == a);\n\n        const long long generic_root = kk2::mod_sqrt(a,\
      \ mod);\n        assert((generic_root != -1) == has_root);\n        if (generic_root\
      \ != -1) assert(generic_root * generic_root % mod == a);\n    }\n}\n\n} // namespace\n\
      \nint main() {\n    test_all_residues<kk2::Mont<19>>();\n    test_all_residues<kk2::Mont<17>,\
      \ true>();\n    kk2::ModInt<0>::setmod(19);\n    test_all_residues<kk2::ModInt<0>>();\n\
      \n    using mint = kk2::mont998;\n    assert(kk2::mod_sqrt_detail::mod_sqrt<true>(mint(0))\
      \ == 0);\n    assert(kk2::mod_sqrt_detail::mod_sqrt<true>(mint(1)) == 1);\n\
      \    assert(kk2::mod_sqrt_detail::mod_sqrt<true>(mint(3)) == -1);\n    for (int\
      \ x = 2; x < 1000; ++x) {\n        const mint square = mint(x) * x;\n      \
      \  const long long root = kk2::mod_sqrt_detail::mod_sqrt<true>(square);\n  \
      \      assert(root != -1);\n        assert(mint(root) * root == square);\n \
      \   }\n}\n"
    name: bundled
  isFailed: false
  isVerificationFile: true
  path: verify/unit_test/math_mod/mod_sqrt.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases: []
  timestamp: '2026-09-21 19:50:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math_mod/mod_sqrt.test.cpp
layout: document
---
