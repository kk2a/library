#ifndef KK2_FPS_FPS_BASE_HPP
#define KK2_FPS_FPS_BASE_HPP 1

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

#include "../math_mod/inv_table.hpp"
#include "../type_traits/io.hpp"

namespace kk2 {

template <class Derived, class mint> struct FormalPowerSeriesBase : std::vector<mint> {
    using std::vector<mint>::vector;
    using FPS = Derived;
    using ivta = InvTable<mint>;

    // CRTPを使って派生クラスの参照を取得
    Derived &derived() { return static_cast<Derived &>(*this); }
    const Derived &derived() const { return static_cast<const Derived &>(*this); }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    void debug_output(OStream &os) const {
        os << "[";
        for (size_t i = 0; i < this->size(); i++) {
            os << (*this)[i] << (i + 1 == this->size() ? "" : ", ");
        }
        os << "]";
    }

    template <class OStream, is_ostream_t<OStream> * = nullptr> void output(OStream &os) const {
        for (size_t i = 0; i < this->size(); i++) {
            os << (*this)[i] << (i + 1 == this->size() ? "\n" : " ");
        }
    }
    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const FPS &fps_) {
        for (size_t i = 0; i < fps_.size(); i++) {
            os << fps_[i] << (i + 1 == fps_.size() ? "" : " ");
        }
        return os;
    }

    template <class IStream, is_istream_t<IStream> * = nullptr> FPS &input(IStream &is) {
        for (size_t i = 0; i < this->size(); i++) is >> (*this)[i];
        return derived();
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend IStream &operator>>(IStream &is, FPS &fps_) {
        for (auto &x : fps_) is >> x;
        return is;
    }
    FPS &operator+=(const FPS &r) {
        if (this->size() < r.size()) this->resize(r.size());
        for (size_t i = 0; i < r.size(); i++) (*this)[i] += r[i];
        return derived();
    }

    FPS &operator+=(const mint &r) {
        if (this->empty()) this->resize(1);
        (*this)[0] += r;
        return derived();
    }

    FPS &operator-=(const FPS &r) {
        if (this->size() < r.size()) this->resize(r.size());
        for (size_t i = 0; i < r.size(); i++) (*this)[i] -= r[i];
        return derived();
    }

    FPS &operator-=(const mint &r) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= r;
        return derived();
    }

    FPS &operator*=(const mint &r) {
        for (size_t i = 0; i < this->size(); i++) { (*this)[i] *= r; }
        return derived();
    }
    FPS &operator/=(const FPS &r) {
        assert(!r.empty());
        if (this->size() < r.size()) {
            this->clear();
            return derived();
        }
        int n = this->size() - r.size() + 1;
        if (r.size() <= 64) {
            FPS f(derived()), g(r);
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
            return derived();
        }
        return derived() = (derived().rev().pre(n) * r.rev().inv(n)).pre(n).rev();
    }

    FPS &operator%=(const FPS &r) {
        derived() -= derived() / r * r;
        shrink();
        return derived();
    }

    FPS &operator>>=(int n) {
        if (n >= (int)this->size()) {
            this->clear();
        } else {
            this->erase(this->begin(), this->begin() + n);
        }
        return derived();
    }

    FPS &operator<<=(int n) {
        this->insert(this->begin(), n, mint(0));
        return derived();
    }

    // CRTPを使って派生クラスのメソッドを利用した演算子の自動実装
    FPS operator+(const FPS &r) const { return FPS(derived()) += r; }
    FPS operator+(const mint &r) const { return FPS(derived()) += r; }
    FPS operator-(const FPS &r) const { return FPS(derived()) -= r; }
    FPS operator-(const mint &r) const { return FPS(derived()) -= r; }
    // 掛け算は派生クラスで定義される
    FPS operator*(const FPS &r) const { return FPS(derived()) *= r; }
    FPS operator*(const mint &r) const { return FPS(derived()) *= r; }
    FPS operator/(const FPS &r) const { return FPS(derived()) /= r; }
    FPS operator%(const FPS &r) const { return FPS(derived()) %= r; }
    FPS operator>>(int n) const { return FPS(derived()) >>= n; }
    FPS operator<<(int n) const { return FPS(derived()) <<= n; }

    FPS operator-() const {
        FPS ret(this->size());
        for (size_t i = 0; i < this->size(); i++) ret[i] = -(*this)[i];
        return ret;
    }
    FPS &shrink() {
        while (this->size() && this->back() == mint(0)) this->pop_back();
        return derived();
    }

    FPS &inplace_rev() {
        std::reverse(this->begin(), this->end());
        return derived();
    }

