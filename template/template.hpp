#ifndef TEMPLATE
#define TEMPLATE 1

// #pragma GCC optimize("O3,unroll-loops")

// #include <bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "../type_traits/type_traits.hpp"
#include "fastio.hpp"

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;

using pi = std::pair<int, int>;
using pl = std::pair<i64, i64>;
using pil = std::pair<int, i64>;
using pli = std::pair<i64, int>;

template <class T> using vc = std::vector<T>;
template <class T> using vvc = std::vector<vc<T>>;
template <class T> using vvvc = std::vector<vvc<T>>;
template <class T> using vvvvc = std::vector<vvvc<T>>;

template <class T> using pq = std::priority_queue<T>;
template <class T> using pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <class T> constexpr T infty = 0;
template <> constexpr int infty<int> = (1 << 30) - 123;
template <> constexpr i64 infty<i64> = (1ll << 62) - (1ll << 31);
template <> constexpr i128 infty<i128> = (i128(1) << 126) - (i128(1) << 63);
template <> constexpr u32 infty<u32> = infty<int>;
template <> constexpr u64 infty<u64> = infty<i64>;
template <> constexpr u128 infty<u128> = infty<i128>;
template <> constexpr double infty<double> = infty<i64>;
template <> constexpr long double infty<long double> = infty<i64>;

constexpr int mod = 998244353;
constexpr int modu = 1e9 + 7;
constexpr long double PI = 3.14159265358979323846;

namespace kk2 {

template <class T, class... Sizes> auto make_vector(int first, Sizes... sizes) {
    if constexpr (sizeof...(sizes) == 0) {
        return std::vector<T>(first);
    } else {
        return std::vector<decltype(make_vector(sizes...))>(first, make_vector(sizes...));
    }
}

template <class T, class U> void fill_all(std::vector<T> &v, const U &x) {
    std::fill(std::begin(v), std::end(v), T(x));
}

template <class T, class U> void fill_all(std::vector<std::vector<T>> &v, const U &x) {
    for (auto &u : v) fill_all(u, x);
}

} // namespace kk2

template <class T, class S> inline bool chmax(T &a, const S &b) {
    return (a < b ? a = b, 1 : 0);
}

template <class T, class S> inline bool chmin(T &a, const S &b) {
    return (a > b ? a = b, 1 : 0);
}

#define rep1(a) for (i64 _ = 0; _ < (i64)(a); ++_)
#define rep2(i, a) for (i64 i = 0; i < (i64)(a); ++i)
#define rep3(i, a, b) for (i64 i = (a); i < (i64)(b); ++i)
#define repi2(i, a) for (i64 i = (a) - 1; i >= 0; --i)
#define repi3(i, a, b) for (i64 i = (a) - 1; i >= (i64)(b); --i)
#define overload3(a, b, c, d, ...) d
#define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)

#define fi first
#define se second
#define all(p) std::begin(p), std::end(p)

using kk2::kendl;
using kk2::kin;
using kk2::kout;

struct IoSetUp {
    IoSetUp() {
        std::cin.tie(nullptr);
        std::ios::sync_with_stdio(false);
    }
} iosetup;

template <class OStream, class T, class U, kk2::is_ostream_t<OStream> * = nullptr>
OStream &operator<<(OStream &os, const std::pair<T, U> &p) {
    os << p.first << ' ' << p.second;
    return os;
}

template <class IStream, class T, class U, kk2::is_istream_t<IStream> * = nullptr>
IStream &operator>>(IStream &is, std::pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}

template <class OStream, class T, kk2::is_ostream_t<OStream> * = nullptr>
OStream &operator<<(OStream &os, const std::vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) { os << v[i] << (i + 1 == (int)v.size() ? "" : " "); }
    return os;
}

template <class IStream, class T, kk2::is_istream_t<IStream> * = nullptr>
IStream &operator>>(IStream &is, std::vector<T> &v) {
    for (auto &x : v) is >> x;
    return is;
}

void Yes(bool b = 1) {
    kout << (b ? "Yes\n" : "No\n");
}

void No(bool b = 1) {
    kout << (b ? "No\n" : "Yes\n");
}

void YES(bool b = 1) {
    kout << (b ? "YES\n" : "NO\n");
}

void NO(bool b = 1) {
    kout << (b ? "NO\n" : "YES\n");
}

void yes(bool b = 1) {
    kout << (b ? "yes\n" : "no\n");
}

void no(bool b = 1) {
    kout << (b ? "no\n" : "yes\n");
}

#endif // TEMPLATE
