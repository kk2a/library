#ifndef FUNCTIONAL_REV_HPP
#define FUNCTIONAL_REV_HPP 1

#include "../type_traits/type_traits.hpp"

namespace kk2 {

// reverse_args<f>(y, x) = f(x, y)
template <auto f, std::enable_if_t<is_two_args_function_pointer<decltype(f)>::value> * = nullptr>
auto reverse_args(auto x, auto y) {
    return f(y, x);
}

} // namespace kk2

#endif // FUNCTIONAL_REV_HPP
