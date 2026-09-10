---
data:
  attributes:
    STANDALONE: ''
    links: []
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
    - filename: fps_sqrt.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_sqrt.hpp
    - filename: butterfly.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/butterfly.hpp
    - filename: inv_table.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/inv_table.hpp
    - filename: mod_sqrt.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/mod_sqrt.hpp
    - filename: pow_mod.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/pow_mod.hpp
    - filename: primitive_root.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/primitive_root.hpp
    - filename: mont.hpp
      icon: LIBRARY_ALL_AC
      path: modint/mont.hpp
    - filename: mont_arb.hpp
      icon: LIBRARY_ALL_AC
      path: modint/mont_arb.hpp
    - filename: timer.hpp
      icon: LIBRARY_ALL_AC
      path: others/timer.hpp
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
  - fps/fps_sqrt.hpp
  - math_mod/butterfly.hpp
  - math_mod/inv_table.hpp
  - math_mod/mod_sqrt.hpp
  - math_mod/pow_mod.hpp
  - math_mod/primitive_root.hpp
  - modint/mont.hpp
  - modint/mont_arb.hpp
  - others/timer.hpp
  - type_traits/fps.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "// competitive-verifier: STANDALONE\n\n#include <algorithm>\n#include <cassert>\n\
      #include <iostream>\n#include <string_view>\n\n#include \"../../../fps/fps_ntt_friendly.hpp\"\
      \n#include \"../../../fps/fps_sqrt.hpp\"\n#include \"../../../modint/mont.hpp\"\
      \n#include \"../../../others/timer.hpp\"\n\nusing FPS = kk2::FPSNTT<kk2::mont998>;\n\
      using mint = kk2::mont998;\n\nnamespace {\n\nconstexpr int repetitions = 1000;\n\
      volatile unsigned benchmark_sink = 0;\n\nFPS make_series(int n, int support,\
      \ mint constant) {\n    FPS f(n);\n    f[0] = constant;\n    for (int i = 1;\
      \ i < support; ++i) {\n        int index = 1 + (long long)(i - 1) * (n - 1)\
      \ / std::max(1, support - 1);\n        f[index] = mint(1234567LL * i + 890123);\n\
      \    }\n    return f;\n}\n\ntemplate <class F> double measure(F &&fn) {\n  \
      \  kk2::Timer timer;\n    for (int i = 0; i < repetitions; ++i) {\n        auto\
      \ result = fn();\n        benchmark_sink = benchmark_sink ^ result.back().val();\n\
      \    }\n    return timer.elapsed();\n}\n\ntemplate <class Sparse, class Dense>\n\
      void check_choice(std::string_view name, bool selects_sparse, Sparse &&sparse,\
      \ Dense &&dense) {\n    sparse();\n    dense();\n    const double sparse_ms\
      \ = measure(sparse);\n    const double dense_ms = measure(dense);\n    const\
      \ double selected_ms = selects_sparse ? sparse_ms : dense_ms;\n    const double\
      \ best_ms = std::min(sparse_ms, dense_ms);\n    if (selected_ms > 2.0 * best_ms\
      \ + 0.1) {\n        std::cerr << name << \": selected=\" << selected_ms << \"\
      ms, sparse=\" << sparse_ms\n                  << \"ms, dense=\" << dense_ms\
      \ << \"ms\\n\";\n        assert(false);\n    }\n}\n\nvoid test_small_measured_choices()\
      \ {\n    for (int n : {16, 32}) {\n        for (int support : {4, n / 2}) {\n\
      \            const FPS unit = make_series(n, support, 1);\n            const\
      \ FPS other = make_series(n, support, 2);\n            FPS exponential = unit;\n\
      \            exponential[0] = 0;\n\n            check_choice(\n            \
      \    \"convolution\",\n                kk2::is_sparse_operation(kk2::FPSOperation::CONVOLUTION,\
      \ true, unit, other),\n                [&] {\n                    FPS result\
      \ = unit;\n                    return kk2::sparse_convolution(result, other);\n\
      \                },\n                [&] { return unit.dense_mul(other); });\n\
      \            check_choice(\n                \"inverse\",\n                kk2::is_sparse_operation(kk2::FPSOperation::INVERSE,\
      \ true, unit, FPS(), n),\n                [&] { return unit.sparse_inv(n); },\n\
      \                [&] { return unit.dense_inv(n); });\n            check_choice(\n\
      \                \"log\",\n                kk2::is_sparse_operation(kk2::FPSOperation::LOG,\
      \ true, unit, FPS(), n),\n                [&] { return unit.sparse_log(n); },\n\
      \                [&] { return unit.dense_log(n); });\n            check_choice(\n\
      \                \"exp\",\n                kk2::is_sparse_operation(kk2::FPSOperation::EXP,\
      \ true, exponential, FPS(), n),\n                [&] { return exponential.sparse_exp(n);\
      \ },\n                [&] { return exponential.dense_exp(n); });\n         \
      \   check_choice(\n                \"pow\",\n                kk2::is_sparse_operation(kk2::FPSOperation::POWER,\
      \ true, unit, FPS(), n),\n                [&] { return unit.sparse_pow(7, n);\
      \ },\n                [&] { return unit.dense_pow(7, n); });\n            check_choice(\n\
      \                \"division\",\n                kk2::is_sparse_operation(kk2::FPSOperation::DIVISION,\
      \ true, other, unit, n),\n                [&] { return other.sparse_div(unit,\
      \ n); },\n                [&] { return other.dense_mul(unit.dense_inv(n)).pre(n);\
      \ });\n            check_choice(\n                \"sqrt\",\n              \
      \  kk2::is_sparse_operation(kk2::FPSOperation::SQRT, true, unit, FPS(), n),\n\
      \                [&] { return kk2::sparse_sqrt(unit, n); },\n              \
      \  [&] { return kk2::dense_sqrt(unit, n); });\n\n            FPS divisor = unit;\n\
      \            divisor.back() = 1;\n            const FPS dividend = other.dense_mul(divisor);\n\
      \            check_choice(\n                \"polynomial division\",\n     \
      \           kk2::is_sparse_operation(\n                    kk2::FPSOperation::POLYNOMIAL_DIVISION,\
      \ true, dividend, divisor, n),\n                [&] { return dividend.sparse_quo(divisor);\
      \ },\n                [&] { return dividend.dense_quo(divisor); });\n      \
      \  }\n    }\n}\n\n} // namespace\n\nint main() { test_small_measured_choices();\
      \ }\n"
    name: default
  - code: "#line 1 \"verify/unit_test/fps/sparsity_small_performance.test.cpp\"\n\
      // competitive-verifier: STANDALONE\n\n#include <algorithm>\n#include <cassert>\n\
      #include <iostream>\n#include <string_view>\n\n#line 1 \"fps/fps_ntt_friendly.hpp\"\
      \n\n\n\n#line 7 \"fps/fps_ntt_friendly.hpp\"\n#include <utility>\n#include <vector>\n\
      \n#line 1 \"convolution/convolution.hpp\"\n\n\n\n#line 5 \"convolution/convolution.hpp\"\
      \n#include <ranges>\n#line 7 \"convolution/convolution.hpp\"\n\n#line 1 \"fps/fps_sparsity_detector.hpp\"\
      \n\n\n\n#line 5 \"fps/fps_sparsity_detector.hpp\"\n#include <bit>\n#include\
      \ <cstdint>\n#include <memory>\n\nnamespace kk2 {\n\nenum class FPSOperation\
      \ {\n    CONVOLUTION,\n    LOG,\n    POWER,\n    DIVISION,\n    POLYNOMIAL_DIVISION,\n\
      \    INVERSE,\n    EXP,\n    SQRT\n};\n\nnamespace fps::sparsity_detail {\n\n\
      // E(n): the leading FFT evaluation cost, up to the common field-operation\n\
      // constant that cancels when dense and sparse leading terms are compared.\n\
      inline std::int64_t evaluation_work(int n) {\n    if (n <= 1) return 1;\n  \
      \  const unsigned z = std::bit_ceil(static_cast<unsigned>(n));\n    return static_cast<std::int64_t>(z)\
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
      \ namespace kk2\n\n\n#line 1 \"fps/fps_base.hpp\"\n\n\n\n#line 7 \"fps/fps_base.hpp\"\
      \n#include <tuple>\n#line 10 \"fps/fps_base.hpp\"\n\n#line 1 \"math_mod/inv_table.hpp\"\
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
      #line 6 \"type_traits/fps.hpp\"\n#include <type_traits>\n\nnamespace kk2::fps\
      \ {\n\nnamespace category {\n\nstruct arbitrary_modulus {};\nstruct ntt_friendly_modulus\
      \ {};\n\nstruct ordinary {};\nstruct exponential_generating {};\nstruct set_power_series\
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
      \ namespace kk2::fps\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#line 5 \"type_traits/io.hpp\"\
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
      \n} // namespace kk2\n\n\n#line 14 \"fps/fps_base.hpp\"\n\nnamespace kk2 {\n\
      \ntemplate <class Derived, fps::Modular mint> struct FormalPowerSeriesBase :\
      \ std::vector<mint> {\n    using std::vector<mint>::vector;\n    using FPS =\
      \ Derived;\n    using ivta = InvTable<mint>;\n\n    // CRTP\u3092\u4F7F\u3063\
      \u3066\u6D3E\u751F\u30AF\u30E9\u30B9\u306E\u53C2\u7167\u3092\u53D6\u5F97\n \
      \   Derived &derived() { return static_cast<Derived &>(*this); }\n    const\
      \ Derived &derived() const { return static_cast<const Derived &>(*this); }\n\
      \n    template <OutputStream OStream> void debug_output(OStream &os) const {\n\
      \        os << \"[\";\n        for (size_t i = 0; i < this->size(); i++) {\n\
      \            os << (*this)[i] << (i + 1 == this->size() ? \"\" : \", \");\n\
      \        }\n        os << \"]\";\n    }\n\n    template <OutputStream OStream>\
      \ void output(OStream &os) const {\n        for (size_t i = 0; i < this->size();\
      \ i++) {\n            os << (*this)[i] << (i + 1 == this->size() ? \"\\n\" :\
      \ \" \");\n        }\n    }\n    template <OutputStream OStream> friend OStream\
      \ &operator<<(OStream &os, const FPS &fps_) {\n        for (size_t i = 0; i\
      \ < fps_.size(); i++) {\n            os << fps_[i] << (i + 1 == fps_.size()\
      \ ? \"\" : \" \");\n        }\n        return os;\n    }\n\n    template <InputStream\
      \ IStream> FPS &input(IStream &is) {\n        for (size_t i = 0; i < this->size();\
      \ i++) is >> (*this)[i];\n        return derived();\n    }\n\n    template <InputStream\
      \ IStream> friend IStream &operator>>(IStream &is, FPS &fps_) {\n        for\
      \ (auto &x : fps_) is >> x;\n        return is;\n    }\n    FPS &operator+=(const\
      \ FPS &r) {\n        if (this->size() < r.size()) this->resize(r.size());\n\
      \        for (size_t i = 0; i < r.size(); i++) (*this)[i] += r[i];\n       \
      \ return derived();\n    }\n\n    FPS &operator+=(const mint &r) {\n       \
      \ if (this->empty()) this->resize(1);\n        (*this)[0] += r;\n        return\
      \ derived();\n    }\n\n    FPS &operator-=(const FPS &r) {\n        if (this->size()\
      \ < r.size()) this->resize(r.size());\n        for (size_t i = 0; i < r.size();\
      \ i++) (*this)[i] -= r[i];\n        return derived();\n    }\n\n    FPS &operator-=(const\
      \ mint &r) {\n        if (this->empty()) this->resize(1);\n        (*this)[0]\
      \ -= r;\n        return derived();\n    }\n\n    FPS &operator*=(const mint\
      \ &r) {\n        for (size_t i = 0; i < this->size(); i++) { (*this)[i] *= r;\
      \ }\n        return derived();\n    }\n    FPS &operator/=(const FPS &r) {\n\
      \        assert(!r.empty());\n        if (this->size() < r.size()) {\n     \
      \       this->clear();\n            return derived();\n        }\n        int\
      \ n = this->size() - r.size() + 1;\n        if (is_sparse_operation(FPSOperation::POLYNOMIAL_DIVISION,\n\
      \                                fps::NTTFriendlyFormalPowerSeries<FPS>,\n \
      \                               derived(),\n                               \
      \ r,\n                                n))\n            return derived() = sparse_quo(r);\n\
      \        return derived() = dense_quo(r);\n    }\n\n    FPS sparse_quo(const\
      \ FPS &r) const {\n        assert(!r.empty());\n        if (this->size() < r.size())\
      \ return {};\n        const int n = this->size() - r.size() + 1;\n        const\
      \ mint lead_inv = r.back().inv();\n        std::vector<std::pair<int, mint>>\
      \ support;\n        for (int i = (int)r.size() - 2; i >= 0; --i) {\n       \
      \     if (r[i] != mint(0)) support.emplace_back((int)r.size() - 1 - i, r[i]\
      \ * lead_inv);\n        }\n        FPS quotient_rev(n);\n        for (int k\
      \ = 0; k < n; ++k) {\n            quotient_rev[k] = (*this)[this->size() - 1\
      \ - k] * lead_inv;\n            for (const auto &[offset, coefficient] : support)\
      \ {\n                if (offset > k) break;\n                quotient_rev[k]\
      \ -= quotient_rev[k - offset] * coefficient;\n            }\n        }\n   \
      \     return quotient_rev.rev();\n    }\n\n    FPS dense_quo(const FPS &r) const\
      \ {\n        assert(!r.empty());\n        if (this->size() < r.size()) return\
      \ {};\n        const int n = this->size() - r.size() + 1;\n        return derived().rev().pre(n).dense_mul(r.rev().dense_inv(n)).pre(n).rev();\n\
      \    }\n\n    FPS &operator%=(const FPS &r) {\n        derived() -= derived()\
      \ / r * r;\n        shrink();\n        return derived();\n    }\n\n    FPS &operator>>=(int\
      \ n) {\n        if (n >= (int)this->size()) {\n            this->clear();\n\
      \        } else {\n            this->erase(this->begin(), this->begin() + n);\n\
      \        }\n        return derived();\n    }\n\n    FPS &operator<<=(int n)\
      \ {\n        this->insert(this->begin(), n, mint(0));\n        return derived();\n\
      \    }\n\n    // CRTP\u3092\u4F7F\u3063\u3066\u6D3E\u751F\u30AF\u30E9\u30B9\u306E\
      \u30E1\u30BD\u30C3\u30C9\u3092\u5229\u7528\u3057\u305F\u6F14\u7B97\u5B50\u306E\
      \u81EA\u52D5\u5B9F\u88C5\n    FPS operator+(const FPS &r) const { return FPS(derived())\
      \ += r; }\n    FPS operator+(const mint &r) const { return FPS(derived()) +=\
      \ r; }\n    FPS operator-(const FPS &r) const { return FPS(derived()) -= r;\
      \ }\n    FPS operator-(const mint &r) const { return FPS(derived()) -= r; }\n\
      \    // \u639B\u3051\u7B97\u306F\u6D3E\u751F\u30AF\u30E9\u30B9\u3067\u5B9A\u7FA9\
      \u3055\u308C\u308B\n    FPS operator*(const FPS &r) const { return FPS(derived())\
      \ *= r; }\n    FPS operator*(const mint &r) const { return FPS(derived()) *=\
      \ r; }\n    FPS operator/(const FPS &r) const { return FPS(derived()) /= r;\
      \ }\n    FPS operator%(const FPS &r) const { return FPS(derived()) %= r; }\n\
      \    FPS operator>>(int n) const { return FPS(derived()) >>= n; }\n    FPS operator<<(int\
      \ n) const { return FPS(derived()) <<= n; }\n\n    FPS operator-() const {\n\
      \        FPS ret(this->size());\n        for (size_t i = 0; i < this->size();\
      \ i++) ret[i] = -(*this)[i];\n        return ret;\n    }\n    FPS &shrink()\
      \ {\n        while (this->size() && this->back() == mint(0)) this->pop_back();\n\
      \        return derived();\n    }\n\n    FPS &inplace_rev() {\n        std::reverse(this->begin(),\
      \ this->end());\n        return derived();\n    }\n\n    FPS &inplace_dot(const\
      \ FPS &r) {\n        this->resize(std::min(this->size(), r.size()));\n     \
      \   for (size_t i = 0; i < this->size(); i++) (*this)[i] *= r[i];\n        return\
      \ derived();\n    }\n\n    FPS &inplace_pre(int n) {\n        this->resize(n);\n\
      \        return derived();\n    }\n\n    FPS &inplace_diff() {\n        if (this->empty())\
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
      \    FPS log(int deg = -1) const {\n        assert(!this->empty() && (*this)[0]\
      \ == mint(1));\n        if (is_sparse_operation(\n                FPSOperation::LOG,\
      \ fps::NTTFriendlyFormalPowerSeries<FPS>, derived(), FPS(), deg))\n        \
      \    return derived().sparse_log(deg);\n        return derived().dense_log(deg);\n\
      \    }\n\n    template <class T> FPS pow(T k, int deg = -1) const {\n      \
      \  if (deg == -1) deg = this->size();\n        if (k == 0) return derived().dense_pow(k,\
      \ deg);\n        int zero = 0;\n        while (zero != int(this->size()) &&\
      \ (*this)[zero] == mint(0)) ++zero;\n        if (zero == int(this->size()) ||\
      \ __int128_t(zero) * k >= deg)\n            return derived().dense_pow(k, deg);\n\
      \        if (zero == 0\n            && is_sparse_operation(\n              \
      \  FPSOperation::POWER, fps::NTTFriendlyFormalPowerSeries<FPS>, derived(), FPS(),\
      \ deg))\n            return derived().sparse_pow(k, deg);\n        if (zero\
      \ > 0) {\n            FPS normalized(this->begin() + zero, this->end());\n \
      \           const int normalized_deg = deg - int(__int128_t(zero) * k);\n  \
      \          if (is_sparse_operation(FPSOperation::POWER,\n                  \
      \                  fps::NTTFriendlyFormalPowerSeries<FPS>,\n               \
      \                     normalized,\n                                    FPS(),\n\
      \                                    normalized_deg))\n                return\
      \ derived().sparse_pow(k, deg);\n        }\n        return derived().dense_pow(k,\
      \ deg);\n    }\n\n    FPS div(const FPS &r, int deg = -1) const {\n        assert(!r.empty()\
      \ && r[0] != mint(0));\n        if (deg == -1) deg = this->size();\n       \
      \ if (is_sparse_operation(\n                FPSOperation::DIVISION, fps::NTTFriendlyFormalPowerSeries<FPS>,\
      \ derived(), r, deg))\n            return derived().sparse_div(r, deg);\n  \
      \      return FPS(derived()).pre(deg).dense_mul(r.dense_inv(deg)).pre(deg);\n\
      \    }\n\n    FPS inv(int deg = -1) const {\n        assert(!this->empty() &&\
      \ (*this)[0] != mint(0));\n        if (is_sparse_operation(FPSOperation::INVERSE,\n\
      \                                fps::NTTFriendlyFormalPowerSeries<FPS>,\n \
      \                               derived(),\n                               \
      \ FPS(),\n                                deg))\n            return derived().sparse_inv(deg);\n\
      \        return derived().dense_inv(deg);\n    }\n\n    FPS exp(int deg = -1)\
      \ const {\n        assert(this->empty() || (*this)[0] == mint(0));\n       \
      \ if (is_sparse_operation(\n                FPSOperation::EXP, fps::NTTFriendlyFormalPowerSeries<FPS>,\
      \ derived(), FPS(), deg))\n            return derived().sparse_exp(deg);\n \
      \       return derived().dense_exp(deg);\n    }\n\n    FPS dense_log(int deg\
      \ = -1) const {\n        if (deg == -1) deg = this->size();\n        return\
      \ derived().diff().dense_mul(derived().dense_inv(deg)).pre(deg - 1).integral();\n\
      \    }\n    FPS sparse_log(int deg = -1) const {\n        if (deg == -1) deg\
      \ = this->size();\n        std::vector<std::pair<int, mint>> fs;\n        for\
      \ (int i = 1; i < int(this->size()); i++) {\n            if ((*this)[i] != mint(0))\
      \ fs.emplace_back(i, (*this)[i]);\n        }\n        ivta::set_upper(deg);\n\
      \n        FPS g(deg);\n        for (int k = 0; k < deg - 1; k++) {\n       \
      \     for (auto &[j, fj] : fs) {\n                if (k < j) break;\n      \
      \          int i = k - j;\n                g[k + 1] -= g[i + 1] * fj * (i +\
      \ 1);\n            }\n            g[k + 1] *= ivta::inv(k + 1);\n          \
      \  if (k + 1 < int(this->size())) g[k + 1] += (*this)[k + 1];\n        }\n\n\
      \        return g;\n    }\n\n    template <class T> FPS dense_pow(T k, int deg\
      \ = -1) const {\n        const int n = this->size();\n        if (deg == -1)\
      \ deg = n;\n        if (k == 0) {\n            FPS ret(deg);\n            if\
      \ (deg > 0) ret[0] = mint(1);\n            return ret;\n        }\n        for\
      \ (int i = 0; i < n; i++) {\n            if ((*this)[i] != mint(0)) {\n    \
      \            mint rev = mint(1) / (*this)[i];\n                FPS ret = ((derived()\
      \ * rev) >> i).dense_log(deg) * k;\n                ret = ret.dense_exp(deg);\n\
      \                ret *= (*this)[i].pow(k);\n                ret = (ret << (i\
      \ * k)).pre(deg);\n                if ((int)ret.size() < deg) ret.resize(deg,\
      \ mint(0));\n                return ret;\n            }\n            if (__int128_t(i\
      \ + 1) * k >= deg) return FPS(deg, mint(0));\n        }\n        return FPS(deg,\
      \ mint(0));\n    }\n    template <class T> FPS sparse_pow(T k, int deg = -1)\
      \ const {\n        if (deg == -1) deg = this->size();\n        if (k == 0) {\n\
      \            FPS ret(deg);\n            if (deg > 0) ret[0] = mint(1);\n   \
      \         return ret;\n        }\n\n        int zero = 0;\n        while (zero\
      \ != int(this->size()) && (*this)[zero] == mint(0)) zero++;\n        if (zero\
      \ == int(this->size()) || __int128_t(zero) * k >= deg) { return FPS(deg, mint(0));\
      \ }\n        if (zero != 0) {\n            FPS suf(this->begin() + zero, this->end());\n\
      \            auto g = suf.sparse_pow(k, deg - zero * k);\n            FPS ret(zero\
      \ * k, mint(0));\n            std::copy(std::begin(g), std::end(g), std::back_inserter(ret));\n\
      \            return ret;\n        }\n\n        int mod = mint::getmod();\n \
      \       static std::vector<mint> inv{1, 1};\n        while ((int)inv.size()\
      \ <= deg) {\n            int i = inv.size();\n            inv.push_back(-inv[mod\
      \ % i] * (mod / i));\n        }\n\n        const mint constant_term = (*this)[0].pow(k);\n\
      \        k %= mod;\n        std::vector<std::tuple<int, mint, mint>> fs;\n \
      \       for (int i = 1; i < int(this->size()); i++) {\n            if ((*this)[i]\
      \ != mint(0))\n                fs.emplace_back(i, (*this)[i], (*this)[i] * mint(i)\
      \ * (k + 1));\n        }\n\n        FPS g(deg);\n        g[0] = constant_term;\n\
      \        mint denom = (*this)[0].inv();\n        for (int a = 1; a < deg; a++)\
      \ {\n            for (auto &[i, f_i, weighted_f_i] : fs) {\n               \
      \ if (a < i) break;\n                g[a] += g[a - i] * (weighted_f_i - f_i\
      \ * a);\n            }\n            g[a] *= denom * inv[a];\n        }\n   \
      \     return g;\n    } // return this / r\n    FPS sparse_div(const FPS &r,\
      \ int deg = -1) const {\n        assert(!r.empty() && r[0] != mint(0));\n  \
      \      if (deg == -1) deg = this->size();\n        mint ir0 = r[0].inv();\n\
      \        FPS ret = derived() * ir0;\n        ret.resize(deg);\n        std::vector<std::pair<int,\
      \ mint>> gs;\n        for (int i = 1; i < (int)r.size(); i++) {\n          \
      \  if (r[i] != mint(0)) gs.emplace_back(i, r[i] * ir0);\n        }\n       \
      \ for (int i = 0; i < deg; i++) {\n            for (auto &[j, g_j] : gs) {\n\
      \                if (i + j >= deg) break;\n                ret[i + j] -= ret[i]\
      \ * g_j;\n            }\n        }\n        return ret;\n    }\n\n    FPS sparse_inv(int\
      \ deg = -1) const {\n        if (deg == -1) deg = this->size();\n        std::vector<std::pair<int,\
      \ mint>> fs;\n        for (int i = 1; i < int(this->size()); i++) {\n      \
      \      if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i]);\n        }\n\
      \        FPS ret(deg);\n        mint if0 = (*this)[0].inv();\n        if (0\
      \ < deg) ret[0] = if0;\n        for (int k = 1; k < deg; k++) {\n          \
      \  for (auto &[j, fj] : fs) {\n                if (k < j) break;\n         \
      \       ret[k] += ret[k - j] * fj;\n            }\n            ret[k] *= -if0;\n\
      \        }\n        return ret;\n    }\n\n    FPS sparse_exp(int deg = -1) const\
      \ {\n        if (deg == -1) deg = this->size();\n        std::vector<std::pair<int,\
      \ mint>> fs;\n        for (int i = 1; i < int(this->size()); i++) {\n      \
      \      if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i] * i);\n    \
      \    }\n\n        int mod = mint::getmod();\n        static std::vector<mint>\
      \ inv{1, 1};\n        int now = inv.size();\n        inv.resize(std::max(now,\
      \ deg + 1));\n        for (int i = now; i <= deg; i++) inv[i] = -inv[mod % i]\
      \ * (mod / i);\n\n        FPS g(deg);\n        if (deg) g[0] = 1;\n        for\
      \ (int k = 0; k < deg - 1; k++) {\n            for (auto &[ip1, derivative_coefficient]\
      \ : fs) {\n                int i = ip1 - 1;\n                if (k < i) break;\n\
      \                g[k + 1] += g[k - i] * derivative_coefficient;\n          \
      \  }\n            g[k + 1] *= inv[k + 1];\n        }\n\n        return g;\n\
      \    }\n    FPS &inplace_imos(int n) {\n        inplace_pre(n);\n        for\
      \ (int i = 0; i < n - 1; i++) (*this)[i + 1] += (*this)[i];\n        return\
      \ derived();\n    }\n\n    FPS &inplace_iimos(int n) {\n        inplace_pre(n);\n\
      \        for (int i = 0; i < n - 1; i++) (*this)[i + 1] -= (*this)[i];\n   \
      \     return derived();\n    }\n    FPS imos(int n) const { return FPS(derived()).inplace_imos(n);\
      \ }\n    FPS iimos(int n) const { return FPS(derived()).inplace_iimos(n); }\n\
      };\n\n} // namespace kk2\n\n\n#line 12 \"fps/fps_ntt_friendly.hpp\"\n\nnamespace\
      \ kk2 {\n\ntemplate <fps::Modular mint>\nstruct FormalPowerSeriesNTTFriendly\n\
      \    : FormalPowerSeriesBase<FormalPowerSeriesNTTFriendly<mint>, mint> {\n \
      \   using base = FormalPowerSeriesBase<FormalPowerSeriesNTTFriendly<mint>, mint>;\n\
      \    using FPS = FormalPowerSeriesNTTFriendly<mint>;\n    using base::FormalPowerSeriesBase;\n\
      \    using base::operator*=; // \u57FA\u5E95\u30AF\u30E9\u30B9\u306Eoperator*=\u3092\
      \u7D99\u627F\n    using modulus_category = kk2::fps::category::ntt_friendly_modulus;\n\
      \    using series_category = kk2::fps::category::ordinary;\n    using variable_category\
      \ = kk2::fps::category::univariate;\n    static constexpr bool is_ntt_friendly\
      \ = true;\n\n    // CRTP\u3092\u4F7F\u3063\u305F\u5B9F\u88C5 - override\u306F\
      \u4E0D\u8981\n    FPS &operator*=(const FPS &r) {\n        convolution(*this,\
      \ r);\n        return *this;\n    }\n    FPS dense_mul(const FPS &r) const {\n\
      \        FPS result(*this);\n        convolution(result, r, false);\n      \
      \  return result;\n    }\n    void but() { butterfly(*this); }\n    void ibut()\
      \ { butterfly_inv(*this); }\n    void db() { doubling(*this); }\n    static\
      \ int but_pr() { return primitive_root<mint::getmod()>; }\n\n    FPS dense_inv(int\
      \ deg = -1) const {\n        if (deg == -1) deg = (int)this->size();\n     \
      \   FPS res(deg);\n        res[0] = {mint(1) / (*this)[0]};\n        for (int\
      \ d = 1; d < deg; d <<= 1) {\n            FPS f(2 * d), g(2 * d);\n        \
      \    std::copy(std::begin(*this),\n                      std::begin(*this) +\
      \ std::min((int)this->size(), 2 * d),\n                      std::begin(f));\n\
      \            std::copy(std::begin(res), std::begin(res) + d, std::begin(g));\n\
      \            f.but();\n            g.but();\n            f.inplace_dot(g);\n\
      \            f.ibut();\n            std::fill(std::begin(f), std::begin(f) +\
      \ d, mint(0));\n            f.but();\n            f.inplace_dot(g);\n      \
      \      f.ibut();\n            for (int j = d; j < std::min(2 * d, deg); j++)\
      \ res[j] = -f[j];\n        }\n        return res.pre(deg);\n    }\n\n    FPS\
      \ dense_exp(int deg = -1) const {\n        if (deg == -1) deg = (int)this->size();\n\
      \n        FPS b{1, 1 < (int)this->size() ? (*this)[1] : mint(0)};\n        FPS\
      \ c{1}, z1, z2{1, 1};\n        for (int m = 2; m < deg; m <<= 1) {\n       \
      \     auto y = b;\n            y.resize(m << 1);\n            y.but();\n   \
      \         z1 = z2;\n            FPS z(m);\n            z = y.dot(z1);\n    \
      \        z.ibut();\n            std::fill(std::begin(z), std::begin(z) + (m\
      \ >> 1), mint(0));\n            z.but();\n            z.inplace_dot(-z1);\n\
      \            z.ibut();\n            c.insert(std::end(c), std::begin(z) + (m\
      \ >> 1), std::end(z));\n            z2 = c;\n            z2.resize(m << 1);\n\
      \            z2.but();\n\n            FPS x(this->begin(), this->begin() + std::min<int>(this->size(),\
      \ m));\n            x.resize(m);\n            x.inplace_diff();\n          \
      \  x.push_back(mint(0));\n            x.but();\n            x.inplace_dot(y);\n\
      \            x.ibut();\n            x -= b.diff();\n            x.resize(m <<\
      \ 1);\n            for (int i = 0; i < m - 1; i++) {\n                x[m +\
      \ i] = x[i];\n                x[i] = mint(0);\n            }\n            x.but();\n\
      \            x.inplace_dot(z2);\n            x.ibut();\n            x.pop_back();\n\
      \            x.inplace_int();\n            for (int i = m; i < std::min<int>(this->size(),\
      \ m << 1); i++) x[i] += (*this)[i];\n            std::fill(std::begin(x), std::begin(x)\
      \ + m, mint(0));\n            x.but();\n            x.inplace_dot(y);\n    \
      \        x.ibut();\n            b.insert(std::end(b), std::begin(x) + m, std::end(x));\n\
      \        }\n        return FPS(std::begin(b), std::begin(b) + deg);\n    }\n\
      };\n\ntemplate <fps::Modular mint> using FPSNTT = FormalPowerSeriesNTTFriendly<mint>;\n\
      \n} // namespace kk2\n\n\n#line 1 \"fps/fps_sqrt.hpp\"\n\n\n\n#line 5 \"fps/fps_sqrt.hpp\"\
      \n\n#line 1 \"math_mod/mod_sqrt.hpp\"\n\n\n\n#line 5 \"math_mod/mod_sqrt.hpp\"\
      \n\n#line 1 \"modint/mont_arb.hpp\"\n\n\n\n#line 7 \"modint/mont_arb.hpp\"\n\
      \n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#line 5 \"type_traits/integral.hpp\"\
      \n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T>\nusing is_signed_int128\
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
      \ 9 \"fps/fps_sqrt.hpp\"\n\nnamespace kk2 {\n\ntemplate <class FPS, class mint\
      \ = typename FPS::value_type>\nFPS dense_sqrt(const FPS &f, int deg = -1) {\n\
      \    if (deg == -1) deg = (int)f.size();\n    if ((int)f.size() == 0) return\
      \ FPS(deg, mint(0));\n    if (f[0] == mint(0)) {\n        for (int i = 1; i\
      \ < (int)f.size(); i++) {\n            if (f[i] != mint(0)) {\n            \
      \    if (i & 1) return {};\n                if (deg - i / 2 <= 0) break;\n \
      \               auto ret = dense_sqrt(f >> i, deg - i / 2);\n              \
      \  if (ret.empty()) return {};\n                ret = ret << (i / 2);\n    \
      \            if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n        \
      \        return ret;\n            }\n        }\n        return FPS(deg, mint(0));\n\
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
      \ deg);\n}\n\n} // namespace kk2\n\n\n#line 1 \"modint/mont.hpp\"\n\n\n\n#line\
      \ 8 \"modint/mont.hpp\"\n\n#line 11 \"modint/mont.hpp\"\n\nnamespace kk2 {\n\
      \ntemplate <int p> struct LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n\
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
      \ namespace kk2\n\n\n#line 1 \"others/timer.hpp\"\n\n\n\n#include <chrono>\n\
      \nnamespace kk2 {\n\nstruct Timer {\n    using clock = std::chrono::high_resolution_clock;\n\
      \    using time_point = clock::time_point;\n\n    clock::time_point start;\n\
      \n    Timer() : start(clock::now()) {}\n\n    void reset() { start = clock::now();\
      \ }\n\n    /**\n     * @brief \u6642\u9593\u3092\u8A08\u6E2C\u3059\u308B\n \
      \    * @return \u7D4C\u904E\u6642\u9593 (ms)\n     */\n    double elapsed()\
      \ const {\n        auto end = clock::now();\n        return std::chrono::duration_cast<std::chrono::nanoseconds>(end\
      \ - start).count() * 1e-6;\n    }\n};\n\n} // namespace kk2\n\n\n#line 12 \"\
      verify/unit_test/fps/sparsity_small_performance.test.cpp\"\n\nusing FPS = kk2::FPSNTT<kk2::mont998>;\n\
      using mint = kk2::mont998;\n\nnamespace {\n\nconstexpr int repetitions = 1000;\n\
      volatile unsigned benchmark_sink = 0;\n\nFPS make_series(int n, int support,\
      \ mint constant) {\n    FPS f(n);\n    f[0] = constant;\n    for (int i = 1;\
      \ i < support; ++i) {\n        int index = 1 + (long long)(i - 1) * (n - 1)\
      \ / std::max(1, support - 1);\n        f[index] = mint(1234567LL * i + 890123);\n\
      \    }\n    return f;\n}\n\ntemplate <class F> double measure(F &&fn) {\n  \
      \  kk2::Timer timer;\n    for (int i = 0; i < repetitions; ++i) {\n        auto\
      \ result = fn();\n        benchmark_sink = benchmark_sink ^ result.back().val();\n\
      \    }\n    return timer.elapsed();\n}\n\ntemplate <class Sparse, class Dense>\n\
      void check_choice(std::string_view name, bool selects_sparse, Sparse &&sparse,\
      \ Dense &&dense) {\n    sparse();\n    dense();\n    const double sparse_ms\
      \ = measure(sparse);\n    const double dense_ms = measure(dense);\n    const\
      \ double selected_ms = selects_sparse ? sparse_ms : dense_ms;\n    const double\
      \ best_ms = std::min(sparse_ms, dense_ms);\n    if (selected_ms > 2.0 * best_ms\
      \ + 0.1) {\n        std::cerr << name << \": selected=\" << selected_ms << \"\
      ms, sparse=\" << sparse_ms\n                  << \"ms, dense=\" << dense_ms\
      \ << \"ms\\n\";\n        assert(false);\n    }\n}\n\nvoid test_small_measured_choices()\
      \ {\n    for (int n : {16, 32}) {\n        for (int support : {4, n / 2}) {\n\
      \            const FPS unit = make_series(n, support, 1);\n            const\
      \ FPS other = make_series(n, support, 2);\n            FPS exponential = unit;\n\
      \            exponential[0] = 0;\n\n            check_choice(\n            \
      \    \"convolution\",\n                kk2::is_sparse_operation(kk2::FPSOperation::CONVOLUTION,\
      \ true, unit, other),\n                [&] {\n                    FPS result\
      \ = unit;\n                    return kk2::sparse_convolution(result, other);\n\
      \                },\n                [&] { return unit.dense_mul(other); });\n\
      \            check_choice(\n                \"inverse\",\n                kk2::is_sparse_operation(kk2::FPSOperation::INVERSE,\
      \ true, unit, FPS(), n),\n                [&] { return unit.sparse_inv(n); },\n\
      \                [&] { return unit.dense_inv(n); });\n            check_choice(\n\
      \                \"log\",\n                kk2::is_sparse_operation(kk2::FPSOperation::LOG,\
      \ true, unit, FPS(), n),\n                [&] { return unit.sparse_log(n); },\n\
      \                [&] { return unit.dense_log(n); });\n            check_choice(\n\
      \                \"exp\",\n                kk2::is_sparse_operation(kk2::FPSOperation::EXP,\
      \ true, exponential, FPS(), n),\n                [&] { return exponential.sparse_exp(n);\
      \ },\n                [&] { return exponential.dense_exp(n); });\n         \
      \   check_choice(\n                \"pow\",\n                kk2::is_sparse_operation(kk2::FPSOperation::POWER,\
      \ true, unit, FPS(), n),\n                [&] { return unit.sparse_pow(7, n);\
      \ },\n                [&] { return unit.dense_pow(7, n); });\n            check_choice(\n\
      \                \"division\",\n                kk2::is_sparse_operation(kk2::FPSOperation::DIVISION,\
      \ true, other, unit, n),\n                [&] { return other.sparse_div(unit,\
      \ n); },\n                [&] { return other.dense_mul(unit.dense_inv(n)).pre(n);\
      \ });\n            check_choice(\n                \"sqrt\",\n              \
      \  kk2::is_sparse_operation(kk2::FPSOperation::SQRT, true, unit, FPS(), n),\n\
      \                [&] { return kk2::sparse_sqrt(unit, n); },\n              \
      \  [&] { return kk2::dense_sqrt(unit, n); });\n\n            FPS divisor = unit;\n\
      \            divisor.back() = 1;\n            const FPS dividend = other.dense_mul(divisor);\n\
      \            check_choice(\n                \"polynomial division\",\n     \
      \           kk2::is_sparse_operation(\n                    kk2::FPSOperation::POLYNOMIAL_DIVISION,\
      \ true, dividend, divisor, n),\n                [&] { return dividend.sparse_quo(divisor);\
      \ },\n                [&] { return dividend.dense_quo(divisor); });\n      \
      \  }\n    }\n}\n\n} // namespace\n\nint main() { test_small_measured_choices();\
      \ }\n"
    name: bundled
  isFailed: false
  isVerificationFile: true
  path: verify/unit_test/fps/sparsity_small_performance.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases: []
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/fps/sparsity_small_performance.test.cpp
layout: document
---
