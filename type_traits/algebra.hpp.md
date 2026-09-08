---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: lazy_red_black_tree_node.hpp
      icon: LIBRARY_ALL_AC
      path: bbst/base/lazy_red_black_tree_node.hpp
    - filename: lazy_red_black_tree.hpp
      icon: LIBRARY_ALL_AC
      path: bbst/lazy_red_black_tree.hpp
    - filename: persistent_lazy_red_black_tree.hpp
      icon: LIBRARY_NO_TESTS
      path: bbst/persistent_lazy_red_black_tree.hpp
    - filename: disjoint_sparse_table.hpp
      icon: LIBRARY_ALL_AC
      path: data_structure/disjoint_sparse_table.hpp
    - filename: sparse_table.hpp
      icon: LIBRARY_ALL_AC
      path: data_structure/sparse_table.hpp
    - filename: static_rmq.hpp
      icon: LIBRARY_ALL_AC
      path: data_structure/static_rmq.hpp
    - filename: euler_tour.hpp
      icon: LIBRARY_ALL_AC
      path: graph/tree/euler_tour.hpp
    - filename: bsgs.hpp
      icon: LIBRARY_NO_TESTS
      path: math/monoid/bsgs.hpp
    - filename: pow.hpp
      icon: LIBRARY_NO_TESTS
      path: math/monoid/pow.hpp
    - filename: lazy.hpp
      icon: LIBRARY_ALL_AC
      path: segment_tree/lazy.hpp
    - filename: seg.hpp
      icon: LIBRARY_ALL_AC
      path: segment_tree/seg.hpp
    - filename: seg2d.hpp
      icon: LIBRARY_NO_TESTS
      path: segment_tree/seg2d.hpp
    - filename: ds_dynamic_sequence_range_affine_range_sum.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
    - filename: ds_point_set_range_composite_large_2.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_ds/ds_point_set_range_composite_large_2.test.cpp
    type: Required by
  - files:
    - filename: algebra.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/algebra/algebra.test.cpp
    - filename: ds_point_set_range_composite.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
    - filename: ds_range_affine_range_sum.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
    - filename: ds_range_affine_range_sum_large_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
    - filename: ds_range_set_range_composite.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_set_range_composite.test.cpp
    - filename: ds_static_rmq.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_static_rmq.test.cpp
    - filename: ds_static_rmq_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_static_rmq_2.test.cpp
    - filename: tree_vertex_add_path_sum_1.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_add_path_sum_1.test.cpp
    - filename: tree_vertex_add_subtree_sum_1.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_add_subtree_sum_1.test.cpp
    - filename: tree_vertex_set_path_composite_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_TYPE_TRAITS_ALGEBRA_HPP\n#define KK2_TYPE_TRAITS_ALGEBRA_HPP\
      \ 1\n\n#include <concepts>\n\nnamespace kk2 {\n\nnamespace algebra {\n\n// These\
      \ concepts describe the static interface expected by the library.\n// Algebraic\
      \ laws such as associativity cannot be checked by the type system.\n//\n// A\
      \ user-defined monoid therefore needs only:\n//\n//   struct MyMonoid {\n//\
      \       static MyMonoid op(const MyMonoid &, const MyMonoid &);\n//       static\
      \ MyMonoid unit();\n//   };\n//\n// The return types are intentionally exact,\
      \ so a typo such as returning the\n// underlying scalar instead of MyMonoid\
      \ is diagnosed at the concept boundary.\ntemplate <class T>\nconcept Semigroup\
      \ = requires(const T &x, const T &y) {\n    { T::op(x, y) } -> std::same_as<T>;\n\
      };\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> && requires {\n    {\
      \ T::unit() } -> std::same_as<T>;\n};\n\ntemplate <class T>\nconcept Group =\
      \ Monoid<T> && requires(const T &x) {\n    { T::inv(x) } -> std::same_as<T>;\n\
      };\n\ntemplate <class T>\nconcept CommutativeMonoid = Monoid<T> && requires\
      \ {\n    { T::commutative } -> std::convertible_to<bool>;\n} && bool(T::commutative);\n\
      \ntemplate <class T>\nconcept CommutativeGroup = Group<T> && requires {\n  \
      \  { T::commutative } -> std::convertible_to<bool>;\n} && bool(T::commutative);\n\
      \n// An action specification owns the pair of algebraic types and the mapping\n\
      // between them. It is the interface required by lazy propagation structures.\n\
      template <class T>\nconcept Action =\n    requires {\n        typename T::A;\n\
      \        typename T::S;\n    } && Monoid<typename T::A> && Monoid<typename T::S>\n\
      \    && requires(const typename T::A &f, const typename T::S &x) {\n       \
      \    { T::act(f, x) } -> std::same_as<typename T::S>;\n       };\n\n} // namespace\
      \ algebra\n\n} // namespace kk2\n\n#endif // KK2_TYPE_TRAITS_ALGEBRA_HPP\n"
    name: default
  - code: "#line 1 \"type_traits/algebra.hpp\"\n\n\n\n#include <concepts>\n\nnamespace\
      \ kk2 {\n\nnamespace algebra {\n\n// These concepts describe the static interface\
      \ expected by the library.\n// Algebraic laws such as associativity cannot be\
      \ checked by the type system.\n//\n// A user-defined monoid therefore needs\
      \ only:\n//\n//   struct MyMonoid {\n//       static MyMonoid op(const MyMonoid\
      \ &, const MyMonoid &);\n//       static MyMonoid unit();\n//   };\n//\n// The\
      \ return types are intentionally exact, so a typo such as returning the\n//\
      \ underlying scalar instead of MyMonoid is diagnosed at the concept boundary.\n\
      template <class T>\nconcept Semigroup = requires(const T &x, const T &y) {\n\
      \    { T::op(x, y) } -> std::same_as<T>;\n};\n\ntemplate <class T>\nconcept\
      \ Monoid = Semigroup<T> && requires {\n    { T::unit() } -> std::same_as<T>;\n\
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
      \ T::S>;\n       };\n\n} // namespace algebra\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: type_traits/algebra.hpp
  pathExtension: hpp
  requiredBy:
  - bbst/base/lazy_red_black_tree_node.hpp
  - bbst/lazy_red_black_tree.hpp
  - bbst/persistent_lazy_red_black_tree.hpp
  - data_structure/disjoint_sparse_table.hpp
  - data_structure/sparse_table.hpp
  - data_structure/static_rmq.hpp
  - graph/tree/euler_tour.hpp
  - math/monoid/bsgs.hpp
  - math/monoid/pow.hpp
  - segment_tree/lazy.hpp
  - segment_tree/seg.hpp
  - segment_tree/seg2d.hpp
  - verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_large_2.test.cpp
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/type_traits/algebra/algebra.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
  - verify/yosupo_ds/ds_range_set_range_composite.test.cpp
  - verify/yosupo_ds/ds_static_rmq.test.cpp
  - verify/yosupo_ds/ds_static_rmq_2.test.cpp
  - verify/yosupo_graph/tree_vertex_add_path_sum_1.test.cpp
  - verify/yosupo_graph/tree_vertex_add_subtree_sum_1.test.cpp
  - verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
documentation_of: type_traits/algebra.hpp
layout: document
---
