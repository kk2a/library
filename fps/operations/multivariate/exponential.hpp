#ifndef KK2_FPS_OPERATIONS_MULTIVARIATE_EXPONENTIAL_HPP
#define KK2_FPS_OPERATIONS_MULTIVARIATE_EXPONENTIAL_HPP 1

#include <algorithm>
#include <cassert>

#include "../../../type_traits/fps.hpp"
#include "logarithm.hpp"

namespace kk2::fps::operations {

template <Multivariate FPS> FPS dense_exp(const FPS &f) {
    using mint = typename FPS::value_type;
    assert(!f.f.empty() && f.f[0] == mint(0));
    const int n = f.f.size();
    FPS result(f.base, typename FPS::fps{1});
    for (int d = 1; d < n; d <<= 1) {
        const int precision = std::min(n, 2 * d);
        result.f.resize(precision, mint(0));
        FPS target(f.base, typename FPS::fps(std::begin(f.f), std::begin(f.f) + precision));
        FPS correction = target - dense_log(result);
        correction += mint(1);
        inplace_dense_mul(result, correction);
    }
    return result;
}

template <Multivariate FPS> FPS &inplace_dense_exp(FPS &f) {
    return f = dense_exp(std::as_const(f));
}

template <Multivariate FPS> FPS sparse_exp(const FPS &f) {
    using mint = typename FPS::value_type;
    assert(!f.f.empty() && f.f[0] == mint(0));
    const int n = f.f.size();
    FPS result(f.base, typename FPS::fps{1});
    for (int d = 1; d < n; d <<= 1) {
        const int precision = std::min(n, 2 * d);
        result.f.resize(precision, mint(0));
        FPS target(f.base, typename FPS::fps(std::begin(f.f), std::begin(f.f) + precision));
        FPS correction = target - sparse_log(result);
        correction += mint(1);
        inplace_sparse_mul(result, correction);
    }
    return result;
}

template <Multivariate FPS> FPS &inplace_sparse_exp(FPS &f) {
    return f = sparse_exp(std::as_const(f));
}

template <Multivariate FPS> FPS exp(const FPS &f) { return dense_exp(f); }

template <Multivariate FPS> FPS &inplace_exp(FPS &f) { return inplace_dense_exp(f); }

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_MULTIVARIATE_EXPONENTIAL_HPP
