---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: rolling_hash.hpp
      icon: LIBRARY_ALL_AC
      path: math/group/rolling_hash.hpp
    - filename: dynamic_rolling_hash.hpp
      icon: LIBRARY_ALL_AC
      path: string/dynamic_rolling_hash.hpp
    - filename: static_rolling_hash.hpp
      icon: LIBRARY_ALL_AC
      path: string/static_rolling_hash.hpp
    - filename: function_util.hpp
      icon: LIBRARY_ALL_AC
      path: template/function_util.hpp
    - filename: procon.hpp
      icon: LIBRARY_ALL_AC
      path: template/procon.hpp
    - filename: parallel.hpp
      icon: LIBRARY_ALL_AC
      path: unionfind/parallel.hpp
    - filename: aoj_alds1_14_b.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/aoj/aoj_alds1_14_b.test.cpp
    type: Required by
  - files:
    - filename: group.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/group/group.test.cpp
    - filename: dynamic_rolling_hash.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/string/dynamic_rolling_hash.test.cpp
    - filename: static_rolling_hash.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/string/static_rolling_hash.test.cpp
    - filename: concepts.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/concepts.test.cpp
    - filename: ds_range_parallel_unionfind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
    - filename: many_a_plus_b_128bit_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
    - filename: string_z_roliha.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_string/string_z_roliha.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: '#ifndef KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP

      #define KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP 1


      #include <array>

      #include <concepts>

      #include <deque>

      #include <list>

      #include <string>

      #include <type_traits>

      #include <vector>


      namespace kk2 {


      template <typename T> struct is_vector : std::false_type {};

      template <typename T, typename Alloc> struct is_vector<std::vector<T, Alloc>>
      : std::true_type {};


      template <typename T> struct is_container : std::false_type {};

      template <typename T, typename Alloc>

      struct is_container<std::vector<T, Alloc>> : std::true_type {};

      template <typename CharT, typename Traits, typename Alloc>

      struct is_container<std::basic_string<CharT, Traits, Alloc>> : std::true_type
      {};

      template <typename T, std::size_t N> struct is_container<std::array<T, N>> :
      std::true_type {};

      template <typename T, typename Alloc> struct is_container<std::deque<T, Alloc>>
      : std::true_type {};

      template <typename T, typename Alloc> struct is_container<std::list<T, Alloc>>
      : std::true_type {};

      template <typename T> using is_container_t = typename std::enable_if_t<is_container<T>::value>;


      template <class T>

      concept Vector = is_vector<std::remove_cvref_t<T>>::value;


      template <class T>

      concept Container = is_container<std::remove_cvref_t<T>>::value;


      } // namespace kk2


      #endif // KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP

      '
    name: default
  - code: '#line 1 "type_traits/container_traits.hpp"




      #include <array>

      #include <concepts>

      #include <deque>

      #include <list>

      #include <string>

      #include <type_traits>

      #include <vector>


      namespace kk2 {


      template <typename T> struct is_vector : std::false_type {};

      template <typename T, typename Alloc> struct is_vector<std::vector<T, Alloc>>
      : std::true_type {};


      template <typename T> struct is_container : std::false_type {};

      template <typename T, typename Alloc>

      struct is_container<std::vector<T, Alloc>> : std::true_type {};

      template <typename CharT, typename Traits, typename Alloc>

      struct is_container<std::basic_string<CharT, Traits, Alloc>> : std::true_type
      {};

      template <typename T, std::size_t N> struct is_container<std::array<T, N>> :
      std::true_type {};

      template <typename T, typename Alloc> struct is_container<std::deque<T, Alloc>>
      : std::true_type {};

      template <typename T, typename Alloc> struct is_container<std::list<T, Alloc>>
      : std::true_type {};

      template <typename T> using is_container_t = typename std::enable_if_t<is_container<T>::value>;


      template <class T>

      concept Vector = is_vector<std::remove_cvref_t<T>>::value;


      template <class T>

      concept Container = is_container<std::remove_cvref_t<T>>::value;


      } // namespace kk2



      '
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: type_traits/container_traits.hpp
  pathExtension: hpp
  requiredBy:
  - math/group/rolling_hash.hpp
  - string/dynamic_rolling_hash.hpp
  - string/static_rolling_hash.hpp
  - template/function_util.hpp
  - template/procon.hpp
  - unionfind/parallel.hpp
  - verify/aoj/aoj_alds1_14_b.test.cpp
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/group/group.test.cpp
  - verify/unit_test/string/dynamic_rolling_hash.test.cpp
  - verify/unit_test/string/static_rolling_hash.test.cpp
  - verify/unit_test/type_traits/concepts.test.cpp
  - verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
  - verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
  - verify/yosupo_string/string_z_roliha.test.cpp
documentation_of: type_traits/container_traits.hpp
layout: document
---
