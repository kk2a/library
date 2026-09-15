---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/polynomial_root_finding
    links:
    - https://judge.yosupo.jp/problem/polynomial_root_finding
  dependencies:
  - files:
    - filename: convolution.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution.hpp
    - filename: fps_base.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_base.hpp
    - filename: fps_ntt_friendly.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_ntt_friendly.hpp
    - filename: fps_sparsity_detector.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_sparsity_detector.hpp
    - filename: mod_pow.hpp
      icon: LIBRARY_ALL_AC
      path: fps/mod_pow.hpp
    - filename: division.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/division.hpp
    - filename: exponential.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/exponential.hpp
    - filename: inverse.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/inverse.hpp
    - filename: logarithm.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/logarithm.hpp
    - filename: multiplication.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/multiplication.hpp
    - filename: power.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/power.hpp
    - filename: sqrt.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/sqrt.hpp
    - filename: poly_find_root.hpp
      icon: LIBRARY_ALL_AC
      path: fps/poly_find_root.hpp
    - filename: poly_gcd.hpp
      icon: LIBRARY_ALL_AC
      path: fps/poly_gcd.hpp
    - filename: butterfly.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/butterfly.hpp
    - filename: mod_sqrt.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/detail/mod_sqrt.hpp
    - filename: inv_table.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/inv_table.hpp
    - filename: pow_mod.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/pow_mod.hpp
    - filename: primitive_root.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/primitive_root.hpp
    - filename: mont.hpp
      icon: LIBRARY_ALL_AC
      path: modint/mont.hpp
    - filename: gen.hpp
      icon: LIBRARY_ALL_AC
      path: random/gen.hpp
    - filename: seed.hpp
      icon: LIBRARY_ALL_AC
      path: random/seed.hpp
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
  - files: []
    type: Verified with
  dependsOn:
  - convolution/convolution.hpp
  - fps/fps_base.hpp
  - fps/fps_ntt_friendly.hpp
  - fps/fps_sparsity_detector.hpp
  - fps/mod_pow.hpp
  - fps/operations/division.hpp
  - fps/operations/exponential.hpp
  - fps/operations/inverse.hpp
  - fps/operations/logarithm.hpp
  - fps/operations/multiplication.hpp
  - fps/operations/power.hpp
  - fps/operations/sqrt.hpp
  - fps/poly_find_root.hpp
  - fps/poly_gcd.hpp
  - math_mod/butterfly.hpp
  - math_mod/detail/mod_sqrt.hpp
  - math_mod/inv_table.hpp
  - math_mod/pow_mod.hpp
  - math_mod/primitive_root.hpp
  - modint/mont.hpp
  - random/gen.hpp
  - random/seed.hpp
  - template/constant.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  - template/template.hpp
  - template/type_alias.hpp
  - type_traits/fps.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/polynomial_root_finding\n\
      \n#include \"../../fps/fps_ntt_friendly.hpp\"\n#include \"../../fps/poly_find_root.hpp\"\
      \n#include \"../../modint/mont.hpp\"\n#include \"../../template/template.hpp\"\
      \nusing namespace std;\n\nusing FPS = kk2::FPSNTT<kk2::mont998>;\n\nint main()\
      \ {\n    int n;\n    kin >> n;\n    FPS f(n + 1);\n    kin >> f;\n    auto res\
      \ = kk2::find_root(f);\n    kout << res.size() << kendl;\n    kout << res <<\
      \ kendl;\n\n    return 0;\n}\n"
    name: default
  - code: "#line 1 \"verify/yosupo_fps/poly_root_finding.test.cpp\"\n// competitive-verifier:\
      \ PROBLEM https://judge.yosupo.jp/problem/polynomial_root_finding\n\n#line 1\
      \ \"fps/fps_ntt_friendly.hpp\"\n\n\n\n#line 1 \"math_mod/butterfly.hpp\"\n\n\
      \n\n#include <algorithm>\n\n#line 1 \"math_mod/primitive_root.hpp\"\n\n\n\n\
      #line 1 \"math_mod/pow_mod.hpp\"\n\n\n\n#include <cassert>\n\nnamespace kk2\
      \ {\n\ntemplate <class S, class T, class U> constexpr S pow_mod(T x, U n, T\
      \ m) {\n    assert(n >= 0);\n    if (m == 1) return S(0);\n    S _m = m, r =\
      \ 1;\n    S y = x % _m;\n    if (y < 0) y += _m;\n    while (n) {\n        if\
      \ (n & 1) r = (r * y) % _m;\n        if (n >>= 1) y = (y * y) % _m;\n    }\n\
      \    return r;\n}\n\n} // namespace kk2\n\n\n#line 5 \"math_mod/primitive_root.hpp\"\
      \n\nnamespace kk2 {\n\nconstexpr int primitive_root_constexpr(int m) {\n   \
      \ if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
      \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
      \ 3;\n    if (m == 1107296257) return 10;\n    int divs[20] = {};\n    divs[0]\
      \ = 2;\n    int cnt = 1;\n    int x = (m - 1) / 2;\n    while (x % 2 == 0) x\
      \ /= 2;\n    for (int i = 3; (long long)(i)*i <= x; i += 2) {\n        if (x\
      \ % i == 0) {\n            divs[cnt++] = i;\n            while (x % i == 0)\
      \ { x /= i; }\n        }\n    }\n    if (x > 1) { divs[cnt++] = x; }\n    for\
      \ (int g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i <\
      \ cnt; i++) {\n            if (pow_mod<long long>(g, (m - 1) / divs[i], m) ==\
      \ 1) {\n                ok = false;\n                break;\n            }\n\
      \        }\n        if (ok) return g;\n    }\n}\n\ntemplate <int m> static constexpr\
      \ int primitive_root = primitive_root_constexpr(m);\n\n} // namespace kk2\n\n\
      \n#line 7 \"math_mod/butterfly.hpp\"\n\nnamespace kk2 {\n\ntemplate <class FPS,\
      \ class mint = typename FPS::value_type> void butterfly(FPS &a) {\n    static\
      \ int g = primitive_root<mint::getmod()>;\n    int n = int(a.size());\n    int\
      \ h = 0;\n    while ((1U << h) < (unsigned int)(n)) h++;\n    static bool first\
      \ = true;\n    static mint sum_e2[30]; // sum_e[i] = ies[0] * ... * ies[i -\
      \ 1] * es[i]\n    static mint sum_e3[30];\n    static mint es[30], ies[30];\
      \ // es[i]^(2^(2+i)) == 1\n    if (first) {\n        first = false;\n      \
      \  int cnt2 = __builtin_ctz(mint::getmod() - 1);\n        mint e = mint(g).pow((mint::getmod()\
      \ - 1) >> cnt2), ie = e.inv();\n        for (int i = cnt2; i >= 2; i--) {\n\
      \            // e^(2^i) == 1\n            es[i - 2] = e;\n            ies[i\
      \ - 2] = ie;\n            e *= e;\n            ie *= ie;\n        }\n      \
      \  mint now = 1;\n        for (int i = 0; i <= cnt2 - 2; i++) {\n          \
      \  sum_e2[i] = es[i] * now;\n            now *= ies[i];\n        }\n       \
      \ now = 1;\n        for (int i = 0; i <= cnt2 - 3; i++) {\n            sum_e3[i]\
      \ = es[i + 1] * now;\n            now *= ies[i + 1];\n        }\n    }\n\n \
      \   int len = 0;\n    while (len < h) {\n        if (h - len == 1) {\n     \
      \       int p = 1 << (h - len - 1);\n            mint rot = 1;\n           \
      \ for (int s = 0; s < (1 << len); s++) {\n                int offset = s <<\
      \ (h - len);\n                for (int i = 0; i < p; i++) {\n              \
      \      auto l = a[i + offset];\n                    auto r = a[i + offset +\
      \ p] * rot;\n                    a[i + offset] = l + r;\n                  \
      \  a[i + offset + p] = l - r;\n                }\n                if (s + 1\
      \ != (1 << len)) rot *= sum_e2[__builtin_ctz(~(unsigned int)(s))];\n       \
      \     }\n            len++;\n        } else {\n            int p = 1 << (h -\
      \ len - 2);\n            mint rot = 1, imag = es[0];\n            for (int s\
      \ = 0; s < (1 << len); s++) {\n                mint rot2 = rot * rot;\n    \
      \            mint rot3 = rot2 * rot;\n                int offset = s << (h -\
      \ len);\n                for (int i = 0; i < p; i++) {\n                   \
      \ auto a0 = a[i + offset];\n                    auto a1 = a[i + offset + p]\
      \ * rot;\n                    auto a2 = a[i + offset + p * 2] * rot2;\n    \
      \                auto a3 = a[i + offset + p * 3] * rot3;\n                 \
      \   auto a1na3imag = (a1 - a3) * imag;\n                    a[i + offset] =\
      \ a0 + a2 + a1 + a3;\n                    a[i + offset + p] = a0 + a2 - a1 -\
      \ a3;\n                    a[i + offset + p * 2] = a0 - a2 + a1na3imag;\n  \
      \                  a[i + offset + p * 3] = a0 - a2 - a1na3imag;\n          \
      \      }\n                if (s + 1 != (1 << len)) rot *= sum_e3[__builtin_ctz(~(unsigned\
      \ int)(s))];\n            }\n            len += 2;\n        }\n    }\n}\n\n\
      template <class FPS, class mint = typename FPS::value_type> void butterfly_inv(FPS\
      \ &a) {\n    static constexpr int g = primitive_root<mint::getmod()>;\n    int\
      \ n = int(a.size());\n    int h = 0;\n    while ((1U << h) < (unsigned int)(n))\
      \ h++;\n    static bool first = true;\n    static mint sum_ie2[30]; // sum_ie[i]\
      \ = es[0] * ... * es[i - 1] * ies[i]\n    static mint sum_ie3[30];\n    static\
      \ mint es[30], ies[30]; // es[i]^(2^(2+i)) == 1\n    static mint invn[30];\n\
      \    if (first) {\n        first = false;\n        int cnt2 = __builtin_ctz(mint::getmod()\
      \ - 1);\n        mint e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();\n\
      \        for (int i = cnt2; i >= 2; i--) {\n            // e^(2^i) == 1\n  \
      \          es[i - 2] = e;\n            ies[i - 2] = ie;\n            e *= e;\n\
      \            ie *= ie;\n        }\n        mint now = 1;\n        for (int i\
      \ = 0; i <= cnt2 - 2; i++) {\n            sum_ie2[i] = ies[i] * now;\n     \
      \       now *= es[i];\n        }\n        now = 1;\n        for (int i = 0;\
      \ i <= cnt2 - 3; i++) {\n            sum_ie3[i] = ies[i + 1] * now;\n      \
      \      now *= es[i + 1];\n        }\n\n        invn[0] = 1;\n        invn[1]\
      \ = mint::getmod() / 2 + 1;\n        for (int i = 2; i < 30; i++) invn[i] =\
      \ invn[i - 1] * invn[1];\n    }\n    int len = h;\n    while (len) {\n     \
      \   if (len == 1) {\n            int p = 1 << (h - len);\n            mint irot\
      \ = 1;\n            for (int s = 0; s < (1 << (len - 1)); s++) {\n         \
      \       int offset = s << (h - len + 1);\n                for (int i = 0; i\
      \ < p; i++) {\n                    auto l = a[i + offset];\n               \
      \     auto r = a[i + offset + p];\n                    a[i + offset] = l + r;\n\
      \                    a[i + offset + p] = (l - r) * irot;\n                }\n\
      \                if (s + 1 != (1 << (len - 1))) irot *= sum_ie2[__builtin_ctz(~(unsigned\
      \ int)(s))];\n            }\n            len--;\n        } else {\n        \
      \    int p = 1 << (h - len);\n            mint irot = 1, iimag = ies[0];\n \
      \           for (int s = 0; s < (1 << ((len - 2))); s++) {\n               \
      \ mint irot2 = irot * irot;\n                mint irot3 = irot2 * irot;\n  \
      \              int offset = s << (h - len + 2);\n                for (int i\
      \ = 0; i < p; i++) {\n                    auto a0 = a[i + offset];\n       \
      \             auto a1 = a[i + offset + p];\n                    auto a2 = a[i\
      \ + offset + p * 2];\n                    auto a3 = a[i + offset + p * 3];\n\
      \                    auto a2na3iimag = (a2 - a3) * iimag;\n\n              \
      \      a[i + offset] = a0 + a1 + a2 + a3;\n                    a[i + offset\
      \ + p] = (a0 - a1 + a2na3iimag) * irot;\n                    a[i + offset +\
      \ p * 2] = (a0 + a1 - a2 - a3) * irot2;\n                    a[i + offset +\
      \ p * 3] = (a0 - a1 - a2na3iimag) * irot3;\n                }\n            \
      \    if (s + 1 != (1 << (len - 2))) irot *= sum_ie3[__builtin_ctz(~(unsigned\
      \ int)(s))];\n            }\n            len -= 2;\n        }\n    }\n\n   \
      \ for (int i = 0; i < n; i++) a[i] *= invn[h];\n}\n\ntemplate <class FPS, class\
      \ mint = typename FPS::value_type> void doubling(FPS &a) {\n    int n = a.size();\n\
      \    auto b = a;\n    int z = 1;\n    butterfly_inv(b);\n    mint r = 1, zeta\
      \ = mint(primitive_root<mint::getmod()>).pow((mint::getmod() - 1) / (n << 1));\n\
      \    for (int i = 0; i < n; i++) {\n        b[i] *= r;\n        r *= zeta;\n\
      \    }\n    butterfly(b);\n    std::copy(b.begin(), b.end(), std::back_inserter(a));\n\
      }\n\n} // namespace kk2\n\n\n#line 1 \"fps/fps_base.hpp\"\n\n\n\n#line 5 \"\
      fps/fps_base.hpp\"\n#include <iostream>\n#include <vector>\n\n#line 1 \"math_mod/inv_table.hpp\"\
      \n\n\n\n#line 5 \"math_mod/inv_table.hpp\"\n\nnamespace kk2 {\n\n/**\n * @brief\
      \ `[1, n]`\u306Emod\u9006\u5143\u3092\u5217\u6319\u3059\u308B\u30C6\u30FC\u30D6\
      \u30EB\n *\n * @tparam mint\n */\ntemplate <class mint> struct InvTable {\n\
      \    static inline std::vector<mint> _invs{0, 1};\n    static inline auto _mod\
      \ = mint::getmod();\n    InvTable() = delete;\n\n    static void set_upper(int\
      \ m) {\n        if ((int)_invs.size() > m) return;\n        int start = _invs.size();\n\
      \        _invs.resize(m + 1);\n        // p = q * i + r\n        // - q / r\
      \ = 1 / i (mod p)\n        for (int i = start; i <= m; ++i) _invs[i] = (-_invs[_mod\
      \ % i]) * (_mod / i);\n    }\n\n    static inline mint inv(int n) {\n      \
      \  bool neg = n < 0;\n        if (neg) n = -n;\n        if (n >= (int)_invs.size())\
      \ set_upper(n);\n        return neg ? -_invs[n] : _invs[n];\n    }\n};\n\n}\
      \ // namespace kk2\n\n\n#line 1 \"type_traits/fps.hpp\"\n\n\n\n#include <concepts>\n\
      #include <ranges>\n#include <type_traits>\n\nnamespace kk2::fps {\n\nnamespace\
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
      \ namespace kk2::fps\n\n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#line\
      \ 5 \"type_traits/integral.hpp\"\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\n\
      template <typename T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T,\
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
      \n} // namespace kk2\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#line 5 \"type_traits/io.hpp\"\
      \n#include <fstream>\n#include <istream>\n#include <ostream>\n#line 9 \"type_traits/io.hpp\"\
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
      \n} // namespace kk2\n\n\n#line 1 \"fps/operations/division.hpp\"\n\n\n\n#line\
      \ 5 \"fps/operations/division.hpp\"\n#include <memory>\n#include <utility>\n\
      #line 8 \"fps/operations/division.hpp\"\n\n#line 1 \"fps/fps_sparsity_detector.hpp\"\
      \n\n\n\n#line 5 \"fps/fps_sparsity_detector.hpp\"\n#include <bit>\n#include\
      \ <cstdint>\n#line 9 \"fps/fps_sparsity_detector.hpp\"\n\nnamespace kk2 {\n\n\
      enum class FPSOperation {\n    CONVOLUTION,\n    LOG,\n    POWER,\n    DIVISION,\n\
      \    POLYNOMIAL_DIVISION,\n    INVERSE,\n    EXP,\n    SQRT\n};\n\nnamespace\
      \ fps::sparsity_detail {\n\n// E(n): the leading FFT evaluation cost, up to\
      \ the common field-operation\n// constant that cancels when dense and sparse\
      \ leading terms are compared.\ninline std::int64_t evaluation_work(int n) {\n\
      \    if (n <= 1) return 1;\n    const unsigned z = std::bit_ceil(static_cast<unsigned>(n));\n\
      \    return static_cast<std::int64_t>(z) * std::countr_zero(z);\n}\n\ninline\
      \ int transform_size(int n, int m) {\n    if (n <= 0 || m <= 0) return 0;\n\
      \    return static_cast<int>(std::bit_ceil(static_cast<unsigned>(n + m - 1)));\n\
      }\n\ninline std::int64_t\nconvolution_dense_work(int n, int m, int precision,\
      \ bool same, bool ntt_friendly) {\n    n = std::min(n, precision);\n    m =\
      \ std::min(m, precision);\n    const int z = transform_size(n, m);\n    if (z\
      \ == 0) return 0;\n\n    // A different pair needs two forward and one inverse\
      \ transform. Squaring\n    // reuses the forward transform and needs only one\
      \ forward transform.\n    const int transforms = same ? 2 : 3;\n    // Arbitrary-modulus\
      \ convolution uses three NTT-friendly moduli.\n    const int moduli = ntt_friendly\
      \ ? 1 : 3;\n    return static_cast<std::int64_t>(transforms) * moduli * evaluation_work(z);\n\
      }\n\ninline std::int64_t inverse_dense_work(int precision, bool ntt_friendly)\
      \ {\n    if (precision <= 1) return 0;\n    const int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(precision)));\n\
      \    // NTT-friendly uses five transforms per Newton level, whose geometric\n\
      \    // sum has leading term 10 E(z). The arbitrary-modulus implementation\n\
      \    // performs two fresh convolutions per level, giving 60 E(z).\n    return\
      \ (ntt_friendly ? 10 : 60) * evaluation_work(z);\n}\n\ninline std::int64_t log_dense_work(int\
      \ n, int precision, bool ntt_friendly) {\n    return inverse_dense_work(precision,\
      \ ntt_friendly)\n           + convolution_dense_work(std::max(0, n - 1), precision,\
      \ precision, false, ntt_friendly);\n}\n\ninline long double exp_dense_work(int\
      \ precision, bool ntt_friendly) {\n    if (precision <= 1) return 0;\n    const\
      \ int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(precision)));\n\
      \    if (ntt_friendly) {\n        if (precision <= 2) return 0;\n        //\
      \ Bostan--Schost, Theorem 1: (33/2) E(z) + (97/4) z.  Only\n        // the leading\
      \ E(z) term matters for the sparsity threshold.\n        return 16.5L * evaluation_work(z);\n\
      \    }\n    // FPSArb recomputes a logarithm and a product at every Newton level.\n\
      \    return 192 * evaluation_work(z);\n}\n\ninline long double power_dense_work(int\
      \ n, int precision, bool ntt_friendly) {\n    return log_dense_work(n, precision,\
      \ ntt_friendly) + exp_dense_work(precision, ntt_friendly);\n}\n\ninline std::int64_t\
      \ division_dense_work(int n, int precision, bool ntt_friendly) {\n    return\
      \ inverse_dense_work(precision, ntt_friendly)\n           + convolution_dense_work(\n\
      \               std::min(n, precision), precision, precision, false, ntt_friendly);\n\
      }\n\ninline std::int64_t polynomial_division_dense_work(int quotient_size, bool\
      \ ntt_friendly) {\n    return inverse_dense_work(quotient_size, ntt_friendly)\n\
      \           + convolution_dense_work(\n               quotient_size, quotient_size,\
      \ quotient_size, false, ntt_friendly);\n}\n\ninline std::int64_t sqrt_dense_work(int\
      \ precision, bool ntt_friendly) {\n    if (precision <= 1) return 0;\n    const\
      \ int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(precision)));\n\
      \    // Newton uses an inverse and one product at every level. The implementation\n\
      \    // computes the complete next power-of-two block even at the last level.\n\
      \    return (ntt_friendly ? 32 : 156) * evaluation_work(z);\n}\n\ninline long\
      \ double\nsparse_work(FPSOperation op, int target, std::int64_t nonzero_a, std::int64_t\
      \ nonzero_b) {\n    switch (op) {\n        case FPSOperation::CONVOLUTION:\n\
      \            return static_cast<long double>(nonzero_a) * nonzero_b;\n     \
      \   case FPSOperation::DIVISION:\n        case FPSOperation::POLYNOMIAL_DIVISION:\n\
      \            return static_cast<long double>(target) * nonzero_b;\n        case\
      \ FPSOperation::LOG:\n        case FPSOperation::POWER:\n        case FPSOperation::INVERSE:\n\
      \        case FPSOperation::EXP:\n        case FPSOperation::SQRT:\n       \
      \     return static_cast<long double>(target) * nonzero_a;\n    }\n    return\
      \ 0;\n}\n\ninline long double sparse_work_constant(FPSOperation op, bool ntt_friendly)\
      \ {\n    // Calibrated against the simplified sparse-work model at degrees 1024\n\
      \    // and 4096.  Values are rounded upward near the measured crossover so\
      \ a\n    // close decision favors the dense implementation.\n    switch (op)\
      \ {\n        case FPSOperation::CONVOLUTION:\n            return ntt_friendly\
      \ ? 0.90L : 0.55L;\n        case FPSOperation::DIVISION:\n        case FPSOperation::POLYNOMIAL_DIVISION:\n\
      \            return ntt_friendly ? 0.90L : 0.40L;\n        case FPSOperation::LOG:\n\
      \            return ntt_friendly ? 2.70L : 1.00L;\n        case FPSOperation::POWER:\n\
      \            return ntt_friendly ? 1.35L : 0.70L;\n        case FPSOperation::INVERSE:\n\
      \            return ntt_friendly ? 1.00L : 0.40L;\n        case FPSOperation::EXP:\n\
      \            return ntt_friendly ? 1.05L : 0.45L;\n        case FPSOperation::SQRT:\n\
      \            return ntt_friendly ? 1.40L : 0.65L;\n    }\n    return 1.00L;\n\
      }\n\n} // namespace fps::sparsity_detail\n\ntemplate <class FPS, class mint\
      \ = typename FPS::value_type>\nbool is_sparse_operation(\n    FPSOperation op,\
      \ bool is_ntt_friendly, const FPS &a, const FPS &b = FPS(), int precision =\
      \ -1) {\n    const int n = a.size(), m = b.size();\n    if (n + m == 0) return\
      \ false;\n\n    const bool convolution = op == FPSOperation::CONVOLUTION;\n\
      \    const bool division = op == FPSOperation::DIVISION;\n    const bool polynomial_division\
      \ = op == FPSOperation::POLYNOMIAL_DIVISION;\n    const int requested =\n  \
      \      precision < 0 ? (convolution ? std::max(0, n + m - 1) : n) : std::max(0,\
      \ precision);\n    const int target = convolution ? std::min(requested, std::max(0,\
      \ n + m - 1)) : requested;\n    const int limit_a = convolution            \
      \           ? std::min(n, target) :\n                        (division || polynomial_division)\
      \ ? 0 :\n                                                            std::min(n,\
      \ target);\n    const int limit_b = convolution         ? std::min(m, target)\
      \ :\n                        division            ? std::min(m, target) :\n \
      \                       polynomial_division ? m :\n                        \
      \                      0;\n    const auto is_nonzero = [](const mint &x) {\n\
      \        return x != mint(0);\n    };\n    const std::int64_t nonzero_a = std::ranges::count_if(a\
      \ | std::views::take(limit_a), is_nonzero);\n    const std::int64_t nonzero_b\
      \ = std::ranges::count_if(b | std::views::take(limit_b), is_nonzero);\n\n  \
      \  long double dense_work = 0;\n    switch (op) {\n        case FPSOperation::CONVOLUTION:\n\
      \            dense_work = fps::sparsity_detail::convolution_dense_work(\n  \
      \              n, m, target, std::addressof(a) == std::addressof(b), is_ntt_friendly);\n\
      \            break;\n        case FPSOperation::LOG:\n            dense_work\
      \ = fps::sparsity_detail::log_dense_work(n, target, is_ntt_friendly);\n    \
      \        break;\n        case FPSOperation::POWER:\n            dense_work =\
      \ fps::sparsity_detail::power_dense_work(n, target, is_ntt_friendly);\n    \
      \        break;\n        case FPSOperation::DIVISION:\n            dense_work\
      \ = fps::sparsity_detail::division_dense_work(n, target, is_ntt_friendly);\n\
      \            break;\n        case FPSOperation::POLYNOMIAL_DIVISION:\n     \
      \       dense_work =\n                fps::sparsity_detail::polynomial_division_dense_work(target,\
      \ is_ntt_friendly);\n            break;\n        case FPSOperation::INVERSE:\n\
      \            dense_work = fps::sparsity_detail::inverse_dense_work(target, is_ntt_friendly);\n\
      \            break;\n        case FPSOperation::EXP:\n            dense_work\
      \ = fps::sparsity_detail::exp_dense_work(target, is_ntt_friendly);\n       \
      \     break;\n        case FPSOperation::SQRT:\n            dense_work = fps::sparsity_detail::sqrt_dense_work(target,\
      \ is_ntt_friendly);\n            break;\n    }\n\n    const long double sparse_work\
      \ =\n        fps::sparsity_detail::sparse_work(op, target, nonzero_a, nonzero_b);\n\
      \    return dense_work\n           > fps::sparsity_detail::sparse_work_constant(op,\
      \ is_ntt_friendly) * sparse_work;\n}\n\n} // namespace kk2\n\n\n#line 11 \"\
      fps/operations/division.hpp\"\n\nnamespace kk2::fps::operations {\n\ntemplate\
      \ <UnivariateFormalPowerSeries FPS> FPS division_identity(int precision) {\n\
      \    using mint = typename FPS::value_type;\n    FPS result(precision, mint(0));\n\
      \    if (precision > 0) result[0] = mint(1);\n    return result;\n}\n\ntemplate\
      \ <UnivariateFormalPowerSeries FPS>\nFPS &inplace_dense_div(FPS &dividend, const\
      \ FPS &divisor, int precision = -1) {\n    using mint = typename FPS::value_type;\n\
      \    assert(!divisor.empty() && divisor[0] != mint(0));\n    if (precision ==\
      \ -1) precision = static_cast<int>(dividend.size());\n    if (std::addressof(dividend)\
      \ == std::addressof(divisor))\n        return dividend = division_identity<FPS>(precision);\n\
      \n    FPS inverse = divisor.dense_inv(precision);\n    return dividend.inplace_pre(precision).inplace_dense_mul(inverse).inplace_pre(precision);\n\
      }\n\ntemplate <UnivariateFormalPowerSeries FPS>\nFPS dense_div(const FPS &dividend,\
      \ const FPS &divisor, int precision = -1) {\n    using mint = typename FPS::value_type;\n\
      \    assert(!divisor.empty() && divisor[0] != mint(0));\n    if (precision ==\
      \ -1) precision = static_cast<int>(dividend.size());\n    if (std::addressof(dividend)\
      \ == std::addressof(divisor))\n        return division_identity<FPS>(precision);\n\
      \    FPS result = dividend;\n    return inplace_dense_div(result, divisor, precision);\n\
      }\n\ntemplate <UnivariateFormalPowerSeries FPS>\nFPS &inplace_sparse_div(FPS\
      \ &dividend, const FPS &divisor, int precision = -1) {\n    using mint = typename\
      \ FPS::value_type;\n    assert(!divisor.empty() && divisor[0] != mint(0));\n\
      \    if (precision == -1) precision = static_cast<int>(dividend.size());\n \
      \   if (std::addressof(dividend) == std::addressof(divisor))\n        return\
      \ dividend = division_identity<FPS>(precision);\n\n    const mint constant_inv\
      \ = divisor[0].inv();\n    std::vector<std::pair<int, mint>> support;\n    for\
      \ (int i = 1; i < static_cast<int>(divisor.size()); ++i) {\n        if (divisor[i]\
      \ != mint(0)) support.emplace_back(i, divisor[i] * constant_inv);\n    }\n \
      \   dividend *= constant_inv;\n    dividend.resize(precision);\n    for (int\
      \ i = 0; i < precision; ++i) {\n        for (const auto &[index, coefficient]\
      \ : support) {\n            if (i + index >= precision) break;\n           \
      \ dividend[i + index] -= dividend[i] * coefficient;\n        }\n    }\n    return\
      \ dividend;\n}\n\ntemplate <UnivariateFormalPowerSeries FPS>\nFPS sparse_div(const\
      \ FPS &dividend, const FPS &divisor, int precision = -1) {\n    using mint =\
      \ typename FPS::value_type;\n    assert(!divisor.empty() && divisor[0] != mint(0));\n\
      \    if (precision == -1) precision = static_cast<int>(dividend.size());\n \
      \   if (std::addressof(dividend) == std::addressof(divisor))\n        return\
      \ division_identity<FPS>(precision);\n    FPS result = dividend;\n    return\
      \ inplace_sparse_div(result, divisor, precision);\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS>\nFPS div(const FPS &dividend, const FPS &divisor, int precision = -1)\
      \ {\n    using mint = typename FPS::value_type;\n    assert(!divisor.empty()\
      \ && divisor[0] != mint(0));\n    if (precision == -1) precision = static_cast<int>(dividend.size());\n\
      \    if (std::addressof(dividend) == std::addressof(divisor))\n        return\
      \ division_identity<FPS>(precision);\n    if (is_sparse_operation(FPSOperation::DIVISION,\n\
      \                            NTTFriendlyFormalPowerSeries<FPS>,\n          \
      \                  dividend,\n                            divisor,\n       \
      \                     precision))\n        return sparse_div(dividend, divisor,\
      \ precision);\n    return dense_div(dividend, divisor, precision);\n}\n\ntemplate\
      \ <UnivariateFormalPowerSeries FPS>\nFPS &inplace_div(FPS &dividend, const FPS\
      \ &divisor, int precision = -1) {\n    using mint = typename FPS::value_type;\n\
      \    assert(!divisor.empty() && divisor[0] != mint(0));\n    if (precision ==\
      \ -1) precision = static_cast<int>(dividend.size());\n    if (std::addressof(dividend)\
      \ == std::addressof(divisor))\n        return dividend = division_identity<FPS>(precision);\n\
      \    const bool use_sparse = is_sparse_operation(\n        FPSOperation::DIVISION,\
      \ NTTFriendlyFormalPowerSeries<FPS>, dividend, divisor, precision);\n    if\
      \ (use_sparse) return inplace_sparse_div(dividend, divisor, precision);\n  \
      \  return inplace_dense_div(dividend, divisor, precision);\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS>\nFPS &inplace_dense_quo(FPS &dividend, const FPS &divisor) {\n    assert(!divisor.empty());\n\
      \    if (dividend.size() < divisor.size()) {\n        dividend.clear();\n  \
      \      return dividend;\n    }\n    if (std::addressof(dividend) == std::addressof(divisor))\
      \ {\n        dividend = FPS{1};\n        return dividend;\n    }\n\n    const\
      \ int quotient_size = dividend.size() - divisor.size() + 1;\n    FPS reversed_inverse\
      \ = divisor.rev().dense_inv(quotient_size);\n    return dividend.inplace_rev()\n\
      \        .inplace_pre(quotient_size)\n        .inplace_dense_mul(reversed_inverse)\n\
      \        .inplace_pre(quotient_size)\n        .inplace_rev();\n}\n\ntemplate\
      \ <UnivariateFormalPowerSeries FPS> FPS dense_quo(const FPS &dividend, const\
      \ FPS &divisor) {\n    assert(!divisor.empty());\n    if (std::addressof(dividend)\
      \ == std::addressof(divisor)) return FPS{1};\n    FPS result = dividend;\n \
      \   return inplace_dense_quo(result, divisor);\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS>\nFPS &inplace_sparse_quo(FPS &dividend, const FPS &divisor) {\n    using\
      \ mint = typename FPS::value_type;\n    assert(!divisor.empty());\n    if (dividend.size()\
      \ < divisor.size()) {\n        dividend.clear();\n        return dividend;\n\
      \    }\n    if (std::addressof(dividend) == std::addressof(divisor)) {\n   \
      \     dividend = FPS{1};\n        return dividend;\n    }\n\n    const int quotient_size\
      \ = dividend.size() - divisor.size() + 1;\n    const mint leading_inv = divisor.back().inv();\n\
      \    std::vector<std::pair<int, mint>> support;\n    for (int i = static_cast<int>(divisor.size())\
      \ - 2; i >= 0; --i) {\n        if (divisor[i] != mint(0))\n            support.emplace_back(divisor.size()\
      \ - 1 - i, divisor[i] * leading_inv);\n    }\n    FPS reversed_quotient(quotient_size);\n\
      \    for (int k = 0; k < quotient_size; ++k) {\n        reversed_quotient[k]\
      \ = dividend[dividend.size() - 1 - k] * leading_inv;\n        for (const auto\
      \ &[offset, coefficient] : support) {\n            if (offset > k) break;\n\
      \            reversed_quotient[k] -= reversed_quotient[k - offset] * coefficient;\n\
      \        }\n    }\n    reversed_quotient.inplace_rev();\n    return dividend\
      \ = std::move(reversed_quotient);\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS> FPS sparse_quo(const FPS &dividend, const FPS &divisor) {\n    assert(!divisor.empty());\n\
      \    if (std::addressof(dividend) == std::addressof(divisor)) return FPS{1};\n\
      \    FPS result = dividend;\n    return inplace_sparse_quo(result, divisor);\n\
      }\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS quo(const FPS &dividend,\
      \ const FPS &divisor) {\n    assert(!divisor.empty());\n    if (dividend.size()\
      \ < divisor.size()) return {};\n    if (std::addressof(dividend) == std::addressof(divisor))\
      \ return FPS{1};\n    const int quotient_size = dividend.size() - divisor.size()\
      \ + 1;\n    if (is_sparse_operation(FPSOperation::POLYNOMIAL_DIVISION,\n   \
      \                         NTTFriendlyFormalPowerSeries<FPS>,\n             \
      \               dividend,\n                            divisor,\n          \
      \                  quotient_size))\n        return sparse_quo(dividend, divisor);\n\
      \    return dense_quo(dividend, divisor);\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS> FPS &inplace_quo(FPS &dividend, const FPS &divisor) {\n    assert(!divisor.empty());\n\
      \    if (dividend.size() < divisor.size()) {\n        dividend.clear();\n  \
      \      return dividend;\n    }\n    if (std::addressof(dividend) == std::addressof(divisor))\
      \ {\n        dividend = FPS{1};\n        return dividend;\n    }\n    const\
      \ int quotient_size = dividend.size() - divisor.size() + 1;\n    const bool\
      \ use_sparse = is_sparse_operation(FPSOperation::POLYNOMIAL_DIVISION,\n    \
      \                                            NTTFriendlyFormalPowerSeries<FPS>,\n\
      \                                                dividend,\n               \
      \                                 divisor,\n                               \
      \                 quotient_size);\n    if (use_sparse) return inplace_sparse_quo(dividend,\
      \ divisor);\n    return inplace_dense_quo(dividend, divisor);\n}\n\ntemplate\
      \ <UnivariateFormalPowerSeries FPS>\nFPS &inplace_dense_mod(FPS &dividend, const\
      \ FPS &divisor) {\n    assert(!divisor.empty());\n    if (std::addressof(dividend)\
      \ == std::addressof(divisor)) {\n        dividend.clear();\n        return dividend;\n\
      \    }\n    FPS quotient = dense_quo(dividend, divisor);\n    return (dividend\
      \ -= quotient.inplace_dense_mul(divisor)).shrink();\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS> FPS dense_mod(const FPS &dividend, const FPS &divisor) {\n    FPS result\
      \ = dividend;\n    return inplace_dense_mod(result, divisor);\n}\n\ntemplate\
      \ <UnivariateFormalPowerSeries FPS>\nFPS &inplace_sparse_mod(FPS &dividend,\
      \ const FPS &divisor) {\n    assert(!divisor.empty());\n    if (std::addressof(dividend)\
      \ == std::addressof(divisor)) {\n        dividend.clear();\n        return dividend;\n\
      \    }\n    FPS quotient = sparse_quo(dividend, divisor);\n    return (dividend\
      \ -= quotient.inplace_sparse_mul(divisor)).shrink();\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS> FPS sparse_mod(const FPS &dividend, const FPS &divisor) {\n    FPS result\
      \ = dividend;\n    return inplace_sparse_mod(result, divisor);\n}\n\ntemplate\
      \ <UnivariateFormalPowerSeries FPS> FPS &inplace_mod(FPS &dividend, const FPS\
      \ &divisor) {\n    assert(!divisor.empty());\n    if (std::addressof(dividend)\
      \ == std::addressof(divisor)) {\n        dividend.clear();\n        return dividend;\n\
      \    }\n    if (dividend.size() < divisor.size()) return dividend.shrink();\n\
      \    const int quotient_size = dividend.size() - divisor.size() + 1;\n    const\
      \ bool use_sparse = is_sparse_operation(FPSOperation::POLYNOMIAL_DIVISION,\n\
      \                                                NTTFriendlyFormalPowerSeries<FPS>,\n\
      \                                                dividend,\n               \
      \                                 divisor,\n                               \
      \                 quotient_size);\n    if (use_sparse) return inplace_sparse_mod(dividend,\
      \ divisor);\n    return inplace_dense_mod(dividend, divisor);\n}\n\ntemplate\
      \ <UnivariateFormalPowerSeries FPS> FPS mod(const FPS &dividend, const FPS &divisor)\
      \ {\n    FPS result = dividend;\n    return inplace_mod(result, divisor);\n\
      }\n\n} // namespace kk2::fps::operations\n\n\n#line 1 \"fps/operations/exponential.hpp\"\
      \n\n\n\n#line 8 \"fps/operations/exponential.hpp\"\n\n#line 11 \"fps/operations/exponential.hpp\"\
      \n\nnamespace kk2::fps::operations {\n\ntemplate <NTTFriendlyFormalPowerSeries\
      \ FPS> FPS dense_exp(const FPS &f, int precision = -1) {\n    using mint = typename\
      \ FPS::value_type;\n    assert(f.empty() || f[0] == mint(0));\n    if (precision\
      \ == -1) precision = static_cast<int>(f.size());\n\n    FPS result{1, 1 < static_cast<int>(f.size())\
      \ ? f[1] : mint(0)};\n    FPS inverse{1}, transformed_inverse, previous_transformed_inverse{1,\
      \ 1};\n    for (int m = 2; m < precision; m <<= 1) {\n        FPS transformed_result\
      \ = result;\n        transformed_result.resize(m << 1);\n        transformed_result.but();\n\
      \        transformed_inverse = previous_transformed_inverse;\n        FPS correction(m);\n\
      \        correction = transformed_result.dot(transformed_inverse);\n       \
      \ correction.ibut();\n        std::fill_n(correction.begin(), m >> 1, mint(0));\n\
      \        correction.but();\n        correction.inplace_dot(-transformed_inverse);\n\
      \        correction.ibut();\n        inverse.insert(inverse.end(), correction.begin()\
      \ + (m >> 1), correction.end());\n        previous_transformed_inverse = inverse;\n\
      \        previous_transformed_inverse.resize(m << 1);\n        previous_transformed_inverse.but();\n\
      \n        FPS delta(f.begin(), f.begin() + std::min(static_cast<int>(f.size()),\
      \ m));\n        delta.resize(m);\n        delta.inplace_diff();\n        delta.push_back(mint(0));\n\
      \        delta.but();\n        delta.inplace_dot(transformed_result);\n    \
      \    delta.ibut();\n        delta -= result.diff();\n        delta.resize(m\
      \ << 1);\n        std::copy_n(delta.begin(), m - 1, delta.begin() + m);\n  \
      \      std::fill_n(delta.begin(), m - 1, mint(0));\n        delta.but();\n \
      \       delta.inplace_dot(previous_transformed_inverse);\n        delta.ibut();\n\
      \        delta.pop_back();\n        delta.inplace_int();\n        for (int i\
      \ = m; i < std::min(static_cast<int>(f.size()), m << 1); ++i) delta[i] += f[i];\n\
      \        std::fill_n(delta.begin(), m, mint(0));\n        delta.but();\n   \
      \     delta.inplace_dot(transformed_result);\n        delta.ibut();\n      \
      \  result.insert(result.end(), delta.begin() + m, delta.end());\n    }\n   \
      \ return FPS(result.begin(), result.begin() + precision);\n}\n\ntemplate <ArbitraryModulusFormalPowerSeries\
      \ FPS> FPS dense_exp(const FPS &f, int precision = -1);\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS> FPS &inplace_dense_exp(FPS &f, int precision = -1) {\n    if (precision\
      \ == -1) precision = static_cast<int>(f.size());\n    return f = dense_exp(std::as_const(f),\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_sparse_exp(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  assert(f.empty() || f[0] == mint(0));\n    if (precision == -1) precision\
      \ = static_cast<int>(f.size());\n\n    std::vector<std::pair<int, mint>> support;\n\
      \    for (int i = 1; i < static_cast<int>(f.size()); ++i) {\n        if (f[i]\
      \ != mint(0)) support.emplace_back(i, f[i] * i);\n    }\n\n    const int mod\
      \ = mint::getmod();\n    static std::vector<mint> inverse{1, 1};\n    const\
      \ int old_size = inverse.size();\n    inverse.resize(std::max(old_size, precision\
      \ + 1));\n    for (int i = old_size; i <= precision; ++i) inverse[i] = -inverse[mod\
      \ % i] * (mod / i);\n\n    f.assign(precision, mint(0));\n    if (precision\
      \ > 0) f[0] = mint(1);\n    for (int k = 0; k < precision - 1; ++k) {\n    \
      \    for (const auto &[index, derivative_coefficient] : support) {\n       \
      \     const int derivative_index = index - 1;\n            if (k < derivative_index)\
      \ break;\n            f[k + 1] += f[k - derivative_index] * derivative_coefficient;\n\
      \        }\n        f[k + 1] *= inverse[k + 1];\n    }\n    return f;\n}\n\n\
      template <UnivariateFormalPowerSeries FPS> FPS sparse_exp(const FPS &f, int\
      \ precision = -1) {\n    FPS result = f;\n    return inplace_sparse_exp(result,\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS exp(const\
      \ FPS &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n\
      \    assert(f.empty() || f[0] == mint(0));\n    if (is_sparse_operation(\n \
      \           FPSOperation::EXP, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(),\
      \ precision))\n        return sparse_exp(f, precision);\n    return dense_exp(f,\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_exp(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  assert(f.empty() || f[0] == mint(0));\n    const bool use_sparse = is_sparse_operation(\n\
      \        FPSOperation::EXP, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), precision);\n\
      \    if (use_sparse) return inplace_sparse_exp(f, precision);\n    return inplace_dense_exp(f,\
      \ precision);\n}\n\n} // namespace kk2::fps::operations\n\n\n#line 1 \"fps/operations/inverse.hpp\"\
      \n\n\n\n#line 8 \"fps/operations/inverse.hpp\"\n\n#line 11 \"fps/operations/inverse.hpp\"\
      \n\nnamespace kk2::fps::operations {\n\ntemplate <NTTFriendlyFormalPowerSeries\
      \ FPS> FPS dense_inv(const FPS &f, int precision = -1) {\n    using mint = typename\
      \ FPS::value_type;\n    assert(!f.empty() && f[0] != mint(0));\n    if (precision\
      \ == -1) precision = static_cast<int>(f.size());\n\n    FPS result(precision);\n\
      \    if (precision == 0) return result;\n    result[0] = mint(1) / f[0];\n \
      \   for (int d = 1; d < precision; d <<= 1) {\n        FPS lhs(2 * d), rhs(2\
      \ * d);\n        std::copy_n(f.begin(), std::min(static_cast<int>(f.size()),\
      \ 2 * d), lhs.begin());\n        std::copy_n(result.begin(), d, rhs.begin());\n\
      \        lhs.but();\n        rhs.but();\n        lhs.inplace_dot(rhs);\n   \
      \     lhs.ibut();\n        std::fill_n(lhs.begin(), d, mint(0));\n        lhs.but();\n\
      \        lhs.inplace_dot(rhs);\n        lhs.ibut();\n        const int next_precision\
      \ = std::min(2 * d, precision);\n        std::transform(lhs.begin() + d,\n \
      \                      lhs.begin() + next_precision,\n                     \
      \  result.begin() + d,\n                       [](const mint &coefficient) {\
      \ return -coefficient; });\n    }\n    return result;\n}\n\ntemplate <ArbitraryModulusFormalPowerSeries\
      \ FPS> FPS dense_inv(const FPS &f, int precision = -1);\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS> FPS &inplace_dense_inv(FPS &f, int precision = -1) {\n    if (precision\
      \ == -1) precision = static_cast<int>(f.size());\n    return f = dense_inv(std::as_const(f),\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_sparse_inv(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  assert(!f.empty() && f[0] != mint(0));\n    if (precision == -1) precision\
      \ = static_cast<int>(f.size());\n\n    std::vector<std::pair<int, mint>> support;\n\
      \    for (int i = 1; i < static_cast<int>(f.size()); ++i) {\n        if (f[i]\
      \ != mint(0)) support.emplace_back(i, f[i]);\n    }\n    const mint constant_inv\
      \ = f[0].inv();\n    f.resize(precision);\n    if (precision > 0) f[0] = constant_inv;\n\
      \    for (int k = 1; k < precision; ++k) {\n        f[k] = mint(0);\n      \
      \  for (const auto &[index, coefficient] : support) {\n            if (k < index)\
      \ break;\n            f[k] += f[k - index] * coefficient;\n        }\n     \
      \   f[k] *= -constant_inv;\n    }\n    return f;\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS> FPS sparse_inv(const FPS &f, int precision = -1) {\n    FPS result =\
      \ f;\n    return inplace_sparse_inv(result, precision);\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS> FPS inv(const FPS &f, int precision = -1) {\n    using mint = typename\
      \ FPS::value_type;\n    assert(!f.empty() && f[0] != mint(0));\n    if (is_sparse_operation(\n\
      \            FPSOperation::INVERSE, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(),\
      \ precision))\n        return sparse_inv(f, precision);\n    return dense_inv(f,\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_inv(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  assert(!f.empty() && f[0] != mint(0));\n    const bool use_sparse = is_sparse_operation(\n\
      \        FPSOperation::INVERSE, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(),\
      \ precision);\n    if (use_sparse) return inplace_sparse_inv(f, precision);\n\
      \    return inplace_dense_inv(f, precision);\n}\n\n} // namespace kk2::fps::operations\n\
      \n\n#line 1 \"fps/operations/logarithm.hpp\"\n\n\n\n#line 7 \"fps/operations/logarithm.hpp\"\
      \n\n#line 11 \"fps/operations/logarithm.hpp\"\n\nnamespace kk2::fps::operations\
      \ {\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_dense_log(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  assert(!f.empty() && f[0] == mint(1));\n    if (precision == -1) precision\
      \ = static_cast<int>(f.size());\n    if (precision == 0) {\n        f.clear();\n\
      \        return f;\n    }\n\n    FPS inverse = f.dense_inv(precision);\n   \
      \ return f.inplace_diff().inplace_dense_mul(inverse).inplace_pre(precision -\
      \ 1).inplace_int();\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS dense_log(const\
      \ FPS &f, int precision = -1) {\n    FPS result = f;\n    return inplace_dense_log(result,\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_sparse_log(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  using ivta = InvTable<mint>;\n    assert(!f.empty() && f[0] == mint(1));\n\
      \    if (precision == -1) precision = static_cast<int>(f.size());\n\n    std::vector<std::pair<int,\
      \ mint>> support;\n    for (int i = 1; i < static_cast<int>(f.size()); ++i)\
      \ {\n        if (f[i] != mint(0)) support.emplace_back(i, f[i]);\n    }\n  \
      \  ivta::set_upper(precision);\n\n    f.assign(precision, mint(0));\n    std::size_t\
      \ next_support = 0;\n    for (int k = 0; k < precision - 1; ++k) {\n       \
      \ for (const auto &[index, coefficient] : support) {\n            if (k < index)\
      \ break;\n            const int i = k - index;\n            f[k + 1] -= f[i\
      \ + 1] * coefficient * (i + 1);\n        }\n        f[k + 1] *= ivta::inv(k\
      \ + 1);\n        while (next_support < support.size() && support[next_support].first\
      \ < k + 1) ++next_support;\n        if (next_support < support.size() && support[next_support].first\
      \ == k + 1)\n            f[k + 1] += support[next_support].second;\n    }\n\
      \    return f;\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS sparse_log(const\
      \ FPS &f, int precision = -1) {\n    FPS result = f;\n    return inplace_sparse_log(result,\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS log(const\
      \ FPS &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n\
      \    assert(!f.empty() && f[0] == mint(1));\n    if (is_sparse_operation(\n\
      \            FPSOperation::LOG, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(),\
      \ precision))\n        return sparse_log(f, precision);\n    return dense_log(f,\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_log(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  assert(!f.empty() && f[0] == mint(1));\n    const bool use_sparse = is_sparse_operation(\n\
      \        FPSOperation::LOG, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), precision);\n\
      \    if (use_sparse) return inplace_sparse_log(f, precision);\n    return inplace_dense_log(f,\
      \ precision);\n}\n\n} // namespace kk2::fps::operations\n\n\n#line 1 \"fps/operations/multiplication.hpp\"\
      \n\n\n\n#line 1 \"convolution/convolution.hpp\"\n\n\n\n#line 8 \"convolution/convolution.hpp\"\
      \n\n#line 11 \"convolution/convolution.hpp\"\n\nnamespace kk2 {\n\ntemplate\
      \ <class FPS, class mint = typename FPS::value_type>\nFPS &inplace_sparse_convolution(FPS\
      \ &a, const FPS &b, int deg = -1) {\n    const int original_a_size = a.size(),\
      \ original_b_size = b.size();\n    if (!original_a_size || !original_b_size)\
      \ {\n        a.clear();\n        return a;\n    }\n    if (deg == -1) deg =\
      \ original_a_size + original_b_size - 1;\n    const int target = std::min(std::max(0,\
      \ deg), original_a_size + original_b_size - 1);\n    if (target == 0) {\n  \
      \      a.clear();\n        return a;\n    }\n\n    std::vector<std::pair<int,\
      \ mint>> support_b;\n    for (int i = 0; i < std::min(original_b_size, target);\
      \ ++i) {\n        if (b[i] != mint(0)) support_b.emplace_back(i, b[i]);\n  \
      \  }\n    a.resize(target);\n    for (int i = std::min(original_a_size, target)\
      \ - 1; i >= 0; --i) {\n        const mint coefficient = a[i];\n        a[i]\
      \ = mint(0);\n        if (coefficient == mint(0)) continue;\n        for (const\
      \ auto &[j, b_j] : support_b) {\n            if (i + j >= target) break;\n \
      \           a[i + j] += coefficient * b_j;\n        }\n    }\n    return a;\n\
      }\n\ntemplate <class FPS> FPS sparse_convolution(const FPS &a, const FPS &b,\
      \ int deg = -1) {\n    FPS result = a;\n    inplace_sparse_convolution(result,\
      \ b, deg);\n    return result;\n}\n\ntemplate <class FPS> FPS &inplace_dense_convolution(FPS\
      \ &a, const FPS &b, int deg = -1) {\n    const int original_a_size = a.size(),\
      \ original_b_size = b.size();\n    if (!original_a_size || !original_b_size)\
      \ {\n        a.clear();\n        return a;\n    }\n    if (deg == -1) deg =\
      \ original_a_size + original_b_size - 1;\n    const int target = std::min(std::max(0,\
      \ deg), original_a_size + original_b_size - 1);\n    if (target == 0) {\n  \
      \      a.clear();\n        return a;\n    }\n\n    const int n = std::min(original_a_size,\
      \ target);\n    const int m = std::min(original_b_size, target);\n\n    int\
      \ z = 1;\n    while (z < n + m - 1) z <<= 1;\n    if (std::addressof(a) == std::addressof(b))\
      \ {\n        a.resize(n);\n        a.resize(z);\n        butterfly(a);\n   \
      \     for (int i = 0; i < z; i++) a[i] *= a[i];\n    } else {\n        a.resize(n);\n\
      \        a.resize(z);\n        butterfly(a);\n        FPS t(b.begin(), b.begin()\
      \ + m);\n        t.resize(z);\n        butterfly(t);\n        for (int i = 0;\
      \ i < z; i++) a[i] *= t[i];\n    }\n    butterfly_inv(a);\n    a.resize(target);\n\
      \    return a;\n}\n\ntemplate <class FPS> FPS dense_convolution(const FPS &a,\
      \ const FPS &b, int deg = -1) {\n    FPS result = a;\n    inplace_dense_convolution(result,\
      \ b, deg);\n    return result;\n}\n\ntemplate <class FPS> FPS &inplace_convolution(FPS\
      \ &a, const FPS &b, int deg = -1) {\n    const bool use_sparse = is_sparse_operation(FPSOperation::CONVOLUTION,\
      \ true, a, b, deg);\n    if (use_sparse) return inplace_sparse_convolution(a,\
      \ b, deg);\n    return inplace_dense_convolution(a, b, deg);\n}\n\ntemplate\
      \ <class FPS> FPS convolution(const FPS &a, const FPS &b, int deg = -1) {\n\
      \    if (is_sparse_operation(FPSOperation::CONVOLUTION, true, a, b, deg))\n\
      \        return sparse_convolution(a, b, deg);\n    return dense_convolution(a,\
      \ b, deg);\n}\n\n} // namespace kk2\n\n\n#line 7 \"fps/operations/multiplication.hpp\"\
      \n\nnamespace kk2::fps::operations {\n\ntemplate <NTTFriendlyFormalPowerSeries\
      \ FPS>\nFPS &inplace_dense_mul(FPS &lhs, const FPS &rhs, int precision = -1)\
      \ {\n    return inplace_dense_convolution(lhs, rhs, precision);\n}\n\ntemplate\
      \ <ArbitraryModulusFormalPowerSeries FPS>\nFPS &inplace_dense_mul(FPS &lhs,\
      \ const FPS &rhs, int precision = -1);\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS>\nFPS dense_mul(const FPS &lhs, const FPS &rhs, int precision = -1) {\n\
      \    FPS result = lhs;\n    inplace_dense_mul(result, rhs, precision);\n   \
      \ return result;\n}\n\ntemplate <UnivariateFormalPowerSeries FPS>\nFPS &inplace_sparse_mul(FPS\
      \ &lhs, const FPS &rhs, int precision = -1) {\n    return inplace_sparse_convolution(lhs,\
      \ rhs, precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS>\nFPS sparse_mul(const\
      \ FPS &lhs, const FPS &rhs, int precision = -1) {\n    FPS result = lhs;\n \
      \   inplace_sparse_mul(result, rhs, precision);\n    return result;\n}\n\ntemplate\
      \ <UnivariateFormalPowerSeries FPS>\nFPS mul(const FPS &lhs, const FPS &rhs,\
      \ int precision = -1) {\n    if (is_sparse_operation(\n            FPSOperation::CONVOLUTION,\
      \ NTTFriendlyFormalPowerSeries<FPS>, lhs, rhs, precision))\n        return sparse_mul(lhs,\
      \ rhs, precision);\n    return dense_mul(lhs, rhs, precision);\n}\n\ntemplate\
      \ <UnivariateFormalPowerSeries FPS>\nFPS &inplace_mul(FPS &lhs, const FPS &rhs,\
      \ int precision = -1) {\n    const bool use_sparse = is_sparse_operation(\n\
      \        FPSOperation::CONVOLUTION, NTTFriendlyFormalPowerSeries<FPS>, lhs,\
      \ rhs, precision);\n    if (use_sparse) return inplace_sparse_mul(lhs, rhs,\
      \ precision);\n    return inplace_dense_mul(lhs, rhs, precision);\n}\n\n} //\
      \ namespace kk2::fps::operations\n\n\n#line 1 \"fps/operations/power.hpp\"\n\
      \n\n\n#include <tuple>\n#line 6 \"fps/operations/power.hpp\"\n\n#line 10 \"\
      fps/operations/power.hpp\"\n\nnamespace kk2::fps::operations {\n\nstruct PowerPreprocessResult\
      \ {\n    int precision;\n    int normalized_precision;\n    int shift;\n   \
      \ bool finished;\n};\n\ntemplate <UnivariateFormalPowerSeries FPS, Integral\
      \ T>\nPowerPreprocessResult inplace_power_preprocess(FPS &f, T exponent, int\
      \ precision) {\n    using mint = typename FPS::value_type;\n    if (precision\
      \ == -1) precision = static_cast<int>(f.size());\n    if (exponent == 0) {\n\
      \        f.assign(precision, mint(0));\n        if (precision > 0) f[0] = mint(1);\n\
      \        return {precision, 0, 0, true};\n    }\n\n    int leading_zeros = 0;\n\
      \    while (leading_zeros != static_cast<int>(f.size()) && f[leading_zeros]\
      \ == mint(0))\n        ++leading_zeros;\n    if (leading_zeros == static_cast<int>(f.size())\n\
      \        || __int128_t(leading_zeros) * exponent >= precision) {\n        f.assign(precision,\
      \ mint(0));\n        return {precision, 0, 0, true};\n    }\n\n    const int\
      \ shift = static_cast<int>(__int128_t(leading_zeros) * exponent);\n    if (leading_zeros\
      \ > 0) f.erase(f.begin(), f.begin() + leading_zeros);\n    return {precision,\
      \ precision - shift, shift, false};\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS>\nFPS &inplace_power_postprocess(FPS &f, const PowerPreprocessResult &preprocessed)\
      \ {\n    using mint = typename FPS::value_type;\n    if (preprocessed.shift\
      \ > 0) f.insert(f.begin(), preprocessed.shift, mint(0));\n    f.resize(preprocessed.precision);\n\
      \    return f;\n}\n\ntemplate <UnivariateFormalPowerSeries FPS, Integral T>\n\
      FPS &inplace_dense_pow_normalized(FPS &f, T exponent, int precision) {\n   \
      \ const auto leading_coefficient = f[0];\n    f *= leading_coefficient.inv();\n\
      \    f.inplace_dense_log(precision);\n    f *= exponent;\n    f.inplace_dense_exp(precision);\n\
      \    f *= leading_coefficient.pow(exponent);\n    return f;\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS, Integral T>\nFPS &inplace_sparse_pow_normalized(FPS &f, T exponent, int\
      \ precision) {\n    using mint = typename FPS::value_type;\n    const int mod\
      \ = mint::getmod();\n    static std::vector<mint> inverse{1, 1};\n    while\
      \ (static_cast<int>(inverse.size()) <= precision) {\n        const int i = inverse.size();\n\
      \        inverse.push_back(-inverse[mod % i] * (mod / i));\n    }\n\n    const\
      \ mint constant_term = f[0].pow(exponent);\n    exponent %= mod;\n    std::vector<std::tuple<int,\
      \ mint, mint>> support;\n    for (int i = 1; i < static_cast<int>(f.size());\
      \ ++i) {\n        if (f[i] != mint(0)) support.emplace_back(i, f[i], f[i] *\
      \ mint(i) * (exponent + 1));\n    }\n\n    const mint constant_inv = f[0].inv();\n\
      \    f.assign(precision, mint(0));\n    f[0] = constant_term;\n    for (int\
      \ degree = 1; degree < precision; ++degree) {\n        for (const auto &[index,\
      \ coefficient, weighted_coefficient] : support) {\n            if (degree <\
      \ index) break;\n            f[degree] += f[degree - index] * (weighted_coefficient\
      \ - coefficient * degree);\n        }\n        f[degree] *= constant_inv * inverse[degree];\n\
      \    }\n    return f;\n}\n\ntemplate <UnivariateFormalPowerSeries FPS>\nbool\
      \ power_uses_sparse(const FPS &normalized, int normalized_precision) {\n   \
      \ return is_sparse_operation(FPSOperation::POWER,\n                        \
      \       NTTFriendlyFormalPowerSeries<FPS>,\n                               normalized,\n\
      \                               FPS(),\n                               normalized_precision);\n\
      }\n\ntemplate <UnivariateFormalPowerSeries FPS, Integral T>\nFPS &inplace_dense_pow(FPS\
      \ &f, T exponent, int precision = -1) {\n    const PowerPreprocessResult preprocessed\
      \ = inplace_power_preprocess(f, exponent, precision);\n    if (preprocessed.finished)\
      \ return f;\n    inplace_dense_pow_normalized(f, exponent, preprocessed.normalized_precision);\n\
      \    return inplace_power_postprocess(f, preprocessed);\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS, Integral T>\nFPS dense_pow(const FPS &f, T exponent, int precision =\
      \ -1) {\n    FPS result = f;\n    inplace_dense_pow(result, exponent, precision);\n\
      \    return result;\n}\n\ntemplate <UnivariateFormalPowerSeries FPS, Integral\
      \ T>\nFPS &inplace_sparse_pow(FPS &f, T exponent, int precision = -1) {\n  \
      \  const PowerPreprocessResult preprocessed = inplace_power_preprocess(f, exponent,\
      \ precision);\n    if (preprocessed.finished) return f;\n    inplace_sparse_pow_normalized(f,\
      \ exponent, preprocessed.normalized_precision);\n    return inplace_power_postprocess(f,\
      \ preprocessed);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS, Integral T>\n\
      FPS sparse_pow(const FPS &f, T exponent, int precision = -1) {\n    FPS result\
      \ = f;\n    inplace_sparse_pow(result, exponent, precision);\n    return result;\n\
      }\n\ntemplate <UnivariateFormalPowerSeries FPS, Integral T>\nFPS &inplace_pow(FPS\
      \ &f, T exponent, int precision = -1) {\n    const PowerPreprocessResult preprocessed\
      \ = inplace_power_preprocess(f, exponent, precision);\n    if (preprocessed.finished)\
      \ return f;\n    if (power_uses_sparse(f, preprocessed.normalized_precision))\n\
      \        inplace_sparse_pow_normalized(f, exponent, preprocessed.normalized_precision);\n\
      \    else inplace_dense_pow_normalized(f, exponent, preprocessed.normalized_precision);\n\
      \    return inplace_power_postprocess(f, preprocessed);\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS, Integral T>\nFPS pow(const FPS &f, T exponent, int precision = -1) {\n\
      \    FPS result = f;\n    inplace_pow(result, exponent, precision);\n    return\
      \ result;\n}\n\n} // namespace kk2::fps::operations\n\n\n#line 1 \"fps/operations/sqrt.hpp\"\
      \n\n\n\n#line 6 \"fps/operations/sqrt.hpp\"\n\n#line 1 \"math_mod/detail/mod_sqrt.hpp\"\
      \n\n\n\n#line 5 \"math_mod/detail/mod_sqrt.hpp\"\n\nnamespace kk2::mod_sqrt_detail\
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
      \ z, m, e);\n}\n\n} // namespace kk2::mod_sqrt_detail\n\n\n#line 11 \"fps/operations/sqrt.hpp\"\
      \n\nnamespace kk2::fps::operations {\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS> FPS dense_sqrt(const FPS &f, int precision = -1) {\n    using mint =\
      \ typename FPS::value_type;\n    if (precision == -1) precision = static_cast<int>(f.size());\n\
      \    if (f.empty()) return FPS(precision, mint(0));\n    if (f[0] == mint(0))\
      \ {\n        for (int i = 1; i < static_cast<int>(f.size()); ++i) {\n      \
      \      if (f[i] == mint(0)) continue;\n            if (i & 1) return {};\n \
      \           if (precision - i / 2 <= 0) break;\n            FPS result = dense_sqrt(f\
      \ >> i, precision - i / 2);\n            if (result.empty()) return {};\n  \
      \          result <<= i / 2;\n            if (static_cast<int>(result.size())\
      \ < precision) result.resize(precision, mint(0));\n            return result;\n\
      \        }\n        return FPS(precision, mint(0));\n    }\n\n    const long\
      \ long root = mod_sqrt_detail::mod_sqrt<NTTFriendlyFormalPowerSeries<FPS>>(f[0]);\n\
      \    if (root == -1) return {};\n    assert(root * root % mint::getmod() ==\
      \ f[0].val());\n    FPS result{mint(root)};\n    const mint inverse_two = mint(2).inv();\n\
      \    for (int d = 1; d < precision; d <<= 1) {\n        result = (result + f.pre(d\
      \ << 1).dense_mul(result.dense_inv(d << 1))) * inverse_two;\n    }\n    return\
      \ result.pre(precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS\
      \ &inplace_dense_sqrt(FPS &f, int precision = -1) {\n    if (precision == -1)\
      \ precision = static_cast<int>(f.size());\n    return f = dense_sqrt(std::as_const(f),\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_sparse_sqrt(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  if (precision == -1) precision = static_cast<int>(f.size());\n    if (f.empty())\
      \ {\n        f.assign(precision, mint(0));\n        return f;\n    }\n    if\
      \ (f[0] == mint(0)) {\n        for (int i = 1; i < static_cast<int>(f.size());\
      \ ++i) {\n            if (f[i] == mint(0)) continue;\n            if (i & 1)\
      \ {\n                f.clear();\n                return f;\n            }\n\
      \            if (precision - i / 2 <= 0) break;\n            f >>= i;\n    \
      \        inplace_sparse_sqrt(f, precision - i / 2);\n            if (f.empty())\
      \ return f;\n            f <<= i / 2;\n            if (static_cast<int>(f.size())\
      \ < precision) f.resize(precision, mint(0));\n            return f;\n      \
      \  }\n        f.assign(precision, mint(0));\n        return f;\n    }\n\n  \
      \  const long long root = mod_sqrt_detail::mod_sqrt<NTTFriendlyFormalPowerSeries<FPS>>(f[0]);\n\
      \    if (root == -1) {\n        f.clear();\n        return f;\n    }\n    return\
      \ inplace_sparse_pow(f, (mint::getmod() + 1) >> 1, precision) *= mint(root).inv();\n\
      }\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS sparse_sqrt(const FPS &f,\
      \ int precision = -1) {\n    FPS result = f;\n    return inplace_sparse_sqrt(result,\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS sqrt(const\
      \ FPS &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n\
      \    if (!f.empty() && f[0] != mint(0)\n        && is_sparse_operation(\n  \
      \          FPSOperation::SQRT, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(),\
      \ precision))\n        return sparse_sqrt(f, precision);\n    return dense_sqrt(f,\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_sqrt(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  const bool use_sparse =\n        !f.empty() && f[0] != mint(0)\n        &&\
      \ is_sparse_operation(\n            FPSOperation::SQRT, NTTFriendlyFormalPowerSeries<FPS>,\
      \ f, FPS(), precision);\n    if (use_sparse) return inplace_sparse_sqrt(f, precision);\n\
      \    return inplace_dense_sqrt(f, precision);\n}\n\n} // namespace kk2::fps::operations\n\
      \n\n#line 19 \"fps/fps_base.hpp\"\n\nnamespace kk2 {\n\ntemplate <class Derived,\
      \ fps::Modular mint> struct FormalPowerSeriesBase : std::vector<mint> {\n  \
      \  using std::vector<mint>::vector;\n    using FPS = Derived;\n    using ivta\
      \ = InvTable<mint>;\n\n    // CRTP\u3092\u4F7F\u3063\u3066\u6D3E\u751F\u30AF\
      \u30E9\u30B9\u306E\u53C2\u7167\u3092\u53D6\u5F97\n    Derived &derived() { return\
      \ static_cast<Derived &>(*this); }\n    const Derived &derived() const { return\
      \ static_cast<const Derived &>(*this); }\n\n    template <OutputStream OStream>\
      \ void debug_output(OStream &os) const {\n        os << \"[\";\n        for\
      \ (size_t i = 0; i < this->size(); i++) {\n            os << (*this)[i] << (i\
      \ + 1 == this->size() ? \"\" : \", \");\n        }\n        os << \"]\";\n \
      \   }\n\n    template <OutputStream OStream> void output(OStream &os) const\
      \ {\n        for (size_t i = 0; i < this->size(); i++) {\n            os <<\
      \ (*this)[i] << (i + 1 == this->size() ? \"\\n\" : \" \");\n        }\n    }\n\
      \    template <OutputStream OStream> friend OStream &operator<<(OStream &os,\
      \ const FPS &fps_) {\n        for (size_t i = 0; i < fps_.size(); i++) {\n \
      \           os << fps_[i] << (i + 1 == fps_.size() ? \"\" : \" \");\n      \
      \  }\n        return os;\n    }\n\n    template <InputStream IStream> FPS &input(IStream\
      \ &is) {\n        for (size_t i = 0; i < this->size(); i++) is >> (*this)[i];\n\
      \        return derived();\n    }\n\n    template <InputStream IStream> friend\
      \ IStream &operator>>(IStream &is, FPS &fps_) {\n        for (auto &x : fps_)\
      \ is >> x;\n        return is;\n    }\n    FPS &operator+=(const FPS &r) {\n\
      \        if (this->size() < r.size()) this->resize(r.size());\n        for (size_t\
      \ i = 0; i < r.size(); i++) (*this)[i] += r[i];\n        return derived();\n\
      \    }\n\n    FPS &operator+=(const mint &r) {\n        if (this->empty()) this->resize(1);\n\
      \        (*this)[0] += r;\n        return derived();\n    }\n\n    FPS &operator-=(const\
      \ FPS &r) {\n        if (this->size() < r.size()) this->resize(r.size());\n\
      \        for (size_t i = 0; i < r.size(); i++) (*this)[i] -= r[i];\n       \
      \ return derived();\n    }\n\n    FPS &operator-=(const mint &r) {\n       \
      \ if (this->empty()) this->resize(1);\n        (*this)[0] -= r;\n        return\
      \ derived();\n    }\n\n    FPS &operator*=(const mint &r) {\n        for (size_t\
      \ i = 0; i < this->size(); i++) { (*this)[i] *= r; }\n        return derived();\n\
      \    }\n    FPS &operator*=(const FPS &r) { return inplace_mul(r); }\n    FPS\
      \ &operator/=(const FPS &r) { return inplace_quo(r); }\n\n    FPS dense_quo(const\
      \ FPS &r) const { return fps::operations::dense_quo(derived(), r); }\n    FPS\
      \ &inplace_dense_quo(const FPS &r) {\n        return fps::operations::inplace_dense_quo(derived(),\
      \ r);\n    }\n    FPS sparse_quo(const FPS &r) const { return fps::operations::sparse_quo(derived(),\
      \ r); }\n    FPS &inplace_sparse_quo(const FPS &r) {\n        return fps::operations::inplace_sparse_quo(derived(),\
      \ r);\n    }\n    FPS quo(const FPS &r) const { return fps::operations::quo(derived(),\
      \ r); }\n    FPS &inplace_quo(const FPS &r) { return fps::operations::inplace_quo(derived(),\
      \ r); }\n    FPS dense_mod(const FPS &r) const { return fps::operations::dense_mod(derived(),\
      \ r); }\n    FPS &inplace_dense_mod(const FPS &r) {\n        return fps::operations::inplace_dense_mod(derived(),\
      \ r);\n    }\n    FPS sparse_mod(const FPS &r) const { return fps::operations::sparse_mod(derived(),\
      \ r); }\n    FPS &inplace_sparse_mod(const FPS &r) {\n        return fps::operations::inplace_sparse_mod(derived(),\
      \ r);\n    }\n    FPS mod(const FPS &r) const { return fps::operations::mod(derived(),\
      \ r); }\n    FPS &inplace_mod(const FPS &r) { return fps::operations::inplace_mod(derived(),\
      \ r); }\n\n    FPS &operator%=(const FPS &r) { return inplace_mod(r); }\n\n\
      \    FPS &operator>>=(int n) {\n        if (n >= (int)this->size()) {\n    \
      \        this->clear();\n        } else {\n            this->erase(this->begin(),\
      \ this->begin() + n);\n        }\n        return derived();\n    }\n\n    FPS\
      \ &operator<<=(int n) {\n        this->insert(this->begin(), n, mint(0));\n\
      \        return derived();\n    }\n\n    // CRTP\u3092\u4F7F\u3063\u3066\u6D3E\
      \u751F\u30AF\u30E9\u30B9\u306E\u30E1\u30BD\u30C3\u30C9\u3092\u5229\u7528\u3057\
      \u305F\u6F14\u7B97\u5B50\u306E\u81EA\u52D5\u5B9F\u88C5\n    FPS operator+(const\
      \ FPS &r) const { return FPS(derived()) += r; }\n    FPS operator+(const mint\
      \ &r) const { return FPS(derived()) += r; }\n    FPS operator-(const FPS &r)\
      \ const { return FPS(derived()) -= r; }\n    FPS operator-(const mint &r) const\
      \ { return FPS(derived()) -= r; }\n    FPS operator*(const FPS &r) const { return\
      \ FPS(derived()) *= r; }\n    FPS operator*(const mint &r) const { return FPS(derived())\
      \ *= r; }\n    FPS operator/(const FPS &r) const { return FPS(derived()) /=\
      \ r; }\n    FPS operator%(const FPS &r) const { return FPS(derived()) %= r;\
      \ }\n    FPS operator>>(int n) const { return FPS(derived()) >>= n; }\n    FPS\
      \ operator<<(int n) const { return FPS(derived()) <<= n; }\n\n    FPS operator-()\
      \ const {\n        FPS ret(this->size());\n        std::ranges::transform(\n\
      \            *this, ret.begin(), [](const mint &coefficient) { return -coefficient;\
      \ });\n        return ret;\n    }\n    FPS &shrink() {\n        while (this->size()\
      \ && this->back() == mint(0)) this->pop_back();\n        return derived();\n\
      \    }\n\n    FPS &inplace_rev() {\n        std::reverse(this->begin(), this->end());\n\
      \        return derived();\n    }\n\n    FPS &inplace_dot(const FPS &r) {\n\
      \        this->resize(std::min(this->size(), r.size()));\n        for (size_t\
      \ i = 0; i < this->size(); i++) (*this)[i] *= r[i];\n        return derived();\n\
      \    }\n\n    FPS &inplace_pre(int n) {\n        this->resize(n);\n        return\
      \ derived();\n    }\n\n    FPS &inplace_diff() {\n        if (this->empty())\
      \ return derived();\n        this->erase(this->begin());\n        for (size_t\
      \ i = 1; i <= this->size(); i++) (*this)[i - 1] *= mint(i);\n        return\
      \ derived();\n    }\n\n    FPS &inplace_int() {\n        ivta::set_upper(this->size());\n\
      \        this->insert(this->begin(), mint(0));\n        for (size_t i = 1; i\
      \ < this->size(); i++) (*this)[i] *= ivta::inv(i);\n        return derived();\n\
      \    }\n\n    // CRTP\u3092\u4F7F\u3063\u305F\u4FBF\u5229\u95A2\u6570\u306E\u81EA\
      \u52D5\u5B9F\u88C5\n    FPS rev() const { return FPS(derived()).inplace_rev();\
      \ }\n    FPS dot(const FPS &r) const { return FPS(derived()).inplace_dot(r);\
      \ }\n    FPS pre(int n) const { return FPS(derived()).inplace_pre(n); }\n  \
      \  FPS diff() const { return FPS(derived()).inplace_diff(); }\n    FPS integral()\
      \ const { return FPS(derived()).inplace_int(); }\n\n    mint eval(mint x) const\
      \ {\n        mint r = 0, w = 1;\n        for (auto &v : *this) {\n         \
      \   r += w * v;\n            w *= x;\n        }\n        return r;\n    }\n\n\
      \    FPS dense_log(int precision = -1) const {\n        return fps::operations::dense_log(derived(),\
      \ precision);\n    }\n    FPS &inplace_dense_log(int precision = -1) {\n   \
      \     return fps::operations::inplace_dense_log(derived(), precision);\n   \
      \ }\n    FPS sparse_log(int precision = -1) const {\n        return fps::operations::sparse_log(derived(),\
      \ precision);\n    }\n    FPS &inplace_sparse_log(int precision = -1) {\n  \
      \      return fps::operations::inplace_sparse_log(derived(), precision);\n \
      \   }\n    FPS log(int precision = -1) const { return fps::operations::log(derived(),\
      \ precision); }\n    FPS &inplace_log(int precision = -1) {\n        return\
      \ fps::operations::inplace_log(derived(), precision);\n    }\n\n    template\
      \ <Integral T> FPS dense_pow(T exponent, int precision = -1) const {\n     \
      \   return fps::operations::dense_pow(derived(), exponent, precision);\n   \
      \ }\n    template <Integral T> FPS &inplace_dense_pow(T exponent, int precision\
      \ = -1) {\n        return fps::operations::inplace_dense_pow(derived(), exponent,\
      \ precision);\n    }\n    template <Integral T> FPS sparse_pow(T exponent, int\
      \ precision = -1) const {\n        return fps::operations::sparse_pow(derived(),\
      \ exponent, precision);\n    }\n    template <Integral T> FPS &inplace_sparse_pow(T\
      \ exponent, int precision = -1) {\n        return fps::operations::inplace_sparse_pow(derived(),\
      \ exponent, precision);\n    }\n    template <Integral T> FPS pow(T exponent,\
      \ int precision = -1) const {\n        return fps::operations::pow(derived(),\
      \ exponent, precision);\n    }\n    template <Integral T> FPS &inplace_pow(T\
      \ exponent, int precision = -1) {\n        return fps::operations::inplace_pow(derived(),\
      \ exponent, precision);\n    }\n\n    FPS dense_div(const FPS &r, int precision\
      \ = -1) const {\n        return fps::operations::dense_div(derived(), r, precision);\n\
      \    }\n    FPS &inplace_dense_div(const FPS &r, int precision = -1) {\n   \
      \     return fps::operations::inplace_dense_div(derived(), r, precision);\n\
      \    }\n    FPS sparse_div(const FPS &r, int precision = -1) const {\n     \
      \   return fps::operations::sparse_div(derived(), r, precision);\n    }\n  \
      \  FPS &inplace_sparse_div(const FPS &r, int precision = -1) {\n        return\
      \ fps::operations::inplace_sparse_div(derived(), r, precision);\n    }\n   \
      \ FPS div(const FPS &r, int precision = -1) const {\n        return fps::operations::div(derived(),\
      \ r, precision);\n    }\n    FPS &inplace_div(const FPS &r, int precision =\
      \ -1) {\n        return fps::operations::inplace_div(derived(), r, precision);\n\
      \    }\n\n    FPS dense_inv(int precision = -1) const {\n        return fps::operations::dense_inv(derived(),\
      \ precision);\n    }\n    FPS &inplace_dense_inv(int precision = -1) {\n   \
      \     return fps::operations::inplace_dense_inv(derived(), precision);\n   \
      \ }\n    FPS sparse_inv(int precision = -1) const {\n        return fps::operations::sparse_inv(derived(),\
      \ precision);\n    }\n    FPS &inplace_sparse_inv(int precision = -1) {\n  \
      \      return fps::operations::inplace_sparse_inv(derived(), precision);\n \
      \   }\n    FPS inv(int precision = -1) const { return fps::operations::inv(derived(),\
      \ precision); }\n    FPS &inplace_inv(int precision = -1) {\n        return\
      \ fps::operations::inplace_inv(derived(), precision);\n    }\n\n    FPS dense_exp(int\
      \ precision = -1) const {\n        return fps::operations::dense_exp(derived(),\
      \ precision);\n    }\n    FPS &inplace_dense_exp(int precision = -1) {\n   \
      \     return fps::operations::inplace_dense_exp(derived(), precision);\n   \
      \ }\n    FPS sparse_exp(int precision = -1) const {\n        return fps::operations::sparse_exp(derived(),\
      \ precision);\n    }\n    FPS &inplace_sparse_exp(int precision = -1) {\n  \
      \      return fps::operations::inplace_sparse_exp(derived(), precision);\n \
      \   }\n    FPS exp(int precision = -1) const { return fps::operations::exp(derived(),\
      \ precision); }\n    FPS &inplace_exp(int precision = -1) {\n        return\
      \ fps::operations::inplace_exp(derived(), precision);\n    }\n\n    FPS dense_sqrt(int\
      \ precision = -1) const {\n        return fps::operations::dense_sqrt(derived(),\
      \ precision);\n    }\n    FPS &inplace_dense_sqrt(int precision = -1) {\n  \
      \      return fps::operations::inplace_dense_sqrt(derived(), precision);\n \
      \   }\n    FPS sparse_sqrt(int precision = -1) const {\n        return fps::operations::sparse_sqrt(derived(),\
      \ precision);\n    }\n    FPS &inplace_sparse_sqrt(int precision = -1) {\n \
      \       return fps::operations::inplace_sparse_sqrt(derived(), precision);\n\
      \    }\n    FPS sqrt(int precision = -1) const { return fps::operations::sqrt(derived(),\
      \ precision); }\n    FPS &inplace_sqrt(int precision = -1) {\n        return\
      \ fps::operations::inplace_sqrt(derived(), precision);\n    }\n\n    FPS dense_mul(const\
      \ FPS &r, int precision = -1) const {\n        return fps::operations::dense_mul(derived(),\
      \ r, precision);\n    }\n    FPS &inplace_dense_mul(const FPS &r, int precision\
      \ = -1) {\n        return fps::operations::inplace_dense_mul(derived(), r, precision);\n\
      \    }\n    FPS sparse_mul(const FPS &r, int precision = -1) const {\n     \
      \   return fps::operations::sparse_mul(derived(), r, precision);\n    }\n  \
      \  FPS &inplace_sparse_mul(const FPS &r, int precision = -1) {\n        return\
      \ fps::operations::inplace_sparse_mul(derived(), r, precision);\n    }\n   \
      \ FPS mul(const FPS &r, int precision = -1) const {\n        return fps::operations::mul(derived(),\
      \ r, precision);\n    }\n    FPS &inplace_mul(const FPS &r, int precision =\
      \ -1) {\n        return fps::operations::inplace_mul(derived(), r, precision);\n\
      \    }\n\n    FPS &inplace_imos(int n) {\n        inplace_pre(n);\n        for\
      \ (int i = 0; i < n - 1; i++) (*this)[i + 1] += (*this)[i];\n        return\
      \ derived();\n    }\n\n    FPS &inplace_iimos(int n) {\n        inplace_pre(n);\n\
      \        for (int i = 0; i < n - 1; i++) (*this)[i + 1] -= (*this)[i];\n   \
      \     return derived();\n    }\n    FPS imos(int n) const { return FPS(derived()).inplace_imos(n);\
      \ }\n    FPS iimos(int n) const { return FPS(derived()).inplace_iimos(n); }\n\
      };\n\n} // namespace kk2\n\n\n#line 6 \"fps/fps_ntt_friendly.hpp\"\n\nnamespace\
      \ kk2 {\n\ntemplate <fps::Modular mint>\nstruct FormalPowerSeriesNTTFriendly\n\
      \    : FormalPowerSeriesBase<FormalPowerSeriesNTTFriendly<mint>, mint> {\n \
      \   using base = FormalPowerSeriesBase<FormalPowerSeriesNTTFriendly<mint>, mint>;\n\
      \    using FPS = FormalPowerSeriesNTTFriendly<mint>;\n    using base::FormalPowerSeriesBase;\n\
      \    using base::operator*=; // \u57FA\u5E95\u30AF\u30E9\u30B9\u306Eoperator*=\u3092\
      \u7D99\u627F\n    using modulus_category = kk2::fps::category::ntt_friendly_modulus;\n\
      \    using series_category = kk2::fps::category::ordinary;\n    using variable_category\
      \ = kk2::fps::category::univariate;\n    static constexpr bool is_ntt_friendly\
      \ = true;\n\n    void but() { butterfly(*this); }\n    void ibut() { butterfly_inv(*this);\
      \ }\n    void db() { doubling(*this); }\n    static int but_pr() { return primitive_root<mint::getmod()>;\
      \ }\n};\n\ntemplate <fps::Modular mint> using FPSNTT = FormalPowerSeriesNTTFriendly<mint>;\n\
      \n} // namespace kk2\n\n\n#line 1 \"fps/poly_find_root.hpp\"\n\n\n\n#line 5\
      \ \"fps/poly_find_root.hpp\"\n\n#line 1 \"random/gen.hpp\"\n\n\n\n#line 6 \"\
      random/gen.hpp\"\n#include <numeric>\n#include <random>\n#include <unordered_set>\n\
      #line 10 \"random/gen.hpp\"\n\n#line 1 \"random/seed.hpp\"\n\n\n\n#include <chrono>\n\
      \nnamespace kk2 {\n\nnamespace random {\n\nusing u64 = unsigned long long;\n\
      \ninline u64 non_deterministic_seed() {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n\
      \                   std::chrono::high_resolution_clock::now().time_since_epoch())\n\
      \                   .count();\n    seed ^= reinterpret_cast<u64>(&seed);\n \
      \   seed ^= seed << 5;\n    seed ^= seed >> 41;\n    seed ^= seed << 20;\n \
      \   return seed;\n}\n\ninline u64 deterministic_seed() { return 5801799128519729247ull;\
      \ }\n\ninline u64 seed() {\n#if defined(KK2_RANDOM_DETERMINISTIC)\n    return\
      \ deterministic_seed();\n#else\n    return non_deterministic_seed();\n#endif\n\
      }\n\n} // namespace random\n\n} // namespace kk2\n\n\n#line 12 \"random/gen.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace random {\n\nusing i64 = long long;\nusing u64\
      \ = unsigned long long;\n\ninline u64 rng() {\n    static std::mt19937_64 mt(kk2::random::seed());\n\
      \    return mt();\n}\n\n// [l, r)\ninline i64 rng(i64 l, i64 r) {\n    assert(l\
      \ < r);\n    return l + rng() % (r - l);\n}\n\n// [l, r)\ntemplate <class T>\
      \ std::vector<T> random_vector(int n, T l, T r) {\n    std::vector<T> res(n);\n\
      \    for (int i = 0; i < n; i++) res[i] = rng(l, r);\n    return res;\n}\n\n\
      // [l, r)\nstd::vector<i64> distinct_rng(i64 l, i64 r, i64 n) {\n    assert(l\
      \ < r and n <= r - l);\n    std::unordered_set<i64> st;\n    for (i64 i = n;\
      \ i; --i) {\n        i64 m = rng(l, r + 1 - i);\n        if (st.find(m) != st.end())\
      \ m = r - i;\n        st.insert(m);\n    }\n    std::vector<i64> res(st.begin(),\
      \ st.end());\n    std::sort(res.begin(), res.end());\n    return res;\n}\n\n\
      template <class Iter> void shuffle(Iter first, Iter last) {\n    if (first ==\
      \ last) return;\n    int len = 1;\n    for (auto it = first + 1; it != last;\
      \ ++it) {\n        len++;\n        int j = rng(0, len);\n        if (j != len\
      \ - 1) std::iter_swap(first + j, it);\n    }\n}\n\ntemplate <class T> std::vector<T>\
      \ perm(int n) {\n    std::vector<T> res(n);\n    std::iota(res.begin(), res.end(),\
      \ T(0));\n    shuffle(res.begin(), res.end());\n    return res;\n}\n\ntemplate\
      \ <class T> std::vector<T> choices(int l, int r, int k) {\n    assert(l < r\
      \ and k <= r - l);\n    std::vector<T> res(r - l);\n    std::iota(res.begin(),\
      \ res.end(), T(l));\n    shuffle(res.begin(), res.end());\n    res.resize(k);\n\
      \    return res;\n}\n\n} // namespace random\n\n} // namespace kk2\n\n\n#line\
      \ 1 \"fps/mod_pow.hpp\"\n\n\n\n#line 5 \"fps/mod_pow.hpp\"\n\n#line 7 \"fps/mod_pow.hpp\"\
      \n\nnamespace kk2 {\n\n// return f ^ k mod g\ntemplate <class FPS, class mint\
      \ = typename FPS::value_type, Integral T>\nFPS mod_pow(T k, const FPS &f, const\
      \ FPS &g) {\n    // assert(!is_signed_v<T> || k >= 0);\n    assert(!g.empty());\n\
      \n    auto inv = g.rev().inv();\n    auto quo = [&](const FPS &poly) {\n   \
      \     if (poly.size() < g.size()) return FPS{};\n        int n = poly.size()\
      \ - g.size() + 1;\n        return (poly.rev().pre(n) * inv.pre(n)).pre(n).rev();\n\
      \    };\n    FPS res{1}, b(f);\n    while (k) {\n        if (k & 1) {\n    \
      \        res *= b;\n            res -= quo(res) * g;\n            res.shrink();\n\
      \        }\n        b *= b;\n        b -= quo(b) * g;\n        b.shrink();\n\
      \        k >>= 1;\n    }\n    return res;\n}\n\n} // namespace kk2\n\n\n#line\
      \ 1 \"fps/poly_gcd.hpp\"\n\n\n\n#line 5 \"fps/poly_gcd.hpp\"\n#include <array>\n\
      #line 7 \"fps/poly_gcd.hpp\"\n\nnamespace kk2 {\n\nnamespace poly_gcd_impl {\n\
      \ntemplate <class FPS> using Vec = std::array<FPS, 2>;\n\ntemplate <class FPS>\
      \ struct mat_poly {\n    FPS a00, a01, a10, a11;\n\n    mat_poly() = default;\n\
      \n    mat_poly(FPS a00_, FPS a01_, FPS a10_, FPS a11_) : a00(a00_), a01(a01_),\
      \ a10(a10_), a11(a11_) {}\n\n    mat_poly &operator*=(const mat_poly &r) {\n\
      \        FPS A00 = a00 * r.a00 + a01 * r.a10;\n        FPS A01 = a00 * r.a01\
      \ + a01 * r.a11;\n        FPS A10 = a10 * r.a00 + a11 * r.a10;\n        FPS\
      \ A11 = a10 * r.a01 + a11 * r.a11;\n        A00.shrink();\n        A01.shrink();\n\
      \        A10.shrink();\n        A11.shrink();\n        std::swap(a00, A00);\n\
      \        std::swap(a01, A01);\n        std::swap(a10, A10);\n        std::swap(a11,\
      \ A11);\n        return *this;\n    }\n\n    static mat_poly identity() { return\
      \ mat_poly(FPS{1}, FPS(), FPS(), FPS{1}); }\n\n    mat_poly operator*(const\
      \ mat_poly &r) const { return mat_poly(*this) *= r; }\n};\n\ntemplate <class\
      \ FPS> Vec<FPS> operator*(const mat_poly<FPS> &a, const Vec<FPS> &b) {\n   \
      \ FPS x0 = a.a00 * b[0] + a.a01 * b[1];\n    FPS x1 = a.a10 * b[0] + a.a11 *\
      \ b[1];\n    x0.shrink();\n    x1.shrink();\n    return {x0, x1};\n};\n\ntemplate\
      \ <class FPS> void inner_naive_gcd(mat_poly<FPS> &a, Vec<FPS> &b) {\n    FPS\
      \ quo = b[0] / b[1];\n    FPS rem = b[0] - quo * b[1];\n    FPS x10 = a.a00\
      \ - quo * a.a10;\n    FPS x11 = a.a01 - quo * a.a11;\n    rem.shrink();\n  \
      \  x10.shrink();\n    x11.shrink();\n    std::swap(x10, a.a10);\n    std::swap(x11,\
      \ a.a11);\n    std::swap(x10, a.a00);\n    std::swap(x11, a.a01);\n    b = {b[1],\
      \ rem};\n}\n\ntemplate <class FPS> mat_poly<FPS> inner_half_gcd(Vec<FPS> b)\
      \ {\n    int n = (int)b[0].size(), m = (int)b[1].size();\n    int k = (n + 1)\
      \ >> 1;\n    if (m <= k) return mat_poly<FPS>::identity();\n    mat_poly<FPS>\
      \ m1 = inner_half_gcd(Vec<FPS>{b[0] >> k, b[1] >> k});\n    b = m1 * b;\n  \
      \  if ((int)b[1].size() <= k) return m1;\n    inner_naive_gcd(m1, b);\n    if\
      \ ((int)b[1].size() <= k) return m1;\n    int l = (int)b[0].size() - 1;\n  \
      \  int j = 2 * k - l;\n    b[0] = b[0] >> j;\n    b[1] = b[1] >> j;\n    return\
      \ inner_half_gcd(b) * m1;\n}\n\ntemplate <class FPS> mat_poly<FPS> inner_poly_gcd(const\
      \ FPS &a, const FPS &b) {\n    Vec<FPS> c{a, b};\n    c[0].shrink();\n    c[1].shrink();\n\
      \    int n = (int)c[0].size(), m = (int)c[1].size();\n    if (n < m) {\n   \
      \     mat_poly<FPS> ret = inner_poly_gcd(c[1], c[0]);\n        std::swap(ret.a00,\
      \ ret.a01);\n        std::swap(ret.a10, ret.a11);\n        return ret;\n   \
      \ }\n\n    mat_poly<FPS> res = mat_poly<FPS>::identity();\n    while (1) {\n\
      \        mat_poly<FPS> m1 = inner_half_gcd(c);\n        c = m1 * c;\n      \
      \  if (c[1].empty()) return m1 * res;\n        inner_naive_gcd(m1, c);\n   \
      \     if (c[1].empty()) return m1 * res;\n        res = m1 * res;\n    }\n}\n\
      \ntemplate <class FPS> FPS poly_gcd(FPS a, FPS b) {\n    Vec<FPS> c{a, b};\n\
      \    mat_poly<FPS> m = inner_poly_gcd(a, b);\n    c = m * c;\n    if (!c[0].empty())\
      \ {\n        auto coeff = c[0].back().inv();\n        for (auto &x : c[0]) x\
      \ *= coeff;\n    }\n    return c[0];\n}\n\n// f ^ {-1} mod g\ntemplate <class\
      \ FPS> std::pair<bool, FPS> poly_inv(const FPS &f, const FPS &g) {\n    Vec<FPS>\
      \ c{f, g};\n    mat_poly<FPS> m = inner_poly_gcd(f, g);\n    FPS gcd_ = (m *\
      \ c)[0];\n    if (gcd_.size() != 1) return {0, FPS()};\n    Vec<FPS> x{FPS{1},\
      \ g};\n    return {1, ((m * x)[0] % g) * gcd_[0].inv()};\n}\n\n} // namespace\
      \ poly_gcd_impl\n\nusing poly_gcd_impl::poly_gcd;\nusing poly_gcd_impl::poly_inv;\n\
      \n} // namespace kk2\n\n\n#line 9 \"fps/poly_find_root.hpp\"\n\nnamespace kk2\
      \ {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\nstd::vector<mint>\
      \ find_root(const FPS &f) {\n    long long p = mint::getmod();\n    std::vector<mint>\
      \ res;\n    if (p == 2) {\n        for (int i = 0; i < 2; i++) {\n         \
      \   if (f.eval(mint(i)) == mint(0)) { res.push_back(mint(i)); }\n        }\n\
      \        return res;\n    }\n\n    std::vector<FPS> fs;\n    fs.push_back(poly_gcd(mod_pow(p,\
      \ FPS{0, 1}, f) - FPS{0, 1}, f));\n    while (!fs.empty()) {\n        auto g\
      \ = fs.back();\n        fs.pop_back();\n        if (g.size() == 2) res.push_back(-g[0]);\n\
      \        if (g.size() <= 2) continue;\n        FPS s = FPS{random::rng(0, p),\
      \ 1};\n        FPS t = poly_gcd(mod_pow((p - 1) / 2, s, g) - FPS{1}, g);\n \
      \       fs.push_back(t);\n        if (g.size() != t.size()) fs.push_back(g /\
      \ t);\n    }\n    return res;\n}\n\n} // namespace kk2\n\n\n#line 1 \"modint/mont.hpp\"\
      \n\n\n\n#line 8 \"modint/mont.hpp\"\n\n#line 11 \"modint/mont.hpp\"\n\nnamespace\
      \ kk2 {\n\ntemplate <int p> struct LazyMontgomeryModInt {\n    using mint =\
      \ LazyMontgomeryModInt;\n    using i32 = int32_t;\n    using i64 = int64_t;\n\
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
      \ namespace kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#line 6 \"template/template.hpp\"\
      \n#include <bitset>\n#line 9 \"template/template.hpp\"\n#include <cmath>\n#include\
      \ <deque>\n#include <functional>\n#include <iterator>\n#include <limits>\n#include\
      \ <map>\n#line 16 \"template/template.hpp\"\n#include <optional>\n#include <queue>\n\
      #line 19 \"template/template.hpp\"\n#include <set>\n#include <stack>\n#include\
      \ <string>\n#include <unordered_map>\n#line 26 \"template/template.hpp\"\n\n\
      #line 1 \"template/constant.hpp\"\n\n\n\n#line 1 \"template/type_alias.hpp\"\
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
      \ const S &b) { return (a > b ? a = b, 1 : 0); }\n\n\n#line 7 \"verify/yosupo_fps/poly_root_finding.test.cpp\"\
      \nusing namespace std;\n\nusing FPS = kk2::FPSNTT<kk2::mont998>;\n\nint main()\
      \ {\n    int n;\n    kin >> n;\n    FPS f(n + 1);\n    kin >> f;\n    auto res\
      \ = kk2::find_root(f);\n    kout << res.size() << kendl;\n    kout << res <<\
      \ kendl;\n\n    return 0;\n}\n"
    name: bundled
  isFailed: false
  isVerificationFile: true
  path: verify/yosupo_fps/poly_root_finding.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases:
  - elapsed: 10.048450367000015
    environment: g++
    memory: 4.532
    name: all_distinct_00
    status: AC
  - elapsed: 10.235325267000007
    environment: g++
    memory: 4.392
    name: all_distinct_01
    status: AC
  - elapsed: 10.286153189999993
    environment: g++
    memory: 4.264
    name: all_distinct_02
    status: AC
  - elapsed: 10.094708106999974
    environment: g++
    memory: 4.428
    name: all_distinct_03
    status: AC
  - elapsed: 9.929571142999976
    environment: g++
    memory: 4.428
    name: all_distinct_04
    status: AC
  - elapsed: 10.290447287000006
    environment: g++
    memory: 4.424
    name: all_distinct_05
    status: AC
  - elapsed: 9.986063280999986
    environment: g++
    memory: 4.532
    name: all_distinct_06
    status: AC
  - elapsed: 10.182519627000033
    environment: g++
    memory: 4.42
    name: all_distinct_07
    status: AC
  - elapsed: 10.536493968999991
    environment: g++
    memory: 4.372
    name: all_distinct_08
    status: AC
  - elapsed: 10.158639565999977
    environment: g++
    memory: 4.424
    name: all_distinct_09
    status: AC
  - elapsed: 0.5848957909999513
    environment: g++
    memory: 4.152
    name: all_same_00
    status: AC
  - elapsed: 0.0026525440000000344
    environment: g++
    memory: 3.752
    name: deg0_00
    status: AC
  - elapsed: 0.0029267369999956827
    environment: g++
    memory: 3.752
    name: example_00
    status: AC
  - elapsed: 0.0025899229999595264
    environment: g++
    memory: 3.796
    name: example_01
    status: AC
  - elapsed: 0.002805899000009049
    environment: g++
    memory: 3.78
    name: example_02
    status: AC
  - elapsed: 0.007666715999960161
    environment: g++
    memory: 3.788
    name: example_03
    status: AC
  - elapsed: 2.625163784999984
    environment: g++
    memory: 4.428
    name: max_random_00
    status: AC
  - elapsed: 1.5949234530000354
    environment: g++
    memory: 4.392
    name: max_random_01
    status: AC
  - elapsed: 1.6005306819999987
    environment: g++
    memory: 4.376
    name: max_random_02
    status: AC
  - elapsed: 3.7665770810000367
    environment: g++
    memory: 4.428
    name: max_random_03
    status: AC
  - elapsed: 7.299481326999967
    environment: g++
    memory: 4.428
    name: max_random_04
    status: AC
  - elapsed: 3.8390288890000193
    environment: g++
    memory: 4.428
    name: max_random_05
    status: AC
  - elapsed: 2.8857262619999915
    environment: g++
    memory: 4.424
    name: max_random_06
    status: AC
  - elapsed: 2.963557934999983
    environment: g++
    memory: 4.428
    name: max_random_07
    status: AC
  - elapsed: 4.673145704000035
    environment: g++
    memory: 4.524
    name: max_random_08
    status: AC
  - elapsed: 1.596688610000001
    environment: g++
    memory: 4.428
    name: max_random_09
    status: AC
  - elapsed: 0.0029409510000277805
    environment: g++
    memory: 3.768
    name: small_random_00
    status: AC
  - elapsed: 0.0031926109999744767
    environment: g++
    memory: 3.784
    name: small_random_01
    status: AC
  - elapsed: 0.0037945860000263565
    environment: g++
    memory: 3.744
    name: small_random_02
    status: AC
  - elapsed: 0.0023475790000020424
    environment: g++
    memory: 3.8
    name: small_random_03
    status: AC
  - elapsed: 0.0026881400000320355
    environment: g++
    memory: 3.804
    name: small_random_04
    status: AC
  - elapsed: 0.004835585000023457
    environment: g++
    memory: 3.788
    name: small_random_05
    status: AC
  - elapsed: 0.0038556349999794293
    environment: g++
    memory: 3.78
    name: small_random_06
    status: AC
  - elapsed: 0.0036210700000083307
    environment: g++
    memory: 3.804
    name: small_random_07
    status: AC
  - elapsed: 0.0036853050000331677
    environment: g++
    memory: 3.788
    name: small_random_08
    status: AC
  - elapsed: 0.0023263580000048023
    environment: g++
    memory: 3.78
    name: small_random_09
    status: AC
  timestamp: '2026-09-15 18:49:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_fps/poly_root_finding.test.cpp
layout: document
---
