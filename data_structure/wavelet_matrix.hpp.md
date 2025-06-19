---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/bit_vector.hpp
    title: data_structure/bit_vector.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/wavelet_matrix.test.cpp
    title: verify/unit_test/wavelet_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_DATA_STRUCTURE_WAVELET_MATRIX_HPP\n#define KK2_DATA_STRUCTURE_WAVELET_MATRIX_HPP\
    \ 1\n\n#include <algorithm>\n#include <vector>\n\n#include \"../bit/bitcount.hpp\"\
    \n#include \"bit_vector.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename T> struct\
    \ WaveletMatrix {\n    int n, lg;\n    std::vector<T> a;\n    std::vector<BitVector>\
    \ mat;\n    bool built = false;\n\n    WaveletMatrix() = default;\n\n    WaveletMatrix(int\
    \ n_) : n(n_), a(n_) {}\n\n    WaveletMatrix(const std::vector<T> &a_) : n(a_.size()),\
    \ a(a_) { build(); }\n\n    void build() {\n        built = true;\n        lg\
    \ = 0;\n        T mx = *std::max_element(a.begin(), a.end());\n        if (mx\
    \ <= 0) mx = 1;\n        lg = msb(mx) + 1;\n        mat.resize(lg, BitVector(n));\n\
    \        std::vector<T> now(a), nxt(n);\n        for (int i = lg - 1; i >= 0;\
    \ --i) {\n            BitVector &bv = mat[i];\n            for (int j = 0; j <\
    \ n; ++j) {\n                if ((now[j] >> i) & 1) bv.set(j);\n            }\n\
    \            bv.build();\n            int one = bv.zeros, zero = 0;\n        \
    \    for (int j = 0; j < n; ++j) {\n                if ((now[j] >> i) & 1) {\n\
    \                    nxt[one++] = now[j];\n                } else {\n        \
    \            nxt[zero++] = now[j];\n                }\n            }\n       \
    \     std::swap(now, nxt);\n        }\n    }\n\n    void set(int i, T x) {\n \
    \       assert(0 <= i && i < n);\n        assert(x >= 0);\n        assert(!built);\n\
    \        a[i] = x;\n    }\n\n    T access(int k) const {\n        assert(0 <=\
    \ k && k < n);\n        return a[k];\n    }\n\n    int rank(T b, int k) {\n  \
    \      assert(0 <= k && k <= n);\n        int l = 0, r = k;\n        for (int\
    \ i = lg - 1; i >= 0; --i) {\n            r = (b >> i & 1) ? mat[i].rank1(r) +\
    \ mat[i].zeros : mat[i].rank0(r);\n            l = (b >> i & 1) ? mat[i].rank1(l)\
    \ + mat[i].zeros : mat[i].rank0(l);\n        }\n        return r - l;\n    }\n\
    \n    int select(T b, int k) {\n        assert(0 <= k && k < n);\n        int\
    \ l = 0;\n        for (int i = lg - 1; i >= 0; --i)\n            l = (b >> i &\
    \ 1) ? mat[i].rank1(l) + mat[i].zeros : mat[i].rank0(l);\n        k += l;\n  \
    \      for (int i = 0; i < lg; ++i) {\n            k = (b >> i & 1) ? mat[i].select1(k\
    \ - mat[i].zeros) : mat[i].select0(k);\n            if (k == -1) return -1;\n\
    \        }\n        return k;\n    }\n\n    T kth_smallest(int l, int r, int k)\
    \ const {\n        assert(0 <= l && l <= r && r <= n);\n        assert(r - l >\
    \ k);\n        T res = 0;\n        for (int i = lg - 1; i >= 0; --i) {\n     \
    \       int ll = mat[i].rank0(l), rr = mat[i].rank0(r);\n            if (k < rr\
    \ - ll) {\n                l = ll, r = rr;\n            } else {\n           \
    \     k -= rr - ll;\n                res |= T(1) << i;\n                l += mat[i].zeros\
    \ - ll;\n                r += mat[i].zeros - rr;\n            }\n        }\n \
    \       return res;\n    }\n\n    T kth_largest(int l, int r, int k) const {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        assert(r - l > k);\n   \
    \     return kth_smallest(l, r, r - l - k - 1);\n    }\n\n    int range_freq(int\
    \ l, int r, T upper) const {\n        assert(0 <= l && l <= r && r <= n);\n  \
    \      assert(0 <= upper);\n        if (upper >> lg) return r - l;\n        int\
    \ res = 0;\n        for (int i = lg - 1; i >= 0; --i) {\n            if (upper\
    \ >> i & 1) res += mat[i].rank0(r) - mat[i].rank0(l);\n            l = (upper\
    \ >> i & 1) ? mat[i].rank1(l) + mat[i].zeros : mat[i].rank0(l);\n            r\
    \ = (upper >> i & 1) ? mat[i].rank1(r) + mat[i].zeros : mat[i].rank0(r);\n   \
    \         if (l == r) break;\n        }\n        return res;\n    }\n\n    int\
    \ range_freq(int l, int r, T lower, T upper) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        assert(0 <= lower && lower <= upper);\n        return\
    \ range_freq(l, r, upper) - range_freq(l, r, lower);\n    }\n\n    T max_not_greater(int\
    \ l, int r, T b) {\n        assert(0 <= l && l <= r && r <= n);\n        int count\
    \ = range_freq(l, r, b + 1);\n        return count == 0 ? -1 : kth_smallest(l,\
    \ r, count - 1);\n    }\n\n    T min_not_less(int l, int r, T b) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        int count = range_freq(l, r, b);\n     \
    \   return count == r - l ? -1 : kth_smallest(l, r, count);\n    }\n};\n\n} //\
    \ namespace kk2\n\n\n#endif // KK2_DATA_STRUCTURE_WAVELET_MATRIX_HPP\n"
  dependsOn:
  - bit/bitcount.hpp
  - type_traits/integral.hpp
  - data_structure/bit_vector.hpp
  isVerificationFile: false
  path: data_structure/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2025-04-24 20:44:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/wavelet_matrix.test.cpp
documentation_of: data_structure/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/data_structure/wavelet_matrix.hpp
- /library/data_structure/wavelet_matrix.hpp.html
title: data_structure/wavelet_matrix.hpp
---
