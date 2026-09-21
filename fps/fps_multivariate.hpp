#ifndef KK2_FPS_FPS_MULTIVARIATE_HPP
#define KK2_FPS_FPS_MULTIVARIATE_HPP 1

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

#include "../convolution/multi_convolution_truncated.hpp"
#include "../convolution/multi_convolution_truncated_arb.hpp"
#include "../type_traits/io.hpp"
#include "fps_arb.hpp"
#include "fps_ntt_friendly.hpp"

namespace kk2 {

template <fps::Modular mint,
          template <fps::Modular> class UnivariateFPS = FormalPowerSeriesNTTFriendly>
struct MultivariateFormalPowerSeries {
    using mfps = MultivariateFormalPowerSeries;
    using fps = UnivariateFPS<mint>;
    using value_type = mint;
    using modulus_category = typename fps::modulus_category;
    using series_category = kk2::fps::category::ordinary;
    using variable_category = kk2::fps::category::multivariate;

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

    int size() const { return f.size(); }
    auto begin() { return f.begin(); }
    auto end() { return f.end(); }
    auto begin() const { return f.begin(); }
    auto end() const { return f.end(); }

    template <OutputStream OStream> friend OStream &operator<<(OStream &os, const mfps &mfps_) {
        for (int i = 0; i < (int)mfps_.f.size(); i++)
            os << mfps_.f[i] << (i + 1 == (int)mfps_.f.size() ? "" : " ");
        return os;
    }

    template <OutputStream OStream> void output(OStream &os) const {
        for (int i = 0; i < (int)f.size(); i++) os << f[i] << (i + 1 == (int)f.size() ? "\n" : " ");
    }

    template <InputStream IStream> mfps &input(IStream &is) {
        for (auto &x : f) is >> x;
        return *this;
    }

    template <InputStream IStream> friend IStream &operator>>(IStream &is, mfps &mfps_) {
        for (auto &x : mfps_.f) is >> x;
        return is;
    }

    template <typename T, typename... Ts> int _id(int x, T y, Ts... ys) {
        assert(x < (int)base.size() && (int)y < base[x]);
        if constexpr (sizeof...(Ts) == 0) return y;
        else return y + base[x] * _id(x + 1, ys...);
    }

    template <typename... Args>
        requires(sizeof...(Args) > 0)
    int id(Args... args) {
        return _id(0, args...);
    }

    template <typename... Args> mint &operator()(Args... args) { return f[id(args...)]; }

    mint &operator[](int i) { return f[i]; }
    const mint &operator[](int i) const { return f[i]; }

