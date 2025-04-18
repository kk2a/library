#ifndef KK2_GEOMETRY_ARGUMENT_SORT_HPP
#define KK2_GEOMETRY_ARGUMENT_SORT_HPP 1

#include <algorithm>
#include <vector>

#include "point.hpp"

namespace kk2 {

template <class T> struct ArgumentSort {
    using point = Point<T>;
    point O;

    ArgumentSort(const point &O_ = point()) : O(O_) {}

    // p - O = (x, y)
    // 1 : y < 0
    // 2 : y >= 0 and x >= 0
    // 3 : otherwise
    int location(const point &p) {
        point q = p - O;
        return q.y < 0 ? 1 : q.x >= 0 ? 2 : 3;
    }

    bool cmp(const point &a, const point &b) {
        int loc_a = location(a), loc_b = location(b);
        T cr = cross(a, b, O);
        return loc_a != loc_b ? loc_a < loc_b : cr == 0 ? norm(a, O) < norm(b, O) : cr > 0;
    }

    void argument_sort(std::vector<point> &ps) {
        std::sort(
            ps.begin(), ps.end(), [this](auto &&a, auto &&b) -> bool { return this->cmp(a, b); });
    }

    template <class Iterator>
    Iterator min_up_argument(Iterator first, Iterator last, const point &p) {
        return std::lower_bound(
            first, last, p, [this](auto &&a, auto &&b) -> bool { return this->cmp(a, b); });
    }
};

} // namespace kk2

#endif // KK2_GEOMETRY_ARGUMENT_SORT_HPP
