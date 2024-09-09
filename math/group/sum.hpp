#ifndef MATH_GROUP_SUM_HPP
#define MATH_GROUP_SUM_HPP 1

#include <iostream>
#include <vector>

namespace kk2 {

namespace group {

template <class S>
struct Sum {
    S a, size;
    Sum() : a(S()), size(0) {}
    Sum(S a, S size = 1) : a(a), size(size) {}
    operator S() const { return a; }
    friend std::ostream& operator<<(std::ostream& os, const Sum& sum) {
        os << sum.a;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Sum& sum) {
        is >> sum.a;
        sum.size = 1;
        return is;
    }
    Sum& operator=(const S& rhs) {
        a = rhs;
        size = 1;
        return *this;
    }

    Sum& add(const S& rhs) {
        a += rhs * size;
        return *this;
    }
    Sum& update(const S& rhs) {
        a = rhs * size;
        return *this;
    }
    Sum& multiply(const S& rhs) {
        a *= rhs;
        return *this;
    }
    Sum& op(const Sum& rhs) {
        a += rhs.a;
        size += rhs.size;
        return *this;
    }
};

template <class S>
Sum<S> SumOp(Sum<S> l, Sum<S> r) { return l.op(r); }

template <class S>
Sum<S> SumUnit() { return Sum<S>(); }

template <class S>
Sum<S> SumInv(Sum<S> x) { return Sum<S>(-x.a, -x.size); }

} // namespace group

template <class S, class... Args>
std::vector<group::Sum<S>> GetVecSum(int n, Args... args) {
    return std::vector<group::Sum<S>>(n, group::Sum<S>(args...));
}

} // namespace kk2

#endif // MATH_GROUP_SUM_HPP
