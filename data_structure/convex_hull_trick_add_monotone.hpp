#ifndef KK2_DATA_STRUCTURE_CONVEX_HULL_TRICK_ADD_MONOTONE_HPP
#define KK2_DATA_STRUCTURE_CONVEX_HULL_TRICK_ADD_MONOTONE_HPP 1

#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <tuple>

#include "../math/frac_floor.hpp"
#include "../type_traits/type_traits.hpp"

namespace kk2 {

template <typename T, bool isMin = true> struct CHTAddMonotone {
    struct Line {
        // ax + b
        T a, b;

        Line(T a_, T b_) : a(a_), b(b_) {}

        T eval(T x) const { return a * x + b; }
    };

    std::deque<Line> lines;

    CHTAddMonotone() = default;

    bool empty() const { return lines.empty(); }

    void clear() { lines.clear(); }

    static constexpr int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }

    template <typename Iterators> static constexpr bool check(Iterators mid) {
        auto [l1, l2, l3] = std::tie(*std::prev(mid), *mid, *std::next(mid));
        if (l2.b == l1.b or l3.b == l2.b)
            return sgn(l2.a - l1.a) * sgn(l3.b - l2.b) >= sgn(l3.a - l2.a) * sgn(l2.b - l1.b);
        if constexpr (is_integral_extended<T>::value) {
            return kk2::fracfloor(l2.b - l1.b, l1.a - l2.a)
                   >= kk2::fracfloor(l3.b - l2.b, l2.a - l3.a);
        } else {
            return (l2.b - l1.b) * sgn(l3.a - l2.a) / std::abs(l2.a - l1.a)
                   >= (l3.b - l2.b) * sgn(l2.a - l1.a) / std::abs(l3.a - l2.a);
        }
    }

    void add(T a, T b) {
        if (!isMin) a = -a, b = -b;
        Line l(a, b);
        if (empty()) {
            lines.emplace_back(l);
            return;
        }
        if (lines.front().a <= a) {
            if (lines.front().a == a) {
                if (lines.front().b <= b) return;
                lines.pop_front();
            }
            lines.emplace_front(l);
            while ((int)lines.size() >= 3 and check(std::next(lines.begin()))) {
                lines.erase(std::next(lines.begin()));
            }
        } else if (lines.back().a >= a) {
            if (lines.back().a == a) {
                if (lines.back().b <= b) return;
                lines.pop_back();
            }
            lines.emplace_back(l);
            while ((int)lines.size() >= 3 and check(std::prev(lines.end(), 2))) {
                lines.erase(std::prev(lines.end(), 2));
            }
        } else {
            std::cerr << "Invalid input" << std::endl;
            exit(1);
        }
    }

    T query(T x) const {
        assert(!empty());
        int l = -1, r = (int)lines.size() - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (lines[mid].eval(x) >= lines[mid + 1].eval(x)) l = mid;
            else r = mid;
        }
        if constexpr (isMin) return lines[r].eval(x);
        else return -lines[r].eval(x);
    }
};

} // namespace kk2

#endif // KK2_DATA_STRUCTURE_CONVEX_HULL_TRICK_ADD_MONOTONE_HPP
