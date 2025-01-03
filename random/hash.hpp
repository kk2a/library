#ifndef RANDOM_HASH_HPP
#define RANDOM_HASH_HPP 1

#include <algorithm>
#include <array>
#include <cassert>

#include "../modint/modint_2_61m1.hpp"
#include "gen.hpp"

namespace kk2 {

namespace random {

template <int NUM> struct Hash : std::array<ModInt2_61m1, NUM> {
    using mint = ModInt2_61m1;
    using std::array<mint, NUM>::operator[];
    using u64 = unsigned long long;

    Hash() : std::array<mint, NUM>() {}

    template <class T, is_integral_t<T> * = nullptr> Hash(T x) {
        std::fill(this->begin(), this->end(), mint(x));
    }

    static Hash get_base() {
        Hash base;
        for (int i = 0; i < NUM; i++) { base[i] = rng(1, mint::getmod() - 1); }
        return base;
    }

    Hash &operator+=(const Hash &rhs) {
        for (int i = 0; i < NUM; i++) { (*this)[i] += rhs[i]; }
        return *this;
    }

    Hash &operator-=(const Hash &rhs) {
        for (int i = 0; i < NUM; i++) { (*this)[i] -= rhs[i]; }
        return *this;
    }

    Hash &operator*=(const Hash &rhs) {
        for (int i = 0; i < NUM; i++) { (*this)[i] *= rhs[i]; }
        return *this;
    }

    Hash &operator/=(const Hash &rhs) {
        for (int i = 0; i < NUM; i++) { (*this)[i] /= rhs[i]; }
        return *this;
    }

    Hash operator+(const Hash &rhs) const { return Hash(*this) += rhs; }

    Hash operator-(const Hash &rhs) const { return Hash(*this) -= rhs; }

    Hash operator*(const Hash &rhs) const { return Hash(*this) *= rhs; }

    Hash operator/(const Hash &rhs) const { return Hash(*this) /= rhs; }

    Hash operator-() const {
        Hash res;
        for (int i = 0; i < NUM; i++) { res[i] = -(*this)[i]; }
        return res;
    }

    bool operator==(const Hash &rhs) const {
        for (int i = 0; i < NUM; i++) {
            if ((*this)[i] != rhs[i]) return false;
        }
        return true;
    }

    bool operator!=(const Hash &rhs) const {
        for (int i = 0; i < NUM; i++) {
            if ((*this)[i] != rhs[i]) return true;
        }
        return false;
    }

    Hash pow(u64 n) const {
        Hash x = *this, r;
        for (int i = 0; i < NUM; i++) { r[i] = x[i].pow(n); }
        return r;
    }

    Hash inv() const {
        Hash r;
        for (int i = 0; i < NUM; i++) { r[i] = (*this)[i].inv(); }
        return r;
    }
};

} // namespace random

} // namespace kk2

#endif // RANDOM_HASH_HPP
