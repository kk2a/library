#ifndef DATA_STRUCTURE_PREFIX_SUM_2D_HPP
#define DATA_STRUCTURE_PREFIX_SUM_2D_HPP 1

#include <cassert>
#include <vector>

namespace kk2 {

template <class T> struct Prefix2D {
    std::vector<std::vector<T>> acc;
    int h, w;

    constexpr Prefix2D() = default;

    constexpr Prefix2D(const std::vector<std::vector<T>> &a)
        : acc(a.size() + 1, std::vector<T>(a[0].size() + 1)),
          h((int)a.size()),
          w((int)a[0].size()) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                acc[i + 1][j + 1] = acc[i + 1][j] + acc[i][j + 1] - acc[i][j] + a[i][j];
            }
        }
    }

    constexpr T sum(int li, int lj, int ri, int rj) const {
        assert(0 <= li && li <= ri && ri <= h);
        assert(0 <= lj && lj <= rj && rj <= w);
        return acc[ri][rj] - acc[li][rj] - acc[ri][lj] + acc[li][lj];
    }

    constexpr T get(int i, int j) const {
        assert(0 <= i && i < h);
        assert(0 <= j && j < w);
        return acc[i + 1][j + 1] - acc[i][j + 1] - acc[i + 1][j] + acc[i][j];
    }

    constexpr T operator()(int li, int lj, int ri, int rj) const {
        assert(0 <= li && li <= ri && ri <= h);
        assert(0 <= lj && lj <= rj && rj <= w);
        return acc[ri][rj] - acc[li][rj] - acc[ri][lj] + acc[li][lj];
    }

    constexpr T operator()(int i, int j) const {
        assert(0 <= i && i < h);
        assert(0 <= j && j < w);
        return acc[i + 1][j + 1] - acc[i][j + 1] - acc[i + 1][j] + acc[i][j];
    }
};

} // namespace kk2

#endif // DATA_STRUCTURE_PREFIX_SUM_2D_HPP
