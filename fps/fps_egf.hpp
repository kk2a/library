#ifndef KK2_FPS_FPS_EGF_HPP
#define KK2_FPS_FPS_EGF_HPP 1

#include <vector>

#include "fps_ntt_friendly.hpp"

namespace kk2 {

// Exponential generating functions store coefficients in the basis x^n/n!.
// Multiplication is the binomial convolution; conversion to ordinary FPS by
// factorial scaling gives a simple baseline for inverse/log/exp/pow. Faster
// implementations can replace that conversion with a factorial-weighted NTT.
template <fps::Modular mint,
          template <fps::Modular> class UnivariateFPS = FormalPowerSeriesNTTFriendly>
struct ExponentialGeneratingFunction {
    using egf = ExponentialGeneratingFunction;
    using fps = UnivariateFPS<mint>;
    using value_type = mint;
    using modulus_category = typename fps::modulus_category;
    using series_category = kk2::fps::category::exponential_generating;
    using iterator = typename std::vector<mint>::iterator;
    using const_iterator = typename std::vector<mint>::const_iterator;

    ExponentialGeneratingFunction() = default;
    explicit ExponentialGeneratingFunction(int precision);

    int size() const;
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    mint &operator[](int index);
    const mint &operator[](int index) const;

    egf &operator+=(const egf &rhs);
    egf &operator-=(const egf &rhs);
    egf &operator*=(const egf &rhs);
    egf operator+(const egf &rhs) const;
    egf operator-(const egf &rhs) const;
    egf operator*(const egf &rhs) const;

    egf dense_mul(const egf &rhs) const;
    egf &inplace_dense_mul(const egf &rhs);
    egf sparse_mul(const egf &rhs) const;
    egf &inplace_sparse_mul(const egf &rhs);
    egf mul(const egf &rhs) const;
    egf &inplace_mul(const egf &rhs);
    egf dense_inv() const;
    egf &inplace_dense_inv();
    egf sparse_inv() const;
    egf &inplace_sparse_inv();
    egf inv() const;
    egf &inplace_inv();
    egf dense_log() const;
    egf &inplace_dense_log();
    egf sparse_log() const;
    egf &inplace_sparse_log();
    egf log() const;
    egf &inplace_log();
    egf dense_exp() const;
    egf &inplace_dense_exp();
    egf sparse_exp() const;
    egf &inplace_sparse_exp();
    egf exp() const;
    egf &inplace_exp();
    egf dense_pow(long long exponent) const;
    egf &inplace_dense_pow(long long exponent);
    egf sparse_pow(long long exponent) const;
    egf &inplace_sparse_pow(long long exponent);
    egf pow(long long exponent) const;
    egf &inplace_pow(long long exponent);
    egf dense_sqrt() const;
    egf &inplace_dense_sqrt();
    egf sparse_sqrt() const;
    egf &inplace_sparse_sqrt();
    egf sqrt() const;
    egf &inplace_sqrt();
};

template <fps::Modular mint> using EGF = ExponentialGeneratingFunction<mint>;

} // namespace kk2

#endif // KK2_FPS_FPS_EGF_HPP
