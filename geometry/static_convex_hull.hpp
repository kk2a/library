#ifndef GEOMETRY_CONVEX_HULL_HPP
#define GEOMETRY_CONVEX_HULL_HPP 1

#include <algorithm>
#include <utility>
#include <vector>

#include "point.hpp"

namespace kk2 {

template <typename T> struct StaticConvexHull {
    using point = Point<T>;
    std::vector<point> ps, hull;
    // 各頂点に対して，hullのindexを格納
    // -1なら凸包に含まれない
    std::vector<int> idx;

    StaticConvexHull() = default;

    StaticConvexHull(const std::vector<point> &ps) : ps(ps) {}

    void add_point(T x, T y) { ps.emplace_back(x, y); }

    void add_point(const point &p) { ps.push_back(p); }

    void build() {
        int _n = size(ps);
        if (_n == 0) return;
        if (_n == 1) {
            hull = ps;
            idx = {0};
            return;
        }

        idx.resize(_n, -1);
        std::vector<std::pair<point, int>> tmp(_n);
        for (int i = 0; i < _n; i++) tmp[i] = {ps[i], i};
        std::sort(tmp.begin(), tmp.end());
        std::vector<bool> same(_n);
        for (int i = 1; i < _n; i++) same[i] = tmp[i - 1].first == tmp[i].first;
        std::vector<std::pair<point, int>> up, dw;

        for (int i = 0; i < _n; i++) {
            if (same[i]) continue;
            // 傾きが減少
            while (size(up) >= 2
                   && cross(up[size(up) - 2].first - up[size(up) - 1].first,
                            up[size(up) - 1].first - tmp[i].first)
                          >= 0) {
                up.pop_back();
            }

            // 傾きが増加
            while (size(dw) >= 2
                   && cross(dw[size(dw) - 2].first - dw[size(dw) - 1].first,
                            dw[size(dw) - 1].first - tmp[i].first)
                          <= 0) {
                dw.pop_back();
            }
            up.emplace_back(tmp[i]);
            dw.emplace_back(tmp[i]);
        }

        if (int(size(up)) == 1) {
            hull = {up[0].first};
            idx[up[0].second] = 0;
            return;
        }

        hull.resize(size(up) + size(dw) - 2);

        for (int i = 0; i < (int)size(dw); i++) {
            hull[i] = dw[i].first;
            idx[dw[i].second] = i;
        }
        for (int i = size(up) - 2; i > 0; i--) {
            hull[size(up) + size(dw) - 2 - i] = up[i].first;
            idx[up[i].second] = size(up) + size(dw) - 2 - i;
        }
    }
};

} // namespace kk2

#endif // GEOMETRY_CONVEX_HULL_HPP
