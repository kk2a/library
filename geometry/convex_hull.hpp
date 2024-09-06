#ifndef GEOMETRY_CONVEX_HULL_HPP
#define GEOMETRY_CONVEX_HULL_HPP 1

#include "point.hpp"

namespace kk2 {

template <typename T>
struct ConvexHull {
    vector<Point<T>> ps, hull;
    vector<int> idx;

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
        vc<pair<Point<T>, int>> tmp(_n);
        rep (i, _n) tmp[i] = {ps[i], i};
        sort(all(tmp));
        vector<pair<Point<T>, int>> up, dw;
        up.push_back(tmp[0]);
        dw.push_back(tmp[0]);
        up.push_back(tmp[1]);
        dw.push_back(tmp[1]);

        for (int i = 2; i < _n; i++) {
            while (size(up) >= 2 && cross(up[size(up) - 1].first
                   - up[size(up) - 2].first, tmp[i].first - up[size(up) - 1].first) >= 0) {
                up.pop_back();
            }
            while (size(dw) >= 2 && cross(dw[size(dw) - 1].first
                   - dw[size(dw) - 2].first, tmp[i].first - dw[size(dw) - 1].first) <= 0) {
                dw.pop_back();
            }
            up.push_back(tmp[i]); 
            dw.push_back(tmp[i]);
        }
        hull.reserve(size(up) + size(dw) - 2);
        idx.resize(_n, -1);
        for (int i = 0; i < (int)size(up); i++) {
            hull.emplace_back(up[i].first);
            idx[up[i].second] = i;
        }
        for (int i = size(dw) - 2; i > 0; i--) {
            hull.emplace_back(dw[i].first);
            idx[dw[i].second] = size(hull) - 1;
        }
    }
};

} // namespace kk2

#endif // GEOMETRY_CONVEX_HULL_HPP
