#ifndef KK2_TEMPLATE_TEMPLATE_HPP
#define KK2_TEMPLATE_TEMPLATE_HPP 1

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <functional>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "constant.hpp"
#include "fastio.hpp"
#include "io_util.hpp"
#include "macros.hpp"
#include "type_alias.hpp"

using kk2::kendl;
using kk2::kin;
using kk2::kout;

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

template <class T, class S> inline bool chmax(T &a, const S &b) {
    return (a < b ? a = b, 1 : 0);
}

template <class T, class S> inline bool chmin(T &a, const S &b) {
    return (a > b ? a = b, 1 : 0);
}

#endif // KK2_TEMPLATE_TEMPLATE_HPP
