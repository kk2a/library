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
  bundledCode: "#line 1 \"template/fastio.hpp\"\n\n\n\n#include <cctype>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <fstream>\n#include <string>\n\nnamespace\
    \ kk2 {\n\nnamespace fastio {\n\n#define INPUT_FILE \"in.txt\"\n#define OUTPUT_FILE\
    \ \"out.txt\"\n\nstruct Scanner {\n  private:\n    static constexpr size_t INPUT_BUF\
    \ = 1 << 17;\n    size_t pos = INPUT_BUF;\n    static char buf[INPUT_BUF];\n \
    \   FILE *fp;\n\n  public:\n    Scanner() { fp = stdin; }\n\n    Scanner(const\
    \ char *file) { fp = fopen(file, \"r\"); }\n\n    ~Scanner() {\n        if (fp\
    \ != stdin) fclose(fp);\n    }\n\n    char now() {\n        if (pos == INPUT_BUF)\
    \ {\n            size_t len = fread(buf, 1, INPUT_BUF, fp);\n            if (len\
    \ != INPUT_BUF) buf[len] = '\\n';\n            pos = 0;\n        }\n        return\
    \ buf[pos];\n    }\n\n    void skip_space() {\n        while (isspace(now()))\
    \ ++pos;\n    }\n\n    uint32_t next_u32() {\n        skip_space();\n        uint32_t\
    \ res = 0;\n        while (isdigit(now())) {\n            res = res * 10 + (now()\
    \ - '0');\n            ++pos;\n        }\n        return res;\n    }\n\n    int32_t\
    \ next_i32() {\n        skip_space();\n        if (now() == '-') {\n         \
    \   ++pos;\n            return (int32_t)(-next_u32());\n        }\n        else\
    \ return (int32_t)next_uint();\n    }\n\n    uint64_t next_u64() {\n        skip_space();\n\
    \        uint64_t res = 0;\n        while (isdigit(now())) {\n            res\
    \ = res * 10 + (now() - '0');\n            ++pos;\n        }\n        return res;\n\
    \    }\n\n    int64_t next_i64() {\n        skip_space();\n        if (now() ==\
    \ '-') {\n            ++pos;\n            return (int64_t)(-next_u64());\n   \
    \     }\n        else return (int64_t)next_u64();\n    }\n\n    __uint128_t next_u128()\
    \ {\n        skip_space();\n        __uint128_t res = 0;\n        while (isdigit(now()))\
    \ {\n            res = res * 10 + (now() - '0');\n            ++pos;\n       \
    \ }\n        return res;\n    }\n\n    __int128_t next_i128() {\n        skip_space();\n\
    \        if (now() == '-') {\n            ++pos;\n            return (__int128_t)(-next_u128());\n\
    \        }\n        else return (__int128_t)next_u128();\n    }\n\n    char next_char()\
    \ {\n        skip_space();\n        auto res = now();\n        ++pos;\n      \
    \  return res;\n    }\n\n    std::string next_string() {\n        skip_space();\n\
    \        std::string res;\n        while (!isspace(now())) {\n            res.push_back(now());\n\
    \            ++pos;\n        }\n        return res;\n    }\n\n    Scanner &operator>>(int\
    \ &x) {\n        x = next_i32();\n        return *this;\n    }\n\n    Scanner\
    \ &operator>>(unsigned int &x) {\n        x = next_u32();\n        return *this;\n\
    \    }\n\n    Scanner &operator>>(long long &x) {\n        x = next_i64();\n \
    \       return *this;\n    }\n\n    Scanner &operator>>(unsigned long long &x)\
    \ {\n        x = next_u64();\n        return *this;\n    }\n\n    Scanner &operator>>(__int128_t\
    \ &x) {\n        x = next_i128();\n        return *this;\n    }\n\n    Scanner\
    \ &operator>>(__uint128_t &x) {\n        x = next_u128();\n        return *this;\n\
    \    }\n};\n\n#ifdef KK2\nScanner kin(INPUT_FILE);\n#elif defined(INTERACTIVE)\n\
    #define kin std::cin\n#else\nScanner kin;\n#endif\n\n} // namespace fastio\n\n\
    } // namespace kk2\n\n\n"
  code: "#ifndef TEMPLATE_FASTIO_HPP\n#define TEMPLATE_FASTIO_HPP 1\n\n#include <cctype>\n\
    #include <cstdint>\n#include <cstdio>\n#include <fstream>\n#include <string>\n\
    \nnamespace kk2 {\n\nnamespace fastio {\n\n#define INPUT_FILE \"in.txt\"\n#define\
    \ OUTPUT_FILE \"out.txt\"\n\nstruct Scanner {\n  private:\n    static constexpr\
    \ size_t INPUT_BUF = 1 << 17;\n    size_t pos = INPUT_BUF;\n    static char buf[INPUT_BUF];\n\
    \    FILE *fp;\n\n  public:\n    Scanner() { fp = stdin; }\n\n    Scanner(const\
    \ char *file) { fp = fopen(file, \"r\"); }\n\n    ~Scanner() {\n        if (fp\
    \ != stdin) fclose(fp);\n    }\n\n    char now() {\n        if (pos == INPUT_BUF)\
    \ {\n            size_t len = fread(buf, 1, INPUT_BUF, fp);\n            if (len\
    \ != INPUT_BUF) buf[len] = '\\n';\n            pos = 0;\n        }\n        return\
    \ buf[pos];\n    }\n\n    void skip_space() {\n        while (isspace(now()))\
    \ ++pos;\n    }\n\n    uint32_t next_u32() {\n        skip_space();\n        uint32_t\
    \ res = 0;\n        while (isdigit(now())) {\n            res = res * 10 + (now()\
    \ - '0');\n            ++pos;\n        }\n        return res;\n    }\n\n    int32_t\
    \ next_i32() {\n        skip_space();\n        if (now() == '-') {\n         \
    \   ++pos;\n            return (int32_t)(-next_u32());\n        }\n        else\
    \ return (int32_t)next_uint();\n    }\n\n    uint64_t next_u64() {\n        skip_space();\n\
    \        uint64_t res = 0;\n        while (isdigit(now())) {\n            res\
    \ = res * 10 + (now() - '0');\n            ++pos;\n        }\n        return res;\n\
    \    }\n\n    int64_t next_i64() {\n        skip_space();\n        if (now() ==\
    \ '-') {\n            ++pos;\n            return (int64_t)(-next_u64());\n   \
    \     }\n        else return (int64_t)next_u64();\n    }\n\n    __uint128_t next_u128()\
    \ {\n        skip_space();\n        __uint128_t res = 0;\n        while (isdigit(now()))\
    \ {\n            res = res * 10 + (now() - '0');\n            ++pos;\n       \
    \ }\n        return res;\n    }\n\n    __int128_t next_i128() {\n        skip_space();\n\
    \        if (now() == '-') {\n            ++pos;\n            return (__int128_t)(-next_u128());\n\
    \        }\n        else return (__int128_t)next_u128();\n    }\n\n    char next_char()\
    \ {\n        skip_space();\n        auto res = now();\n        ++pos;\n      \
    \  return res;\n    }\n\n    std::string next_string() {\n        skip_space();\n\
    \        std::string res;\n        while (!isspace(now())) {\n            res.push_back(now());\n\
    \            ++pos;\n        }\n        return res;\n    }\n\n    Scanner &operator>>(int\
    \ &x) {\n        x = next_i32();\n        return *this;\n    }\n\n    Scanner\
    \ &operator>>(unsigned int &x) {\n        x = next_u32();\n        return *this;\n\
    \    }\n\n    Scanner &operator>>(long long &x) {\n        x = next_i64();\n \
    \       return *this;\n    }\n\n    Scanner &operator>>(unsigned long long &x)\
    \ {\n        x = next_u64();\n        return *this;\n    }\n\n    Scanner &operator>>(__int128_t\
    \ &x) {\n        x = next_i128();\n        return *this;\n    }\n\n    Scanner\
    \ &operator>>(__uint128_t &x) {\n        x = next_u128();\n        return *this;\n\
    \    }\n};\n\n#ifdef KK2\nScanner kin(INPUT_FILE);\n#elif defined(INTERACTIVE)\n\
    #define kin std::cin\n#else\nScanner kin;\n#endif\n\n} // namespace fastio\n\n\
    } // namespace kk2\n\n#endif // TEMPLATE_FASTIO_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: template/fastio.hpp
  requiredBy: []
  timestamp: '2024-10-11 14:10:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/fastio.hpp
layout: document
redirect_from:
- /library/template/fastio.hpp
- /library/template/fastio.hpp.html
title: template/fastio.hpp
---
