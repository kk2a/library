#ifndef KK2_FPS_FPS_NTT_FRIENDLY_HPP
#define KK2_FPS_FPS_NTT_FRIENDLY_HPP 1

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

#include "../convolution/convolution.hpp"
#include "../type_traits/io.hpp"

namespace kk2 {

template <class mint>
struct FormalPowerSeriesNTTFriendly : std::vector<mint> {
    using std::vector<mint>::vector;
    using FPS = FormalPowerSeriesNTTFriendly;

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    void debug_output(OStream &os) const {
        os << "[";
        for (int i = 0; i < (int)this->size(); i++) {
            os << (*this)[i] << (i + 1 == (int)this->size() ? "" : ", ");
        }
        os << "]";
    }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    void output(OStream &os) const {
        for (int i = 0; i < (int)this->size(); i++) {
            os << (*this)[i] << (i + 1 == (int)this->size() ? "\n" : " ");
        }
    }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const FPS &fps_) {
        for (int i = 0; i < (int)fps_.size(); i++) {
            os << fps_[i] << (i + 1 == (int)fps_.size() ? "" : " ");
        }
        return os;
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    FPS &input(IStream &is) {
        for (int i = 0; i < (int)this->size(); i++) is >> (*this)[i];
        return *this;
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend IStream &operator>>(IStream &is, FPS &fps_) {
        for (auto &x : fps_) is >> x;
        return is;
    }

    FPS &operator+=(const FPS &r) {
        if (this->size() < r.size()) this->resize(r.size());
        for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];
        return *this;
    }

    FPS &operator+=(const mint &r) {
        if (this->empty()) this->resize(1);
        (*this)[0] += r;
        return *this;
    }

    FPS &operator-=(const FPS &r) {
        if (this->size() < r.size()) this->resize(r.size());
        for (int i = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];
        return *this;
    }

    FPS &operator-=(const mint &r) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= r;
        return *this;
    }

    FPS &operator*=(const mint &r) {
        for (int i = 0; i < (int)this->size(); i++) { (*this)[i] *= r; }
        return *this;
    }

    FPS &operator/=(const FPS &r) {
        assert(!r.empty());
        if (this->size() < r.size()) {
            this->clear();
            return *this;
        }
        int n = this->size() - r.size() + 1;
        if ((int)r.size() <= 64) {
            FPS f(*this), g(r);
            g.shrink();
            mint coeff = g.back().inv();
            for (auto &x : g) x *= coeff;
            int deg = (int)f.size() - (int)g.size() + 1;
            int gs = g.size();
            FPS quo(deg);
            for (int i = deg - 1; i >= 0; i--) {
                quo[i] = f[i + gs - 1];
                for (int j = 0; j < gs; j++) f[i + j] -= quo[i] * g[j];
            }
            *this = quo * coeff;
            this->resize(n, mint(0));
            return *this;
        }
        return *this = ((*this).rev().pre(n) * r.rev().inv(n)).pre(n).rev();
    }

    FPS &operator%=(const FPS &r) {
        *this -= *this / r * r;
        shrink();
        return *this;
    }

    FPS operator+(const FPS &r) const { return FPS(*this) += r; }

    FPS operator+(const mint &r) const { return FPS(*this) += r; }

    FPS operator-(const FPS &r) const { return FPS(*this) -= r; }

    FPS operator-(const mint &r) const { return FPS(*this) -= r; }

    FPS operator*(const mint &r) const { return FPS(*this) *= r; }

    FPS operator/(const FPS &r) const { return FPS(*this) /= r; }

    FPS operator%(const FPS &r) const { return FPS(*this) %= r; }

    FPS operator-() const {
        FPS ret(this->size());
        for (int i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];
        return ret;
    }

    FPS &shrink() {
        while (this->size() && this->back() == mint(0)) this->pop_back();
        return *this;
    }

    FPS rev() const {
        FPS ret(*this);
        std::reverse(ret.begin(), ret.end());
        return ret;
    }

