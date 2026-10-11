---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: debug.hpp
      icon: LIBRARY_NO_TESTS
      path: template/debug.hpp
    type: Required by
  - files:
    - filename: concepts.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/concepts.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: '#ifndef KK2_TYPE_TRAITS_MEMBER_HPP

      #define KK2_TYPE_TRAITS_MEMBER_HPP 1


      #include <utility>


      namespace kk2 {


      template <class T, class... Ts> concept HasDebugOutput = requires { std::declval<T>().debug_output(std::declval<Ts>()...);
      };

      template <class T, class... Ts> concept HasVal = requires { std::declval<T>().val(std::declval<Ts>()...);
      };

      } // namespace kk2


      #endif // KK2_TYPE_TRAITS_MEMBER_HPP

      '
    name: default
  - code: '#line 1 "type_traits/member.hpp"




      #include <utility>


      namespace kk2 {


      template <class T, class... Ts> concept HasDebugOutput = requires { std::declval<T>().debug_output(std::declval<Ts>()...);
      };

      template <class T, class... Ts> concept HasVal = requires { std::declval<T>().val(std::declval<Ts>()...);
      };

      } // namespace kk2



      '
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: type_traits/member.hpp
  pathExtension: hpp
  requiredBy:
  - template/debug.hpp
  timestamp: '2026-10-11 18:25:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/type_traits/concepts.test.cpp
documentation_of: type_traits/member.hpp
layout: document
---
