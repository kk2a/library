#ifndef FPS_HPP
#define FPS_HPP 1


template <class mint>
struct FormalPowerSeries : vector<mint> {
    using vector<mint>::vector;
    using FPS = FormalPowerSeries;

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
        for (int i = 0; i < (int)this->size(); i++) {
            (*this)[i] *= r;
        }
        return *this;
    }
    FPS &operator/=(const FPS &r) {
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

    void shrink() {
        while (this->size() && this->back() == mint(0)) this->pop_back();
    }

    FPS rev() const {
        FPS ret(*this);
        reverse(ret.begin(), ret.end());
        return ret;
    }
    FPS dot(FPS r) const {
        FPS ret(min(this->size(), r.size()));
        for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];
        return ret;
    }

    FPS pre(int n) const {
        FPS ret(begin(*this), begin(*this) + min((int)this->size(), n));
        if ((int)ret.size() < n) ret.resize(n, mint(0));
        return ret;
    }

    FPS operator>>(int n) const {
        if (n >= (int)this->size()) return {};
        FPS ret(begin(*this) + n, end(*this));
        return ret;
    }
    FPS operator<<(int n) const {
        FPS ret(*this);
        ret.insert(begin(ret), n, mint(0));
        return ret;
    }

    FPS diff() const {
        const int n = (int)this->size();
        FPS ret(max(0, n - 1));
        for (int i = 1; i < n; i++) {
            ret[i - 1] = (*this)[i] * mint(i);
        }
        return ret;
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
        for (int i = 0; i < n; i++) {
            ret[i + 1] *= (*this)[i];
        }
        return ret;
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
    FPS pow(int64_t k, int deg = -1) const {
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

    FPS &operator*=(const FPS &r);
    FPS operator*(const FPS &r) const { return FPS(*this) *= r; }
    void but();
    void ibut();
    void db();
    static int but_pr();
    FPS inv(int deg = -1) const;
    FPS exp(int deg = -1) const;
};

#endif // FPS_HPP