    FPS &inplace_dot(const FPS &r) {
        this->resize(std::min(this->size(), r.size()));
        for (size_t i = 0; i < this->size(); i++) (*this)[i] *= r[i];
        return derived();
    }

    FPS &inplace_pre(int n) {
        this->resize(n);
        return derived();
    }

    FPS &inplace_diff() {
        if (this->empty()) return derived();
        this->erase(this->begin());
        for (size_t i = 1; i <= this->size(); i++) (*this)[i - 1] *= mint(i);
        return derived();
    }

    FPS &inplace_int() {
        ivta::set_upper(this->size());
        this->insert(this->begin(), mint(0));
        for (size_t i = 1; i < this->size(); i++) (*this)[i] *= ivta::inv(i);
        return derived();
    }

    // CRTPを使った便利関数の自動実装
    FPS rev() const { return FPS(derived()).inplace_rev(); }
    FPS dot(const FPS &r) const { return FPS(derived()).inplace_dot(r); }
    FPS pre(int n) const { return FPS(derived()).inplace_pre(n); }
    FPS diff() const { return FPS(derived()).inplace_diff(); }
    FPS integral() const { return FPS(derived()).inplace_int(); }

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
        // sparsity check
        return derived().dense_log(deg);
    }

    template <class T> FPS pow(T k, int deg = -1) const {
        // sparsity check
        return derived().dense_pow(k, deg);
    }

    FPS div(const FPS &r, int deg = -1) const {
        // sparsity check
        return (FPS(derived()).pre(deg) * r.inv(deg)).pre(deg);
    }

    FPS inv(int deg = -1) const {
        assert(!this->empty() && (*this)[0] != mint(0));
        // sparsity check
        return derived().dense_inv(deg);
    }

    FPS exp(int deg = -1) const {
        assert(this->empty() || (*this)[0] == mint(0));
        // sparsity check
        return derived().dense_exp(deg);
    }

    FPS dense_log(int deg = -1) const {
        if (deg == -1) deg = this->size();
        return (derived().diff() * derived().inv(deg)).pre(deg - 1).integral();
    }
    FPS sparse_log(int deg = -1) const {
        if (deg == -1) deg = this->size();
        std::vector<std::pair<int, mint>> fs;
        for (int i = 1; i < int(this->size()); i++) {
            if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i]);
        }
        ivta::set_upper(deg);

        FPS g(deg);
        for (int k = 0; k < deg - 1; k++) {
            for (auto &[j, fj] : fs) {
                if (k < j) break;
                int i = k - j;
                g[k + 1] -= g[i + 1] * fj * (i + 1);
            }
            g[k + 1] *= ivta::inv(k + 1);
            if (k + 1 < int(this->size())) g[k + 1] += (*this)[k + 1];
        }

        return g;
    }

    template <class T> FPS dense_pow(T k, int deg = -1) const {
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
                FPS ret = ((derived() * rev) >> i).log(deg) * k;
                ret = ret.exp(deg);
                ret *= (*this)[i].pow(k);
                ret = (ret << (i * k)).pre(deg);
                if ((int)ret.size() < deg) ret.resize(deg, mint(0));
                return ret;
            }
            if (__int128_t(i + 1) * k >= deg) return FPS(deg, mint(0));
        }
        return FPS(deg, mint(0));
    }
    template <class T> FPS sparse_pow(T k, int deg = -1) const {
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
    } // return this / r
    FPS sparse_div(const FPS &r, int deg = -1) const {
        assert(!r.empty() && r[0] != mint(0));
        if (deg == -1) deg = this->size();
        mint ir0 = r[0].inv();
        FPS ret = derived() * ir0;
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
        if (deg == -1) deg = this->size();
        std::vector<std::pair<int, mint>> fs;
        for (int i = 1; i < int(this->size()); i++) {
            if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i]);
        }

        int mod = mint::getmod();
        static std::vector<mint> inv{1, 1};
        int now = inv.size();
        inv.resize(std::max(now, deg + 1));
        for (int i = now; i <= deg; i++) inv[i] = -inv[mod % i] * (mod / i);

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
        for (int i = 0; i < n - 1; i++) (*this)[i + 1] += (*this)[i];
        return derived();
    }

    FPS &inplace_iimos(int n) {
        inplace_pre(n);
        for (int i = 0; i < n - 1; i++) (*this)[i + 1] -= (*this)[i];
        return derived();
    }
    FPS imos(int n) const { return FPS(derived()).inplace_imos(n); }
    FPS iimos(int n) const { return FPS(derived()).inplace_iimos(n); }
};

} // namespace kk2

#endif // KK2_FPS_FPS_BASE_HPP
