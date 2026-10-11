---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: concepts.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/concepts.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: '#ifndef KK2_TYPE_TRAITS_OPERATOR_HPP

      #define KK2_TYPE_TRAITS_OPERATOR_HPP 1


      namespace kk2 {


      template <class T> concept HasNegation = requires(T x) { -x; };

      template <class LHS, class RHS = LHS> concept HasPlus = requires(LHS lhs, RHS
      rhs) { lhs + rhs; };

      template <class LHS, class RHS = LHS> concept HasMinus = requires(LHS lhs, RHS
      rhs) { lhs - rhs; };

      template <class LHS, class RHS = LHS> concept HasMultiplies = requires(LHS lhs,
      RHS rhs) { lhs * rhs; };

      template <class LHS, class RHS = LHS> concept HasDivides = requires(LHS lhs,
      RHS rhs) { lhs / rhs; };

      template <class LHS, class RHS = LHS> concept HasModulus = requires(LHS lhs,
      RHS rhs) { lhs % rhs; };

      template <class T> concept HasBitNot = requires(T x) { ~x; };

      template <class LHS, class RHS = LHS> concept HasBitAnd = requires(LHS lhs,
      RHS rhs) { lhs & rhs; };

      template <class LHS, class RHS = LHS> concept HasBitOr = requires(LHS lhs, RHS
      rhs) { lhs | rhs; };

      template <class LHS, class RHS = LHS> concept HasBitXor = requires(LHS lhs,
      RHS rhs) { lhs ^ rhs; };

      template <class T> concept HasLogicalNot = requires(T x) { !x; };

      template <class LHS, class RHS = LHS> concept HasLogicalAnd = requires(LHS lhs,
      RHS rhs) { (lhs && rhs); };

      template <class LHS, class RHS = LHS> concept HasLogicalOr = requires(LHS lhs,
      RHS rhs) { lhs || rhs; };

      template <class LHS, class RHS = LHS> concept HasEqualTo = requires(LHS lhs,
      RHS rhs) { lhs == rhs; };

      template <class LHS, class RHS = LHS> concept HasNotEqualTo = requires(LHS lhs,
      RHS rhs) { lhs != rhs; };

      template <class LHS, class RHS = LHS> concept HasLess = requires(LHS lhs, RHS
      rhs) { lhs < rhs; };

      template <class LHS, class RHS = LHS> concept HasGreater = requires(LHS lhs,
      RHS rhs) { lhs > rhs; };

      template <class LHS, class RHS = LHS> concept HasLessEqual = requires(LHS lhs,
      RHS rhs) { lhs <= rhs; };

      template <class LHS, class RHS = LHS> concept HasGreaterEqual = requires(LHS
      lhs, RHS rhs) { lhs >= rhs; };

      } // namespace kk2


      #endif // KK2_TYPE_TRAITS_OPERATOR_HPP

      '
    name: default
  - code: '#line 1 "type_traits/operator.hpp"




      namespace kk2 {


      template <class T> concept HasNegation = requires(T x) { -x; };

      template <class LHS, class RHS = LHS> concept HasPlus = requires(LHS lhs, RHS
      rhs) { lhs + rhs; };

      template <class LHS, class RHS = LHS> concept HasMinus = requires(LHS lhs, RHS
      rhs) { lhs - rhs; };

      template <class LHS, class RHS = LHS> concept HasMultiplies = requires(LHS lhs,
      RHS rhs) { lhs * rhs; };

      template <class LHS, class RHS = LHS> concept HasDivides = requires(LHS lhs,
      RHS rhs) { lhs / rhs; };

      template <class LHS, class RHS = LHS> concept HasModulus = requires(LHS lhs,
      RHS rhs) { lhs % rhs; };

      template <class T> concept HasBitNot = requires(T x) { ~x; };

      template <class LHS, class RHS = LHS> concept HasBitAnd = requires(LHS lhs,
      RHS rhs) { lhs & rhs; };

      template <class LHS, class RHS = LHS> concept HasBitOr = requires(LHS lhs, RHS
      rhs) { lhs | rhs; };

      template <class LHS, class RHS = LHS> concept HasBitXor = requires(LHS lhs,
      RHS rhs) { lhs ^ rhs; };

      template <class T> concept HasLogicalNot = requires(T x) { !x; };

      template <class LHS, class RHS = LHS> concept HasLogicalAnd = requires(LHS lhs,
      RHS rhs) { (lhs && rhs); };

      template <class LHS, class RHS = LHS> concept HasLogicalOr = requires(LHS lhs,
      RHS rhs) { lhs || rhs; };

      template <class LHS, class RHS = LHS> concept HasEqualTo = requires(LHS lhs,
      RHS rhs) { lhs == rhs; };

      template <class LHS, class RHS = LHS> concept HasNotEqualTo = requires(LHS lhs,
      RHS rhs) { lhs != rhs; };

      template <class LHS, class RHS = LHS> concept HasLess = requires(LHS lhs, RHS
      rhs) { lhs < rhs; };

      template <class LHS, class RHS = LHS> concept HasGreater = requires(LHS lhs,
      RHS rhs) { lhs > rhs; };

      template <class LHS, class RHS = LHS> concept HasLessEqual = requires(LHS lhs,
      RHS rhs) { lhs <= rhs; };

      template <class LHS, class RHS = LHS> concept HasGreaterEqual = requires(LHS
      lhs, RHS rhs) { lhs >= rhs; };

      } // namespace kk2



      '
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: type_traits/operator.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-10-11 18:25:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/type_traits/concepts.test.cpp
documentation_of: type_traits/operator.hpp
layout: document
---
