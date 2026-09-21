#ifndef KK2_FPS_FPS_BIVARIATE_HPP
#define KK2_FPS_FPS_BIVARIATE_HPP 1

#include <vector>

#include "fps_ntt_friendly.hpp"

namespace kk2 {

// A rectangular bivariate FPS. The implementation can use either the
// Kronecker-substitution/2-D NTT product or a truncated 2-D convolution.
// Inversion is naturally implemented by Newton iteration, while log/exp/pow
// follow from the formal derivative and integral in the two coordinates.
template <fps::Modular mint,
          template <fps::Modular> class UnivariateFPS = FormalPowerSeriesNTTFriendly>
struct BivariateFormalPowerSeries {
    using bfps = BivariateFormalPowerSeries;
    using fps = UnivariateFPS<mint>;
    using value_type = mint;
    using modulus_category = typename fps::modulus_category;
    using series_category = kk2::fps::category::ordinary;
    using variable_category = kk2::fps::category::bivariate;
    using iterator = typename std::vector<mint>::iterator;
    using const_iterator = typename std::vector<mint>::const_iterator;

    BivariateFormalPowerSeries() = default;
    BivariateFormalPowerSeries(int x_size, int y_size);

    int size() const;
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    mint &operator[](int index);
    const mint &operator[](int index) const;
    mint &operator()(int x, int y);
    const mint &operator()(int x, int y) const;

    bfps &operator+=(const bfps &rhs);
    bfps &operator-=(const bfps &rhs);
    bfps &operator*=(const bfps &rhs);
    bfps &operator+=(const mint &rhs);
    bfps &operator-=(const mint &rhs);
    bfps &operator*=(const mint &rhs);
    bfps &operator/=(const mint &rhs);
    bfps operator+(const bfps &rhs) const;
    bfps operator-(const bfps &rhs) const;
    bfps operator*(const bfps &rhs) const;
    bfps operator+(const mint &rhs) const;
    bfps operator-(const mint &rhs) const;
    bfps operator*(const mint &rhs) const;
    bfps operator/(const mint &rhs) const;

    bfps dense_mul(const bfps &rhs) const;
    bfps &inplace_dense_mul(const bfps &rhs);
    bfps sparse_mul(const bfps &rhs) const;
    bfps &inplace_sparse_mul(const bfps &rhs);
    bfps mul(const bfps &rhs) const;
    bfps &inplace_mul(const bfps &rhs);
    bfps dense_inv() const;
    bfps &inplace_dense_inv();
    bfps sparse_inv() const;
    bfps &inplace_sparse_inv();
    bfps inv() const;
    bfps &inplace_inv();
    bfps dense_log() const;
    bfps &inplace_dense_log();
    bfps sparse_log() const;
    bfps &inplace_sparse_log();
    bfps log() const;
    bfps &inplace_log();
    bfps dense_exp() const;
    bfps &inplace_dense_exp();
    bfps sparse_exp() const;
    bfps &inplace_sparse_exp();
    bfps exp() const;
    bfps &inplace_exp();
    bfps dense_pow(long long exponent) const;
    bfps &inplace_dense_pow(long long exponent);
    bfps sparse_pow(long long exponent) const;
    bfps &inplace_sparse_pow(long long exponent);
    bfps pow(long long exponent) const;
    bfps &inplace_pow(long long exponent);
    bfps dense_sqrt() const;
    bfps &inplace_dense_sqrt();
    bfps sparse_sqrt() const;
    bfps &inplace_sparse_sqrt();
    bfps sqrt() const;
    bfps &inplace_sqrt();

    bfps diff_x() const;
    bfps &inplace_diff_x();
    bfps diff_y() const;
    bfps &inplace_diff_y();
    bfps integral_x() const;
    bfps &inplace_integral_x();
    bfps integral_y() const;
    bfps &inplace_integral_y();
};

template <fps::Modular mint> using BivariateFPS = BivariateFormalPowerSeries<mint>;

} // namespace kk2

#endif // KK2_FPS_FPS_BIVARIATE_HPP
