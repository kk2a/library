---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
  - icon: ':question:'
    path: math/monoid/min.hpp
    title: math/monoid/min.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/tree/euler_tour.hpp
    title: graph/tree/euler_tour.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_static_rmq.test.cpp
    title: verify/yosupo_ds/ds_static_rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_vertex_add_path_sum_1.test.cpp
    title: verify/yosupo_graph/tree_vertex_add_path_sum_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_vertex_add_subtree_sum_1.test.cpp
    title: verify/yosupo_graph/tree_vertex_add_subtree_sum_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/static_rmq.hpp\"\n\n\n\n#line 1 \"math/monoid/min.hpp\"\
    \n\n\n\n#include <functional>\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include\
    \ <istream>\n#include <ostream>\n#include <type_traits>\n\nnamespace kk2 {\n\n\
    namespace type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\n\
    } // namespace type_traits\n\ntemplate <typename T> using is_standard_istream\
    \ =\n    typename std::conditional<std::is_same<T, std::istream>::value\n    \
    \                              || std::is_same<T, std::ifstream>::value,\n   \
    \                           std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_standard_ostream =\n    typename std::conditional<std::is_same<T,\
    \ std::ostream>::value\n                                  || std::is_same<T, std::ofstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
    \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
    \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
    template <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
    \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
    \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate <typename\
    \ T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n#line 7 \"math/monoid/min.hpp\"\n\nnamespace kk2 {\n\nnamespace monoid\
    \ {\n\ntemplate <class S, class Compare = std::less<S>> struct Min {\n    static\
    \ constexpr bool commutative = true;\n    using M = Min;\n    S a;\n    bool is_unit;\n\
    \n    Min() : a(S()), is_unit(true) {}\n    Min(S a_) : a(a_), is_unit(false)\
    \ {}\n    operator S() const { return a; }\n\n    inline static M op(M l, M r)\
    \ {\n        if (l.is_unit or r.is_unit) return l.is_unit ? r : l;\n        return\
    \ Compare{}(l.a, r.a) ? l : r;\n    }\n\n    inline static M unit() { return M();\
    \ }\n\n    bool operator==(const M &rhs) const {\n        return is_unit == rhs.is_unit\
    \ and (is_unit or a == rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const\
    \ {\n        return is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n   \
    \ }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend\
    \ OStream &operator<<(OStream &os, const M &x) {\n        if (x.is_unit) os <<\
    \ \"inf\";\n        else os << x.a;\n        return os;\n    }\n\n    template\
    \ <class IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, M &x) {\n        is >> x.a;\n        x.is_unit = false;\n        return\
    \ is;\n    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\n\n#line 1 \"\
    data_structure/sparse_table.hpp\"\n\n\n\n#include <cassert>\n#include <vector>\n\
    \nnamespace kk2 {\n\n// require: op(x, x) = x for all x\ntemplate <class S, S\
    \ (*op)(S, S), S (*e)()> struct SparseTable {\n    SparseTable() = default;\n\n\
    \    SparseTable(int n) : _n(n) {\n        log = 0;\n        while ((1 << log)\
    \ < _n) log++;\n        table.assign(log + 1, std::vector<S>(_n));\n    }\n\n\
    \    SparseTable(const std::vector<S> &v) : _n(int(v.size())) {\n        log =\
    \ 0;\n        while ((1 << log) < _n) log++;\n        table.assign(log + 1, std::vector<S>(_n));\n\
    \        for (int i = 0; i < _n; i++) table[0][i] = v[i];\n        build();\n\
    \    }\n\n    void build() {\n        assert(!is_built);\n        is_built = true;\n\
    \        for (int i = 1; i <= log; i++) {\n            for (int j = 0; j + (1\
    \ << i) <= _n; j++) {\n                table[i][j] = op(table[i - 1][j], table[i\
    \ - 1][j + (1 << (i - 1))]);\n            }\n        }\n    }\n\n    template\
    \ <class... Args> void init_set(int p, Args... args) {\n        assert(0 <= p\
    \ && p < _n);\n        assert(!is_built);\n        table[0][p] = S(args...);\n\
    \    }\n\n    using Monoid = S;\n\n    static S Op(S l, S r) { return op(l, r);\
    \ }\n\n    static S MonoidUnit() { return e(); }\n\n    S prod(int l, int r) const\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        assert(is_built);\n\
    \        if (l == r) return e();\n        int i = 31 ^ __builtin_clz(r - l);\n\
    \        return op(table[i][l], table[i][r - (1 << i)]);\n    }\n\n    S get(int\
    \ i) const {\n        assert(0 <= i && i < _n);\n        assert(is_built);\n \
    \       return table[0][i];\n    }\n\n    // return r s.t.\n    // r = l or f(op(a[l],\
    \ a[l+1], ..., a[r-1])) == true\n    // r = n or f(op(a[l], a[l+1], ..., a[r]))\
    \   == false\n    template <bool (*f)(S)> int max_right(int l) const {\n     \
    \   return max_right(l, [](S x) { return f(x); });\n    }\n\n    template <class\
    \ F> int max_right(int l, F f) const {\n        assert(0 <= l && l <= _n);\n \
    \       assert(f(e()));\n        assert(is_built);\n        if (l == _n) return\
    \ _n;\n        int left = l - 1, right = _n;\n        while (right - left > 1)\
    \ {\n            int mid = (left + right) >> 1;\n            if (f(prod(l, mid)))\
    \ left = mid;\n            else right = mid;\n        }\n        return right;\n\
    \    }\n\n    // return l s.t.\n    // l = r or f(op(a[l], a[l+1], ..., a[r-1]))\
    \ == false\n    // l = 0 or f(op(a[l], a[l+1], ..., a[r]))   == true\n    template\
    \ <bool (*f)(S)> int min_left(int r) const {\n        return min_left(r, [](S\
    \ x) { return f(x); });\n    }\n\n    template <class F> int min_left(int r, F\
    \ f) const {\n        assert(0 <= r && r <= _n);\n        assert(f(e()));\n  \
    \      assert(is_built);\n        if (r == 0) return 0;\n        int left = -1,\
    \ right = r;\n        while (right - left > 1) {\n            int mid = (left\
    \ + right) >> 1;\n            if (f(prod(mid, r))) right = mid;\n            else\
    \ left = mid;\n        }\n        return right;\n    }\n\n  private:\n    int\
    \ _n, log;\n    std::vector<std::vector<S>> table;\n    bool is_built = false;\n\
    };\n\ntemplate <class M> using SparseTableS = SparseTable<M, M::op, M::unit>;\n\
    \n} // namespace kk2\n\n\n#line 6 \"data_structure/static_rmq.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class S> using StaticRMQ = SparseTableS<monoid::Min<S>>;\n\
    \n} // namespace kk2\n\n\n"
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
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_static_rmq.test.cpp
  - verify/yosupo_graph/tree_vertex_add_path_sum_1.test.cpp
  - verify/yosupo_graph/tree_vertex_add_subtree_sum_1.test.cpp
documentation_of: data_structure/static_rmq.hpp
layout: document
redirect_from:
- /library/data_structure/static_rmq.hpp
- /library/data_structure/static_rmq.hpp.html
title: data_structure/static_rmq.hpp
---
