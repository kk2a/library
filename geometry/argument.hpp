#ifndef GEOMETRY_ARGUMENT_HPP
#define GEOMETRY_ARGUMENT_HPP 1

#include <algorithm>
#include "point.hpp"

namespace kk2 {

template <class T>
struct ArgumentSort {
    using i64 = long long;
    static Point<T> O;
    static void setO(const Point<T>& p) { O = p; }

  private:
    // p - O = (x, y) 
    // 1 : y < 0
    // 2 : y >= 0 and x >= 0
    // 3 : otherwise
    static int location(const Point<T>& p) {
        Point<T> q = p - O;
        return q.y < 0 ? 1 : q.x >= 0 ? 2 : 3;
    }

    static bool cmp(const Point<T>& a, const Point<T>& b) {
        int loc_a = location(a), loc_b = location(b);
        i64 cr = cross(a, b, O);
        return loc_a != loc_b ? loc_a < loc_b :
               cr == 0 ? norm(a, O) < norm(b, O) : cr > 0;
    }

  public:
    static void argument_sort(vector<Point<T>>& ps) {
        std::sort(std::begin(ps), std::end(ps), cmp);
    }

    template <class ForwardIt>
    static ForwardIt min_up_argument(ForwardIt first, ForwardIt last, const Point<T>& p) {
        return std::lower_bound(first, last, p, cmp);
    }
};

} // namespace kk2

#endif // GEOMETRY_ARGUMENT_HPP
