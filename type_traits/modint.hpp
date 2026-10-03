#ifndef KK2_TYPE_TRAITS_MODINT_HPP
#define KK2_TYPE_TRAITS_MODINT_HPP 1

#include <concepts>

#include "integral.hpp"

namespace kk2::modint {

template <class M>
concept Modular = requires(M x) {
    requires Integral<decltype(M::getmod())>;
    x.val();
    { x.inv() } -> std::same_as<M>;
};

} // namespace kk2::modint

#endif // KK2_TYPE_TRAITS_MODINT_HPP
