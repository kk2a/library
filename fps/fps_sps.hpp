#ifndef KK2_FPS_FPS_SPS_HPP
#define KK2_FPS_FPS_SPS_HPP 1

#include <vector>

#include "fps_ntt_friendly.hpp"

namespace kk2 {

// Set Power Series indexed by subsets of a fixed ground set. The intended
// implementation uses the ranked zeta transform for subset convolution and
// the usual zeta/Möbius transforms for pointwise subset operations.
template <fps::Modular mint,
          template <fps::Modular> class UnivariateFPS = FormalPowerSeriesNTTFriendly>
struct SetPowerSeries {
    using sps = SetPowerSeries;
    using fps = UnivariateFPS<mint>;
    using value_type = mint;
    using modulus_category = typename fps::modulus_category;
    using series_category = kk2::fps::category::set_power_series;
    using iterator = typename std::vector<mint>::iterator;
    using const_iterator = typename std::vector<mint>::const_iterator;

    SetPowerSeries() = default;
    explicit SetPowerSeries(int dimension);

    int size() const;
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    mint &operator[](int subset);
    const mint &operator[](int subset) const;

    sps &operator+=(const sps &rhs);
    sps &operator-=(const sps &rhs);
    sps &operator*=(const sps &rhs);
    sps operator+(const sps &rhs) const;
    sps operator-(const sps &rhs) const;
    sps operator*(const sps &rhs) const;

    sps zeta() const;
    sps &inplace_zeta();
    sps mobius() const;
    sps &inplace_mobius();
    sps subset_convolution(const sps &rhs) const;
    sps &inplace_subset_convolution(const sps &rhs);
    sps ranked_subset_convolution(const sps &rhs) const;
    sps &inplace_ranked_subset_convolution(const sps &rhs);

    sps dense_mul(const sps &rhs) const;
    sps &inplace_dense_mul(const sps &rhs);
    sps sparse_mul(const sps &rhs) const;
    sps &inplace_sparse_mul(const sps &rhs);
    sps mul(const sps &rhs) const;
    sps &inplace_mul(const sps &rhs);
    sps dense_inv() const;
    sps &inplace_dense_inv();
    sps sparse_inv() const;
    sps &inplace_sparse_inv();
    sps inv() const;
    sps &inplace_inv();
    sps dense_log() const;
    sps &inplace_dense_log();
    sps sparse_log() const;
    sps &inplace_sparse_log();
    sps log() const;
    sps &inplace_log();
    sps dense_exp() const;
    sps &inplace_dense_exp();
    sps sparse_exp() const;
    sps &inplace_sparse_exp();
    sps exp() const;
    sps &inplace_exp();
    sps dense_pow(long long exponent) const;
    sps &inplace_dense_pow(long long exponent);
    sps sparse_pow(long long exponent) const;
    sps &inplace_sparse_pow(long long exponent);
    sps pow(long long exponent) const;
    sps &inplace_pow(long long exponent);
};

template <fps::Modular mint> using SPS = SetPowerSeries<mint>;

} // namespace kk2

#endif // KK2_FPS_FPS_SPS_HPP
