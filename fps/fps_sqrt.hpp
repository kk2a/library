#ifndef KK2_FPS_FPS_SQRT_HPP
#define KK2_FPS_FPS_SQRT_HPP 1

#include <cassert>

#include "../math_mod/mod_sqrt.hpp"
#include "fps_sparsity_detector.hpp"
#include "../type_traits/fps.hpp"

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type> FPS dense_sqrt(const FPS &f, int deg = -1) {
    if (deg == -1) deg = (int)f.size();
    if ((int)f.size() == 0) return FPS(deg, mint(0));
    if (f[0] == mint(0)) {
        for (int i = 1; i < (int)f.size(); i++) {
            if (f[i] != mint(0)) {
                if (i & 1) return {};
                if (deg - i / 2 <= 0) break;
                auto ret = dense_sqrt(f >> i, deg - i / 2);
                if (ret.empty()) return {};
                ret = ret << (i / 2);
                if ((int)ret.size() < deg) ret.resize(deg, mint(0));
                return ret;
            }
        }
        return FPS(deg, mint(0));
    }

    long long sqr = mod_sqrt(f[0].val(), mint::getmod());
    if (sqr == -1) return {};
    assert(sqr * sqr % mint::getmod() == f[0].val());
    FPS ret = {mint(sqr)};
    mint inv2 = mint(2).inv();
    for (int i = 1; i < deg; i <<= 1) {
        ret = (ret + f.pre(i << 1).dense_mul(ret.dense_inv(i << 1))) * inv2;
    }
    return ret.pre(deg);
}

template <class FPS, class mint = typename FPS::value_type>
FPS sparse_sqrt(const FPS &f, int deg = -1) {
    // using mint = typename FPS::value_type;
    if (deg == -1) deg = (int)f.size();
    if ((int)f.size() == 0) return FPS(deg, mint(0));
    if (f[0] == mint(0)) {
        for (int i = 1; i < (int)f.size(); i++) {
            if (f[i] != mint(0)) {
                if (i & 1) return {};
                if (deg - i / 2 <= 0) break;
                auto ret = sparse_sqrt(f >> i, deg - i / 2);
                if (ret.empty()) return {};
                ret = ret << (i / 2);
                if ((int)ret.size() < deg) ret.resize(deg, mint(0));
                return ret;
            }
        }
        return FPS(deg, mint(0));
    }
    long long sqr = mod_sqrt(f[0].val(), mint::getmod());
    if (sqr == -1) return {};
    return f.sparse_pow(((mint::getmod() + 1) >> 1), deg) * mint(sqr).inv();
}

template <class FPS, class mint = typename FPS::value_type> FPS sqrt(const FPS &f, int deg = -1) {
    if (deg == -1) deg = (int)f.size();
    if (!f.empty() && f[0] != mint(0)
        && is_sparse_operation(FPSOperation::SQRT, fps::NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), deg))
        return sparse_sqrt(f, deg);
    return dense_sqrt(f, deg);
}

} // namespace kk2

#endif // KK2_FPS_FPS_SQRT_HPP
