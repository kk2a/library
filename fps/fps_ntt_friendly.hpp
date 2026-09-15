#ifndef KK2_FPS_FPS_NTT_FRIENDLY_HPP
#define KK2_FPS_FPS_NTT_FRIENDLY_HPP 1

#include "../math_mod/butterfly.hpp"
#include "fps_base.hpp"

namespace kk2 {

template <fps::Modular mint>
struct FormalPowerSeriesNTTFriendly
    : FormalPowerSeriesBase<FormalPowerSeriesNTTFriendly<mint>, mint> {
    using base = FormalPowerSeriesBase<FormalPowerSeriesNTTFriendly<mint>, mint>;
    using FPS = FormalPowerSeriesNTTFriendly<mint>;
    using base::FormalPowerSeriesBase;
    using base::operator*=; // 基底クラスのoperator*=を継承
    using modulus_category = kk2::fps::category::ntt_friendly_modulus;
    using series_category = kk2::fps::category::ordinary;
    using variable_category = kk2::fps::category::univariate;
    static constexpr bool is_ntt_friendly = true;

    void but() { butterfly(*this); }
    void ibut() { butterfly_inv(*this); }
    void db() { doubling(*this); }
    static int but_pr() { return primitive_root<mint::getmod()>; }
};

template <fps::Modular mint> using FPSNTT = FormalPowerSeriesNTTFriendly<mint>;

} // namespace kk2

#endif // KK2_FPS_FPS_NTT_FRIENDLY_HPP
