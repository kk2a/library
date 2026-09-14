#ifndef KK2_FPS_FPS_SQRT_HPP
#define KK2_FPS_FPS_SQRT_HPP 1

#include "operations/sqrt.hpp"

namespace kk2 {

template <class FPS> FPS dense_sqrt(const FPS &f, int precision = -1) {
    return fps::operations::dense_sqrt(f, precision);
}

template <class FPS> FPS sparse_sqrt(const FPS &f, int precision = -1) {
    return fps::operations::sparse_sqrt(f, precision);
}

template <class FPS> FPS sqrt(const FPS &f, int precision = -1) {
    return fps::operations::sqrt(f, precision);
}

} // namespace kk2

#endif // KK2_FPS_FPS_SQRT_HPP
