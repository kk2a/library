#ifndef KK2_TEMPLATE_PROCON_HPP
#define KK2_TEMPLATE_PROCON_HPP 1

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
// #include <chrono>
// #include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "type_alias.hpp"
#include "constant.hpp"
#include "function_util.hpp"
#include "macros.hpp"
#include "io_util.hpp"

struct FastIOSetUp {
    FastIOSetUp() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);  
    }
} fast_io_set_up;
auto &kin = std::cin;
auto &kout = std::cout;
auto (*kendl)(std::ostream &) = std::endl<char, std::char_traits<char>>;

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

std::istream &operator>>(std::istream &is, u128 &x) {
    std::string s;
    is >> s;
    x = 0;
    for (char c : s) {
        assert('0' <= c && c <= '9');
        x = x * 10 + c - '0';
    }
    return is;
}

std::istream &operator>>(std::istream &is, i128 &x) {
    std::string s;
    is >> s;
    bool neg = s[0] == '-';
    x = 0;
    for (int i = neg; i < (int)s.size(); i++) {
        assert('0' <= s[i] && s[i] <= '9');
        x = x * 10 + s[i] - '0';
    }
    if (neg) x = -x;
    return is;
}

std::ostream &operator<<(std::ostream &os, u128 x) {
    if (x == 0) return os << '0';
    std::string s;
    while (x) {
        s.push_back('0' + x % 10);
        x /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

std::ostream &operator<<(std::ostream &os, i128 x) {
    if (x == 0) return os << '0';
    if (x < 0) {
        os << '-';
        x = -x;
    }
    std::string s;
    while (x) {
        s.push_back('0' + x % 10);
        x /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

#endif // KK2_TEMPLATE_PROCON_HPP
