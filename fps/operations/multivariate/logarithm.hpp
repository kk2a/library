#ifndef KK2_FPS_OPERATIONS_MULTIVARIATE_LOGARITHM_HPP
#define KK2_FPS_OPERATIONS_MULTIVARIATE_LOGARITHM_HPP 1

#include <cassert>

#include "../../../type_traits/fps.hpp"
#include "inverse.hpp"

namespace kk2::fps::operations {

template <Multivariate FPS> FPS dense_log(const FPS &f) {
    using mint = typename FPS::value_type;
    assert(!f.f.empty() && f.f[0] == mint(1));
    FPS result = dense_mul(f.diff(), dense_inv(f)).integral();
    result.f.resize(f.f.size());
    return result;
}

template <Multivariate FPS> FPS &inplace_dense_log(FPS &f) {
    return f = dense_log(std::as_const(f));
}

template <Multivariate FPS> FPS sparse_log(const FPS &f) {
    using mint = typename FPS::value_type;
    assert(!f.f.empty() && f.f[0] == mint(1));
    FPS result = sparse_mul(f.diff(), sparse_inv(f)).integral();
    result.f.resize(f.f.size());
    return result;
}

template <Multivariate FPS> FPS &inplace_sparse_log(FPS &f) {
    return f = sparse_log(std::as_const(f));
}

template <Multivariate FPS> FPS log(const FPS &f) { return dense_log(f); }

template <Multivariate FPS> FPS &inplace_log(FPS &f) { return inplace_dense_log(f); }

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_MULTIVARIATE_LOGARITHM_HPP
