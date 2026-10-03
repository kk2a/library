// competitive-verifier: STANDALONE

#include "../../../../type_traits/fps.hpp"

#include <vector>

#include "../../../../fps/fps_arb.hpp"
#include "../../../../fps/fps_bivariate.hpp"
#include "../../../../fps/fps_egf.hpp"
#include "../../../../fps/fps_multivariate.hpp"
#include "../../../../fps/fps_ntt_friendly.hpp"
#include "../../../../fps/fps_sps.hpp"
#include "../../../../modint/mont.hpp"

using NTTFPS = kk2::FPSNTT<kk2::mont998>;
using ArbFPS = kk2::FPSArb<kk2::mont998>;
using MFPS = kk2::MultivariateFormalPowerSeries<kk2::mont998>;
using MFPSArb = kk2::MultivariateFormalPowerSeriesArbitrary<kk2::mont107>;
using BFPS = kk2::BivariateFormalPowerSeries<kk2::mont998>;
using SPS = kk2::SetPowerSeries<kk2::mont998>;
using EGF = kk2::ExponentialGeneratingFunction<kk2::mont998>;

struct FutureSPS : std::vector<int> {
    using std::vector<int>::vector;
    using value_type = int;
    using modulus_category = kk2::fps::category::arbitrary_modulus;
    using series_category = kk2::fps::category::set_power_series;
};

struct FutureEGFBivariate : std::vector<int> {
    using std::vector<int>::vector;
    using value_type = int;
    using modulus_category = kk2::fps::category::arbitrary_modulus;
    using series_category = kk2::fps::category::exponential_generating;
    using variable_category = kk2::fps::category::bivariate;
};

static_assert(kk2::fps::Modular<kk2::mont998>);
static_assert(kk2::fps::FormalPowerSeries<NTTFPS>);
static_assert(kk2::fps::NTTFriendlyFormalPowerSeries<NTTFPS>);
static_assert(kk2::fps::OrdinaryFormalPowerSeries<NTTFPS>);
static_assert(kk2::fps::UnivariateFormalPowerSeries<NTTFPS>);
static_assert(!kk2::fps::ArbitraryModulusFormalPowerSeries<NTTFPS>);

static_assert(kk2::fps::ArbitraryModulusFormalPowerSeries<ArbFPS>);
static_assert(kk2::fps::FormalPowerSeries<MFPS>);
static_assert(kk2::fps::MultivariateFormalPowerSeries<MFPS>);
static_assert(kk2::fps::FormalPowerSeries<MFPSArb>);
static_assert(kk2::fps::ArbitraryModulusFormalPowerSeries<MFPSArb>);
static_assert(kk2::fps::MultivariateFormalPowerSeries<MFPSArb>);

static_assert(kk2::fps::BivariateFormalPowerSeries<BFPS>);
static_assert(kk2::fps::SetPowerSeries<SPS>);
static_assert(kk2::fps::ExponentialGeneratingFunction<EGF>);
static_assert(kk2::fps::Bivariate<BFPS>);
static_assert(kk2::fps::SPS<SPS>);
static_assert(kk2::fps::EGF<EGF>);

static_assert(kk2::fps::SetPowerSeries<FutureSPS>);
static_assert(kk2::fps::SPS<FutureSPS>);
static_assert(kk2::fps::EGF<FutureEGFBivariate>);
static_assert(kk2::fps::Bivariate<FutureEGFBivariate>);
static_assert(!kk2::fps::Multivariate<FutureEGFBivariate>);

int main() {}
