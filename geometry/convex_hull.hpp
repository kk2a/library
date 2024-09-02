#ifndef GEOMETRY_CONVEX_HULL_HPP
#define GEOMETRY_CONVEX_HULL_HPP 1

#include "point.hpp"

namespace kk2 {

template <typename T>
struct ConvexHull {
    vector<Point<T>> ps, hull;

    ConvexHull() = default;
    ConvexHull(const vector<Point<T>>& ps) : ps(ps) {}

    void emplace_point(T x, T y) {
        ps.emplace_back(x, y);
    }
    void push_point(const Point<T>& p) {
        ps.push_back(p);
    }

    void build() {
        int _n = size(ps);
        if (_n == 1) {
            hull = ps;
            return;
        }
        sort(begin(ps), end(ps));
        vector<Point<T>> up, dw;
        up.push_back(ps[0]);
        dw.push_back(ps[0]);
        up.push_back(ps[1]);
        dw.push_back(ps[1]);

        for (int i = 2; i < _n; i++) {
            while (size(up) >= 2 && cross(up[size(up) - 1]
                   - up[size(up) - 2], ps[i] - up[size(up) - 1]) >= 0) {
                up.pop_back();
            }
            while (size(dw) >= 2 && cross(dw[size(dw) - 1]
                   - dw[size(dw) - 2], ps[i] - dw[size(dw) - 1]) <= 0) {
                dw.pop_back();
            }
            up.push_back(ps[i]);
            dw.push_back(ps[i]);
        }
        hull = up;
        for (int i = size(dw) - 2; i > 0; i--) {
            hull.emplace_back(dw[i]);
        }
    }
};

} // namespace kk2

#endif // GEOMETRY_CONVEX_HULL_HPP