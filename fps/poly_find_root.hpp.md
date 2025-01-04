---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: fps/mod_pow.hpp
    title: fps/mod_pow.hpp
  - icon: ':x:'
    path: fps/poly_gcd.hpp
    title: fps/poly_gcd.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/seed.hpp
    title: random/seed.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_fps/poly_root_finding.test.cpp
    title: verify/yosupo_fps/poly_root_finding.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/poly_find_root.hpp\"\n\n\n\n#include <vector>\n\n#line\
    \ 1 \"random/gen.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <numeric>\n#include <unordered_set>\n#line 9 \"random/gen.hpp\"\n\n#line 1 \"\
    random/seed.hpp\"\n\n\n\n#include <chrono>\n\nnamespace kk2 {\n\nnamespace random\
    \ {\n\nusing u64 = unsigned long long;\n\nu64 non_deterministic_seed() {\n   \
    \ u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n         \
    \          std::chrono::high_resolution_clock::now().time_since_epoch())\n   \
    \                .count();\n    seed ^= reinterpret_cast<u64>(&seed);\n    seed\
    \ ^= seed << 5;\n    seed ^= seed >> 41;\n    seed ^= seed << 20;\n    return\
    \ seed;\n}\n\nu64 deterministic_seed() {\n    return 5801799128519729247ull;\n\
    }\n\nu64 seed() {\n#if defined(KK2) && !defined(KK2_RANDOM_NON_DETERMINISTIC)\n\
    \    return deterministic_seed();\n#else\n    return non_deterministic_seed();\n\
    #endif\n}\n\n} // namespace random\n\n} // namespace kk2\n\n\n#line 11 \"random/gen.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace random {\n\nusing i64 = long long;\nusing u64\
    \ = unsigned long long;\n\nu64 xorshift128plus(u64 &x, u64 &y) {\n    u64 t =\
    \ x;\n    t ^= t << 23;\n    t ^= t >> 17;\n    t ^= y ^ (y >> 26);\n    x = y;\n\
    \    y = t;\n    return x + y;\n}\n\nconstexpr int iterations = 100;\n\nvoid warm_up(u64\
    \ &x, u64 &y) {\n    for (int i = 0; i < iterations; i++) xorshift128plus(x, y);\n\
    }\n\nu64 rng() {\n    static bool first = true;\n    static u64 x = seed(), y\
    \ = seed();\n    if (first) {\n        warm_up(x, y);\n        first = false;\n\
    \    }\n    return xorshift128plus(x, y);\n}\n\n// [l, r)\ni64 rng(i64 l, i64\
    \ r) {\n    assert(l < r);\n    return l + rng() % (r - l);\n}\n\n// [l, r)\n\
    template <class T>\nstd::vector<T> random_vector(int n, T l, T r) {\n    std::vector<T>\
    \ res(n);\n    for (int i = 0; i < n; i++) res[i] = rng(l, r);\n    return res;\n\
    }\n\n// [l, r)\nstd::vector<i64> distinct_rng(i64 l, i64 r, i64 n) {\n    assert(l\
    \ < r and n <= r - l);\n    std::unordered_set<i64> st;\n    for (i64 i = n; i;\
    \ --i) {\n        i64 m = rng(l, r + 1 - i);\n        if (st.find(m) != st.end())\
    \ m = r - i;\n        st.insert(m);\n    }\n    std::vector<i64> res(st.begin(),\
    \ st.end());\n    std::sort(res.begin(), res.end());\n    return res;\n}\n\ntemplate\
    \ <class Iter> void shuffle(Iter first, Iter last) {\n    if (first == last) return;\n\
    \    int len = 1;\n    for (auto it = first + 1; it != last; ++it) {\n       \
    \ len++;\n        int j = rng(0, len);\n        if (j != len - 1) std::iter_swap(first\
    \ + j, it);\n    }\n}\n\ntemplate <class T> std::vector<T> perm(int n) {\n   \
    \ std::vector<T> res(n);\n    std::iota(res.begin(), res.end(), T(0));\n    shuffle(res.begin(),\
    \ res.end());\n    return res;\n}\n\ntemplate <class T> std::vector<T> choices(int\
    \ l, int r, int k) {\n    assert(l < r and k <= r - l);\n    std::vector<T> res(r\
    \ - l);\n    std::iota(res.begin(), res.end(), T(l));\n    shuffle(res.begin(),\
    \ res.end());\n    res.resize(k);\n    return res;\n}\n\n} // namespace random\n\
    \n} // namespace kk2\n\n\n#line 1 \"fps/mod_pow.hpp\"\n\n\n\n#line 5 \"fps/mod_pow.hpp\"\
    \n\nnamespace kk2 {\n\n// return f ^ k mod g\ntemplate <class FPS, class mint\
    \ = typename FPS::value_type, class T>\nFPS mod_pow(T k, const FPS &f, const FPS\
    \ &g) {\n    // assert(!is_signed_v<T> || k >= 0);\n    assert(!g.empty());\n\n\
    \    auto inv = g.rev().inv();\n    auto quo = [&](const FPS &poly) {\n      \
    \  if (poly.size() < g.size()) return FPS{};\n        int n = poly.size() - g.size()\
    \ + 1;\n        return (poly.rev().pre(n) * inv.pre(n)).pre(n).rev();\n    };\n\
    \    FPS res{1}, b(f);\n    while (k) {\n        if (k & 1) {\n            res\
    \ *= b;\n            res -= quo(res) * g;\n            res.shrink();\n       \
    \ }\n        b *= b;\n        b -= quo(b) * g;\n        b.shrink();\n        k\
    \ >>= 1;\n    }\n    return res;\n}\n\n} // namespace kk2\n\n\n#line 1 \"fps/poly_gcd.hpp\"\
    \n\n\n\n#line 5 \"fps/poly_gcd.hpp\"\n#include <array>\n#include <utility>\n\n\
    namespace kk2 {\n\nnamespace poly_gcd_impl {\n\ntemplate <class FPS> using Vec\
    \ = std::array<FPS, 2>;\n\ntemplate <class FPS> struct mat_poly {\n    FPS a00,\
    \ a01, a10, a11;\n\n    mat_poly() = default;\n\n    mat_poly(FPS a00_, FPS a01_,\
    \ FPS a10_, FPS a11_) : a00(a00_), a01(a01_), a10(a10_), a11(a11_) {}\n\n    mat_poly\
    \ &operator*=(const mat_poly &r) {\n        FPS A00 = a00 * r.a00 + a01 * r.a10;\n\
    \        FPS A01 = a00 * r.a01 + a01 * r.a11;\n        FPS A10 = a10 * r.a00 +\
    \ a11 * r.a10;\n        FPS A11 = a10 * r.a01 + a11 * r.a11;\n        A00.shrink();\n\
    \        A01.shrink();\n        A10.shrink();\n        A11.shrink();\n       \
    \ std::swap(a00, A00);\n        std::swap(a01, A01);\n        std::swap(a10, A10);\n\
    \        std::swap(a11, A11);\n        return *this;\n    }\n\n    static mat_poly\
    \ identity() { return mat_poly(FPS{1}, FPS(), FPS(), FPS{1}); }\n\n    mat_poly\
    \ operator*(const mat_poly &r) const { return mat_poly(*this) *= r; }\n};\n\n\
    template <class FPS> Vec<FPS> operator*(const mat_poly<FPS> &a, const Vec<FPS>\
    \ &b) {\n    FPS x0 = a.a00 * b[0] + a.a01 * b[1];\n    FPS x1 = a.a10 * b[0]\
    \ + a.a11 * b[1];\n    x0.shrink();\n    x1.shrink();\n    return {x0, x1};\n\
    };\n\ntemplate <class FPS> void inner_naive_gcd(mat_poly<FPS> &a, Vec<FPS> &b)\
    \ {\n    FPS quo = b[0] / b[1];\n    FPS rem = b[0] - quo * b[1];\n    FPS x10\
    \ = a.a00 - quo * a.a10;\n    FPS x11 = a.a01 - quo * a.a11;\n    rem.shrink();\n\
    \    x10.shrink();\n    x11.shrink();\n    std::swap(x10, a.a10);\n    std::swap(x11,\
    \ a.a11);\n    std::swap(x10, a.a00);\n    std::swap(x11, a.a01);\n    b = {b[1],\
    \ rem};\n}\n\ntemplate <class FPS> mat_poly<FPS> inner_half_gcd(Vec<FPS> b) {\n\
    \    int n = (int)b[0].size(), m = (int)b[1].size();\n    int k = (n + 1) >> 1;\n\
    \    if (m <= k) return mat_poly<FPS>::identity();\n    mat_poly<FPS> m1 = inner_half_gcd(Vec<FPS>{b[0]\
    \ >> k, b[1] >> k});\n    b = m1 * b;\n    if ((int)b[1].size() <= k) return m1;\n\
    \    inner_naive_gcd(m1, b);\n    if ((int)b[1].size() <= k) return m1;\n    int\
    \ l = (int)b[0].size() - 1;\n    int j = 2 * k - l;\n    b[0] = b[0] >> j;\n \
    \   b[1] = b[1] >> j;\n    return inner_half_gcd(b) * m1;\n}\n\ntemplate <class\
    \ FPS> mat_poly<FPS> inner_poly_gcd(const FPS &a, const FPS &b) {\n    Vec<FPS>\
    \ c{a, b};\n    c[0].shrink();\n    c[1].shrink();\n    int n = (int)c[0].size(),\
    \ m = (int)c[1].size();\n    if (n < m) {\n        mat_poly<FPS> ret = inner_poly_gcd(c[1],\
    \ c[0]);\n        std::swap(ret.a00, ret.a01);\n        std::swap(ret.a10, ret.a11);\n\
    \        return ret;\n    }\n\n    mat_poly<FPS> res = mat_poly<FPS>::identity();\n\
    \    while (1) {\n        mat_poly<FPS> m1 = inner_half_gcd(c);\n        c = m1\
    \ * c;\n        if (c[1].empty()) return m1 * res;\n        inner_naive_gcd(m1,\
    \ c);\n        if (c[1].empty()) return m1 * res;\n        res = m1 * res;\n \
    \   }\n}\n\ntemplate <class FPS> FPS poly_gcd(FPS a, FPS b) {\n    Vec<FPS> c{a,\
    \ b};\n    mat_poly<FPS> m = inner_poly_gcd(a, b);\n    c = m * c;\n    if (!c[0].empty())\
    \ {\n        auto coeff = c[0].back().inv();\n        for (auto &x : c[0]) x *=\
    \ coeff;\n    }\n    return c[0];\n}\n\n// f ^ {-1} mod g\ntemplate <class FPS>\
    \ std::pair<bool, FPS> poly_inv(const FPS &f, const FPS &g) {\n    Vec<FPS> c{f,\
    \ g};\n    mat_poly<FPS> m = inner_poly_gcd(f, g);\n    FPS gcd_ = (m * c)[0];\n\
    \    if (gcd_.size() != 1) return {0, FPS()};\n    Vec<FPS> x{FPS{1}, g};\n  \
    \  return {1, ((m * x)[0] % g) * gcd_[0].inv()};\n}\n\n} // namespace poly_gcd_impl\n\
    \nusing poly_gcd_impl::poly_gcd;\nusing poly_gcd_impl::poly_inv;\n\n} // namespace\
    \ kk2\n\n\n#line 9 \"fps/poly_find_root.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
    \ FPS, class mint = typename FPS::value_type>\nstd::vector<mint> find_root(const\
    \ FPS &f) {\n    long long p = mint::getmod();\n    std::vector<mint> res;\n \
    \   if (p == 2) {\n        for (int i = 0; i < 2; i++) {\n            if (f.eval(mint(i))\
    \ == mint(0)) { res.push_back(mint(i)); }\n        }\n        return res;\n  \
    \  }\n\n    std::vector<FPS> fs;\n    fs.push_back(poly_gcd(mod_pow(p, FPS{0,\
    \ 1}, f) - FPS{0, 1}, f));\n    while (!fs.empty()) {\n        auto g = fs.back();\n\
    \        fs.pop_back();\n        if (g.size() == 2) res.push_back(-g[0]);\n  \
    \      if (g.size() <= 2) continue;\n        FPS s = FPS{random::rng(0, p), 1};\n\
    \        FPS t = poly_gcd(mod_pow((p - 1) / 2, s, g) - FPS{1}, g);\n        fs.push_back(t);\n\
    \        if (g.size() != t.size()) fs.push_back(g / t);\n    }\n    return res;\n\
    }\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_FPS_POLY_FIND_ROOT_HPP\n#define KK2_FPS_POLY_FIND_ROOT_HPP 1\n\
    \n#include <vector>\n\n#include \"../random/gen.hpp\"\n#include \"mod_pow.hpp\"\
    \n#include \"poly_gcd.hpp\"\n\nnamespace kk2 {\n\ntemplate <class FPS, class mint\
    \ = typename FPS::value_type>\nstd::vector<mint> find_root(const FPS &f) {\n \
    \   long long p = mint::getmod();\n    std::vector<mint> res;\n    if (p == 2)\
    \ {\n        for (int i = 0; i < 2; i++) {\n            if (f.eval(mint(i)) ==\
    \ mint(0)) { res.push_back(mint(i)); }\n        }\n        return res;\n    }\n\
    \n    std::vector<FPS> fs;\n    fs.push_back(poly_gcd(mod_pow(p, FPS{0, 1}, f)\
    \ - FPS{0, 1}, f));\n    while (!fs.empty()) {\n        auto g = fs.back();\n\
    \        fs.pop_back();\n        if (g.size() == 2) res.push_back(-g[0]);\n  \
    \      if (g.size() <= 2) continue;\n        FPS s = FPS{random::rng(0, p), 1};\n\
    \        FPS t = poly_gcd(mod_pow((p - 1) / 2, s, g) - FPS{1}, g);\n        fs.push_back(t);\n\
    \        if (g.size() != t.size()) fs.push_back(g / t);\n    }\n    return res;\n\
    }\n\n} // namespace kk2\n\n#endif // KK2_FPS_POLY_FIND_ROOT_HPP\n"
  dependsOn:
  - random/gen.hpp
  - random/seed.hpp
  - fps/mod_pow.hpp
  - fps/poly_gcd.hpp
  isVerificationFile: false
  path: fps/poly_find_root.hpp
  requiredBy: []
  timestamp: '2025-01-05 07:17:08+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_fps/poly_root_finding.test.cpp
documentation_of: fps/poly_find_root.hpp
layout: document
redirect_from:
- /library/fps/poly_find_root.hpp
- /library/fps/poly_find_root.hpp.html
title: fps/poly_find_root.hpp
---
