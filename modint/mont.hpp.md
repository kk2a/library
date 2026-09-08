---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files:
    - filename: convolution_arb.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution_arb.hpp
    - filename: convolution_int.hpp
      icon: LIBRARY_NO_TESTS
      path: convolution/convolution_int.hpp
    - filename: fps_arb.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_arb.hpp
    - filename: ds_dynamic_sequence_range_affine_range_sum.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
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
    - filename: algebra.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/algebra/algebra.test.cpp
    - filename: fps.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/fps/fps.test.cpp
    - filename: convolution_and.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_and.test.cpp
    - filename: convolution_arbitrary.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_arbitrary.test.cpp
    - filename: convolution_gcd.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_gcd.test.cpp
    - filename: convolution_lcm.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_lcm.test.cpp
    - filename: convolution_multi_truncated.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_multi_truncated.test.cpp
    - filename: convolution_ntt_friendly.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_ntt_friendly.test.cpp
    - filename: convolution_or.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_or.test.cpp
    - filename: convolution_subset.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_subset.test.cpp
    - filename: convolution_xor.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_xor.test.cpp
    - filename: ds_point_set_range_composite.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
    - filename: ds_point_set_range_composite_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
    - filename: ds_potentialized_unionfind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
    - filename: ds_range_affine_range_sum.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
    - filename: ds_range_parallel_unionfind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
    - filename: ds_range_set_range_composite.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_set_range_composite.test.cpp
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
    - filename: graph_enumerate_triangle.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_enumerate_triangle.test.cpp
    - filename: tree_vertex_set_path_composite_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
    - filename: matrix_det.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_det.test.cpp
    - filename: matrix_inv.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_inv.test.cpp
    - filename: matrix_pow.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_pow.test.cpp
    - filename: matrix_product.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_product.test.cpp
    - filename: matrix_rank.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_rank.test.cpp
    - filename: solution_of_linear_equations.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/solution_of_linear_equations.test.cpp
    - filename: enumerate_bell_number.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_bell_number.test.cpp
    - filename: enumerate_stirling_number_of_the_first_kind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
    - filename: many_factrials.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/many_factrials.test.cpp
    - filename: prefix_sum_of_multiplicative_function.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
    - filename: sum_of_totient_function.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/sum_of_totient_function.test.cpp
    - filename: yuki_1510.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yuki/yuki_1510.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_MODINT_MONT_HPP\n#define KK2_MODINT_MONT_HPP 1\n\n#include\
      \ <cassert>\n#include <cstdint>\n#include <iostream>\n#include <type_traits>\n\
      \n#include \"../type_traits/integral.hpp\"\n#include \"../type_traits/io.hpp\"\
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
      \ namespace kk2\n\n#endif // KK2_MODINT_MONT_HPP\n"
    name: default
  - code: "#line 1 \"modint/mont.hpp\"\n\n\n\n#include <cassert>\n#include <cstdint>\n\
      #include <iostream>\n#include <type_traits>\n\n#line 1 \"type_traits/integral.hpp\"\
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
      \ namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: modint/mont.hpp
  pathExtension: hpp
  requiredBy:
  - convolution/convolution_arb.hpp
  - convolution/convolution_int.hpp
  - fps/fps_arb.hpp
  - verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
  - verify/yosupo_fps/fps_composition.test.cpp
  - verify/yosupo_fps/fps_composition_inv.test.cpp
  - verify/yosupo_fps/fps_exp_arb.test.cpp
  - verify/yosupo_fps/fps_multipoint_evaluation_geometric.test.cpp
  - verify/yosupo_fps/poly_interpolation_geometric.test.cpp
  - verify/yosupo_fps/poly_sample_point_shift.test.cpp
  - verify/yosupo_fps/poly_to_newton_basis.test.cpp
  - verify/yosupo_math/kth_term_of_linearly_recurrent_sequence.test.cpp
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/type_traits/algebra/algebra.test.cpp
  - verify/unit_test/type_traits/fps/fps.test.cpp
  - verify/yosupo_convolution/convolution_and.test.cpp
  - verify/yosupo_convolution/convolution_arbitrary.test.cpp
  - verify/yosupo_convolution/convolution_gcd.test.cpp
  - verify/yosupo_convolution/convolution_lcm.test.cpp
  - verify/yosupo_convolution/convolution_multi_truncated.test.cpp
  - verify/yosupo_convolution/convolution_ntt_friendly.test.cpp
  - verify/yosupo_convolution/convolution_or.test.cpp
  - verify/yosupo_convolution/convolution_subset.test.cpp
  - verify/yosupo_convolution/convolution_xor.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  - verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  - verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
  - verify/yosupo_ds/ds_range_set_range_composite.test.cpp
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
  - verify/yosupo_graph/graph_enumerate_triangle.test.cpp
  - verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
  - verify/yosupo_linalg/matrix_det.test.cpp
  - verify/yosupo_linalg/matrix_inv.test.cpp
  - verify/yosupo_linalg/matrix_pow.test.cpp
  - verify/yosupo_linalg/matrix_product.test.cpp
  - verify/yosupo_linalg/matrix_rank.test.cpp
  - verify/yosupo_linalg/solution_of_linear_equations.test.cpp
  - verify/yosupo_math/enumerate_bell_number.test.cpp
  - verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
  - verify/yosupo_math/many_factrials.test.cpp
  - verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
  - verify/yosupo_math/sum_of_totient_function.test.cpp
  - verify/yuki/yuki_1510.test.cpp
documentation_of: modint/mont.hpp
layout: document
---
