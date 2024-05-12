---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/fps.hpp
    title: fps/fps.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/fps_composition.hpp\"\n\n\n\n#line 1 \"fps/fps.hpp\"\
    \n\n\n\n\ntemplate <class mint>\nstruct FormalPowerSeries : vector<mint> {\n \
    \   using vector<mint>::vector;\n    using FPS = FormalPowerSeries;\n\n    FPS\
    \ &operator+=(const FPS &r) {\n        if (this->size() < r.size()) this->resize(r.size());\n\
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
    \     return r;\n    }\n    FPS log(int deg = -1) const {\n        assert(!this->empty()\
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
    #line 5 \"fps/fps_composition.hpp\"\n\n// calculate (g \\circ f) (X)\ntemplate\
    \ <class mint>\nFormalPowerSeries<mint> composition(FormalPowerSeries<mint> f,\n\
    \                                    FormalPowerSeries<mint> g,\n            \
    \                        int deg = -1) {\n    if (f.empty() || g.empty()) return\
    \ {};\n    \n    auto rec = [&](auto self, FormalPowerSeries<mint> q,\n      \
    \             int n, int h, int k) -> FormalPowerSeries<mint> {\n        if (n\
    \ == 0) {\n            FormalPowerSeries<mint> t(begin(q), begin(q) + k);\n  \
    \          t.push_back(1);\n            FormalPowerSeries<mint> u = g * t.rev().inv().rev();\n\
    \            FormalPowerSeries<mint> p(h * k);\n            for (int i = 0; i\
    \ < (int)size(g); i++) {\n                p[k - 1 - i] = u[i + k];\n         \
    \   }\n            return p;\n        }\n        FormalPowerSeries<mint> nq(4\
    \ * h * k), nr(2 * h * k);\n        for (int i = 0; i < k; i++) {\n          \
    \  copy(begin(q) + i * h, begin(q) + i * h + n + 1,\n                 begin(nq)\
    \ + i * 2 * h);\n        }\n        nq[k * 2 * h] += 1;\n        int z = 1;\n\
    \        while (z < 2 * h * k) z <<= 1;\n        mint invz = mint(z).inv(), invz2\
    \ = invz * mint(2).inv();\n        nq.resize(z << 1);\n        nq.but();\n   \
    \     for (int i = 0; i < 4 * h * k; i += 2) swap(nq[i], nq[i + 1]);\n       \
    \ for (int i = 0; i < 2 * h * k; i++) {\n            nr[i] = nq[i * 2] * nq[i\
    \ * 2 + 1];\n        }\n        nr.resize(z);\n        nr.ibut();\n        for\
    \ (int i = 0; i < 2 * h * k; i++) nr[i] *= invz;\n        nr[0] -= 1;\n      \
    \  q.assign(h * k, 0);\n        for (int i = 0; i < 2 * k; i++) {\n          \
    \  for (int j = 0; j <= n / 2; j++) {\n                q[i * h / 2 + j] = nr[i\
    \ * h + j];\n            }\n        }\n        auto p = self(self, q, n / 2, h\
    \ / 2, k * 2);\n        FormalPowerSeries<mint> np(4 * h * k);\n        for (int\
    \ i = 0; i < 2 * k; i++) {\n            for (int j = 0; j <= n / 2; j++) {\n \
    \               np[i * 2 * h + j * 2 + n % 2] = p[i * h / 2 + j];\n          \
    \  }\n        }\n        np.resize(z << 1);\n        np.but();\n        for (int\
    \ i = 1; i < 4 * h * k; i <<= 1) {\n            reverse(begin(nq) + i, begin(nq)\
    \ + i * 2);\n        }\n        for (int i = 0; i < 4 * h * k; i++) {\n      \
    \      np[i] *= nq[i];\n        }\n        np.ibut();\n        for (int i = 0;\
    \ i < 4 * h * k; i++) np[i] *= invz2;\n        p.assign(h * k, 0);\n        for\
    \ (int i = 0; i < k; i++) {\n            copy(begin(np) + i * 2 * h, begin(np)\
    \ + i * 2 * h + n + 1,\n                 begin(p) + i * h);\n        }\n     \
    \   return p;\n    }; \n\n    if (deg == -1) deg = max(size(f), size(g));\n  \
    \  f.resize(deg), g.resize(deg);\n    int n = int(size(f)) - 1, k = 1;\n    int\
    \ h = 1;\n    while (h < n + 1) h <<= 1;\n    FormalPowerSeries<mint> q(h * k);\n\
    \    for (int i = 0; i <= n; i++) q[i] = -f[i];\n    FormalPowerSeries<mint> p\
    \ = rec(rec, q, n, h, k);\n    return p.pre(n + 1).rev();\n}\n\n\n\n"
  code: "#ifndef FPS_COMPOSITION_HPP\n#define FPS_COMPOSITION_HPP 1\n\n#include \"\
    fps.hpp\"\n\n// calculate (g \\circ f) (X)\ntemplate <class mint>\nFormalPowerSeries<mint>\
    \ composition(FormalPowerSeries<mint> f,\n                                   \
    \ FormalPowerSeries<mint> g,\n                                    int deg = -1)\
    \ {\n    if (f.empty() || g.empty()) return {};\n    \n    auto rec = [&](auto\
    \ self, FormalPowerSeries<mint> q,\n                   int n, int h, int k) ->\
    \ FormalPowerSeries<mint> {\n        if (n == 0) {\n            FormalPowerSeries<mint>\
    \ t(begin(q), begin(q) + k);\n            t.push_back(1);\n            FormalPowerSeries<mint>\
    \ u = g * t.rev().inv().rev();\n            FormalPowerSeries<mint> p(h * k);\n\
    \            for (int i = 0; i < (int)size(g); i++) {\n                p[k - 1\
    \ - i] = u[i + k];\n            }\n            return p;\n        }\n        FormalPowerSeries<mint>\
    \ nq(4 * h * k), nr(2 * h * k);\n        for (int i = 0; i < k; i++) {\n     \
    \       copy(begin(q) + i * h, begin(q) + i * h + n + 1,\n                 begin(nq)\
    \ + i * 2 * h);\n        }\n        nq[k * 2 * h] += 1;\n        int z = 1;\n\
    \        while (z < 2 * h * k) z <<= 1;\n        mint invz = mint(z).inv(), invz2\
    \ = invz * mint(2).inv();\n        nq.resize(z << 1);\n        nq.but();\n   \
    \     for (int i = 0; i < 4 * h * k; i += 2) swap(nq[i], nq[i + 1]);\n       \
    \ for (int i = 0; i < 2 * h * k; i++) {\n            nr[i] = nq[i * 2] * nq[i\
    \ * 2 + 1];\n        }\n        nr.resize(z);\n        nr.ibut();\n        for\
    \ (int i = 0; i < 2 * h * k; i++) nr[i] *= invz;\n        nr[0] -= 1;\n      \
    \  q.assign(h * k, 0);\n        for (int i = 0; i < 2 * k; i++) {\n          \
    \  for (int j = 0; j <= n / 2; j++) {\n                q[i * h / 2 + j] = nr[i\
    \ * h + j];\n            }\n        }\n        auto p = self(self, q, n / 2, h\
    \ / 2, k * 2);\n        FormalPowerSeries<mint> np(4 * h * k);\n        for (int\
    \ i = 0; i < 2 * k; i++) {\n            for (int j = 0; j <= n / 2; j++) {\n \
    \               np[i * 2 * h + j * 2 + n % 2] = p[i * h / 2 + j];\n          \
    \  }\n        }\n        np.resize(z << 1);\n        np.but();\n        for (int\
    \ i = 1; i < 4 * h * k; i <<= 1) {\n            reverse(begin(nq) + i, begin(nq)\
    \ + i * 2);\n        }\n        for (int i = 0; i < 4 * h * k; i++) {\n      \
    \      np[i] *= nq[i];\n        }\n        np.ibut();\n        for (int i = 0;\
    \ i < 4 * h * k; i++) np[i] *= invz2;\n        p.assign(h * k, 0);\n        for\
    \ (int i = 0; i < k; i++) {\n            copy(begin(np) + i * 2 * h, begin(np)\
    \ + i * 2 * h + n + 1,\n                 begin(p) + i * h);\n        }\n     \
    \   return p;\n    }; \n\n    if (deg == -1) deg = max(size(f), size(g));\n  \
    \  f.resize(deg), g.resize(deg);\n    int n = int(size(f)) - 1, k = 1;\n    int\
    \ h = 1;\n    while (h < n + 1) h <<= 1;\n    FormalPowerSeries<mint> q(h * k);\n\
    \    for (int i = 0; i <= n; i++) q[i] = -f[i];\n    FormalPowerSeries<mint> p\
    \ = rec(rec, q, n, h, k);\n    return p.pre(n + 1).rev();\n}\n\n\n#endif /* FPS_COMPOSITION_HPP\
    \ */"
  dependsOn:
  - fps/fps.hpp
  isVerificationFile: false
  path: fps/fps_composition.hpp
  requiredBy: []
  timestamp: '2024-05-12 17:44:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/fps_composition.hpp
layout: document
redirect_from:
- /library/fps/fps_composition.hpp
- /library/fps/fps_composition.hpp.html
title: fps/fps_composition.hpp
---
