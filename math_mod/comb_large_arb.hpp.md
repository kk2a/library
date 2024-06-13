---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/butterfly.hpp
    title: convolution/butterfly.hpp
  - icon: ':warning:'
    path: convolution/convo_arb.hpp
    title: convolution/convo_arb.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps.hpp
    title: fps/fps.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps.hpp
    title: fps/fps.hpp
  - icon: ':warning:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  - icon: ':warning:'
    path: fps/sample_point_shift.hpp
    title: fps/sample_point_shift.hpp
  - icon: ':warning:'
    path: math_mod/comb.hpp
    title: math_mod/comb.hpp
  - icon: ':warning:'
    path: math_mod/garner.hpp
    title: math_mod/garner.hpp
  - icon: ':warning:'
    path: math_mod/inv.hpp
    title: math_mod/inv.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/pow_expr.hpp
    title: math_mod/pow_expr.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/primitive_rt_expr.hpp
    title: math_mod/primitive_rt_expr.hpp
  - icon: ':heavy_check_mark:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math_mod/comb_large_arb.hpp\"\n\n\n\n#line 1 \"fps/fps_arb.hpp\"\
    \n\n\n\n#line 1 \"fps/fps.hpp\"\n\n\n\n\ntemplate <class mint>\nstruct FormalPowerSeries\
    \ : vector<mint> {\n    using vector<mint>::vector;\n    using FPS = FormalPowerSeries;\n\
    \n    FPS &operator+=(const FPS &r) {\n        if (this->size() < r.size()) this->resize(r.size());\n\
    \        for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n       \
    \ return *this;\n    }\n    FPS &operator+=(const mint &r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] += r;\n        return *this;\n    }\n \
    \   FPS &operator-=(const FPS &r) {\n        if (this->size() < r.size()) this->resize(r.size());\n\
    \        for (int i = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n       \
    \ return *this;\n    }\n    FPS &operator-=(const mint &r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] -= r;\n        return *this;\n    }\n \
    \   FPS &operator*=(const mint &r) {\n        for (int i = 0; i < (int)this->size();\
    \ i++) {\n            (*this)[i] *= r;\n        }\n        return *this;\n   \
    \ }\n    FPS &operator/=(const FPS &r) {\n        if (this->size() < r.size())\
    \ {\n            this->clear();\n            return *this;\n        }\n      \
    \  int n = this->size() - r.size() + 1;\n        if ((int)r.size() <= 64) {\n\
    \            FPS f(*this), g(r);\n            g.shrink();\n            mint coeff\
    \ = g.back().inv();\n            for (auto &x : g) x *= coeff;\n            int\
    \ deg = (int)f.size() - (int)g.size() + 1;\n            int gs = g.size();\n \
    \           FPS quo(deg);\n            for (int i = deg - 1; i >= 0; i--) {\n\
    \                quo[i] = f[i + gs - 1];\n                for (int j = 0; j <\
    \ gs; j++) f[i + j] -= quo[i] * g[j];\n            }\n            *this = quo\
    \ * coeff;\n            this->resize(n, mint(0));\n            return *this;\n\
    \        }\n        return *this = ((*this).rev().pre(n) * r.rev().inv(n)).pre(n).rev();\
    \        \n    }\n    FPS &operator%=(const FPS &r) {\n        *this -= *this\
    \ / r * r;\n        shrink();\n        return *this;\n    }\n\n    FPS operator+(const\
    \ FPS &r) const { return FPS(*this) += r; }\n    FPS operator+(const mint &r)\
    \ const { return FPS(*this) += r; }\n    FPS operator-(const FPS &r) const { return\
    \ FPS(*this) -= r; }\n    FPS operator-(const mint &r) const { return FPS(*this)\
    \ -= r; }\n    FPS operator*(const mint &r) const { return FPS(*this) *= r; }\n\
    \    FPS operator/(const FPS &r) const { return FPS(*this) /= r; }\n    FPS operator%(const\
    \ FPS &r) const { return FPS(*this) %= r; }\n    FPS operator-() const {\n   \
    \     FPS ret(this->size());\n        for (int i = 0; i < (int)this->size(); i++)\
    \ ret[i] = -(*this)[i];\n        return ret;\n    }\n\n    FPS shrink() {\n  \
    \      while (this->size() && this->back() == mint(0)) this->pop_back();\n   \
    \     return *this;\n    }\n\n    FPS rev() const {\n        FPS ret(*this);\n\
    \        reverse(ret.begin(), ret.end());\n        return ret;\n    }\n\n    FPS\
    \ inplace_rev() {\n        reverse(this->begin(), this->end());\n        return\
    \ *this;\n    }\n\n    FPS dot(const FPS &r) const {\n        FPS ret(min(this->size(),\
    \ r.size()));\n        for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\n        return ret;\n    }\n\n    FPS inplace_dot(const FPS &r) {\n\
    \        this->resize(min(this->size(), r.size()));\n        for (int i = 0; i\
    \ < (int)this->size(); i++) (*this)[i] *= r[i];\n        return *this;\n    }\n\
    \n    FPS pre(int n) const {\n        FPS ret(begin(*this), begin(*this) + min((int)this->size(),\
    \ n));\n        if ((int)ret.size() < n) ret.resize(n, mint(0));\n        return\
    \ ret;\n    }\n\n    FPS inplace_pre(int n) {\n        this->resize(n);\n    \
    \    return *this;\n    }\n\n    FPS operator>>(int n) const {\n        if (n\
    \ >= (int)this->size()) return {};\n        FPS ret(begin(*this) + n, end(*this));\n\
    \        return ret;\n    }\n    FPS operator<<(int n) const {\n        FPS ret(*this);\n\
    \        ret.insert(begin(ret), n, mint(0));\n        return ret;\n    }\n\n \
    \   FPS diff() const {\n        const int n = (int)this->size();\n        FPS\
    \ ret(max(0, n - 1));\n        for (int i = 1; i < n; i++) {\n            ret[i\
    \ - 1] = (*this)[i] * mint(i);\n        }\n        return ret;\n    }\n\n    FPS\
    \ inplace_diff() {\n        if (this->empty()) return {};\n        this->erase(this->begin());\n\
    \        for (int i = 1; i <= (int)this->size(); i++)\n            (*this)[i -\
    \ 1] *= mint(i);\n        return *this;\n    }\n\n    FPS integral() const {\n\
    \        const int n = (int)this->size();\n        FPS ret(n + 1);\n        ret[0]\
    \ = mint(0);\n        if (n > 0) ret[1] = mint(1);\n        auto mod = mint::getmod();\n\
    \        for (int i = 2; i <= n; i++) {\n            // p = q * i + r\n      \
    \      // - q / r = 1 / i (mod p)\n            ret[i] = (-ret[mod % i]) * (mod\
    \ / i);\n        }\n        for (int i = 0; i < n; i++) {\n            ret[i +\
    \ 1] *= (*this)[i];\n        }\n        return ret;\n    }\n\n    FPS inplace_int()\
    \ {\n        static vector<mint> inv{0, 1};\n        const int n = this->size();\n\
    \        auto mod = mint::getmod();\n        while ((int)inv.size() <= n) {\n\
    \            // p = q * i + r\n            // - q / r = 1 / i (mod p)\n      \
    \      int i = inv.size();\n            inv.push_back((-inv[mod % i]) * (mod /\
    \ i));\n        }\n        this->insert(this->begin(), mint(0));\n        for\
    \ (int i = 1; i <= n; i++) (*this)[i] *= inv[i];\n        return *this;\n    }\n\
    \n    mint eval(mint x) const {\n        mint r = 0, w = 1;\n        for (auto\
    \ &v : *this) {\n            r += w * v;\n            w *= x;\n        }\n   \
    \     return r;\n    }\n\n    FPS log(int deg = -1) const {\n        assert(!this->empty()\
    \ && (*this)[0] == mint(1));\n        if (deg == -1) deg = this->size();\n   \
    \     return (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n    }\n\
    \n    FPS sparse_log(int deg = -1) const {\n        assert(!this->empty() && (*this)[0]\
    \ == mint(1));\n        if (deg == -1) deg = this->size();\n        vector<pair<int,\
    \ mint>> fs;\n        for (int i = 1; i < int(this->size()); i++) {\n        \
    \    if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i]);\n        }\n\n\
    \        int mod = mint::getmod();\n        static vector<mint> inv{1, 1};\n \
    \       while ((int)inv.size() <= deg) {\n            int i = inv.size();\n  \
    \          inv.push_back(-inv[mod % i] * (mod / i));\n        }\n\n        FPS\
    \ g(deg);\n        for (int k = 0; k < deg - 1; k++) {\n            for (auto\
    \ &[j, fj] : fs) {\n                if (k < j) break;\n                int i =\
    \ k - j;\n                g[k + 1] -= g[i + 1] * fj * (i + 1);\n            }\n\
    \            g[k + 1] *= inv[k + 1];\n            if (k + 1 < int(this->size()))\
    \ g[k + 1] += (*this)[k + 1];\n        }\n\n        return g;\n    }\n\n    template\
    \ <class T>\n    FPS pow(T k, int deg = -1) const {\n        const int n = this->size();\n\
    \        if (deg == -1) deg = n;\n        if (k == 0) {\n            FPS ret(deg);\n\
    \            if (deg > 0) ret[0] = mint(1);\n            return ret;\n       \
    \ }\n        for (int i = 0; i < n; i++) {\n            if ((*this)[i] != mint(0))\
    \ {\n                mint rev = mint(1) / (*this)[i];\n                FPS ret\
    \ = (((*this * rev) >> i).log(deg) * k).exp(deg);\n                ret *= (*this)[i].pow(k);\n\
    \                ret = (ret << (i * k)).pre(deg);\n                if ((int)ret.size()\
    \ < deg) ret.resize(deg, mint(0));\n                return ret;\n            }\n\
    \            if (__int128_t(i + 1) * k >= deg) return FPS(deg, mint(0));\n   \
    \     }\n        return FPS(deg, mint(0));\n    }\n\n    template <class T>\n\
    \    FPS sparse_pow(T k, int deg = -1) const {\n        if (deg == -1) deg = this->size();\n\
    \        if (k == 0) {\n            FPS ret(deg);\n            if (deg > 0) ret[0]\
    \ = mint(1);\n            return ret;\n        }\n\n        int zero = 0;\n  \
    \      while (zero != int(this->size()) &&\n               (*this)[zero] == mint(0))\
    \ zero++;\n        if (zero == int(this->size()) ||\n            __int128_t(zero)\
    \ * k >= deg) {\n            return FPS(deg, mint(0));\n        }\n        if\
    \ (zero != 0) {\n            FPS suf(this->begin() + zero, this->end());\n   \
    \         auto g = suf.sparse_pow(k, deg - zero * k);\n            FPS ret(zero\
    \ * k, mint(0));\n            copy(begin(g), end(g), back_inserter(ret));\n  \
    \          return ret;\n        }\n\n        int mod = mint::getmod();\n     \
    \   static vector<mint> inv{1, 1};\n        while ((int)inv.size() <= deg) {\n\
    \            int i = inv.size();\n            inv.push_back(-inv[mod % i] * (mod\
    \ / i));\n        }\n\n        vector<pair<int, mint>> fs;\n        for (int i\
    \ = 1; i < int(this->size()); i++) {\n            if ((*this)[i] != mint(0)) fs.emplace_back(i,\
    \ (*this)[i]);\n        }\n\n        FPS g(deg);\n        g[0] = (*this)[0].pow(k);\n\
    \        mint denom = (*this)[0].inv();\n        k %= mod;\n        for (int a\
    \ = 1; a < deg; a++) {\n            for (auto& [i, f_i] : fs) {\n            \
    \    if (a < i) break;\n                g[a] += g[a - i] * f_i * (mint(i) * (k\
    \ + 1) - a);\n            }\n            g[a] *= denom * inv[a];\n        }\n\
    \        return g;\n    }\n\n    // assume that r is sparse\n    // return this\
    \ / r\n    FPS sparse_div(const FPS &r, int deg = -1) const {\n        assert(!r.empty()\
    \ && r[0] != mint(0));\n        if (deg == -1) deg = this->size();\n        mint\
    \ ir0 = r[0].inv();\n        FPS ret = *this * ir0;\n        ret.resize(deg);\n\
    \        vector<pair<int, mint>> gs;\n        for (int i = 1; i < (int)r.size();\
    \ i++) {\n            if (r[i] != mint(0)) gs.emplace_back(i, r[i] * ir0);\n \
    \       }\n        for (int i = 0; i < deg; i++) {\n            for (auto &[j,\
    \ g_j] : gs) {\n                if (i + j >= deg) break;\n                ret[i\
    \ + j] -= ret[i] * g_j;\n            }\n        }\n        return ret;\n    }\n\
    \n    FPS sparse_inv(int deg = -1) const {\n        assert(!this->empty() && (*this)[0]\
    \ != mint(0));\n        if (deg == -1) deg = this->size();\n        vector<pair<int,\
    \ mint>> fs;\n        for (int i = 1; i < int(this->size()); i++) {\n        \
    \    if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i]);\n        }\n \
    \       FPS ret(deg);\n        mint if0 = (*this)[0].inv();\n        if (0 < deg)\
    \ ret[0] = if0;\n        for (int k = 1; k < deg; k++) {\n            for (auto\
    \ &[j, fj] : fs) {\n                if (k < j) break;\n                ret[k]\
    \ += ret[k - j] * fj;\n            }\n            ret[k] *= -if0;\n        }\n\
    \        return ret;\n    }\n\n    FPS sparse_exp(int deg = -1) const {\n    \
    \    assert(this->empty() || (*this)[0] == mint(0));\n        if (deg == -1) deg\
    \ = this->size();\n        vector<pair<int, mint>> fs;\n        for (int i = 1;\
    \ i < int(this->size()); i++) {\n            if ((*this)[i] != mint(0)) fs.emplace_back(i,\
    \ (*this)[i]);\n        }\n\n        int mod = mint::getmod();\n        static\
    \ vector<mint> inv{1, 1};\n        while ((int)inv.size() <= deg) {\n        \
    \    int i = inv.size();\n            inv.push_back(-inv[mod % i] * (mod / i));\n\
    \        }\n\n        FPS g(deg);\n        if (deg) g[0] = 1;\n        for (int\
    \ k = 0; k < deg - 1; k++) {\n            for (auto &[ip1, fip1] : fs) {\n   \
    \             int i = ip1 - 1;\n                if (k < i) break;\n          \
    \      g[k + 1] += g[k - i] * fip1 * (i + 1);\n            }\n            g[k\
    \ + 1] *= inv[k + 1];\n        }\n\n        return g;\n    }\n\n    FPS &operator*=(const\
    \ FPS &r);\n    FPS operator*(const FPS &r) const { return FPS(*this) *= r; }\n\
    \    void but();\n    void ibut();\n    void db();\n    static int but_pr();\n\
    \    FPS inv(int deg = -1) const;\n    FPS exp(int deg = -1) const;\n};\n\n\n\
    #line 1 \"convolution/convo_arb.hpp\"\n\n\n\n#line 1 \"modint/mont.hpp\"\n\n\n\
    \ntemplate <int p>\nstruct LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n\
    \    using i32 = int32_t;\n    using i64 = int64_t;\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32\
    \ ret = p;\n        for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;\n        return\
    \ ret;\n    }\n\n    static constexpr u32 r = get_r();\n    static constexpr u32\
    \ n2 = -u64(p) % p;\n    static_assert(r * p == 1, \"invalid, r * p != 1\");\n\
    \    static_assert(p < (1 << 30), \"invalid, p >= 2 ^ 30\");\n    static_assert((p\
    \ & 1) == 1, \"invalid, p % 2 == 0\");\n    \n    u32 _v;\n\n    constexpr LazyMontgomeryModInt()\
    \ : _v(0) {}\n    constexpr LazyMontgomeryModInt(const i64& b)\n         : _v(reduce(u64(b\
    \ % p + p) * n2)) {}\n\n    static constexpr u32 reduce(const u64& b) {\n    \
    \    return (b + u64(u32(b) * u32(-r)) * p) >> 32;\n    }\n    constexpr mint&\
    \ operator+=(const mint& b) {\n        if (i32(_v += b._v - 2 * p) < 0) _v +=\
    \ 2 * p;\n        return *this;\n    }\n    constexpr mint& operator-=(const mint&\
    \ b) {\n        if (i32(_v -= b._v) < 0) _v += 2 * p;\n        return *this;\n\
    \    }\n    constexpr mint& operator*=(const mint& b) {\n        _v = reduce(u64(_v)\
    \ * b._v);\n        return *this;\n    }\n    constexpr mint& operator/=(const\
    \ mint& b) {\n        *this *= b.inv();\n        return *this;\n    }\n\n    constexpr\
    \ mint operator+(const mint& b) const { return mint(*this) += b; }\n    constexpr\
    \ mint operator-(const mint& b) const { return mint(*this) -= b; }\n    constexpr\
    \ mint operator-() const { return mint() - mint(*this); }\n    constexpr mint\
    \ operator*(const mint& b) const { return mint(*this) *= b; }\n    constexpr mint\
    \ operator/(const mint& b) const { return mint(*this) /= b; }\n    constexpr bool\
    \ operator==(const mint &b) const {\n        return (_v >= p ? _v - p : _v) ==\
    \ (b._v >= p ? b._v - p : b._v);\n    }\n    constexpr bool operator!=(const mint\
    \ &b) const {\n        return (_v >= p ? _v - p : _v) != (b._v >= p ? b._v - p\
    \ : b._v);\n    }\n\n    template <class T>\n    constexpr mint pow(T n) const\
    \ {\n        mint ret(1), mul(*this);\n        while (n > 0) {\n            if\
    \ (n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n       \
    \ }\n        return ret;\n    }\n    constexpr mint inv() const { return pow(p\
    \ - 2); }\n\n    friend ostream& operator<<(ostream& os, const mint& x) {\n  \
    \      return os << x.val();\n    }\n    friend istream& operator>>(istream& is,\
    \ mint& x) {\n        i64 t; is >> t; x = mint(t);\n        return (is);\n   \
    \ }\n\n    constexpr u32 val() const {\n        u32 ret = reduce(_v);\n      \
    \  return ret >= p ? ret - p : ret;\n    }\n    static constexpr u32 getmod()\
    \ { return p; }\n};\n\ntemplate <int p>\nusing Mont = LazyMontgomeryModInt<p>;\n\
    \n\n#line 1 \"convolution/convolution.hpp\"\n\n\n\n#line 1 \"convolution/butterfly.hpp\"\
    \n\n\n\n#line 1 \"math_mod/primitive_rt_expr.hpp\"\n\n\n\n#line 1 \"math_mod/pow_expr.hpp\"\
    \n\n\n\nconstexpr long long pow_mod_constexpr(long long x, long long n, long long\
    \ m) {\n    if (m == 1) return 0;\n    unsigned long long _m = (unsigned long\
    \ long)(m);\n    unsigned long long r = 1;\n    unsigned long long y = (x % m\
    \ + m) % m;\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n        y\
    \ = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n\n#line 5 \"math_mod/primitive_rt_expr.hpp\"\
    \n\nconstexpr int primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n\
    \    if (m == 167772161) return 3;\n    if (m == 469762049) return 3;\n    if\
    \ (m == 754974721) return 11;\n    if (m == 998244353) return 3;\n    if (m ==\
    \ 1107296257) return 10;\n    int divs[20] = {}; \n    divs[0] = 2;\n    int cnt\
    \ = 1;\n    int x = (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int\
    \ i = 3; (long long)(i)*i <= x; i += 2) {\n        if (x % i == 0) {\n       \
    \     divs[cnt++] = i;\n            while (x % i == 0) {\n                x /=\
    \ i;\n            }\n        }\n    }\n    if (x > 1) {\n        divs[cnt++] =\
    \ x;\n    }\n    for (int g = 2;; g++) {\n        bool ok = true;\n        for\
    \ (int i = 0; i < cnt; i++) {\n            if (pow_mod_constexpr(g, (m - 1) /\
    \ divs[i], m) == 1) {\n                ok = false;\n                break;\n \
    \           }\n        }\n        if (ok) return g;\n    }\n}\ntemplate <int m>\
    \ static constexpr int primitive_root = primitive_root_constexpr(m);\n\n\n#line\
    \ 5 \"convolution/butterfly.hpp\"\n\ntemplate <class FPS, class mint = typename\
    \ FPS::value_type>\nvoid butterfly(FPS& a) {\n    static int g = primitive_root<mint::getmod()>;\n\
    \    int n = int(a.size());\n    int h = 0;\n    while ((1U << h) < (unsigned\
    \ int)(n)) h++;\n    static bool first = true;\n    static mint sum_e2[30];  //\
    \ sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]\n    static mint sum_e3[30];\n\
    \    static mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1\n    if (first) {\n\
    \        first = false;\n        int cnt2 = __builtin_ctz(mint::getmod() - 1);\n\
    \        mint e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();\n \
    \       for (int i = cnt2; i >= 2; i--) {\n            // e^(2^i) == 1\n     \
    \       es[i - 2] = e;\n            ies[i - 2] = ie;\n            e *= e;\n  \
    \          ie *= ie;\n        }\n        mint now = 1;\n        for (int i = 0;\
    \ i <= cnt2 - 2; i++) {\n            sum_e2[i] = es[i] * now;\n            now\
    \ *= ies[i];\n        }\n        now = 1;\n        for (int i = 0; i <= cnt2 -\
    \ 3; i++) {\n            sum_e3[i] = es[i + 1] * now;\n            now *= ies[i\
    \ + 1];\n        }\n    }\n\n    int len = 0;\n    while (len < h) {\n       \
    \ if (h - len == 1) {\n            int p = 1 << (h - len - 1);\n            mint\
    \ rot = 1;\n            for (int s = 0; s < (1 << len); s++) {\n             \
    \   int offset = s << (h - len);\n                for (int i = 0; i < p; i++)\
    \ {\n                    auto l = a[i + offset];\n                    auto r =\
    \ a[i + offset + p] * rot;\n                    a[i + offset] = l + r;\n     \
    \               a[i + offset + p] = l - r;\n                }\n              \
    \  if (s + 1 != (1 << len)) \n                    rot *= sum_e2[__builtin_ctz(~(unsigned\
    \ int)(s))];\n            }\n            len++;\n        }\n        else {\n \
    \           int p = 1 << (h - len - 2);\n            mint rot = 1, imag = es[0];\n\
    \            for (int s = 0; s < (1 << len); s++) {\n                mint rot2\
    \ = rot * rot;\n                mint rot3 = rot2 * rot;\n                int offset\
    \ = s << (h - len);\n                for (int i = 0; i < p; i++) {\n         \
    \           auto a0 = a[i + offset];\n                    auto a1 = a[i + offset\
    \ + p] * rot;\n                    auto a2 = a[i + offset + p * 2] * rot2;\n \
    \                   auto a3 = a[i + offset + p * 3] * rot3;\n                \
    \    auto a1na3imag = (a1 - a3) * imag;\n                    a[i + offset] = a0\
    \ + a2 + a1 + a3;\n                    a[i + offset + p] = a0 + a2 - a1 - a3;\n\
    \                    a[i + offset + p * 2] = a0 - a2 + a1na3imag;\n          \
    \          a[i + offset + p * 3] = a0 - a2 - a1na3imag;\n                }\n \
    \               if (s + 1 != (1 << len))\n                rot *= sum_e3[__builtin_ctz(~(unsigned\
    \ int)(s))];\n            }\n            len += 2;\n        }\n    }\n}\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nvoid butterfly_inv(FPS&\
    \ a) {\n    static constexpr int g = primitive_root<mint::getmod()>;\n    int\
    \ n = int(a.size());\n    int h = 0;\n    while ((1U << h) < (unsigned int)(n))\
    \ h++;\n    static bool first = true;\n    static mint sum_ie2[30];  // sum_ie[i]\
    \ = es[0] * ... * es[i - 1] * ies[i]\n    static mint sum_ie3[30];\n    static\
    \ mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1\n    if (first) {\n        first\
    \ = false;\n        int cnt2 = __builtin_ctz(mint::getmod() - 1);\n        mint\
    \ e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();\n        for (int\
    \ i = cnt2; i >= 2; i--) {\n            // e^(2^i) == 1\n            es[i - 2]\
    \ = e;\n            ies[i - 2] = ie;\n            e *= e;\n            ie *= ie;\n\
    \        }\n        mint now = 1;\n        for (int i = 0; i <= cnt2 - 2; i++)\
    \ {\n            sum_ie2[i] = ies[i] * now;\n            now *= es[i];\n     \
    \   }\n        now = 1;\n        for (int i = 0; i <= cnt2 - 3; i++) {\n     \
    \       sum_ie3[i] = ies[i + 1] * now;\n            now *= es[i + 1];\n      \
    \  }\n    }\n    int len = h;\n    while (len) {\n        if (len == 1) {\n  \
    \          int p = 1 << (h - len);\n            mint irot = 1;\n            for\
    \ (int s = 0; s < (1 << (len - 1)); s++) {\n                int offset = s <<\
    \ (h - len +  1);\n                for (int i = 0; i < p; i++) {\n           \
    \         auto l = a[i + offset];\n                    auto r = a[i + offset +\
    \ p];\n                    a[i + offset] = l + r;\n                    a[i + offset\
    \ + p] = (l - r) * irot;\n                }\n                if (s + 1 != (1 <<\
    \ (len - 1)))\n                    irot *= sum_ie2[__builtin_ctz(~(unsigned int)(s))];\n\
    \            }\n            len--;\n        }\n        else {\n            int\
    \ p = 1 << (h - len);\n            mint irot = 1, iimag = ies[0];\n          \
    \  for (int s = 0; s < (1 << ((len - 2))); s++) {\n                mint irot2\
    \ = irot * irot;\n                mint irot3 = irot2 * irot;\n               \
    \ int offset = s << (h - len + 2);\n                for (int i = 0; i < p; i++)\
    \ {\n                    auto a0 = a[i + offset];\n                    auto a1\
    \ = a[i + offset + p];\n                    auto a2 = a[i + offset + p * 2];\n\
    \                    auto a3 = a[i + offset + p * 3];\n                    auto\
    \ a2na3iimag = (a2 - a3) * iimag;\n                    \n                    a[i\
    \ + offset] = a0 + a1 + a2 + a3;\n                    a[i + offset + p] = (a0\
    \ - a1 + a2na3iimag) * irot;\n                    a[i + offset + p * 2] = (a0\
    \ + a1 - a2 - a3) * irot2;\n                    a[i + offset + p * 3] = (a0 -\
    \ a1 - a2na3iimag) * irot3;\n                }\n                if (s + 1 != (1\
    \ << (len - 2)))\n                    irot *= sum_ie3[__builtin_ctz(~(unsigned\
    \ int)(s))];\n            }\n            len -= 2;\n        }\n    }\n}\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nvoid doubling(FPS &a) {\n\
    \    int n = a.size();\n    auto b = a;\n    int z = 1;\n    while (z < n) z <<=\
    \ 1;\n    mint invz = mint(z).inv();\n    butterfly_inv(b); b *= invz;\n    mint\
    \ r = 1, zeta = mint(primitive_root<mint::getmod()>).\n                      \
    \ pow((mint::getmod() - 1) / (n << 1));\n    for (int i = 0; i < n; i++) {\n \
    \       b[i] *= r;\n        r *= zeta;\n    }\n    butterfly(b);\n    copy(begin(b),\
    \ end(b), back_inserter(a));\n}\n\n\n#line 5 \"convolution/convolution.hpp\"\n\
    \ntemplate <class FPS, class mint = typename FPS::value_type>\nFPS convolution(FPS&\
    \ a, FPS b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m)\
    \ return {};\n    if (std::min(n, m) <= 60) {\n        if (n < m) {\n        \
    \    swap(n, m);\n            swap(a, b);\n        }\n        FPS res(n + m -\
    \ 1);\n        for (int i = 0; i < n; i++) {\n            for (int j = 0; j <\
    \ m; j++) {\n                res[i + j] += a[i] * b[j];\n            }\n     \
    \   }\n        a = res;\n        return a;\n    }\n    int z = 1;\n    while (z\
    \ < n + m - 1) z <<= 1;\n    a.resize(z);\n    butterfly(a);\n    b.resize(z);\n\
    \    butterfly(b);\n    for (int i = 0; i < z; i++) a[i] *= b[i];\n    butterfly_inv(a);\n\
    \    a.resize(n + m - 1);\n    mint iz = mint(z).inv();\n    for (int i = 0; i\
    \ < n + m - 1; i++) a[i] *= iz;\n    return a;\n}\n\n\n#line 1 \"math_mod/garner.hpp\"\
    \n\n\n\n#line 1 \"math_mod/inv.hpp\"\n\n\n\ntemplate <class T, class U>\nconstexpr\
    \ long long mod_inversion(T a, U modulo) {\n    long long s = modulo, t = a;\n\
    \    long long m0 = 0, m1 = 1;\n    while (t) {\n        long long u = s / t;\n\
    \        swap(s -= t * u, t);\n        swap(m0 -= m1 * u, m1);\n    }\n    if\
    \ (m0 < 0) m0 += modulo / s;\n    return m0;\n}\n\n\n#line 5 \"math_mod/garner.hpp\"\
    \n\nlong long garner(const vector<long long>& d, const vector<long long>& p) {\n\
    \    static int nm = d.size();\n    vector<long long> kp(nm + 1, 0), rmult(nm\
    \ + 1, 1);\n    for (int ii = 0; ii < nm; ii++) {\n        long long x = (d[ii]\
    \ - kp[ii]) * mod_inversion(rmult[ii], p[ii]) % p[ii];\n        x = (x + p[ii])\
    \ % p[ii];\n        for (int iii = ii + 1; iii < nm + 1; iii++) {\n          \
    \  kp[iii] = (kp[iii] + rmult[iii] * x) % p[iii];\n            rmult[iii] = (rmult[iii]\
    \ * p[ii]) % p[iii];\n        }\n    }\n    return kp[nm];\n}\n\n\n#line 8 \"\
    convolution/convo_arb.hpp\"\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    FPS convolution_arb(FPS& a, FPS b) {\n    int n = int(a.size()), m = int(b.size());\n\
    \    if (!n || !m) return {};\n    static constexpr long long MOD1 = 754974721;\
    \  // 2^24\n    static constexpr long long MOD2 = 167772161;  // 2^25\n    static\
    \ constexpr long long MOD3 = 469762049;  // 2^26\n    using mint1 = LazyMontgomeryModInt<MOD1>;\n\
    \    using mint2 = LazyMontgomeryModInt<MOD2>;\n    using mint3 = LazyMontgomeryModInt<MOD3>;\n\
    \n    vector<long long> a0(n), b0(m);\n    for (int i = 0; i < n; i++) a0[i] =\
    \ a[i].val();\n    for (int i = 0; i < m; i++) b0[i] = b[i].val();\n    auto a1\
    \ = FormalPowerSeries<mint1>(begin(a0), end(a0));\n    auto b1 = FormalPowerSeries<mint1>(begin(b0),\
    \ end(b0));\n    auto c1 = convolution<mint1>(a1, b1);\n    auto a2 = FormalPowerSeries<mint2>(begin(a0),\
    \ end(a0));\n    auto b2 = FormalPowerSeries<mint2>(begin(b0), end(b0));\n   \
    \ auto c2 = convolution<mint2>(a2, b2);\n    auto a3 = FormalPowerSeries<mint3>(begin(a0),\
    \ end(a0));\n    auto b3 = FormalPowerSeries<mint3>(begin(b0), end(b0));\n   \
    \ auto c3 = convolution<mint3>(a3, b3);\n    static const vector<long long> p\
    \ = {MOD1, MOD2, MOD3, mint::getmod()};\n    FPS res(n + m - 1);\n    for (int\
    \ i = 0; i < n + m - 1; i++) {\n        res[i] = mint(garner({c1[i].val(), c2[i].val(),\
    \ c3[i].val()}, p));\n    }\n    a = res;\n    return res;\n}\n\n\n#line 6 \"\
    fps/fps_arb.hpp\"\n\ntemplate <class mint>\nvoid FormalPowerSeries<mint>::but()\
    \ {\n    exit(1);\n}\n\ntemplate <class mint>\nvoid FormalPowerSeries<mint>::ibut()\
    \ {\n    exit(1);\n}\n\ntemplate <class mint>\nvoid FormalPowerSeries<mint>::db()\
    \ {\n    exit(1);\n}\n\ntemplate <class mint>\nint FormalPowerSeries<mint>::but_pr()\
    \ {\n    return 0;\n}\n\ntemplate <class mint>\nFormalPowerSeries<mint> &FormalPowerSeries<mint>::operator*=(\n\
    \    const FormalPowerSeries<mint>& r) {\n    if (this->empty() || r.empty())\
    \ {\n        this->clear();\n        return *this;\n    }\n    convolution_arb(*this,\
    \ r);\n    return *this;\n}\n\ntemplate <class mint>\nFormalPowerSeries<mint>\
    \ FormalPowerSeries<mint>::inv(int deg) const {\n    assert((*this)[0] != mint(0));\n\
    \    if (deg == -1) deg = this->size();\n    FormalPowerSeries<mint> res{mint(1)\
    \ / (*this)[0]};\n    for (int i = 1; i < deg; i <<= 1) {\n        res = (res\
    \ * mint(2) - this->pre(i << 1) * res * res).pre(i << 1);\n    }\n    return res.pre(deg);\n\
    }\n\ntemplate <class mint>\nFormalPowerSeries<mint> FormalPowerSeries<mint>::exp(int\
    \ deg) const {\n    assert(this->empty() || (*this)[0] == mint(0));\n    if (deg\
    \ == -1) deg = this->size();\n    FormalPowerSeries<mint> ret{mint(1)};\n    for\
    \ (int i = 1; i < deg; i <<= 1) {\n        ret = (ret * (pre(i << 1) + mint{1}\
    \ - ret.log(i << 1))).pre(i << 1);\n    }\n    return ret.pre(deg);\n}\n\n\n#line\
    \ 1 \"fps/sample_point_shift.hpp\"\n\n\n\ntemplate <class FPS, class mint = typename\
    \ FPS::value_type>\nvector<mint> SamplePointShift(vector<mint> &y, mint t, int\
    \ m = -1) {\n    if (m == -1) m = y.size();\n    long long tval = t.val();\n \
    \   int k = (int)y.size() - 1;\n    if (tval <= k) {\n        FPS ret(m);\n  \
    \      int ptr = 0;\n        for (long long i = tval; i <= k and ptr < m; i++)\
    \ {\n            ret[ptr++] = y[i];\n        }\n        if (k + 1 < tval + m)\
    \ {\n            auto suf = SamplePointShift<FPS>(y, mint(k + 1), m - ptr);\n\
    \            for (int i = k + 1; i < tval + m; i++) {\n                ret[ptr++]\
    \ = suf[i - (k + 1)];\n            }\n        }\n        return ret;\n    }\n\
    \    if (tval + m > mint::getmod()) {\n        auto pref = SamplePointShift<FPS>(y,\
    \ mint(t), mint::getmod() - tval);\n        auto suf = SamplePointShift<FPS>(y,\
    \ mint(0), m - (int)pref.size());\n        copy(begin(suf), end(suf), back_inserter(pref));\n\
    \        return pref;\n    }\n\n    vector<mint> inv(k + 1, 1);\n    FPS d(k +\
    \ 1);\n    for (int i = 2; i <= k; i++) inv[k] *= i;\n    inv[k] = inv[k].inv();\n\
    \    for (int i = k; i >= 1; i--) inv[i - 1] = inv[i] * i;\n    for (int i = 0;\
    \ i <= k; i++) {\n        d[i] = inv[i] * inv[k - i] * y[i];\n        if ((k -\
    \ i) & 1) d[i] = -d[i];\n    }\n\n    FPS h(m + k);\n    for (int i = 0; i < m\
    \ + k; i++) {\n        h[i] = (t - k + i).inv();\n    }\n\n    FPS dh = d * h;\n\
    \n    vector<mint> ret(m);\n    mint cur = t;\n    for (int i = 1; i <= k; i++)\
    \ cur *= t - i;\n    for (int i = 0; i < m; i++) {\n        ret[i] = cur * dh[k\
    \ + i];\n        cur *= t + i + 1;\n        cur *= h[i];\n    }\n    return ret;\n\
    }\n\n\n#line 1 \"math_mod/comb.hpp\"\n\n\n\ntemplate <class mint>\nstruct Comb\
    \ {\n    static inline vector<mint> _fact{1}, _ifact{1}, _inv{1};\n\n    Comb()\
    \ = delete;\n\n    static void extend(int m = -1) {\n        int n = (int)_fact.size();\n\
    \        if (m == -1) m = n << 1;\n        if (n > m) return;\n        m = min<int>(m,\
    \ mint::getmod() - 1);\n        _fact.resize(m + 1);\n        _ifact.resize(m\
    \ + 1);\n        _inv.resize(m + 1);\n        for (int i = n; i <= m; i++) _fact[i]\
    \ = _fact[i - 1] * i;\n        _ifact[m] = _fact[m].inv();\n        _inv[m] =\
    \ _ifact[m] * _fact[m - 1];\n        for (int i = m; i > n; i--) {\n         \
    \   _ifact[i - 1] = _ifact[i] * i;\n            _inv[i - 1] = _ifact[i - 1] *\
    \ _fact[i - 2];\n        }\n    }\n\n    static mint fact(int n) {\n        if\
    \ (n < 0) return 0;\n        if ((int)_fact.size() <= n) extend(n);\n        return\
    \ _fact[n];\n    }\n\n    static mint ifact(int n) {\n        if (n < 0) return\
    \ 0;\n        if ((int)_ifact.size() <= n) extend(n);\n        return _ifact[n];\n\
    \    }\n\n    static mint inv(int n) {\n        if (n < 0) return -inv(-n);\n\
    \        if ((int)_inv.size() <= n) extend(n);\n        return _inv[n];\n    }\n\
    \n    static mint binom(int n, int k) {\n        if (k < 0 || k > n) return 0;\n\
    \        return fact(n) * ifact(k) * ifact(n - k);\n    }\n\n    template <class\
    \ T>\n    static mint multinomial(const vector<T>& r) {\n        static_assert(is_integral_v<T>,\
    \ \"T must be integral\");\n        int n = 0;\n        for (auto &x : r) {\n\
    \            if (x < 0) return 0;\n            n += x;\n        }\n        mint\
    \ res = fact(n);\n        for (auto &x : r) res *= ifact(x);\n        return res;\n\
    \    }\n\n    static mint binom_naive(int n, int k) {\n        if (n < 0 || k\
    \ < 0 || k > n) return 0;\n        mint res = 1;\n        k = min(k, n - k);\n\
    \        for (int i = 1; i <= k; i++) res *= inv(i) * (n--);\n        return res;\n\
    \    }\n\n    static mint permu(int n, int k) {\n        if (n < 0 || k < 0 ||\
    \ k > n) return 0;\n        return fact(n) * ifact(n - k);\n    }\n\n    static\
    \ mint homo(int n, int k) {\n        if (n < 0 || k < 0) return 0;\n        return\
    \ k == 0 ? 1 : binom(n + k - 1, k);\n    }\n};\n\n\n#line 7 \"math_mod/comb_large_arb.hpp\"\
    \n\ntemplate <class mint>\nstruct CombLarge {\n    using FPS = FormalPowerSeries<mint>;\n\
    \    static constexpr int LOG_BLOCK_SIZE = 16;\n    static constexpr int BLOCK_SIZE\
    \ = 1 << LOG_BLOCK_SIZE;\n    static constexpr int BLOCK_NUM = mint::getmod()\
    \ >> LOG_BLOCK_SIZE;\n\n    static inline int threshold = 2000000;\n\n    CombLarge()\
    \ = delete;\n\n    static mint fact(int n) {\n        return n <= threshold ?\
    \ Comb<mint>::fact(n) : _large_fact(n);\n    }\n    static mint inv_fact(int n)\
    \ {\n        return n <= threshold ? Comb<mint>::ifact(n) : _large_fact(n).inv();\n\
    \    }\n    static mint binom(int n, int r) {\n        if (r < 0 || r > n) return\
    \ mint(0);\n        return fact(n) * inv_fact(r) * inv_fact(n - r);\n    }\n\n\
    \    template <class T>\n    static mint multinomial(vector<T> r) {\n        static_assert(is_integral_v<T>,\
    \ \"T must be integral\");\n        long long n = 0;\n        for (auto &x : r)\
    \ {\n            assert(x >= 0);\n            n += x;\n        }\n        if (n\
    \ >= mint::getmod()) return 0;\n        mint res = fact(n);\n        for (auto\
    \ &x : r) res *= inv_fact(x);\n        return res;\n    }\n\n    static mint permu(int\
    \ n, int r) {\n        if (r < 0 || r > n) return mint(0);\n        return fact(n)\
    \ * inv_fact(n - r);\n    }\n    static mint homo(int n, int r) {\n        if\
    \ (n < 0 || r < 0) return mint(0);\n        return r == 0 ? 1 : binom(n + r -\
    \ 1, r);\n    }\n  private:\n    static inline vector<mint> _block_fact{};\n \
    \   \n    static void _build() {\n        if (_block_fact.size()) return;\n  \
    \      vector<mint> f{1};\n        f.reserve(BLOCK_SIZE);\n        for (int i\
    \ = 0; i < LOG_BLOCK_SIZE; i++) {\n            vector<mint> g = SamplePointShift<FPS>(f,\
    \ mint(1 << i), 3 << i);\n            const auto get = [&](int j) {\n        \
    \        return j < (1 << i) ? f[j] : g[j - (1 << i)];\n            };\n     \
    \       f.resize(2 << i);\n            for (int j = 0; j < 2 << i; j++) {\n  \
    \              f[j] = get(2 * j) * get(2 * j + 1) * ((2 * j + 1) << i);\n    \
    \        }\n        }\n\n        if (BLOCK_NUM > BLOCK_SIZE) {\n            vector<mint>\
    \ g = SamplePointShift<FPS>(f, mint(BLOCK_SIZE),\n                BLOCK_NUM -\
    \ BLOCK_SIZE);\n            move(begin(g), end(g), back_inserter(f));\n      \
    \  }\n        else f.resize(BLOCK_NUM);\n        for (int i = 0; i < BLOCK_NUM;\
    \ i++) {\n            f[i] *= mint(i + 1) * BLOCK_SIZE;\n        }\n        //\
    \ f[i] = prod_{j = 1} ^ (BLOCK_SIZE) (i * BLOCK_SIZE + j)\n\n        f.insert(begin(f),\
    \ 1);\n        for (int i = 1; i <= BLOCK_NUM; i++) {\n            f[i] *= f[i\
    \ - 1];\n        }\n        _block_fact = move(f);\n    }\n\n    static mint _large_fact(int\
    \ n) {\n        _build();\n        mint res;\n        int q = n / BLOCK_SIZE,\
    \ r = n % BLOCK_SIZE;\n        if (2 * r <= BLOCK_SIZE) {\n            res = _block_fact[q];\n\
    \            for (int i = 0; i < r; i++) {\n                res *= n - i;\n  \
    \          }\n        }\n        else if (q != BLOCK_NUM) {\n            res =\
    \ _block_fact[q + 1];\n            mint den = 1;\n            for (int i = 1;\
    \ i <= BLOCK_SIZE - r; i++) {\n                den *= n + i;\n            }\n\
    \            res /= den;\n        }\n        else {\n            res = -1;\n \
    \           mint den = 1;\n            for (int i = mint::getmod() - 1; i > n;\
    \ i++) {\n                den *= i;\n            }\n            res /= den;\n\
    \        }\n        return res;\n    }\n};\n\n\n"
  code: "#ifndef MOD_COMB_LARGE_ARB_HPP\n#define MOD_COMB_LARGE_ARB_HPP 1\n\n#include\
    \ \"../fps/fps_arb.hpp\"\n#include \"../fps/sample_point_shift.hpp\"\n#include\
    \ \"comb.hpp\"\n\ntemplate <class mint>\nstruct CombLarge {\n    using FPS = FormalPowerSeries<mint>;\n\
    \    static constexpr int LOG_BLOCK_SIZE = 16;\n    static constexpr int BLOCK_SIZE\
    \ = 1 << LOG_BLOCK_SIZE;\n    static constexpr int BLOCK_NUM = mint::getmod()\
    \ >> LOG_BLOCK_SIZE;\n\n    static inline int threshold = 2000000;\n\n    CombLarge()\
    \ = delete;\n\n    static mint fact(int n) {\n        return n <= threshold ?\
    \ Comb<mint>::fact(n) : _large_fact(n);\n    }\n    static mint inv_fact(int n)\
    \ {\n        return n <= threshold ? Comb<mint>::ifact(n) : _large_fact(n).inv();\n\
    \    }\n    static mint binom(int n, int r) {\n        if (r < 0 || r > n) return\
    \ mint(0);\n        return fact(n) * inv_fact(r) * inv_fact(n - r);\n    }\n\n\
    \    template <class T>\n    static mint multinomial(vector<T> r) {\n        static_assert(is_integral_v<T>,\
    \ \"T must be integral\");\n        long long n = 0;\n        for (auto &x : r)\
    \ {\n            assert(x >= 0);\n            n += x;\n        }\n        if (n\
    \ >= mint::getmod()) return 0;\n        mint res = fact(n);\n        for (auto\
    \ &x : r) res *= inv_fact(x);\n        return res;\n    }\n\n    static mint permu(int\
    \ n, int r) {\n        if (r < 0 || r > n) return mint(0);\n        return fact(n)\
    \ * inv_fact(n - r);\n    }\n    static mint homo(int n, int r) {\n        if\
    \ (n < 0 || r < 0) return mint(0);\n        return r == 0 ? 1 : binom(n + r -\
    \ 1, r);\n    }\n  private:\n    static inline vector<mint> _block_fact{};\n \
    \   \n    static void _build() {\n        if (_block_fact.size()) return;\n  \
    \      vector<mint> f{1};\n        f.reserve(BLOCK_SIZE);\n        for (int i\
    \ = 0; i < LOG_BLOCK_SIZE; i++) {\n            vector<mint> g = SamplePointShift<FPS>(f,\
    \ mint(1 << i), 3 << i);\n            const auto get = [&](int j) {\n        \
    \        return j < (1 << i) ? f[j] : g[j - (1 << i)];\n            };\n     \
    \       f.resize(2 << i);\n            for (int j = 0; j < 2 << i; j++) {\n  \
    \              f[j] = get(2 * j) * get(2 * j + 1) * ((2 * j + 1) << i);\n    \
    \        }\n        }\n\n        if (BLOCK_NUM > BLOCK_SIZE) {\n            vector<mint>\
    \ g = SamplePointShift<FPS>(f, mint(BLOCK_SIZE),\n                BLOCK_NUM -\
    \ BLOCK_SIZE);\n            move(begin(g), end(g), back_inserter(f));\n      \
    \  }\n        else f.resize(BLOCK_NUM);\n        for (int i = 0; i < BLOCK_NUM;\
    \ i++) {\n            f[i] *= mint(i + 1) * BLOCK_SIZE;\n        }\n        //\
    \ f[i] = prod_{j = 1} ^ (BLOCK_SIZE) (i * BLOCK_SIZE + j)\n\n        f.insert(begin(f),\
    \ 1);\n        for (int i = 1; i <= BLOCK_NUM; i++) {\n            f[i] *= f[i\
    \ - 1];\n        }\n        _block_fact = move(f);\n    }\n\n    static mint _large_fact(int\
    \ n) {\n        _build();\n        mint res;\n        int q = n / BLOCK_SIZE,\
    \ r = n % BLOCK_SIZE;\n        if (2 * r <= BLOCK_SIZE) {\n            res = _block_fact[q];\n\
    \            for (int i = 0; i < r; i++) {\n                res *= n - i;\n  \
    \          }\n        }\n        else if (q != BLOCK_NUM) {\n            res =\
    \ _block_fact[q + 1];\n            mint den = 1;\n            for (int i = 1;\
    \ i <= BLOCK_SIZE - r; i++) {\n                den *= n + i;\n            }\n\
    \            res /= den;\n        }\n        else {\n            res = -1;\n \
    \           mint den = 1;\n            for (int i = mint::getmod() - 1; i > n;\
    \ i++) {\n                den *= i;\n            }\n            res /= den;\n\
    \        }\n        return res;\n    }\n};\n\n#endif // MOD_COMB_LARGE_ARB_HPP\n"
  dependsOn:
  - fps/fps_arb.hpp
  - fps/fps.hpp
  - convolution/convo_arb.hpp
  - modint/mont.hpp
  - convolution/convolution.hpp
  - convolution/butterfly.hpp
  - math_mod/primitive_rt_expr.hpp
  - math_mod/pow_expr.hpp
  - fps/fps.hpp
  - math_mod/garner.hpp
  - math_mod/inv.hpp
  - fps/sample_point_shift.hpp
  - math_mod/comb.hpp
  isVerificationFile: false
  path: math_mod/comb_large_arb.hpp
  requiredBy: []
  timestamp: '2024-06-13 21:51:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math_mod/comb_large_arb.hpp
layout: document
redirect_from:
- /library/math_mod/comb_large_arb.hpp
- /library/math_mod/comb_large_arb.hpp.html
title: math_mod/comb_large_arb.hpp
---
