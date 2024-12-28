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
    std::vector<point> up, dw;
    std::vector<int> idx_hull, idx_up, idx_dw;

    StaticConvexHull() = default;

    StaticConvexHull(const std::vector<point> &ps) : ps(ps) {}

    void add_point(T x, T y) { ps.emplace_back(x, y); }

    void add_point(const point &p) { ps.push_back(p); }

    void build() {
        int _n = size(ps);
        if (_n == 0) return;

        idx_hull.resize(_n, -1);
        idx_up.resize(_n, -1);
        idx_dw.resize(_n, -1);

        std::vector<std::pair<point, int>> tmp(_n);
        for (int i = 0; i < _n; i++) tmp[i] = {ps[i], i};
        std::sort(tmp.begin(), tmp.end());
        std::vector<bool> same(_n);
        for (int i = 1; i < _n; i++) same[i] = tmp[i - 1].first == tmp[i].first;
        std::vector<std::pair<point, int>> up_, dw_;

        for (int i = 0; i < _n; i++) {
            if (same[i]) continue;
            // 傾きが減少
            while (size(up_) >= 2
                   && cross(up_[size(up_) - 1].first - up_[size(up_) - 2].first,
                            tmp[i].first - up_[size(up_) - 1].first)
                          >= 0) {
                up_.pop_back();
            }

            // 傾きが増加
            while (size(dw_) >= 2
                   && cross(dw_[size(dw_) - 1].first - dw_[size(dw_) - 2].first,
                            tmp[i].first - dw_[size(dw_) - 1].first)
                          <= 0) {
                dw_.pop_back();
            }
            up_.emplace_back(tmp[i]);
            dw_.emplace_back(tmp[i]);
        }

        if (int(size(up_)) == 1) {
            hull = up = dw = {up_[0].first};
            idx_hull[up_[0].second] = idx_up[up_[0].second] = idx_dw[up_[0].second] = 0;
            return;
        }

        hull.resize(size(up_) + size(dw_) - 2);
        up.resize(size(up_));
        dw.resize(size(dw_));

        for (int i = 0; i < (int)size(dw_); i++) {
            hull[i] = dw[i] = dw_[i].first;
            idx_hull[dw_[i].second] = idx_dw[dw_[i].second] = i;
        }
        up.back() = up_.back().first;
        idx_up[up_.back().second] = up_.size() - 1;
        up[0] = up_[0].first;
        idx_up[up_[0].second] = 0;
        for (int i = size(up_) - 2; i; i--) {
            hull[size(up_) + size(dw_) - 2 - i] = up[i] = up_[i].first;
            idx_hull[up_[i].second] = size(up_) + size(dw_) - 2 - i;
            idx_up[up_[i].second] = i;
        }
    }
};

} // namespace kk2

#endif // GEOMETRY_CONVEX_HULL_HPP
