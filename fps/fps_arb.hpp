#ifndef FPS_ARB_HPP
#define FPS_ARB_HPP 1

#include "../convolution/convo_arb.hpp"
#include "fps.hpp"

namespace kk2 {

template <class mint> void FormalPowerSeries<mint>::but() {
    exit(1);
}

template <class mint> void FormalPowerSeries<mint>::ibut() {
    exit(1);
}

template <class mint> void FormalPowerSeries<mint>::db() {
    exit(1);
}

template <class mint> int FormalPowerSeries<mint>::but_pr() {
    return 0;
}

template <class mint>
FormalPowerSeries<mint> &
FormalPowerSeries<mint>::operator*=(const FormalPowerSeries<mint> &r) {
    if (this->empty() || r.empty()) {
        this->clear();
        return *this;
    }
    convolution_arb(*this, r, mint::getmod());
    return *this;
}

template <class mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::inv(int deg) const {
    assert((*this)[0] != mint(0));
    if (deg == -1) deg = this->size();
    FormalPowerSeries<mint> res{(*this)[0].inv()};
    for (int i = 1; i < deg; i <<= 1) {
        res = (res * mint(2) - this->pre(i << 1) * res * res).pre(i << 1);
    }
    return res.pre(deg);
}

template <class mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::exp(int deg) const {
    assert(this->empty() || (*this)[0] == mint(0));
    if (deg == -1) deg = this->size();
    FormalPowerSeries<mint> ret{mint(1)};
    for (int i = 1; i < deg; i <<= 1) {
        ret = (ret * (pre(i << 1) + mint{1} - ret.log(i << 1))).pre(i << 1);
    }
    return ret.pre(deg);
}

} // namespace kk2

#endif // FPS_ARB_HPP