    FPS &inplace_rev() {
        std::reverse(this->begin(), this->end());
        return *this;
    }

    FPS dot(const FPS &r) const {
        FPS ret(std::min(this->size(), r.size()));
        for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];
        return ret;
    }

    FPS &inplace_dot(const FPS &r) {
        this->resize(std::min(this->size(), r.size()));
        for (int i = 0; i < (int)this->size(); i++) (*this)[i] *= r[i];
        return *this;
    }

    FPS pre(int n) const {
        FPS ret(this->begin(), this->begin() + std::min((int)this->size(), n));
        if ((int)ret.size() < n) ret.resize(n, mint(0));
        return ret;
    }

    FPS &inplace_pre(int n) {
        this->resize(n);
        return *this;
    }

    FPS operator>>(int n) const {
        if (n >= (int)this->size()) return {};
        FPS ret(this->begin() + n, this->end());
        return ret;
    }

    FPS operator<<(int n) const {
        FPS ret(*this);
        ret.insert(ret.begin(), n, mint(0));
        return ret;
    }

    FPS diff() const {
        const int n = (int)this->size();
        FPS ret(std::max(0, n - 1));
        for (int i = 1; i < n; i++) { ret[i - 1] = (*this)[i] * mint(i); }
        return ret;
    }

    FPS &inplace_diff() {
        if (this->empty()) return *this = FPS();
        this->erase(this->begin());
        for (int i = 1; i <= (int)this->size(); i++) (*this)[i - 1] *= mint(i);
        return *this;
    }

    FPS integral() const {
        const int n = (int)this->size();
        FPS ret(n + 1);
        ret[0] = mint(0);
        if (n > 0) ret[1] = mint(1);
        auto mod = mint::getmod();
        for (int i = 2; i <= n; i++) {
            // p = q * i + r
            // - q / r = 1 / i (mod p)
            ret[i] = (-ret[mod % i]) * (mod / i);
        }
        for (int i = 0; i < n; i++) { ret[i + 1] *= (*this)[i]; }
        return ret;
    }

    FPS &inplace_int() {
        static std::vector<mint> inv{0, 1};
        const int n = this->size();
        auto mod = mint::getmod();
        while ((int)inv.size() <= n) {
            // p = q * i + r
            // - q / r = 1 / i (mod p)
            int i = inv.size();
            inv.push_back((-inv[mod % i]) * (mod / i));
        }
        this->insert(this->begin(), mint(0));
        for (int i = 1; i <= n; i++) (*this)[i] *= inv[i];
        return *this;
    }

    mint eval(mint x) const {
        mint r = 0, w = 1;
        for (auto &v : *this) {
            r += w * v;
            w *= x;
        }
        return r;
    }

    FPS log(int deg = -1) const {
        assert(!this->empty() && (*this)[0] == mint(1));
        if (deg == -1) deg = this->size();
        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
    }

    FPS sparse_log(int deg = -1) const {
        assert(!this->empty() && (*this)[0] == mint(1));
        if (deg == -1) deg = this->size();
        std::vector<std::pair<int, mint>> fs;
        for (int i = 1; i < int(this->size()); i++) {
            if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i]);
        }

        int mod = mint::getmod();
        static std::vector<mint> inv{1, 1};
        while ((int)inv.size() <= deg) {
            int i = inv.size();
            inv.push_back(-inv[mod % i] * (mod / i));
        }

        FPS g(deg);
        for (int k = 0; k < deg - 1; k++) {
            for (auto &[j, fj] : fs) {
                if (k < j) break;
                int i = k - j;
                g[k + 1] -= g[i + 1] * fj * (i + 1);
            }
            g[k + 1] *= inv[k + 1];
            if (k + 1 < int(this->size())) g[k + 1] += (*this)[k + 1];
        }

        return g;
    }

    template <class T>
    FPS pow(T k, int deg = -1) const {
        const int n = this->size();
        if (deg == -1) deg = n;
        if (k == 0) {
            FPS ret(deg);
            if (deg > 0) ret[0] = mint(1);
            return ret;
        }
        for (int i = 0; i < n; i++) {
            if ((*this)[i] != mint(0)) {
                mint rev = mint(1) / (*this)[i];
                FPS ret = (((*this * rev) >> i).log(deg) * k).exp(deg);
                ret *= (*this)[i].pow(k);
                ret = (ret << (i * k)).pre(deg);
                if ((int)ret.size() < deg) ret.resize(deg, mint(0));
                return ret;
            }
            if (__int128_t(i + 1) * k >= deg) return FPS(deg, mint(0));
        }
        return FPS(deg, mint(0));
    }

    template <class T>
    FPS sparse_pow(T k, int deg = -1) const {
        if (deg == -1) deg = this->size();
        if (k == 0) {
            FPS ret(deg);
            if (deg > 0) ret[0] = mint(1);
            return ret;
        }

        int zero = 0;
        while (zero != int(this->size()) && (*this)[zero] == mint(0)) zero++;
        if (zero == int(this->size()) || __int128_t(zero) * k >= deg) { return FPS(deg, mint(0)); }
        if (zero != 0) {
            FPS suf(this->begin() + zero, this->end());
            auto g = suf.sparse_pow(k, deg - zero * k);
            FPS ret(zero * k, mint(0));
            std::copy(std::begin(g), std::end(g), std::back_inserter(ret));
            return ret;
        }

        int mod = mint::getmod();
        static std::vector<mint> inv{1, 1};
        while ((int)inv.size() <= deg) {
            int i = inv.size();
            inv.push_back(-inv[mod % i] * (mod / i));
        }

        std::vector<std::pair<int, mint>> fs;
        for (int i = 1; i < int(this->size()); i++) {
            if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i]);
        }

        FPS g(deg);
        g[0] = (*this)[0].pow(k);
        mint denom = (*this)[0].inv();
        k %= mod;
        for (int a = 1; a < deg; a++) {
            for (auto &[i, f_i] : fs) {
                if (a < i) break;
                g[a] += g[a - i] * f_i * (mint(i) * (k + 1) - a);
            }
            g[a] *= denom * inv[a];
        }
        return g;
    }

    // assume that r is sparse
    // return this / r
    FPS sparse_div(const FPS &r, int deg = -1) const {
        assert(!r.empty() && r[0] != mint(0));
        if (deg == -1) deg = this->size();
        mint ir0 = r[0].inv();
        FPS ret = *this * ir0;
        ret.resize(deg);
        std::vector<std::pair<int, mint>> gs;
        for (int i = 1; i < (int)r.size(); i++) {
            if (r[i] != mint(0)) gs.emplace_back(i, r[i] * ir0);
        }
        for (int i = 0; i < deg; i++) {
            for (auto &[j, g_j] : gs) {
                if (i + j >= deg) break;
                ret[i + j] -= ret[i] * g_j;
            }
        }
        return ret;
    }

    FPS sparse_inv(int deg = -1) const {
        assert(!this->empty() && (*this)[0] != mint(0));
        if (deg == -1) deg = this->size();
        std::vector<std::pair<int, mint>> fs;
        for (int i = 1; i < int(this->size()); i++) {
            if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i]);
        }
        FPS ret(deg);
        mint if0 = (*this)[0].inv();
        if (0 < deg) ret[0] = if0;
        for (int k = 1; k < deg; k++) {
            for (auto &[j, fj] : fs) {
                if (k < j) break;
                ret[k] += ret[k - j] * fj;
            }
            ret[k] *= -if0;
        }
        return ret;
    }

    FPS sparse_exp(int deg = -1) const {
        assert(this->empty() || (*this)[0] == mint(0));
        if (deg == -1) deg = this->size();
        std::vector<std::pair<int, mint>> fs;
        for (int i = 1; i < int(this->size()); i++) {
            if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i]);
        }

        int mod = mint::getmod();
        static std::vector<mint> inv{1, 1};
        while ((int)inv.size() <= deg) {
            int i = inv.size();
            inv.push_back(-inv[mod % i] * (mod / i));
        }

        FPS g(deg);
        if (deg) g[0] = 1;
        for (int k = 0; k < deg - 1; k++) {
            for (auto &[ip1, fip1] : fs) {
                int i = ip1 - 1;
                if (k < i) break;
                g[k + 1] += g[k - i] * fip1 * (i + 1);
            }
            g[k + 1] *= inv[k + 1];
        }

        return g;
    }

    FPS &inplace_imos(int n) {
        inplace_pre(n);
        for (int i = 0; i < n - 1; i++) { (*this)[i + 1] += (*this)[i]; }
        return *this;
    }

    FPS imos(int n) const {
        FPS ret(*this);
        return ret.inplace_imos(n);
    }

    FPS &inplace_iimos(int n) {
        inplace_pre(n);
        for (int i = 0; i < n - 1; i++) { (*this)[i + 1] -= (*this)[i]; }
        return *this;
    }

    FPS iimos(int n) const {
        FPS ret(*this);
        return ret.inplace_iimos(n);
    }

    FPS &operator*=(const FPS &r);

    FPS operator*(const FPS &r) const { return FPS(*this) *= r; }

    void but();
    void ibut();
    void db();
    static int but_pr();
    FPS inv(int deg = -1) const;
    FPS exp(int deg = -1) const;
};

