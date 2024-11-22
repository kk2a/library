#ifndef SEGMENT_TREE_SEG_2D_HPP
#define SEGMENT_TREE_SEG_2D_HPP 1

#include <cassert>
#include <vector>

namespace kk2 {

// commutative monoid
template <class S, S (*op)(S, S), S (*e)()> struct SegTree2D {
    SegTree2D() = default;

    SegTree2D(int h_, int w_) : _h(h_), _w(w_) {
        size_h = size_w = 1;
        while (size_h < _h) size_h <<= 1;
        while (size_w < _w) size_w <<= 1;
        d = std::vector<std::vector<S>>(size_h * 2, std::vector<S>(size_w * 2, e()));
    }

    template <class... Args>
    SegTree2D(int h_, int w_, Args... args)
        : SegTree2D(std::vector<std::vector<S>>(h_, std::vector<S>(w_, S(args...)))) {}

    SegTree2D(const std::vector<std::vector<S>> &v) : _h(int(v.size())), _w(int(v[0].size())) {
        size_h = size_w = 1;
        while (size_h < _h) size_h <<= 1;
        while (size_w < _w) size_w <<= 1;
        d = std::vector<std::vector<S>>(size_h * 2, std::vector<S>(size_w * 2, e()));
        for (int i = 0; i < _h; i++) {
            for (int j = 0; j < _w; j++) { d[i + size_h][j + size_w] = v[i][j]; }
        }
        for (int j = size_w; j < size_w * 2; j++) {
            for (int i = size_h - 1; i; i--) updatei(i, j);
        }
        for (int i = 1; i < size_h * 2; i++) {
            for (int j = size_w - 1; j; j--) updatej(i, j);
        }
    }

    void set(int i, int j, const S &x) {
        assert(0 <= i && i < _h);
        assert(0 <= j && j < _w);
        i += size_h;
        j += size_w;
        d[i][j] = x;
        for (int ii = i >> 1; ii; ii >>= 1) updatei(ii, j);
        for (int ii = i; ii; ii >>= 1) {
            for (int jj = j >> 1; jj; jj >>= 1) updatej(ii, jj);
        }
    }

    template <class... Args> void emplace_set(int i, int j, Args... args) { set(i, j, S(args...)); }

    S get(int i, int j) {
        assert(0 <= i && i < _h);
        assert(0 <= j && j < _w);
        return d[i + size_h][j + size_w];
    }

    S prod(int i1, int j1, int i2, int j2) {
        assert(0 <= i1 && i1 <= i2 && i2 <= _h);
        assert(0 <= j1 && j1 <= j2 && j2 <= _w);
        if (i1 == i2 || j1 == j2) return e();
        i1 += size_h;
        i2 += size_h;
        j1 += size_w;
        j2 += size_w;

        S res = e();
        for (; i1 < i2; i1 >>= 1, i2 >>= 1) {
            if (i1 & 1) res = op(res, inner_prod(i1++, j1, j2));
            if (i2 & 1) res = op(inner_prod(--i2, j1, j2), res);
        }
        return res;
    }

  private:
    int _h, _w, size_h, size_w;
    std::vector<std::vector<S>> d;

    void updatei(int i, int j) { d[i][j] = op(d[i * 2][j], d[i * 2 + 1][j]); }

    void updatej(int i, int j) { d[i][j] = op(d[i][j * 2], d[i][j * 2 + 1]); }

    S inner_prod(int i, int j1, int j2) {
        S res = e();
        for (; j1 < j2; j1 >>= 1, j2 >>= 1) {
            if (j1 & 1) res = op(res, d[i][j1++]);
            if (j2 & 1) res = op(d[i][--j2], res);
        }
        return res;
    }
};

} // namespace kk2

#endif // SEGMENT_TREE_SEG_2D_HPP
