---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: inv_table.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/inv_table.hpp
    - filename: fps.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/fps.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files:
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
  - math_mod/inv_table.hpp
  - type_traits/fps.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_FPS_FPS_BASE_HPP\n#define KK2_FPS_FPS_BASE_HPP 1\n\n#include\
      \ <algorithm>\n#include <cassert>\n#include <iostream>\n#include <tuple>\n#include\
      \ <utility>\n#include <vector>\n\n#include \"../math_mod/inv_table.hpp\"\n#include\
      \ \"../type_traits/fps.hpp\"\n#include \"../type_traits/io.hpp\"\n\nnamespace\
      \ kk2 {\n\ntemplate <class Derived, fps::Modular mint> struct FormalPowerSeriesBase\
      \ : std::vector<mint> {\n    using std::vector<mint>::vector;\n    using FPS\
      \ = Derived;\n    using ivta = InvTable<mint>;\n\n    // CRTP\u3092\u4F7F\u3063\
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
      };\n\n} // namespace kk2\n\n#endif // KK2_FPS_FPS_BASE_HPP\n"
    name: default
  - code: "#line 1 \"fps/fps_base.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
      #include <iostream>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
      \n#line 1 \"math_mod/inv_table.hpp\"\n\n\n\n#line 5 \"math_mod/inv_table.hpp\"\
      \n\nnamespace kk2 {\n\n/**\n * @brief `[1, n]`\u306Emod\u9006\u5143\u3092\u5217\
      \u6319\u3059\u308B\u30C6\u30FC\u30D6\u30EB\n *\n * @tparam mint\n */\ntemplate\
      \ <class mint> struct InvTable {\n    static inline std::vector<mint> _invs{0,\
      \ 1};\n    static inline auto _mod = mint::getmod();\n    InvTable() = delete;\n\
      \n    static void set_upper(int m) {\n        if ((int)_invs.size() > m) return;\n\
      \        int start = _invs.size();\n        _invs.resize(m + 1);\n        //\
      \ p = q * i + r\n        // - q / r = 1 / i (mod p)\n        for (int i = start;\
      \ i <= m; ++i) _invs[i] = (-_invs[_mod % i]) * (_mod / i);\n    }\n\n    static\
      \ inline mint inv(int n) {\n        bool neg = n < 0;\n        if (neg) n =\
      \ -n;\n        if (n >= (int)_invs.size()) set_upper(n);\n        return neg\
      \ ? -_invs[n] : _invs[n];\n    }\n};\n\n} // namespace kk2\n\n\n#line 1 \"type_traits/fps.hpp\"\
      \n\n\n\n#include <concepts>\n#include <ranges>\n#include <type_traits>\n\nnamespace\
      \ kk2::fps {\n\nnamespace category {\n\nstruct arbitrary_modulus {};\nstruct\
      \ ntt_friendly_modulus {};\n\nstruct ordinary {};\nstruct exponential_generating\
      \ {};\nstruct set_power_series {};\n\nstruct univariate {};\nstruct bivariate\
      \ {};\nstruct multivariate {};\n\n} // namespace category\n\ntemplate <class\
      \ M>\nconcept Modular = requires(M x) {\n    { M::getmod() } -> std::integral;\n\
      \    x.val();\n    { x.inv() } -> std::same_as<M>;\n};\n\ntemplate <class F>\n\
      concept FormalPowerSeries = requires(const F &f, int i) {\n    typename F::value_type;\n\
      \    typename F::modulus_category;\n    typename F::series_category;\n    {\
      \ f.size() } -> std::integral;\n    f[i];\n} && std::ranges::range<const F>;\n\
      \ntemplate <class F>\nconcept NTTFriendlyFormalPowerSeries =\n    FormalPowerSeries<F>\n\
      \    && std::same_as<typename F::modulus_category, category::ntt_friendly_modulus>;\n\
      \ntemplate <class F>\nconcept ArbitraryModulusFormalPowerSeries =\n    FormalPowerSeries<F>\
      \ && std::same_as<typename F::modulus_category, category::arbitrary_modulus>;\n\
      \ntemplate <class F>\nconcept OrdinaryFormalPowerSeries =\n    FormalPowerSeries<F>\
      \ && std::same_as<typename F::series_category, category::ordinary>;\n\ntemplate\
      \ <class F>\nconcept ExponentialGeneratingFunction =\n    FormalPowerSeries<F>\n\
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
      };\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: fps/fps_base.hpp
  pathExtension: hpp
  requiredBy:
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
documentation_of: fps/fps_base.hpp
layout: document
---
