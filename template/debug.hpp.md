---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef TEMPLATE_DEBUG_HPP\n#define TEMPLATE_DEBUG_HPP 1\n\n#include <array>\n\
    #include <deque>\n#include <map>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <utility>\n#include <vector>\n\n#include \"../type_traits/type_traits.hpp\"\n\
    \nnamespace kk2 {\n\nnamespace debug {\n\n#ifdef KK2\n\ntemplate <class OStream,\
    \ is_ostream_t<OStream> * = nullptr> void output(OStream &os) {\n}\n\ntemplate\
    \ <class OStream, class T, is_ostream_t<OStream> * = nullptr>\nvoid output(OStream\
    \ &os, const T &t) {\n    os << t;\n}\n\ntemplate <class OStream, class T, is_ostream_t<OStream>\
    \ * = nullptr>\nvoid output(OStream &os, const std::vector<T> &v) {\n    os <<\
    \ \"[\";\n    for (int i = 0; i < (int)v.size(); i++) {\n        os << v[i];\n\
    \        if (i + 1 != (int)v.size()) os << \", \";\n    }\n    os << \"]\";\n\
    }\n\ntemplate <class OStream, class T, size_t F, is_ostream_t<OStream> * = nullptr>\n\
    void output(OStream &os, const std::array<T, F> &a) {\n    os << \"[\";\n    for\
    \ (int i = 0; i < (int)F; i++) {\n        os << a[i];\n        if (i + 1 != (int)F)\
    \ os << \", \";\n    }\n    os << \"]\";\n}\n    \ntemplate <class OStream, class\
    \ T, class U, is_ostream_t<OStream> * = nullptr>\nvoid output(OStream &os, const\
    \ std::pair<T, U> &p) {\n    os << \"(\";\n    os << p.first << \", \" << p.second;\n\
    \    os << \")\";\n}\n\ntemplate <class OStream, class T, is_ostream_t<OStream>\
    \ * = nullptr>\nvoid output(OStream &os, const std::queue<T> &q) {\n    os <<\
    \ \"[\";\n    std::queue<T> tmp = q;\n    while (!tmp.empty()) {\n        os <<\
    \ tmp.front();\n        tmp.pop();\n        if (!tmp.empty()) os << \", \";\n\
    \    }\n    os << \"]\";\n}\n\ntemplate <class OStream, class T, class Container,\
    \ class Compare, is_ostream_t<OStream> * = nullptr>\nvoid output(OStream &os,\
    \ const std::priority_queue<T, Container, Compare> &q) {\n    os << \"[\";\n \
    \   std::priority_queue<T, Container, Compare> tmp = q;\n    while (!tmp.empty())\
    \ {\n        os << tmp.top();\n        tmp.pop();\n        if (!tmp.empty()) os\
    \ << \", \";\n    }\n    os << \"]\";\n}\n\ntemplate <class OStream, class T,\
    \ is_ostream_t<OStream> * = nullptr>\nvoid output(OStream &os, const std::deque<T>\
    \ &d) {\n    os << \"[\";\n    std::deque<T> tmp = d;\n    while (!tmp.empty())\
    \ {\n        os << tmp.front();\n        tmp.pop_front();\n        if (!tmp.empty())\
    \ os << \", \";\n    }\n    os << \"]\";\n}\n\ntemplate <class OStream, class\
    \ T, is_ostream_t<OStream> * = nullptr>\nvoid output(OStream &os, const std::stack<T>\
    \ &s) {\n    os << \"[\";\n    std::stack<T> tmp = s;\n    std::vector<T> v;\n\
    \    while (!tmp.empty()) {\n        v.push_back(tmp.top());\n        tmp.pop();\n\
    \    }\n    for (int i = (int)v.size() - 1; i >= 0; i--) {\n        os << v[i];\n\
    \        if (i != 0) os << \", \";\n    }\n    os << \"]\";\n}\n\ntemplate <class\
    \ OStream,\n          class Key,\n          class Compare,\n          class Allocator,\n\
    \          is_ostream_t<OStream> * = nullptr>\nvoid output(OStream &os, const\
    \ std::set<Key, Compare, Allocator> &s) {\n    os << \"{\";\n    std::set<Key,\
    \ Compare, Allocator> tmp = s;\n    for (auto it = tmp.begin(); it != tmp.end();\
    \ ++it) {\n        os << *it;\n        if (std::next(it) != tmp.end()) os << \"\
    , \";\n    }\n    os << \"}\";\n}\n\ntemplate <class OStream,\n          class\
    \ Key,\n          class Compare,\n          class Allocator,\n          is_ostream_t<OStream>\
    \ * = nullptr>\nvoid output(OStream &os, const std::multiset<Key, Compare, Allocator>\
    \ &s) {\n    os << \"{\";\n    std::multiset<Key, Compare, Allocator> tmp = s;\n\
    \    for (auto it = tmp.begin(); it != tmp.end(); ++it) {\n        os << *it;\n\
    \        if (std::next(it) != tmp.end()) os << \", \";\n    }\n    os << \"}\"\
    ;\n}\n\ntemplate <class OStream,\n          class Key,\n          class Hash,\n\
    \          class KeyEqual,\n          class Allocator,\n          is_ostream_t<OStream>\
    \ * = nullptr>\nvoid output(OStream &os, const std::unordered_set<Key, Hash, KeyEqual,\
    \ Allocator> &s) {\n    os << \"{\";\n    std::unordered_set<Key, Hash, KeyEqual,\
    \ Allocator> tmp = s;\n    for (auto it = tmp.begin(); it != tmp.end(); ++it)\
    \ {\n        os << *it;\n        if (std::next(it) != tmp.end()) os << \", \"\
    ;\n    }\n    os << \"}\";\n}\n\ntemplate <class OStream,\n          class Key,\n\
    \          class Hash,\n          class KeyEqual,\n          class Allocator,\n\
    \          is_ostream_t<OStream> * = nullptr>\nvoid output(OStream &os, const\
    \ std::unordered_multiset<Key, Hash, KeyEqual, Allocator> &s) {\n    os << \"\
    {\";\n    std::unordered_multiset<Key, Hash, KeyEqual, Allocator> tmp = s;\n \
    \   for (auto it = tmp.begin(); it != tmp.end(); ++it) {\n        os << *it;\n\
    \        if (std::next(it) != tmp.end()) os << \", \";\n    }\n    os << \"}\"\
    ;\n}\n\ntemplate <class OStream,\n          class Key,\n          class T,\n \
    \         class Compare,\n          class Allocator,\n          is_ostream_t<OStream>\
    \ * = nullptr>\nvoid output(OStream &os, const std::map<Key, T, Compare, Allocator>\
    \ &m) {\n    os << \"{\";\n    std::map<Key, T, Compare, Allocator> tmp = m;\n\
    \    for (auto it = tmp.begin(); it != tmp.end(); ++it) {\n        os << it->first\
    \ << \": \" << it->second;\n        if (std::next(it) != tmp.end()) os << \",\
    \ \";\n    }\n    os << \"}\";\n}\n\ntemplate <class OStream,\n          class\
    \ Key,\n          class T,\n          class Hash,\n          class KeyEqual,\n\
    \          class Allocator,\n          is_ostream_t<OStream> * = nullptr>\nvoid\
    \ output(OStream &os, const std::unordered_map<Key, T, Hash, KeyEqual, Allocator>\
    \ &m) {\n    os << \"{\";\n    std::unordered_map<Key, T, Hash, KeyEqual, Allocator>\
    \ tmp = m;\n    for (auto it = tmp.begin(); it != tmp.end(); ++it) {\n       \
    \ os << it->first << \": \" << it->second;\n        if (std::next(it) != tmp.end())\
    \ os << \", \";\n    }\n    os << \"}\";\n}\n\ntemplate <class OStream, class\
    \ T, class... Args, is_ostream_t<OStream> * = nullptr>\nvoid output(OStream &os,\
    \ const T &t, const Args &...args) {\n    output(os, t);\n    os << ' ';\n   \
    \ output(os, args...);\n}\n\ntemplate <class OStream, class... Args, is_ostream_t<OStream>\
    \ * = nullptr>\nvoid outputln(OStream &os, const Args &...args) {\n    output(os,\
    \ args...);\n    os << '\\n';\n}\n\n#else\ntemplate <class OStream, class... Args,\
    \ is_ostream_t<OStream> * = nullptr>\nvoid output(OStream &os, const Args &...args)\
    \ {\n}\n\ntemplate <class OStream, class... Args, is_ostream_t<OStream> * = nullptr>\n\
    void outputln(OStream &os, const Args &...args) {\n}\n\n#endif // KK2\n\n} //\
    \ namespace debug\n\n} // namespace kk2\n\n#endif // TEMPLATE_DEBUG_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: template/debug.hpp
  requiredBy: []
  timestamp: '2024-12-11 14:40:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/debug.hpp
layout: document
redirect_from:
- /library/template/debug.hpp
- /library/template/debug.hpp.html
title: template/debug.hpp
---
