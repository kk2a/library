#ifndef TEMPLATE
#define TEMPLATE 1

#pragma GCC optimize("O3,unroll-loops")

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

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;

using pi = std::pair<int, int>;
using pl = std::pair<i64, i64>;
using pil = std::pair<int, i64>;
using pli = std::pair<i64, int>;

template <class T> constexpr T infty = 0;
template <> constexpr int infty<int> = (1 << 30) - 123;
template <> constexpr i64 infty<i64> = (1ll << 62) - (1ll << 31);
template <> constexpr i128 infty<i128> = i128(infty<i64>) * infty<i64>;
template <> constexpr u32 infty<u32> = infty<int>;
template <> constexpr u64 infty<u64> = infty<i64>;
template <> constexpr double infty<double> = infty<i64>;
template <> constexpr long double infty<long double> = infty<i64>;

constexpr int mod = 998244353;
constexpr int modu = 1e9 + 7;
constexpr long double PI = 3.14159265358979323846;

template <class T> using vc = std::vector<T>;
template <class T> using vvc = std::vector<vc<T>>;
template <class T> using vvvc = std::vector<vvc<T>>;
template <class T> using vvvvc = std::vector<vvvc<T>>;

template <class T> using pq = std::priority_queue<T>;
template <class T> using pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;

namespace kk2 {

template <class T, class... Sizes> auto make_vector(const T &init, int first, Sizes... sizes) {
    if constexpr (sizeof...(sizes) == 0) {
        return std::vector<T>(first, init);
    } else {
        return std::vector<decltype(make_vector(init, sizes...))>(first,
                                                                  make_vector(init, sizes...));
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

#ifdef KK2
std::ifstream in("in.txt");
std::ofstream out("out.txt");
#else
#define in std::cin
#define out std::cout
#endif

void YES(bool b = 1) {
    std::cout << (b ? "YES" : "NO") << '\n';
}

void NO(bool b = 1) {
    std::cout << (b ? "NO" : "YES") << '\n';
}

void YESflush(bool b = 1) {
    std::cout << (b ? "YES" : "NO") << std::endl;
}

void NOflush(bool b = 1) {
    std::cout << (b ? "NO" : "YES") << std::endl;
}

void Yes(bool b = 1) {
    std::cout << (b ? "Yes" : "No") << '\n';
}

void No(bool b = 1) {
    std::cout << (b ? "No" : "Yes") << '\n';
}

void Yesflush(bool b = 1) {
    std::cout << (b ? "Yes" : "No") << std::endl;
}

void Noflush(bool b = 1) {
    std::cout << (b ? "No" : "Yes") << std::endl;
}

void yes(bool b = 1) {
    std::cout << (b ? "yes" : "no") << '\n';
}

void no(bool b = 1) {
    std::cout << (b ? "no" : "yes") << '\n';
}

void yesflush(bool b = 1) {
    std::cout << (b ? "yes" : "no") << std::endl;
}

void noflush(bool b = 1) {
    std::cout << (b ? "no" : "yes") << std::endl;
}

#endif // TEMPLATE
