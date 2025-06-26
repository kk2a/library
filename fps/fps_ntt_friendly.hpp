#ifndef KK2_FPS_FPS_NTT_FRIENDLY_HPP
#define KK2_FPS_FPS_NTT_FRIENDLY_HPP 1

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

#include "../convolution/convolution.hpp"
#include "fps_base.hpp"

namespace kk2 {

template <class mint> struct FormalPowerSeriesNTTFriendly
    : FormalPowerSeriesBase<FormalPowerSeriesNTTFriendly<mint>, mint> {
    using base = FormalPowerSeriesBase<FormalPowerSeriesNTTFriendly<mint>, mint>;
    using FPS = FormalPowerSeriesNTTFriendly<mint>;
    using base::FormalPowerSeriesBase;
    static constexpr bool is_ntt_friendly = true;

    // CRTPを使った実装 - overrideは不要
    FPS &operator*=(const FPS &r) {
        convolution(*this, r);
        return *this;
    }
    void but() { butterfly(*this); }
    void ibut() { butterfly_inv(*this); }
    void db() { doubling(*this); }

    FPS dense_inv(int deg = -1) const {
        if (deg == -1) deg = (int)this->size();
        FPS res(deg);
        res[0] = {mint(1) / (*this)[0]};
        for (int d = 1; d < deg; d <<= 1) {
            FPS f(2 * d), g(2 * d);
            std::copy(std::begin(*this),
                      std::begin(*this) + std::min((int)this->size(), 2 * d),
                      std::begin(f));
            std::copy(std::begin(res), std::begin(res) + d, std::begin(g));
            f.but();
            g.but();
            f.inplace_dot(g);
            f.ibut();
            std::fill(std::begin(f), std::begin(f) + d, mint(0));
            f.but();
            f.inplace_dot(g);
            f.ibut();
            for (int j = d; j < std::min(2 * d, deg); j++) res[j] = -f[j];
        }
        return res.pre(deg);
    }

    FPS dense_exp(int deg = -1) const {
        if (deg == -1) deg = (int)this->size();

        FPS b{1, 1 < (int)this->size() ? (*this)[1] : mint(0)};
        FPS c{1}, z1, z2{1, 1};
        for (int m = 2; m < deg; m <<= 1) {
            auto y = b;
            y.resize(m << 1);
            y.but();
            z1 = z2;
            FPS z(m);
            z = y.dot(z1);
            z.ibut();
            std::fill(std::begin(z), std::begin(z) + (m >> 1), mint(0));
            z.but();
            z.inplace_dot(-z1);
            z.ibut();
            c.insert(std::end(c), std::begin(z) + (m >> 1), std::end(z));
            z2 = c;
            z2.resize(m << 1);
            z2.but();

            FPS x(this->begin(), this->begin() + std::min<int>(this->size(), m));
            x.resize(m);
            x.inplace_diff();
            x.push_back(mint(0));
            x.but();
            x.inplace_dot(y);
            x.ibut();
            x -= b.diff();
            x.resize(m << 1);
            for (int i = 0; i < m - 1; i++) {
                x[m + i] = x[i];
                x[i] = mint(0);
            }
            x.but();
            x.inplace_dot(z2);
            x.ibut();
            x.pop_back();
            x.inplace_int();
            for (int i = m; i < std::min<int>(this->size(), m << 1); i++) x[i] += (*this)[i];
            std::fill(std::begin(x), std::begin(x) + m, mint(0));
            x.but();
            x.inplace_dot(y);
            x.ibut();
            b.insert(std::end(b), std::begin(x) + m, std::end(x));
        }
        return FPS(std::begin(b), std::begin(b) + deg);
    }
};

template <class mint> using FPSNTT = FormalPowerSeriesNTTFriendly<mint>;

} // namespace kk2

#endif // KK2_FPS_FPS_NTT_FRIENDLY_HPP
