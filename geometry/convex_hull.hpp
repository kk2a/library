#ifndef GEOMETRY_CONVEX_HULL_HPP
#define GEOMETRY_CONVEX_HULL_HPP 1

#include "point.hpp"

namespace kk2 {

struct Convex_hull {
    using i64 = long long;
  public:
    vector<Point> ps, hull;

    void add_point(i64 x, i64 y) {
        ps.emplace_back(x, y);
    }

    void query() {
        int _n = size(ps);
        if (_n == 1) {
            hull = ps;
            return;
        }
        vector<Point> res = ps;
        sort(res.begin(), res.end());
        vector<Point> up, dw;
        up.emplace_back(res[0]); dw.emplace_back(res[0]);
        up.emplace_back(res[1]); dw.emplace_back(res[1]);
        for (int i = 2; i < _n; i++) {
            while (size(up) >= 2 && cross(up[size(up) - 1]
                   - up[size(up) - 2], res[i] - up[size(up) - 1]) >= 0) {
                up.pop_back();
            }
            while (size(dw) >= 2 && cross(dw[size(dw) - 1]
                   - dw[size(dw) - 2], res[i] - dw[size(dw) - 1]) <= 0) {
                dw.pop_back();
            }
            up.emplace_back(res[i]);
            dw.emplace_back(res[i]);
        }
        hull = up;
        for (int i = size(dw) - 2; i > 0; i--) {
            hull.emplace_back(dw[i]);
        }
    }
};

} // namespace kk2

#endif // GEOMETRY_CONVEX_HULL_HPP
