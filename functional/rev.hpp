#ifndef FUNCTIONAL_REV_HPP
#define FUNCTIONAL_REV_HPP 1

namespace kk2 {

template <class R, class T1, class T2, R (*f)(T1, T2)> R rev(T2 x, T1 y) {
    return f(y, x);
}

} // namespace kk2

#endif // FUNCTIONAL_REV_HPP
