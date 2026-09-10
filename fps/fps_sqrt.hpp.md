---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: fps_sparsity_detector.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_sparsity_detector.hpp
    - filename: mod_sqrt.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/mod_sqrt.hpp
    - filename: mont_arb.hpp
      icon: LIBRARY_ALL_AC
      path: modint/mont_arb.hpp
    - filename: fps.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/fps.hpp
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: sparsity_performance.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_performance.test.cpp
    - filename: sparsity_small_performance.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_small_performance.test.cpp
    - filename: fps_sprase_sqrt.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_sprase_sqrt.test.cpp
    - filename: fps_sqrt.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_sqrt.test.cpp
    type: Verified with
  dependsOn:
  - fps/fps_sparsity_detector.hpp
  - math_mod/mod_sqrt.hpp
  - modint/mont_arb.hpp
  - type_traits/fps.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_FPS_FPS_SQRT_HPP\n#define KK2_FPS_FPS_SQRT_HPP 1\n\n#include\
      \ <cassert>\n\n#include \"../math_mod/mod_sqrt.hpp\"\n#include \"../type_traits/fps.hpp\"\
      \n#include \"fps_sparsity_detector.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
      \ FPS, class mint = typename FPS::value_type>\nFPS dense_sqrt(const FPS &f,\
      \ int deg = -1) {\n    if (deg == -1) deg = (int)f.size();\n    if ((int)f.size()\
      \ == 0) return FPS(deg, mint(0));\n    if (f[0] == mint(0)) {\n        for (int\
      \ i = 1; i < (int)f.size(); i++) {\n            if (f[i] != mint(0)) {\n   \
      \             if (i & 1) return {};\n                if (deg - i / 2 <= 0) break;\n\
      \                auto ret = dense_sqrt(f >> i, deg - i / 2);\n             \
      \   if (ret.empty()) return {};\n                ret = ret << (i / 2);\n   \
      \             if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n       \
      \         return ret;\n            }\n        }\n        return FPS(deg, mint(0));\n\
      \    }\n\n    long long sqr = mod_sqrt(f[0].val(), mint::getmod());\n    if\
      \ (sqr == -1) return {};\n    assert(sqr * sqr % mint::getmod() == f[0].val());\n\
      \    FPS ret = {mint(sqr)};\n    mint inv2 = mint(2).inv();\n    for (int i\
      \ = 1; i < deg; i <<= 1) {\n        ret = (ret + f.pre(i << 1).dense_mul(ret.dense_inv(i\
      \ << 1))) * inv2;\n    }\n    return ret.pre(deg);\n}\n\ntemplate <class FPS,\
      \ class mint = typename FPS::value_type>\nFPS sparse_sqrt(const FPS &f, int\
      \ deg = -1) {\n    // using mint = typename FPS::value_type;\n    if (deg ==\
      \ -1) deg = (int)f.size();\n    if ((int)f.size() == 0) return FPS(deg, mint(0));\n\
      \    if (f[0] == mint(0)) {\n        for (int i = 1; i < (int)f.size(); i++)\
      \ {\n            if (f[i] != mint(0)) {\n                if (i & 1) return {};\n\
      \                if (deg - i / 2 <= 0) break;\n                auto ret = sparse_sqrt(f\
      \ >> i, deg - i / 2);\n                if (ret.empty()) return {};\n       \
      \         ret = ret << (i / 2);\n                if ((int)ret.size() < deg)\
      \ ret.resize(deg, mint(0));\n                return ret;\n            }\n  \
      \      }\n        return FPS(deg, mint(0));\n    }\n    long long sqr = mod_sqrt(f[0].val(),\
      \ mint::getmod());\n    if (sqr == -1) return {};\n    return f.sparse_pow(((mint::getmod()\
      \ + 1) >> 1), deg) * mint(sqr).inv();\n}\n\ntemplate <class FPS, class mint\
      \ = typename FPS::value_type> FPS sqrt(const FPS &f, int deg = -1) {\n    if\
      \ (deg == -1) deg = (int)f.size();\n    if (!f.empty() && f[0] != mint(0)\n\
      \        && is_sparse_operation(\n            FPSOperation::SQRT, fps::NTTFriendlyFormalPowerSeries<FPS>,\
      \ f, FPS(), deg))\n        return sparse_sqrt(f, deg);\n    return dense_sqrt(f,\
      \ deg);\n}\n\n} // namespace kk2\n\n#endif // KK2_FPS_FPS_SQRT_HPP\n"
    name: default
  - code: "#line 1 \"fps/fps_sqrt.hpp\"\n\n\n\n#include <cassert>\n\n#line 1 \"math_mod/mod_sqrt.hpp\"\
      \n\n\n\n#line 5 \"math_mod/mod_sqrt.hpp\"\n\n#line 1 \"modint/mont_arb.hpp\"\
      \n\n\n\n#line 5 \"modint/mont_arb.hpp\"\n#include <iostream>\n#include <utility>\n\
      \n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace\
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
      \ __uint128_t, id>;\n\n} // namespace kk2\n\n\n#line 7 \"math_mod/mod_sqrt.hpp\"\
      \n\nnamespace kk2 {\n\n// ref: https://37zigen.com/tonelli-shanks-algorithm/\n\
      template <class T, class U> long long mod_sqrt(const T &a, const U &p) {\n \
      \   assert(0 <= a && a < p);\n    if (a < 2) return a;\n    using Mint = ArbitraryLazyMontgomeryModInt<54105064>;\n\
      \    Mint::setmod(p);\n\n    // euler's criterion\n    if (Mint(a).pow((p -\
      \ 1) / 2) != Mint(1)) return -1;\n\n    // find b: non quadratic residue\n \
      \   Mint b = 1;\n    while (b.pow((p - 1) / 2) == Mint(1)) b += 1;\n\n    //\
      \ (Z/pZ)^*\n    // \u2245 Z/(p-1)Z\n    // \u2245 Z/2^eZ * Z/mZ (m: odd)\n \
      \   long long m = p - 1, e = 0;\n    while (m % 2 == 0) m >>= 1, e++;\n\n  \
      \  Mint x = Mint(a).pow((m - 1) / 2);\n    Mint y = Mint(a) * x * x;\n    x\
      \ *= a;\n    Mint z = Mint(b).pow(m);\n    while (y != Mint(1)) {\n        //\
      \ x -> (x_1, x_2) in Z/2^eZ * Z/mZ\n        // a -> (a_1, a_2) in Z/2^eZ * Z/mZ\n\
      \        long long j = 0;\n        Mint t = y;\n        while (t != Mint(1))\
      \ {\n            j++;\n            t *= t;\n        }\n        z = z.pow(1LL\
      \ << (e - j - 1));\n        x *= z;\n        z *= z;\n        y *= z;\n    \
      \    e = j;\n    }\n    return x.val();\n}\n\n} // namespace kk2\n\n\n#line\
      \ 1 \"type_traits/fps.hpp\"\n\n\n\n#line 5 \"type_traits/fps.hpp\"\n#include\
      \ <ranges>\n#line 7 \"type_traits/fps.hpp\"\n\nnamespace kk2::fps {\n\nnamespace\
      \ category {\n\nstruct arbitrary_modulus {};\nstruct ntt_friendly_modulus {};\n\
      \nstruct ordinary {};\nstruct exponential_generating {};\nstruct set_power_series\
      \ {};\n\nstruct univariate {};\nstruct bivariate {};\nstruct multivariate {};\n\
      \n} // namespace category\n\ntemplate <class M>\nconcept Modular = requires(M\
      \ x) {\n    { M::getmod() } -> std::integral;\n    x.val();\n    { x.inv() }\
      \ -> std::same_as<M>;\n};\n\ntemplate <class F>\nconcept FormalPowerSeries =\
      \ requires(const F &f, int i) {\n    typename F::value_type;\n    typename F::modulus_category;\n\
      \    typename F::series_category;\n    { f.size() } -> std::integral;\n    f[i];\n\
      } && std::ranges::range<const F>;\n\ntemplate <class F>\nconcept NTTFriendlyFormalPowerSeries\
      \ =\n    FormalPowerSeries<F>\n    && std::same_as<typename F::modulus_category,\
      \ category::ntt_friendly_modulus>;\n\ntemplate <class F>\nconcept ArbitraryModulusFormalPowerSeries\
      \ =\n    FormalPowerSeries<F> && std::same_as<typename F::modulus_category,\
      \ category::arbitrary_modulus>;\n\ntemplate <class F>\nconcept OrdinaryFormalPowerSeries\
      \ =\n    FormalPowerSeries<F> && std::same_as<typename F::series_category, category::ordinary>;\n\
      \ntemplate <class F>\nconcept ExponentialGeneratingFunction =\n    FormalPowerSeries<F>\n\
      \    && std::same_as<typename F::series_category, category::exponential_generating>;\n\
      \ntemplate <class F>\nconcept SetPowerSeries =\n    FormalPowerSeries<F> &&\
      \ std::same_as<typename F::series_category, category::set_power_series>;\n\n\
      template <class F>\nconcept UnivariateFormalPowerSeries = FormalPowerSeries<F>\
      \ && requires {\n    typename F::variable_category;\n} && std::same_as<typename\
      \ F::variable_category, category::univariate>;\n\ntemplate <class F>\nconcept\
      \ BivariateFormalPowerSeries = FormalPowerSeries<F> && requires {\n    typename\
      \ F::variable_category;\n} && std::same_as<typename F::variable_category, category::bivariate>;\n\
      \ntemplate <class F>\nconcept MultivariateFormalPowerSeries = FormalPowerSeries<F>\
      \ && requires {\n    typename F::variable_category;\n} && std::same_as<typename\
      \ F::variable_category, category::multivariate>;\n\n// Short names for the categories\
      \ that are commonly used in algorithms.\ntemplate <class F>\nconcept SPS = SetPowerSeries<F>;\n\
      \ntemplate <class F>\nconcept EGF = ExponentialGeneratingFunction<F>;\n\ntemplate\
      \ <class F>\nconcept Bivariate = BivariateFormalPowerSeries<F>;\n\ntemplate\
      \ <class F>\nconcept Multivariate = MultivariateFormalPowerSeries<F>;\n\n} //\
      \ namespace kk2::fps\n\n\n#line 1 \"fps/fps_sparsity_detector.hpp\"\n\n\n\n\
      #include <algorithm>\n#include <bit>\n#include <cstdint>\n#include <memory>\n\
      \nnamespace kk2 {\n\nenum class FPSOperation {\n    CONVOLUTION,\n    LOG,\n\
      \    POWER,\n    DIVISION,\n    POLYNOMIAL_DIVISION,\n    INVERSE,\n    EXP,\n\
      \    SQRT\n};\n\nnamespace fps::sparsity_detail {\n\n// E(n): the leading FFT\
      \ evaluation cost, up to the common field-operation\n// constant that cancels\
      \ when dense and sparse leading terms are compared.\ninline std::int64_t evaluation_work(int\
      \ n) {\n    if (n <= 1) return 1;\n    const unsigned z = std::bit_ceil(static_cast<unsigned>(n));\n\
      \    return static_cast<std::int64_t>(z) * std::countr_zero(z);\n}\n\ninline\
      \ int transform_size(int n, int m) {\n    if (n <= 0 || m <= 0) return 0;\n\
      \    return static_cast<int>(std::bit_ceil(static_cast<unsigned>(n + m - 1)));\n\
      }\n\ninline std::int64_t convolution_dense_work(int n, int m, bool same, bool\
      \ ntt_friendly) {\n    const int z = transform_size(n, m);\n    if (z == 0)\
      \ return 0;\n\n    // A different pair needs two forward and one inverse transform.\
      \ Squaring\n    // reuses the forward transform and needs only one forward transform.\n\
      \    const int transforms = same ? 2 : 3;\n    // Arbitrary-modulus convolution\
      \ uses three NTT-friendly moduli.\n    const int moduli = ntt_friendly ? 1 :\
      \ 3;\n    return static_cast<std::int64_t>(transforms) * moduli * evaluation_work(z);\n\
      }\n\ninline std::int64_t inverse_dense_work(int deg, bool ntt_friendly) {\n\
      \    if (deg <= 1) return 0;\n    const int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(deg)));\n\
      \    // NTT-friendly uses five transforms per Newton level, whose geometric\n\
      \    // sum has leading term 10 E(z). The arbitrary-modulus implementation\n\
      \    // performs two fresh convolutions per level, giving 60 E(z).\n    return\
      \ (ntt_friendly ? 10 : 60) * evaluation_work(z);\n}\n\ninline std::int64_t log_dense_work(int\
      \ n, int deg, bool ntt_friendly) {\n    return inverse_dense_work(deg, ntt_friendly)\n\
      \           + convolution_dense_work(std::max(0, n - 1), deg, false, ntt_friendly);\n\
      }\n\ninline long double exp_dense_work(int deg, bool ntt_friendly) {\n    if\
      \ (deg <= 1) return 0;\n    const int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(deg)));\n\
      \    if (ntt_friendly) {\n        if (deg <= 2) return 0;\n        // Bostan--Schost,\
      \ Theorem 1: (33/2) E(z) + (97/4) z.  Only\n        // the leading E(z) term\
      \ matters for the sparsity threshold.\n        return 16.5L * evaluation_work(z);\n\
      \    }\n    // FPSArb recomputes a logarithm and a product at every Newton level.\n\
      \    return 192 * evaluation_work(z);\n}\n\ninline long double power_dense_work(int\
      \ n, int deg, bool ntt_friendly) {\n    return log_dense_work(n, deg, ntt_friendly)\
      \ + exp_dense_work(deg, ntt_friendly);\n}\n\ninline std::int64_t division_dense_work(int\
      \ n, int deg, bool ntt_friendly) {\n    return inverse_dense_work(deg, ntt_friendly)\n\
      \           + convolution_dense_work(std::min(n, deg), deg, false, ntt_friendly);\n\
      }\n\ninline std::int64_t polynomial_division_dense_work(int quotient_size, bool\
      \ ntt_friendly) {\n    return inverse_dense_work(quotient_size, ntt_friendly)\n\
      \           + convolution_dense_work(quotient_size, quotient_size, false, ntt_friendly);\n\
      }\n\ninline std::int64_t sqrt_dense_work(int deg, bool ntt_friendly) {\n   \
      \ if (deg <= 1) return 0;\n    const int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(deg)));\n\
      \    // Newton uses an inverse and one product at every level. The implementation\n\
      \    // computes the complete next power-of-two block even at the last level.\n\
      \    return (ntt_friendly ? 32 : 156) * evaluation_work(z);\n}\n\ninline long\
      \ double sparse_leading_work(FPSOperation op, long double support_output_pairs)\
      \ {\n    switch (op) {\n    case FPSOperation::LOG:\n        return 3 * support_output_pairs;\n\
      \    case FPSOperation::POWER:\n    case FPSOperation::SQRT:\n        return\
      \ 4 * support_output_pairs;\n    case FPSOperation::CONVOLUTION:\n    case FPSOperation::DIVISION:\n\
      \    case FPSOperation::POLYNOMIAL_DIVISION:\n    case FPSOperation::INVERSE:\n\
      \    case FPSOperation::EXP:\n        return 2 * support_output_pairs;\n   \
      \ }\n    return 0;\n}\n\ninline long double sparse_runtime_factor(FPSOperation\
      \ op) {\n    // Conversion from the field-operation model above to observed\
      \ running\n    // time. Calibrated on powers of two from 256 through 4096 while\
      \ keeping\n    // the threshold conservative when the two implementations are\
      \ close.\n    switch (op) {\n    case FPSOperation::POWER:\n    case FPSOperation::SQRT:\n\
      \        return 0.60L;\n    case FPSOperation::DIVISION:\n    case FPSOperation::POLYNOMIAL_DIVISION:\n\
      \        return 0.75L;\n    case FPSOperation::CONVOLUTION:\n        return\
      \ 1.50L;\n    case FPSOperation::LOG:\n        return 1.25L;\n    case FPSOperation::INVERSE:\n\
      \        return 0.90L;\n    case FPSOperation::EXP:\n        return 1.00L;\n\
      \    }\n    return 1.00L;\n}\n\n} // namespace fps::sparsity_detail\n\ntemplate\
      \ <class FPS, class mint = typename FPS::value_type>\nbool is_sparse_operation(\n\
      \    FPSOperation op, bool is_ntt_friendly, const FPS &a, const FPS &b = FPS(),\
      \ int deg = -1) {\n    const int n = a.size(), m = b.size();\n    if (n + m\
      \ == 0) return false;\n\n    const bool convolution = op == FPSOperation::CONVOLUTION;\n\
      \    const bool division = op == FPSOperation::DIVISION;\n    const bool polynomial_division\
      \ = op == FPSOperation::POLYNOMIAL_DIVISION;\n    const int target = deg < 0\
      \ ? n : std::max(0, deg);\n    std::int64_t nonzero_a = 0, nonzero_b = 0;\n\
      \    long double pair_work = 0;\n\n    const int limit_a = convolution     \
      \                  ? n :\n                        (division || polynomial_division)\
      \ ? 0 :\n                                                            std::min(n,\
      \ target);\n    for (int i = 0; i < limit_a; ++i) {\n        if (a[i] == mint(0))\
      \ continue;\n        ++nonzero_a;\n        if (!convolution && i > 0) {\n  \
      \          const int terms = op == FPSOperation::LOG ? target - 1 - i : target\
      \ - i;\n            if (terms > 0) pair_work += terms;\n        }\n    }\n\n\
      \    const int limit_b = convolution         ? m :\n                       \
      \ division            ? std::min(m, target) :\n                        polynomial_division\
      \ ? m :\n                                              0;\n    for (int i =\
      \ 0; i < limit_b; ++i) {\n        if (b[i] == mint(0)) continue;\n        ++nonzero_b;\n\
      \        if (division && i > 0) pair_work += target - i;\n        if (polynomial_division\
      \ && i + 1 < m) {\n            const int terms = target - (m - 1 - i);\n   \
      \         if (terms > 0) pair_work += terms;\n        }\n    }\n\n    if (convolution)\
      \ { pair_work = static_cast<long double>(nonzero_a) * nonzero_b; }\n\n    long\
      \ double dense_work = 0;\n    switch (op) {\n    case FPSOperation::CONVOLUTION:\n\
      \        dense_work = fps::sparsity_detail::convolution_dense_work(\n      \
      \      n, m, std::addressof(a) == std::addressof(b), is_ntt_friendly);\n   \
      \     break;\n    case FPSOperation::LOG:\n        dense_work = fps::sparsity_detail::log_dense_work(n,\
      \ target, is_ntt_friendly);\n        break;\n    case FPSOperation::POWER:\n\
      \        dense_work = fps::sparsity_detail::power_dense_work(n, target, is_ntt_friendly);\n\
      \        break;\n    case FPSOperation::DIVISION:\n        dense_work = fps::sparsity_detail::division_dense_work(n,\
      \ target, is_ntt_friendly);\n        break;\n    case FPSOperation::POLYNOMIAL_DIVISION:\n\
      \        dense_work = fps::sparsity_detail::polynomial_division_dense_work(target,\
      \ is_ntt_friendly);\n        break;\n    case FPSOperation::INVERSE:\n     \
      \   dense_work = fps::sparsity_detail::inverse_dense_work(target, is_ntt_friendly);\n\
      \        break;\n    case FPSOperation::EXP:\n        dense_work = fps::sparsity_detail::exp_dense_work(target,\
      \ is_ntt_friendly);\n        break;\n    case FPSOperation::SQRT:\n        dense_work\
      \ = fps::sparsity_detail::sqrt_dense_work(target, is_ntt_friendly);\n      \
      \  break;\n    }\n\n    // Count the leading field operations executed for each\
      \ support/output\n    // pair. Linear scans, initialization and per-output normalization\
      \ are\n    // intentionally omitted on both the sparse and dense sides.\n  \
      \  const long double sparse_work = fps::sparsity_detail::sparse_leading_work(op,\
      \ pair_work);\n    return dense_work > fps::sparsity_detail::sparse_runtime_factor(op)\
      \ * sparse_work;\n}\n\n} // namespace kk2\n\n\n#line 9 \"fps/fps_sqrt.hpp\"\n\
      \nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
      FPS dense_sqrt(const FPS &f, int deg = -1) {\n    if (deg == -1) deg = (int)f.size();\n\
      \    if ((int)f.size() == 0) return FPS(deg, mint(0));\n    if (f[0] == mint(0))\
      \ {\n        for (int i = 1; i < (int)f.size(); i++) {\n            if (f[i]\
      \ != mint(0)) {\n                if (i & 1) return {};\n                if (deg\
      \ - i / 2 <= 0) break;\n                auto ret = dense_sqrt(f >> i, deg -\
      \ i / 2);\n                if (ret.empty()) return {};\n                ret\
      \ = ret << (i / 2);\n                if ((int)ret.size() < deg) ret.resize(deg,\
      \ mint(0));\n                return ret;\n            }\n        }\n       \
      \ return FPS(deg, mint(0));\n    }\n\n    long long sqr = mod_sqrt(f[0].val(),\
      \ mint::getmod());\n    if (sqr == -1) return {};\n    assert(sqr * sqr % mint::getmod()\
      \ == f[0].val());\n    FPS ret = {mint(sqr)};\n    mint inv2 = mint(2).inv();\n\
      \    for (int i = 1; i < deg; i <<= 1) {\n        ret = (ret + f.pre(i << 1).dense_mul(ret.dense_inv(i\
      \ << 1))) * inv2;\n    }\n    return ret.pre(deg);\n}\n\ntemplate <class FPS,\
      \ class mint = typename FPS::value_type>\nFPS sparse_sqrt(const FPS &f, int\
      \ deg = -1) {\n    // using mint = typename FPS::value_type;\n    if (deg ==\
      \ -1) deg = (int)f.size();\n    if ((int)f.size() == 0) return FPS(deg, mint(0));\n\
      \    if (f[0] == mint(0)) {\n        for (int i = 1; i < (int)f.size(); i++)\
      \ {\n            if (f[i] != mint(0)) {\n                if (i & 1) return {};\n\
      \                if (deg - i / 2 <= 0) break;\n                auto ret = sparse_sqrt(f\
      \ >> i, deg - i / 2);\n                if (ret.empty()) return {};\n       \
      \         ret = ret << (i / 2);\n                if ((int)ret.size() < deg)\
      \ ret.resize(deg, mint(0));\n                return ret;\n            }\n  \
      \      }\n        return FPS(deg, mint(0));\n    }\n    long long sqr = mod_sqrt(f[0].val(),\
      \ mint::getmod());\n    if (sqr == -1) return {};\n    return f.sparse_pow(((mint::getmod()\
      \ + 1) >> 1), deg) * mint(sqr).inv();\n}\n\ntemplate <class FPS, class mint\
      \ = typename FPS::value_type> FPS sqrt(const FPS &f, int deg = -1) {\n    if\
      \ (deg == -1) deg = (int)f.size();\n    if (!f.empty() && f[0] != mint(0)\n\
      \        && is_sparse_operation(\n            FPSOperation::SQRT, fps::NTTFriendlyFormalPowerSeries<FPS>,\
      \ f, FPS(), deg))\n        return sparse_sqrt(f, deg);\n    return dense_sqrt(f,\
      \ deg);\n}\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: fps/fps_sqrt.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/fps/sparsity_performance.test.cpp
  - verify/unit_test/fps/sparsity_small_performance.test.cpp
  - verify/yosupo_fps/fps_sprase_sqrt.test.cpp
  - verify/yosupo_fps/fps_sqrt.test.cpp
documentation_of: fps/fps_sqrt.hpp
layout: document
---
