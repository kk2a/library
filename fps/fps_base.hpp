#ifndef KK2_FPS_FPS_BASE_HPP
#define KK2_FPS_FPS_BASE_HPP 1

#include <algorithm>
#include <iostream>
#include <vector>

#include "../math_mod/inv_table.hpp"
#include "../type_traits/fps.hpp"
#include "../type_traits/io.hpp"
#include "operations/division.hpp"
#include "operations/exponential.hpp"
#include "operations/inverse.hpp"
#include "operations/logarithm.hpp"
#include "operations/multiplication.hpp"
#include "operations/power.hpp"
#include "operations/sqrt.hpp"

namespace kk2 {

template <class Derived, fps::Modular mint> struct FormalPowerSeriesBase : std::vector<mint> {
    using std::vector<mint>::vector;
    using FPS = Derived;
    using ivta = InvTable<mint>;

    // CRTPを使って派生クラスの参照を取得
    Derived &derived() { return static_cast<Derived &>(*this); }
    const Derived &derived() const { return static_cast<const Derived &>(*this); }

    template <OutputStream OStream> void debug_output(OStream &os) const {
        os << "[";
        for (size_t i = 0; i < this->size(); i++) {
            os << (*this)[i] << (i + 1 == this->size() ? "" : ", ");
        }
        os << "]";
    }

    template <OutputStream OStream> void output(OStream &os) const {
        for (size_t i = 0; i < this->size(); i++) {
            os << (*this)[i] << (i + 1 == this->size() ? "\n" : " ");
        }
    }
    template <OutputStream OStream> friend OStream &operator<<(OStream &os, const FPS &fps_) {
        for (size_t i = 0; i < fps_.size(); i++) {
            os << fps_[i] << (i + 1 == fps_.size() ? "" : " ");
        }
        return os;
    }

    template <InputStream IStream> FPS &input(IStream &is) {
        for (size_t i = 0; i < this->size(); i++) is >> (*this)[i];
        return derived();
    }

    template <InputStream IStream> friend IStream &operator>>(IStream &is, FPS &fps_) {
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
    FPS &operator*=(const FPS &r) { return inplace_mul(r); }
    FPS &operator/=(const FPS &r) { return inplace_quo(r); }

    FPS dense_quo(const FPS &r) const { return fps::operations::dense_quo(derived(), r); }
    FPS &inplace_dense_quo(const FPS &r) {
        return fps::operations::inplace_dense_quo(derived(), r);
    }
    FPS sparse_quo(const FPS &r) const { return fps::operations::sparse_quo(derived(), r); }
    FPS &inplace_sparse_quo(const FPS &r) {
        return fps::operations::inplace_sparse_quo(derived(), r);
    }
    FPS quo(const FPS &r) const { return fps::operations::quo(derived(), r); }
    FPS &inplace_quo(const FPS &r) { return fps::operations::inplace_quo(derived(), r); }
    FPS mod(const FPS &r) const { return fps::operations::mod(derived(), r); }
    FPS &inplace_mod(const FPS &r) { return fps::operations::inplace_mod(derived(), r); }

    FPS &operator%=(const FPS &r) { return inplace_mod(r); }

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

    FPS dense_log(int deg = -1) const { return fps::operations::dense_log(derived(), deg); }
    FPS &inplace_dense_log(int deg = -1) {
        return fps::operations::inplace_dense_log(derived(), deg);
    }
    FPS sparse_log(int deg = -1) const { return fps::operations::sparse_log(derived(), deg); }
    FPS &inplace_sparse_log(int deg = -1) {
        return fps::operations::inplace_sparse_log(derived(), deg);
    }
    FPS log(int deg = -1) const { return fps::operations::log(derived(), deg); }
    FPS &inplace_log(int deg = -1) { return fps::operations::inplace_log(derived(), deg); }

    template <class T> FPS dense_pow(T exponent, int deg = -1) const {
        return fps::operations::dense_pow(derived(), exponent, deg);
    }
    template <class T> FPS &inplace_dense_pow(T exponent, int deg = -1) {
        return fps::operations::inplace_dense_pow(derived(), exponent, deg);
    }
    template <class T> FPS sparse_pow(T exponent, int deg = -1) const {
        return fps::operations::sparse_pow(derived(), exponent, deg);
    }
    template <class T> FPS &inplace_sparse_pow(T exponent, int deg = -1) {
        return fps::operations::inplace_sparse_pow(derived(), exponent, deg);
    }
    template <class T> FPS pow(T exponent, int deg = -1) const {
        return fps::operations::pow(derived(), exponent, deg);
    }
    template <class T> FPS &inplace_pow(T exponent, int deg = -1) {
        return fps::operations::inplace_pow(derived(), exponent, deg);
    }

    FPS dense_div(const FPS &r, int deg = -1) const {
        return fps::operations::dense_div(derived(), r, deg);
    }
    FPS &inplace_dense_div(const FPS &r, int deg = -1) {
        return fps::operations::inplace_dense_div(derived(), r, deg);
    }
    FPS sparse_div(const FPS &r, int deg = -1) const {
        return fps::operations::sparse_div(derived(), r, deg);
    }
    FPS &inplace_sparse_div(const FPS &r, int deg = -1) {
        return fps::operations::inplace_sparse_div(derived(), r, deg);
    }
    FPS div(const FPS &r, int deg = -1) const { return fps::operations::div(derived(), r, deg); }
    FPS &inplace_div(const FPS &r, int deg = -1) {
        return fps::operations::inplace_div(derived(), r, deg);
    }

    FPS dense_inv(int deg = -1) const { return fps::operations::dense_inv(derived(), deg); }
    FPS &inplace_dense_inv(int deg = -1) {
        return fps::operations::inplace_dense_inv(derived(), deg);
    }
    FPS sparse_inv(int deg = -1) const { return fps::operations::sparse_inv(derived(), deg); }
    FPS &inplace_sparse_inv(int deg = -1) {
        return fps::operations::inplace_sparse_inv(derived(), deg);
    }
    FPS inv(int deg = -1) const { return fps::operations::inv(derived(), deg); }
    FPS &inplace_inv(int deg = -1) { return fps::operations::inplace_inv(derived(), deg); }

    FPS dense_exp(int deg = -1) const { return fps::operations::dense_exp(derived(), deg); }
    FPS &inplace_dense_exp(int deg = -1) {
        return fps::operations::inplace_dense_exp(derived(), deg);
    }
    FPS sparse_exp(int deg = -1) const { return fps::operations::sparse_exp(derived(), deg); }
    FPS &inplace_sparse_exp(int deg = -1) {
        return fps::operations::inplace_sparse_exp(derived(), deg);
    }
    FPS exp(int deg = -1) const { return fps::operations::exp(derived(), deg); }
    FPS &inplace_exp(int deg = -1) { return fps::operations::inplace_exp(derived(), deg); }

    FPS dense_sqrt(int deg = -1) const { return fps::operations::dense_sqrt(derived(), deg); }
    FPS &inplace_dense_sqrt(int deg = -1) {
        return fps::operations::inplace_dense_sqrt(derived(), deg);
    }
    FPS sparse_sqrt(int deg = -1) const { return fps::operations::sparse_sqrt(derived(), deg); }
    FPS &inplace_sparse_sqrt(int deg = -1) {
        return fps::operations::inplace_sparse_sqrt(derived(), deg);
    }
    FPS sqrt(int deg = -1) const { return fps::operations::sqrt(derived(), deg); }
    FPS &inplace_sqrt(int deg = -1) { return fps::operations::inplace_sqrt(derived(), deg); }

    FPS dense_mul(const FPS &r, int deg = -1) const {
        return fps::operations::dense_mul(derived(), r, deg);
    }
    FPS &inplace_dense_mul(const FPS &r, int deg = -1) {
        return fps::operations::inplace_dense_mul(derived(), r, deg);
    }
    FPS sparse_mul(const FPS &r, int deg = -1) const {
        return fps::operations::sparse_mul(derived(), r, deg);
    }
    FPS &inplace_sparse_mul(const FPS &r, int deg = -1) {
        return fps::operations::inplace_sparse_mul(derived(), r, deg);
    }
    FPS mul(const FPS &r, int deg = -1) const { return fps::operations::mul(derived(), r, deg); }
    FPS &inplace_mul(const FPS &r, int deg = -1) {
        return fps::operations::inplace_mul(derived(), r, deg);
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
