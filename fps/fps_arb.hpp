#ifndef KK2_FPS_FPS_ARB_HPP
#define KK2_FPS_FPS_ARB_HPP 1

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

#include "../convolution/convolution_arb.hpp"
#include "fps_base.hpp"

namespace kk2 {

template <class mint> struct FormalPowerSeriesArbitrary
    : FormalPowerSeriesBase<FormalPowerSeriesArbitrary<mint>, mint> {
    using base = FormalPowerSeriesBase<FormalPowerSeriesArbitrary<mint>, mint>;
    using FPS = FormalPowerSeriesArbitrary<mint>;
    using base::FormalPowerSeriesBase;
    using base::operator*=; // 基底クラスのoperator*=を継承
    static constexpr bool is_ntt_friendly = false;

    // CRTPを使った実装 - overrideは不要
    FPS &operator*=(const FPS &r) {
        convolution_arb(*this, r);
        return *this;
    }
    void but() { exit(1); }
    void ibut() { exit(1); }
    void db() { exit(1); }
    static int but_pr() {
        exit(1);
        return 0;
    }

    FPS dense_inv(int deg = -1) const {
        if (deg == -1) deg = this->size();
        FPS res{(*this)[0].inv()};
        for (int i = 1; i < deg; i <<= 1) {
            res = (res + res - this->pre(i << 1) * (res * res)).pre(i << 1);
        }
        return res.pre(deg);
    }

    FPS dense_exp(int deg = -1) const {
        if (deg == -1) deg = this->size();
        FPS ret{mint(1)};
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret * (this->pre(i << 1) + mint{1} - ret.log(i << 1))).pre(i << 1);
        }
        return ret.pre(deg);
    }
};

template <class mint> using FPSArb = FormalPowerSeriesArbitrary<mint>;

} // namespace kk2

#endif // KK2_FPS_FPS_ARB_HPP
