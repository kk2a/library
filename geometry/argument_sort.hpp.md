---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: point.hpp
      icon: LIBRARY_ALL_AC
      path: geometry/point.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: arg_sort.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_geometry/arg_sort.test.cpp
    type: Verified with
  dependsOn:
  - geometry/point.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_GEOMETRY_ARGUMENT_SORT_HPP\n#define KK2_GEOMETRY_ARGUMENT_SORT_HPP\
      \ 1\n\n#include <algorithm>\n#include <vector>\n\n#include \"point.hpp\"\n\n\
      namespace kk2 {\n\ntemplate <class T> struct ArgumentSort {\n    using point\
      \ = Point<T>;\n    point O;\n\n    ArgumentSort(const point &O_ = point()) :\
      \ O(O_) {}\n\n    // p - O = (x, y)\n    // 1 : y < 0\n    // 2 : y >= 0 and\
      \ x >= 0\n    // 3 : otherwise\n    int location(const point &p) {\n       \
      \ point q = p - O;\n        return q.y < 0 ? 1 : q.x >= 0 ? 2 : 3;\n    }\n\n\
      \    bool cmp(const point &a, const point &b) {\n        int loc_a = location(a),\
      \ loc_b = location(b);\n        T cr = cross(a, b, O);\n        return loc_a\
      \ != loc_b ? loc_a < loc_b : cr == 0 ? norm(a, O) < norm(b, O) : cr > 0;\n \
      \   }\n\n    void argument_sort(std::vector<point> &ps) {\n        std::sort(\n\
      \            ps.begin(), ps.end(), [this](auto &&a, auto &&b) -> bool { return\
      \ this->cmp(a, b); });\n    }\n\n    template <class Iterator>\n    Iterator\
      \ min_up_argument(Iterator first, Iterator last, const point &p) {\n       \
      \ return std::lower_bound(\n            first, last, p, [this](auto &&a, auto\
      \ &&b) -> bool { return this->cmp(a, b); });\n    }\n};\n\n} // namespace kk2\n\
      \n#endif // KK2_GEOMETRY_ARGUMENT_SORT_HPP\n"
    name: default
  - code: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/resolver.py\"\
      , line 290, in resolve\n    bundled_code = language.bundle(path, basedir=basedir)\n\
      \                   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/languages/cplusplus.py\"\
      , line 243, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/languages/cplusplus_bundle.py\"\
      , line 478, in update\n    self.update(\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/languages/cplusplus_bundle.py\"\
      , line 354, in update\n    raise BundleErrorAt(\ncompetitive_verifier.oj.languages.cplusplus_bundle.BundleErrorAt:\
      \ geometry/point.hpp: line 4: #pragma once found in an include guard with #ifndef\n"
    name: bundle error
  isFailed: false
  isVerificationFile: false
  path: geometry/argument_sort.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_geometry/arg_sort.test.cpp
documentation_of: geometry/argument_sort.hpp
layout: document
---
