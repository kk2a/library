#ifndef KK2_DATA_STRUCTURE_PREFIX_SUM_2D_HPP
#define KK2_DATA_STRUCTURE_PREFIX_SUM_2D_HPP 1

#include <cassert>
#include <vector>

namespace kk2 {

template <class T> struct PrefixSum2D {
    std::vector<std::vector<T>> acc;
    int h, w;

    constexpr PrefixSum2D() = default;

    constexpr PrefixSum2D(int h_, int w_) : acc(h_ + 1, std::vector<T>(w_ + 1)), h(h_), w(w_) {}

    constexpr PrefixSum2D(const std::vector<std::vector<T>> &a)
        : acc(a.size() + 1, std::vector<T>(a[0].size() + 1)),
          h((int)a.size()),
          w((int)a[0].size()) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                acc[i + 1][j + 1] = a[i][j];
            }
        build();
    }

    constexpr void build() {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                acc[i + 1][j + 1] += acc[i][j + 1] + acc[i + 1][j] - acc[i][j];
            }
        }
    }

    constexpr void init_set(int i, int j, T x) {
        assert(0 <= i && i < h);
        assert(0 <= j && j < w);
        acc[i + 1][j + 1] = x;
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

#endif // KK2_DATA_STRUCTURE_PREFIX_SUM_2D_HPP
