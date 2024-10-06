---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/butterfly.hpp
    title: convolution/butterfly.hpp
  - icon: ':question:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps.hpp
    title: fps/fps.hpp
  - icon: ':heavy_check_mark:'
    path: fps/ntt_friendly.hpp
    title: fps/ntt_friendly.hpp
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':question:'
    path: math_mod/primitive_root.hpp
    title: math_mod/primitive_root.hpp
  - icon: ':question:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/pow_of_formal_power_series
  bundledCode: "#line 1 \"verify/yosupo_fps/fps_pow.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\n\n#line 1 \"fps/ntt_friendly.hpp\"\
    \n\n\n\n#line 1 \"convolution/convolution.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <vector>\n\n#line 1 \"convolution/butterfly.hpp\"\n\n\n\n#line 5 \"convolution/butterfly.hpp\"\
    \n\n#line 1 \"math_mod/primitive_root.hpp\"\n\n\n\n#line 1 \"math_mod/pow_mod.hpp\"\
    \n\n\n\n#include <cassert>\n\n#line 1 \"type_traits/type_traits.hpp\"\n\n\n\n\
    #include <type_traits>\n\nnamespace kk2 {\n\ntemplate <typename T>\nusing is_signed_int128\
    \ = typename std::conditional<std::is_same<T, __int128_t>::value\n           \
    \                                            or std::is_same<T, __int128>::value,\n\
    \                                                   std::true_type,\n        \
    \                                           std::false_type>::type;\n\ntemplate\
    \ <typename T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value\n                                  or std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <typename T>\nusing\
    \ is_integral_extended =\n    typename std::conditional<std::is_integral<T>::value\
    \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_signed_extended =\n\
    \    typename std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_extended\
    \ =\n    typename std::conditional<std::is_unsigned<T>::value or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\n} // namespace kk2\n\n\n#line 7 \"math_mod/pow_mod.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow_mod(T\
    \ x, U n, T m) {\n    assert(!is_signed_extended<U>::value || n >= 0);\n    if\
    \ (m == 1) return S(0);\n    S _m = S(m), r = 1;\n    S y = S(x) % _m;\n    if\
    \ (y < 0) y += _m;\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n  \
    \      y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n} // namespace\
    \ kk2\n\n\n#line 5 \"math_mod/primitive_root.hpp\"\n\nnamespace kk2 {\n\nconstexpr\
    \ int primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n    if (m\
    \ == 167772161) return 3;\n    if (m == 469762049) return 3;\n    if (m == 754974721)\
    \ return 11;\n    if (m == 998244353) return 3;\n    if (m == 1107296257) return\
    \ 10;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) { x /= i; }\n        }\n    }\n    if (x > 1) {\
    \ divs[cnt++] = x; }\n    for (int g = 2;; g++) {\n        bool ok = true;\n \
    \       for (int i = 0; i < cnt; i++) {\n            if (pow_mod<long long>(g,\
    \ (m - 1) / divs[i], m) == 1) {\n                ok = false;\n               \
    \ break;\n            }\n        }\n        if (ok) return g;\n    }\n}\n\ntemplate\
    \ <int m> static constexpr int primitive_root = primitive_root_constexpr(m);\n\
    \n} // namespace kk2\n\n\n#line 7 \"convolution/butterfly.hpp\"\n\nnamespace kk2\
    \ {\n\ntemplate <class FPS, class mint = typename FPS::value_type> void butterfly(FPS\
    \ &a) {\n    static int g = primitive_root<mint::getmod()>;\n    int n = int(a.size());\n\
    \    int h = 0;\n    while ((1U << h) < (unsigned int)(n)) h++;\n    static bool\
    \ first = true;\n    static mint sum_e2[30]; // sum_e[i] = ies[0] * ... * ies[i\
    \ - 1] * es[i]\n    static mint sum_e3[30];\n    static mint es[30], ies[30];\
    \ // es[i]^(2^(2+i)) == 1\n    if (first) {\n        first = false;\n        int\
    \ cnt2 = __builtin_ctz(mint::getmod() - 1);\n        mint e = mint(g).pow((mint::getmod()\
    \ - 1) >> cnt2), ie = e.inv();\n        for (int i = cnt2; i >= 2; i--) {\n  \
    \          // e^(2^i) == 1\n            es[i - 2] = e;\n            ies[i - 2]\
    \ = ie;\n            e *= e;\n            ie *= ie;\n        }\n        mint now\
    \ = 1;\n        for (int i = 0; i <= cnt2 - 2; i++) {\n            sum_e2[i] =\
    \ es[i] * now;\n            now *= ies[i];\n        }\n        now = 1;\n    \
    \    for (int i = 0; i <= cnt2 - 3; i++) {\n            sum_e3[i] = es[i + 1]\
    \ * now;\n            now *= ies[i + 1];\n        }\n    }\n\n    int len = 0;\n\
    \    while (len < h) {\n        if (h - len == 1) {\n            int p = 1 <<\
    \ (h - len - 1);\n            mint rot = 1;\n            for (int s = 0; s < (1\
    \ << len); s++) {\n                int offset = s << (h - len);\n            \
    \    for (int i = 0; i < p; i++) {\n                    auto l = a[i + offset];\n\
    \                    auto r = a[i + offset + p] * rot;\n                    a[i\
    \ + offset] = l + r;\n                    a[i + offset + p] = l - r;\n       \
    \         }\n                if (s + 1 != (1 << len)) rot *= sum_e2[__builtin_ctz(~(unsigned\
    \ int)(s))];\n            }\n            len++;\n        } else {\n          \
    \  int p = 1 << (h - len - 2);\n            mint rot = 1, imag = es[0];\n    \
    \        for (int s = 0; s < (1 << len); s++) {\n                mint rot2 = rot\
    \ * rot;\n                mint rot3 = rot2 * rot;\n                int offset\
    \ = s << (h - len);\n                for (int i = 0; i < p; i++) {\n         \
    \           auto a0 = a[i + offset];\n                    auto a1 = a[i + offset\
    \ + p] * rot;\n                    auto a2 = a[i + offset + p * 2] * rot2;\n \
    \                   auto a3 = a[i + offset + p * 3] * rot3;\n                \
    \    auto a1na3imag = (a1 - a3) * imag;\n                    a[i + offset] = a0\
    \ + a2 + a1 + a3;\n                    a[i + offset + p] = a0 + a2 - a1 - a3;\n\
    \                    a[i + offset + p * 2] = a0 - a2 + a1na3imag;\n          \
    \          a[i + offset + p * 3] = a0 - a2 - a1na3imag;\n                }\n \
    \               if (s + 1 != (1 << len)) rot *= sum_e3[__builtin_ctz(~(unsigned\
    \ int)(s))];\n            }\n            len += 2;\n        }\n    }\n}\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type> void butterfly_inv(FPS &a)\
    \ {\n    static constexpr int g = primitive_root<mint::getmod()>;\n    int n =\
    \ int(a.size());\n    int h = 0;\n    while ((1U << h) < (unsigned int)(n)) h++;\n\
    \    static bool first = true;\n    static mint sum_ie2[30]; // sum_ie[i] = es[0]\
    \ * ... * es[i - 1] * ies[i]\n    static mint sum_ie3[30];\n    static mint es[30],\
    \ ies[30]; // es[i]^(2^(2+i)) == 1\n    static mint invn[30];\n    if (first)\
    \ {\n        first = false;\n        int cnt2 = __builtin_ctz(mint::getmod() -\
    \ 1);\n        mint e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();\n\
    \        for (int i = cnt2; i >= 2; i--) {\n            // e^(2^i) == 1\n    \
    \        es[i - 2] = e;\n            ies[i - 2] = ie;\n            e *= e;\n \
    \           ie *= ie;\n        }\n        mint now = 1;\n        for (int i =\
    \ 0; i <= cnt2 - 2; i++) {\n            sum_ie2[i] = ies[i] * now;\n         \
    \   now *= es[i];\n        }\n        now = 1;\n        for (int i = 0; i <= cnt2\
    \ - 3; i++) {\n            sum_ie3[i] = ies[i + 1] * now;\n            now *=\
    \ es[i + 1];\n        }\n\n        invn[0] = 1;\n        invn[1] = mint::getmod()\
    \ / 2 + 1;\n        for (int i = 2; i < 30; i++) invn[i] = invn[i - 1] * invn[1];\n\
    \    }\n    int len = h;\n    while (len) {\n        if (len == 1) {\n       \
    \     int p = 1 << (h - len);\n            mint irot = 1;\n            for (int\
    \ s = 0; s < (1 << (len - 1)); s++) {\n                int offset = s << (h -\
    \ len + 1);\n                for (int i = 0; i < p; i++) {\n                 \
    \   auto l = a[i + offset];\n                    auto r = a[i + offset + p];\n\
    \                    a[i + offset] = l + r;\n                    a[i + offset\
    \ + p] = (l - r) * irot;\n                }\n                if (s + 1 != (1 <<\
    \ (len - 1))) irot *= sum_ie2[__builtin_ctz(~(unsigned int)(s))];\n          \
    \  }\n            len--;\n        } else {\n            int p = 1 << (h - len);\n\
    \            mint irot = 1, iimag = ies[0];\n            for (int s = 0; s < (1\
    \ << ((len - 2))); s++) {\n                mint irot2 = irot * irot;\n       \
    \         mint irot3 = irot2 * irot;\n                int offset = s << (h - len\
    \ + 2);\n                for (int i = 0; i < p; i++) {\n                    auto\
    \ a0 = a[i + offset];\n                    auto a1 = a[i + offset + p];\n    \
    \                auto a2 = a[i + offset + p * 2];\n                    auto a3\
    \ = a[i + offset + p * 3];\n                    auto a2na3iimag = (a2 - a3) *\
    \ iimag;\n\n                    a[i + offset] = a0 + a1 + a2 + a3;\n         \
    \           a[i + offset + p] = (a0 - a1 + a2na3iimag) * irot;\n             \
    \       a[i + offset + p * 2] = (a0 + a1 - a2 - a3) * irot2;\n               \
    \     a[i + offset + p * 3] = (a0 - a1 - a2na3iimag) * irot3;\n              \
    \  }\n                if (s + 1 != (1 << (len - 2))) irot *= sum_ie3[__builtin_ctz(~(unsigned\
    \ int)(s))];\n            }\n            len -= 2;\n        }\n    }\n\n    for\
    \ (int i = 0; i < n; i++) a[i] *= invn[h];\n}\n\ntemplate <class FPS, class mint\
    \ = typename FPS::value_type> void doubling(FPS &a) {\n    int n = a.size();\n\
    \    auto b = a;\n    int z = 1;\n    butterfly_inv(b);\n    mint r = 1, zeta\
    \ = mint(primitive_root<mint::getmod()>).pow((mint::getmod() - 1) / (n << 1));\n\
    \    for (int i = 0; i < n; i++) {\n        b[i] *= r;\n        r *= zeta;\n \
    \   }\n    butterfly(b);\n    std::copy(b.begin(), b.end(), std::back_inserter(a));\n\
    }\n\n} // namespace kk2\n\n\n#line 8 \"convolution/convolution.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type> FPS convolution(FPS\
    \ &a, const FPS &b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n\
    \ || !m) return {};\n    if (std::min(n, m) <= 60) {\n        FPS res(n + m -\
    \ 1);\n        for (int i = 0; i < n; i++) {\n            for (int j = 0; j <\
    \ m; j++) { res[i + j] += a[i] * b[j]; }\n        }\n        a = res;\n      \
    \  return a;\n    }\n    int z = 1;\n    while (z < n + m - 1) z <<= 1;\n    if\
    \ (a == b) {\n        a.resize(z);\n        butterfly(a);\n        for (int i\
    \ = 0; i < z; i++) a[i] *= a[i];\n    } else {\n        a.resize(z);\n       \
    \ butterfly(a);\n        FPS t(b.begin(), b.end());\n        t.resize(z);\n  \
    \      butterfly(t);\n        for (int i = 0; i < z; i++) a[i] *= t[i];\n    }\n\
    \    butterfly_inv(a);\n    a.resize(n + m - 1);\n    return a;\n}\n\n} // namespace\
    \ kk2\n\n\n#line 1 \"fps/fps.hpp\"\n\n\n\n#line 6 \"fps/fps.hpp\"\n#include <utility>\n\
    #line 8 \"fps/fps.hpp\"\n\nnamespace kk2 {\n\ntemplate <class mint> struct FormalPowerSeries\
    \ : std::vector<mint> {\n    using std::vector<mint>::vector;\n    using FPS =\
    \ FormalPowerSeries;\n\n    FPS &operator+=(const FPS &r) {\n        if (this->size()\
    \ < r.size()) this->resize(r.size());\n        for (int i = 0; i < (int)r.size();\
    \ i++) (*this)[i] += r[i];\n        return *this;\n    }\n\n    FPS &operator+=(const\
    \ mint &r) {\n        if (this->empty()) this->resize(1);\n        (*this)[0]\
    \ += r;\n        return *this;\n    }\n\n    FPS &operator-=(const FPS &r) {\n\
    \        if (this->size() < r.size()) this->resize(r.size());\n        for (int\
    \ i = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n        return *this;\n\
    \    }\n\n    FPS &operator-=(const mint &r) {\n        if (this->empty()) this->resize(1);\n\
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
    \ ret.end());\n        return ret;\n    }\n\n    FPS inplace_rev() {\n       \
    \ std::reverse(this->begin(), this->end());\n        return *this;\n    }\n\n\
    \    FPS dot(const FPS &r) const {\n        FPS ret(std::min(this->size(), r.size()));\n\
    \        for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];\n\
    \        return ret;\n    }\n\n    FPS inplace_dot(const FPS &r) {\n        this->resize(std::min(this->size(),\
    \ r.size()));\n        for (int i = 0; i < (int)this->size(); i++) (*this)[i]\
    \ *= r[i];\n        return *this;\n    }\n\n    FPS pre(int n) const {\n     \
    \   FPS ret(this->begin(), this->begin() + std::min((int)this->size(), n));\n\
    \        if ((int)ret.size() < n) ret.resize(n, mint(0));\n        return ret;\n\
    \    }\n\n    FPS inplace_pre(int n) {\n        this->resize(n);\n        return\
    \ *this;\n    }\n\n    FPS operator>>(int n) const {\n        if (n >= (int)this->size())\
    \ return {};\n        FPS ret(this->begin() + n, this->end());\n        return\
    \ ret;\n    }\n\n    FPS operator<<(int n) const {\n        FPS ret(*this);\n\
    \        ret.insert(ret.begin(), n, mint(0));\n        return ret;\n    }\n\n\
    \    FPS diff() const {\n        const int n = (int)this->size();\n        FPS\
    \ ret(std::max(0, n - 1));\n        for (int i = 1; i < n; i++) { ret[i - 1] =\
    \ (*this)[i] * mint(i); }\n        return ret;\n    }\n\n    FPS inplace_diff()\
    \ {\n        if (this->empty()) return {};\n        this->erase(this->begin());\n\
    \        for (int i = 1; i <= (int)this->size(); i++) (*this)[i - 1] *= mint(i);\n\
    \        return *this;\n    }\n\n    FPS integral() const {\n        const int\
    \ n = (int)this->size();\n        FPS ret(n + 1);\n        ret[0] = mint(0);\n\
    \        if (n > 0) ret[1] = mint(1);\n        auto mod = mint::getmod();\n  \
    \      for (int i = 2; i <= n; i++) {\n            // p = q * i + r\n        \
    \    // - q / r = 1 / i (mod p)\n            ret[i] = (-ret[mod % i]) * (mod /\
    \ i);\n        }\n        for (int i = 0; i < n; i++) { ret[i + 1] *= (*this)[i];\
    \ }\n        return ret;\n    }\n\n    FPS inplace_int() {\n        static std::vector<mint>\
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
    \ }\n\n    FPS inplace_imos(int n) {\n        inplace_pre(n);\n        for (int\
    \ i = 0; i < n - 1; i++) { (*this)[i + 1] += (*this)[i]; }\n        return *this;\n\
    \    }\n\n    FPS imos(int n) const {\n        FPS ret(*this);\n        return\
    \ ret.inplace_imos(n);\n    }\n\n    FPS inplace_iimos(int n) {\n        inplace_pre(n);\n\
    \        for (int i = 0; i < n - 1; i++) { (*this)[i + 1] -= (*this)[i]; }\n \
    \       return *this;\n    }\n\n    FPS iimos(int n) const {\n        FPS ret(*this);\n\
    \        return ret.inplace_iimos(n);\n    }\n\n    FPS &operator*=(const FPS\
    \ &r);\n\n    FPS operator*(const FPS &r) const { return FPS(*this) *= r; }\n\n\
    \    void but();\n    void ibut();\n    void db();\n    static int but_pr();\n\
    \    FPS inv(int deg = -1) const;\n    FPS exp(int deg = -1) const;\n};\n\n} //\
    \ namespace kk2\n\n\n#line 6 \"fps/ntt_friendly.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class mint>\nFormalPowerSeries<mint> &FormalPowerSeries<mint>::operator*=(const\
    \ FormalPowerSeries<mint> &r) {\n    if (this->empty() || r.empty()) {\n     \
    \   this->clear();\n        return *this;\n    }\n    convolution(*this, r);\n\
    \    return *this;\n}\n\ntemplate <class mint> void FormalPowerSeries<mint>::but()\
    \ {\n    butterfly(*this);\n}\n\ntemplate <class mint> void FormalPowerSeries<mint>::ibut()\
    \ {\n    butterfly_inv(*this);\n}\n\ntemplate <class mint> void FormalPowerSeries<mint>::db()\
    \ {\n    doubling(*this);\n}\n\ntemplate <class mint> int FormalPowerSeries<mint>::but_pr()\
    \ {\n    return primitive_root<mint::getmod()>;\n}\n\ntemplate <class mint> FormalPowerSeries<mint>\
    \ FormalPowerSeries<mint>::inv(int deg) const {\n    assert((*this)[0] != mint(0));\n\
    \    if (deg == -1) deg = (int)this->size();\n    FormalPowerSeries<mint> res(deg);\n\
    \    res[0] = {mint(1) / (*this)[0]};\n    for (int d = 1; d < deg; d <<= 1) {\n\
    \        FormalPowerSeries<mint> f(2 * d), g(2 * d);\n        std::copy(std::begin(*this),\n\
    \                  std::begin(*this) + std::min((int)this->size(), 2 * d),\n \
    \                 std::begin(f));\n        std::copy(std::begin(res), std::begin(res)\
    \ + d, std::begin(g));\n        f.but();\n        g.but();\n        f.inplace_dot(g);\n\
    \        f.ibut();\n        std::fill(std::begin(f), std::begin(f) + d, mint(0));\n\
    \        f.but();\n        f.inplace_dot(g);\n        f.ibut();\n        for (int\
    \ j = d; j < std::min(2 * d, deg); j++) res[j] = -f[j];\n    }\n    return res.pre(deg);\n\
    }\n\ntemplate <class mint> FormalPowerSeries<mint> FormalPowerSeries<mint>::exp(int\
    \ deg) const {\n    assert(this->empty() || (*this)[0] == mint(0));\n    if (deg\
    \ == -1) deg = (int)this->size();\n    FormalPowerSeries<mint> inv;\n    inv.reserve(deg\
    \ + 1);\n    inv.push_back(mint(0));\n    inv.push_back(mint(1));\n\n    FormalPowerSeries<mint>\
    \ b{1, 1 < (int)this->size() ? (*this)[1] : mint(0)};\n    FormalPowerSeries<mint>\
    \ c{1}, z1, z2{1, 1};\n    for (int m = 2; m < deg; m <<= 1) {\n        auto y\
    \ = b;\n        y.resize(m << 1);\n        y.but();\n        z1 = z2;\n      \
    \  FormalPowerSeries<mint> z(m);\n        z = y.dot(z1);\n        z.ibut();\n\
    \        std::fill(std::begin(z), std::begin(z) + (m >> 1), mint(0));\n      \
    \  z.but();\n        z.inplace_dot(-z1);\n        z.ibut();\n        c.insert(std::end(c),\
    \ std::begin(z) + (m >> 1), std::end(z));\n        z2 = c;\n        z2.resize(m\
    \ << 1);\n        z2.but();\n\n        FormalPowerSeries<mint> x(this->begin(),\
    \ this->begin() + std::min<int>(this->size(), m));\n        x.resize(m);\n   \
    \     x.inplace_diff();\n        x.push_back(mint(0));\n        x.but();\n   \
    \     x.inplace_dot(y);\n        x.ibut();\n        x -= b.diff();\n        x.resize(m\
    \ << 1);\n        for (int i = 0; i < m - 1; i++) {\n            x[m + i] = x[i];\n\
    \            x[i] = mint(0);\n        }\n        x.but();\n        x.inplace_dot(z2);\n\
    \        x.ibut();\n        x.pop_back();\n        x.inplace_int();\n        for\
    \ (int i = m; i < std::min<int>(this->size(), m << 1); i++) x[i] += (*this)[i];\n\
    \        std::fill(std::begin(x), std::begin(x) + m, mint(0));\n        x.but();\n\
    \        x.inplace_dot(y);\n        x.ibut();\n        b.insert(std::end(b), std::begin(x)\
    \ + m, std::end(x));\n    }\n    return FormalPowerSeries<mint>(std::begin(b),\
    \ std::begin(b) + deg);\n}\n\n} // namespace kk2\n\n\n#line 1 \"modint/mont.hpp\"\
    \n\n\n\n#line 5 \"modint/mont.hpp\"\n#include <cstdint>\n#include <iostream>\n\
    #line 8 \"modint/mont.hpp\"\n\n#line 10 \"modint/mont.hpp\"\n\nnamespace kk2 {\n\
    \ntemplate <int p> struct LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n\
    \    using i32 = int32_t;\n    using i64 = int64_t;\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32\
    \ ret = p;\n        for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;\n        return\
    \ ret;\n    }\n\n    static constexpr u32 r = get_r();\n    static constexpr u32\
    \ n2 = -u64(p) % p;\n    static_assert(r * p == 1, \"invalid, r * p != 1\");\n\
    \    static_assert(p < (1 << 30), \"invalid, p >= 2 ^ 30\");\n    static_assert((p\
    \ & 1) == 1, \"invalid, p % 2 == 0\");\n\n    u32 _v;\n\n    operator int() const\
    \ { return val(); }\n\n    constexpr LazyMontgomeryModInt() : _v(0) {}\n\n   \
    \ template <typename T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    constexpr LazyMontgomeryModInt(T b) : _v(reduce(u64(b % p\
    \ + p) * n2)) {}\n\n    static constexpr u32 reduce(const u64 &b) { return (b\
    \ + u64(u32(b) * u32(-r)) * p) >> 32; }\n\n    constexpr mint &operator++() {\
    \ return *this += 1; }\n\n    constexpr mint &operator--() { return *this -= 1;\
    \ }\n\n    constexpr mint operator++(int) {\n        mint ret = *this;\n     \
    \   *this += 1;\n        return ret;\n    }\n\n    constexpr mint operator--(int)\
    \ {\n        mint ret = *this;\n        *this -= 1;\n        return ret;\n   \
    \ }\n\n    constexpr mint &operator+=(const mint &b) {\n        if (i32(_v +=\
    \ b._v - 2 * p) < 0) _v += 2 * p;\n        return *this;\n    }\n\n    constexpr\
    \ mint &operator-=(const mint &b) {\n        if (i32(_v -= b._v) < 0) _v += 2\
    \ * p;\n        return *this;\n    }\n\n    constexpr mint &operator*=(const mint\
    \ &b) {\n        _v = reduce(u64(_v) * b._v);\n        return *this;\n    }\n\n\
    \    constexpr mint &operator/=(const mint &b) {\n        *this *= b.inv();\n\
    \        return *this;\n    }\n\n    constexpr mint operator-() const { return\
    \ mint() - mint(*this); }\n\n    constexpr bool operator==(const mint &b) const\
    \ {\n        return (_v >= p ? _v - p : _v) == (b._v >= p ? b._v - p : b._v);\n\
    \    }\n\n    constexpr bool operator!=(const mint &b) const {\n        return\
    \ (_v >= p ? _v - p : _v) != (b._v >= p ? b._v - p : b._v);\n    }\n\n    friend\
    \ constexpr mint operator+(const mint &a, const mint &b) { return mint(a) += b;\
    \ }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator+(const mint &a, T b) {\n  \
    \      return mint(a) += mint(b);\n    }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator+(T a, const mint &b) {\n  \
    \      return mint(a) += b;\n    }\n\n    friend constexpr mint operator-(const\
    \ mint &a, const mint &b) { return mint(a) -= b; }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator-(const mint &a, T b) {\n  \
    \      return mint(a) -= mint(b);\n    }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator-(T a, const mint &b) {\n  \
    \      return mint(a) -= b;\n    }\n\n    friend constexpr mint operator*(const\
    \ mint &a, const mint &b) { return mint(a) *= b; }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator*(const mint &a, T b) {\n  \
    \      return mint(a) *= mint(b);\n    }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator*(T a, const mint &b) {\n  \
    \      return mint(a) *= b;\n    }\n\n    friend constexpr mint operator/(const\
    \ mint &a, const mint &b) { return mint(a) /= b; }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator/(const mint &a, T b) {\n  \
    \      return mint(a) /= mint(b);\n    }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator/(T a, const mint &b) {\n  \
    \      return mint(a) /= b;\n    }\n\n    template <class T> constexpr mint pow(T\
    \ n) const {\n        mint ret(1), mul(*this);\n        while (n > 0) {\n    \
    \        if (n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n\n    constexpr mint inv() const { return\
    \ pow(p - 2); }\n\n    friend std::ostream &operator<<(std::ostream &os, const\
    \ mint &x) { return os << x.val(); }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &x) {\n        i64 t;\n        is >> t;\n        x = mint(t);\n  \
    \      return (is);\n    }\n\n    constexpr u32 val() const {\n        u32 ret\
    \ = reduce(_v);\n        return ret >= p ? ret - p : ret;\n    }\n\n    static\
    \ constexpr u32 getmod() { return p; }\n};\n\ntemplate <int p> using Mont = LazyMontgomeryModInt<p>;\n\
    \n\nusing mont998 = Mont<998244353>;\nusing mont107 = Mont<1000000007>;\n\n} //\
    \ namespace kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#pragma GCC optimize(\"\
    O3,unroll-loops\")\n\n// #include <bits/stdc++.h>\n#line 8 \"template/template.hpp\"\
    \n#include <array>\n#include <bitset>\n#line 11 \"template/template.hpp\"\n#include\
    \ <chrono>\n#include <cmath>\n#include <cstring>\n#include <deque>\n#include <fstream>\n\
    #include <functional>\n#include <iomanip>\n#line 19 \"template/template.hpp\"\n\
    #include <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <optional>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#line 32 \"template/template.hpp\"\
    \n#include <unordered_map>\n#include <unordered_set>\n#line 36 \"template/template.hpp\"\
    \n\nusing u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi = std::pair<int,\
    \ int>;\nusing pl = std::pair<i64, i64>;\nusing pil = std::pair<int, i64>;\nusing\
    \ pli = std::pair<i64, int>;\n\ntemplate <class T> constexpr T infty = 0;\ntemplate\
    \ <> constexpr int infty<int> = (1 << 30) - 123;\ntemplate <> constexpr i64 infty<i64>\
    \ = (1ll << 62) - (1ll << 31);\ntemplate <> constexpr i128 infty<i128> = i128(infty<i64>)\
    \ * infty<i64>;\ntemplate <> constexpr u32 infty<u32> = infty<int>;\ntemplate\
    \ <> constexpr u64 infty<u64> = infty<i64>;\ntemplate <> constexpr double infty<double>\
    \ = infty<i64>;\ntemplate <> constexpr long double infty<long double> = infty<i64>;\n\
    \nconstexpr int mod = 998244353;\nconstexpr int modu = 1e9 + 7;\nconstexpr long\
    \ double PI = 3.14159265358979323846;\n\ntemplate <class T> using vc = std::vector<T>;\n\
    template <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using vvvc\
    \ = std::vector<vvc<T>>;\ntemplate <class T> using vvvvc = std::vector<vvvc<T>>;\n\
    \ntemplate <class T> using pq = std::priority_queue<T>;\ntemplate <class T> using\
    \ pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\nnamespace\
    \ kk2 {\n\ntemplate <class T, class... Sizes> auto make_vector(const T &init,\
    \ int first, Sizes... sizes) {\n    if constexpr (sizeof...(sizes) == 0) {\n \
    \       return std::vector<T>(first, init);\n    } else {\n        return std::vector<decltype(make_vector(init,\
    \ sizes...))>(first,\n                                                       \
    \           make_vector(init, sizes...));\n    }\n}\n\ntemplate <class T, class\
    \ U> void fill_all(std::vector<T> &v, const U &x) {\n    std::fill(std::begin(v),\
    \ std::end(v), T(x));\n}\n\ntemplate <class T, class U> void fill_all(std::vector<std::vector<T>>\
    \ &v, const U &x) {\n    for (auto &u : v) fill_all(u, x);\n}\n\n} // namespace\
    \ kk2\n\ntemplate <class T, class S> inline bool chmax(T &a, const S &b) {\n \
    \   return (a < b ? a = b, 1 : 0);\n}\n\ntemplate <class T, class S> inline bool\
    \ chmin(T &a, const S &b) {\n    return (a > b ? a = b, 1 : 0);\n}\n\n#define\
    \ rep1(a) for (i64 _ = 0; _ < (i64)(a); ++_)\n#define rep2(i, a) for (i64 i =\
    \ 0; i < (i64)(a); ++i)\n#define rep3(i, a, b) for (i64 i = (a); i < (i64)(b);\
    \ ++i)\n#define repi2(i, a) for (i64 i = (a) - 1; i >= 0; --i)\n#define repi3(i,\
    \ a, b) for (i64 i = (a) - 1; i >= (i64)(b); --i)\n#define overload3(a, b, c,\
    \ d, ...) d\n#define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n\
    #define repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n\
    #define fi first\n#define se second\n#define all(p) std::begin(p), std::end(p)\n\
    \nstruct IoSetUp {\n    IoSetUp() {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \    }\n} iosetup;\n\n#ifdef KK2\nstd::ifstream in(\"in.txt\");\nstd::ofstream\
    \ out(\"out.txt\");\n#else\n#define in std::cin\n#define out std::cout\n#endif\n\
    \nvoid YES(bool b = 1) {\n    std::cout << (b ? \"YES\" : \"NO\") << '\\n';\n\
    }\n\nvoid NO(bool b = 1) {\n    std::cout << (b ? \"NO\" : \"YES\") << '\\n';\n\
    }\n\nvoid Yes(bool b = 1) {\n    std::cout << (b ? \"Yes\" : \"No\") << '\\n';\n\
    }\n\nvoid No(bool b = 1) {\n    std::cout << (b ? \"No\" : \"Yes\") << '\\n';\n\
    }\n\nvoid yes(bool b = 1) {\n    std::cout << (b ? \"yes\" : \"no\") << '\\n';\n\
    }\n\nvoid no(bool b = 1) {\n    std::cout << (b ? \"no\" : \"yes\") << '\\n';\n\
    }\n\n\n#line 6 \"verify/yosupo_fps/fps_pow.test.cpp\"\nusing namespace std;\n\n\
    using FPS = kk2::FormalPowerSeries<kk2::mont998>;\n\nint main() {\n    int n;\n\
    \    i64 m;\n    cin >> n >> m;\n    FPS f(n);\n    rep (i, n) cin >> f[i];\n\
    \    auto g = f.pow(m);\n    rep (i, g.size()) cout << g[i] << \" \\n\"[i == n\
    \ - 1];\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \n\n#include \"../../fps/ntt_friendly.hpp\"\n#include \"../../modint/mont.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nusing FPS\
    \ = kk2::FormalPowerSeries<kk2::mont998>;\n\nint main() {\n    int n;\n    i64\
    \ m;\n    cin >> n >> m;\n    FPS f(n);\n    rep (i, n) cin >> f[i];\n    auto\
    \ g = f.pow(m);\n    rep (i, g.size()) cout << g[i] << \" \\n\"[i == n - 1];\n\
    \n    return 0;\n}"
  dependsOn:
  - fps/ntt_friendly.hpp
  - convolution/convolution.hpp
  - convolution/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - type_traits/type_traits.hpp
  - fps/fps.hpp
  - modint/mont.hpp
  - type_traits/type_traits.hpp
  - template/template.hpp
  isVerificationFile: true
  path: verify/yosupo_fps/fps_pow.test.cpp
  requiredBy: []
  timestamp: '2024-10-06 17:19:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_fps/fps_pow.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_fps/fps_pow.test.cpp
- /verify/verify/yosupo_fps/fps_pow.test.cpp.html
title: verify/yosupo_fps/fps_pow.test.cpp
---
