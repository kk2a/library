#ifndef KK2_CONVOLUTION_CONVOLUTION_HPP
#define KK2_CONVOLUTION_CONVOLUTION_HPP 1

#include <algorithm>
#include <memory>
#include <utility>
#include <vector>

#include "../fps/fps_sparsity_detector.hpp"
#include "../math_mod/butterfly.hpp"

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type>
FPS &inplace_sparse_convolution(FPS &a, const FPS &b, int deg = -1) {
    const int original_a_size = a.size(), original_b_size = b.size();
    if (!original_a_size || !original_b_size) {
        a.clear();
        return a;
    }
    if (deg == -1) deg = original_a_size + original_b_size - 1;
    const int target = std::min(std::max(0, deg), original_a_size + original_b_size - 1);
    if (target == 0) {
        a.clear();
        return a;
    }

    std::vector<std::pair<int, mint>> support_b;
    for (int i = 0; i < std::min(original_b_size, target); ++i) {
        if (b[i] != mint(0)) support_b.emplace_back(i, b[i]);
    }
    a.resize(target);
    for (int i = std::min(original_a_size, target) - 1; i >= 0; --i) {
        const mint coefficient = a[i];
        a[i] = mint(0);
        if (coefficient == mint(0)) continue;
        for (const auto &[j, b_j] : support_b) {
            if (i + j >= target) break;
            a[i + j] += coefficient * b_j;
        }
    }
    return a;
}

template <class FPS> FPS sparse_convolution(const FPS &a, const FPS &b, int deg = -1) {
    FPS result = a;
    inplace_sparse_convolution(result, b, deg);
    return result;
}

template <class FPS> FPS &inplace_dense_convolution(FPS &a, const FPS &b, int deg = -1) {
    const int original_a_size = a.size(), original_b_size = b.size();
    if (!original_a_size || !original_b_size) {
        a.clear();
        return a;
    }
    if (deg == -1) deg = original_a_size + original_b_size - 1;
    const int target = std::min(std::max(0, deg), original_a_size + original_b_size - 1);
    if (target == 0) {
        a.clear();
        return a;
    }

    const int n = std::min(original_a_size, target);
    const int m = std::min(original_b_size, target);

    int z = 1;
    while (z < n + m - 1) z <<= 1;
    if (std::addressof(a) == std::addressof(b)) {
        a.resize(n);
        a.resize(z);
        butterfly(a);
        for (int i = 0; i < z; i++) a[i] *= a[i];
    } else {
        a.resize(n);
        a.resize(z);
        butterfly(a);
        FPS t(b.begin(), b.begin() + m);
        t.resize(z);
        butterfly(t);
        for (int i = 0; i < z; i++) a[i] *= t[i];
    }
    butterfly_inv(a);
    a.resize(target);
    return a;
}

template <class FPS> FPS dense_convolution(const FPS &a, const FPS &b, int deg = -1) {
    FPS result = a;
    inplace_dense_convolution(result, b, deg);
    return result;
}

template <class FPS> FPS &inplace_convolution(FPS &a, const FPS &b, int deg = -1) {
    const bool use_sparse = is_sparse_operation(FPSOperation::CONVOLUTION, true, a, b, deg);
    if (use_sparse) return inplace_sparse_convolution(a, b, deg);
    return inplace_dense_convolution(a, b, deg);
}

template <class FPS> FPS convolution(const FPS &a, const FPS &b, int deg = -1) {
    if (is_sparse_operation(FPSOperation::CONVOLUTION, true, a, b, deg))
        return sparse_convolution(a, b, deg);
    return dense_convolution(a, b, deg);
}

} // namespace kk2

#endif // KK2_CONVOLUTION_CONVOLUTION_HPP
