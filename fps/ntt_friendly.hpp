#ifndef FPS_NTT_FRIENDLY_HPP
#define FPS_NTT_FRIENDLY_HPP 1

#include "../convolution/butterfly.hpp"
#include "../convolution/convolution.hpp"
#include "fps.hpp"


template <class mint>
FormalPowerSeries<mint> &FormalPowerSeries<mint>::operator*=(
        const FormalPowerSeries<mint> &r) {
    if (this->empty() || r.empty()) {
        this->clear();
        return *this;
    }
    convolution(*this, r);
    return *this;
}

template <class mint> 
void FormalPowerSeries<mint>::but() {
    butterfly(*this);
}

template <class mint>
void FormalPowerSeries<mint>::ibut() {
    butterfly_inv(*this);
}

template <class mint>
void FormalPowerSeries<mint>::db() {
    doubling(*this);
}

template <class mint>
int FormalPowerSeries<mint>::but_pr() {
    return primitive_root<mint::getmod()>;
}

template <class mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::inv(int deg) const {
    assert((*this)[0] != mint(0));
    if (deg == -1) deg = (int)this->size();
    FormalPowerSeries<mint> res(deg);
    res[0] = {mint(1) / (*this)[0]};
    auto ind = mint{2}.inv(), intwo = mint{2}.inv();
    for (int d = 1; d < deg; d <<= 1) {
        FormalPowerSeries<mint> f(2 * d), g(2 * d);
        copy(begin(*this), begin(*this) + min((int)this->size(), 2 * d), begin(f));
        copy(begin(res), begin(res) + d, begin(g));
        f.but(); g.but();
        f.inplace_dot(g);
        f.ibut(); f *= ind;
        fill(begin(f), begin(f) + d, mint(0));
        f.but();
        f.inplace_dot(g);
        f.ibut(); f *= ind;
        for (int j = d; j < min(2 * d, deg); j++) res[j] = -f[j];
        ind *= intwo;
    }
    return res.pre(deg);
}

template <class mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::exp(int deg) const {
    assert(this->empty() || (*this)[0] == mint(0));
    if (deg == -1) deg = (int)this->size();
    FormalPowerSeries<mint> inv;
    inv.reserve(deg + 1);
    inv.push_back(mint(0));
    inv.push_back(mint(1));

    FormalPowerSeries<mint> b{1, 1 < (int)this->size() ?
                              (*this)[1] : mint(0)};
    FormalPowerSeries<mint> c{1}, z1, z2{1, 1};
    mint im = mint{2}.inv(), intwo = mint{2}.inv();
    for (int m = 2; m < deg; m <<= 1) {
        auto y = b;
        y.resize(m << 1);
        y.but();
        z1 = z2;
        FormalPowerSeries<mint> z(m);
        z = y.dot(z1);
        z.ibut(); z *= im;
        fill(begin(z), begin(z) + (m >> 1), mint(0));
        z.but(); z.inplace_dot(-z1);
        z.ibut(); z *= im;
        c.insert(end(c), begin(z) + (m >> 1), end(z));
        z2 = c;
        z2.resize(m << 1);
        z2.but();

        FormalPowerSeries<mint> x(begin(*this), begin(*this) +
                                  min<int>(this->size(), m));
        x.resize(m);
        x.inplace_diff();
        x.push_back(mint(0));
        x.but();
        x.inplace_dot(y);
        x.ibut(); x *= im;
        x -= b.diff();
        x.resize(m << 1);
        for (int i = 0; i < m - 1; i++) {
            x[m + i] = x[i];
            x[i] = mint(0);
        }
        x.but();
        x.inplace_dot(z2);
        x.ibut(); x *= im * intwo;
        x.pop_back();
        x.inplace_int();
        for (int i = m; i < min<int>(this->size(),m << 1); i++)
            x[i] += (*this)[i];
        fill(begin(x), begin(x) + m, mint(0));
        x.but();
        x.inplace_dot(y);
        x.ibut(); x *= im * intwo;
        b.insert(end(b), begin(x) + m, end(x));
        im *= intwo;
    }
    return FormalPowerSeries<mint>(begin(b), begin(b) + deg);
}


#endif // FPS_NTT_FRIENDLY_HPP
