---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.hpp
    title: data_structure/wavelet_matrix.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/bit_vector.test.cpp
    title: verify/unit_test/bit_vector.test.cpp
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
  code: "#ifndef KK2_DATA_STRUCTURE_BIT_VECTOR_HPP\n#define KK2_DATA_STRUCTURE_BIT_VECTOR_HPP\
    \ 1\n\n#include <vector>\n\n#include \"../bit/bitcount.hpp\"\n\nnamespace kk2\
    \ {\n\nstruct BitVector {\n    using u32 = unsigned int;\n    using Uint = unsigned\
    \ long long;\n    static constexpr int B = 64;\n    int n, zeros;\n    std::vector<u32>\
    \ count;\n    std::vector<Uint> bits;\n    BitVector() = default;\n\n    BitVector(int\
    \ n_) : n(n_), count(n_ / B + 1), bits(n_ / B + 1) {}\n\n    inline void set(int\
    \ i) { bits[i / B] |= Uint(1) << (i % B); }\n\n    void build() {\n        for\
    \ (u32 i = 1; i < count.size(); ++i) count[i] = count[i - 1] + popcount(bits[i\
    \ - 1]);\n        zeros = n - rank1(n);\n    }\n\n    inline int get(int i) const\
    \ { return (bits[i / B] >> (i % B)) & 1; }\n\n    inline int rank0(int i) const\
    \ { return i - rank1(i); }\n\n    inline int rank1(int i) const {\n        return\
    \ count[i / B] + popcount(bits[i / B] & ((Uint(1) << (i % B)) - 1));\n    }\n\n\
    \    int select0(int i) const {\n        if (i >= zeros) return -1;\n        int\
    \ lb = 0, ub = n;\n        while (ub - lb > 1) {\n            int mid = (lb +\
    \ ub) / 2;\n            if (rank0(mid) > i) ub = mid;\n            else lb = mid;\n\
    \        }\n        return lb;\n    }\n\n    int select1(int i) const {\n    \
    \    if (i >= n - zeros) return -1;\n        int lb = 0, ub = n;\n        while\
    \ (ub - lb > 1) {\n            int mid = (lb + ub) / 2;\n            if (rank1(mid)\
    \ > i) ub = mid;\n            else lb = mid;\n        }\n        return lb;\n\
    \    }\n};\n\n} // namespace kk2\n\n#endif // KK2_DATA_STRUCTURE_BIT_VECTOR_HPP\n"
  dependsOn:
  - bit/bitcount.hpp
  - type_traits/integral.hpp
  isVerificationFile: false
  path: data_structure/bit_vector.hpp
  requiredBy:
  - data_structure/wavelet_matrix.hpp
  timestamp: '2025-04-05 10:48:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/bit_vector.test.cpp
  - verify/unit_test/wavelet_matrix.test.cpp
documentation_of: data_structure/bit_vector.hpp
layout: document
redirect_from:
- /library/data_structure/bit_vector.hpp
- /library/data_structure/bit_vector.hpp.html
title: data_structure/bit_vector.hpp
---
