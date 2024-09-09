#ifndef POLY_GCD_HPP
#define POLY_GCD_HPP 1

#include <algorithm>
#include <array>
#include <utility>

namespace kk2 {

namespace poly_gcd {

template <class FPS> using Vec = std::array<FPS, 2>;

template <class FPS> struct mat_poly {
    FPS a00, a01, a10, a11;

    mat_poly() = default;

    mat_poly(FPS a00_, FPS a01_, FPS a10_, FPS a11_)
        : a00(a00_),
          a01(a01_),
          a10(a10_),
          a11(a11_) {}

    mat_poly &operator*=(const mat_poly &r) {
        FPS A00 = a00 * r.a00 + a01 * r.a10;
        FPS A01 = a00 * r.a01 + a01 * r.a11;
        FPS A10 = a10 * r.a00 + a11 * r.a10;
        FPS A11 = a10 * r.a01 + a11 * r.a11;
        A00.shrink();
        A01.shrink();
        A10.shrink();
        A11.shrink();
        std::swap(a00, A00);
        std::swap(a01, A01);
        std::swap(a10, A10);
        std::swap(a11, A11);
        return *this;
    }

    static mat_poly identity() {
        return mat_poly(FPS{1}, FPS(), FPS(), FPS{1});
    }

    mat_poly operator*(const mat_poly &r) const { return mat_poly(*this) *= r; }
};

template <class FPS>
Vec<FPS> operator*(const mat_poly<FPS> &a, const Vec<FPS> &b) {
    FPS x0 = a.a00 * b[0] + a.a01 * b[1];
    FPS x1 = a.a10 * b[0] + a.a11 * b[1];
    x0.shrink();
    x1.shrink();
    return {x0, x1};
};

template <class FPS> void InnerNaiveGcd(mat_poly<FPS> &a, Vec<FPS> &b) {
    FPS quo = b[0] / b[1];
    FPS rem = b[0] - quo * b[1];
    FPS x10 = a.a00 - quo * a.a10;
    FPS x11 = a.a01 - quo * a.a11;
    rem.shrink();
    x10.shrink();
    x11.shrink();
    std::swap(x10, a.a10);
    std::swap(x11, a.a11);
    std::swap(x10, a.a00);
    std::swap(x11, a.a01);
    b = {b[1], rem};
}

template <class FPS> mat_poly<FPS> InnerHalfGcd(Vec<FPS> b) {
    int n = (int)b[0].size(), m = (int)b[1].size();
    int k = (n + 1) >> 1;
    if (m <= k) return mat_poly<FPS>::identity();
    mat_poly<FPS> m1 = InnerHalfGcd(Vec<FPS>{b[0] >> k, b[1] >> k});
    b = m1 * b;
    if ((int)b[1].size() <= k) return m1;
    InnerNaiveGcd(m1, b);
    if ((int)b[1].size() <= k) return m1;
    int l = (int)b[0].size() - 1;
    int j = 2 * k - l;
    b[0] = b[0] >> j;
    b[1] = b[1] >> j;
    return InnerHalfGcd(b) * m1;
}

template <class FPS> mat_poly<FPS> InnerPolyGcd(const FPS &a, const FPS &b) {
    Vec<FPS> c{a, b};
    c[0].shrink();
    c[1].shrink();
    int n = (int)c[0].size(), m = (int)c[1].size();
    if (n < m) {
        mat_poly<FPS> ret = InnerPolyGcd(c[1], c[0]);
        std::swap(ret.a00, ret.a01);
        std::swap(ret.a10, ret.a11);
        return ret;
    }

    mat_poly<FPS> res = mat_poly<FPS>::identity();
    while (1) {
        mat_poly<FPS> m1 = InnerHalfGcd(c);
        c = m1 * c;
        if (c[1].empty()) return m1 * res;
        InnerNaiveGcd(m1, c);
        if (c[1].empty()) return m1 * res;
        res = m1 * res;
    }
}

template <class FPS> FPS PolyGcd(FPS a, FPS b) {
    Vec<FPS> c{a, b};
    mat_poly<FPS> m = InnerPolyGcd(a, b);
    c = m * c;
    if (!c[0].empty()) {
        auto coeff = c[0].back().inv();
        for (auto &x : c[0]) x *= coeff;
    }
    return c[0];
}

// f ^ {-1} mod g
template <class FPS> std::pair<bool, FPS> PolyInv(const FPS &f, const FPS &g) {
    Vec<FPS> c{f, g};
    mat_poly<FPS> m = InnerPolyGcd(f, g);
    FPS gcd_ = (m * c)[0];
    if (gcd_.size() != 1) return {0, FPS()};
    Vec<FPS> x{FPS{1}, g};
    return {1, ((m * x)[0] % g) * gcd_[0].inv()};
}

} // namespace poly_gcd

using poly_gcd::PolyGcd;
using poly_gcd::PolyInv;

} // namespace kk2

#endif // poly_gcd.hpp
