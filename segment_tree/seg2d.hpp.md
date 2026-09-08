---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: algebra.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/algebra.hpp
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn:
  - type_traits/algebra.hpp
  embedded:
  - code: "#ifndef KK2_SEGMENT_TREE_SEG2D_HPP\n#define KK2_SEGMENT_TREE_SEG2D_HPP\
      \ 1\n\n#include <cassert>\n#include <vector>\n\n#include \"../type_traits/algebra.hpp\"\
      \n\nnamespace kk2 {\n\n// commutative monoid\ntemplate <algebra::CommutativeMonoid\
      \ M> struct SegmentTree2D {\n    SegmentTree2D() = default;\n\n    SegmentTree2D(int\
      \ h_, int w_) : _h(h_), _w(w_) {\n        size_h = size_w = 1;\n        while\
      \ (size_h < _h) size_h <<= 1;\n        while (size_w < _w) size_w <<= 1;\n \
      \       d = std::vector<std::vector<M>>(size_h * 2, std::vector<M>(size_w *\
      \ 2, M::unit()));\n    }\n\n    template <class... Args>\n    SegmentTree2D(int\
      \ h_, int w_, Args... args)\n        : SegmentTree2D(std::vector<std::vector<M>>(h_,\
      \ std::vector<M>(w_, M(args...)))) {}\n\n    SegmentTree2D(const std::vector<std::vector<M>>\
      \ &v) : _h(int(v.size())), _w(int(v[0].size())) {\n        size_h = size_w =\
      \ 1;\n        while (size_h < _h) size_h <<= 1;\n        while (size_w < _w)\
      \ size_w <<= 1;\n        d = std::vector<std::vector<M>>(size_h * 2, std::vector<M>(size_w\
      \ * 2, M::unit()));\n        for (int i = 0; i < _h; i++) {\n            for\
      \ (int j = 0; j < _w; j++) { d[i + size_h][j + size_w] = v[i][j]; }\n      \
      \  }\n        build();\n    }\n\n    void build() {\n        assert(!is_built);\n\
      \        is_built = true;\n        for (int j = size_w; j < size_w * 2; j++)\
      \ {\n            for (int i = size_h - 1; i; i--) updatei(i, j);\n        }\n\
      \        for (int i = 1; i < size_h * 2; i++) {\n            for (int j = size_w\
      \ - 1; j; j--) updatej(i, j);\n        }\n    }\n\n    template <class... Args>\
      \ void init_set(int i, int j, Args... args) {\n        assert(0 <= i && i <\
      \ _h);\n        assert(0 <= j && j < _w);\n        assert(!is_built);\n    \
      \    d[i + size_h][j + size_w] = M(args...);\n    }\n\n    template <class...\
      \ Args> void set(int i, int j, Args... args) {\n        assert(0 <= i && i <\
      \ _h);\n        assert(0 <= j && j < _w);\n        assert(is_built);\n     \
      \   i += size_h;\n        j += size_w;\n        d[i][j] = M(args...);\n    \
      \    for (int ii = i >> 1; ii; ii >>= 1) updatei(ii, j);\n        for (int ii\
      \ = i; ii; ii >>= 1) {\n            for (int jj = j >> 1; jj; jj >>= 1) updatej(ii,\
      \ jj);\n        }\n    }\n\n    M get(int i, int j) {\n        assert(0 <= i\
      \ && i < _h);\n        assert(0 <= j && j < _w);\n        assert(is_built);\n\
      \        return d[i + size_h][j + size_w];\n    }\n\n    M prod(int i1, int\
      \ j1, int i2, int j2) {\n        assert(0 <= i1 && i1 <= i2 && i2 <= _h);\n\
      \        assert(0 <= j1 && j1 <= j2 && j2 <= _w);\n        assert(is_built);\n\
      \        if (i1 == i2 || j1 == j2) return M::unit();\n        i1 += size_h;\n\
      \        i2 += size_h;\n        j1 += size_w;\n        j2 += size_w;\n\n   \
      \     M res = M::unit();\n        for (; i1 < i2; i1 >>= 1, i2 >>= 1) {\n  \
      \          if (i1 & 1) res = M::op(res, inner_prod(i1++, j1, j2));\n       \
      \     if (i2 & 1) res = M::op(inner_prod(--i2, j1, j2), res);\n        }\n \
      \       return res;\n    }\n\n  private:\n    int _h, _w, size_h, size_w;\n\
      \    std::vector<std::vector<M>> d;\n    bool is_built = false;\n\n    void\
      \ updatei(int i, int j) { d[i][j] = M::op(d[i * 2][j], d[i * 2 + 1][j]); }\n\
      \n    void updatej(int i, int j) { d[i][j] = M::op(d[i][j * 2], d[i][j * 2 +\
      \ 1]); }\n\n    M inner_prod(int i, int j1, int j2) {\n        M res = M::unit();\n\
      \        for (; j1 < j2; j1 >>= 1, j2 >>= 1) {\n            if (j1 & 1) res\
      \ = M::op(res, d[i][j1++]);\n            if (j2 & 1) res = M::op(d[i][--j2],\
      \ res);\n        }\n        return res;\n    }\n};\n\n} // namespace kk2\n\n\
      #endif // KK2_SEGMENT_TREE_SEG2D_HPP\n"
    name: default
  - code: "#line 1 \"segment_tree/seg2d.hpp\"\n\n\n\n#include <cassert>\n#include\
      \ <vector>\n\n#line 1 \"type_traits/algebra.hpp\"\n\n\n\n#include <concepts>\n\
      \nnamespace kk2 {\n\nnamespace algebra {\n\n// These concepts describe the static\
      \ interface expected by the library.\n// Algebraic laws such as associativity\
      \ cannot be checked by the type system.\n//\n// A user-defined monoid therefore\
      \ needs only:\n//\n//   struct MyMonoid {\n//       static MyMonoid op(const\
      \ MyMonoid &, const MyMonoid &);\n//       static MyMonoid unit();\n//   };\n\
      //\n// The return types are intentionally exact, so a typo such as returning\
      \ the\n// underlying scalar instead of MyMonoid is diagnosed at the concept\
      \ boundary.\ntemplate <class T>\nconcept Semigroup = requires(const T &x, const\
      \ T &y) {\n    { T::op(x, y) } -> std::same_as<T>;\n};\n\ntemplate <class T>\n\
      concept Monoid = Semigroup<T> && requires {\n    { T::unit() } -> std::same_as<T>;\n\
      };\n\ntemplate <class T>\nconcept Group = Monoid<T> && requires(const T &x)\
      \ {\n    { T::inv(x) } -> std::same_as<T>;\n};\n\ntemplate <class T>\nconcept\
      \ CommutativeMonoid = Monoid<T> && requires {\n    { T::commutative } -> std::convertible_to<bool>;\n\
      } && bool(T::commutative);\n\ntemplate <class T>\nconcept CommutativeGroup =\
      \ Group<T> && requires {\n    { T::commutative } -> std::convertible_to<bool>;\n\
      } && bool(T::commutative);\n\n// An action specification owns the pair of algebraic\
      \ types and the mapping\n// between them. It is the interface required by lazy\
      \ propagation structures.\ntemplate <class T>\nconcept Action =\n    requires\
      \ {\n        typename T::A;\n        typename T::S;\n    } && Monoid<typename\
      \ T::A> && Monoid<typename T::S>\n    && requires(const typename T::A &f, const\
      \ typename T::S &x) {\n           { T::act(f, x) } -> std::same_as<typename\
      \ T::S>;\n       };\n\n} // namespace algebra\n\n} // namespace kk2\n\n\n#line\
      \ 8 \"segment_tree/seg2d.hpp\"\n\nnamespace kk2 {\n\n// commutative monoid\n\
      template <algebra::CommutativeMonoid M> struct SegmentTree2D {\n    SegmentTree2D()\
      \ = default;\n\n    SegmentTree2D(int h_, int w_) : _h(h_), _w(w_) {\n     \
      \   size_h = size_w = 1;\n        while (size_h < _h) size_h <<= 1;\n      \
      \  while (size_w < _w) size_w <<= 1;\n        d = std::vector<std::vector<M>>(size_h\
      \ * 2, std::vector<M>(size_w * 2, M::unit()));\n    }\n\n    template <class...\
      \ Args>\n    SegmentTree2D(int h_, int w_, Args... args)\n        : SegmentTree2D(std::vector<std::vector<M>>(h_,\
      \ std::vector<M>(w_, M(args...)))) {}\n\n    SegmentTree2D(const std::vector<std::vector<M>>\
      \ &v) : _h(int(v.size())), _w(int(v[0].size())) {\n        size_h = size_w =\
      \ 1;\n        while (size_h < _h) size_h <<= 1;\n        while (size_w < _w)\
      \ size_w <<= 1;\n        d = std::vector<std::vector<M>>(size_h * 2, std::vector<M>(size_w\
      \ * 2, M::unit()));\n        for (int i = 0; i < _h; i++) {\n            for\
      \ (int j = 0; j < _w; j++) { d[i + size_h][j + size_w] = v[i][j]; }\n      \
      \  }\n        build();\n    }\n\n    void build() {\n        assert(!is_built);\n\
      \        is_built = true;\n        for (int j = size_w; j < size_w * 2; j++)\
      \ {\n            for (int i = size_h - 1; i; i--) updatei(i, j);\n        }\n\
      \        for (int i = 1; i < size_h * 2; i++) {\n            for (int j = size_w\
      \ - 1; j; j--) updatej(i, j);\n        }\n    }\n\n    template <class... Args>\
      \ void init_set(int i, int j, Args... args) {\n        assert(0 <= i && i <\
      \ _h);\n        assert(0 <= j && j < _w);\n        assert(!is_built);\n    \
      \    d[i + size_h][j + size_w] = M(args...);\n    }\n\n    template <class...\
      \ Args> void set(int i, int j, Args... args) {\n        assert(0 <= i && i <\
      \ _h);\n        assert(0 <= j && j < _w);\n        assert(is_built);\n     \
      \   i += size_h;\n        j += size_w;\n        d[i][j] = M(args...);\n    \
      \    for (int ii = i >> 1; ii; ii >>= 1) updatei(ii, j);\n        for (int ii\
      \ = i; ii; ii >>= 1) {\n            for (int jj = j >> 1; jj; jj >>= 1) updatej(ii,\
      \ jj);\n        }\n    }\n\n    M get(int i, int j) {\n        assert(0 <= i\
      \ && i < _h);\n        assert(0 <= j && j < _w);\n        assert(is_built);\n\
      \        return d[i + size_h][j + size_w];\n    }\n\n    M prod(int i1, int\
      \ j1, int i2, int j2) {\n        assert(0 <= i1 && i1 <= i2 && i2 <= _h);\n\
      \        assert(0 <= j1 && j1 <= j2 && j2 <= _w);\n        assert(is_built);\n\
      \        if (i1 == i2 || j1 == j2) return M::unit();\n        i1 += size_h;\n\
      \        i2 += size_h;\n        j1 += size_w;\n        j2 += size_w;\n\n   \
      \     M res = M::unit();\n        for (; i1 < i2; i1 >>= 1, i2 >>= 1) {\n  \
      \          if (i1 & 1) res = M::op(res, inner_prod(i1++, j1, j2));\n       \
      \     if (i2 & 1) res = M::op(inner_prod(--i2, j1, j2), res);\n        }\n \
      \       return res;\n    }\n\n  private:\n    int _h, _w, size_h, size_w;\n\
      \    std::vector<std::vector<M>> d;\n    bool is_built = false;\n\n    void\
      \ updatei(int i, int j) { d[i][j] = M::op(d[i * 2][j], d[i * 2 + 1][j]); }\n\
      \n    void updatej(int i, int j) { d[i][j] = M::op(d[i][j * 2], d[i][j * 2 +\
      \ 1]); }\n\n    M inner_prod(int i, int j1, int j2) {\n        M res = M::unit();\n\
      \        for (; j1 < j2; j1 >>= 1, j2 >>= 1) {\n            if (j1 & 1) res\
      \ = M::op(res, d[i][j1++]);\n            if (j2 & 1) res = M::op(d[i][--j2],\
      \ res);\n        }\n        return res;\n    }\n};\n\n} // namespace kk2\n\n\
      \n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: segment_tree/seg2d.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment_tree/seg2d.hpp
layout: document
---
