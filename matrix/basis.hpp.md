---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: matrix/matrix_field.hpp
    title: matrix/matrix_field.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: matrix/frobenius_form.hpp
    title: matrix/frobenius_form.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef MATRIX_BASIS_HPP\n#define MATRIX_BASIS_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <optional>\n#include <vector>\n\n#include \"matrix_field.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace linear_algebra {\n\ntemplate <class Matrix, class\
    \ Field> struct Basis_base {\n    struct RowBasicTransform {\n        int type;\n\
    \        int i, j;\n        Field t, t_inv;\n\n        RowBasicTransform() = default;\n\
    \n        // type = 0: row(i) <- row(i) * t\n        //           t_inv = 1 /\
    \ t\n        // type = 1: row(j) <- row(j) + row(i) * t\n        //          \
    \ t_inv = -t\n        // type = 2: swap(row(i), row(j))\n        //          \
    \ t_inv = unused\n        RowBasicTransform(int type_, int i_, int j_, Field t_,\
    \ Field t_inv_)\n            : type(type_),\n              i(i_),\n          \
    \    j(j_),\n              t(t_),\n              t_inv(t_inv_) {}\n\n        void\
    \ transform(Matrix &mat, bool inv = false) const {\n            if (type == 0)\
    \ {\n                if (inv) {\n                    mat[i][0] *= t_inv;\n   \
    \             } else {\n                    mat[i][0] *= t;\n                }\n\
    \            } else if (type == 1) {\n                if (inv) {\n           \
    \         mat[j][0] += mat[i][0] * t_inv;\n                } else {\n        \
    \            mat[j][0] += mat[i][0] * t;\n                }\n            } else\
    \ if (type == 2) {\n                std::swap(mat[i], mat[j]);\n            }\n\
    \        }\n    };\n\n    int h, rank;\n\n    struct SnapShot {\n        int rank,\
    \ hist_size;\n    };\n\n    std::vector<RowBasicTransform> hist;\n    std::vector<SnapShot>\
    \ snaps;\n\n    BasisField() = default;\n\n    BasisField(int h_) : h(h_), rank(0)\
    \ {}\n\n    Matrix &sweep(Matrix &vec) const {\n        for (auto &&t : hist)\
    \ t.transform(vec);\n        return vec;\n    }\n\n    // vec is column vector\n\
    \    bool is_linearly_independent(const Matrix &vec) const {\n        assert(vec.get_h()\
    \ == h);\n        assert(vec.get_w() == 1);\n        if (rank == h) return false;\n\
    \n        Matrix tmp(vec);\n        sweep(tmp);\n        for (int i = rank; i\
    \ < h; ++i) {\n            if (tmp[i][0] != Field(0)) return true;\n        }\n\
    \        return false;\n    }\n\n    // vec is column vector\n    // if vec is\
    \ not linearly independent with current basis, return coordinate vector\n    //\
    \ else return std::nullopt\n    std::optional<Matrix> add(const Matrix &vec) {\n\
    \        assert(vec.get_h() == h);\n        assert(vec.get_w() == 1);\n\n    \
    \    Matrix tmp(vec);\n        sweep(tmp);\n\n        int pivot = -1;\n      \
    \  for (int i = rank; i < h; ++i) {\n            if (tmp[i][0] != Field(0)) {\n\
    \                pivot = i;\n                break;\n            }\n        }\n\
    \        if (pivot == -1) return tmp;\n\n        if (pivot != rank) {\n      \
    \      std::swap(tmp[pivot], tmp[rank]);\n            hist.emplace_back(2, rank,\
    \ pivot, Field(1), Field(1));\n        }\n        if (tmp[rank][0] != Field(1))\
    \ {\n            hist.emplace_back(0, rank, -1, tmp[rank][0].inv(), tmp[rank][0]);\n\
    \            tmp[rank][0] = Field(1);\n        }\n        for (int i = 0; i <\
    \ h; ++i) {\n            if (i == rank) continue;\n            Field t = -tmp[i][0];\n\
    \            if (t == Field(0)) continue;\n            hist.emplace_back(1, rank,\
    \ i, t, -t);\n        }\n        ++rank;\n        return {};\n    }\n\n    Matrix\
    \ get_coordinate(const Matrix &vec) const {\n        assert(vec.get_h() == h);\n\
    \        assert(vec.get_w() == 1);\n        Matrix tmp(vec);\n        sweep(tmp);\n\
    \        for (int i = rank; i < h; ++i) assert(tmp[i][0] == Field(0));\n     \
    \   return res;\n    }\n\n    void snapshot() { snaps.emplace_back(rank, (int)hist.size());\
    \ }\n\n    void rollback() {\n        if (snaps.empty()) return;\n        auto\
    \ snap = snaps.back();\n        snaps.pop_back();\n        rank = snap.rank;\n\
    \        hist.resize(snap.hist_size);\n    }\n};\n\n} // namespace linear_algebra\n\
    \ntemplate <class Matrix>\nusing BasisMatrix = linear_algebra::Basis_base<Matrix,\
    \ typename Matrix::value_type>;\n\n} // namespace kk2\n\n#endif // MATRIX_BASIS_HPP\n"
  dependsOn:
  - matrix/matrix_field.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: matrix/basis.hpp
  requiredBy:
  - matrix/frobenius_form.hpp
  timestamp: '2024-12-08 12:34:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/basis.hpp
layout: document
redirect_from:
- /library/matrix/basis.hpp
- /library/matrix/basis.hpp.html
title: matrix/basis.hpp
---
