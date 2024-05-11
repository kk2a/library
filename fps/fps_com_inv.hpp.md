---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: fps/fps.hpp
    title: fps/fps.hpp
  - icon: ':warning:'
    path: fps/power_projection.hpp
    title: fps/power_projection.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/fps_com_inv.hpp\"\n\n\n\n#line 1 \"fps/fps.hpp\"\n\n\
    \n\n\ntemplate <class mint>\nstruct FormalPowerSeries : vector<mint> {\n    using\
    \ vector<mint>::vector;\n    using FPS = FormalPowerSeries;\n\n    FPS &operator+=(const\
    \ FPS &r) {\n        if (this->size() < r.size()) this->resize(r.size());\n  \
    \      for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n        return\
    \ *this;\n    }\n    FPS &operator+=(const mint &r) {\n        if (this->empty())\
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
    \ ret[i] = -(*this)[i];\n        return ret;\n    }\n\n    void shrink() {\n \
    \       while (this->size() && this->back() == mint(0)) this->pop_back();\n  \
    \  }\n\n    FPS rev() const {\n        FPS ret(*this);\n        reverse(ret.begin(),\
    \ ret.end());\n        return ret;\n    }\n\n    FPS inplace_rev() {\n       \
    \ reverse(this->begin(), this->end());\n        return *this;\n    }\n\n    FPS\
    \ dot(const FPS &r) const {\n        FPS ret(min(this->size(), r.size()));\n \
    \       for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];\n\
    \        return ret;\n    }\n\n    FPS inplace_dot(const FPS &r) {\n        this->resize(min(this->size(),\
    \ r.size()));\n        for (int i = 0; i < (int)this->size(); i++) (*this)[i]\
    \ *= r[i];\n        return *this;\n    }\n\n    FPS pre(int n) const {\n     \
    \   FPS ret(begin(*this), begin(*this) + min((int)this->size(), n));\n       \
    \ if ((int)ret.size() < n) ret.resize(n, mint(0));\n        return ret;\n    }\n\
    \n    FPS inplace_pre(int n) {\n        this->resize(n);\n        return *this;\n\
    \    }\n\n    FPS operator>>(int n) const {\n        if (n >= (int)this->size())\
    \ return {};\n        FPS ret(begin(*this) + n, end(*this));\n        return ret;\n\
    \    }\n    FPS operator<<(int n) const {\n        FPS ret(*this);\n        ret.insert(begin(ret),\
    \ n, mint(0));\n        return ret;\n    }\n\n    FPS diff() const {\n       \
    \ const int n = (int)this->size();\n        FPS ret(max(0, n - 1));\n        for\
    \ (int i = 1; i < n; i++) {\n            ret[i - 1] = (*this)[i] * mint(i);\n\
    \        }\n        return ret;\n    }\n\n    FPS inplace_diff() {\n        if\
    \ (this->empty()) return {};\n        this->erase(this->begin());\n        for\
    \ (int i = 1; i <= (int)this->size(); i++)\n            (*this)[i - 1] *= mint(i);\n\
    \        return *this;\n    }\n\n    FPS integral() const {\n        const int\
    \ n = (int)this->size();\n        FPS ret(n + 1);\n        ret[0] = mint(0);\n\
    \        if (n > 0) ret[1] = mint(1);\n        auto mod = mint::getmod();\n  \
    \      for (int i = 2; i <= n; i++) {\n            // p = q * i + r\n        \
    \    // - q / r = 1 / i (mod p)\n            ret[i] = (-ret[mod % i]) * (mod /\
    \ i);\n        }\n        for (int i = 0; i < n; i++) {\n            ret[i + 1]\
    \ *= (*this)[i];\n        }\n        return ret;\n    }\n\n    FPS inplace_int()\
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
    #line 1 \"fps/power_projection.hpp\"\n\n\n\n#line 5 \"fps/power_projection.hpp\"\
    \n\n// [X ^ n] f(X) ^ i g(X)  enumerate for i = 0, ... , m \n// n = \\deg f -\
    \ 1\ntemplate <class mint>\nFormalPowerSeries<mint> power_projection(FormalPowerSeries<mint>\
    \ f,\n                                        FormalPowerSeries<mint> g = {1},\n\
    \                                        int m = -1) {\n    if (f.empty() || g.empty())\
    \ return {};\n    int n = int(size(f)) - 1, k = 1;\n    g.resize(n + 1);\n   \
    \ if (m == -1) m = n;\n    int h = 1;\n    while (h < n + 1) h <<= 1;\n    FormalPowerSeries<mint>\
    \ p((n + 1) * k), q((n + 1) * k),\n        np, nq, buf, buf2;\n    for (int i\
    \ = 0; i <= n; i++) p[i * k] = g[i];\n    for (int i = 0; i <= n; i++) q[i * k]\
    \ = -f[i];\n    q[0] += 1;\n    mint inv2 = mint(2).inv();\n    mint invk = mint(k).inv();\n\
    \    mint invh = mint(h).inv();\n    while (n) {\n        mint w = mint(FormalPowerSeries<mint>::but_pr()).\n\
    \            pow((mint::getmod() - 1) / (k << 1));\n        mint invw = w.inv();\n\
    \n        buf2.resize(k);\n        auto db = [&]() -> void {\n            copy(begin(buf),\
    \ end(buf), begin(buf2));\n            buf2.ibut();\n            for (int i =\
    \ 0; i < k; i++) buf2[i] *= invk;\n            mint r = 1;\n            for (int\
    \ i = 0; i < k; i++) {\n                buf2[i] *= r;\n                r *= w;\n\
    \            }\n            buf2.but();\n            copy(begin(buf2), end(buf2),\
    \ back_inserter(buf));\n        };\n\n        np.clear(), nq.clear();\n      \
    \  for (int i = 0; i <= n; i++) {\n            buf.resize(k);\n            copy(begin(p)\
    \ + i * k, begin(p) + (i + 1) * k, begin(buf));\n            db();\n         \
    \   copy(begin(buf), end(buf), back_inserter(np));\n\n            buf.resize(k);\n\
    \            copy(begin(q) + i * k, begin(q) + (i + 1) * k, begin(buf));\n   \
    \         if (i == 0) {\n                for (int j = 0; j < k; j++) buf[j] -=\
    \ 1;\n                db();\n                for (int j = 0; j < k; j++) buf[j]\
    \ += 1;\n                for (int j = 0; j < k; j++) buf[k + j] -= 1; \n     \
    \       }\n            else db();\n\n            copy(begin(buf), end(buf), back_inserter(nq));\n\
    \        }\n\n        np.resize(2 * h * 2 * k);\n        nq.resize(2 * h * 2 *\
    \ k);\n        FormalPowerSeries<mint> p1(2 * h), q1(2 * h);\n\n        w = mint(FormalPowerSeries<mint>::but_pr()).\n\
    \            pow((mint::getmod() - 1) / (h << 1));\n        invw = w.inv();\n\
    \        vector<int> btr;\n        if (n & 1) {\n            btr.resize(h);\n\
    \            for (int i = 0, lg = __builtin_ctz(h); i < h; i++) {\n          \
    \      btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (lg - 1));\n            }\n \
    \       }\n\n        for (int j = 0; j < 2 * k; j++) {\n            p1.assign(2\
    \ * h, 0);\n            q1.assign(2 * h, 0);\n            for (int i = 0; i <\
    \ h; i++) {\n                p1[i] = np[i * 2 * k + j];\n                q1[i]\
    \ = nq[i * 2 * k + j];\n            }\n            p1.but(); q1.but();\n     \
    \       for (int i = 0; i < 2 * h; i += 2) swap(q1[i], q1[i + 1]);\n         \
    \   for (int i = 0; i < 2 * h; i++) p1[i] *= q1[i];\n            for (int i =\
    \ 0; i < h; i++) q1[i] = q1[i * 2] * q1[i * 2 + 1];\n            if (n & 1) {\n\
    \                mint c = inv2;\n                buf.resize(h);\n            \
    \    for (int i : btr) {\n                    buf[i] = (p1[i * 2] - p1[i * 2 +\
    \ 1]) * c;\n                    c *= invw;\n                }\n              \
    \  swap(p1, buf);\n            }\n            else {\n                for (int\
    \ i = 0; i < h; i++) p1[i] =\n                    (p1[i * 2] + p1[i * 2 + 1])\
    \ * inv2;\n            }\n            p1.resize(h); q1.resize(h);\n          \
    \  p1.ibut(); q1.ibut();\n            for (int i = 0; i < h; i++) { p1[i] *= invh;\
    \ q1[i] *= invh; }\n            for (int i = 0; i < h; i++) {\n              \
    \  np[i * 2 * k + j] = p1[i];\n                nq[i * 2 * k + j] = q1[i];\n  \
    \          }\n        }\n\n        np.resize((n / 2 + 1) * 2 * k);\n        nq.resize((n\
    \ / 2 + 1) * 2 * k);\n        swap(p, np); swap(q, nq);\n        n >>= 1, h >>=\
    \ 1, k <<= 1;\n        invh *= 2, invk *= inv2;\n    }\n\n    FormalPowerSeries<mint>\
    \ s(begin(p), begin(p) + k);\n    FormalPowerSeries<mint> t(begin(q), begin(q)\
    \ + k);\n    s.ibut(); t.ibut();\n    for (int i = 0; i < k; i++) { s[i] *= invk;\
    \ t[i] *= invk; }\n    t[0] -= 1;\n    if (f[0] == mint(0)) return s.rev().pre(m\
    \ + 1);\n    return (s.rev() * (t + (FormalPowerSeries<mint>{1} << k)).\n    \
    \       rev().inv(m + 1)).pre(m + 1);\n}\n\n\n#line 6 \"fps/fps_com_inv.hpp\"\n\
    \n// calculate f ^ {-1} (X)  mod X ^ deg\ntemplate <class mint>\nFormalPowerSeries<mint>\
    \ compositionnal_inv(FormalPowerSeries<mint> f,\n                            \
    \               int deg = -1) {\n    assert(int(size(f)) >= 2 and f[1] != 0);\n\
    \    if (deg == -1) deg = int(size(f));\n    if (deg < 2) return FormalPowerSeries<mint>{0,\
    \ f[1].inv()}.pre(deg);\n    int n = deg - 1;\n    FormalPowerSeries<mint> h =\
    \ power_projection(f) * n;\n\n    for (int k = 1; k <= n; k++) h[k] /= k;\n  \
    \  h.inplace_rev();\n    h *= h[0].inv();\n    FormalPowerSeries<mint> g = (h.log()\
    \ * mint(-n).inv()).exp();\n    g *= f[1].inv();\n    return (g << 1).pre(deg);\n\
    }\n\n\n"
  code: "#ifndef FPS_COMPOSITION_INVERSION_HPP\n#define FPS_COMPOSITION_INVERSION_HPP\
    \ 1\n\n#include \"fps.hpp\"\n#include \"power_projection.hpp\"\n\n// calculate\
    \ f ^ {-1} (X)  mod X ^ deg\ntemplate <class mint>\nFormalPowerSeries<mint> compositionnal_inv(FormalPowerSeries<mint>\
    \ f,\n                                           int deg = -1) {\n    assert(int(size(f))\
    \ >= 2 and f[1] != 0);\n    if (deg == -1) deg = int(size(f));\n    if (deg <\
    \ 2) return FormalPowerSeries<mint>{0, f[1].inv()}.pre(deg);\n    int n = deg\
    \ - 1;\n    FormalPowerSeries<mint> h = power_projection(f) * n;\n\n    for (int\
    \ k = 1; k <= n; k++) h[k] /= k;\n    h.inplace_rev();\n    h *= h[0].inv();\n\
    \    FormalPowerSeries<mint> g = (h.log() * mint(-n).inv()).exp();\n    g *= f[1].inv();\n\
    \    return (g << 1).pre(deg);\n}\n\n#endif // FPS_COMPOSITION_INVERSION_HPP\n"
  dependsOn:
  - fps/fps.hpp
  - fps/power_projection.hpp
  isVerificationFile: false
  path: fps/fps_com_inv.hpp
  requiredBy: []
  timestamp: '2024-05-10 04:03:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/fps_com_inv.hpp
layout: document
redirect_from:
- /library/fps/fps_com_inv.hpp
- /library/fps/fps_com_inv.hpp.html
title: fps/fps_com_inv.hpp
---
