#ifndef FPS_NTT_FRIENDLY_HPP
#define FPS_NTT_FRIENDLY_HPP 1

#ifdef KK2
#include <kk2/convolution/butterfly.hpp>
#include <kk2/convolution/convolution.hpp>
#include <kk2/fps/fps.hpp>
#endif


template <class mint>
FormalPowerSeries<mint> &FormalPowerSeries<mint>::operator*=(
        const FormalPowerSeries<mint> &r) {
    if (this->empty() || r.empty()) {
        this->clear();
        return *this;
    }
    convolution<mint>(*this, r);
    return *this;
}

template <class mint> 
void FormalPowerSeries<mint>::but() {
    butterfly<mint>(*this);
}

template <class mint>
void FormalPowerSeries<mint>::ibut() {
    butterfly_inv<mint>(*this);
}

template <class mint>
void FormalPowerSeries<mint>::db() {
    doubling<mint>(*this);
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
        for (int j = 0; j < min(deg, 2 * d); j++)
            f[j] = (*this)[j];
        for (int j = 0; j < d; j++) g[j] = res[j];
        f.but();
        g.but();
        for (int j = 0; j < 2 * d; j++) f[j] *= g[j];
        f.ibut();
        for (int j = 0; j < 2 * d; j++) f[j] *= ind;
        for (int j = 0; j < d; j++) f[j] = 0;
        f.but();
        for (int j = 0; j < 2 * d; j++) f[j] *= g[j];
        f.ibut();
        for (int j = 0; j < 2 * d; j++) f[j] *= ind;
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

    FormalPowerSeries<mint> b{1, 1 < (int)this->size() ? (*this)[1] : mint(0)};
    FormalPowerSeries<mint> c{1}, z1, z2{1, 1};
    mint im = mint{2}.inv(), intwo = mint{2}.inv();
    for (int m = 2; m < deg; m <<= 1) {
        auto y = b;
        y.resize(m << 1);
        y.but();
        z1 = z2;
        FormalPowerSeries<mint> z(m);
        for (int i = 0; i < m; i++) z[i] = y[i] * z1[i];
        z.ibut();
        for (int i = 0; i < m; i++) z[i] *= im;
        fill(begin(z), begin(z) + (m >> 1), mint(0));
        z.but();
        for (int i = 0; i < m; i++) z[i] *= -z1[i];
        z.ibut();
        for (int i = 0; i < m; i++) z[i] *= im;
        c.insert(end(c), begin(z) + (m >> 1), end(z));
        z2 = c;
        z2.resize(m << 1);
        z2.but();

        FormalPowerSeries<mint> x(begin(*this), begin(*this) + min<int>(this->size(), m));
        x.resize(m);
        x.inplace_diff();
        x.push_back(mint(0));
        x.but();
        for (int i = 0; i < m; i++) x[i] *= y[i];
        x.ibut();
        for (int i = 0; i < m; i++) x[i] *= im;
        x -= b.diff();
        x.resize(m << 1);
        for (int i = 0; i < m - 1; i++) {
            x[m + i] = x[i];
            x[i] = mint(0);
        }
        x.but();
        for (int i = 0; i < 2 * m; i++) x[i] *= z2[i];
        x.ibut();
        for (int i = 0; i < 2 * m; i++) x[i] *= im * intwo;
        x.pop_back();
        x.inplace_int();
        for (int i = m; i < min<int>(this->size(), m << 1); i++) x[i] += (*this)[i];
        fill(begin(x), begin(x) + m, mint(0));
        x.but();
        for (int i = 0; i < 2 * m; i++) x[i] *= y[i];
        x.ibut();
        for (int i = 0; i < 2 * m; i++) x[i] *= im * intwo;
        b.insert(end(b), begin(x) + m, end(x));
        im *= intwo;
    }
    return FormalPowerSeries<mint>(begin(b), begin(b) + deg);
}


#endif // FPS_NTT_FRIENDLY_HPP
