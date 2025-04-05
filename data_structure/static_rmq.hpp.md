---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
  - icon: ':question:'
    path: math/monoid/min.hpp
    title: math/monoid/min.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/tree/euler_tour.hpp
    title: graph/tree/euler_tour.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_ds/ds_static_rmq.test.cpp
    title: verify/yosupo_ds/ds_static_rmq.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
  code: '#ifndef KK2_DATA_STRUCTURE_STATIC_RMQ_HPP

    #define KK2_DATA_STRUCTURE_STATIC_RMQ_HPP 1


    #include "../math/monoid/min.hpp"

    #include "sparse_table.hpp"


    namespace kk2 {


    template <class S> using StaticRMQ = SparseTableS<monoid::Min<S>>;


    } // namespace kk2


    #endif // KK2_DATA_STRUCTURE_STATIC_RMQ_HPP

    '
  dependsOn:
  - math/monoid/min.hpp
  - type_traits/io.hpp
  - data_structure/sparse_table.hpp
  isVerificationFile: false
  path: data_structure/static_rmq.hpp
  requiredBy:
  - graph/tree/euler_tour.hpp
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_ds/ds_static_rmq.test.cpp
documentation_of: data_structure/static_rmq.hpp
layout: document
redirect_from:
- /library/data_structure/static_rmq.hpp
- /library/data_structure/static_rmq.hpp.html
title: data_structure/static_rmq.hpp
---
