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
      \ Alloc>> : std::true_type {};\ntemplate <typename T> struct is_container :\
      \ std::false_type {};\ntemplate <typename T, typename Alloc> struct is_container<std::vector<T,\
      \ Alloc>> : std::true_type {};\ntemplate <typename CharT, typename Traits, typename\
      \ Alloc> struct is_container<std::basic_string<CharT, Traits, Alloc>> : std::true_type\
      \ {};\ntemplate <typename T, std::size_t N> struct is_container<std::array<T,\
      \ N>> : std::true_type {};\ntemplate <typename T, typename Alloc> struct is_container<std::deque<T,\
      \ Alloc>> : std::true_type {};\ntemplate <typename T, typename Alloc> struct\
      \ is_container<std::list<T, Alloc>> : std::true_type {};\ntemplate <typename\
      \ T> using is_container_t = typename std::enable_if_t<is_container<T>::value>;\n\
      template <class T> concept Vector = is_vector<std::remove_cvref_t<T>>::value;\n\
      template <class T> concept Container = is_container<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 1 \"type_traits/functional.hpp\"\n\n\n\n#line\
      \ 6 \"type_traits/functional.hpp\"\n\n#line 1 \"type_traits/integral.hpp\"\n\
      \n\n\n#line 5 \"type_traits/integral.hpp\"\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\
      \ntemplate <typename T> using is_signed_int128 = typename std::conditional<std::is_same<T,\
      \ __int128_t>::value or std::is_same<T, __int128>::value, std::true_type, std::false_type>::type;\n\
      template <typename T> using is_unsigned_int128 = typename std::conditional<std::is_same<T,\
      \ __uint128_t>::value or std::is_same<T, unsigned __int128>::value, std::true_type,\
      \ std::false_type>::type;\ntemplate <typename T> using is_integral = typename\
      \ std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\
      \ or is_unsigned_int128<T>::value, std::true_type, std::false_type>::type;\n\
      template <typename T> using is_signed = typename std::conditional<std::is_signed<T>::value\
      \ or is_signed_int128<T>::value, std::true_type, std::false_type>::type;\ntemplate\
      \ <typename T> using is_unsigned = typename std::conditional<std::is_unsigned<T>::value\
      \ or is_unsigned_int128<T>::value, std::true_type, std::false_type>::type;\n\
      template <typename T> using make_unsigned_int128 = typename std::conditional<std::is_same<T,\
      \ __int128_t>::value, __uint128_t, unsigned __int128>;\ntemplate <typename T>\
      \ using to_unsigned = typename std::conditional<is_signed_int128<T>::value,\
      \ make_unsigned_int128<T>, typename std::conditional<std::is_signed<T>::value,\
      \ std::make_unsigned<T>, std::common_type<T>>::type>::type;\n\n#else\n\ntemplate\
      \ <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
      template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
      template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
      template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
      \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
      template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
      template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
      template <class T> concept Integral = is_integral<std::remove_cv_t<T>>::value;\n\
      template <class T> concept SignedIntegral = is_signed<std::remove_cv_t<T>>::value;\n\
      template <class T> concept UnsignedIntegral = is_unsigned<std::remove_cv_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 8 \"type_traits/functional.hpp\"\n\nnamespace\
      \ kk2 {\n\ntemplate <typename T> using is_function_pointer = typename std::conditional<std::is_pointer_v<T>\
      \ && std::is_function_v<std::remove_pointer_t<T>>, std::true_type, std::false_type>::type;\n\
      template <typename T> struct is_two_args_function_pointer : std::false_type\
      \ {};\ntemplate <typename R, typename T1, typename T2> struct is_two_args_function_pointer<R\
      \ (*)(T1, T2)> : std::true_type {\n    using return_type = R;\n    using first_argument_type\
      \ = T1;\n    using second_argument_type = T2;\n};\ntemplate <typename T> using\
      \ is_two_args_function_pointer_t = std::enable_if_t<is_two_args_function_pointer<T>::value>;\n\
      template <class T> concept FunctionPointer = is_function_pointer<T>::value;\n\
      template <class T> concept TwoArgsFunctionPointer = is_two_args_function_pointer<T>::value;\n\
      template <class T> concept UnsignedTwoArgsFunctionPointer = TwoArgsFunctionPointer<T>\
      \ && requires {\n    typename is_two_args_function_pointer<T>::first_argument_type;\n\
      \    typename is_two_args_function_pointer<T>::second_argument_type;\n} && UnsignedIntegral<typename\
      \ is_two_args_function_pointer<T>::first_argument_type> && UnsignedIntegral<typename\
      \ is_two_args_function_pointer<T>::second_argument_type>;\n\n} // namespace\
      \ kk2\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#line 5 \"type_traits/io.hpp\"\
      \n#include <fstream>\n#include <istream>\n#line 9 \"type_traits/io.hpp\"\n\n\
      namespace kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct\
      \ ostream_tag {};\n\n} // namespace type_traits\n\ntemplate <typename T> using\
      \ is_standard_istream = typename std::conditional<std::is_same<T, std::istream>::value\
      \ || std::is_same<T, std::ifstream>::value, std::true_type, std::false_type>::type;\n\
      template <typename T> using is_standard_ostream = typename std::conditional<std::is_same<T,\
      \ std::ostream>::value || std::is_same<T, std::ofstream>::value, std::true_type,\
      \ std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
      \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
      \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\
      template <typename T> using is_istream = typename std::conditional<is_standard_istream<T>::value\
      \ || is_user_defined_istream<T>::value, std::true_type, std::false_type>::type;\n\
      template <typename T> using is_ostream = typename std::conditional<is_standard_ostream<T>::value\
      \ || is_user_defined_ostream<T>::value, std::true_type, std::false_type>::type;\n\
      template <typename T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;\n\
      template <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\
      template <class T> concept StandardInputStream = is_standard_istream<std::remove_cvref_t<T>>::value;\n\
      template <class T> concept StandardOutputStream = is_standard_ostream<std::remove_cvref_t<T>>::value;\n\
      template <class T> concept InputStream = is_istream<std::remove_cvref_t<T>>::value;\n\
      template <class T> concept OutputStream = is_ostream<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 1 \"type_traits/member.hpp\"\n\n\n\n#include\
      \ <utility>\n\nnamespace kk2 {\n\ntemplate <class T, class... Ts> concept HasDebugOutput\
      \ = requires { std::declval<T>().debug_output(std::declval<Ts>()...); };\ntemplate\
      \ <class T, class... Ts> concept HasVal = requires { std::declval<T>().val(std::declval<Ts>()...);\
      \ };\n} // namespace kk2\n\n\n#line 1 \"type_traits/operator.hpp\"\n\n\n\nnamespace\
      \ kk2 {\n\ntemplate <class T> concept HasNegation = requires(T x) { -x; };\n\
      template <class LHS, class RHS = LHS> concept HasPlus = requires(LHS lhs, RHS\
      \ rhs) { lhs + rhs; };\ntemplate <class LHS, class RHS = LHS> concept HasMinus\
      \ = requires(LHS lhs, RHS rhs) { lhs - rhs; };\ntemplate <class LHS, class RHS\
      \ = LHS> concept HasMultiplies = requires(LHS lhs, RHS rhs) { lhs * rhs; };\n\
      template <class LHS, class RHS = LHS> concept HasDivides = requires(LHS lhs,\
      \ RHS rhs) { lhs / rhs; };\ntemplate <class LHS, class RHS = LHS> concept HasModulus\
      \ = requires(LHS lhs, RHS rhs) { lhs % rhs; };\ntemplate <class T> concept HasBitNot\
      \ = requires(T x) { ~x; };\ntemplate <class LHS, class RHS = LHS> concept HasBitAnd\
      \ = requires(LHS lhs, RHS rhs) { lhs & rhs; };\ntemplate <class LHS, class RHS\
      \ = LHS> concept HasBitOr = requires(LHS lhs, RHS rhs) { lhs | rhs; };\ntemplate\
      \ <class LHS, class RHS = LHS> concept HasBitXor = requires(LHS lhs, RHS rhs)\
      \ { lhs ^ rhs; };\ntemplate <class T> concept HasLogicalNot = requires(T x)\
      \ { !x; };\ntemplate <class LHS, class RHS = LHS> concept HasLogicalAnd = requires(LHS\
      \ lhs, RHS rhs) { (lhs && rhs); };\ntemplate <class LHS, class RHS = LHS> concept\
      \ HasLogicalOr = requires(LHS lhs, RHS rhs) { lhs || rhs; };\ntemplate <class\
      \ LHS, class RHS = LHS> concept HasEqualTo = requires(LHS lhs, RHS rhs) { lhs\
      \ == rhs; };\ntemplate <class LHS, class RHS = LHS> concept HasNotEqualTo =\
      \ requires(LHS lhs, RHS rhs) { lhs != rhs; };\ntemplate <class LHS, class RHS\
      \ = LHS> concept HasLess = requires(LHS lhs, RHS rhs) { lhs < rhs; };\ntemplate\
      \ <class LHS, class RHS = LHS> concept HasGreater = requires(LHS lhs, RHS rhs)\
      \ { lhs > rhs; };\ntemplate <class LHS, class RHS = LHS> concept HasLessEqual\
      \ = requires(LHS lhs, RHS rhs) { lhs <= rhs; };\ntemplate <class LHS, class\
      \ RHS = LHS> concept HasGreaterEqual = requires(LHS lhs, RHS rhs) { lhs >= rhs;\
      \ };\n} // namespace kk2\n\n\n#line 12 \"verify/unit_test/type_traits/concepts.test.cpp\"\
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
    name: bundled
  isFailed: false
  isVerificationFile: true
  path: verify/unit_test/type_traits/concepts.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases: []
  timestamp: '2026-10-11 18:25:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/type_traits/concepts.test.cpp
layout: document
---
