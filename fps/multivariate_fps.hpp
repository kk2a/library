#ifndef FPS_MULTIVARIATE_FPS_HPP
#define FPS_MULTIVARIATE_FPS_HPP 1

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#include "../convolution/multi_convolution_truncated.hpp"
#include "ntt_friendly.hpp"

namespace kk2 {

template <typename mint> struct MultivariateFormalPowerSeries {
    using mfps = MultivariateFormalPowerSeries;
    using fps = FormalPowerSeries<mint>;
    using value_type = mint;

    std::vector<int> base;
    fps f;

    MultivariateFormalPowerSeries() = default;

    MultivariateFormalPowerSeries(const std::vector<int> &base_) : base(base_) {
        int n = 1;
        for (int x : base) n *= x;
        f.resize(n);
    }

    MultivariateFormalPowerSeries(const std::vector<int> &base_, const fps &f_)
        : base(base_),
          f(f_) {}

    friend std::ostream &operator<<(std::ostream &os, MFPS &mfps_) const {
        for (int i = 0; i < (int)mfps_.f.size(); i++) os << mfps_.f[i] << (i + 1 == (int)mfps_.f.size() ? "" : " ");
        return os;
    }

    void output(std::ostream &os) const {
        for (int i = 0; i < (int)f.size(); i++) os << f[i] << (i + 1 == (int)f.size() ? "\n" : " ");
    }

    MFPS &input(std::istream &is) {
        for (auto &x : f) is >> x;
        return *this;
    }

    friend std::istream &operator>>(std::istream &is, MFPS &mfps_) {
        for (auto &x : mfps_.f) is >> x;
        return is;
    }

    template <typename T, typename... Ts> int _id(int x, T y, Ts... ys) {
        assert(x < (int)base.size() && (int)y < base[x]);
        if constexpr (sizeof...(Ts) == 0) return y;
        else return y + base[x] * _id(x + 1, ys...);
    }

    template <typename... Args> int id(Args... args) {
        static_assert(sizeof...(Args) > 0);
        return _id(0, args...);
    }

    template <typename... Args> mint &operator()(Args... args) { return f[id(args...)]; }

    mint &operator[](int i) { return f[i]; }

    void display() const {
        for (int i = 0; i < (int)f.size(); i++) {
            int x = i;
            std::cout << "f(";
            for (int j = 0; j < (int)base.size(); j++) {
                std::cout << x % base[j] << (j + 1 == (int)base.size() ? ") = " : ", ");
                x /= base[j];
            }
            std::cout << f[i] << "\n";
        }
    }

    mfps &operator+=(const mfps &rhs) {
        assert(base == rhs.base && f.size() == rhs.f.size());
        for (int i = 0; i < (int)f.size(); i++) f[i] += rhs.f[i];
        return *this;
    }

    mfps &operator-=(const mfps &rhs) {
        assert(base == rhs.base && f.size() == rhs.f.size());
        for (int i = 0; i < (int)f.size(); i++) f[i] -= rhs.f[i];
        return *this;
    }

    mfps &operator*=(const mfps &rhs) {
        assert(base == rhs.base && f.size() == rhs.f.size());
        multi_convolution_truncated(f, rhs.f, base);
        return *this;
    }

    mfps &operator+=(const mint &rhs) {
        assert(!f.empty());
        f[0] += rhs;
        return *this;
    }

    mfps &operator-=(const mint &rhs) {
        assert(!f.empty());
        f[0] -= rhs;
        return *this;
    }

    mfps &operator*=(const mint &rhs) {
        for (auto &x : f) x *= rhs;
        return *this;
    }

    mfps &operator/=(const mint &rhs) {
        for (auto &x : f) x /= rhs;
        return *this;
    }

    mfps operator+(const mfps &rhs) const { return mfps(*this) += rhs; }

    mfps operator-(const mfps &rhs) const { return mfps(*this) -= rhs; }

    mfps operator*(const mfps &rhs) const { return mfps(*this) *= rhs; }

    mfps operator+(const mint &rhs) const { return mfps(*this) += rhs; }

    mfps operator-(const mint &rhs) const { return mfps(*this) -= rhs; }

    mfps operator*(const mint &rhs) const { return mfps(*this) *= rhs; }

    mfps operator/(const mint &rhs) const { return mfps(*this) /= rhs; }

    mfps operator+() const { return mfps(*this); }

    mfps operator-() const { return mfps(base, -f); }

    friend bool operator==(const mfps &lhs, const mfps &rhs) {
        return lhs.f == rhs.f && lhs.base == rhs.base;
    }

    friend bool operator!=(const mfps &lhs, const mfps &rhs) { return !(lhs == rhs); }

    mfps diff() const {
        mfps ret(*this);
        for (int i = 0; i < (int)ret.f.size(); i++) ret.f[i] *= i;
        return ret;
    }

    mfps &inplace_diff() {
        for (int i = 0; i < (int)f.size(); i++) f[i] *= i;
        return *this;
    }

    static std::vector<mint> _inv;

    static void ensure_inv(int n) {
        while ((int)_inv.size() <= n) {
            int i = _inv.size();
            _inv.push_back((-_inv[mint::getmod() % i]) * (mint::getmod() / i));
        }
    }

    mfps integral() const {
        ensure_inv(f.size());
        mfps ret(*this);
        for (int i = 1; i < (int)ret.f.size(); i++) ret.f[i] *= _inv[i];
        return ret;
    }

    mfps &inplace_int() {
        ensure_inv(f.size());
        for (int i = 1; i < (int)f.size(); i++) f[i] *= _inv[i];
        return *this;
    }

    mfps inv() const {
        assert(!f.empty() && f[0] != mint(0));
        if (base.empty()) return mfps(base, fps{f[0].inv()});

        int n = f.size(), k = base.size();
        int z = 1;
        while (z < 2 * n - 1) z <<= 1;
        std::vector<int> chi(z);
        for (int i = 0; i < n; i++) {
            int x = i;
            for (int j = 0; j < k - 1; j++) chi[i] += (x /= base[j]);
            chi[i] %= k;
        }
        auto naive_and_dot = [&k](const std::vector<fps> &a,
                                  const std::vector<fps> &b,
                                  std::vector<fps> &c) -> void {
            std::vector<mint> tmp(k);
            for (int ii = 0; ii < (int)a[0].size(); ii++) {
                for (int i = 0; i < k; i++) {
                    for (int j = 0; j < k; j++) {
                        tmp[i + j - (i + j >= k ? k : 0)] += a[i][ii] * b[j][ii];
                    }
                }
                for (int i = 0; i < k; i++) c[i][ii] = tmp[i], tmp[i] = mint{0};
            }
        };

        // reference:
        // https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp
        // Let g_k := f_k^{-1} mod x^k, \deg g_k < k.
        // Then we obtain g_1, g_2, g_4, ... by using the following recurrence:
        // - g_1 = (f_0)^{-1} ...(1)
        // - g_{2k} = 2g_k - g_k^2 f mod x^2k ...(2)
        // - [x^{k + i}]g_{2k} = [x^{k + i}](-g_k^2 f) ...(3)
        fps g(z);
        g[0] = f[0].inv(); // by (1)
        for (int d = 1; d < n; d <<= 1) {
            std::vector<fps> a(k, fps(2 * d)), b(k, fps(2 * d)), c(k, fps(2 * d));
            for (int i = 0; i < std::min((int)f.size(), 2 * d); i++) a[chi[i]][i] = f[i];
            for (int i = 0; i < d; i++) b[chi[i]][i] = g[i];
            for (auto &x : a) x.but();
            for (auto &x : b) x.but();
            naive_and_dot(a, b, c);
            for (auto &x : c) x.ibut();
            // compute g_d f

            for (auto &x : a) std::fill(std::begin(x), std::end(x), mint(0));

            for (int i = d; i < 2 * d; i++) a[chi[i]][i] = c[chi[i]][i];
            for (auto &x : a) x.but();
            naive_and_dot(a, b, c);
            for (auto &x : c) x.ibut();
            // compute g_d^2 f

            // by (2), (3)
            for (int i = d; i < 2 * d; i++) g[i] = -c[chi[i]][i];
        }
        mfps res(*this);
        res.f = fps(std::begin(g), std::begin(g) + n);
        return res;
    }

    mfps log() const {
        assert(!f.empty() && f[0] == mint(1));
        return ((*this).diff() * (*this).inv()).integral();
    }

    mfps exp() const {
        assert(!f.empty() && f[0] == mint(0));
        int n = f.size();
        mfps res(base, fps{1});
        for (int d = 1; d < n; d <<= 1) {
            int s = std::min(n, 2 * d);
            res.f.resize(s, mint(0));
            res *= mfps(base, fps(std::begin(f), std::begin(f) + s)) - res.log() + 1;
        }
        return res;
    }

    mfps pow(long long e) const {
        assert(!f.empty());
        if (f[0] != mint(0)) {
            mint f0inv = f[0].inv(), coef = f[0].pow(e);
            return (((*this) * f0inv).log() * e).exp() * coef;
        }
        int n = f.size();
        long long base_sum = 0;
        for (auto &b : base) base_sum += b - 1;
        if (e > base_sum) return mfps(base, fps(n));
        mfps res(base, fps(n)), a(*this);
        res.f[0] = 1;
        while (e) {
            if (e & 1) res *= a;
            if (e >>= 1) a *= a;
        }
        return res;
    }
};

template <typename mint> std::vector<mint> MultivariateFormalPowerSeries<mint>::_inv = {0, 1};

} // namespace kk2

#endif // FPS_MULTIVARIATE_FPS_HPP
