#ifndef KK2_FUNCTIONAL_REVERSE_ARGS_HPP
#define KK2_FUNCTIONAL_REVERSE_ARGS_HPP 1

#include "../type_traits/functional.hpp"

namespace kk2 {

// reverse_args<f>(y, x) = f(x, y)
template <auto f, is_two_args_function_pointer_t<decltype(f)> * = nullptr>
inline auto reverse_args(auto x, auto y) {
    return f(y, x);
}

} // namespace kk2

#endif // KK2_FUNCTIONAL_REVERSE_ARGS_HPP
