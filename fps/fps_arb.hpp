#ifndef KK2_FPS_FPS_ARB_HPP
#define KK2_FPS_FPS_ARB_HPP 1

#include <cstdlib>

#include "fps_base.hpp"

namespace kk2 {

template <fps::Modular mint>
struct FormalPowerSeriesArbitrary : FormalPowerSeriesBase<FormalPowerSeriesArbitrary<mint>, mint> {
    using base = FormalPowerSeriesBase<FormalPowerSeriesArbitrary<mint>, mint>;
    using FPS = FormalPowerSeriesArbitrary<mint>;
    using base::FormalPowerSeriesBase;
    using base::operator*=; // 基底クラスのoperator*=を継承
    using modulus_category = kk2::fps::category::arbitrary_modulus;
    using series_category = kk2::fps::category::ordinary;
    using variable_category = kk2::fps::category::univariate;
    static constexpr bool is_ntt_friendly = false;

    void but() { exit(1); }
    void ibut() { exit(1); }
    void db() { exit(1); }
    static int but_pr() {
        exit(1);
        return 0;
    }
};

template <fps::Modular mint> using FPSArb = FormalPowerSeriesArbitrary<mint>;

} // namespace kk2

#endif // KK2_FPS_FPS_ARB_HPP
