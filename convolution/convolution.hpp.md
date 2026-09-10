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
    - filename: butterfly.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/butterfly.hpp
    - filename: pow_mod.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/pow_mod.hpp
    - filename: primitive_root.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/primitive_root.hpp
    type: Depends on
  - files:
    - filename: convolution_arb.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution_arb.hpp
    - filename: convolution_int.hpp
      icon: LIBRARY_NO_TESTS
      path: convolution/convolution_int.hpp
    - filename: multi_convolution_truncated.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/multi_convolution_truncated.hpp
    - filename: fps_arb.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_arb.hpp
    - filename: fps_multivariate.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_multivariate.hpp
    - filename: fps_ntt_friendly.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_ntt_friendly.hpp
    - filename: comb_large.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/comb_large.hpp
    - filename: fps_composition.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_fps/fps_composition.test.cpp
    - filename: fps_composition_inv.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_fps/fps_composition_inv.test.cpp
    - filename: fps_exp_arb.test.cpp
      icon: LIBRARY_NO_TESTS
      path: verify/yosupo_fps/fps_exp_arb.test.cpp
    - filename: fps_multipoint_evaluation_geometric.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_fps/fps_multipoint_evaluation_geometric.test.cpp
    - filename: poly_interpolation_geometric.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_fps/poly_interpolation_geometric.test.cpp
    - filename: poly_sample_point_shift.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_fps/poly_sample_point_shift.test.cpp
    - filename: poly_to_newton_basis.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_fps/poly_to_newton_basis.test.cpp
    - filename: kth_term_of_linearly_recurrent_sequence.test.cpp
      icon: LIBRARY_NO_TESTS
      path: verify/yosupo_math/kth_term_of_linearly_recurrent_sequence.test.cpp
    type: Required by
  - files:
    - filename: sparsity_boundary.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_boundary.test.cpp
    - filename: sparsity_performance.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_performance.test.cpp
    - filename: sparsity_small_performance.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_small_performance.test.cpp
    - filename: large_fact_arb_mod.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
    - filename: fps.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/fps/fps.test.cpp
    - filename: convolution_arbitrary.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_arbitrary.test.cpp
    - filename: convolution_multi_truncated.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_multi_truncated.test.cpp
    - filename: convolution_ntt_friendly.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_ntt_friendly.test.cpp
    - filename: fps_exp.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_exp.test.cpp
    - filename: fps_inv.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_inv.test.cpp
    - filename: fps_inv_arb.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_inv_arb.test.cpp
    - filename: fps_log.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_log.test.cpp
    - filename: fps_log_arb.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_log_arb.test.cpp
    - filename: fps_multipoint_evaluation.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_multipoint_evaluation.test.cpp
    - filename: fps_pow.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_pow.test.cpp
    - filename: fps_product_of_polynomial_sequence.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_product_of_polynomial_sequence.test.cpp
    - filename: fps_sparse_exp.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_sparse_exp.test.cpp
    - filename: fps_sparse_inv.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_sparse_inv.test.cpp
    - filename: fps_sparse_log.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_sparse_log.test.cpp
    - filename: fps_sparse_pow.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_sparse_pow.test.cpp
    - filename: fps_sprase_sqrt.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_sprase_sqrt.test.cpp
    - filename: fps_sqrt.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_sqrt.test.cpp
    - filename: poly_division.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_division.test.cpp
    - filename: poly_interpolation.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_interpolation.test.cpp
    - filename: poly_inv.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_inv.test.cpp
    - filename: poly_root_finding.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_root_finding.test.cpp
    - filename: poly_taylor_shift.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_taylor_shift.test.cpp
    - filename: enumerate_bell_number.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_bell_number.test.cpp
    - filename: enumerate_stirling_number_of_the_first_kind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
    - filename: many_factrials.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/many_factrials.test.cpp
    - filename: yuki_1510.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yuki/yuki_1510.test.cpp
    type: Verified with
  dependsOn:
  - fps/fps_sparsity_detector.hpp
  - math_mod/butterfly.hpp
  - math_mod/pow_mod.hpp
  - math_mod/primitive_root.hpp
  embedded:
  - code: "#ifndef KK2_CONVOLUTION_CONVOLUTION_HPP\n#define KK2_CONVOLUTION_CONVOLUTION_HPP\
      \ 1\n\n#include <algorithm>\n#include <ranges>\n#include <vector>\n\n#include\
      \ \"../fps/fps_sparsity_detector.hpp\"\n#include \"../math_mod/butterfly.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
      FPS sparse_convolution(FPS &a, const FPS &b) {\n    int n = int(a.size()), m\
      \ = int(b.size());\n    if (!n || !m) {\n        a.clear();\n        return\
      \ a;\n    }\n    std::vector<int> nza, nzb;\n    nza.reserve(std::ranges::count_if(a,\
      \ [](const mint &x) { return x != mint(0); }));\n    nzb.reserve(std::ranges::count_if(b,\
      \ [](const mint &x) { return x != mint(0); }));\n    for (int i = 0; i < n;\
      \ i++)\n        if (a[i] != mint(0)) nza.push_back(i);\n    for (int i = 0;\
      \ i < m; i++)\n        if (b[i] != mint(0)) nzb.push_back(i);\n    FPS res(n\
      \ + m - 1);\n    for (int i : nza)\n        for (int j : nzb) res[i + j] +=\
      \ a[i] * b[j];\n    return a = res;\n}\n\ntemplate <class FPS> FPS dense_convolution(FPS\
      \ &a, const FPS &b) {\n    int n = int(a.size()), m = int(b.size());\n    if\
      \ (!n || !m) {\n        a.clear();\n        return a;\n    }\n\n    int z =\
      \ 1;\n    while (z < n + m - 1) z <<= 1;\n    if (std::addressof(a) == std::addressof(b))\
      \ {\n        a.resize(z);\n        butterfly(a);\n        for (int i = 0; i\
      \ < z; i++) a[i] *= a[i];\n    } else {\n        a.resize(z);\n        butterfly(a);\n\
      \        FPS t(b.begin(), b.end());\n        t.resize(z);\n        butterfly(t);\n\
      \        for (int i = 0; i < z; i++) a[i] *= t[i];\n    }\n    butterfly_inv(a);\n\
      \    a.resize(n + m - 1);\n    return a;\n}\n\ntemplate <class FPS> FPS convolution(FPS\
      \ &a, const FPS &b, bool detect_sparsity = true) {\n    if (detect_sparsity\
      \ && is_sparse_operation(FPSOperation::CONVOLUTION, 1, a, b))\n        return\
      \ sparse_convolution(a, b);\n    return dense_convolution(a, b);\n}\n\n} //\
      \ namespace kk2\n\n#endif // KK2_CONVOLUTION_CONVOLUTION_HPP\n"
    name: default
  - code: "#line 1 \"convolution/convolution.hpp\"\n\n\n\n#include <algorithm>\n#include\
      \ <ranges>\n#include <vector>\n\n#line 1 \"fps/fps_sparsity_detector.hpp\"\n\
      \n\n\n#line 5 \"fps/fps_sparsity_detector.hpp\"\n#include <bit>\n#include <cstdint>\n\
      #include <memory>\n\nnamespace kk2 {\n\nenum class FPSOperation {\n    CONVOLUTION,\n\
      \    LOG,\n    POWER,\n    DIVISION,\n    POLYNOMIAL_DIVISION,\n    INVERSE,\n\
      \    EXP,\n    SQRT\n};\n\nnamespace fps::sparsity_detail {\n\n// E(n): the\
      \ leading FFT evaluation cost, up to the common field-operation\n// constant\
      \ that cancels when dense and sparse leading terms are compared.\ninline std::int64_t\
      \ evaluation_work(int n) {\n    if (n <= 1) return 1;\n    const unsigned z\
      \ = std::bit_ceil(static_cast<unsigned>(n));\n    return static_cast<std::int64_t>(z)\
      \ * std::countr_zero(z);\n}\n\ninline int transform_size(int n, int m) {\n \
      \   if (n <= 0 || m <= 0) return 0;\n    return static_cast<int>(std::bit_ceil(static_cast<unsigned>(n\
      \ + m - 1)));\n}\n\ninline std::int64_t convolution_dense_work(int n, int m,\
      \ bool same, bool ntt_friendly) {\n    const int z = transform_size(n, m);\n\
      \    if (z == 0) return 0;\n\n    // A different pair needs two forward and\
      \ one inverse transform. Squaring\n    // reuses the forward transform and needs\
      \ only one forward transform.\n    const int transforms = same ? 2 : 3;\n  \
      \  // Arbitrary-modulus convolution uses three NTT-friendly moduli.\n    const\
      \ int moduli = ntt_friendly ? 1 : 3;\n    return static_cast<std::int64_t>(transforms)\
      \ * moduli * evaluation_work(z);\n}\n\ninline std::int64_t inverse_dense_work(int\
      \ deg, bool ntt_friendly) {\n    if (deg <= 1) return 0;\n    const int z =\
      \ static_cast<int>(std::bit_ceil(static_cast<unsigned>(deg)));\n    // NTT-friendly\
      \ uses five transforms per Newton level, whose geometric\n    // sum has leading\
      \ term 10 E(z). The arbitrary-modulus implementation\n    // performs two fresh\
      \ convolutions per level, giving 60 E(z).\n    return (ntt_friendly ? 10 : 60)\
      \ * evaluation_work(z);\n}\n\ninline std::int64_t log_dense_work(int n, int\
      \ deg, bool ntt_friendly) {\n    return inverse_dense_work(deg, ntt_friendly)\n\
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
      \ * sparse_work;\n}\n\n} // namespace kk2\n\n\n#line 1 \"math_mod/butterfly.hpp\"\
      \n\n\n\n#line 5 \"math_mod/butterfly.hpp\"\n\n#line 1 \"math_mod/primitive_root.hpp\"\
      \n\n\n\n#line 1 \"math_mod/pow_mod.hpp\"\n\n\n\n#include <cassert>\n\nnamespace\
      \ kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow_mod(T x, U n,\
      \ T m) {\n    assert(n >= 0);\n    if (m == 1) return S(0);\n    S _m = m, r\
      \ = 1;\n    S y = x % _m;\n    if (y < 0) y += _m;\n    while (n) {\n      \
      \  if (n & 1) r = (r * y) % _m;\n        if (n >>= 1) y = (y * y) % _m;\n  \
      \  }\n    return r;\n}\n\n} // namespace kk2\n\n\n#line 5 \"math_mod/primitive_root.hpp\"\
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
      }\n\n} // namespace kk2\n\n\n#line 10 \"convolution/convolution.hpp\"\n\nnamespace\
      \ kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\nFPS\
      \ sparse_convolution(FPS &a, const FPS &b) {\n    int n = int(a.size()), m =\
      \ int(b.size());\n    if (!n || !m) {\n        a.clear();\n        return a;\n\
      \    }\n    std::vector<int> nza, nzb;\n    nza.reserve(std::ranges::count_if(a,\
      \ [](const mint &x) { return x != mint(0); }));\n    nzb.reserve(std::ranges::count_if(b,\
      \ [](const mint &x) { return x != mint(0); }));\n    for (int i = 0; i < n;\
      \ i++)\n        if (a[i] != mint(0)) nza.push_back(i);\n    for (int i = 0;\
      \ i < m; i++)\n        if (b[i] != mint(0)) nzb.push_back(i);\n    FPS res(n\
      \ + m - 1);\n    for (int i : nza)\n        for (int j : nzb) res[i + j] +=\
      \ a[i] * b[j];\n    return a = res;\n}\n\ntemplate <class FPS> FPS dense_convolution(FPS\
      \ &a, const FPS &b) {\n    int n = int(a.size()), m = int(b.size());\n    if\
      \ (!n || !m) {\n        a.clear();\n        return a;\n    }\n\n    int z =\
      \ 1;\n    while (z < n + m - 1) z <<= 1;\n    if (std::addressof(a) == std::addressof(b))\
      \ {\n        a.resize(z);\n        butterfly(a);\n        for (int i = 0; i\
      \ < z; i++) a[i] *= a[i];\n    } else {\n        a.resize(z);\n        butterfly(a);\n\
      \        FPS t(b.begin(), b.end());\n        t.resize(z);\n        butterfly(t);\n\
      \        for (int i = 0; i < z; i++) a[i] *= t[i];\n    }\n    butterfly_inv(a);\n\
      \    a.resize(n + m - 1);\n    return a;\n}\n\ntemplate <class FPS> FPS convolution(FPS\
      \ &a, const FPS &b, bool detect_sparsity = true) {\n    if (detect_sparsity\
      \ && is_sparse_operation(FPSOperation::CONVOLUTION, 1, a, b))\n        return\
      \ sparse_convolution(a, b);\n    return dense_convolution(a, b);\n}\n\n} //\
      \ namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: convolution/convolution.hpp
  pathExtension: hpp
  requiredBy:
  - convolution/convolution_arb.hpp
  - convolution/convolution_int.hpp
  - convolution/multi_convolution_truncated.hpp
  - fps/fps_arb.hpp
  - fps/fps_multivariate.hpp
  - fps/fps_ntt_friendly.hpp
  - math_mod/comb_large.hpp
  - verify/yosupo_fps/fps_composition.test.cpp
  - verify/yosupo_fps/fps_composition_inv.test.cpp
  - verify/yosupo_fps/fps_exp_arb.test.cpp
  - verify/yosupo_fps/fps_multipoint_evaluation_geometric.test.cpp
  - verify/yosupo_fps/poly_interpolation_geometric.test.cpp
  - verify/yosupo_fps/poly_sample_point_shift.test.cpp
  - verify/yosupo_fps/poly_to_newton_basis.test.cpp
  - verify/yosupo_math/kth_term_of_linearly_recurrent_sequence.test.cpp
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/fps/sparsity_boundary.test.cpp
  - verify/unit_test/fps/sparsity_performance.test.cpp
  - verify/unit_test/fps/sparsity_small_performance.test.cpp
  - verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
  - verify/unit_test/type_traits/fps/fps.test.cpp
  - verify/yosupo_convolution/convolution_arbitrary.test.cpp
  - verify/yosupo_convolution/convolution_multi_truncated.test.cpp
  - verify/yosupo_convolution/convolution_ntt_friendly.test.cpp
  - verify/yosupo_fps/fps_exp.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_inv_arb.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
  - verify/yosupo_fps/fps_log_arb.test.cpp
  - verify/yosupo_fps/fps_multipoint_evaluation.test.cpp
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_product_of_polynomial_sequence.test.cpp
  - verify/yosupo_fps/fps_sparse_exp.test.cpp
  - verify/yosupo_fps/fps_sparse_inv.test.cpp
  - verify/yosupo_fps/fps_sparse_log.test.cpp
  - verify/yosupo_fps/fps_sparse_pow.test.cpp
  - verify/yosupo_fps/fps_sprase_sqrt.test.cpp
  - verify/yosupo_fps/fps_sqrt.test.cpp
  - verify/yosupo_fps/poly_division.test.cpp
  - verify/yosupo_fps/poly_interpolation.test.cpp
  - verify/yosupo_fps/poly_inv.test.cpp
  - verify/yosupo_fps/poly_root_finding.test.cpp
  - verify/yosupo_fps/poly_taylor_shift.test.cpp
  - verify/yosupo_math/enumerate_bell_number.test.cpp
  - verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
  - verify/yosupo_math/many_factrials.test.cpp
  - verify/yuki/yuki_1510.test.cpp
documentation_of: convolution/convolution.hpp
layout: document
---
