#ifndef TEMPLATE
#define TEMPLATE 1

#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

using pi = pair<int, int>;
using pl = pair<i64, i64>;
using pil = pair<int, i64>;
using pli = pair<i64, int>;

template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = (1 << 30) - 123;
template <>
constexpr i64 infty<i64> = (1ll << 62) - (1ll << 31);
template <>
constexpr i128 infty<i128> = i128(infty<i64>) * infty<i64>;
template <>
constexpr u32 infty<u32> = infty<int>;
template <>
constexpr u64 infty<u64> = infty<i64>;
template <>
constexpr double infty<double> = infty<i64>;
template <>
constexpr long double infty<long double> = infty<i64>;
constexpr int mod = 998244353;
constexpr int modu = 1e9 + 7;

template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;

template <class T>
using pq = priority_queue<T>;
template <class T>
using pqi = priority_queue<T, vector<T>, greater<T>>;

template <class T, class S>
inline bool chmax(T &a, const S &b) {
    return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
    return (a > b ? a = b, 1 : 0);
}

# define rep1(a) for (i64 _ = 0; _ < i64(a); _++)
# define rep2(i, a) for (i64 i = 0; i < i64(a); i++)
# define rep3(i, a, b) for (i64 i = (a); i < i64(b); i++)
# define repi2(i, a) for (i64 i = (a) - 1; i >= 0; i--)
# define repi3(i, a, b) for (i64 i = (a) - 1; i >= (b); i--)
# define overload3(a, b, c, d, ...) d
# define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
# define repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)

# define pb push_back
# define eb emplace_back
# define fi first
# define se second
# define all(p) begin(p), end(p)

#endif // TEMPLATE
