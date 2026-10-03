#ifndef KK2_TYPE_TRAITS_OPERATOR_HPP
#define KK2_TYPE_TRAITS_OPERATOR_HPP 1

namespace kk2 {

template <class T> concept HasNegation = requires(T x) { -x; };
template <class LHS, class RHS = LHS> concept HasPlus = requires(LHS lhs, RHS rhs) { lhs + rhs; };
template <class LHS, class RHS = LHS> concept HasMinus = requires(LHS lhs, RHS rhs) { lhs - rhs; };
template <class LHS, class RHS = LHS> concept HasMultiplies = requires(LHS lhs, RHS rhs) { lhs * rhs; };
template <class LHS, class RHS = LHS> concept HasDivides = requires(LHS lhs, RHS rhs) { lhs / rhs; };
template <class LHS, class RHS = LHS> concept HasModulus = requires(LHS lhs, RHS rhs) { lhs % rhs; };
template <class T> concept HasBitNot = requires(T x) { ~x; };
template <class LHS, class RHS = LHS> concept HasBitAnd = requires(LHS lhs, RHS rhs) { lhs & rhs; };
template <class LHS, class RHS = LHS> concept HasBitOr = requires(LHS lhs, RHS rhs) { lhs | rhs; };
template <class LHS, class RHS = LHS> concept HasBitXor = requires(LHS lhs, RHS rhs) { lhs ^ rhs; };
template <class T> concept HasLogicalNot = requires(T x) { !x; };
template <class LHS, class RHS = LHS> concept HasLogicalAnd = requires(LHS lhs, RHS rhs) { (lhs && rhs); };
template <class LHS, class RHS = LHS> concept HasLogicalOr = requires(LHS lhs, RHS rhs) { lhs || rhs; };
template <class LHS, class RHS = LHS> concept HasEqualTo = requires(LHS lhs, RHS rhs) { lhs == rhs; };
template <class LHS, class RHS = LHS> concept HasNotEqualTo = requires(LHS lhs, RHS rhs) { lhs != rhs; };
template <class LHS, class RHS = LHS> concept HasLess = requires(LHS lhs, RHS rhs) { lhs < rhs; };
template <class LHS, class RHS = LHS> concept HasGreater = requires(LHS lhs, RHS rhs) { lhs > rhs; };
template <class LHS, class RHS = LHS> concept HasLessEqual = requires(LHS lhs, RHS rhs) { lhs <= rhs; };
template <class LHS, class RHS = LHS> concept HasGreaterEqual = requires(LHS lhs, RHS rhs) { lhs >= rhs; };
} // namespace kk2

#endif // KK2_TYPE_TRAITS_OPERATOR_HPP
