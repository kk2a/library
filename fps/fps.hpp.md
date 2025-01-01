---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  - icon: ':warning:'
    path: fps/multivariate_fps.hpp
    title: fps/multivariate_fps.hpp
  - icon: ':question:'
    path: fps/ntt_friendly.hpp
    title: fps/ntt_friendly.hpp
  - icon: ':x:'
    path: math_mod/comb_large.hpp
    title: math_mod/comb_large.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_composition.test.cpp
    title: verify/yosupo_fps/fps_composition.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_composition_inv.test.cpp
    title: verify/yosupo_fps/fps_composition_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_exp.test.cpp
    title: verify/yosupo_fps/fps_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_exp_arb.test.cpp
    title: verify/yosupo_fps/fps_exp_arb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_inv.test.cpp
    title: verify/yosupo_fps/fps_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_inv_arb.test.cpp
    title: verify/yosupo_fps/fps_inv_arb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_log.test.cpp
    title: verify/yosupo_fps/fps_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_log_arb.test.cpp
    title: verify/yosupo_fps/fps_log_arb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_pow.test.cpp
    title: verify/yosupo_fps/fps_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_sparse_exp.test.cpp
    title: verify/yosupo_fps/fps_sparse_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_sparse_inv.test.cpp
    title: verify/yosupo_fps/fps_sparse_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_sparse_log.test.cpp
    title: verify/yosupo_fps/fps_sparse_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_sparse_pow.test.cpp
    title: verify/yosupo_fps/fps_sparse_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_sprase_sqrt.test.cpp
    title: verify/yosupo_fps/fps_sprase_sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_sqrt.test.cpp
    title: verify/yosupo_fps/fps_sqrt.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/many_factrials.test.cpp
    title: verify/yosupo_math/many_factrials.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef FPS_HPP\n#define FPS_HPP 1\n\n#include <algorithm>\n#include <cassert>\n\
    #include <iostream>\n#include <utility>\n#include <vector>\n\n#include \"../type_traits/type_traits.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class mint> struct FormalPowerSeries : std::vector<mint>\
    \ {\n    using std::vector<mint>::vector;\n    using FPS = FormalPowerSeries;\n\
    \n    template <class OStream, is_ostream_t<OStream> * = nullptr> void display(OStream\
    \ &os) const {\n        for (int i = 0; i < (int)this->size(); i++) {\n      \
    \      os << (*this)[i] << \" \\n\"[i == (int)this->size() - 1];\n        }\n\
    \    }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr> void\
    \ output(OStream &os) const {\n        for (int i = 0; i < (int)this->size();\
    \ i++) {\n            os << (*this)[i] << (i + 1 == (int)this->size() ? \"\\n\"\
    \ : \" \");\n        }\n    }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    friend OStream &operator<<(OStream &os, const FPS &fps_) {\n\
    \        for (int i = 0; i < (int)fps_.size(); i++) {\n            os << fps_[i]\
    \ << (i + 1 == (int)fps_.size() ? \"\" : \" \");\n        }\n        return os;\n\
    \    }\n\n    template <class IStream, is_istream_t<IStream> * = nullptr> FPS\
    \ &input(IStream &is) {\n        for (int i = 0; i < (int)this->size(); i++) is\
    \ >> (*this)[i];\n        return *this;\n    }\n\n    template <class IStream,\
    \ is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream &is,\
    \ FPS &fps_) {\n        for (auto &x : fps_) is >> x;\n        return is;\n  \
    \  }\n\n    FPS &operator+=(const FPS &r) {\n        if (this->size() < r.size())\
    \ this->resize(r.size());\n        for (int i = 0; i < (int)r.size(); i++) (*this)[i]\
    \ += r[i];\n        return *this;\n    }\n\n    FPS &operator+=(const mint &r)\
    \ {\n        if (this->empty()) this->resize(1);\n        (*this)[0] += r;\n \
    \       return *this;\n    }\n\n    FPS &operator-=(const FPS &r) {\n        if\
    \ (this->size() < r.size()) this->resize(r.size());\n        for (int i = 0; i\
    \ < (int)r.size(); i++) (*this)[i] -= r[i];\n        return *this;\n    }\n\n\
    \    FPS &operator-=(const mint &r) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] -= r;\n        return *this;\n    }\n\n    FPS &operator*=(const\
    \ mint &r) {\n        for (int i = 0; i < (int)this->size(); i++) { (*this)[i]\
    \ *= r; }\n        return *this;\n    }\n\n    FPS &operator/=(const FPS &r) {\n\
    \        assert(!r.empty());\n        if (this->size() < r.size()) {\n       \
    \     this->clear();\n            return *this;\n        }\n        int n = this->size()\
    \ - r.size() + 1;\n        if ((int)r.size() <= 64) {\n            FPS f(*this),\
    \ g(r);\n            g.shrink();\n            mint coeff = g.back().inv();\n \
    \           for (auto &x : g) x *= coeff;\n            int deg = (int)f.size()\
    \ - (int)g.size() + 1;\n            int gs = g.size();\n            FPS quo(deg);\n\
    \            for (int i = deg - 1; i >= 0; i--) {\n                quo[i] = f[i\
    \ + gs - 1];\n                for (int j = 0; j < gs; j++) f[i + j] -= quo[i]\
    \ * g[j];\n            }\n            *this = quo * coeff;\n            this->resize(n,\
    \ mint(0));\n            return *this;\n        }\n        return *this = ((*this).rev().pre(n)\
    \ * r.rev().inv(n)).pre(n).rev();\n    }\n\n    FPS &operator%=(const FPS &r)\
    \ {\n        *this -= *this / r * r;\n        shrink();\n        return *this;\n\
    \    }\n\n    FPS operator+(const FPS &r) const { return FPS(*this) += r; }\n\n\
    \    FPS operator+(const mint &r) const { return FPS(*this) += r; }\n\n    FPS\
    \ operator-(const FPS &r) const { return FPS(*this) -= r; }\n\n    FPS operator-(const\
    \ mint &r) const { return FPS(*this) -= r; }\n\n    FPS operator*(const mint &r)\
    \ const { return FPS(*this) *= r; }\n\n    FPS operator/(const FPS &r) const {\
    \ return FPS(*this) /= r; }\n\n    FPS operator%(const FPS &r) const { return\
    \ FPS(*this) %= r; }\n\n    FPS operator-() const {\n        FPS ret(this->size());\n\
    \        for (int i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];\n \
    \       return ret;\n    }\n\n    FPS shrink() {\n        while (this->size()\
    \ && this->back() == mint(0)) this->pop_back();\n        return *this;\n    }\n\
    \n    FPS rev() const {\n        FPS ret(*this);\n        std::reverse(ret.begin(),\
    \ ret.end());\n        return ret;\n    }\n\n    FPS &inplace_rev() {\n      \
    \  std::reverse(this->begin(), this->end());\n        return *this;\n    }\n\n\
    \    FPS dot(const FPS &r) const {\n        FPS ret(std::min(this->size(), r.size()));\n\
    \        for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];\n\
    \        return ret;\n    }\n\n    FPS &inplace_dot(const FPS &r) {\n        this->resize(std::min(this->size(),\
    \ r.size()));\n        for (int i = 0; i < (int)this->size(); i++) (*this)[i]\
    \ *= r[i];\n        return *this;\n    }\n\n    FPS pre(int n) const {\n     \
    \   FPS ret(this->begin(), this->begin() + std::min((int)this->size(), n));\n\
    \        if ((int)ret.size() < n) ret.resize(n, mint(0));\n        return ret;\n\
    \    }\n\n    FPS &inplace_pre(int n) {\n        this->resize(n);\n        return\
    \ *this;\n    }\n\n    FPS operator>>(int n) const {\n        if (n >= (int)this->size())\
    \ return {};\n        FPS ret(this->begin() + n, this->end());\n        return\
    \ ret;\n    }\n\n    FPS operator<<(int n) const {\n        FPS ret(*this);\n\
    \        ret.insert(ret.begin(), n, mint(0));\n        return ret;\n    }\n\n\
    \    FPS diff() const {\n        const int n = (int)this->size();\n        FPS\
    \ ret(std::max(0, n - 1));\n        for (int i = 1; i < n; i++) { ret[i - 1] =\
    \ (*this)[i] * mint(i); }\n        return ret;\n    }\n\n    FPS &inplace_diff()\
    \ {\n        if (this->empty()) return *this = FPS();\n        this->erase(this->begin());\n\
    \        for (int i = 1; i <= (int)this->size(); i++) (*this)[i - 1] *= mint(i);\n\
    \        return *this;\n    }\n\n    FPS integral() const {\n        const int\
    \ n = (int)this->size();\n        FPS ret(n + 1);\n        ret[0] = mint(0);\n\
    \        if (n > 0) ret[1] = mint(1);\n        auto mod = mint::getmod();\n  \
    \      for (int i = 2; i <= n; i++) {\n            // p = q * i + r\n        \
    \    // - q / r = 1 / i (mod p)\n            ret[i] = (-ret[mod % i]) * (mod /\
    \ i);\n        }\n        for (int i = 0; i < n; i++) { ret[i + 1] *= (*this)[i];\
    \ }\n        return ret;\n    }\n\n    FPS &inplace_int() {\n        static std::vector<mint>\
    \ inv{0, 1};\n        const int n = this->size();\n        auto mod = mint::getmod();\n\
    \        while ((int)inv.size() <= n) {\n            // p = q * i + r\n      \
    \      // - q / r = 1 / i (mod p)\n            int i = inv.size();\n         \
    \   inv.push_back((-inv[mod % i]) * (mod / i));\n        }\n        this->insert(this->begin(),\
    \ mint(0));\n        for (int i = 1; i <= n; i++) (*this)[i] *= inv[i];\n    \
    \    return *this;\n    }\n\n    mint eval(mint x) const {\n        mint r = 0,\
    \ w = 1;\n        for (auto &v : *this) {\n            r += w * v;\n         \
    \   w *= x;\n        }\n        return r;\n    }\n\n    FPS log(int deg = -1)\
    \ const {\n        assert(!this->empty() && (*this)[0] == mint(1));\n        if\
    \ (deg == -1) deg = this->size();\n        return (this->diff() * this->inv(deg)).pre(deg\
    \ - 1).integral();\n    }\n\n    FPS sparse_log(int deg = -1) const {\n      \
    \  assert(!this->empty() && (*this)[0] == mint(1));\n        if (deg == -1) deg\
    \ = this->size();\n        std::vector<std::pair<int, mint>> fs;\n        for\
    \ (int i = 1; i < int(this->size()); i++) {\n            if ((*this)[i] != mint(0))\
    \ fs.emplace_back(i, (*this)[i]);\n        }\n\n        int mod = mint::getmod();\n\
    \        static std::vector<mint> inv{1, 1};\n        while ((int)inv.size() <=\
    \ deg) {\n            int i = inv.size();\n            inv.push_back(-inv[mod\
    \ % i] * (mod / i));\n        }\n\n        FPS g(deg);\n        for (int k = 0;\
    \ k < deg - 1; k++) {\n            for (auto &[j, fj] : fs) {\n              \
    \  if (k < j) break;\n                int i = k - j;\n                g[k + 1]\
    \ -= g[i + 1] * fj * (i + 1);\n            }\n            g[k + 1] *= inv[k +\
    \ 1];\n            if (k + 1 < int(this->size())) g[k + 1] += (*this)[k + 1];\n\
    \        }\n\n        return g;\n    }\n\n    template <class T> FPS pow(T k,\
    \ int deg = -1) const {\n        const int n = this->size();\n        if (deg\
    \ == -1) deg = n;\n        if (k == 0) {\n            FPS ret(deg);\n        \
    \    if (deg > 0) ret[0] = mint(1);\n            return ret;\n        }\n    \
    \    for (int i = 0; i < n; i++) {\n            if ((*this)[i] != mint(0)) {\n\
    \                mint rev = mint(1) / (*this)[i];\n                FPS ret = (((*this\
    \ * rev) >> i).log(deg) * k).exp(deg);\n                ret *= (*this)[i].pow(k);\n\
    \                ret = (ret << (i * k)).pre(deg);\n                if ((int)ret.size()\
    \ < deg) ret.resize(deg, mint(0));\n                return ret;\n            }\n\
    \            if (__int128_t(i + 1) * k >= deg) return FPS(deg, mint(0));\n   \
    \     }\n        return FPS(deg, mint(0));\n    }\n\n    template <class T> FPS\
    \ sparse_pow(T k, int deg = -1) const {\n        if (deg == -1) deg = this->size();\n\
    \        if (k == 0) {\n            FPS ret(deg);\n            if (deg > 0) ret[0]\
    \ = mint(1);\n            return ret;\n        }\n\n        int zero = 0;\n  \
    \      while (zero != int(this->size()) && (*this)[zero] == mint(0)) zero++;\n\
    \        if (zero == int(this->size()) || __int128_t(zero) * k >= deg) { return\
    \ FPS(deg, mint(0)); }\n        if (zero != 0) {\n            FPS suf(this->begin()\
    \ + zero, this->end());\n            auto g = suf.sparse_pow(k, deg - zero * k);\n\
    \            FPS ret(zero * k, mint(0));\n            std::copy(std::begin(g),\
    \ std::end(g), std::back_inserter(ret));\n            return ret;\n        }\n\
    \n        int mod = mint::getmod();\n        static std::vector<mint> inv{1, 1};\n\
    \        while ((int)inv.size() <= deg) {\n            int i = inv.size();\n \
    \           inv.push_back(-inv[mod % i] * (mod / i));\n        }\n\n        std::vector<std::pair<int,\
    \ mint>> fs;\n        for (int i = 1; i < int(this->size()); i++) {\n        \
    \    if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i]);\n        }\n\n\
    \        FPS g(deg);\n        g[0] = (*this)[0].pow(k);\n        mint denom =\
    \ (*this)[0].inv();\n        k %= mod;\n        for (int a = 1; a < deg; a++)\
    \ {\n            for (auto &[i, f_i] : fs) {\n                if (a < i) break;\n\
    \                g[a] += g[a - i] * f_i * (mint(i) * (k + 1) - a);\n         \
    \   }\n            g[a] *= denom * inv[a];\n        }\n        return g;\n   \
    \ }\n\n    // assume that r is sparse\n    // return this / r\n    FPS sparse_div(const\
    \ FPS &r, int deg = -1) const {\n        assert(!r.empty() && r[0] != mint(0));\n\
    \        if (deg == -1) deg = this->size();\n        mint ir0 = r[0].inv();\n\
    \        FPS ret = *this * ir0;\n        ret.resize(deg);\n        std::vector<std::pair<int,\
    \ mint>> gs;\n        for (int i = 1; i < (int)r.size(); i++) {\n            if\
    \ (r[i] != mint(0)) gs.emplace_back(i, r[i] * ir0);\n        }\n        for (int\
    \ i = 0; i < deg; i++) {\n            for (auto &[j, g_j] : gs) {\n          \
    \      if (i + j >= deg) break;\n                ret[i + j] -= ret[i] * g_j;\n\
    \            }\n        }\n        return ret;\n    }\n\n    FPS sparse_inv(int\
    \ deg = -1) const {\n        assert(!this->empty() && (*this)[0] != mint(0));\n\
    \        if (deg == -1) deg = this->size();\n        std::vector<std::pair<int,\
    \ mint>> fs;\n        for (int i = 1; i < int(this->size()); i++) {\n        \
    \    if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i]);\n        }\n \
    \       FPS ret(deg);\n        mint if0 = (*this)[0].inv();\n        if (0 < deg)\
    \ ret[0] = if0;\n        for (int k = 1; k < deg; k++) {\n            for (auto\
    \ &[j, fj] : fs) {\n                if (k < j) break;\n                ret[k]\
    \ += ret[k - j] * fj;\n            }\n            ret[k] *= -if0;\n        }\n\
    \        return ret;\n    }\n\n    FPS sparse_exp(int deg = -1) const {\n    \
    \    assert(this->empty() || (*this)[0] == mint(0));\n        if (deg == -1) deg\
    \ = this->size();\n        std::vector<std::pair<int, mint>> fs;\n        for\
    \ (int i = 1; i < int(this->size()); i++) {\n            if ((*this)[i] != mint(0))\
    \ fs.emplace_back(i, (*this)[i]);\n        }\n\n        int mod = mint::getmod();\n\
    \        static std::vector<mint> inv{1, 1};\n        while ((int)inv.size() <=\
    \ deg) {\n            int i = inv.size();\n            inv.push_back(-inv[mod\
    \ % i] * (mod / i));\n        }\n\n        FPS g(deg);\n        if (deg) g[0]\
    \ = 1;\n        for (int k = 0; k < deg - 1; k++) {\n            for (auto &[ip1,\
    \ fip1] : fs) {\n                int i = ip1 - 1;\n                if (k < i)\
    \ break;\n                g[k + 1] += g[k - i] * fip1 * (i + 1);\n           \
    \ }\n            g[k + 1] *= inv[k + 1];\n        }\n\n        return g;\n   \
    \ }\n\n    FPS &inplace_imos(int n) {\n        inplace_pre(n);\n        for (int\
    \ i = 0; i < n - 1; i++) { (*this)[i + 1] += (*this)[i]; }\n        return *this;\n\
    \    }\n\n    FPS imos(int n) const {\n        FPS ret(*this);\n        return\
    \ ret.inplace_imos(n);\n    }\n\n    FPS &inplace_iimos(int n) {\n        inplace_pre(n);\n\
    \        for (int i = 0; i < n - 1; i++) { (*this)[i + 1] -= (*this)[i]; }\n \
    \       return *this;\n    }\n\n    FPS iimos(int n) const {\n        FPS ret(*this);\n\
    \        return ret.inplace_iimos(n);\n    }\n\n    FPS &operator*=(const FPS\
    \ &r);\n\n    FPS operator*(const FPS &r) const { return FPS(*this) *= r; }\n\n\
    \    void but();\n    void ibut();\n    void db();\n    static int but_pr();\n\
    \    FPS inv(int deg = -1) const;\n    FPS exp(int deg = -1) const;\n};\n\n} //\
    \ namespace kk2\n\n#endif // FPS_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: fps/fps.hpp
  requiredBy:
  - math_mod/comb_large.hpp
  - fps/multivariate_fps.hpp
  - fps/ntt_friendly.hpp
  - fps/fps_arb.hpp
  timestamp: '2024-12-28 13:04:26+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_math/many_factrials.test.cpp
  - verify/yosupo_fps/fps_exp.test.cpp
  - verify/yosupo_fps/fps_sparse_pow.test.cpp
  - verify/yosupo_fps/fps_sparse_log.test.cpp
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_sparse_inv.test.cpp
  - verify/yosupo_fps/fps_composition.test.cpp
  - verify/yosupo_fps/fps_composition_inv.test.cpp
  - verify/yosupo_fps/fps_sqrt.test.cpp
  - verify/yosupo_fps/fps_inv_arb.test.cpp
  - verify/yosupo_fps/fps_sparse_exp.test.cpp
  - verify/yosupo_fps/fps_exp_arb.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_sprase_sqrt.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
  - verify/yosupo_fps/fps_log_arb.test.cpp
documentation_of: fps/fps.hpp
layout: document
redirect_from:
- /library/fps/fps.hpp
- /library/fps/fps.hpp.html
title: fps/fps.hpp
---
