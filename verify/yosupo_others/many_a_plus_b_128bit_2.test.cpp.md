---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/monoid/max.hpp
    title: math/monoid/max.hpp
  - icon: ':question:'
    path: math/monoid/min.hpp
    title: math/monoid/min.hpp
  - icon: ':question:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':x:'
    path: template/function_util.hpp
    title: template/function_util.hpp
  - icon: ':question:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':question:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':x:'
    path: template/procon.hpp
    title: template/procon.hpp
  - icon: ':question:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':question:'
    path: type_traits/container_traits.hpp
    title: type_traits/container_traits.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb_128bit
    links:
    - https://judge.yosupo.jp/problem/many_aplusb_128bit
  bundledCode: "#line 1 \"verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb_128bit\" \n\n#line\
    \ 1 \"template/procon.hpp\"\n\n\n\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <map>\n#include <numeric>\n#include <optional>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <vector>\n\n#line 1 \"template/constant.hpp\"\
    \n\n\n\n#line 1 \"template/type_alias.hpp\"\n\n\n\n#line 8 \"template/type_alias.hpp\"\
    \n\nusing u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi = std::pair<int,\
    \ int>;\nusing pl = std::pair<i64, i64>;\nusing pil = std::pair<int, i64>;\nusing\
    \ pli = std::pair<i64, int>;\n\ntemplate <class T> using vc = std::vector<T>;\n\
    template <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using vvvc\
    \ = std::vector<vvc<T>>;\ntemplate <class T> using vvvvc = std::vector<vvvc<T>>;\n\
    \ntemplate <class T> using pq = std::priority_queue<T>;\ntemplate <class T> using\
    \ pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\n\n#line 5\
    \ \"template/constant.hpp\"\n\ntemplate <class T> constexpr T infty = 0;\ntemplate\
    \ <> constexpr int infty<int> = (1 << 30) - 123;\ntemplate <> constexpr i64 infty<i64>\
    \ = (1ll << 62) - (1ll << 31);\ntemplate <> constexpr i128 infty<i128> = (i128(1)\
    \ << 126) - (i128(1) << 63);\ntemplate <> constexpr u32 infty<u32> = infty<int>;\n\
    template <> constexpr u64 infty<u64> = infty<i64>;\ntemplate <> constexpr u128\
    \ infty<u128> = infty<i128>;\ntemplate <> constexpr double infty<double> = infty<i64>;\n\
    template <> constexpr long double infty<long double> = infty<i64>;\n\nconstexpr\
    \ int mod = 998244353;\nconstexpr int modu = 1e9 + 7;\nconstexpr long double PI\
    \ = 3.14159265358979323846;\n\n\n#line 1 \"template/function_util.hpp\"\n\n\n\n\
    #line 6 \"template/function_util.hpp\"\n\n#line 1 \"math/monoid/max.hpp\"\n\n\n\
    \n#line 5 \"math/monoid/max.hpp\"\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include\
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
    \ kk2\n\n\n#line 7 \"math/monoid/max.hpp\"\n\nnamespace kk2 {\n\nnamespace monoid\
    \ {\n\ntemplate <class S, class Compare = std::less<S>> struct Max {\n    static\
    \ constexpr bool commutative = true;\n    using M = Max;\n    S a;\n    bool is_unit;\n\
    \n    Max() : a(S()), is_unit(true) {}\n    Max(S a_) : a(a_), is_unit(false)\
    \ {}\n    operator S() const { return a; }\n\n    inline static M op(M l, M r)\
    \ {\n        if (l.is_unit or r.is_unit) return l.is_unit ? r : l;\n        return\
    \ Compare{}(l.a, r.a) ? r : l;\n    }\n\n    inline static M unit() { return M();\
    \ }\n\n    bool operator==(const M &rhs) const {\n        return is_unit == rhs.is_unit\
    \ and (is_unit or a == rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const\
    \ {\n        return is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n   \
    \ }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend\
    \ OStream &operator<<(OStream &os, const M &x) {\n        if (x.is_unit) os <<\
    \ \"-inf\";\n        else os << x.a;\n        return os;\n    }\n\n    template\
    \ <class IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, M &x) {\n        is >> x.a;\n        x.is_unit = false;\n        return\
    \ is;\n    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\n\n#line 1 \"\
    math/monoid/min.hpp\"\n\n\n\n#line 5 \"math/monoid/min.hpp\"\n\n#line 7 \"math/monoid/min.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace monoid {\n\ntemplate <class S, class Compare\
    \ = std::less<S>> struct Min {\n    static constexpr bool commutative = true;\n\
    \    using M = Min;\n    S a;\n    bool is_unit;\n\n    Min() : a(S()), is_unit(true)\
    \ {}\n    Min(S a_) : a(a_), is_unit(false) {}\n    operator S() const { return\
    \ a; }\n\n    inline static M op(M l, M r) {\n        if (l.is_unit or r.is_unit)\
    \ return l.is_unit ? r : l;\n        return Compare{}(l.a, r.a) ? l : r;\n   \
    \ }\n\n    inline static M unit() { return M(); }\n\n    bool operator==(const\
    \ M &rhs) const {\n        return is_unit == rhs.is_unit and (is_unit or a ==\
    \ rhs.a);\n    }\n\n    bool operator!=(const M &rhs) const {\n        return\
    \ is_unit != rhs.is_unit or (!is_unit and a != rhs.a);\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const M &x) {\n        if (x.is_unit) os << \"inf\";\n        else os <<\
    \ x.a;\n        return os;\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    friend IStream &operator>>(IStream &is, M &x) {\n        is\
    \ >> x.a;\n        x.is_unit = false;\n        return is;\n    }\n};\n\n} // namespace\
    \ monoid\n\n} // namespace kk2\n\n\n#line 1 \"type_traits/container_traits.hpp\"\
    \n\n\n\n#line 6 \"type_traits/container_traits.hpp\"\n#include <list>\n#line 10\
    \ \"type_traits/container_traits.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename\
    \ T> struct is_vector : std::false_type {};\ntemplate <typename T, typename Alloc>\
    \ struct is_vector<std::vector<T, Alloc>> : std::true_type {};\n\ntemplate <typename\
    \ T> struct is_container : std::false_type {};\ntemplate <typename T, typename\
    \ Alloc> struct is_container<std::vector<T, Alloc>> : std::true_type {\n};\ntemplate\
    \ <typename CharT, typename Traits, typename Alloc>\nstruct is_container<std::basic_string<CharT,\
    \ Traits, Alloc>> : std::true_type {};\ntemplate <typename T, std::size_t N> struct\
    \ is_container<std::array<T, N>> : std::true_type {};\ntemplate <typename T, typename\
    \ Alloc> struct is_container<std::deque<T, Alloc>> : std::true_type {};\ntemplate\
    \ <typename T, typename Alloc> struct is_container<std::list<T, Alloc>> : std::true_type\
    \ {};\ntemplate <typename T> using is_container_t = typename std::enable_if_t<is_container<T>::value>;\n\
    \n} // namespace kk2\n\n\n#line 10 \"template/function_util.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class T, class... Sizes> auto make_vector(int first, Sizes...\
    \ sizes) {\n    if constexpr (sizeof...(sizes) == 0) {\n        return std::vector<T>(first);\n\
    \    } else {\n        return std::vector<decltype(make_vector<T>(sizes...))>(first,\
    \ make_vector<T>(sizes...));\n    }\n}\n\ntemplate <class T, class U> void fill_all(std::vector<T>\
    \ &v, const U &x) {\n    if constexpr (is_vector<T>::value) {\n        for (auto\
    \ &u : v) fill_all(u, x);\n    } else {\n        std::fill(v.begin(), v.end(),\
    \ T(x));\n    }\n}\n\ntemplate <class T, class U> int iota_all(std::vector<T>\
    \ &v, U x, int offset = 0) {\n    if constexpr (is_vector<T>::value) {\n     \
    \   for (auto &u : v) offset += iota_all(u, x + offset);\n    } else {\n     \
    \   for (auto &u : v) u = x++, ++offset;\n    }\n    return offset;\n}\n\ntemplate\
    \ <class C> int mysize(const C &c) { return size(c); }\n\n\n// T: commutative\
    \ monoid, F: (U, T) -> U\ntemplate <class U, class T, class F>\nU all_monoid_prod(const\
    \ std::vector<T> &v, U unit, const F &f) {\n    U res = unit;\n    if constexpr\
    \ (is_vector<T>::value) {\n        for (const auto &x : v) res = f(res, all_monoid_prod(x,\
    \ unit, f));\n    } else {\n        for (const auto &x : v) res = f(res, x);\n\
    \    }\n    return res;\n}\n\ntemplate <class U, class T> U all_sum(const std::vector<T>\
    \ &v, U unit = U()) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return a + b; });\n}\ntemplate <class U, class T> U all_prod(const std::vector<T>\
    \ &v, U unit = U(1)) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return a * b; });\n}\ntemplate <class U, class T> U all_xor(const std::vector<T>\
    \ &v, U unit = U()) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return a ^ b; });\n}\ntemplate <class U, class T> U all_and(const std::vector<T>\
    \ &v, U unit = U(-1)) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return a & b; });\n}\ntemplate <class U, class T> U all_or(const std::vector<T>\
    \ &v, U unit = U()) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return a | b; });\n}\ntemplate <class U, class T> U all_min(const std::vector<T>\
    \ &v) {\n    return all_monoid_prod<monoid::Min<U>, T>(v, monoid::Min<U>::unit(),\
    \ monoid::Min<U>::op);\n}\ntemplate <class U, class T> U all_max(const std::vector<T>\
    \ &v) {\n    return all_monoid_prod<monoid::Max<U>, T>(v, monoid::Max<U>::unit(),\
    \ monoid::Max<U>::op);\n}\ntemplate <class U, class T> U all_gcd(const std::vector<T>\
    \ &v, U unit = U()) {\n    return all_monoid_prod<U, T>(v, unit, [](U a, U b)\
    \ { return std::gcd(a, b); });\n}\ntemplate <class U, class T> U all_lcm(const\
    \ std::vector<T> &v, U unit = U(1)) {\n    return all_monoid_prod<U, T>(v, unit,\
    \ [](U a, U b) { return std::lcm(a, b); });\n}\ntemplate <class U, class T> int\
    \ all_count(const std::vector<T> &v, U x) {\n    return all_monoid_prod<int, T>(v,\
    \ 0, [x](int a, U y) { return a + int(x == y); });\n}\n\n} // namespace kk2\n\n\
    \n#line 1 \"template/io_util.hpp\"\n\n\n\n#line 7 \"template/io_util.hpp\"\n\n\
    #line 9 \"template/io_util.hpp\"\n\n// \u306A\u3093\u304Boj verify\u306F\u30D7\
    \u30ED\u30C8\u30BF\u30A4\u30D7\u5BA3\u8A00\u304C\u843D\u3061\u308B\n\nnamespace\
    \ impl {\n\nstruct read {\n    template <class IStream, class T> inline static\
    \ void all_read(IStream &is, T &x) { is >> x; }\n\n    template <class IStream,\
    \ class T, class U>\n    inline static void all_read(IStream &is, std::pair<T,\
    \ U> &p) {\n        all_read(is, p.first);\n        all_read(is, p.second);\n\
    \    }\n\n    template <class IStream, class T> inline static void all_read(IStream\
    \ &is, std::vector<T> &v) {\n        for (T &x : v) all_read(is, x);\n    }\n\n\
    \    template <class IStream, class T, size_t F>\n    inline static void all_read(IStream\
    \ &is, std::array<T, F> &a) {\n        for (T &x : a) all_read(is, x);\n    }\n\
    };\n\nstruct write {\n    template <class OStream, class T> inline static void\
    \ all_write(OStream &os, const T &x) {\n        os << x;\n    }\n\n    template\
    \ <class OStream, class T, class U>\n    inline static void all_write(OStream\
    \ &os, const std::pair<T, U> &p) {\n        all_write(os, p.first);\n        all_write(os,\
    \ ' ');\n        all_write(os, p.second);\n    }\n\n    template <class OStream,\
    \ class T>\n    inline static void all_write(OStream &os, const std::vector<T>\
    \ &v) {\n        for (int i = 0; i < (int)v.size(); ++i) {\n            if (i)\
    \ all_write(os, ' ');\n            all_write(os, v[i]);\n        }\n    }\n\n\
    \    template <class OStream, class T, size_t F>\n    inline static void all_write(OStream\
    \ &os, const std::array<T, F> &a) {\n        for (int i = 0; i < (int)F; ++i)\
    \ {\n            if (i) all_write(os, ' ');\n            all_write(os, a[i]);\n\
    \        }\n    }\n};\n\n} // namespace impl\n\ntemplate <class IStream, class\
    \ T, class U, kk2::is_istream_t<IStream> * = nullptr>\nIStream &operator>>(IStream\
    \ &is, std::pair<T, U> &p) {\n    impl::read::all_read(is, p);\n    return is;\n\
    }\n\ntemplate <class IStream, class T, kk2::is_istream_t<IStream> * = nullptr>\n\
    IStream &operator>>(IStream &is, std::vector<T> &v) {\n    impl::read::all_read(is,\
    \ v);\n    return is;\n}\n\ntemplate <class IStream, class T, size_t F, kk2::is_istream_t<IStream>\
    \ * = nullptr>\nIStream &operator>>(IStream &is, std::array<T, F> &a) {\n    impl::read::all_read(is,\
    \ a);\n    return is;\n}\n\ntemplate <class OStream, class T, class U, kk2::is_ostream_t<OStream>\
    \ * = nullptr>\nOStream &operator<<(OStream &os, const std::pair<T, U> &p) {\n\
    \    impl::write::all_write(os, p);\n    return os;\n}\n\ntemplate <class OStream,\
    \ class T, kk2::is_ostream_t<OStream> * = nullptr>\nOStream &operator<<(OStream\
    \ &os, const std::vector<T> &v) {\n    impl::write::all_write(os, v);\n    return\
    \ os;\n}\n\ntemplate <class OStream, class T, size_t F, kk2::is_ostream_t<OStream>\
    \ * = nullptr>\nOStream &operator<<(OStream &os, const std::array<T, F> &a) {\n\
    \    impl::write::all_write(os, a);\n    return os;\n}\n\n\n#line 1 \"template/macros.hpp\"\
    \n\n\n\n#define rep1(a) for (long long _ = 0; _ < (long long)(a); ++_)\n#define\
    \ rep2(i, a) for (long long i = 0; i < (long long)(a); ++i)\n#define rep3(i, a,\
    \ b) for (long long i = (a); i < (long long)(b); ++i)\n#define repi2(i, a) for\
    \ (long long i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (long long\
    \ i = (a) - 1; i >= (long long)(b); --i)\n#define overload3(a, b, c, d, ...) d\n\
    #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define\
    \ repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n#define\
    \ fi first\n#define se second\n#define all(p) begin(p), end(p)\n\n\n#line 31 \"\
    template/procon.hpp\"\n\nstruct FastIOSetUp {\n    FastIOSetUp() {\n        std::ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n    }\n} fast_io_set_up;\n\nauto &kin = std::cin;\n\
    auto &kout = std::cout;\nauto (*kendl)(std::ostream &) = std::endl<char, std::char_traits<char>>;\n\
    \nvoid Yes(bool b = 1) { kout << (b ? \"Yes\\n\" : \"No\\n\"); }\nvoid No(bool\
    \ b = 1) { kout << (b ? \"No\\n\" : \"Yes\\n\"); }\nvoid YES(bool b = 1) { kout\
    \ << (b ? \"YES\\n\" : \"NO\\n\"); }\nvoid NO(bool b = 1) { kout << (b ? \"NO\\\
    n\" : \"YES\\n\"); }\nvoid yes(bool b = 1) { kout << (b ? \"yes\\n\" : \"no\\\
    n\"); }\nvoid no(bool b = 1) { kout << (b ? \"no\\n\" : \"yes\\n\"); }\ntemplate\
    \ <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a =\
    \ b, 1 : 0); }\ntemplate <class T, class S> inline bool chmin(T &a, const S &b)\
    \ { return (a > b ? a = b, 1 : 0); }\n\nstd::istream &operator>>(std::istream\
    \ &is, u128 &x) {\n    std::string s;\n    is >> s;\n    x = 0;\n    for (char\
    \ c : s) {\n        assert('0' <= c && c <= '9');\n        x = x * 10 + c - '0';\n\
    \    }\n    return is;\n}\n\nstd::istream &operator>>(std::istream &is, i128 &x)\
    \ {\n    std::string s;\n    is >> s;\n    bool neg = s[0] == '-';\n    x = 0;\n\
    \    for (int i = neg; i < (int)s.size(); i++) {\n        assert('0' <= s[i] &&\
    \ s[i] <= '9');\n        x = x * 10 + s[i] - '0';\n    }\n    if (neg) x = -x;\n\
    \    return is;\n}\n\nstd::ostream &operator<<(std::ostream &os, u128 x) {\n \
    \   if (x == 0) return os << '0';\n    std::string s;\n    while (x) {\n     \
    \   s.push_back('0' + x % 10);\n        x /= 10;\n    }\n    std::reverse(s.begin(),\
    \ s.end());\n    return os << s;\n}\n\nstd::ostream &operator<<(std::ostream &os,\
    \ i128 x) {\n    if (x == 0) return os << '0';\n    if (x < 0) {\n        os <<\
    \ '-';\n        x = -x;\n    }\n    std::string s;\n    while (x) {\n        s.push_back('0'\
    \ + x % 10);\n        x /= 10;\n    }\n    std::reverse(s.begin(), s.end());\n\
    \    return os << s;\n}\n\n\n#line 4 \"verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int t;\n    kin >> t;\n    rep (t)\
    \ {\n        i128 a, b;\n        kin >> a >> b;\n        kout << a + b << \"\\\
    n\";\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb_128bit\" \n\
    \n#include \"../../template/procon.hpp\"\nusing namespace std;\n\nint main() {\n\
    \    int t;\n    kin >> t;\n    rep (t) {\n        i128 a, b;\n        kin >>\
    \ a >> b;\n        kout << a + b << \"\\n\";\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - template/procon.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/function_util.hpp
  - math/monoid/max.hpp
  - type_traits/io.hpp
  - math/monoid/min.hpp
  - type_traits/container_traits.hpp
  - template/io_util.hpp
  - type_traits/io.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
- /verify/verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp.html
title: verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
---
