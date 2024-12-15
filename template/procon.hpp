#ifndef TEMPLATE_PROCON_HPP
#define TEMPLATE_PROCON_HPP 1

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

#ifndef INPUT_FILE
#define INPUT_FILE "in.txt"
#endif
#ifndef OUTPUT_FILE
#define OUTPUT_FILE "out.txt"
#endif

#ifdef KK2
std::ifstream kin(INPUT_FILE);
std::ofstream kout(OUTPUT_FILE);
auto (*kendl)(std::ostream &) = std::endl<char, std::char_traits<char>>;
#else
auto &kin = std::cin;
auto &kout = std::cout;
auto (*kendl)(std::ostream &) = std::endl<char, std::char_traits<char>>;
#endif

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

#endif // TEMPLATE_PROCON_HPP
