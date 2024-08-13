#ifndef FPS_MULTIVARIATE_FPS_HPP
#define FPS_MULTIVARIATE_FPS_HPP 1

#include "fps.hpp"
#include "../convolution/multi_convo_truncated.hpp"

template <typename mint>
struct MultivariateFormalPowerSeries {
    using mfps = MultivariateFormalPowerSeries;
    using fps = FormalPowerSeries<mint>;
    using value_type = mint;

    vector<int> base;
    fps f;

    MultivariateFormalPowerSeries() = default;
    MultivariateFormalPowerSeries(const vector<int>& base_) : base(base_) {
        int n = 1;
        for (int x : base) n *= x;
        f.resize(n);
    }
    MultivariateFormalPowerSeries(const vector<int>& base_, const fps& f_) : base(base_), f(f_) {}

    template <typename T, typename... Ts>
    int _id(int x, T y, Ts... ys) {
        assert(x < (int)base.size() && (int)y < base[x]);
        if constexpr (sizeof...(Ts) == 0) return y;
        return y + base[x] * _id(x + 1, ys...);
    }

    template <typename... Args>
    int id(Args... args) {
        return _id(0, args...);
    }

    template <typename... Args>
    mint& operator()(Args... args) {
        return f[id(args...)];
    }

    mint& operator[](int i) {
        return f[i];
    }

    void display() const {
        for (int i = 0; i < (int)f.size(); i++) {
            int x = i;
            cout << "f(";
            for (int j = 0; j < (int)base.size(); j++) {
                cout << x % base[j] << (j + 1 == (int)base.size() ? ") = " : ", ");
                x /= base[j];
            }
            cout << f[i] << endl;
        }
    }

    mfps& operator+=(const mfps& rhs) {
        assert(base == rhs.base && f.size() == rhs.f.size());
        for (int i = 0; i < (int)f.size(); i++) f[i] += rhs.f[i];
        return *this;
    }

    mfps& operator-=(const mfps& rhs) {
        assert(base == rhs.base && f.size() == rhs.f.size());
        for (int i = 0; i < (int)f.size(); i++) f[i] -= rhs.f[i];
        return *this;
    }

    mfps& operator*=(const mfps& rhs) {
        assert(base == rhs.base && f.size() == rhs.f.size());
        multi_convolution_truncated(f, rhs.f, base);
        return *this;
    }

    mfps& operator+=(const mint& rhs) {
        assert(!f.empty());
        f[0] += rhs;
        return *this;
    }

    mfps& operator-=(const mint& rhs) {
        assert(!f.empty());
        f[0] -= rhs;
        return *this;
    }

    mfps& operator*=(const mint& rhs) {
        for (auto &x : f) x *= rhs;
        return *this;
    }

    mfps& operator/=(const mint& rhs) {
        for (auto &x : f) x /= rhs;
        return *this;
    }

    mfps operator+(const mfps& rhs) const { return mfps(*this) += rhs; }
    mfps operator-(const mfps& rhs) const { return mfps(*this) -= rhs; }
    mfps operator*(const mfps& rhs) const { return mfps(*this) *= rhs; }

    mfps operator+(const mint& rhs) const { return mfps(*this) += rhs; }
    mfps operator-(const mint& rhs) const { return mfps(*this) -= rhs; }
    mfps operator*(const mint& rhs) const { return mfps(*this) *= rhs; }
    mfps operator/(const mint& rhs) const { return mfps(*this) /= rhs; }

    mfps operator+() const { return mfps(*this); }
    mfps operator-() const { return mfps(base, -f); }

    friend bool operator==(const mfps& lhs, const mfps& rhs) {
        return lhs.f == rhs.f && lhs.base == rhs.base;
    }
    friend bool operator!=(const mfps& lhs, const mfps& rhs) {
        return !(lhs == rhs);
    }

    mfps diff() const {
        mfps ret(*this);
        for (int i = 0; i < (int)ret.f.size(); i++) ret.f[i] *= i;
        return ret;
    }

    mfps& inplace_diff() {
        for (int i = 0; i < (int)f.size(); i++) f[i] *= i;
        return *this;
    }

    static vector<mint> _inv;
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

    mfps& inplace_int() {
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
        vector<int> chi(z);
        for (int i = 0; i < n; i++) {
            int x = i;
            for (int j = 0; j < k - 1; j++) chi[i] += (x /= base[j]);
            chi[i] %= k;
        }
        auto naive_and_dot = [&k](const vector<fps>& a, const vector<fps>& b, vector<fps>& c) -> void {
            vector<mint> tmp(k);
            for (int ii = 0; ii < (int)a[0].size(); ii++) {
                for (int i = 0; i < k; i++) {
                    for (int j = 0; j < k; j++) {
                        tmp[i + j - (i + j >= k ? k : 0)] += a[i][ii] * b[j][ii];
                    }
                }
                for (int i = 0; i < k; i++) c[i][ii] = tmp[i], tmp[i] = mint{0};
            }
        };

        // reference: https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp
        // Let g_k := f_k^{-1} mod x^k, \deg g_k < k.
        // Then we obtain g_1, g_2, g_4, ... by using the following recurrence:
        // - g_1 = (f_0)^{-1} ...(1)
        // - g_{2k} = 2g_k - g_k^2 f mod x^2k ...(2)
        // - [x^{k + i}]g_{2k} = [x^{k + i}](-g_k^2 f) ...(3)
        fps g(z);
        g[0] = f[0].inv(); // by (1)
        mint inv2 = mint{2}.inv();
        mint i2d = inv2;
        for (int d = 1; d < n; d <<= 1) {
            vector<fps> a(k, fps(2 * d)), b(k, fps(2 * d)), c(k, fps(2 * d));
            for (int i = 0; i < min((int)f.size(), 2 * d); i++) a[chi[i]][i] = f[i];
            for (int i = 0; i < d; i++) b[chi[i]][i] = g[i];
            for (auto& x : a) butterfly(x);
            for (auto& x : b) butterfly(x);
            naive_and_dot(a, b, c);
            for (auto& x : c) {
                butterfly_inv(x);
                x *= i2d;
            }
            // compute g_k f

            for (auto& x : a) fill(begin(x), end(x), mint(0));

            // \becasue \deg g_k < k, we can ignore the terms of x^{k + i} for i >= k.
            for (int i = 0; i < 2 * d; i++) a[chi[i]][i] = c[chi[i]][i];
            for (auto& x : a) butterfly(x);
            naive_and_dot(a, b, c);
            for (auto& x : c) {
                butterfly_inv(x);
                x *= i2d;
            }
            // compute g_k^2 f

            // by (2), (3)
            for (int i = d; i < 2 * d; i++) g[i] = -c[chi[i]][i];
            i2d *= inv2;
        }
        mfps res(*this);
        res.f = fps(begin(g), begin(g) + n);
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
            int s = min(n, 2 * d);
            res.f.resize(s, mint(0));
            res *= mfps(base, fps(begin(f), begin(f) + s)) - res.log() + 1;
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
        for (auto& b : base) base_sum += b - 1;
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

template <typename mint>
vector<mint> MultivariateFormalPowerSeries<mint>::_inv = {0, 1};

namespace kk2 {
    template <typename mint>
    using MFPS = MultivariateFormalPowerSeries<mint>;
}

#endif // FPS_MULTIVARIATE_FPS_HPP
