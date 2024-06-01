#ifndef GEOMETRY_ARGUMENT_HPP
#define GEOMETRY_ARGUMENT_HPP 1

#include "point.hpp"

template <int id>
struct ArgumentSort {
    using i64 = long long;
    static Point O;
    static void setO(const Point& p) { O = p; }

  private:
    // p - O = (x, y) 
    // 1 : y < 0
    // 2 : y >= 0 and x >= 0
    // 3 : otherwise
    static int location(const Point& p) {
        Point q = p - O;
        return q.y < 0 ? 1 : q.x >= 0 ? 2 : 3;
    }

    static bool cmp(const Point& a, const Point& b) {
        int loc_a = location(a), loc_b = location(b);
        i64 cr = cross(a, b, O);
        return loc_a != loc_b ? loc_a < loc_b :
               cr == 0 ? norm(a, O) < norm(b, O) : cr > 0;
    }

  public:
    static void argument_sort(vector<Point>& ps) {
        sort(begin(ps), end(ps), cmp);
    }

    template <class ForwardIt>
    static ForwardIt min_up_argument(ForwardIt first, ForwardIt last, const Point& p) {
        return lower_bound(first, last, p, cmp);
    }
};
template <int id>
Point ArgumentSort<id>::O(0, 0);

#endif // GEOMETRY_ARGUMENT_HPP
