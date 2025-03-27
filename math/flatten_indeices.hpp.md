---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/flatten_indeices.hpp\"\n\n\n\n#include <vector>\n\n\
    namespace kk2 {\n\nstruct FlattenIndices {\n  private:\n    std::vector<int> _inner_dims;\n\
    \n  public:\n    FlattenIndices(const std::vector<int> &dims) {\n        _inner_dims.resize(dims.size()\
    \ + 1);\n        _inner_dims[0] = 1;\n        for (unsigned int i = 1; i <= dims.size();\
    \ ++i)\n            _inner_dims[i] = _inner_dims[i - 1] * dims[i - 1];\n    }\n\
    \n    int operator()(const std::vector<int> &indices) const {\n        int res\
    \ = 0;\n        for (unsigned int i = 0; i < indices.size(); ++i) res += indices[i]\
    \ * _inner_dims[i];\n        return res;\n    }\n\n    std::vector<int> operator()(int\
    \ index) const {\n        std::vector<int> res(_inner_dims.size() - 1);\n    \
    \    for (unsigned int i = 0; i < res.size(); ++i)\n            res[i] = index\
    \ / _inner_dims[i] % _inner_dims[i + 1];\n\n        return res;\n    }\n\n   \
    \ int next(int index, unsigned int i) const {\n        assert(i < _inner_dims.size()\
    \ - 1);\n        if (index % _inner_dims[i + 1] / _inner_dims[i] == _inner_dims[i\
    \ + 1] / _inner_dims[i] - 1)\n            return -1;\n        return index + _inner_dims[i];\n\
    \    }\n\n    int prev(int index, unsigned int i) const {\n        assert(i <\
    \ _inner_dims.size() - 1);\n        if (index % _inner_dims[i + 1] / _inner_dims[i]\
    \ == 0) return -1;\n        return index - _inner_dims[i];\n    }\n\n    int size()\
    \ const { return _inner_dims.back(); }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_FLATTEN_INDICES_HPP\n#define KK2_MATH_FLATTEN_INDICES_HPP\
    \ 1\n\n#include <vector>\n\nnamespace kk2 {\n\nstruct FlattenIndices {\n  private:\n\
    \    std::vector<int> _inner_dims;\n\n  public:\n    FlattenIndices(const std::vector<int>\
    \ &dims) {\n        _inner_dims.resize(dims.size() + 1);\n        _inner_dims[0]\
    \ = 1;\n        for (unsigned int i = 1; i <= dims.size(); ++i)\n            _inner_dims[i]\
    \ = _inner_dims[i - 1] * dims[i - 1];\n    }\n\n    int operator()(const std::vector<int>\
    \ &indices) const {\n        int res = 0;\n        for (unsigned int i = 0; i\
    \ < indices.size(); ++i) res += indices[i] * _inner_dims[i];\n        return res;\n\
    \    }\n\n    std::vector<int> operator()(int index) const {\n        std::vector<int>\
    \ res(_inner_dims.size() - 1);\n        for (unsigned int i = 0; i < res.size();\
    \ ++i)\n            res[i] = index / _inner_dims[i] % _inner_dims[i + 1];\n\n\
    \        return res;\n    }\n\n    int next(int index, unsigned int i) const {\n\
    \        assert(i < _inner_dims.size() - 1);\n        if (index % _inner_dims[i\
    \ + 1] / _inner_dims[i] == _inner_dims[i + 1] / _inner_dims[i] - 1)\n        \
    \    return -1;\n        return index + _inner_dims[i];\n    }\n\n    int prev(int\
    \ index, unsigned int i) const {\n        assert(i < _inner_dims.size() - 1);\n\
    \        if (index % _inner_dims[i + 1] / _inner_dims[i] == 0) return -1;\n  \
    \      return index - _inner_dims[i];\n    }\n\n    int size() const { return\
    \ _inner_dims.back(); }\n};\n\n} // namespace kk2\n\n#endif // KK2_MATH_FLATTEN_INDICES_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/flatten_indeices.hpp
  requiredBy: []
  timestamp: '2025-03-28 03:33:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/flatten_indeices.hpp
layout: document
redirect_from:
- /library/math/flatten_indeices.hpp
- /library/math/flatten_indeices.hpp.html
title: math/flatten_indeices.hpp
---
