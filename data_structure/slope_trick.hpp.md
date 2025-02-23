---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/slope_trick.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <queue>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class T, class\
    \ U = T>\nstruct SlopeTrick {\n  private:\n    struct P {\n        T pos;\n  \
    \      U count;\n\n        P(T pos, U count) : pos(pos), count(count) {}\n\n \
    \       bool operator<(const P &p) const { return pos < p.pos; }\n\n        bool\
    \ operator>(const P &p) const { return pos > p.pos; }\n    };\n\n    std::priority_queue<P>\
    \ left;\n    std::priority_queue<P, std::vector<P>, std::greater<P>> right;\n\
    \    T _shift_left, _shift_right, min_y;\n\n    void push_left(T pos, U count)\
    \ { left.emplace(pos - _shift_left, count); }\n\n    void push_right(T pos, U\
    \ count) { right.emplace(pos - _shift_right, count); }\n\n    P get_left() { return\
    \ P(left.top().pos + _shift_left, left.top().count); }\n\n    P get_right() {\
    \ return P(right.top().pos + _shift_right, right.top().count); }\n\n    void pop_left()\
    \ { left.pop(); }\n\n    void pop_right() { right.pop(); }\n\n  public:\n    SlopeTrick()\
    \ : _shift_left(), _shift_right(), min_y() {}\n\n    // add: max(0, x - a) * c\n\
    \    void add_inc(T a, U c = 1) {\n        U used = 0;\n        while (used <\
    \ c and !left.empty()) {\n            auto [pos, count] = get_left();\n      \
    \      if (pos <= a) break;\n            pop_left();\n            U use = std::min(c\
    \ - used, count);\n            push_right(pos, use);\n            if (count >\
    \ use) push_left(pos, count - use);\n            min_y += (pos - a) * use;\n \
    \           used += use;\n        }\n        if (used) push_left(a, used);\n \
    \       if (c - used) push_right(a, c - used);\n    }\n\n    // add: max(0, a\
    \ - x) * c\n    void add_dec(T a, U c = 1) {\n        U used = 0;\n        while\
    \ (used < c and !right.empty()) {\n            auto [pos, count] = get_right();\n\
    \            if (pos >= a) break;\n            pop_right();\n            U use\
    \ = std::min(c - used, count);\n            push_left(pos, use);\n           \
    \ if (count > use) push_right(pos, count - use);\n            min_y += (a - pos)\
    \ * use;\n            used += use;\n        }\n        if (used) push_right(a,\
    \ used);\n        if (c - used) push_left(a, c - used);\n    }\n\n    // add:\
    \ abs(x - a) * c\n    void add_abs(T a, U c = 1) { add_inc(a, c), add_dec(a, c);\
    \ }\n\n    struct T_inf {\n        T a;\n        bool inf;\n    };\n\n    struct\
    \ T_minf {\n        T a;\n        bool minf;\n    };\n\n    struct get_min_result\
    \ {\n        T_inf a;\n        T_minf b;\n        T min_y;\n    };\n\n    /**\n\
    \     * f(x) = min_y + sum(max(0, x - a) * c) + sum(max(0, a - x) * c)\n     *\
    \ f^-1(min_y) = [a, b]\n     * return {a, b, min_y}\n     */\n    get_min_result\
    \ get_min() {\n        T_inf a{0, true};\n        T_minf b{0, true};\n       \
    \ if (!left.empty()) {\n            a.a = get_left().pos;\n            a.inf =\
    \ false;\n        }\n        if (!right.empty()) {\n            b.a = get_right().pos;\n\
    \            b.minf = false;\n        }\n        return {a, b, min_y};\n    }\n\
    \n    // f \\mapsto (x \\mapsto min_(y <= x) f(y))\n    void chmin_left() { decltype(left)().swap(left);\
    \ }\n\n    // f \\mapsto (x \\mapsto min_(y >= x) f(y))\n    void chmin_right()\
    \ { decltype(right)().swap(right); }\n\n    void shift_left(T x) { _shift_left\
    \ += x; }\n\n    void shift_right(T x) { _shift_right += x; }\n\n    // f \\mapsto\
    \ (t \\mapsto f(t - x))\n    void shift_x(T x) { _shift_left += x, _shift_right\
    \ += x; }\n\n    // f \\mapsto f + x\n    void shift_y(T x) { min_y += x; }\n\
    };\n\n} // namespace kk2\n\n\n\n"
  code: "#ifndef KK2_DATA_STRUCTURE_SLOPE_TRICK_HPP\n#define KK2_DATA_STRUCTURE_SLOPE_TRICK_HPP\
    \ 1\n\n#include <algorithm>\n#include <queue>\n#include <vector>\n\nnamespace\
    \ kk2 {\n\ntemplate <class T, class U = T>\nstruct SlopeTrick {\n  private:\n\
    \    struct P {\n        T pos;\n        U count;\n\n        P(T pos, U count)\
    \ : pos(pos), count(count) {}\n\n        bool operator<(const P &p) const { return\
    \ pos < p.pos; }\n\n        bool operator>(const P &p) const { return pos > p.pos;\
    \ }\n    };\n\n    std::priority_queue<P> left;\n    std::priority_queue<P, std::vector<P>,\
    \ std::greater<P>> right;\n    T _shift_left, _shift_right, min_y;\n\n    void\
    \ push_left(T pos, U count) { left.emplace(pos - _shift_left, count); }\n\n  \
    \  void push_right(T pos, U count) { right.emplace(pos - _shift_right, count);\
    \ }\n\n    P get_left() { return P(left.top().pos + _shift_left, left.top().count);\
    \ }\n\n    P get_right() { return P(right.top().pos + _shift_right, right.top().count);\
    \ }\n\n    void pop_left() { left.pop(); }\n\n    void pop_right() { right.pop();\
    \ }\n\n  public:\n    SlopeTrick() : _shift_left(), _shift_right(), min_y() {}\n\
    \n    // add: max(0, x - a) * c\n    void add_inc(T a, U c = 1) {\n        U used\
    \ = 0;\n        while (used < c and !left.empty()) {\n            auto [pos, count]\
    \ = get_left();\n            if (pos <= a) break;\n            pop_left();\n \
    \           U use = std::min(c - used, count);\n            push_right(pos, use);\n\
    \            if (count > use) push_left(pos, count - use);\n            min_y\
    \ += (pos - a) * use;\n            used += use;\n        }\n        if (used)\
    \ push_left(a, used);\n        if (c - used) push_right(a, c - used);\n    }\n\
    \n    // add: max(0, a - x) * c\n    void add_dec(T a, U c = 1) {\n        U used\
    \ = 0;\n        while (used < c and !right.empty()) {\n            auto [pos,\
    \ count] = get_right();\n            if (pos >= a) break;\n            pop_right();\n\
    \            U use = std::min(c - used, count);\n            push_left(pos, use);\n\
    \            if (count > use) push_right(pos, count - use);\n            min_y\
    \ += (a - pos) * use;\n            used += use;\n        }\n        if (used)\
    \ push_right(a, used);\n        if (c - used) push_left(a, c - used);\n    }\n\
    \n    // add: abs(x - a) * c\n    void add_abs(T a, U c = 1) { add_inc(a, c),\
    \ add_dec(a, c); }\n\n    struct T_inf {\n        T a;\n        bool inf;\n  \
    \  };\n\n    struct T_minf {\n        T a;\n        bool minf;\n    };\n\n   \
    \ struct get_min_result {\n        T_inf a;\n        T_minf b;\n        T min_y;\n\
    \    };\n\n    /**\n     * f(x) = min_y + sum(max(0, x - a) * c) + sum(max(0,\
    \ a - x) * c)\n     * f^-1(min_y) = [a, b]\n     * return {a, b, min_y}\n    \
    \ */\n    get_min_result get_min() {\n        T_inf a{0, true};\n        T_minf\
    \ b{0, true};\n        if (!left.empty()) {\n            a.a = get_left().pos;\n\
    \            a.inf = false;\n        }\n        if (!right.empty()) {\n      \
    \      b.a = get_right().pos;\n            b.minf = false;\n        }\n      \
    \  return {a, b, min_y};\n    }\n\n    // f \\mapsto (x \\mapsto min_(y <= x)\
    \ f(y))\n    void chmin_left() { decltype(left)().swap(left); }\n\n    // f \\\
    mapsto (x \\mapsto min_(y >= x) f(y))\n    void chmin_right() { decltype(right)().swap(right);\
    \ }\n\n    void shift_left(T x) { _shift_left += x; }\n\n    void shift_right(T\
    \ x) { _shift_right += x; }\n\n    // f \\mapsto (t \\mapsto f(t - x))\n    void\
    \ shift_x(T x) { _shift_left += x, _shift_right += x; }\n\n    // f \\mapsto f\
    \ + x\n    void shift_y(T x) { min_y += x; }\n};\n\n} // namespace kk2\n\n\n#endif\
    \ // KK2_DATA_STRUCTURE_SLOPE_TRICK_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/slope_trick.hpp
  requiredBy: []
  timestamp: '2025-02-23 19:24:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/slope_trick.hpp
layout: document
redirect_from:
- /library/data_structure/slope_trick.hpp
- /library/data_structure/slope_trick.hpp.html
title: data_structure/slope_trick.hpp
---
