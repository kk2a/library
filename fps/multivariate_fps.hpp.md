---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/butterfly.hpp
    title: convolution/butterfly.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/multi_convolution_truncated.hpp
    title: convolution/multi_convolution_truncated.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps.hpp
    title: fps/fps.hpp
  - icon: ':heavy_check_mark:'
    path: fps/ntt_friendly.hpp
    title: fps/ntt_friendly.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/primitive_root.hpp
    title: math_mod/primitive_root.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp
  bundledCode: "#line 1 \"fps/multivariate_fps.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <iostream>\n#include <vector>\n\n#line 1 \"convolution/multi_convolution_truncated.hpp\"\
    \n\n\n\n#line 5 \"convolution/multi_convolution_truncated.hpp\"\n\n#line 1 \"\
    convolution/convolution.hpp\"\n\n\n\n#line 6 \"convolution/convolution.hpp\"\n\
    \n#line 1 \"convolution/butterfly.hpp\"\n\n\n\n#line 5 \"convolution/butterfly.hpp\"\
    \n\n#line 1 \"math_mod/primitive_root.hpp\"\n\n\n\n#line 1 \"math_mod/pow_mod.hpp\"\
    \n\n\n\n#line 5 \"math_mod/pow_mod.hpp\"\n\n#line 1 \"type_traits/type_traits.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace kk2 {\n\ntemplate <typename T>\nusing\
    \ is_signed_int128 = typename std::conditional<std::is_same<T, __int128_t>::value\n\
    \                                                       or std::is_same<T, __int128>::value,\n\
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
    \ kk2\n\n\n#line 7 \"convolution/multi_convolution_truncated.hpp\"\n\nnamespace\
    \ kk2 {\n\n// reference: https://rushcheyo.blog.uoj.ac/blog/6547\n// \u65E5\u672C\
    \u8A9E:\n// https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp\n\
    template <class FPS, class mint = typename FPS::value_type>\nFPS multi_convolution_truncated(FPS\
    \ &a, const FPS &b, const std::vector<int> &base) {\n    int n = int(a.size());\n\
    \    if (!n) return {};\n    int k = base.size();\n    if (!k) return convolution(a,\
    \ b);\n    // chi[i] = \\sum_{j} \\floor(i / (base[0]...base[j]))\n    std::vector<int>\
    \ chi(n, 0);\n    for (int i = 0; i < n; i++) {\n        int x = i;\n        for\
    \ (int j = 0; j < k - 1; j++) chi[i] += (x /= base[j]);\n        chi[i] %= k;\n\
    \    }\n    int z = 1;\n    while (z < 2 * n - 1) z <<= 1;\n    std::vector<FPS>\
    \ f(k, FPS(z));\n    std::vector<FPS> g(k, FPS(z));\n    for (int i = 0; i < n;\
    \ i++) f[chi[i]][i] = a[i], g[chi[i]][i] = b[i];\n    for (auto &x : f) butterfly(x);\n\
    \    for (auto &x : g) butterfly(x);\n    std::vector<mint> tmp(k);\n    for (int\
    \ ii = 0; ii < z; ii++) {\n        for (int i = 0; i < k; i++) {\n           \
    \ for (int j = 0; j < k; j++) {\n                tmp[i + j - (i + j >= k ? k :\
    \ 0)] += f[i][ii] * g[j][ii];\n            }\n        }\n        for (int i =\
    \ 0; i < k; i++) f[i][ii] = tmp[i], tmp[i] = mint{0};\n    }\n    for (auto &x\
    \ : f) butterfly_inv(x);\n    for (int i = 0; i < n; i++) a[i] = f[chi[i]][i];\n\
    \    return a;\n}\n\n} // namespace kk2\n\n\n#line 1 \"fps/ntt_friendly.hpp\"\n\
    \n\n\n#line 1 \"fps/fps.hpp\"\n\n\n\n#line 7 \"fps/fps.hpp\"\n#include <utility>\n\
    #line 9 \"fps/fps.hpp\"\n\nnamespace kk2 {\n\ntemplate <class mint> struct FormalPowerSeries\
    \ : std::vector<mint> {\n    using std::vector<mint>::vector;\n    using FPS =\
    \ FormalPowerSeries;\n\n    void display() const {\n        for (int i = 0; i\
    \ < (int)this->size(); i++) {\n            std::cout << (*this)[i] << \" \\n\"\
    [i == (int)this->size() - 1];\n        }\n    }\n\n    void output(std::ostream\
    \ &os) const {\n        for (int i = 0; i < (int)this->size(); i++) {\n      \
    \      os << (*this)[i] << (i + 1 == (int)this->size() ? \"\" : \" \");\n    \
    \    }\n    }\n\n    friend std::ostream &operator<<(std::ostream &os, const FPS\
    \ &fps_) {\n        for (int i = 0; i < (int)fps_.size(); i++) {\n           \
    \ os << fps_[i] << (i + 1 == (int)fps_.size() ? \"\" : \" \");\n        }\n  \
    \      return os;\n    }\n\n    FPS &input(std::istream &is) {\n        for (int\
    \ i = 0; i < (int)this->size(); i++) is >> (*this)[i];\n        return *this;\n\
    \    }\n\n    friend std::istream &operator>>(std::istream &is, FPS &fps_) {\n\
    \        for (auto &x : fps_) is >> x;\n        return is;\n    }\n\n    FPS &operator+=(const\
    \ FPS &r) {\n        if (this->size() < r.size()) this->resize(r.size());\n  \
    \      for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n        return\
    \ *this;\n    }\n\n    FPS &operator+=(const mint &r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] += r;\n        return *this;\n    }\n\n\
    \    FPS &operator-=(const FPS &r) {\n        if (this->size() < r.size()) this->resize(r.size());\n\
    \        for (int i = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n       \
    \ return *this;\n    }\n\n    FPS &operator-=(const mint &r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] -= r;\n        return *this;\n    }\n\n\
    \    FPS &operator*=(const mint &r) {\n        for (int i = 0; i < (int)this->size();\
    \ i++) { (*this)[i] *= r; }\n        return *this;\n    }\n\n    FPS &operator/=(const\
    \ FPS &r) {\n        assert(!r.empty());\n        if (this->size() < r.size())\
    \ {\n            this->clear();\n            return *this;\n        }\n      \
    \  int n = this->size() - r.size() + 1;\n        if ((int)r.size() <= 64) {\n\
    \            FPS f(*this), g(r);\n            g.shrink();\n            mint coeff\
    \ = g.back().inv();\n            for (auto &x : g) x *= coeff;\n            int\
    \ deg = (int)f.size() - (int)g.size() + 1;\n            int gs = g.size();\n \
    \           FPS quo(deg);\n            for (int i = deg - 1; i >= 0; i--) {\n\
    \                quo[i] = f[i + gs - 1];\n                for (int j = 0; j <\
    \ gs; j++) f[i + j] -= quo[i] * g[j];\n            }\n            *this = quo\
    \ * coeff;\n            this->resize(n, mint(0));\n            return *this;\n\
    \        }\n        return *this = ((*this).rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n\
    \    }\n\n    FPS &operator%=(const FPS &r) {\n        *this -= *this / r * r;\n\
    \        shrink();\n        return *this;\n    }\n\n    FPS operator+(const FPS\
    \ &r) const { return FPS(*this) += r; }\n\n    FPS operator+(const mint &r) const\
    \ { return FPS(*this) += r; }\n\n    FPS operator-(const FPS &r) const { return\
    \ FPS(*this) -= r; }\n\n    FPS operator-(const mint &r) const { return FPS(*this)\
    \ -= r; }\n\n    FPS operator*(const mint &r) const { return FPS(*this) *= r;\
    \ }\n\n    FPS operator/(const FPS &r) const { return FPS(*this) /= r; }\n\n \
    \   FPS operator%(const FPS &r) const { return FPS(*this) %= r; }\n\n    FPS operator-()\
    \ const {\n        FPS ret(this->size());\n        for (int i = 0; i < (int)this->size();\
    \ i++) ret[i] = -(*this)[i];\n        return ret;\n    }\n\n    FPS shrink() {\n\
    \        while (this->size() && this->back() == mint(0)) this->pop_back();\n \
    \       return *this;\n    }\n\n    FPS rev() const {\n        FPS ret(*this);\n\
    \        std::reverse(ret.begin(), ret.end());\n        return ret;\n    }\n\n\
    \    FPS inplace_rev() {\n        std::reverse(this->begin(), this->end());\n\
    \        return *this;\n    }\n\n    FPS dot(const FPS &r) const {\n        FPS\
    \ ret(std::min(this->size(), r.size()));\n        for (int i = 0; i < (int)ret.size();\
    \ i++) ret[i] = (*this)[i] * r[i];\n        return ret;\n    }\n\n    FPS inplace_dot(const\
    \ FPS &r) {\n        this->resize(std::min(this->size(), r.size()));\n       \
    \ for (int i = 0; i < (int)this->size(); i++) (*this)[i] *= r[i];\n        return\
    \ *this;\n    }\n\n    FPS pre(int n) const {\n        FPS ret(this->begin(),\
    \ this->begin() + std::min((int)this->size(), n));\n        if ((int)ret.size()\
    \ < n) ret.resize(n, mint(0));\n        return ret;\n    }\n\n    FPS inplace_pre(int\
    \ n) {\n        this->resize(n);\n        return *this;\n    }\n\n    FPS operator>>(int\
    \ n) const {\n        if (n >= (int)this->size()) return {};\n        FPS ret(this->begin()\
    \ + n, this->end());\n        return ret;\n    }\n\n    FPS operator<<(int n)\
    \ const {\n        FPS ret(*this);\n        ret.insert(ret.begin(), n, mint(0));\n\
    \        return ret;\n    }\n\n    FPS diff() const {\n        const int n = (int)this->size();\n\
    \        FPS ret(std::max(0, n - 1));\n        for (int i = 1; i < n; i++) { ret[i\
    \ - 1] = (*this)[i] * mint(i); }\n        return ret;\n    }\n\n    FPS inplace_diff()\
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
    \ std::begin(b) + deg);\n}\n\n} // namespace kk2\n\n\n#line 11 \"fps/multivariate_fps.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename mint> struct MultivariateFormalPowerSeries\
    \ {\n    using mfps = MultivariateFormalPowerSeries;\n    using fps = FormalPowerSeries<mint>;\n\
    \    using value_type = mint;\n\n    std::vector<int> base;\n    fps f;\n\n  \
    \  MultivariateFormalPowerSeries() = default;\n\n    MultivariateFormalPowerSeries(const\
    \ std::vector<int> &base_) : base(base_) {\n        int n = 1;\n        for (int\
    \ x : base) n *= x;\n        f.resize(n);\n    }\n\n    MultivariateFormalPowerSeries(const\
    \ std::vector<int> &base_, const fps &f_)\n        : base(base_),\n          f(f_)\
    \ {}\n\n    friend std::ostream &operator<<(std::ostream &os, const MFPS &mfps_)\
    \ {\n        for (int i = 0; i < (int)mfps_.f.size(); i++) os << mfps_.f[i] <<\
    \ (i + 1 == (int)mfps_.f.size() ? \"\" : \" \");\n        return os;\n    }\n\n\
    \    void output(std::ostream &os) const {\n        for (int i = 0; i < (int)f.size();\
    \ i++) os << f[i] << (i + 1 == (int)f.size() ? \"\\n\" : \" \");\n    }\n\n  \
    \  MFPS &input(std::istream &is) {\n        for (auto &x : f) is >> x;\n     \
    \   return *this;\n    }\n\n    friend std::istream &operator>>(std::istream &is,\
    \ MFPS &mfps_) {\n        for (auto &x : mfps_.f) is >> x;\n        return is;\n\
    \    }\n\n    template <typename T, typename... Ts> int _id(int x, T y, Ts...\
    \ ys) {\n        assert(x < (int)base.size() && (int)y < base[x]);\n        if\
    \ constexpr (sizeof...(Ts) == 0) return y;\n        else return y + base[x] *\
    \ _id(x + 1, ys...);\n    }\n\n    template <typename... Args> int id(Args...\
    \ args) {\n        static_assert(sizeof...(Args) > 0);\n        return _id(0,\
    \ args...);\n    }\n\n    template <typename... Args> mint &operator()(Args...\
    \ args) { return f[id(args...)]; }\n\n    mint &operator[](int i) { return f[i];\
    \ }\n\n    void display() const {\n        for (int i = 0; i < (int)f.size();\
    \ i++) {\n            int x = i;\n            std::cout << \"f(\";\n         \
    \   for (int j = 0; j < (int)base.size(); j++) {\n                std::cout <<\
    \ x % base[j] << (j + 1 == (int)base.size() ? \") = \" : \", \");\n          \
    \      x /= base[j];\n            }\n            std::cout << f[i] << \"\\n\"\
    ;\n        }\n    }\n\n    mfps &operator+=(const mfps &rhs) {\n        assert(base\
    \ == rhs.base && f.size() == rhs.f.size());\n        for (int i = 0; i < (int)f.size();\
    \ i++) f[i] += rhs.f[i];\n        return *this;\n    }\n\n    mfps &operator-=(const\
    \ mfps &rhs) {\n        assert(base == rhs.base && f.size() == rhs.f.size());\n\
    \        for (int i = 0; i < (int)f.size(); i++) f[i] -= rhs.f[i];\n        return\
    \ *this;\n    }\n\n    mfps &operator*=(const mfps &rhs) {\n        assert(base\
    \ == rhs.base && f.size() == rhs.f.size());\n        multi_convolution_truncated(f,\
    \ rhs.f, base);\n        return *this;\n    }\n\n    mfps &operator+=(const mint\
    \ &rhs) {\n        assert(!f.empty());\n        f[0] += rhs;\n        return *this;\n\
    \    }\n\n    mfps &operator-=(const mint &rhs) {\n        assert(!f.empty());\n\
    \        f[0] -= rhs;\n        return *this;\n    }\n\n    mfps &operator*=(const\
    \ mint &rhs) {\n        for (auto &x : f) x *= rhs;\n        return *this;\n \
    \   }\n\n    mfps &operator/=(const mint &rhs) {\n        for (auto &x : f) x\
    \ /= rhs;\n        return *this;\n    }\n\n    mfps operator+(const mfps &rhs)\
    \ const { return mfps(*this) += rhs; }\n\n    mfps operator-(const mfps &rhs)\
    \ const { return mfps(*this) -= rhs; }\n\n    mfps operator*(const mfps &rhs)\
    \ const { return mfps(*this) *= rhs; }\n\n    mfps operator+(const mint &rhs)\
    \ const { return mfps(*this) += rhs; }\n\n    mfps operator-(const mint &rhs)\
    \ const { return mfps(*this) -= rhs; }\n\n    mfps operator*(const mint &rhs)\
    \ const { return mfps(*this) *= rhs; }\n\n    mfps operator/(const mint &rhs)\
    \ const { return mfps(*this) /= rhs; }\n\n    mfps operator+() const { return\
    \ mfps(*this); }\n\n    mfps operator-() const { return mfps(base, -f); }\n\n\
    \    friend bool operator==(const mfps &lhs, const mfps &rhs) {\n        return\
    \ lhs.f == rhs.f && lhs.base == rhs.base;\n    }\n\n    friend bool operator!=(const\
    \ mfps &lhs, const mfps &rhs) { return !(lhs == rhs); }\n\n    mfps diff() const\
    \ {\n        mfps ret(*this);\n        for (int i = 0; i < (int)ret.f.size();\
    \ i++) ret.f[i] *= i;\n        return ret;\n    }\n\n    mfps &inplace_diff()\
    \ {\n        for (int i = 0; i < (int)f.size(); i++) f[i] *= i;\n        return\
    \ *this;\n    }\n\n    static std::vector<mint> _inv;\n\n    static void ensure_inv(int\
    \ n) {\n        while ((int)_inv.size() <= n) {\n            int i = _inv.size();\n\
    \            _inv.push_back((-_inv[mint::getmod() % i]) * (mint::getmod() / i));\n\
    \        }\n    }\n\n    mfps integral() const {\n        ensure_inv(f.size());\n\
    \        mfps ret(*this);\n        for (int i = 1; i < (int)ret.f.size(); i++)\
    \ ret.f[i] *= _inv[i];\n        return ret;\n    }\n\n    mfps &inplace_int()\
    \ {\n        ensure_inv(f.size());\n        for (int i = 1; i < (int)f.size();\
    \ i++) f[i] *= _inv[i];\n        return *this;\n    }\n\n    mfps inv() const\
    \ {\n        assert(!f.empty() && f[0] != mint(0));\n        if (base.empty())\
    \ return mfps(base, fps{f[0].inv()});\n\n        int n = f.size(), k = base.size();\n\
    \        int z = 1;\n        while (z < 2 * n - 1) z <<= 1;\n        std::vector<int>\
    \ chi(z);\n        for (int i = 0; i < n; i++) {\n            int x = i;\n   \
    \         for (int j = 0; j < k - 1; j++) chi[i] += (x /= base[j]);\n        \
    \    chi[i] %= k;\n        }\n        auto naive_and_dot = [&k](const std::vector<fps>\
    \ &a,\n                                  const std::vector<fps> &b,\n        \
    \                          std::vector<fps> &c) -> void {\n            std::vector<mint>\
    \ tmp(k);\n            for (int ii = 0; ii < (int)a[0].size(); ii++) {\n     \
    \           for (int i = 0; i < k; i++) {\n                    for (int j = 0;\
    \ j < k; j++) {\n                        tmp[i + j - (i + j >= k ? k : 0)] +=\
    \ a[i][ii] * b[j][ii];\n                    }\n                }\n           \
    \     for (int i = 0; i < k; i++) c[i][ii] = tmp[i], tmp[i] = mint{0};\n     \
    \       }\n        };\n\n        // reference:\n        // https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp\n\
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
    \ = {0, 1};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef FPS_MULTIVARIATE_FPS_HPP\n#define FPS_MULTIVARIATE_FPS_HPP 1\n\n\
    #include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <vector>\n\
    \n#include \"../convolution/multi_convolution_truncated.hpp\"\n#include \"ntt_friendly.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename mint> struct MultivariateFormalPowerSeries\
    \ {\n    using mfps = MultivariateFormalPowerSeries;\n    using fps = FormalPowerSeries<mint>;\n\
    \    using value_type = mint;\n\n    std::vector<int> base;\n    fps f;\n\n  \
    \  MultivariateFormalPowerSeries() = default;\n\n    MultivariateFormalPowerSeries(const\
    \ std::vector<int> &base_) : base(base_) {\n        int n = 1;\n        for (int\
    \ x : base) n *= x;\n        f.resize(n);\n    }\n\n    MultivariateFormalPowerSeries(const\
    \ std::vector<int> &base_, const fps &f_)\n        : base(base_),\n          f(f_)\
    \ {}\n\n    friend std::ostream &operator<<(std::ostream &os, const MFPS &mfps_)\
    \ {\n        for (int i = 0; i < (int)mfps_.f.size(); i++) os << mfps_.f[i] <<\
    \ (i + 1 == (int)mfps_.f.size() ? \"\" : \" \");\n        return os;\n    }\n\n\
    \    void output(std::ostream &os) const {\n        for (int i = 0; i < (int)f.size();\
    \ i++) os << f[i] << (i + 1 == (int)f.size() ? \"\\n\" : \" \");\n    }\n\n  \
    \  MFPS &input(std::istream &is) {\n        for (auto &x : f) is >> x;\n     \
    \   return *this;\n    }\n\n    friend std::istream &operator>>(std::istream &is,\
    \ MFPS &mfps_) {\n        for (auto &x : mfps_.f) is >> x;\n        return is;\n\
    \    }\n\n    template <typename T, typename... Ts> int _id(int x, T y, Ts...\
    \ ys) {\n        assert(x < (int)base.size() && (int)y < base[x]);\n        if\
    \ constexpr (sizeof...(Ts) == 0) return y;\n        else return y + base[x] *\
    \ _id(x + 1, ys...);\n    }\n\n    template <typename... Args> int id(Args...\
    \ args) {\n        static_assert(sizeof...(Args) > 0);\n        return _id(0,\
    \ args...);\n    }\n\n    template <typename... Args> mint &operator()(Args...\
    \ args) { return f[id(args...)]; }\n\n    mint &operator[](int i) { return f[i];\
    \ }\n\n    void display() const {\n        for (int i = 0; i < (int)f.size();\
    \ i++) {\n            int x = i;\n            std::cout << \"f(\";\n         \
    \   for (int j = 0; j < (int)base.size(); j++) {\n                std::cout <<\
    \ x % base[j] << (j + 1 == (int)base.size() ? \") = \" : \", \");\n          \
    \      x /= base[j];\n            }\n            std::cout << f[i] << \"\\n\"\
    ;\n        }\n    }\n\n    mfps &operator+=(const mfps &rhs) {\n        assert(base\
    \ == rhs.base && f.size() == rhs.f.size());\n        for (int i = 0; i < (int)f.size();\
    \ i++) f[i] += rhs.f[i];\n        return *this;\n    }\n\n    mfps &operator-=(const\
    \ mfps &rhs) {\n        assert(base == rhs.base && f.size() == rhs.f.size());\n\
    \        for (int i = 0; i < (int)f.size(); i++) f[i] -= rhs.f[i];\n        return\
    \ *this;\n    }\n\n    mfps &operator*=(const mfps &rhs) {\n        assert(base\
    \ == rhs.base && f.size() == rhs.f.size());\n        multi_convolution_truncated(f,\
    \ rhs.f, base);\n        return *this;\n    }\n\n    mfps &operator+=(const mint\
    \ &rhs) {\n        assert(!f.empty());\n        f[0] += rhs;\n        return *this;\n\
    \    }\n\n    mfps &operator-=(const mint &rhs) {\n        assert(!f.empty());\n\
    \        f[0] -= rhs;\n        return *this;\n    }\n\n    mfps &operator*=(const\
    \ mint &rhs) {\n        for (auto &x : f) x *= rhs;\n        return *this;\n \
    \   }\n\n    mfps &operator/=(const mint &rhs) {\n        for (auto &x : f) x\
    \ /= rhs;\n        return *this;\n    }\n\n    mfps operator+(const mfps &rhs)\
    \ const { return mfps(*this) += rhs; }\n\n    mfps operator-(const mfps &rhs)\
    \ const { return mfps(*this) -= rhs; }\n\n    mfps operator*(const mfps &rhs)\
    \ const { return mfps(*this) *= rhs; }\n\n    mfps operator+(const mint &rhs)\
    \ const { return mfps(*this) += rhs; }\n\n    mfps operator-(const mint &rhs)\
    \ const { return mfps(*this) -= rhs; }\n\n    mfps operator*(const mint &rhs)\
    \ const { return mfps(*this) *= rhs; }\n\n    mfps operator/(const mint &rhs)\
    \ const { return mfps(*this) /= rhs; }\n\n    mfps operator+() const { return\
    \ mfps(*this); }\n\n    mfps operator-() const { return mfps(base, -f); }\n\n\
    \    friend bool operator==(const mfps &lhs, const mfps &rhs) {\n        return\
    \ lhs.f == rhs.f && lhs.base == rhs.base;\n    }\n\n    friend bool operator!=(const\
    \ mfps &lhs, const mfps &rhs) { return !(lhs == rhs); }\n\n    mfps diff() const\
    \ {\n        mfps ret(*this);\n        for (int i = 0; i < (int)ret.f.size();\
    \ i++) ret.f[i] *= i;\n        return ret;\n    }\n\n    mfps &inplace_diff()\
    \ {\n        for (int i = 0; i < (int)f.size(); i++) f[i] *= i;\n        return\
    \ *this;\n    }\n\n    static std::vector<mint> _inv;\n\n    static void ensure_inv(int\
    \ n) {\n        while ((int)_inv.size() <= n) {\n            int i = _inv.size();\n\
    \            _inv.push_back((-_inv[mint::getmod() % i]) * (mint::getmod() / i));\n\
    \        }\n    }\n\n    mfps integral() const {\n        ensure_inv(f.size());\n\
    \        mfps ret(*this);\n        for (int i = 1; i < (int)ret.f.size(); i++)\
    \ ret.f[i] *= _inv[i];\n        return ret;\n    }\n\n    mfps &inplace_int()\
    \ {\n        ensure_inv(f.size());\n        for (int i = 1; i < (int)f.size();\
    \ i++) f[i] *= _inv[i];\n        return *this;\n    }\n\n    mfps inv() const\
    \ {\n        assert(!f.empty() && f[0] != mint(0));\n        if (base.empty())\
    \ return mfps(base, fps{f[0].inv()});\n\n        int n = f.size(), k = base.size();\n\
    \        int z = 1;\n        while (z < 2 * n - 1) z <<= 1;\n        std::vector<int>\
    \ chi(z);\n        for (int i = 0; i < n; i++) {\n            int x = i;\n   \
    \         for (int j = 0; j < k - 1; j++) chi[i] += (x /= base[j]);\n        \
    \    chi[i] %= k;\n        }\n        auto naive_and_dot = [&k](const std::vector<fps>\
    \ &a,\n                                  const std::vector<fps> &b,\n        \
    \                          std::vector<fps> &c) -> void {\n            std::vector<mint>\
    \ tmp(k);\n            for (int ii = 0; ii < (int)a[0].size(); ii++) {\n     \
    \           for (int i = 0; i < k; i++) {\n                    for (int j = 0;\
    \ j < k; j++) {\n                        tmp[i + j - (i + j >= k ? k : 0)] +=\
    \ a[i][ii] * b[j][ii];\n                    }\n                }\n           \
    \     for (int i = 0; i < k; i++) c[i][ii] = tmp[i], tmp[i] = mint{0};\n     \
    \       }\n        };\n\n        // reference:\n        // https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp\n\
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
    \ = {0, 1};\n\n} // namespace kk2\n\n#endif // FPS_MULTIVARIATE_FPS_HPP\n"
  dependsOn:
  - convolution/multi_convolution_truncated.hpp
  - convolution/convolution.hpp
  - convolution/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - type_traits/type_traits.hpp
  - fps/ntt_friendly.hpp
  - convolution/convolution.hpp
  - fps/fps.hpp
  isVerificationFile: false
  path: fps/multivariate_fps.hpp
  requiredBy: []
  timestamp: '2024-10-07 04:46:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/multivariate_fps.hpp
layout: document
redirect_from:
- /library/fps/multivariate_fps.hpp
- /library/fps/multivariate_fps.hpp.html
title: fps/multivariate_fps.hpp
---
