---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':question:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':question:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':x:'
    path: convolution/multi_convolution_truncated.hpp
    title: convolution/multi_convolution_truncated.hpp
  - icon: ':question:'
    path: fps/fps_ntt_friendly.hpp
    title: fps/fps_ntt_friendly.hpp
  - icon: ':question:'
    path: fps/fps_sparsity_detector.hpp
    title: fps/fps_sparsity_detector.hpp
  - icon: ':question:'
    path: math_mod/butterfly.hpp
    title: math_mod/butterfly.hpp
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':question:'
    path: math_mod/primitive_root.hpp
    title: math_mod/primitive_root.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 2 more times]\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_FPS_FPS_MULTIVARIATE_HPP\n#define KK2_FPS_FPS_MULTIVARIATE_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include\
    \ <vector>\n\n#include \"../convolution/multi_convolution_truncated.hpp\"\n#include\
    \ \"../type_traits/io.hpp\"\n#include \"fps_ntt_friendly.hpp\"\n\nnamespace kk2\
    \ {\n\ntemplate <typename mint> struct MultivariateFormalPowerSeries {\n    using\
    \ mfps = MultivariateFormalPowerSeries;\n    using fps = FormalPowerSeriesNTTFriendly<mint>;\n\
    \    using value_type = mint;\n\n    std::vector<int> base;\n    fps f;\n\n  \
    \  MultivariateFormalPowerSeries() = default;\n\n    MultivariateFormalPowerSeries(const\
    \ std::vector<int> &base_) : base(base_) {\n        int n = 1;\n        for (int\
    \ x : base) n *= x;\n        f.resize(n);\n    }\n\n    MultivariateFormalPowerSeries(const\
    \ std::vector<int> &base_, const fps &f_)\n        : base(base_),\n          f(f_)\
    \ {}\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend\
    \ OStream &operator<<(OStream &os, const mfps &mfps_) {\n        for (int i =\
    \ 0; i < (int)mfps_.f.size(); i++)\n            os << mfps_.f[i] << (i + 1 ==\
    \ (int)mfps_.f.size() ? \"\" : \" \");\n        return os;\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr> void output(OStream &os)\
    \ const {\n        for (int i = 0; i < (int)f.size(); i++) os << f[i] << (i +\
    \ 1 == (int)f.size() ? \"\\n\" : \" \");\n    }\n\n    template <class IStream,\
    \ is_istream_t<IStream> * = nullptr> mfps &input(IStream &is) {\n        for (auto\
    \ &x : f) is >> x;\n        return *this;\n    }\n\n    template <class IStream,\
    \ is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream &is,\
    \ mfps &mfps_) {\n        for (auto &x : mfps_.f) is >> x;\n        return is;\n\
    \    }\n\n    template <typename T, typename... Ts> int _id(int x, T y, Ts...\
    \ ys) {\n        assert(x < (int)base.size() && (int)y < base[x]);\n        if\
    \ constexpr (sizeof...(Ts) == 0) return y;\n        else return y + base[x] *\
    \ _id(x + 1, ys...);\n    }\n\n    template <typename... Args> int id(Args...\
    \ args) {\n        static_assert(sizeof...(Args) > 0);\n        return _id(0,\
    \ args...);\n    }\n\n    template <typename... Args> mint &operator()(Args...\
    \ args) { return f[id(args...)]; }\n\n    mint &operator[](int i) { return f[i];\
    \ }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr> void display(OStream\
    \ &os) const {\n        for (int i = 0; i < (int)f.size(); i++) {\n          \
    \  int x = i;\n            os << \"f(\";\n            for (int j = 0; j < (int)base.size();\
    \ j++) {\n                os << x % base[j] << (j + 1 == (int)base.size() ? \"\
    ) = \" : \", \");\n                x /= base[j];\n            }\n            os\
    \ << f[i] << \"\\n\";\n        }\n    }\n\n    mfps &operator+=(const mfps &rhs)\
    \ {\n        assert(base == rhs.base && f.size() == rhs.f.size());\n        for\
    \ (int i = 0; i < (int)f.size(); i++) f[i] += rhs.f[i];\n        return *this;\n\
    \    }\n\n    mfps &operator-=(const mfps &rhs) {\n        assert(base == rhs.base\
    \ && f.size() == rhs.f.size());\n        for (int i = 0; i < (int)f.size(); i++)\
    \ f[i] -= rhs.f[i];\n        return *this;\n    }\n\n    mfps &operator*=(const\
    \ mfps &rhs) {\n        assert(base == rhs.base && f.size() == rhs.f.size());\n\
    \        multi_convolution_truncated(f, rhs.f, base);\n        return *this;\n\
    \    }\n\n    mfps &operator+=(const mint &rhs) {\n        assert(!f.empty());\n\
    \        f[0] += rhs;\n        return *this;\n    }\n\n    mfps &operator-=(const\
    \ mint &rhs) {\n        assert(!f.empty());\n        f[0] -= rhs;\n        return\
    \ *this;\n    }\n\n    mfps &operator*=(const mint &rhs) {\n        for (auto\
    \ &x : f) x *= rhs;\n        return *this;\n    }\n\n    mfps &operator/=(const\
    \ mint &rhs) {\n        for (auto &x : f) x /= rhs;\n        return *this;\n \
    \   }\n\n    mfps operator+(const mfps &rhs) const { return mfps(*this) += rhs;\
    \ }\n\n    mfps operator-(const mfps &rhs) const { return mfps(*this) -= rhs;\
    \ }\n\n    mfps operator*(const mfps &rhs) const { return mfps(*this) *= rhs;\
    \ }\n\n    mfps operator+(const mint &rhs) const { return mfps(*this) += rhs;\
    \ }\n\n    mfps operator-(const mint &rhs) const { return mfps(*this) -= rhs;\
    \ }\n\n    mfps operator*(const mint &rhs) const { return mfps(*this) *= rhs;\
    \ }\n\n    mfps operator/(const mint &rhs) const { return mfps(*this) /= rhs;\
    \ }\n\n    mfps operator+() const { return mfps(*this); }\n\n    mfps operator-()\
    \ const { return mfps(base, -f); }\n\n    friend bool operator==(const mfps &lhs,\
    \ const mfps &rhs) {\n        return lhs.f == rhs.f && lhs.base == rhs.base;\n\
    \    }\n\n    friend bool operator!=(const mfps &lhs, const mfps &rhs) { return\
    \ !(lhs == rhs); }\n\n    mfps diff() const {\n        mfps ret(*this);\n    \
    \    for (int i = 0; i < (int)ret.f.size(); i++) ret.f[i] *= i;\n        return\
    \ ret;\n    }\n\n    mfps &inplace_diff() {\n        for (int i = 0; i < (int)f.size();\
    \ i++) f[i] *= i;\n        return *this;\n    }\n\n    static std::vector<mint>\
    \ _inv;\n\n    static void ensure_inv(int n) {\n        while ((int)_inv.size()\
    \ <= n) {\n            int i = _inv.size();\n            _inv.push_back((-_inv[mint::getmod()\
    \ % i]) * (mint::getmod() / i));\n        }\n    }\n\n    mfps integral() const\
    \ {\n        ensure_inv(f.size());\n        mfps ret(*this);\n        for (int\
    \ i = 1; i < (int)ret.f.size(); i++) ret.f[i] *= _inv[i];\n        return ret;\n\
    \    }\n\n    mfps &inplace_int() {\n        ensure_inv(f.size());\n        for\
    \ (int i = 1; i < (int)f.size(); i++) f[i] *= _inv[i];\n        return *this;\n\
    \    }\n\n    mfps inv() const {\n        assert(!f.empty() && f[0] != mint(0));\n\
    \        if (base.empty()) return mfps(base, fps{f[0].inv()});\n\n        int\
    \ n = f.size(), k = base.size();\n        int z = 1;\n        while (z < 2 * n\
    \ - 1) z <<= 1;\n        std::vector<int> chi(z);\n        for (int i = 0; i <\
    \ n; i++) {\n            int x = i;\n            for (int j = 0; j < k - 1; j++)\
    \ chi[i] += (x /= base[j]);\n            chi[i] %= k;\n        }\n        auto\
    \ naive_and_dot = [&k](const std::vector<fps> &a,\n                          \
    \        const std::vector<fps> &b,\n                                  std::vector<fps>\
    \ &c) -> void {\n            std::vector<mint> tmp(k);\n            for (int ii\
    \ = 0; ii < (int)a[0].size(); ii++) {\n                for (int i = 0; i < k;\
    \ i++) {\n                    for (int j = 0; j < k; j++) {\n                \
    \        tmp[i + j - (i + j >= k ? k : 0)] += a[i][ii] * b[j][ii];\n         \
    \           }\n                }\n                for (int i = 0; i < k; i++)\
    \ c[i][ii] = tmp[i], tmp[i] = mint{0};\n            }\n        };\n\n        //\
    \ reference:\n        // https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp\n\
    \        // Let g_k := f_k^{-1} mod x^k, \\deg g_k < k.\n        // Then we obtain\
    \ g_1, g_2, g_4, ... by using the following recurrence:\n        // - g_1 = (f_0)^{-1}\
    \ ...(1)\n        // - g_{2k} = 2g_k - g_k^2 f mod x^2k ...(2)\n        // - [x^{k\
    \ + i}]g_{2k} = [x^{k + i}](-g_k^2 f) ...(3)\n        fps g(z);\n        g[0]\
    \ = f[0].inv(); // by (1)\n        for (int d = 1; d < n; d <<= 1) {\n       \
    \     std::vector<fps> a(k, fps(2 * d)), b(k, fps(2 * d)), c(k, fps(2 * d));\n\
    \            for (int i = 0; i < std::min((int)f.size(), 2 * d); i++) a[chi[i]][i]\
    \ = f[i];\n            for (int i = 0; i < d; i++) b[chi[i]][i] = g[i];\n    \
    \        for (auto &x : a) x.but();\n            for (auto &x : b) x.but();\n\
    \            naive_and_dot(a, b, c);\n            for (auto &x : c) x.ibut();\n\
    \            // compute g_d f\n\n            for (auto &x : a) std::fill(std::begin(x),\
    \ std::end(x), mint(0));\n\n            for (int i = d; i < 2 * d; i++) a[chi[i]][i]\
    \ = c[chi[i]][i];\n            for (auto &x : a) x.but();\n            naive_and_dot(a,\
    \ b, c);\n            for (auto &x : c) x.ibut();\n            // compute g_d^2\
    \ f\n\n            // by (2), (3)\n            for (int i = d; i < 2 * d; i++)\
    \ g[i] = -c[chi[i]][i];\n        }\n        mfps res(*this);\n        res.f =\
    \ fps(std::begin(g), std::begin(g) + n);\n        return res;\n    }\n\n    mfps\
    \ log() const {\n        assert(!f.empty() && f[0] == mint(1));\n        return\
    \ ((*this).diff() * (*this).inv()).integral();\n    }\n\n    mfps exp() const\
    \ {\n        assert(!f.empty() && f[0] == mint(0));\n        int n = f.size();\n\
    \        mfps res(base, fps{1});\n        for (int d = 1; d < n; d <<= 1) {\n\
    \            int s = std::min(n, 2 * d);\n            res.f.resize(s, mint(0));\n\
    \            res *= mfps(base, fps(std::begin(f), std::begin(f) + s)) - res.log()\
    \ + 1;\n        }\n        return res;\n    }\n\n    mfps pow(long long e) const\
    \ {\n        assert(!f.empty());\n        if (f[0] != mint(0)) {\n           \
    \ mint f0inv = f[0].inv(), coef = f[0].pow(e);\n            return (((*this) *\
    \ f0inv).log() * e).exp() * coef;\n        }\n        int n = f.size();\n    \
    \    long long base_sum = 0;\n        for (auto &b : base) base_sum += b - 1;\n\
    \        if (e > base_sum) return mfps(base, fps(n));\n        mfps res(base,\
    \ fps(n)), a(*this);\n        res.f[0] = 1;\n        while (e) {\n           \
    \ if (e & 1) res *= a;\n            if (e >>= 1) a *= a;\n        }\n        return\
    \ res;\n    }\n};\n\ntemplate <typename mint> std::vector<mint> MultivariateFormalPowerSeries<mint>::_inv\
    \ = {0, 1};\n\n} // namespace kk2\n\n#endif // KK2_FPS_FPS_MULTIVARIATE_HPP\n"
  dependsOn:
  - convolution/multi_convolution_truncated.hpp
  - convolution/convolution.hpp
  - fps/fps_sparsity_detector.hpp
  - bit/bitcount.hpp
  - type_traits/integral.hpp
  - math_mod/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - type_traits/io.hpp
  - fps/fps_ntt_friendly.hpp
  - convolution/convolution.hpp
  isVerificationFile: false
  path: fps/fps_multivariate.hpp
  requiredBy: []
  timestamp: '2025-04-24 20:44:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/fps_multivariate.hpp
layout: document
redirect_from:
- /library/fps/fps_multivariate.hpp
- /library/fps/fps_multivariate.hpp.html
title: fps/fps_multivariate.hpp
---
