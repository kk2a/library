#ifndef KK2_TYPE_TRAITS_FPS_HPP
#define KK2_TYPE_TRAITS_FPS_HPP 1

#include <concepts>
#include <ranges>
#include <type_traits>

namespace kk2::fps {

namespace category {

struct arbitrary_modulus {};
struct ntt_friendly_modulus {};

struct ordinary {};
struct exponential_generating {};
struct set_power_series {};

struct univariate {};
struct bivariate {};
struct multivariate {};

} // namespace category

template <class M>
concept Modular = requires(M x) {
    { M::getmod() } -> std::integral;
    x.val();
    { x.inv() } -> std::same_as<M>;
};

template <class F>
concept FormalPowerSeries = requires(const F &f, int i) {
    typename F::value_type;
    typename F::modulus_category;
    typename F::series_category;
    { f.size() } -> std::integral;
    f[i];
} && std::ranges::range<const F>;

template <class F>
concept NTTFriendlyFormalPowerSeries =
    FormalPowerSeries<F>
    && std::same_as<typename F::modulus_category, category::ntt_friendly_modulus>;

template <class F>
concept ArbitraryModulusFormalPowerSeries =
    FormalPowerSeries<F> && std::same_as<typename F::modulus_category, category::arbitrary_modulus>;

template <class F>
concept OrdinaryFormalPowerSeries =
    FormalPowerSeries<F> && std::same_as<typename F::series_category, category::ordinary>;

template <class F>
concept ExponentialGeneratingFunction =
    FormalPowerSeries<F>
    && std::same_as<typename F::series_category, category::exponential_generating>;

template <class F>
concept SetPowerSeries =
    FormalPowerSeries<F> && std::same_as<typename F::series_category, category::set_power_series>;

template <class F>
concept UnivariateFormalPowerSeries = FormalPowerSeries<F> && requires {
    typename F::variable_category;
} && std::same_as<typename F::variable_category, category::univariate>;

template <class F>
concept BivariateFormalPowerSeries = FormalPowerSeries<F> && requires {
    typename F::variable_category;
} && std::same_as<typename F::variable_category, category::bivariate>;

template <class F>
concept MultivariateFormalPowerSeries = FormalPowerSeries<F> && requires {
    typename F::variable_category;
} && std::same_as<typename F::variable_category, category::multivariate>;

// Short names for the categories that are commonly used in algorithms.
template <class F>
concept SPS = SetPowerSeries<F>;

template <class F>
concept EGF = ExponentialGeneratingFunction<F>;

template <class F>
concept Bivariate = BivariateFormalPowerSeries<F>;

template <class F>
concept Multivariate = MultivariateFormalPowerSeries<F>;

} // namespace kk2::fps

#endif // KK2_TYPE_TRAITS_FPS_HPP
