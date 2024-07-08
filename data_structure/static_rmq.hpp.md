---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
  - icon: ':warning:'
    path: others/monoid/min.hpp
    title: others/monoid/min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/static_rmq.hpp\"\n\n\n\n#line 1 \"data_structure/sparse_table.hpp\"\
    \n\n\n\n\n// require: op(x, x) = x for all x\ntemplate <class S, S (*op)(S, S),\
    \ S (*e)()>\nstruct SparseTable {\n    SparseTable() : SparseTable(0) {}\n   \
    \ SparseTable(int n) : SparseTable(vector<S>(n, e())) {}\n    SparseTable(const\
    \ vector<S>& v) : _n(int(v.size())) {\n        log = 1;\n        while ((1 <<\
    \ log) <= _n) log++;\n        table.assign(log, vector<S>(_n));\n        for (int\
    \ i = 0; i < _n; i++) table[0][i] = v[i];\n        for (int i = 1; i < log; i++)\
    \ {\n            for (int j = 0; j + (1 << i) <= _n; j++) {\n                table[i][j]\
    \ = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n  \
    \      }\n    }\n\n    using Monoid = S;\n    static S Op(S l, S r) { return op(l,\
    \ r); }\n    static S MonoidUnit() { return e(); }\n\n    S prod(int l, int r)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return\
    \ e();\n        int i = 31 - __builtin_clz(r - l);\n        return op(table[i][l],\
    \ table[i][r - (1 << i)]);\n    }\n\n  private:\n    int _n, log;\n    vector<vector<S>>\
    \ table;\n};\n\n\n#line 1 \"others/monoid/min.hpp\"\n\n\n\nnamespace monoid {\n\
    \ntemplate <class S>\nstruct Min {\n    S a;\n    bool inf;\n    Min() : a(0),\
    \ inf(true) {}\n    Min(S a_, bool inf_ = false) : a(a_), inf(inf_) {}\n    operator\
    \ S() const { return a; }\n    friend ostream& operator<<(ostream& os, const Min&\
    \ min) {\n        os << (min.inf ? \"inf\" : to_string(min.a));\n        return\
    \ os;\n    }\n    friend istream& operator>>(istream& is, Min& min) {\n      \
    \  is >> min.a;\n        min.inf = false;\n        return is;\n    }\n    Min&\
    \ operator=(const S& rhs) {\n        a = rhs;\n        inf = false;\n        return\
    \ *this;\n    }\n\n    Min& add(const S& rhs) {\n        if (inf) return *this;\n\
    \        a += rhs;\n        return *this;\n    }\n    Min& update(const S& rhs)\
    \ {\n        a = rhs;\n        inf = false;\n        return *this;\n    }\n  \
    \  Min& op(const Min& rhs) {\n        if (rhs.inf) return *this;\n        if (inf)\
    \ return *this = rhs;\n        a = min(a, rhs.a);\n        return *this;\n   \
    \ }\n\n    bool is_inf() const { return inf; }\n};\n\ntemplate <class S>\nMin<S>\
    \ MinOp(Min<S> l, Min<S> r) { return l.op(r); }\n\ntemplate <class S>\nMin<S>\
    \ MinUnit() { return Min<S>(); }\n\n} // namespace monoid\n\ntemplate <class S,\
    \ class... Args>\nvector<monoid::Min<S>> GetVecMin(int n, Args... args) {\n  \
    \  return vector<monoid::Min<S>>(n, monoid::Min<S>(args...));\n}\n\n\n\n#line\
    \ 6 \"data_structure/static_rmq.hpp\"\n\ntemplate <class S>\nusing StaticRMQ =\
    \ SparseTable<monoid::Min<S>, monoid::MinOp<S>, monoid::MinUnit<S>>;\n\n\n"
  code: '#ifndef DATA_STRUCTURE_STATIC_RMQ_HPP

    #define DATA_STRUCTURE_STATIC_RMQ_HPP 1


    #include "sparse_table.hpp"

    #include "../others/monoid/min.hpp"


    template <class S>

    using StaticRMQ = SparseTable<monoid::Min<S>, monoid::MinOp<S>, monoid::MinUnit<S>>;


    #endif // DATA_STRUCTURE_STATIC_RMQ_HPP

    '
  dependsOn:
  - data_structure/sparse_table.hpp
  - others/monoid/min.hpp
  isVerificationFile: false
  path: data_structure/static_rmq.hpp
  requiredBy: []
  timestamp: '2024-07-08 10:09:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/static_rmq.hpp
layout: document
redirect_from:
- /library/data_structure/static_rmq.hpp
- /library/data_structure/static_rmq.hpp.html
title: data_structure/static_rmq.hpp
---
