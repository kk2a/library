---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: type_alias.hpp
      icon: LIBRARY_ALL_AC
      path: common/type_alias.hpp
    - filename: convolution.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution.hpp
    - filename: poly_sample_point_shift.hpp
      icon: LIBRARY_ALL_AC
      path: fps/detail/poly_sample_point_shift.hpp
    - filename: fps_sparsity_detector.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_sparsity_detector.hpp
    - filename: poly_sample_point_evaluate.hpp
      icon: LIBRARY_ALL_AC
      path: fps/poly_sample_point_evaluate.hpp
    - filename: butterfly.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/butterfly.hpp
    - filename: comb.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/comb.hpp
    - filename: inv_table.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/inv_table.hpp
    - filename: pow_mod.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/pow_mod.hpp
    - filename: primitive_root.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/primitive_root.hpp
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    - filename: modint.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/modint.hpp
    type: Depends on
  - files:
    - filename: comb_large.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/comb_large.hpp
    - filename: large_fact_arb_mod.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
    - filename: poly_sample_point_shift.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_fps/poly_sample_point_shift.test.cpp
    type: Required by
  - files:
    - filename: poly_sample_point_evaluate.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/poly_sample_point_evaluate.test.cpp
    - filename: many_factrials.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/many_factrials.test.cpp
    type: Verified with
  dependsOn:
  - common/type_alias.hpp
  - convolution/convolution.hpp
  - fps/detail/poly_sample_point_shift.hpp
  - fps/fps_sparsity_detector.hpp
  - fps/poly_sample_point_evaluate.hpp
  - math_mod/butterfly.hpp
  - math_mod/comb.hpp
  - math_mod/inv_table.hpp
  - math_mod/pow_mod.hpp
  - math_mod/primitive_root.hpp
  - type_traits/integral.hpp
  - type_traits/modint.hpp
  embedded:
  - code: "#ifndef KK2_FPS_POLY_SAMPLE_POINT_SHIFT_HPP\n#define KK2_FPS_POLY_SAMPLE_POINT_SHIFT_HPP\
      \ 1\n\n#include <vector>\n\n#include \"../convolution/convolution.hpp\"\n#include\
      \ \"../type_traits/modint.hpp\"\n#include \"detail/poly_sample_point_shift.hpp\"\
      \n\nnamespace kk2 {\n\n/**\n * @brief `return f(t), ..., f(t + m - 1) where\
      \ f(i) = y[i]`\n *\n */\ntemplate <modint::Modular mint>\nstd::vector<mint>\
      \ sample_point_shift(\n    const std::vector<mint> &y,\n    mint t,\n    i32\
      \ m = -1,\n    detail::SamplePointShiftConvolution<mint> convolve = &convolution<std::vector<mint>>)\
      \ {\n    return detail::sample_point_shift(y, t, m, convolve);\n}\n\n} // namespace\
      \ kk2\n\n#endif // KK2_FPS_POLY_SAMPLE_POINT_SHIFT_HPP\n"
    name: default
  - code: "#line 1 \"fps/poly_sample_point_shift.hpp\"\n\n\n\n#include <vector>\n\n\
      #line 1 \"convolution/convolution.hpp\"\n\n\n\n#include <algorithm>\n#include\
      \ <memory>\n#include <utility>\n#line 8 \"convolution/convolution.hpp\"\n\n\
      #line 1 \"fps/fps_sparsity_detector.hpp\"\n\n\n\n#line 5 \"fps/fps_sparsity_detector.hpp\"\
      \n#include <bit>\n#include <cstdint>\n#line 8 \"fps/fps_sparsity_detector.hpp\"\
      \n#include <ranges>\n\nnamespace kk2 {\n\nenum class FPSOperation {\n    CONVOLUTION,\n\
      \    LOG,\n    POWER,\n    DIVISION,\n    POLYNOMIAL_DIVISION,\n    INVERSE,\n\
      \    EXP,\n    SQRT\n};\n\nnamespace fps::sparsity_detail {\n\n// E(n): the\
      \ leading FFT evaluation cost, up to the common field-operation\n// constant\
      \ that cancels when dense and sparse leading terms are compared.\ninline std::int64_t\
      \ evaluation_work(int n) {\n    if (n <= 1) return 1;\n    const unsigned z\
      \ = std::bit_ceil(static_cast<unsigned>(n));\n    return static_cast<std::int64_t>(z)\
      \ * std::countr_zero(z);\n}\n\ninline int transform_size(int n, int m) {\n \
      \   if (n <= 0 || m <= 0) return 0;\n    return static_cast<int>(std::bit_ceil(static_cast<unsigned>(n\
      \ + m - 1)));\n}\n\ninline std::int64_t\nconvolution_dense_work(int n, int m,\
      \ int precision, bool same, bool ntt_friendly) {\n    n = std::min(n, precision);\n\
      \    m = std::min(m, precision);\n    const int z = transform_size(n, m);\n\
      \    if (z == 0) return 0;\n\n    // A different pair needs two forward and\
      \ one inverse transform. Squaring\n    // reuses the forward transform and needs\
      \ only one forward transform.\n    const int transforms = same ? 2 : 3;\n  \
      \  // Arbitrary-modulus convolution uses three NTT-friendly moduli.\n    const\
      \ int moduli = ntt_friendly ? 1 : 3;\n    return static_cast<std::int64_t>(transforms)\
      \ * moduli * evaluation_work(z);\n}\n\ninline std::int64_t inverse_dense_work(int\
      \ precision, bool ntt_friendly) {\n    if (precision <= 1) return 0;\n    const\
      \ int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(precision)));\n\
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
      \ is_ntt_friendly) * sparse_work;\n}\n\n} // namespace kk2\n\n\n#line 1 \"math_mod/butterfly.hpp\"\
      \n\n\n\n#line 5 \"math_mod/butterfly.hpp\"\n#include <cassert>\n#include <cstddef>\n\
      #line 8 \"math_mod/butterfly.hpp\"\n\n#line 1 \"math_mod/primitive_root.hpp\"\
      \n\n\n\n#line 1 \"math_mod/pow_mod.hpp\"\n\n\n\n#line 5 \"math_mod/pow_mod.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow_mod(T\
      \ x, U n, T m) {\n    assert(n >= 0);\n    if (m == 1) return S(0);\n    S _m\
      \ = m, r = 1;\n    S y = x % _m;\n    if (y < 0) y += _m;\n    while (n) {\n\
      \        if (n & 1) r = (r * y) % _m;\n        if (n >>= 1) y = (y * y) % _m;\n\
      \    }\n    return r;\n}\n\n} // namespace kk2\n\n\n#line 5 \"math_mod/primitive_root.hpp\"\
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
      \n#line 10 \"math_mod/butterfly.hpp\"\n\nnamespace kk2 {\n\nnamespace detail\
      \ {\n\ntemplate <class mint> int butterfly_log_size(std::size_t n) {\n    assert((n\
      \ > 0 && (n & (n - 1)) == 0) && \"butterfly size must be a power of two\");\n\
      \    assert(n < (std::size_t{1} << 30) && \"butterfly size is too large\");\n\
      \    assert((static_cast<std::uintmax_t>(mint::getmod()) - 1) % n == 0\n   \
      \        && \"butterfly size is not supported by the modulus\");\n    return\
      \ __builtin_ctz(static_cast<unsigned int>(n));\n}\n\n} // namespace detail\n\
      \ntemplate <class FPS, class mint = typename FPS::value_type> void butterfly(FPS\
      \ &a) {\n    int h = detail::butterfly_log_size<mint>(a.size());\n    static\
      \ int g = primitive_root<mint::getmod()>;\n    static bool first = true;\n \
      \   static mint sum_e2[30]; // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]\n\
      \    static mint sum_e3[30];\n    static mint es[30], ies[30]; // es[i]^(2^(2+i))\
      \ == 1\n    if (first) {\n        first = false;\n        int cnt2 = __builtin_ctz(mint::getmod()\
      \ - 1);\n        mint e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();\n\
      \        for (int i = cnt2; i >= 2; i--) {\n            // e^(2^i) == 1\n  \
      \          es[i - 2] = e;\n            ies[i - 2] = ie;\n            e *= e;\n\
      \            ie *= ie;\n        }\n        mint now = 1;\n        for (int i\
      \ = 0; i <= cnt2 - 2; i++) {\n            sum_e2[i] = es[i] * now;\n       \
      \     now *= ies[i];\n        }\n        now = 1;\n        for (int i = 0; i\
      \ <= cnt2 - 3; i++) {\n            sum_e3[i] = es[i + 1] * now;\n          \
      \  now *= ies[i + 1];\n        }\n    }\n\n    int len = 0;\n    while (len\
      \ < h) {\n        if (h - len == 1) {\n            int p = 1 << (h - len - 1);\n\
      \            mint rot = 1;\n            for (int s = 0; s < (1 << len); s++)\
      \ {\n                int offset = s << (h - len);\n                for (int\
      \ i = 0; i < p; i++) {\n                    auto l = a[i + offset];\n      \
      \              auto r = a[i + offset + p] * rot;\n                    a[i +\
      \ offset] = l + r;\n                    a[i + offset + p] = l - r;\n       \
      \         }\n                if (s + 1 != (1 << len)) rot *= sum_e2[__builtin_ctz(~(unsigned\
      \ int)(s))];\n            }\n            len++;\n        } else {\n        \
      \    int p = 1 << (h - len - 2);\n            mint rot = 1, imag = es[0];\n\
      \            for (int s = 0; s < (1 << len); s++) {\n                mint rot2\
      \ = rot * rot;\n                mint rot3 = rot2 * rot;\n                int\
      \ offset = s << (h - len);\n                for (int i = 0; i < p; i++) {\n\
      \                    auto a0 = a[i + offset];\n                    auto a1 =\
      \ a[i + offset + p] * rot;\n                    auto a2 = a[i + offset + p *\
      \ 2] * rot2;\n                    auto a3 = a[i + offset + p * 3] * rot3;\n\
      \                    auto a1na3imag = (a1 - a3) * imag;\n                  \
      \  a[i + offset] = a0 + a2 + a1 + a3;\n                    a[i + offset + p]\
      \ = a0 + a2 - a1 - a3;\n                    a[i + offset + p * 2] = a0 - a2\
      \ + a1na3imag;\n                    a[i + offset + p * 3] = a0 - a2 - a1na3imag;\n\
      \                }\n                if (s + 1 != (1 << len)) rot *= sum_e3[__builtin_ctz(~(unsigned\
      \ int)(s))];\n            }\n            len += 2;\n        }\n    }\n}\n\n\
      template <class FPS, class mint = typename FPS::value_type> void butterfly_inv(FPS\
      \ &a) {\n    int n = int(a.size());\n    int h = detail::butterfly_log_size<mint>(a.size());\n\
      \    static constexpr int g = primitive_root<mint::getmod()>;\n    static bool\
      \ first = true;\n    static mint sum_ie2[30]; // sum_ie[i] = es[0] * ... * es[i\
      \ - 1] * ies[i]\n    static mint sum_ie3[30];\n    static mint es[30], ies[30];\
      \ // es[i]^(2^(2+i)) == 1\n    static mint invn[30];\n    if (first) {\n   \
      \     first = false;\n        int cnt2 = __builtin_ctz(mint::getmod() - 1);\n\
      \        mint e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();\n\
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
      \    detail::butterfly_log_size<mint>(a.size() * 2);\n    auto b = a;\n    int\
      \ z = 1;\n    butterfly_inv(b);\n    mint r = 1, zeta = mint(primitive_root<mint::getmod()>).pow((mint::getmod()\
      \ - 1) / (n << 1));\n    for (int i = 0; i < n; i++) {\n        b[i] *= r;\n\
      \        r *= zeta;\n    }\n    butterfly(b);\n    std::copy(b.begin(), b.end(),\
      \ std::back_inserter(a));\n}\n\n} // namespace kk2\n\n\n#line 11 \"convolution/convolution.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
      FPS &inplace_sparse_convolution(FPS &a, const FPS &b, int deg = -1) {\n    const\
      \ int original_a_size = a.size(), original_b_size = b.size();\n    if (!original_a_size\
      \ || !original_b_size) {\n        a.clear();\n        return a;\n    }\n   \
      \ if (deg == -1) deg = original_a_size + original_b_size - 1;\n    const int\
      \ target = std::min(std::max(0, deg), original_a_size + original_b_size - 1);\n\
      \    if (target == 0) {\n        a.clear();\n        return a;\n    }\n\n  \
      \  std::vector<std::pair<int, mint>> support_b;\n    for (int i = 0; i < std::min(original_b_size,\
      \ target); ++i) {\n        if (b[i] != mint(0)) support_b.emplace_back(i, b[i]);\n\
      \    }\n    a.resize(target);\n    for (int i = std::min(original_a_size, target)\
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
      \ b, deg);\n}\n\n} // namespace kk2\n\n\n#line 1 \"type_traits/modint.hpp\"\n\
      \n\n\n#include <concepts>\n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#include\
      \ <type_traits>\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename\
      \ T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T, __int128_t>::value\n\
      \                                                       or std::is_same<T, __int128>::value,\n\
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
      \n} // namespace kk2\n\n\n#line 7 \"type_traits/modint.hpp\"\n\nnamespace kk2::modint\
      \ {\n\ntemplate <class M>\nconcept Modular = requires(M x) {\n    requires Integral<decltype(M::getmod())>;\n\
      \    x.val();\n    { x.inv() } -> std::same_as<M>;\n};\n\n} // namespace kk2::modint\n\
      \n\n#line 1 \"fps/detail/poly_sample_point_shift.hpp\"\n\n\n\n#line 7 \"fps/detail/poly_sample_point_shift.hpp\"\
      \n\n#line 1 \"common/type_alias.hpp\"\n\n\n\n#line 6 \"common/type_alias.hpp\"\
      \n\nnamespace kk2 {\n\nusing usize = std::size_t;\nusing i8 = std::int8_t;\n\
      using u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16 = std::uint16_t;\n\
      using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
      using u64 = std::uint64_t;\n\n#ifndef _MSC_VER\nusing i128 = __int128_t;\nusing\
      \ u128 = __uint128_t;\n#endif\n\n} // namespace kk2\n\n\n#line 1 \"math_mod/comb.hpp\"\
      \n\n\n\n#line 7 \"math_mod/comb.hpp\"\n\n#line 1 \"math_mod/inv_table.hpp\"\n\
      \n\n\n#line 6 \"math_mod/inv_table.hpp\"\n\n#line 9 \"math_mod/inv_table.hpp\"\
      \n\nnamespace kk2 {\n\n/**\n * @brief `[1, n]`\u306Emod\u9006\u5143\u3092\u5217\
      \u6319\u3059\u308B\u30C6\u30FC\u30D6\u30EB\n *\n * @tparam mint\n */\ntemplate\
      \ <class mint> struct InvTable {\n    static inline std::vector<mint> _invs{0,\
      \ 1};\n    InvTable() = delete;\n\n    static void set_upper(usize m) {\n  \
      \      if (_invs.size() > m) return;\n        using index_type = std::make_unsigned_t<std::remove_cv_t<decltype(mint::getmod())>>;\n\
      \        const index_type start = static_cast<index_type>(_invs.size());\n \
      \       const index_type upper = static_cast<index_type>(m);\n        const\
      \ index_type mod = static_cast<index_type>(mint::getmod());\n        _invs.resize(m\
      \ + 1);\n        // p = q * i + r\n        // - q / r = 1 / i (mod p)\n    \
      \    for (index_type i = start; i <= upper; ++i) _invs[i] = (-_invs[mod % i])\
      \ * (mod / i);\n    }\n\n    template <UnsignedIntegral T> static inline mint\
      \ inv(T n) {\n        const usize index = static_cast<usize>(n);\n        if\
      \ (index >= _invs.size()) set_upper(index);\n        return _invs[index];\n\
      \    }\n\n    template <SignedIntegral T> static inline mint inv(T n) {\n  \
      \      using U = std::make_unsigned_t<T>;\n        if (n < 0) {\n          \
      \  // n + 1 is representable even when n is the minimum value.\n           \
      \ const U magnitude = static_cast<U>(-(n + 1)) + U(1);\n            return -inv(magnitude);\n\
      \        }\n        return inv(static_cast<U>(n));\n    }\n\n    static inline\
      \ mint inv_unchecked(usize n) { return _invs[n]; }\n};\n\n} // namespace kk2\n\
      \n\n#line 12 \"math_mod/comb.hpp\"\n\nnamespace kk2 {\n\ntemplate <modint::Modular\
      \ mint> struct Comb {\n    static inline std::vector<mint> _fact{1}, _ifact{1};\n\
      \n    Comb() = delete;\n\n  private:\n    static void extend(usize m) {\n  \
      \      const usize n = _fact.size();\n        m = std::min<usize>(m, mint::getmod()\
      \ - 1);\n        _fact.reserve(m + 1);\n        _ifact.resize(m + 1);\n    \
      \    auto &_invs = InvTable<mint>::_invs;\n        if (_invs.size() <= m) _invs.resize(m\
      \ + 1);\n        for (usize i = n; i <= m; i++) _fact.emplace_back(_fact.back()\
      \ * i);\n        _ifact[m] = _fact[m].inv();\n        _invs[m] = _ifact[m] *\
      \ _fact[m - 1];\n        for (usize i = m; i > n; i--) {\n            _ifact[i\
      \ - 1] = _ifact[i] * i;\n            _invs[i - 1] = _ifact[i - 1] * _fact[i\
      \ - 2];\n        }\n    }\n\n    static void ensure(usize n) {\n        assert(n\
      \ < mint::getmod());\n        if (_fact.size() > n) return;\n        extend(std::max<usize>(n,\
      \ _fact.size() * 2));\n    }\n\n  public:\n    static void set_upper(usize n)\
      \ {\n        ensure(std::min<usize>(n, static_cast<usize>(mint::getmod() - 1)));\n\
      \    }\n\n    static mint fact(u32 n) {\n        ensure(static_cast<usize>(n));\n\
      \        return _fact[n];\n    }\n\n    static mint ifact(u32 n) {\n       \
      \ ensure(static_cast<usize>(n));\n        return _ifact[n];\n    }\n\n    static\
      \ mint inv(i32 n) {\n        assert(n != 0);\n        return InvTable<mint>::inv(n);\n\
      \    }\n\n    static mint binom(u32 n, u32 k) {\n        if (k > n) return 0;\n\
      \        return fact(n) * ifact(k) * ifact(n - k);\n    }\n\n    template <UnsignedIntegral\
      \ T> static mint multinomial(const std::vector<T> &r) {\n        u64 n = 0;\n\
      \        for (const T x : r) n += x;\n        assert(n < mint::getmod());\n\
      \        mint res = fact(static_cast<u32>(n));\n        for (const T x : r)\
      \ res *= ifact(static_cast<u32>(x));\n        return res;\n    }\n\n    static\
      \ mint binom_naive(u32 n, u32 k) {\n        if (k > n) return 0;\n        mint\
      \ res = 1;\n        k = std::min(k, n - k);\n        for (u32 i = 1; i <= k;\
      \ i++) res *= inv(i) * (n--);\n        return res;\n    }\n\n    static mint\
      \ permu(u32 n, u32 k) {\n        if (k > n) return 0;\n        return fact(n)\
      \ * ifact(n - k);\n    }\n\n    static mint homo(u32 n, u32 k) { return k ==\
      \ 0 ? 1 : binom(n + k - 1, k); }\n};\n\n} // namespace kk2\n\n\n#line 1 \"fps/poly_sample_point_evaluate.hpp\"\
      \n\n\n\n#line 6 \"fps/poly_sample_point_evaluate.hpp\"\n\n#line 10 \"fps/poly_sample_point_evaluate.hpp\"\
      \n\nnamespace kk2 {\n\n/**\n * @brief Return `f(t)`, where `f(i) = y[i]` for\
      \ `i = 0, ..., y.size() - 1`.\n */\ntemplate <modint::Modular mint> mint sample_point_evaluate(const\
      \ std::vector<mint> &y, mint t) {\n    if (y.empty()) return 0;\n    assert(y.size()\
      \ <= static_cast<usize>(mint::getmod()));\n\n    const usize tval = static_cast<usize>(t.val());\n\
      \    if (tval < y.size()) return y[tval];\n\n    const i32 degree = static_cast<i32>(y.size())\
      \ - 1;\n    Comb<mint>::set_upper(degree);\n\n    std::vector<mint> prefix(y.size()\
      \ + 1, mint(1));\n    for (usize i = 0; i < y.size(); i++) prefix[i + 1] = prefix[i]\
      \ * (t - mint(i));\n\n    mint result = 0;\n    mint suffix = 1;\n    for (usize\
      \ i = y.size(); i-- > 0;) {\n        mint term = y[i] * Comb<mint>::ifact(static_cast<i32>(i))\n\
      \                    * Comb<mint>::ifact(degree - static_cast<i32>(i));\n  \
      \      if ((degree - static_cast<i32>(i)) & 1) term = -term;\n        result\
      \ += term * prefix[i] * suffix;\n        suffix *= t - mint(i);\n    }\n   \
      \ return result;\n}\n\n} // namespace kk2\n\n\n#line 12 \"fps/detail/poly_sample_point_shift.hpp\"\
      \n\nnamespace kk2::detail {\n\ntemplate <modint::Modular mint>\nusing SamplePointShiftConvolution\
      \ = std::vector<mint> (*)(const std::vector<mint> &,\n                     \
      \                                     const std::vector<mint> &,\n         \
      \                                                 int);\n\ntemplate <modint::Modular\
      \ mint>\nstd::vector<mint> sample_point_shift_impl(const std::vector<mint> &y,\n\
      \                                          mint t,\n                       \
      \                   i32 m,\n                                          SamplePointShiftConvolution<mint>\
      \ convolve) {\n    if (m == 0) return {};\n    if (m == 1) return {sample_point_evaluate(y,\
      \ t)};\n    if (y.empty()) return std::vector<mint>(m);\n    i64 tval = static_cast<i64>(t.val());\n\
      \    i32 k = static_cast<i32>(y.size()) - 1;\n    if (tval <= k) {\n       \
      \ std::vector<mint> ret(m);\n        i32 ptr = 0;\n        for (i64 i = tval;\
      \ i <= k and ptr < m; i++) { ret[ptr++] = y[i]; }\n        if (k + 1 < tval\
      \ + m) {\n            auto suf = sample_point_shift_impl(y, mint(k + 1), m -\
      \ ptr, convolve);\n            for (i64 i = k + 1; i < tval + m; i++) { ret[ptr++]\
      \ = suf[i - (k + 1)]; }\n        }\n        return ret;\n    }\n    const i64\
      \ modulus = static_cast<i64>(mint::getmod());\n    if (tval + m > modulus) {\n\
      \        auto pref = sample_point_shift_impl(y, t, static_cast<i32>(modulus\
      \ - tval), convolve);\n        auto suf =\n            sample_point_shift_impl(y,\
      \ mint(0), static_cast<i32>(m + tval - modulus), convolve);\n        std::ranges::copy(suf,\
      \ std::back_inserter(pref));\n        return pref;\n    }\n\n    std::vector<mint>\
      \ d(k + 1);\n    Comb<mint>::set_upper(k);\n    for (i32 i = 0; i <= k; i++)\
      \ {\n        d[i] = Comb<mint>::ifact(i) * Comb<mint>::ifact(k - i) * y[i];\n\
      \        if ((k - i) & 1) d[i] = -d[i];\n    }\n\n    std::vector<mint> h(m\
      \ + k);\n    mint product = 1;\n    for (i32 i = 0; i < m + k; i++) {\n    \
      \    h[i] = product;\n        product *= t - k + i;\n    }\n    product = product.inv();\n\
      \    for (i32 i = m + k - 1; i >= 0; i--) {\n        h[i] *= product;\n    \
      \    product *= t - k + i;\n    }\n\n    std::vector<mint> dh = convolve(d,\
      \ h, -1);\n\n    std::vector<mint> ret(m);\n    mint cur = t;\n    for (i32\
      \ i = 1; i <= k; i++) cur *= t - i;\n    for (i32 i = 0; i < m; i++) {\n   \
      \     ret[i] = cur * dh[k + i];\n        cur *= t + i + 1;\n        cur *= h[i];\n\
      \    }\n    return ret;\n}\n\ntemplate <modint::Modular mint>\nstd::vector<mint>\
      \ sample_point_shift(const std::vector<mint> &y,\n                         \
      \            mint t,\n                                     i32 m,\n        \
      \                             SamplePointShiftConvolution<mint> convolve) {\n\
      \    if (m == -1) m = y.size();\n    assert(m >= 0);\n    return sample_point_shift_impl(y,\
      \ t, m, convolve);\n}\n\n} // namespace kk2::detail\n\n\n#line 9 \"fps/poly_sample_point_shift.hpp\"\
      \n\nnamespace kk2 {\n\n/**\n * @brief `return f(t), ..., f(t + m - 1) where\
      \ f(i) = y[i]`\n *\n */\ntemplate <modint::Modular mint>\nstd::vector<mint>\
      \ sample_point_shift(\n    const std::vector<mint> &y,\n    mint t,\n    i32\
      \ m = -1,\n    detail::SamplePointShiftConvolution<mint> convolve = &convolution<std::vector<mint>>)\
      \ {\n    return detail::sample_point_shift(y, t, m, convolve);\n}\n\n} // namespace\
      \ kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: fps/poly_sample_point_shift.hpp
  pathExtension: hpp
  requiredBy:
  - math_mod/comb_large.hpp
  - verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
  - verify/yosupo_fps/poly_sample_point_shift.test.cpp
  timestamp: '2026-10-03 23:37:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/fps/poly_sample_point_evaluate.test.cpp
  - verify/yosupo_math/many_factrials.test.cpp
documentation_of: fps/poly_sample_point_shift.hpp
layout: document
---