    template <OutputStream OStream> void display(OStream &os) const {
        for (int i = 0; i < (int)f.size(); i++) {
            int x = i;
            os << "f(";
            for (int j = 0; j < (int)base.size(); j++) {
                os << x % base[j] << (j + 1 == (int)base.size() ? ") = " : ", ");
                x /= base[j];
            }
            os << f[i] << "\n";
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

    mfps dense_mul(const mfps &rhs) const { return mfps(*this).inplace_dense_mul(rhs); }
    mfps &inplace_dense_mul(const mfps &rhs) {
        assert(base == rhs.base && f.size() == rhs.f.size());
        if constexpr (kk2::fps::ArbitraryModulusFormalPowerSeries<fps>) {
            inplace_multi_convolution_truncated_arb(f, rhs.f, base);
        } else {
            inplace_multi_convolution_truncated(f, rhs.f, base);
        }
        return *this;
    }
    mfps sparse_mul(const mfps &rhs) const { return mfps(*this).inplace_sparse_mul(rhs); }
    mfps &inplace_sparse_mul(const mfps &rhs) {
        assert(base == rhs.base && f.size() == rhs.f.size());
        inplace_multi_convolution_truncated_sparse(f, rhs.f, base);
        return *this;
    }
    mfps mul(const mfps &rhs) const { return dense_mul(rhs); }
    mfps &inplace_mul(const mfps &rhs) { return inplace_dense_mul(rhs); }

    mfps &operator*=(const mfps &rhs) { return inplace_mul(rhs); }

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

    mfps operator*(const mfps &rhs) const { return mul(rhs); }

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

    mfps dense_inv() const {
        assert(!f.empty() && f[0] != mint(0));
        if (base.empty()) return mfps(base, fps{f[0].inv()});

        if constexpr (kk2::fps::ArbitraryModulusFormalPowerSeries<fps>) {
            const int n = f.size();
            mfps result(base, fps(n));
            result.f[0] = f[0].inv();
            for (int d = 1; d < n; d <<= 1) {
                const int precision = std::min(2 * d, n);
                mfps lhs(base, fps(precision));
                mfps rhs(base, fps(precision));
                std::copy_n(f.begin(), precision, lhs.f.begin());
                std::copy_n(result.f.begin(), std::min(d, precision), rhs.f.begin());

                mfps correction(base, fps(precision));
                correction += mint(2);
                correction -= lhs.dense_mul(rhs);
                rhs.inplace_dense_mul(correction);
                std::copy(rhs.f.begin() + d, rhs.f.end(), result.f.begin() + d);
            }
            return result;
        }

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

            for (auto &x : a) std::ranges::fill(x, mint(0));

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
    mfps &inplace_dense_inv() { return *this = dense_inv(); }
    mfps sparse_inv() const {
        assert(!f.empty() && f[0] != mint(0));
        const int n = f.size();
        mfps result(base, fps(n));
        result.f[0] = f[0].inv();
        for (int i = 1; i < n; ++i) {
            int x = i;
            std::vector<int> target(base.size());
            for (int d = 0; d < (int)base.size(); ++d) {
                target[d] = x % base[d];
                x /= base[d];
            }

            mint coefficient = 0;
            for (int j = 1; j < n; ++j) {
                if (f[j] == mint(0)) continue;
                int y = j, complement = 0, stride = 1;
                bool in_range = true;
                for (int d = 0; d < (int)base.size(); ++d) {
                    const int coordinate = y % base[d];
                    y /= base[d];
                    if (coordinate > target[d]) {
                        in_range = false;
                        break;
                    }
                    complement += (target[d] - coordinate) * stride;
                    stride *= base[d];
                }
                if (in_range) coefficient += f[j] * result.f[complement];
            }
            result.f[i] = -coefficient * result.f[0];
        }
        return result;
    }
    mfps &inplace_sparse_inv() { return *this = sparse_inv(); }
    mfps inv() const { return dense_inv(); }
    mfps &inplace_inv() { return inplace_dense_inv(); }

    mfps dense_log() const {
        assert(!f.empty() && f[0] == mint(1));
        mfps result = diff().dense_mul(dense_inv()).integral();
        result.f.resize(f.size());
        return result;
    }
    mfps &inplace_dense_log() { return *this = dense_log(); }
    mfps sparse_log() const {
        assert(!f.empty() && f[0] == mint(1));
        mfps result = diff().sparse_mul(sparse_inv()).integral();
        result.f.resize(f.size());
        return result;
    }
    mfps &inplace_sparse_log() { return *this = sparse_log(); }
    mfps log() const { return dense_log(); }
    mfps &inplace_log() { return inplace_dense_log(); }

    mfps dense_exp() const {
        assert(!f.empty() && f[0] == mint(0));
        int n = f.size();
        mfps res(base, fps{1});
        for (int d = 1; d < n; d <<= 1) {
            int s = std::min(n, 2 * d);
            res.f.resize(s, mint(0));
            mfps target(base, fps(std::begin(f), std::begin(f) + s));
            mfps correction = target - res.dense_log();
            correction += mint(1);
            res.inplace_dense_mul(correction);
        }
        return res;
    }
    mfps &inplace_dense_exp() { return *this = dense_exp(); }
    mfps sparse_exp() const {
        assert(!f.empty() && f[0] == mint(0));
        int n = f.size();
        mfps res(base, fps{1});
        for (int d = 1; d < n; d <<= 1) {
            int s = std::min(n, 2 * d);
            res.f.resize(s, mint(0));
            mfps target(base, fps(std::begin(f), std::begin(f) + s));
            mfps correction = target - res.sparse_log();
            correction += mint(1);
            res.inplace_sparse_mul(correction);
        }
        return res;
    }
    mfps &inplace_sparse_exp() { return *this = sparse_exp(); }
    mfps exp() const { return dense_exp(); }
    mfps &inplace_exp() { return inplace_dense_exp(); }

    mfps dense_pow(long long e) const {
        assert(!f.empty());
        if (f[0] != mint(0)) {
            mint f0inv = f[0].inv(), coef = f[0].pow(e);
            return (((*this) * f0inv).dense_log() * e).dense_exp() * coef;
        }
        int n = f.size();
        long long base_sum = 0;
        for (auto &b : base) base_sum += b - 1;
        if (e > base_sum) return mfps(base, fps(n));
        mfps res(base, fps(n)), a(*this);
        res.f[0] = 1;
        while (e) {
            if (e & 1) res.inplace_dense_mul(a);
            if (e >>= 1) a.inplace_dense_mul(a);
        }
        return res;
    }
    mfps &inplace_dense_pow(long long e) { return *this = dense_pow(e); }
    mfps sparse_pow(long long e) const {
        assert(!f.empty());
        if (f[0] != mint(0)) {
            mint f0inv = f[0].inv(), coef = f[0].pow(e);
            return (((*this) * f0inv).sparse_log() * e).sparse_exp() * coef;
        }
        int n = f.size();
        long long base_sum = 0;
        for (auto &b : base) base_sum += b - 1;
        if (e > base_sum) return mfps(base, fps(n));
        mfps res(base, fps(n)), a(*this);
        res.f[0] = 1;
        while (e) {
            if (e & 1) res.inplace_sparse_mul(a);
            if (e >>= 1) a.inplace_sparse_mul(a);
        }
        return res;
    }
    mfps &inplace_sparse_pow(long long e) { return *this = sparse_pow(e); }
    mfps pow(long long e) const { return dense_pow(e); }
    mfps &inplace_pow(long long e) { return inplace_dense_pow(e); }
};

template <fps::Modular mint, template <fps::Modular> class UnivariateFPS>
std::vector<mint> MultivariateFormalPowerSeries<mint, UnivariateFPS>::_inv = {0, 1};

template <fps::Modular mint>
using MultivariateFormalPowerSeriesArbitrary =
    MultivariateFormalPowerSeries<mint, FormalPowerSeriesArbitrary>;

} // namespace kk2

#endif // KK2_FPS_FPS_MULTIVARIATE_HPP
