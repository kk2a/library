#ifndef KK2_FPS_FPS_MULTIVARIATE_HPP
#define KK2_FPS_FPS_MULTIVARIATE_HPP 1

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

#include "../type_traits/io.hpp"
#include "fps_arb.hpp"
#include "fps_ntt_friendly.hpp"
#include "operations/multivariate/exponential.hpp"
#include "operations/multivariate/inverse.hpp"
#include "operations/multivariate/logarithm.hpp"
#include "operations/multivariate/multiplication.hpp"
#include "operations/multivariate/power.hpp"

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

    mfps dense_mul(const mfps &rhs) const { return kk2::fps::operations::dense_mul(*this, rhs); }
    mfps &inplace_dense_mul(const mfps &rhs) {
        return kk2::fps::operations::inplace_dense_mul(*this, rhs);
    }
    mfps sparse_mul(const mfps &rhs) const { return kk2::fps::operations::sparse_mul(*this, rhs); }
    mfps &inplace_sparse_mul(const mfps &rhs) {
        return kk2::fps::operations::inplace_sparse_mul(*this, rhs);
    }
    mfps mul(const mfps &rhs) const { return kk2::fps::operations::mul(*this, rhs); }
    mfps &inplace_mul(const mfps &rhs) { return kk2::fps::operations::inplace_mul(*this, rhs); }

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

    mfps dense_inv() const { return kk2::fps::operations::dense_inv(*this); }
    mfps &inplace_dense_inv() { return kk2::fps::operations::inplace_dense_inv(*this); }
    mfps sparse_inv() const { return kk2::fps::operations::sparse_inv(*this); }
    mfps &inplace_sparse_inv() { return kk2::fps::operations::inplace_sparse_inv(*this); }
    mfps inv() const { return kk2::fps::operations::inv(*this); }
    mfps &inplace_inv() { return kk2::fps::operations::inplace_inv(*this); }

    mfps dense_log() const { return kk2::fps::operations::dense_log(*this); }
    mfps &inplace_dense_log() { return kk2::fps::operations::inplace_dense_log(*this); }
    mfps sparse_log() const { return kk2::fps::operations::sparse_log(*this); }
    mfps &inplace_sparse_log() { return kk2::fps::operations::inplace_sparse_log(*this); }
    mfps log() const { return kk2::fps::operations::log(*this); }
    mfps &inplace_log() { return kk2::fps::operations::inplace_log(*this); }

    mfps dense_exp() const { return kk2::fps::operations::dense_exp(*this); }
    mfps &inplace_dense_exp() { return kk2::fps::operations::inplace_dense_exp(*this); }
    mfps sparse_exp() const { return kk2::fps::operations::sparse_exp(*this); }
    mfps &inplace_sparse_exp() { return kk2::fps::operations::inplace_sparse_exp(*this); }
    mfps exp() const { return kk2::fps::operations::exp(*this); }
    mfps &inplace_exp() { return kk2::fps::operations::inplace_exp(*this); }

    mfps dense_pow(long long e) const { return kk2::fps::operations::dense_pow(*this, e); }
    mfps &inplace_dense_pow(long long e) {
        return kk2::fps::operations::inplace_dense_pow(*this, e);
    }
    mfps sparse_pow(long long e) const { return kk2::fps::operations::sparse_pow(*this, e); }
    mfps &inplace_sparse_pow(long long e) {
        return kk2::fps::operations::inplace_sparse_pow(*this, e);
    }
    mfps pow(long long e) const { return kk2::fps::operations::pow(*this, e); }
    mfps &inplace_pow(long long e) { return kk2::fps::operations::inplace_pow(*this, e); }
};

template <fps::Modular mint, template <fps::Modular> class UnivariateFPS>
std::vector<mint> MultivariateFormalPowerSeries<mint, UnivariateFPS>::_inv = {0, 1};

template <fps::Modular mint>
using MultivariateFormalPowerSeriesArbitrary =
    MultivariateFormalPowerSeries<mint, FormalPowerSeriesArbitrary>;

} // namespace kk2

#endif // KK2_FPS_FPS_MULTIVARIATE_HPP
