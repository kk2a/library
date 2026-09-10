---
data:
  attributes:
    STANDALONE: ''
    links: []
  dependencies:
  - files:
    - filename: container_traits.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/container_traits.hpp
    - filename: functional.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/functional.hpp
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    - filename: member.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/member.hpp
    - filename: operator.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/operator.hpp
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn:
  - type_traits/container_traits.hpp
  - type_traits/functional.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - type_traits/member.hpp
  - type_traits/operator.hpp
  embedded:
  - code: "// competitive-verifier: STANDALONE\n\n#include <ostream>\n#include <vector>\n\
      \n#include \"../../../type_traits/container_traits.hpp\"\n#include \"../../../type_traits/functional.hpp\"\
      \n#include \"../../../type_traits/integral.hpp\"\n#include \"../../../type_traits/io.hpp\"\
      \n#include \"../../../type_traits/member.hpp\"\n#include \"../../../type_traits/operator.hpp\"\
      \n\nstruct TaggedInput : kk2::type_traits::istream_tag {};\nstruct TaggedOutput\
      \ : kk2::type_traits::ostream_tag {};\n\nstruct Debuggable {\n    void debug_output(std::ostream\
      \ &) const {}\n};\n\nstruct HasVal {\n    int val(int) const { return 0; }\n\
      };\n\nstatic_assert(kk2::Vector<std::vector<int>>);\nstatic_assert(kk2::Container<std::vector<int>>);\n\
      static_assert(!kk2::Container<std::vector<int>::iterator>);\n\nstatic_assert(kk2::Integral<int>);\n\
      static_assert(kk2::Integral<__int128>);\nstatic_assert(kk2::SignedIntegral<int>);\n\
      static_assert(kk2::UnsignedIntegral<unsigned>);\nstatic_assert(!kk2::SignedIntegral<unsigned>);\n\
      \nstatic_assert(kk2::InputStream<std::istream>);\nstatic_assert(kk2::OutputStream<std::ostream>);\n\
      static_assert(kk2::InputStream<TaggedInput>);\nstatic_assert(kk2::OutputStream<TaggedOutput>);\n\
      static_assert(!kk2::InputStream<int>);\n\nstatic_assert(kk2::FunctionPointer<void\
      \ (*)(int, int)>);\nstatic_assert(kk2::TwoArgsFunctionPointer<void (*)(int,\
      \ int)>);\nstatic_assert(!kk2::TwoArgsFunctionPointer<void (*)(int)>);\nstatic_assert(!kk2::TwoArgsFunctionPointer<int>);\n\
      \nstatic_assert(kk2::HasDebugOutput<Debuggable, std::ostream &>);\nstatic_assert(kk2::HasVal<HasVal,\
      \ int>);\nstatic_assert(kk2::HasPlus<int>);\nstatic_assert(kk2::HasEqualTo<int>);\n\
      static_assert(kk2::HasLogicalNot<bool>);\n\nint main() {}\n"
    name: default
  - code: "#line 1 \"verify/unit_test/type_traits/concepts.test.cpp\"\n// competitive-verifier:\
      \ STANDALONE\n\n#include <ostream>\n#include <vector>\n\n#line 1 \"type_traits/container_traits.hpp\"\
      \n\n\n\n#include <array>\n#include <concepts>\n#include <deque>\n#include <list>\n\
      #include <string>\n#include <type_traits>\n#line 11 \"type_traits/container_traits.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <typename T> struct is_vector : std::false_type\
      \ {};\ntemplate <typename T, typename Alloc> struct is_vector<std::vector<T,\
      \ Alloc>> : std::true_type {};\n\ntemplate <typename T> struct is_container\
      \ : std::false_type {};\ntemplate <typename T, typename Alloc>\nstruct is_container<std::vector<T,\
      \ Alloc>> : std::true_type {};\ntemplate <typename CharT, typename Traits, typename\
      \ Alloc>\nstruct is_container<std::basic_string<CharT, Traits, Alloc>> : std::true_type\
      \ {};\ntemplate <typename T, std::size_t N> struct is_container<std::array<T,\
      \ N>> : std::true_type {};\ntemplate <typename T, typename Alloc> struct is_container<std::deque<T,\
      \ Alloc>> : std::true_type {};\ntemplate <typename T, typename Alloc> struct\
      \ is_container<std::list<T, Alloc>> : std::true_type {};\ntemplate <typename\
      \ T> using is_container_t = typename std::enable_if_t<is_container<T>::value>;\n\
      \ntemplate <class T>\nconcept Vector = is_vector<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept Container = is_container<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 1 \"type_traits/functional.hpp\"\n\n\n\n#line\
      \ 5 \"type_traits/functional.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename\
      \ T>\nusing is_function_pointer =\n    typename std::conditional<std::is_pointer_v<T>\
      \ && std::is_function_v<std::remove_pointer_t<T>>,\n                       \
      \       std::true_type,\n                              std::false_type>::type;\n\
      \ntemplate <typename T> struct is_two_args_function_pointer : std::false_type\
      \ {};\n\ntemplate <typename R, typename T1, typename T2>\nstruct is_two_args_function_pointer<R\
      \ (*)(T1, T2)> : std::true_type {};\n\ntemplate <typename T>\nusing is_two_args_function_pointer_t\
      \ = std::enable_if_t<is_two_args_function_pointer<T>::value>;\n\ntemplate <class\
      \ T>\nconcept FunctionPointer = is_function_pointer<T>::value;\n\ntemplate <class\
      \ T>\nconcept TwoArgsFunctionPointer = is_two_args_function_pointer<T>::value;\n\
      \n} // namespace kk2\n\n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#line\
      \ 5 \"type_traits/integral.hpp\"\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\n\
      template <typename T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T,\
      \ __int128_t>::value\n                                                     \
      \  or std::is_same<T, __int128>::value,\n                                  \
      \                 std::true_type,\n                                        \
      \           std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_int128\
      \ =\n    typename std::conditional<std::is_same<T, __uint128_t>::value\n   \
      \                               or std::is_same<T, unsigned __int128>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T>\nusing is_integral =\n\
      \    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
      \                                  or is_unsigned_int128<T>::value,\n      \
      \                        std::true_type,\n                              std::false_type>::type;\n\
      \ntemplate <typename T>\nusing is_signed = typename std::conditional<std::is_signed<T>::value\
      \ or is_signed_int128<T>::value,\n                                         \
      \   std::true_type,\n                                            std::false_type>::type;\n\
      \ntemplate <typename T>\nusing is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
      \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename\
      \ T>\nusing to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
      \                              make_unsigned_int128<T>,\n                  \
      \            typename std::conditional<std::is_signed<T>::value,\n         \
      \                                               std::make_unsigned<T>,\n   \
      \                                                     std::common_type<T>>::type>::type;\n\
      \n#else\n\ntemplate <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
      template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
      template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
      template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
      \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
      template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
      template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
      \ntemplate <class T>\nconcept Integral = is_integral<std::remove_cv_t<T>>::value;\n\
      \ntemplate <class T>\nconcept SignedIntegral = is_signed<std::remove_cv_t<T>>::value;\n\
      \ntemplate <class T>\nconcept UnsignedIntegral = is_unsigned<std::remove_cv_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#line 5 \"type_traits/io.hpp\"\
      \n#include <fstream>\n#include <istream>\n#line 9 \"type_traits/io.hpp\"\n\n\
      namespace kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct\
      \ ostream_tag {};\n\n} // namespace type_traits\n\ntemplate <typename T>\nusing\
      \ is_standard_istream = typename std::conditional<std::is_same<T, std::istream>::value\n\
      \                                                          || std::is_same<T,\
      \ std::ifstream>::value,\n                                                 \
      \     std::true_type,\n                                                    \
      \  std::false_type>::type;\ntemplate <typename T>\nusing is_standard_ostream\
      \ = typename std::conditional<std::is_same<T, std::ostream>::value\n       \
      \                                                   || std::is_same<T, std::ofstream>::value,\n\
      \                                                      std::true_type,\n   \
      \                                                   std::false_type>::type;\n\
      template <typename T> using is_user_defined_istream = std::is_base_of<type_traits::istream_tag,\
      \ T>;\ntemplate <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
      \ T>;\n\ntemplate <typename T>\nusing is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
      \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
      \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate\
      \ <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\
      \ntemplate <class T>\nconcept StandardInputStream = is_standard_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept StandardOutputStream = is_standard_ostream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept InputStream = is_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept OutputStream = is_ostream<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 1 \"type_traits/member.hpp\"\n\n\n\n#line 5\
      \ \"type_traits/member.hpp\"\n\nnamespace kk2 {\n// BEGIN_PRESERVE_NEWLINES\n\
      \n#define HAS_MEMBER_FUNC(member)                                          \
      \                          \\\n    template <typename T, typename... Ts> struct\
      \ has_member_func_##member##_impl {                 \\\n        template <typename\
      \ U>                                                                      \\\
      \n        static std::true_type check(decltype(std::declval<U>().member(std::declval<Ts>()...))\
      \ *);  \\\n        template <typename U> static std::false_type check(...);\
      \                                   \\\n        using type = decltype(check<T>(nullptr));\
      \                                                  \\\n    };              \
      \                                                                          \
      \     \\\n    template <typename T, typename... Ts>                        \
      \                                  \\\n    struct has_member_func_##member :\
      \ has_member_func_##member##_impl<T, Ts...>::type {};          \\\n    template\
      \ <typename T, typename... Ts>                                             \
      \             \\\n    using has_member_func_##member##_t =                 \
      \                                          \\\n        std::enable_if_t<has_member_func_##member<T,\
      \ Ts...>::value>;                               \\\n    template <typename T,\
      \ typename... Ts>                                                          \\\
      \n    using not_has_member_func_##member##_t =                             \
      \                          \\\n        std::enable_if_t<!has_member_func_##member<T,\
      \ Ts...>::value>;\n\n#define HAS_MEMBER_VAR(member)                        \
      \                                             \\\n    template <typename T>\
      \ struct has_member_var_##member##_impl {                                  \\\
      \n        template <typename U> static std::true_type check(decltype(std::declval<U>().member)\
      \ *);   \\\n        template <typename U> static std::false_type check(...);\
      \                                   \\\n        using type = decltype(check<T>(nullptr));\
      \                                                  \\\n    };              \
      \                                                                          \
      \     \\\n    template <typename T>                                        \
      \                                  \\\n    struct has_member_var_##member :\
      \ has_member_var_##member##_impl<T>::type {};                   \\\n    template\
      \ <typename T>                                                             \
      \             \\\n    using has_member_var_##member##_t = std::enable_if_t<has_member_var_##member<T>::value>;\
      \       \\\n    template <typename T>                                      \
      \                                    \\\n    using not_has_member_var_##member##_t\
      \ = std::enable_if_t<!has_member_var_##member<T>::value>;\n\nHAS_MEMBER_FUNC(debug_output)\n\
      HAS_MEMBER_FUNC(val)\n\ntemplate <class T, class... Ts>\nconcept HasDebugOutput\
      \ = has_member_func_debug_output<T, Ts...>::value;\n\ntemplate <class T, class...\
      \ Ts>\nconcept HasVal = has_member_func_val<T, Ts...>::value;\n\n// END_PRESERVE_NEWLINES\n\
      \n#undef HAS_MEMBER_FUNC\n#undef HAS_MEMBER_VAR\n} // namespace kk2\n\n\n#line\
      \ 1 \"type_traits/operator.hpp\"\n\n\n\n#line 5 \"type_traits/operator.hpp\"\
      \n\nnamespace kk2 {\n// BEGIN_PRESERVE_NEWLINES\n\n#define HAS_BINARY_OP(op,\
      \ op_name)                                                                 \\\
      \n    template <typename LHS, typename RHS> struct has_binary_op_##op_name##_impl\
      \ {                  \\\n        template <typename LHS2, typename RHS2>   \
      \                                                 \\\n        static std::true_type\
      \ check(decltype(std::declval<LHS2>() op std::declval<RHS2>()) *);     \\\n\
      \        template <typename, typename> static std::false_type check(...);  \
      \                         \\\n        using type = decltype(check<LHS, RHS>(nullptr));\
      \                                           \\\n    };                     \
      \                                                                        \\\n\
      \    template <typename LHS, typename RHS = LHS>                           \
      \                         \\\n    struct has_binary_op_##op_name : has_binary_op_##op_name##_impl<LHS,\
      \ RHS>::type {};            \\\n    template <typename LHS, typename RHS = LHS>\
      \                                                    \\\n    using has_binary_op_##op_name##_t\
      \ =                                                            \\\n        std::enable_if_t<has_binary_op_##op_name<LHS,\
      \ RHS>::value>;\n\n#define HAS_UNARY_OP(op, op_name)                       \
      \                                           \\\n    template <typename T> struct\
      \ has_unary_op_##op_name##_impl {                                   \\\n   \
      \     template <typename U> static std::true_type check(decltype(op std::declval<T>())\
      \ *);       \\\n        template <typename U> static std::false_type check(...);\
      \                                   \\\n        using type = decltype(check<T>(nullptr));\
      \                                                  \\\n    };              \
      \                                                                          \
      \     \\\n    template <typename T>                                        \
      \                                  \\\n    struct has_unary_op_##op_name : has_unary_op_##op_name##_impl<T>::type\
      \ {};                     \\\n    template <typename T>                    \
      \                                                      \\\n    using has_unary_op_##op_name##_t\
      \ = std::enable_if_t<has_unary_op_##op_name<T>::value>;\n\nHAS_UNARY_OP(-, negation)\n\
      HAS_BINARY_OP(+, plus)\nHAS_BINARY_OP(-, minus)\nHAS_BINARY_OP(*, multiplies)\n\
      HAS_BINARY_OP(/, divides)\nHAS_BINARY_OP(%, modulus)\n\nHAS_UNARY_OP(~, bit_not)\n\
      HAS_BINARY_OP(&, bit_and)\nHAS_BINARY_OP(|, bit_or)\nHAS_BINARY_OP(^, bit_xor)\n\
      \nHAS_UNARY_OP(!, logical_not)\nHAS_BINARY_OP(&&, logical_and)\nHAS_BINARY_OP(||,\
      \ logical_or)\n\nHAS_BINARY_OP(==, equal_to)\nHAS_BINARY_OP(!=, not_equal_to)\n\
      HAS_BINARY_OP(<, less)\nHAS_BINARY_OP(>, greater)\nHAS_BINARY_OP(<=, less_equal)\n\
      HAS_BINARY_OP(>=, greater_equal)\n\n#define HAS_UNARY_CONCEPT(op, name)    \
      \                                                            \\\n    template\
      \ <class T>                                                                \
      \             \\\n    concept Has##name = requires(T x) { op x; };\n\n#define\
      \ HAS_BINARY_CONCEPT(op, name)                                             \
      \                  \\\n    template <class LHS, class RHS = LHS>           \
      \                                               \\\n    concept Has##name =\
      \ requires(LHS lhs, RHS rhs) { lhs op rhs; };\n\nHAS_UNARY_CONCEPT(-, Negation)\n\
      HAS_BINARY_CONCEPT(+, Plus)\nHAS_BINARY_CONCEPT(-, Minus)\nHAS_BINARY_CONCEPT(*,\
      \ Multiplies)\nHAS_BINARY_CONCEPT(/, Divides)\nHAS_BINARY_CONCEPT(%, Modulus)\n\
      HAS_UNARY_CONCEPT(~, BitNot)\nHAS_BINARY_CONCEPT(&, BitAnd)\nHAS_BINARY_CONCEPT(|,\
      \ BitOr)\nHAS_BINARY_CONCEPT(^, BitXor)\nHAS_UNARY_CONCEPT(!, LogicalNot)\n\
      HAS_BINARY_CONCEPT(&&, LogicalAnd)\nHAS_BINARY_CONCEPT(||, LogicalOr)\nHAS_BINARY_CONCEPT(==,\
      \ EqualTo)\nHAS_BINARY_CONCEPT(!=, NotEqualTo)\nHAS_BINARY_CONCEPT(<, Less)\n\
      HAS_BINARY_CONCEPT(>, Greater)\nHAS_BINARY_CONCEPT(<=, LessEqual)\nHAS_BINARY_CONCEPT(>=,\
      \ GreaterEqual)\n\n#undef HAS_UNARY_CONCEPT\n#undef HAS_BINARY_CONCEPT\n\n//\
      \ END_PRESERVE_NEWLINES\n\n#undef HAS_BINARY_OP\n#undef HAS_UNARY_OP\n} // namespace\
      \ kk2\n\n\n#line 12 \"verify/unit_test/type_traits/concepts.test.cpp\"\n\nstruct\
      \ TaggedInput : kk2::type_traits::istream_tag {};\nstruct TaggedOutput : kk2::type_traits::ostream_tag\
      \ {};\n\nstruct Debuggable {\n    void debug_output(std::ostream &) const {}\n\
      };\n\nstruct HasVal {\n    int val(int) const { return 0; }\n};\n\nstatic_assert(kk2::Vector<std::vector<int>>);\n\
      static_assert(kk2::Container<std::vector<int>>);\nstatic_assert(!kk2::Container<std::vector<int>::iterator>);\n\
      \nstatic_assert(kk2::Integral<int>);\nstatic_assert(kk2::Integral<__int128>);\n\
      static_assert(kk2::SignedIntegral<int>);\nstatic_assert(kk2::UnsignedIntegral<unsigned>);\n\
      static_assert(!kk2::SignedIntegral<unsigned>);\n\nstatic_assert(kk2::InputStream<std::istream>);\n\
      static_assert(kk2::OutputStream<std::ostream>);\nstatic_assert(kk2::InputStream<TaggedInput>);\n\
      static_assert(kk2::OutputStream<TaggedOutput>);\nstatic_assert(!kk2::InputStream<int>);\n\
      \nstatic_assert(kk2::FunctionPointer<void (*)(int, int)>);\nstatic_assert(kk2::TwoArgsFunctionPointer<void\
      \ (*)(int, int)>);\nstatic_assert(!kk2::TwoArgsFunctionPointer<void (*)(int)>);\n\
      static_assert(!kk2::TwoArgsFunctionPointer<int>);\n\nstatic_assert(kk2::HasDebugOutput<Debuggable,\
      \ std::ostream &>);\nstatic_assert(kk2::HasVal<HasVal, int>);\nstatic_assert(kk2::HasPlus<int>);\n\
      static_assert(kk2::HasEqualTo<int>);\nstatic_assert(kk2::HasLogicalNot<bool>);\n\
      \nint main() {}\n"
    name: bundled
  isFailed: false
  isVerificationFile: true
  path: verify/unit_test/type_traits/concepts.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases: []
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/type_traits/concepts.test.cpp
layout: document
---
