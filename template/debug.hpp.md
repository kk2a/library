---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    - filename: member.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/member.hpp
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn:
  - type_traits/io.hpp
  - type_traits/member.hpp
  embedded:
  - code: "#ifndef KK2_TEMPLATE_DEBUG_HPP\n#define KK2_TEMPLATE_DEBUG_HPP 1\n\n#include\
      \ <array>\n#include <deque>\n#include <iostream>\n#include <map>\n#include <queue>\n\
      #include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n#include\
      \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include <vector>\n\
      \n#include \"../type_traits/io.hpp\"\n#include \"../type_traits/member.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace debug {\n\n#ifdef KK2\n\ntemplate <OutputStream\
      \ OStream> void output(OStream &os);\ntemplate <OutputStream OStream, class\
      \ T> void output(OStream &os, const T &t);\ntemplate <OutputStream OStream,\
      \ class T, class... Args>\nvoid output(OStream &os, const T &t, const Args &...args);\n\
      template <OutputStream OStream, class T> void output(OStream &os, const std::vector<T>\
      \ &v);\ntemplate <OutputStream OStream, class T>\nvoid output(OStream &os, const\
      \ std::vector<std::vector<T>> &d);\ntemplate <OutputStream OStream, class T,\
      \ size_t F>\nvoid output(OStream &os, const std::array<T, F> &a);\ntemplate\
      \ <OutputStream OStream, class T, class U>\nvoid output(OStream &os, const std::pair<T,\
      \ U> &p);\ntemplate <OutputStream OStream, class... Args>\nvoid output(OStream\
      \ &os, const std::tuple<Args...> &t);\ntemplate <OutputStream OStream, class\
      \ T> void output(OStream &os, const std::queue<T> &q);\ntemplate <OutputStream\
      \ OStream, class T, class Container, class Compare>\nvoid output(OStream &os,\
      \ const std::priority_queue<T, Container, Compare> &q);\ntemplate <OutputStream\
      \ OStream, class T> void output(OStream &os, const std::deque<T> &d);\ntemplate\
      \ <OutputStream OStream, class T> void output(OStream &os, const std::stack<T>\
      \ &s);\ntemplate <OutputStream OStream, class Key, class Compare, class Allocator>\n\
      void output(OStream &os, const std::set<Key, Compare, Allocator> &s);\ntemplate\
      \ <OutputStream OStream, class Key, class Compare, class Allocator>\nvoid output(OStream\
      \ &os, const std::multiset<Key, Compare, Allocator> &s);\ntemplate <OutputStream\
      \ OStream, class Key, class Hash, class KeyEqual, class Allocator>\nvoid output(OStream\
      \ &os, const std::unordered_set<Key, Hash, KeyEqual, Allocator> &s);\ntemplate\
      \ <OutputStream OStream, class Key, class Hash, class KeyEqual, class Allocator>\n\
      void output(OStream &os, const std::unordered_multiset<Key, Hash, KeyEqual,\
      \ Allocator> &s);\ntemplate <OutputStream OStream, class Key, class T, class\
      \ Compare, class Allocator>\nvoid output(OStream &os, const std::map<Key, T,\
      \ Compare, Allocator> &m);\ntemplate <OutputStream OStream, class Key, class\
      \ T, class Hash, class KeyEqual, class Allocator>\nvoid output(OStream &os,\
      \ const std::unordered_map<Key, T, Hash, KeyEqual, Allocator> &m);\ntemplate\
      \ <OutputStream OStream> void output(OStream &) {}\ntemplate <OutputStream OStream,\
      \ class T> void output(OStream &os, const T &t) {\n    if constexpr (HasDebugOutput<T,\
      \ OStream &>) {\n        t.debug_output(os);\n    } else {\n        os << t;\n\
      \    }\n}\ntemplate <OutputStream OStream, class T, class... Args>\nvoid output(OStream\
      \ &os, const T &t, const Args &...args) {\n    output(os, t);\n    os << \"\
      , \";\n    output(os, args...);\n}\ntemplate <OutputStream OStream, class T>\
      \ void output(OStream &os, const std::vector<T> &v) {\n    os << \"[\";\n  \
      \  for (int i = 0; i < (int)v.size(); i++) {\n        output(os, v[i]);\n  \
      \      if (i + 1 != (int)v.size()) os << \", \";\n    }\n    os << \"]\";\n\
      }\ntemplate <OutputStream OStream, class T>\nvoid output(OStream &os, const\
      \ std::vector<std::vector<T>> &d) {\n    os << \"[\\n\";\n    for (int i = 0;\
      \ i < (int)d.size(); i++) {\n        output(os, d[i]);\n        output(os, \"\
      \\n\");\n    }\n    os << \"]\";\n}\ntemplate <OutputStream OStream, class T,\
      \ size_t F>\nvoid output(OStream &os, const std::array<T, F> &a) {\n    os <<\
      \ \"[\";\n    for (int i = 0; i < (int)F; i++) {\n        output(os, a[i]);\n\
      \        if (i + 1 != (int)F) os << \", \";\n    }\n    os << \"]\";\n}\ntemplate\
      \ <OutputStream OStream, class T, class U>\nvoid output(OStream &os, const std::pair<T,\
      \ U> &p) {\n    os << \"(\";\n    output(os, p.first);\n    os << \", \";\n\
      \    output(os, p.second);\n    os << \")\";\n}\ntemplate <OutputStream OStream,\
      \ class... Args>\nvoid output(OStream &os, const std::tuple<Args...> &t) {\n\
      \    os << \"(\";\n    std::apply([&](const Args &...args) { output(os, args...);\
      \ }, t);\n    os << \")\";\n}\ntemplate <OutputStream OStream, class T> void\
      \ output(OStream &os, const std::queue<T> &q) {\n    os << \"[\";\n    std::queue<T>\
      \ tmp = q;\n    while (!tmp.empty()) {\n        output(os, tmp.front());\n \
      \       tmp.pop();\n        if (!tmp.empty()) os << \", \";\n    }\n    os <<\
      \ \"]\";\n}\ntemplate <OutputStream OStream, class T, class Container, class\
      \ Compare>\nvoid output(OStream &os, const std::priority_queue<T, Container,\
      \ Compare> &q) {\n    os << \"[\";\n    std::priority_queue<T, Container, Compare>\
      \ tmp = q;\n    while (!tmp.empty()) {\n        output(os, tmp.top());\n   \
      \     tmp.pop();\n        if (!tmp.empty()) os << \", \";\n    }\n    os <<\
      \ \"]\";\n}\ntemplate <OutputStream OStream, class T> void output(OStream &os,\
      \ const std::deque<T> &d) {\n    os << \"[\";\n    std::deque<T> tmp = d;\n\
      \    while (!tmp.empty()) {\n        output(os, tmp.front());\n        tmp.pop_front();\n\
      \        if (!tmp.empty()) os << \", \";\n    }\n    os << \"]\";\n}\ntemplate\
      \ <OutputStream OStream, class T> void output(OStream &os, const std::stack<T>\
      \ &s) {\n    os << \"[\";\n    std::stack<T> tmp = s;\n    std::vector<T> v;\n\
      \    while (!tmp.empty()) {\n        v.push_back(tmp.top());\n        tmp.pop();\n\
      \    }\n    for (int i = (int)v.size() - 1; i >= 0; i--) {\n        output(os,\
      \ v[i]);\n        if (i != 0) os << \", \";\n    }\n    os << \"]\";\n}\ntemplate\
      \ <OutputStream OStream, class Key, class Compare, class Allocator>\nvoid output(OStream\
      \ &os, const std::set<Key, Compare, Allocator> &s) {\n    os << \"{\";\n   \
      \ std::set<Key, Compare, Allocator> tmp = s;\n    for (auto it = tmp.begin();\
      \ it != tmp.end(); ++it) {\n        output(os, *it);\n        if (std::next(it)\
      \ != tmp.end()) os << \", \";\n    }\n    os << \"}\";\n}\ntemplate <OutputStream\
      \ OStream, class Key, class Compare, class Allocator>\nvoid output(OStream &os,\
      \ const std::multiset<Key, Compare, Allocator> &s) {\n    os << \"{\";\n   \
      \ std::multiset<Key, Compare, Allocator> tmp = s;\n    for (auto it = tmp.begin();\
      \ it != tmp.end(); ++it) {\n        output(os, *it);\n        if (std::next(it)\
      \ != tmp.end()) os << \", \";\n    }\n    os << \"}\";\n}\ntemplate <OutputStream\
      \ OStream, class Key, class Hash, class KeyEqual, class Allocator>\nvoid output(OStream\
      \ &os, const std::unordered_set<Key, Hash, KeyEqual, Allocator> &s) {\n    os\
      \ << \"{\";\n    std::unordered_set<Key, Hash, KeyEqual, Allocator> tmp = s;\n\
      \    for (auto it = tmp.begin(); it != tmp.end(); ++it) {\n        output(os,\
      \ *it);\n        if (std::next(it) != tmp.end()) os << \", \";\n    }\n    os\
      \ << \"}\";\n}\ntemplate <OutputStream OStream, class Key, class Hash, class\
      \ KeyEqual, class Allocator>\nvoid output(OStream &os, const std::unordered_multiset<Key,\
      \ Hash, KeyEqual, Allocator> &s) {\n    os << \"{\";\n    std::unordered_multiset<Key,\
      \ Hash, KeyEqual, Allocator> tmp = s;\n    for (auto it = tmp.begin(); it !=\
      \ tmp.end(); ++it) {\n        output(os, *it);\n        if (std::next(it) !=\
      \ tmp.end()) os << \", \";\n    }\n    os << \"}\";\n}\ntemplate <OutputStream\
      \ OStream, class Key, class T, class Compare, class Allocator>\nvoid output(OStream\
      \ &os, const std::map<Key, T, Compare, Allocator> &m) {\n    os << \"{\";\n\
      \    std::map<Key, T, Compare, Allocator> tmp = m;\n    for (auto it = tmp.begin();\
      \ it != tmp.end(); ++it) {\n        output(os, it->first);\n        os << \"\
      : \";\n        output(os, it->second);\n        if (std::next(it) != tmp.end())\
      \ os << \", \";\n    }\n    os << \"}\";\n}\ntemplate <OutputStream OStream,\
      \ class Key, class T, class Hash, class KeyEqual, class Allocator>\nvoid output(OStream\
      \ &os, const std::unordered_map<Key, T, Hash, KeyEqual, Allocator> &m) {\n \
      \   os << \"{\";\n    std::unordered_map<Key, T, Hash, KeyEqual, Allocator>\
      \ tmp = m;\n    for (auto it = tmp.begin(); it != tmp.end(); ++it) {\n     \
      \   output(os, it->first);\n        os << \": \";\n        output(os, it->second);\n\
      \        if (std::next(it) != tmp.end()) os << \", \";\n    }\n    os << \"\
      }\";\n}\ntemplate <OutputStream OStream> void outputln(OStream &os) {\n    os\
      \ << '\\n';\n    os.flush();\n}\ntemplate <OutputStream OStream, class T, class...\
      \ Args>\nvoid outputln(OStream &os, const T &t, const Args &...args) {\n   \
      \ output(os, t, args...);\n    os << '\\n';\n    os.flush();\n}\nstd::vector<std::string>\
      \ sep(const char *s) {\n    std::vector<std::string> res;\n    std::string now;\n\
      \    int dep = 0;\n    while (true) {\n        if (*s == '\\0') {\n        \
      \    res.emplace_back(now);\n            break;\n        }\n        if (*s ==\
      \ '(' or *s == '[' or *s == '{') dep++;\n        if (*s == ')' or *s == ']'\
      \ or *s == '}') dep--;\n        if (dep == 0 and *s == ',') {\n            res.emplace_back(now);\n\
      \            now.clear();\n        } else if (!isspace(*s)) {\n            now\
      \ += *s;\n        }\n        s++;\n    }\n    return res;\n}\nvoid show_vars(const\
      \ std::vector<std::string> &, int) {}\ntemplate <class T, class... Args>\nvoid\
      \ show_vars(const std::vector<std::string> &name, int pos, const T &t, const\
      \ Args &...args) {\n    output(std::cerr, name[pos++] + \":\");\n    output(std::cerr,\
      \ t);\n    if (sizeof...(args) > 0) output(std::cerr, \", \");\n    show_vars(name,\
      \ pos, args...);\n}\n\n#define kdebug(...)                                 \
      \                                               \\\n    {                  \
      \                                                                          \
      \  \\\n        std::cerr << \"line:\" << __LINE__ << ' ';                  \
      \                                 \\\n        kk2::debug::show_vars(kk2::debug::sep(#__VA_ARGS__),\
      \ 0, __VA_ARGS__);                      \\\n        std::cerr << std::endl;\
      \                                                                    \\\n  \
      \  }\n\n#define kput(s)                                                    \
      \                                \\\n    {                                 \
      \                                                             \\\n        std::cerr\
      \ << \"line:\" << __LINE__ << ' ';                                         \
      \          \\\n        kk2::debug::outputln(std::cerr, s);                 \
      \                                       \\\n    }\n\n#else\n\ntemplate <OutputStream\
      \ OStream, class... Args> void output(OStream &, const Args &...) {}\ntemplate\
      \ <OutputStream OStream, class... Args> void outputln(OStream &, const Args\
      \ &...) {}\ntemplate <class... Args> void fix_warn(const Args &...) {}\n#define\
      \ kdebug(...) kk2::debug::fix_warn(__VA_ARGS__);\n#define kput(s) kk2::debug::fix_warn(s)\n\
      \n#endif // KK2\n\n} // namespace debug\n\n} // namespace kk2\n\n#endif // KK2_TEMPLATE_DEBUG_HPP\n"
    name: default
  - code: "#line 1 \"template/debug.hpp\"\n\n\n\n#include <array>\n#include <deque>\n\
      #include <iostream>\n#include <map>\n#include <queue>\n#include <set>\n#include\
      \ <stack>\n#include <string>\n#include <tuple>\n#include <unordered_map>\n#include\
      \ <unordered_set>\n#include <utility>\n#include <vector>\n\n#line 1 \"type_traits/io.hpp\"\
      \n\n\n\n#include <concepts>\n#include <fstream>\n#include <istream>\n#include\
      \ <ostream>\n#include <type_traits>\n\nnamespace kk2 {\n\nnamespace type_traits\
      \ {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\
      \ntemplate <typename T>\nusing is_standard_istream = typename std::conditional<std::is_same<T,\
      \ std::istream>::value\n                                                   \
      \       || std::is_same<T, std::ifstream>::value,\n                        \
      \                              std::true_type,\n                           \
      \                           std::false_type>::type;\ntemplate <typename T>\n\
      using is_standard_ostream = typename std::conditional<std::is_same<T, std::ostream>::value\n\
      \                                                          || std::is_same<T,\
      \ std::ofstream>::value,\n                                                 \
      \     std::true_type,\n                                                    \
      \  std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
      \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
      \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
      template <typename T>\nusing is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
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
      \ 20 \"template/debug.hpp\"\n\nnamespace kk2 {\n\nnamespace debug {\n\n#ifdef\
      \ KK2\n\ntemplate <OutputStream OStream> void output(OStream &os);\ntemplate\
      \ <OutputStream OStream, class T> void output(OStream &os, const T &t);\ntemplate\
      \ <OutputStream OStream, class T, class... Args>\nvoid output(OStream &os, const\
      \ T &t, const Args &...args);\ntemplate <OutputStream OStream, class T> void\
      \ output(OStream &os, const std::vector<T> &v);\ntemplate <OutputStream OStream,\
      \ class T>\nvoid output(OStream &os, const std::vector<std::vector<T>> &d);\n\
      template <OutputStream OStream, class T, size_t F>\nvoid output(OStream &os,\
      \ const std::array<T, F> &a);\ntemplate <OutputStream OStream, class T, class\
      \ U>\nvoid output(OStream &os, const std::pair<T, U> &p);\ntemplate <OutputStream\
      \ OStream, class... Args>\nvoid output(OStream &os, const std::tuple<Args...>\
      \ &t);\ntemplate <OutputStream OStream, class T> void output(OStream &os, const\
      \ std::queue<T> &q);\ntemplate <OutputStream OStream, class T, class Container,\
      \ class Compare>\nvoid output(OStream &os, const std::priority_queue<T, Container,\
      \ Compare> &q);\ntemplate <OutputStream OStream, class T> void output(OStream\
      \ &os, const std::deque<T> &d);\ntemplate <OutputStream OStream, class T> void\
      \ output(OStream &os, const std::stack<T> &s);\ntemplate <OutputStream OStream,\
      \ class Key, class Compare, class Allocator>\nvoid output(OStream &os, const\
      \ std::set<Key, Compare, Allocator> &s);\ntemplate <OutputStream OStream, class\
      \ Key, class Compare, class Allocator>\nvoid output(OStream &os, const std::multiset<Key,\
      \ Compare, Allocator> &s);\ntemplate <OutputStream OStream, class Key, class\
      \ Hash, class KeyEqual, class Allocator>\nvoid output(OStream &os, const std::unordered_set<Key,\
      \ Hash, KeyEqual, Allocator> &s);\ntemplate <OutputStream OStream, class Key,\
      \ class Hash, class KeyEqual, class Allocator>\nvoid output(OStream &os, const\
      \ std::unordered_multiset<Key, Hash, KeyEqual, Allocator> &s);\ntemplate <OutputStream\
      \ OStream, class Key, class T, class Compare, class Allocator>\nvoid output(OStream\
      \ &os, const std::map<Key, T, Compare, Allocator> &m);\ntemplate <OutputStream\
      \ OStream, class Key, class T, class Hash, class KeyEqual, class Allocator>\n\
      void output(OStream &os, const std::unordered_map<Key, T, Hash, KeyEqual, Allocator>\
      \ &m);\ntemplate <OutputStream OStream> void output(OStream &) {}\ntemplate\
      \ <OutputStream OStream, class T> void output(OStream &os, const T &t) {\n \
      \   if constexpr (HasDebugOutput<T, OStream &>) {\n        t.debug_output(os);\n\
      \    } else {\n        os << t;\n    }\n}\ntemplate <OutputStream OStream, class\
      \ T, class... Args>\nvoid output(OStream &os, const T &t, const Args &...args)\
      \ {\n    output(os, t);\n    os << \", \";\n    output(os, args...);\n}\ntemplate\
      \ <OutputStream OStream, class T> void output(OStream &os, const std::vector<T>\
      \ &v) {\n    os << \"[\";\n    for (int i = 0; i < (int)v.size(); i++) {\n \
      \       output(os, v[i]);\n        if (i + 1 != (int)v.size()) os << \", \"\
      ;\n    }\n    os << \"]\";\n}\ntemplate <OutputStream OStream, class T>\nvoid\
      \ output(OStream &os, const std::vector<std::vector<T>> &d) {\n    os << \"\
      [\\n\";\n    for (int i = 0; i < (int)d.size(); i++) {\n        output(os, d[i]);\n\
      \        output(os, \"\\n\");\n    }\n    os << \"]\";\n}\ntemplate <OutputStream\
      \ OStream, class T, size_t F>\nvoid output(OStream &os, const std::array<T,\
      \ F> &a) {\n    os << \"[\";\n    for (int i = 0; i < (int)F; i++) {\n     \
      \   output(os, a[i]);\n        if (i + 1 != (int)F) os << \", \";\n    }\n \
      \   os << \"]\";\n}\ntemplate <OutputStream OStream, class T, class U>\nvoid\
      \ output(OStream &os, const std::pair<T, U> &p) {\n    os << \"(\";\n    output(os,\
      \ p.first);\n    os << \", \";\n    output(os, p.second);\n    os << \")\";\n\
      }\ntemplate <OutputStream OStream, class... Args>\nvoid output(OStream &os,\
      \ const std::tuple<Args...> &t) {\n    os << \"(\";\n    std::apply([&](const\
      \ Args &...args) { output(os, args...); }, t);\n    os << \")\";\n}\ntemplate\
      \ <OutputStream OStream, class T> void output(OStream &os, const std::queue<T>\
      \ &q) {\n    os << \"[\";\n    std::queue<T> tmp = q;\n    while (!tmp.empty())\
      \ {\n        output(os, tmp.front());\n        tmp.pop();\n        if (!tmp.empty())\
      \ os << \", \";\n    }\n    os << \"]\";\n}\ntemplate <OutputStream OStream,\
      \ class T, class Container, class Compare>\nvoid output(OStream &os, const std::priority_queue<T,\
      \ Container, Compare> &q) {\n    os << \"[\";\n    std::priority_queue<T, Container,\
      \ Compare> tmp = q;\n    while (!tmp.empty()) {\n        output(os, tmp.top());\n\
      \        tmp.pop();\n        if (!tmp.empty()) os << \", \";\n    }\n    os\
      \ << \"]\";\n}\ntemplate <OutputStream OStream, class T> void output(OStream\
      \ &os, const std::deque<T> &d) {\n    os << \"[\";\n    std::deque<T> tmp =\
      \ d;\n    while (!tmp.empty()) {\n        output(os, tmp.front());\n       \
      \ tmp.pop_front();\n        if (!tmp.empty()) os << \", \";\n    }\n    os <<\
      \ \"]\";\n}\ntemplate <OutputStream OStream, class T> void output(OStream &os,\
      \ const std::stack<T> &s) {\n    os << \"[\";\n    std::stack<T> tmp = s;\n\
      \    std::vector<T> v;\n    while (!tmp.empty()) {\n        v.push_back(tmp.top());\n\
      \        tmp.pop();\n    }\n    for (int i = (int)v.size() - 1; i >= 0; i--)\
      \ {\n        output(os, v[i]);\n        if (i != 0) os << \", \";\n    }\n \
      \   os << \"]\";\n}\ntemplate <OutputStream OStream, class Key, class Compare,\
      \ class Allocator>\nvoid output(OStream &os, const std::set<Key, Compare, Allocator>\
      \ &s) {\n    os << \"{\";\n    std::set<Key, Compare, Allocator> tmp = s;\n\
      \    for (auto it = tmp.begin(); it != tmp.end(); ++it) {\n        output(os,\
      \ *it);\n        if (std::next(it) != tmp.end()) os << \", \";\n    }\n    os\
      \ << \"}\";\n}\ntemplate <OutputStream OStream, class Key, class Compare, class\
      \ Allocator>\nvoid output(OStream &os, const std::multiset<Key, Compare, Allocator>\
      \ &s) {\n    os << \"{\";\n    std::multiset<Key, Compare, Allocator> tmp =\
      \ s;\n    for (auto it = tmp.begin(); it != tmp.end(); ++it) {\n        output(os,\
      \ *it);\n        if (std::next(it) != tmp.end()) os << \", \";\n    }\n    os\
      \ << \"}\";\n}\ntemplate <OutputStream OStream, class Key, class Hash, class\
      \ KeyEqual, class Allocator>\nvoid output(OStream &os, const std::unordered_set<Key,\
      \ Hash, KeyEqual, Allocator> &s) {\n    os << \"{\";\n    std::unordered_set<Key,\
      \ Hash, KeyEqual, Allocator> tmp = s;\n    for (auto it = tmp.begin(); it !=\
      \ tmp.end(); ++it) {\n        output(os, *it);\n        if (std::next(it) !=\
      \ tmp.end()) os << \", \";\n    }\n    os << \"}\";\n}\ntemplate <OutputStream\
      \ OStream, class Key, class Hash, class KeyEqual, class Allocator>\nvoid output(OStream\
      \ &os, const std::unordered_multiset<Key, Hash, KeyEqual, Allocator> &s) {\n\
      \    os << \"{\";\n    std::unordered_multiset<Key, Hash, KeyEqual, Allocator>\
      \ tmp = s;\n    for (auto it = tmp.begin(); it != tmp.end(); ++it) {\n     \
      \   output(os, *it);\n        if (std::next(it) != tmp.end()) os << \", \";\n\
      \    }\n    os << \"}\";\n}\ntemplate <OutputStream OStream, class Key, class\
      \ T, class Compare, class Allocator>\nvoid output(OStream &os, const std::map<Key,\
      \ T, Compare, Allocator> &m) {\n    os << \"{\";\n    std::map<Key, T, Compare,\
      \ Allocator> tmp = m;\n    for (auto it = tmp.begin(); it != tmp.end(); ++it)\
      \ {\n        output(os, it->first);\n        os << \": \";\n        output(os,\
      \ it->second);\n        if (std::next(it) != tmp.end()) os << \", \";\n    }\n\
      \    os << \"}\";\n}\ntemplate <OutputStream OStream, class Key, class T, class\
      \ Hash, class KeyEqual, class Allocator>\nvoid output(OStream &os, const std::unordered_map<Key,\
      \ T, Hash, KeyEqual, Allocator> &m) {\n    os << \"{\";\n    std::unordered_map<Key,\
      \ T, Hash, KeyEqual, Allocator> tmp = m;\n    for (auto it = tmp.begin(); it\
      \ != tmp.end(); ++it) {\n        output(os, it->first);\n        os << \": \"\
      ;\n        output(os, it->second);\n        if (std::next(it) != tmp.end())\
      \ os << \", \";\n    }\n    os << \"}\";\n}\ntemplate <OutputStream OStream>\
      \ void outputln(OStream &os) {\n    os << '\\n';\n    os.flush();\n}\ntemplate\
      \ <OutputStream OStream, class T, class... Args>\nvoid outputln(OStream &os,\
      \ const T &t, const Args &...args) {\n    output(os, t, args...);\n    os <<\
      \ '\\n';\n    os.flush();\n}\nstd::vector<std::string> sep(const char *s) {\n\
      \    std::vector<std::string> res;\n    std::string now;\n    int dep = 0;\n\
      \    while (true) {\n        if (*s == '\\0') {\n            res.emplace_back(now);\n\
      \            break;\n        }\n        if (*s == '(' or *s == '[' or *s ==\
      \ '{') dep++;\n        if (*s == ')' or *s == ']' or *s == '}') dep--;\n   \
      \     if (dep == 0 and *s == ',') {\n            res.emplace_back(now);\n  \
      \          now.clear();\n        } else if (!isspace(*s)) {\n            now\
      \ += *s;\n        }\n        s++;\n    }\n    return res;\n}\nvoid show_vars(const\
      \ std::vector<std::string> &, int) {}\ntemplate <class T, class... Args>\nvoid\
      \ show_vars(const std::vector<std::string> &name, int pos, const T &t, const\
      \ Args &...args) {\n    output(std::cerr, name[pos++] + \":\");\n    output(std::cerr,\
      \ t);\n    if (sizeof...(args) > 0) output(std::cerr, \", \");\n    show_vars(name,\
      \ pos, args...);\n}\n\n#define kdebug(...)                                 \
      \                                               \\\n    {                  \
      \                                                                          \
      \  \\\n        std::cerr << \"line:\" << __LINE__ << ' ';                  \
      \                                 \\\n        kk2::debug::show_vars(kk2::debug::sep(#__VA_ARGS__),\
      \ 0, __VA_ARGS__);                      \\\n        std::cerr << std::endl;\
      \                                                                    \\\n  \
      \  }\n\n#define kput(s)                                                    \
      \                                \\\n    {                                 \
      \                                                             \\\n        std::cerr\
      \ << \"line:\" << __LINE__ << ' ';                                         \
      \          \\\n        kk2::debug::outputln(std::cerr, s);                 \
      \                                       \\\n    }\n\n#else\n\ntemplate <OutputStream\
      \ OStream, class... Args> void output(OStream &, const Args &...) {}\ntemplate\
      \ <OutputStream OStream, class... Args> void outputln(OStream &, const Args\
      \ &...) {}\ntemplate <class... Args> void fix_warn(const Args &...) {}\n#define\
      \ kdebug(...) kk2::debug::fix_warn(__VA_ARGS__);\n#define kput(s) kk2::debug::fix_warn(s)\n\
      \n#endif // KK2\n\n} // namespace debug\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: template/debug.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/debug.hpp
layout: document
---
