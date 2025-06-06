#ifndef KK2_RANDOM_HASH_HPP
#define KK2_RANDOM_HASH_HPP 1

#include <algorithm>
#include <array>
#include <cassert>

#include "../math_mod/primitive_root_64bit.hpp"
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
        for (int i = 0; i < NUM; i++) base[i] = primitive_root_mint<ModInt2_61m1>();
        return base;
    }

    Hash &operator+=(const Hash &rhs) {
        for (int i = 0; i < NUM; i++) (*this)[i] += rhs[i];
        return *this;
    }
    Hash &operator-=(const Hash &rhs) {
        for (int i = 0; i < NUM; i++) (*this)[i] -= rhs[i];
        return *this;
    }
    Hash &operator*=(const Hash &rhs) {
        for (int i = 0; i < NUM; i++) (*this)[i] *= rhs[i];
        return *this;
    }
    Hash &operator/=(const Hash &rhs) {
        for (int i = 0; i < NUM; i++) (*this)[i] /= rhs[i];
        return *this;
    }

    Hash operator+(const Hash &rhs) const { return Hash(*this) += rhs; }
    Hash operator-(const Hash &rhs) const { return Hash(*this) -= rhs; }
    Hash operator*(const Hash &rhs) const { return Hash(*this) *= rhs; }
    Hash operator/(const Hash &rhs) const { return Hash(*this) /= rhs; }
    Hash operator+() const { return *this; }
    Hash operator-() const { return Hash(0) - *this; }

    Hash pow(u64 n) const {
        Hash r;
        for (int i = 0; i < NUM; i++) r[i] = (*this)[i].pow(n);
        return r;
    }

    Hash inv() const {
        Hash r;
        for (int i = 0; i < NUM; i++) r[i] = (*this)[i].inv();
        return r;
    }
};

} // namespace random

} // namespace kk2

#endif // KK2_RANDOM_HASH_HPP
