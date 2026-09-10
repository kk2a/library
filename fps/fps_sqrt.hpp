#ifndef KK2_FPS_FPS_SQRT_HPP
#define KK2_FPS_FPS_SQRT_HPP 1

#include "operations/sqrt.hpp"

namespace kk2 {

template <class FPS> FPS dense_sqrt(const FPS &f, int deg = -1) {
    return fps::operations::dense_sqrt(f, deg);
}

template <class FPS> FPS sparse_sqrt(const FPS &f, int deg = -1) {
    return fps::operations::sparse_sqrt(f, deg);
}

template <class FPS> FPS sqrt(const FPS &f, int deg = -1) { return fps::operations::sqrt(f, deg); }

} // namespace kk2

#endif // KK2_FPS_FPS_SQRT_HPP
