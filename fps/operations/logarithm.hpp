#ifndef KK2_FPS_OPERATIONS_LOGARITHM_HPP
#define KK2_FPS_OPERATIONS_LOGARITHM_HPP 1

#include <cassert>
#include <utility>
#include <vector>

#include "../../math_mod/inv_table.hpp"
#include "../../type_traits/fps.hpp"
#include "../fps_sparsity_detector.hpp"

namespace kk2::fps::operations {

template <UnivariateFormalPowerSeries FPS> FPS &inplace_dense_log(FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    assert(!f.empty() && f[0] == mint(1));
    if (deg == -1) deg = static_cast<int>(f.size());
    if (deg == 0) {
        f.clear();
        return f;
    }

    FPS inverse = f.dense_inv(deg);
    return f.inplace_diff().inplace_dense_mul(inverse).inplace_pre(deg - 1).inplace_int();
}

template <UnivariateFormalPowerSeries FPS> FPS dense_log(const FPS &f, int deg = -1) {
    FPS result = f;
    return inplace_dense_log(result, deg);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_sparse_log(FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    using ivta = InvTable<mint>;
    assert(!f.empty() && f[0] == mint(1));
    if (deg == -1) deg = static_cast<int>(f.size());

    std::vector<std::pair<int, mint>> support;
    for (int i = 1; i < static_cast<int>(f.size()); ++i) {
        if (f[i] != mint(0)) support.emplace_back(i, f[i]);
    }
    ivta::set_upper(deg);

    f.assign(deg, mint(0));
    std::size_t next_support = 0;
    for (int k = 0; k < deg - 1; ++k) {
        for (const auto &[index, coefficient] : support) {
            if (k < index) break;
            const int i = k - index;
            f[k + 1] -= f[i + 1] * coefficient * (i + 1);
        }
        f[k + 1] *= ivta::inv(k + 1);
        while (next_support < support.size() && support[next_support].first < k + 1) ++next_support;
        if (next_support < support.size() && support[next_support].first == k + 1)
            f[k + 1] += support[next_support].second;
    }
    return f;
}

template <UnivariateFormalPowerSeries FPS> FPS sparse_log(const FPS &f, int deg = -1) {
    FPS result = f;
    return inplace_sparse_log(result, deg);
}

template <UnivariateFormalPowerSeries FPS> FPS log(const FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    assert(!f.empty() && f[0] == mint(1));
    if (is_sparse_operation(FPSOperation::LOG, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), deg))
        return sparse_log(f, deg);
    return dense_log(f, deg);
}

template <UnivariateFormalPowerSeries FPS> FPS &inplace_log(FPS &f, int deg = -1) {
    using mint = typename FPS::value_type;
    assert(!f.empty() && f[0] == mint(1));
    const bool use_sparse =
        is_sparse_operation(FPSOperation::LOG, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), deg);
    if (use_sparse) return inplace_sparse_log(f, deg);
    return inplace_dense_log(f, deg);
}

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_LOGARITHM_HPP
