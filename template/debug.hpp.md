---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':warning:'
    path: type_traits/member.hpp
    title: type_traits/member.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/debug.hpp\"\n\n\n\n#include <array>\n#include <deque>\n\
    #include <map>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <tuple>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <utility>\n#include <vector>\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include\
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
    \ kk2\n\n\n#line 1 \"type_traits/member.hpp\"\n\n\n\n#line 5 \"type_traits/member.hpp\"\
    \n\nnamespace kk2 {\n// BEGIN_PRESERVE_NEWLINES\n\n#define HAS_MEMBER_FUNC(member)\
    \                                                                    \\\n    template\
    \ <typename T, typename... Ts> struct has_member_func_##member##_impl {      \
    \           \\\n        template <typename U>                                \
    \                                      \\\n        static std::true_type check(decltype(std::declval<U>().member(std::declval<Ts>()...))\
    \ *);  \\\n        template <typename U> static std::false_type check(...);  \
    \                                 \\\n        using type = decltype(check<T>(nullptr));\
    \                                                  \\\n    };                \
    \                                                                            \
    \ \\\n    template <typename T, typename... Ts> struct has_member_func_##member\
    \                          \\\n        : has_member_func_##member##_impl<T, Ts...>::type\
    \ {};                                      \\\n    template <typename T, typename...\
    \ Ts> using has_member_func_##member##_t =                     \\\n        std::enable_if_t<has_member_func_##member<T,\
    \ Ts...>::value>;                               \\\n    template <typename T,\
    \ typename... Ts> using not_has_member_func_##member##_t =                 \\\n\
    \        std::enable_if_t<!has_member_func_##member<T, Ts...>::value>;\n\n#define\
    \ HAS_MEMBER_VAR(member)                                                     \
    \                \\\n    template <typename T> struct has_member_var_##member##_impl\
    \ {                                  \\\n        template <typename U> static\
    \ std::true_type check(decltype(std::declval<U>().member) *);   \\\n        template\
    \ <typename U> static std::false_type check(...);                            \
    \       \\\n        using type = decltype(check<T>(nullptr));                \
    \                                  \\\n    };                                \
    \                                                             \\\n    template\
    \ <typename T> struct has_member_var_##member                                \
    \           \\\n        : has_member_var_##member##_impl<T>::type {};        \
    \                                      \\\n    template <typename T> using has_member_var_##member##_t\
    \ =                                      \\\n        std::enable_if_t<has_member_var_##member<T>::value>;\
    \                                       \\\n    template <typename T> using not_has_member_var_##member##_t\
    \ =                                  \\\n        std::enable_if_t<!has_member_var_##member<T>::value>;\n\
    \nHAS_MEMBER_FUNC(debug_output)\nHAS_MEMBER_FUNC(val)\n\n// END_PRESERVE_NEWLINES\n\
    \n#undef HAS_MEMBER_FUNC\n#undef HAS_MEMBER_VAR\n} // namespace kk2\n\n\n#line\
    \ 19 \"template/debug.hpp\"\n\nnamespace kk2 {\n\nnamespace debug {\n\n#ifdef\
    \ KK2\n\ntemplate <class OStream, is_ostream_t<OStream> *> void output(OStream\
    \ &os);\ntemplate <class OStream, class T, is_ostream_t<OStream> *> void output(OStream\
    \ &os, const T &t);\ntemplate <class OStream, class T, class... Args, is_ostream_t<OStream>\
    \ *> void output(OStream &os, const T &t, const Args &...args);\ntemplate <class\
    \ OStream, class T, is_ostream_t<OStream> *> void output(OStream &os, const std::vector<T>\
    \ &v);\ntemplate <class OStream, class T, is_ostream_t<OStream> *> void output(OStream\
    \ &os, const std::vector<std::vector<T>> &d);\ntemplate <class OStream, class\
    \ T, size_t F, is_ostream_t<OStream> *> void output(OStream &os, const std::array<T,\
    \ F> &a);\ntemplate <class OStream, class T, class U, is_ostream_t<OStream> *>\
    \ void output(OStream &os, const std::pair<T, U> &p);\ntemplate <class OStream,\
    \ class... Args, is_ostream_t<OStream> *> void output(OStream &os, const std::tuple<Args...>\
    \ &t);\ntemplate <class OStream, class T, is_ostream_t<OStream> *> void output(OStream\
    \ &os, const std::queue<T> &q);\ntemplate <class OStream, class T, class Container,\
    \ class Compare, is_ostream_t<OStream> *> void output(OStream &os, const std::priority_queue<T,\
    \ Container, Compare> &q);\ntemplate <class OStream, class T, is_ostream_t<OStream>\
    \ *> void output(OStream &os, const std::deque<T> &d);\ntemplate <class OStream,\
    \ class T, is_ostream_t<OStream> *> void output(OStream &os, const std::stack<T>\
    \ &s);\ntemplate <class OStream, class Key, class Compare, class Allocator, is_ostream_t<OStream>\
    \ *> void output(OStream &os, const std::set<Key, Compare, Allocator> &s);\ntemplate\
    \ <class OStream, class Key, class Compare, class Allocator, is_ostream_t<OStream>\
    \ *> void output(OStream &os, const std::multiset<Key, Compare, Allocator> &s);\n\
    template <class OStream, class Key, class Hash, class KeyEqual, class Allocator,\
    \ is_ostream_t<OStream> *> void output(OStream &os, const std::unordered_set<Key,\
    \ Hash, KeyEqual, Allocator> &s);\ntemplate <class OStream, class Key, class Hash,\
    \ class KeyEqual, class Allocator, is_ostream_t<OStream> *> void output(OStream\
    \ &os, const std::unordered_multiset<Key, Hash, KeyEqual, Allocator> &s);\ntemplate\
    \ <class OStream, class Key, class T, class Compare, class Allocator, is_ostream_t<OStream>\
    \ *> void output(OStream &os, const std::map<Key, T, Compare, Allocator> &m);\n\
    template <class OStream, class Key, class T, class Hash, class KeyEqual, class\
    \ Allocator, is_ostream_t<OStream> *> void output(OStream &os, const std::unordered_map<Key,\
    \ T, Hash, KeyEqual, Allocator> &m);\ntemplate <class OStream, is_ostream_t<OStream>\
    \ * = nullptr> void output(OStream &) {}\ntemplate <class OStream, class T, is_ostream_t<OStream>\
    \ * = nullptr> void output(OStream &os, const T &t) {\n    if constexpr (has_member_func_debug_output<T,\
    \ OStream &>::value) {\n        t.debug_output(os);\n    } else {\n        os\
    \ << t;\n    }\n}\ntemplate <class OStream, class T, class... Args, is_ostream_t<OStream>\
    \ * = nullptr> void output(OStream &os, const T &t, const Args &...args) {\n \
    \   output(os, t);\n    os << \", \";\n    output(os, args...);\n}\ntemplate <class\
    \ OStream, class T, is_ostream_t<OStream> * = nullptr> void output(OStream &os,\
    \ const std::vector<T> &v) {\n    os << \"[\";\n    for (int i = 0; i < (int)v.size();\
    \ i++) {\n        output(os, v[i]);\n        if (i + 1 != (int)v.size()) os <<\
    \ \", \";\n    }\n    os << \"]\";\n}\ntemplate <class OStream, class T, is_ostream_t<OStream>\
    \ * = nullptr> void output(OStream &os, const std::vector<std::vector<T>> &d)\
    \ {\n    os << \"[\\n\";\n    for (int i = 0; i < (int)d.size(); i++) {\n    \
    \    output(os, d[i]);\n        output(os, \"\\n\");\n    }\n    os << \"]\";\n\
    }\ntemplate <class OStream, class T, size_t F, is_ostream_t<OStream> * = nullptr>\
    \ void output(OStream &os, const std::array<T, F> &a) {\n    os << \"[\";\n  \
    \  for (int i = 0; i < (int)F; i++) {\n        output(os, a[i]);\n        if (i\
    \ + 1 != (int)F) os << \", \";\n    }\n    os << \"]\";\n}\ntemplate <class OStream,\
    \ class T, class U, is_ostream_t<OStream> * = nullptr> void output(OStream &os,\
    \ const std::pair<T, U> &p) {\n    os << \"(\";\n    output(os, p.first);\n  \
    \  os << \", \";\n    output(os, p.second);\n    os << \")\";\n}\ntemplate <class\
    \ OStream, class... Args, is_ostream_t<OStream> * = nullptr> void output(OStream\
    \ &os, const std::tuple<Args...> &t) {\n    os << \"(\";\n    std::apply([&](const\
    \ Args &...args) { output(os, args...); }, t);\n    os << \")\";\n}\ntemplate\
    \ <class OStream, class T, is_ostream_t<OStream> * = nullptr> void output(OStream\
    \ &os, const std::queue<T> &q) {\n    os << \"[\";\n    std::queue<T> tmp = q;\n\
    \    while (!tmp.empty()) {\n        output(os, tmp.front());\n        tmp.pop();\n\
    \        if (!tmp.empty()) os << \", \";\n    }\n    os << \"]\";\n}\ntemplate\
    \ <class OStream, class T, class Container, class Compare, is_ostream_t<OStream>\
    \ * = nullptr> void output(OStream &os, const std::priority_queue<T, Container,\
    \ Compare> &q) {\n    os << \"[\";\n    std::priority_queue<T, Container, Compare>\
    \ tmp = q;\n    while (!tmp.empty()) {\n        output(os, tmp.top());\n     \
    \   tmp.pop();\n        if (!tmp.empty()) os << \", \";\n    }\n    os << \"]\"\
    ;\n}\ntemplate <class OStream, class T, is_ostream_t<OStream> * = nullptr> void\
    \ output(OStream &os, const std::deque<T> &d) {\n    os << \"[\";\n    std::deque<T>\
    \ tmp = d;\n    while (!tmp.empty()) {\n        output(os, tmp.front());\n   \
    \     tmp.pop_front();\n        if (!tmp.empty()) os << \", \";\n    }\n    os\
    \ << \"]\";\n}\ntemplate <class OStream, class T, is_ostream_t<OStream> * = nullptr>\
    \ void output(OStream &os, const std::stack<T> &s) {\n    os << \"[\";\n    std::stack<T>\
    \ tmp = s;\n    std::vector<T> v;\n    while (!tmp.empty()) {\n        v.push_back(tmp.top());\n\
    \        tmp.pop();\n    }\n    for (int i = (int)v.size() - 1; i >= 0; i--) {\n\
    \        output(os, v[i]);\n        if (i != 0) os << \", \";\n    }\n    os <<\
    \ \"]\";\n}\ntemplate <class OStream, class Key, class Compare, class Allocator,\
    \ is_ostream_t<OStream> * = nullptr> void output(OStream &os, const std::set<Key,\
    \ Compare, Allocator> &s) {\n    os << \"{\";\n    std::set<Key, Compare, Allocator>\
    \ tmp = s;\n    for (auto it = tmp.begin(); it != tmp.end(); ++it) {\n       \
    \ output(os, *it);\n        if (std::next(it) != tmp.end()) os << \", \";\n  \
    \  }\n    os << \"}\";\n}\ntemplate <class OStream, class Key, class Compare,\
    \ class Allocator, is_ostream_t<OStream> * = nullptr> void output(OStream &os,\
    \ const std::multiset<Key, Compare, Allocator> &s) {\n    os << \"{\";\n    std::multiset<Key,\
    \ Compare, Allocator> tmp = s;\n    for (auto it = tmp.begin(); it != tmp.end();\
    \ ++it) {\n        output(os, *it);\n        if (std::next(it) != tmp.end()) os\
    \ << \", \";\n    }\n    os << \"}\";\n}\ntemplate <class OStream, class Key,\
    \ class Hash, class KeyEqual, class Allocator, is_ostream_t<OStream> * = nullptr>\
    \ void output(OStream &os, const std::unordered_set<Key, Hash, KeyEqual, Allocator>\
    \ &s) {\n    os << \"{\";\n    std::unordered_set<Key, Hash, KeyEqual, Allocator>\
    \ tmp = s;\n    for (auto it = tmp.begin(); it != tmp.end(); ++it) {\n       \
    \ output(os, *it);\n        if (std::next(it) != tmp.end()) os << \", \";\n  \
    \  }\n    os << \"}\";\n}\ntemplate <class OStream, class Key, class Hash, class\
    \ KeyEqual, class Allocator, is_ostream_t<OStream> * = nullptr> void output(OStream\
    \ &os, const std::unordered_multiset<Key, Hash, KeyEqual, Allocator> &s) {\n \
    \   os << \"{\";\n    std::unordered_multiset<Key, Hash, KeyEqual, Allocator>\
    \ tmp = s;\n    for (auto it = tmp.begin(); it != tmp.end(); ++it) {\n       \
    \ output(os, *it);\n        if (std::next(it) != tmp.end()) os << \", \";\n  \
    \  }\n    os << \"}\";\n}\ntemplate <class OStream, class Key, class T, class\
    \ Compare, class Allocator, is_ostream_t<OStream> * = nullptr> void output(OStream\
    \ &os, const std::map<Key, T, Compare, Allocator> &m) {\n    os << \"{\";\n  \
    \  std::map<Key, T, Compare, Allocator> tmp = m;\n    for (auto it = tmp.begin();\
    \ it != tmp.end(); ++it) {\n        output(os, it->first);\n        os << \":\
    \ \";\n        output(os, it->second);\n        if (std::next(it) != tmp.end())\
    \ os << \", \";\n    }\n    os << \"}\";\n}\ntemplate <class OStream, class Key,\
    \ class T, class Hash, class KeyEqual, class Allocator, is_ostream_t<OStream>\
    \ * = nullptr> void output(OStream &os, const std::unordered_map<Key, T, Hash,\
    \ KeyEqual, Allocator> &m) {\n    os << \"{\";\n    std::unordered_map<Key, T,\
    \ Hash, KeyEqual, Allocator> tmp = m;\n    for (auto it = tmp.begin(); it != tmp.end();\
    \ ++it) {\n        output(os, it->first);\n        os << \": \";\n        output(os,\
    \ it->second);\n        if (std::next(it) != tmp.end()) os << \", \";\n    }\n\
    \    os << \"}\";\n}\ntemplate <class OStream, is_ostream_t<OStream> * = nullptr>\
    \ void outputln(OStream &os) {\n    os << '\\n';\n    os.flush();\n}\ntemplate\
    \ <class OStream, class T, class... Args, is_ostream_t<OStream> * = nullptr> void\
    \ outputln(OStream &os, const T &t, const Args &...args) {\n    output(os, t,\
    \ args...);\n    os << '\\n';\n    os.flush();\n}\nstd::vector<std::string> sep(const\
    \ char *s) {\n    std::vector<std::string> res;\n    std::string now;\n    int\
    \ dep = 0;\n    while (true) {\n        if (*s == '\\0') {\n            res.emplace_back(now);\n\
    \            break;\n        }\n        if (*s == '(' or *s == '[' or *s == '{')\
    \ dep++;\n        if (*s == ')' or *s == ']' or *s == '}') dep--;\n        if\
    \ (dep == 0 and *s == ',') {\n            res.emplace_back(now);\n           \
    \ now.clear();\n        } else if (!isspace(*s)) {\n            now += *s;\n \
    \       }\n        s++;\n    }\n    return res;\n}\nvoid show_vars(const std::vector<std::string>\
    \ &, int) {}\ntemplate <class T, class... Args> void show_vars(const std::vector<std::string>\
    \ &name, int pos, const T &t, const Args &...args) {\n    output(std::cerr, name[pos++]\
    \ + \":\", t);\n    if (sizeof...(args) > 0) output(std::cerr, \", \");\n    show_vars(name,\
    \ pos, args...);\n}\n\n#define kdebug(...)                                   \
    \                          \\\n    {                                         \
    \                                  \\\n        \\ std::cerr << \"line:\" << __LINE__\
    \ << ' ';                              \\\n        \\ kk2::debug::show_vars(kk2::debug::sep(#__VA_ARGS__),\
    \ 0, __VA_ARGS__); \\\n        \\ std::cerr << std::endl;                    \
    \                           \\\n        \\                                   \
    \                                    \\\n    }\n\n#define kput(s)            \
    \                        \\\n    {                                           \
    \   \\\n        \\ std::cerr << \"line:\" << __LINE__ << ' '; \\\n        \\ kk2::debug::outputln(std::cerr,\
    \ s);      \\\n        \\                                          \\\n    }\n\
    \n#else\n\ntemplate <class OStream, class... Args, is_ostream_t<OStream> * = nullptr>\
    \ void output(OStream &, const Args &...) {}\ntemplate <class OStream, class...\
    \ Args, is_ostream_t<OStream> * = nullptr> void outputln(OStream &, const Args\
    \ &...) {}\ntemplate <class... Args> void fix_warn(const Args &...) {}\n#define\
    \ kdebug(...) kk2::debug::fix_warn(__VA_ARGS__);\n#define kput(s) kk2::debug::fix_warn(s)\n\
    \n#endif // KK2\n\n} // namespace debug\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_TEMPLATE_DEBUG_HPP\n#define KK2_TEMPLATE_DEBUG_HPP 1\n\n#include\
    \ <array>\n#include <deque>\n#include <map>\n#include <queue>\n#include <set>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n\n#include \"\
    ../type_traits/io.hpp\"\n#include \"../type_traits/member.hpp\"\n\nnamespace kk2\
    \ {\n\nnamespace debug {\n\n#ifdef KK2\n\ntemplate <class OStream, is_ostream_t<OStream>\
    \ *> void output(OStream &os);\ntemplate <class OStream, class T, is_ostream_t<OStream>\
    \ *> void output(OStream &os, const T &t);\ntemplate <class OStream, class T,\
    \ class... Args, is_ostream_t<OStream> *> void output(OStream &os, const T &t,\
    \ const Args &...args);\ntemplate <class OStream, class T, is_ostream_t<OStream>\
    \ *> void output(OStream &os, const std::vector<T> &v);\ntemplate <class OStream,\
    \ class T, is_ostream_t<OStream> *> void output(OStream &os, const std::vector<std::vector<T>>\
    \ &d);\ntemplate <class OStream, class T, size_t F, is_ostream_t<OStream> *> void\
    \ output(OStream &os, const std::array<T, F> &a);\ntemplate <class OStream, class\
    \ T, class U, is_ostream_t<OStream> *> void output(OStream &os, const std::pair<T,\
    \ U> &p);\ntemplate <class OStream, class... Args, is_ostream_t<OStream> *> void\
    \ output(OStream &os, const std::tuple<Args...> &t);\ntemplate <class OStream,\
    \ class T, is_ostream_t<OStream> *> void output(OStream &os, const std::queue<T>\
    \ &q);\ntemplate <class OStream, class T, class Container, class Compare, is_ostream_t<OStream>\
    \ *> void output(OStream &os, const std::priority_queue<T, Container, Compare>\
    \ &q);\ntemplate <class OStream, class T, is_ostream_t<OStream> *> void output(OStream\
    \ &os, const std::deque<T> &d);\ntemplate <class OStream, class T, is_ostream_t<OStream>\
    \ *> void output(OStream &os, const std::stack<T> &s);\ntemplate <class OStream,\
    \ class Key, class Compare, class Allocator, is_ostream_t<OStream> *> void output(OStream\
    \ &os, const std::set<Key, Compare, Allocator> &s);\ntemplate <class OStream,\
    \ class Key, class Compare, class Allocator, is_ostream_t<OStream> *> void output(OStream\
    \ &os, const std::multiset<Key, Compare, Allocator> &s);\ntemplate <class OStream,\
    \ class Key, class Hash, class KeyEqual, class Allocator, is_ostream_t<OStream>\
    \ *> void output(OStream &os, const std::unordered_set<Key, Hash, KeyEqual, Allocator>\
    \ &s);\ntemplate <class OStream, class Key, class Hash, class KeyEqual, class\
    \ Allocator, is_ostream_t<OStream> *> void output(OStream &os, const std::unordered_multiset<Key,\
    \ Hash, KeyEqual, Allocator> &s);\ntemplate <class OStream, class Key, class T,\
    \ class Compare, class Allocator, is_ostream_t<OStream> *> void output(OStream\
    \ &os, const std::map<Key, T, Compare, Allocator> &m);\ntemplate <class OStream,\
    \ class Key, class T, class Hash, class KeyEqual, class Allocator, is_ostream_t<OStream>\
    \ *> void output(OStream &os, const std::unordered_map<Key, T, Hash, KeyEqual,\
    \ Allocator> &m);\ntemplate <class OStream, is_ostream_t<OStream> * = nullptr>\
    \ void output(OStream &) {}\ntemplate <class OStream, class T, is_ostream_t<OStream>\
    \ * = nullptr> void output(OStream &os, const T &t) {\n    if constexpr (has_member_func_debug_output<T,\
    \ OStream &>::value) {\n        t.debug_output(os);\n    } else {\n        os\
    \ << t;\n    }\n}\ntemplate <class OStream, class T, class... Args, is_ostream_t<OStream>\
    \ * = nullptr> void output(OStream &os, const T &t, const Args &...args) {\n \
    \   output(os, t);\n    os << \", \";\n    output(os, args...);\n}\ntemplate <class\
    \ OStream, class T, is_ostream_t<OStream> * = nullptr> void output(OStream &os,\
    \ const std::vector<T> &v) {\n    os << \"[\";\n    for (int i = 0; i < (int)v.size();\
    \ i++) {\n        output(os, v[i]);\n        if (i + 1 != (int)v.size()) os <<\
    \ \", \";\n    }\n    os << \"]\";\n}\ntemplate <class OStream, class T, is_ostream_t<OStream>\
    \ * = nullptr> void output(OStream &os, const std::vector<std::vector<T>> &d)\
    \ {\n    os << \"[\\n\";\n    for (int i = 0; i < (int)d.size(); i++) {\n    \
    \    output(os, d[i]);\n        output(os, \"\\n\");\n    }\n    os << \"]\";\n\
    }\ntemplate <class OStream, class T, size_t F, is_ostream_t<OStream> * = nullptr>\
    \ void output(OStream &os, const std::array<T, F> &a) {\n    os << \"[\";\n  \
    \  for (int i = 0; i < (int)F; i++) {\n        output(os, a[i]);\n        if (i\
    \ + 1 != (int)F) os << \", \";\n    }\n    os << \"]\";\n}\ntemplate <class OStream,\
    \ class T, class U, is_ostream_t<OStream> * = nullptr> void output(OStream &os,\
    \ const std::pair<T, U> &p) {\n    os << \"(\";\n    output(os, p.first);\n  \
    \  os << \", \";\n    output(os, p.second);\n    os << \")\";\n}\ntemplate <class\
    \ OStream, class... Args, is_ostream_t<OStream> * = nullptr> void output(OStream\
    \ &os, const std::tuple<Args...> &t) {\n    os << \"(\";\n    std::apply([&](const\
    \ Args &...args) { output(os, args...); }, t);\n    os << \")\";\n}\ntemplate\
    \ <class OStream, class T, is_ostream_t<OStream> * = nullptr> void output(OStream\
    \ &os, const std::queue<T> &q) {\n    os << \"[\";\n    std::queue<T> tmp = q;\n\
    \    while (!tmp.empty()) {\n        output(os, tmp.front());\n        tmp.pop();\n\
    \        if (!tmp.empty()) os << \", \";\n    }\n    os << \"]\";\n}\ntemplate\
    \ <class OStream, class T, class Container, class Compare, is_ostream_t<OStream>\
    \ * = nullptr> void output(OStream &os, const std::priority_queue<T, Container,\
    \ Compare> &q) {\n    os << \"[\";\n    std::priority_queue<T, Container, Compare>\
    \ tmp = q;\n    while (!tmp.empty()) {\n        output(os, tmp.top());\n     \
    \   tmp.pop();\n        if (!tmp.empty()) os << \", \";\n    }\n    os << \"]\"\
    ;\n}\ntemplate <class OStream, class T, is_ostream_t<OStream> * = nullptr> void\
    \ output(OStream &os, const std::deque<T> &d) {\n    os << \"[\";\n    std::deque<T>\
    \ tmp = d;\n    while (!tmp.empty()) {\n        output(os, tmp.front());\n   \
    \     tmp.pop_front();\n        if (!tmp.empty()) os << \", \";\n    }\n    os\
    \ << \"]\";\n}\ntemplate <class OStream, class T, is_ostream_t<OStream> * = nullptr>\
    \ void output(OStream &os, const std::stack<T> &s) {\n    os << \"[\";\n    std::stack<T>\
    \ tmp = s;\n    std::vector<T> v;\n    while (!tmp.empty()) {\n        v.push_back(tmp.top());\n\
    \        tmp.pop();\n    }\n    for (int i = (int)v.size() - 1; i >= 0; i--) {\n\
    \        output(os, v[i]);\n        if (i != 0) os << \", \";\n    }\n    os <<\
    \ \"]\";\n}\ntemplate <class OStream, class Key, class Compare, class Allocator,\
    \ is_ostream_t<OStream> * = nullptr> void output(OStream &os, const std::set<Key,\
    \ Compare, Allocator> &s) {\n    os << \"{\";\n    std::set<Key, Compare, Allocator>\
    \ tmp = s;\n    for (auto it = tmp.begin(); it != tmp.end(); ++it) {\n       \
    \ output(os, *it);\n        if (std::next(it) != tmp.end()) os << \", \";\n  \
    \  }\n    os << \"}\";\n}\ntemplate <class OStream, class Key, class Compare,\
    \ class Allocator, is_ostream_t<OStream> * = nullptr> void output(OStream &os,\
    \ const std::multiset<Key, Compare, Allocator> &s) {\n    os << \"{\";\n    std::multiset<Key,\
    \ Compare, Allocator> tmp = s;\n    for (auto it = tmp.begin(); it != tmp.end();\
    \ ++it) {\n        output(os, *it);\n        if (std::next(it) != tmp.end()) os\
    \ << \", \";\n    }\n    os << \"}\";\n}\ntemplate <class OStream, class Key,\
    \ class Hash, class KeyEqual, class Allocator, is_ostream_t<OStream> * = nullptr>\
    \ void output(OStream &os, const std::unordered_set<Key, Hash, KeyEqual, Allocator>\
    \ &s) {\n    os << \"{\";\n    std::unordered_set<Key, Hash, KeyEqual, Allocator>\
    \ tmp = s;\n    for (auto it = tmp.begin(); it != tmp.end(); ++it) {\n       \
    \ output(os, *it);\n        if (std::next(it) != tmp.end()) os << \", \";\n  \
    \  }\n    os << \"}\";\n}\ntemplate <class OStream, class Key, class Hash, class\
    \ KeyEqual, class Allocator, is_ostream_t<OStream> * = nullptr> void output(OStream\
    \ &os, const std::unordered_multiset<Key, Hash, KeyEqual, Allocator> &s) {\n \
    \   os << \"{\";\n    std::unordered_multiset<Key, Hash, KeyEqual, Allocator>\
    \ tmp = s;\n    for (auto it = tmp.begin(); it != tmp.end(); ++it) {\n       \
    \ output(os, *it);\n        if (std::next(it) != tmp.end()) os << \", \";\n  \
    \  }\n    os << \"}\";\n}\ntemplate <class OStream, class Key, class T, class\
    \ Compare, class Allocator, is_ostream_t<OStream> * = nullptr> void output(OStream\
    \ &os, const std::map<Key, T, Compare, Allocator> &m) {\n    os << \"{\";\n  \
    \  std::map<Key, T, Compare, Allocator> tmp = m;\n    for (auto it = tmp.begin();\
    \ it != tmp.end(); ++it) {\n        output(os, it->first);\n        os << \":\
    \ \";\n        output(os, it->second);\n        if (std::next(it) != tmp.end())\
    \ os << \", \";\n    }\n    os << \"}\";\n}\ntemplate <class OStream, class Key,\
    \ class T, class Hash, class KeyEqual, class Allocator, is_ostream_t<OStream>\
    \ * = nullptr> void output(OStream &os, const std::unordered_map<Key, T, Hash,\
    \ KeyEqual, Allocator> &m) {\n    os << \"{\";\n    std::unordered_map<Key, T,\
    \ Hash, KeyEqual, Allocator> tmp = m;\n    for (auto it = tmp.begin(); it != tmp.end();\
    \ ++it) {\n        output(os, it->first);\n        os << \": \";\n        output(os,\
    \ it->second);\n        if (std::next(it) != tmp.end()) os << \", \";\n    }\n\
    \    os << \"}\";\n}\ntemplate <class OStream, is_ostream_t<OStream> * = nullptr>\
    \ void outputln(OStream &os) {\n    os << '\\n';\n    os.flush();\n}\ntemplate\
    \ <class OStream, class T, class... Args, is_ostream_t<OStream> * = nullptr> void\
    \ outputln(OStream &os, const T &t, const Args &...args) {\n    output(os, t,\
    \ args...);\n    os << '\\n';\n    os.flush();\n}\nstd::vector<std::string> sep(const\
    \ char *s) {\n    std::vector<std::string> res;\n    std::string now;\n    int\
    \ dep = 0;\n    while (true) {\n        if (*s == '\\0') {\n            res.emplace_back(now);\n\
    \            break;\n        }\n        if (*s == '(' or *s == '[' or *s == '{')\
    \ dep++;\n        if (*s == ')' or *s == ']' or *s == '}') dep--;\n        if\
    \ (dep == 0 and *s == ',') {\n            res.emplace_back(now);\n           \
    \ now.clear();\n        } else if (!isspace(*s)) {\n            now += *s;\n \
    \       }\n        s++;\n    }\n    return res;\n}\nvoid show_vars(const std::vector<std::string>\
    \ &, int) {}\ntemplate <class T, class... Args> void show_vars(const std::vector<std::string>\
    \ &name, int pos, const T &t, const Args &...args) {\n    output(std::cerr, name[pos++]\
    \ + \":\", t);\n    if (sizeof...(args) > 0) output(std::cerr, \", \");\n    show_vars(name,\
    \ pos, args...);\n}\n\n#define kdebug(...)                                   \
    \                          \\\n    {                                         \
    \                                  \\\n        \\ std::cerr << \"line:\" << __LINE__\
    \ << ' ';                              \\\n        \\ kk2::debug::show_vars(kk2::debug::sep(#__VA_ARGS__),\
    \ 0, __VA_ARGS__); \\\n        \\ std::cerr << std::endl;                    \
    \                           \\\n        \\                                   \
    \                                    \\\n    }\n\n#define kput(s)            \
    \                        \\\n    {                                           \
    \   \\\n        \\ std::cerr << \"line:\" << __LINE__ << ' '; \\\n        \\ kk2::debug::outputln(std::cerr,\
    \ s);      \\\n        \\                                          \\\n    }\n\
    \n#else\n\ntemplate <class OStream, class... Args, is_ostream_t<OStream> * = nullptr>\
    \ void output(OStream &, const Args &...) {}\ntemplate <class OStream, class...\
    \ Args, is_ostream_t<OStream> * = nullptr> void outputln(OStream &, const Args\
    \ &...) {}\ntemplate <class... Args> void fix_warn(const Args &...) {}\n#define\
    \ kdebug(...) kk2::debug::fix_warn(__VA_ARGS__);\n#define kput(s) kk2::debug::fix_warn(s)\n\
    \n#endif // KK2\n\n} // namespace debug\n\n} // namespace kk2\n\n#endif // KK2_TEMPLATE_DEBUG_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  - type_traits/member.hpp
  isVerificationFile: false
  path: template/debug.hpp
  requiredBy: []
  timestamp: '2025-10-08 12:41:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/debug.hpp
layout: document
redirect_from:
- /library/template/debug.hpp
- /library/template/debug.hpp.html
title: template/debug.hpp
---