template <class mint>
FormalPowerSeriesNTTFriendly<mint> &
FormalPowerSeriesNTTFriendly<mint>::operator*=(const FormalPowerSeriesNTTFriendly<mint> &r) {
    if (this->empty() || r.empty()) {
        this->clear();
        return *this;
    }
    convolution(*this, r);
    return *this;
}

template <class mint>
void FormalPowerSeriesNTTFriendly<mint>::but() {
    butterfly(*this);
}

template <class mint>
void FormalPowerSeriesNTTFriendly<mint>::ibut() {
    butterfly_inv(*this);
}

template <class mint>
void FormalPowerSeriesNTTFriendly<mint>::db() {
    doubling(*this);
}

template <class mint>
int FormalPowerSeriesNTTFriendly<mint>::but_pr() {
    return primitive_root<mint::getmod()>;
}

template <class mint>
FormalPowerSeriesNTTFriendly<mint> FormalPowerSeriesNTTFriendly<mint>::inv(int deg) const {
    assert((*this)[0] != mint(0));
    if (deg == -1) deg = (int)this->size();
    FormalPowerSeriesNTTFriendly<mint> res(deg);
    res[0] = {mint(1) / (*this)[0]};
    for (int d = 1; d < deg; d <<= 1) {
        FormalPowerSeriesNTTFriendly<mint> f(2 * d), g(2 * d);
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

template <class mint>
FormalPowerSeriesNTTFriendly<mint> FormalPowerSeriesNTTFriendly<mint>::exp(int deg) const {
    assert(this->empty() || (*this)[0] == mint(0));
    if (deg == -1) deg = (int)this->size();
    FormalPowerSeriesNTTFriendly<mint> inv;
    inv.reserve(deg + 1);
    inv.push_back(mint(0));
    inv.push_back(mint(1));

    FormalPowerSeriesNTTFriendly<mint> b{1, 1 < (int)this->size() ? (*this)[1] : mint(0)};
    FormalPowerSeriesNTTFriendly<mint> c{1}, z1, z2{1, 1};
    for (int m = 2; m < deg; m <<= 1) {
        auto y = b;
        y.resize(m << 1);
        y.but();
        z1 = z2;
        FormalPowerSeriesNTTFriendly<mint> z(m);
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

        FormalPowerSeriesNTTFriendly<mint> x(this->begin(),
                                             this->begin() + std::min<int>(this->size(), m));
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
    return FormalPowerSeriesNTTFriendly<mint>(std::begin(b), std::begin(b) + deg);
}

template <class mint>
using FPSNTT = FormalPowerSeriesNTTFriendly<mint>;

} // namespace kk2

#endif // KK2_FPS_FPS_NTT_FRIENDLY_HPP
