#ifndef KK2_FPS_OPERATIONS_MULTIVARIATE_POWER_HPP
#define KK2_FPS_OPERATIONS_MULTIVARIATE_POWER_HPP 1

#include <cassert>

#include "../../../type_traits/fps.hpp"
#include "exponential.hpp"

namespace kk2::fps::operations {

template <Multivariate FPS> FPS dense_pow(const FPS &f, long long exponent) {
    using mint = typename FPS::value_type;
    assert(!f.f.empty());
    if (f.f[0] != mint(0)) {
        const mint constant_inverse = f.f[0].inv();
        const mint coefficient = f.f[0].pow(exponent);
        return (dense_exp(dense_log(f * constant_inverse) * exponent)) * coefficient;
    }
    const int n = f.f.size();
    long long base_sum = 0;
    for (auto bound : f.base) base_sum += bound - 1;
    if (exponent > base_sum) return FPS(f.base, typename FPS::fps(n));
    FPS result(f.base, typename FPS::fps(n)), factor = f;
    result.f[0] = 1;
    while (exponent) {
        if (exponent & 1) inplace_dense_mul(result, factor);
        if (exponent >>= 1) inplace_dense_mul(factor, factor);
    }
    return result;
}

template <Multivariate FPS> FPS &inplace_dense_pow(FPS &f, long long exponent) {
    return f = dense_pow(std::as_const(f), exponent);
}

template <Multivariate FPS> FPS sparse_pow(const FPS &f, long long exponent) {
    using mint = typename FPS::value_type;
    assert(!f.f.empty());
    if (f.f[0] != mint(0)) {
        const mint constant_inverse = f.f[0].inv();
        const mint coefficient = f.f[0].pow(exponent);
        return (sparse_exp(sparse_log(f * constant_inverse) * exponent)) * coefficient;
    }
    const int n = f.f.size();
    long long base_sum = 0;
    for (auto bound : f.base) base_sum += bound - 1;
    if (exponent > base_sum) return FPS(f.base, typename FPS::fps(n));
    FPS result(f.base, typename FPS::fps(n)), factor = f;
    result.f[0] = 1;
    while (exponent) {
        if (exponent & 1) inplace_sparse_mul(result, factor);
        if (exponent >>= 1) inplace_sparse_mul(factor, factor);
    }
    return result;
}

template <Multivariate FPS> FPS &inplace_sparse_pow(FPS &f, long long exponent) {
    return f = sparse_pow(std::as_const(f), exponent);
}

template <Multivariate FPS> FPS pow(const FPS &f, long long exponent) {
    return dense_pow(f, exponent);
}

template <Multivariate FPS> FPS &inplace_pow(FPS &f, long long exponent) {
    return inplace_dense_pow(f, exponent);
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_MULTIVARIATE_POWER_HPP
