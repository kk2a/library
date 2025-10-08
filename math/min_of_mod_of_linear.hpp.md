---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/frac_floor.hpp
    title: math/frac_floor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: '`min_{l <= x < r} (a * x + b) mod m`'
    links: []
  bundledCode: "#line 1 \"math/min_of_mod_of_linear.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <tuple>\n#include <vector>\n\n#line 1 \"math/frac_floor.hpp\"\
    \n\n\n\n#line 5 \"math/frac_floor.hpp\"\n\nnamespace kk2 {\n\n// floor(x) = ceil(x)\
    \ - 1 (for all x not in Z) ...(1)\n// floor(x) = -ceil(-x)   (for all x)     \
    \     ...(2)\n\n// return floor(a / b)\ntemplate <typename T, typename U> constexpr\
    \ T fracfloor(T a, U b) {\n    assert(b != 0);\n    if (a % b == 0) return a /\
    \ b;\n    if (a >= 0) return a / b;\n\n    // floor(x) = -ceil(-x)      by (2)\n\
    \    //          = -floor(-x) - 1 by (1)\n    return -((-a) / b) - 1;\n}\n\n//\
    \ return ceil(a / b)\ntemplate <typename T, typename U> constexpr T fracceil(T\
    \ a, U b) {\n    assert(b != 0);\n    if (a % b == 0) return a / b;\n    if (a\
    \ >= 0) return a / b + 1;\n\n    // ceil(x) = -floor(-x)      by (2)\n    return\
    \ -((-a) / b);\n}\n\n} // namespace kk2\n\n\n#line 10 \"math/min_of_mod_of_linear.hpp\"\
    \n\nnamespace kk2 {\n\n/**\n * @brief\n * - `f(x) = min_{y in [0, x]} (a * y +\
    \ b) mod m (x in [0, m))`\n *\n * - `f`\u306F`O(log b)`\u500B\u306E\u7B49\u5DEE\
    \u6570\u5217\u3067\u8868\u73FE\u3067\u304D\u308B\n *\n * @param m `0 < m`\n *\
    \ @param a `0 <= a < m`\n * @param b `0 <= b < m`\n * @return\n * - `std::vector<std::tuple<T,\
    \ T, T>> `\n *\n * - `(x\u306E\u516C\u5DEE, y\u306E\u516C\u5DEE(\u7B26\u53F7\u53CD\
    \u8EE2), \u9577\u3055-1)`\u306E\u914D\u5217\n */\ntemplate <class T> std::vector<std::tuple<T,\
    \ T, T>> min_of_mod_of_linear_segment(T m, T a, T b) {\n    T lnum = 0, lden =\
    \ 1, rnum = 1, rden = 0;\n    T x = 0, y = b;\n    T nnum = m - a, nden = m;\n\
    \n    std::vector<std::tuple<T, T, T>> res;\n\n    auto go_down = [&](bool left)\
    \ {\n        T q = nnum / nden, r = nnum - nden * q;\n        (left ? rnum : lnum)\
    \ += (left ? lnum : rnum) * (q - (r == 0));\n        (left ? rden : lden) += (left\
    \ ? lden : rden) * (q - (r == 0));\n        nnum = nden, nden = r;\n        return\
    \ r;\n    };\n\n    do {\n        for (T c{}; nnum - (c = std::max<T>(0, kk2::fracceil(nnum\
    \ - y, nden))) * nden > 0;) {\n            nnum -= c * nden, lnum += c * rnum,\
    \ lden += c * rden;\n            c = y / nnum;\n            res.emplace_back(lden,\
    \ nnum, c);\n            x += lden * c, y -= nnum * c;\n        }\n    } while\
    \ (go_down(0) and go_down(1) and y);\n    return res;\n}\n\n\n/**\n * @brief `min_{l\
    \ <= x < r} (a * x + b) mod m`\n *\n * @param l,r `0 <= l < r`\n * @param m `0\
    \ < m`\n * @param a `0 <= a < m`\n * @param b `0 <= b < m`\n * @return `arg, min`\n\
    \ */\ntemplate <class T> std::pair<T, T> min_of_mod_of_linear(T l, T r, T m, T\
    \ a, T b) {\n    assert(0 <= a and a < m);\n    assert(0 <= b and b < m);\n  \
    \  assert(0 < m);\n    assert(l < r);\n    b = (a * l + b) % m;\n    r -= l, l\
    \ = 0;\n    T lnum = 0, lden = 1, rnum = 1, rden = 0;\n    T x = 0, y = b;\n \
    \   T nnum = m - a, nden = m;\n\n    auto go_down = [&](bool left) {\n       \
    \ T q = nnum / nden, r = nnum - nden * q;\n        (left ? rnum : lnum) += (left\
    \ ? lnum : rnum) * (q - (r == 0));\n        (left ? rden : lden) += (left ? lden\
    \ : rden) * (q - (r == 0));\n        nnum = nden, nden = r;\n        return r;\n\
    \    };\n\n    do {\n        for (T c{}; nnum - (c = std::max<T>(0, kk2::fracceil(nnum\
    \ - y, nden))) * nden > 0;) {\n            nnum -= c * nden, lnum += c * rnum,\
    \ lden += c * rden;\n            c = y / nnum;\n            if (x + lden * c >=\
    \ r) {\n                c = kk2::fracceil(r - x, lden) - 1;\n                return\
    \ {l + x + lden * c, y - nnum * c};\n            }\n            x += lden * c,\
    \ y -= nnum * c;\n        }\n    } while (go_down(0) and go_down(1) and y);\n\
    \    return {l + x, y};\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_MIN_OF_MOD_OF_LINEAR_HPP\n#define KK2_MATH_MIN_OF_MOD_OF_LINEAR_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <tuple>\n#include <vector>\n\
    \n#include \"frac_floor.hpp\"\n\nnamespace kk2 {\n\n/**\n * @brief\n * - `f(x)\
    \ = min_{y in [0, x]} (a * y + b) mod m (x in [0, m))`\n *\n * - `f`\u306F`O(log\
    \ b)`\u500B\u306E\u7B49\u5DEE\u6570\u5217\u3067\u8868\u73FE\u3067\u304D\u308B\n\
    \ *\n * @param m `0 < m`\n * @param a `0 <= a < m`\n * @param b `0 <= b < m`\n\
    \ * @return\n * - `std::vector<std::tuple<T, T, T>> `\n *\n * - `(x\u306E\u516C\
    \u5DEE, y\u306E\u516C\u5DEE(\u7B26\u53F7\u53CD\u8EE2), \u9577\u3055-1)`\u306E\u914D\
    \u5217\n */\ntemplate <class T> std::vector<std::tuple<T, T, T>> min_of_mod_of_linear_segment(T\
    \ m, T a, T b) {\n    T lnum = 0, lden = 1, rnum = 1, rden = 0;\n    T x = 0,\
    \ y = b;\n    T nnum = m - a, nden = m;\n\n    std::vector<std::tuple<T, T, T>>\
    \ res;\n\n    auto go_down = [&](bool left) {\n        T q = nnum / nden, r =\
    \ nnum - nden * q;\n        (left ? rnum : lnum) += (left ? lnum : rnum) * (q\
    \ - (r == 0));\n        (left ? rden : lden) += (left ? lden : rden) * (q - (r\
    \ == 0));\n        nnum = nden, nden = r;\n        return r;\n    };\n\n    do\
    \ {\n        for (T c{}; nnum - (c = std::max<T>(0, kk2::fracceil(nnum - y, nden)))\
    \ * nden > 0;) {\n            nnum -= c * nden, lnum += c * rnum, lden += c *\
    \ rden;\n            c = y / nnum;\n            res.emplace_back(lden, nnum, c);\n\
    \            x += lden * c, y -= nnum * c;\n        }\n    } while (go_down(0)\
    \ and go_down(1) and y);\n    return res;\n}\n\n\n/**\n * @brief `min_{l <= x\
    \ < r} (a * x + b) mod m`\n *\n * @param l,r `0 <= l < r`\n * @param m `0 < m`\n\
    \ * @param a `0 <= a < m`\n * @param b `0 <= b < m`\n * @return `arg, min`\n */\n\
    template <class T> std::pair<T, T> min_of_mod_of_linear(T l, T r, T m, T a, T\
    \ b) {\n    assert(0 <= a and a < m);\n    assert(0 <= b and b < m);\n    assert(0\
    \ < m);\n    assert(l < r);\n    b = (a * l + b) % m;\n    r -= l, l = 0;\n  \
    \  T lnum = 0, lden = 1, rnum = 1, rden = 0;\n    T x = 0, y = b;\n    T nnum\
    \ = m - a, nden = m;\n\n    auto go_down = [&](bool left) {\n        T q = nnum\
    \ / nden, r = nnum - nden * q;\n        (left ? rnum : lnum) += (left ? lnum :\
    \ rnum) * (q - (r == 0));\n        (left ? rden : lden) += (left ? lden : rden)\
    \ * (q - (r == 0));\n        nnum = nden, nden = r;\n        return r;\n    };\n\
    \n    do {\n        for (T c{}; nnum - (c = std::max<T>(0, kk2::fracceil(nnum\
    \ - y, nden))) * nden > 0;) {\n            nnum -= c * nden, lnum += c * rnum,\
    \ lden += c * rden;\n            c = y / nnum;\n            if (x + lden * c >=\
    \ r) {\n                c = kk2::fracceil(r - x, lden) - 1;\n                return\
    \ {l + x + lden * c, y - nnum * c};\n            }\n            x += lden * c,\
    \ y -= nnum * c;\n        }\n    } while (go_down(0) and go_down(1) and y);\n\
    \    return {l + x, y};\n}\n\n} // namespace kk2\n\n#endif // KK2_MATH_MIN_OF_MOD_OF_LINEAR_HPP\n"
  dependsOn:
  - math/frac_floor.hpp
  isVerificationFile: false
  path: math/min_of_mod_of_linear.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:19:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/min_of_mod_of_linear.hpp
layout: document
redirect_from:
- /library/math/min_of_mod_of_linear.hpp
- /library/math/min_of_mod_of_linear.hpp.html
title: '`min_{l <= x < r} (a * x + b) mod m`'
---
