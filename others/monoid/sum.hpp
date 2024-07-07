#ifndef OTHERS_MONOID_SUM_HPP
#define OTHERS_MONOID_SUM_HPP 1

namespace monoid {

template <class S>
struct Sum {
    S a, size;
    Sum() : a(0), size(0) {}
    Sum(S a, S size = 1) : a(a), size(size) {}
    operator S() const { return a; }
    friend ostream& operator<<(ostream& os, const Sum& sum) {
        os << sum.a;
        return os;
    }
    friend istream& operator>>(istream& is, Sum& sum) {
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

} // namespace monoid

template <class S, class... Args>
vector<monoid::Sum<S>> GetVecSum(int n, Args... args) {
    return vector<monoid::Sum<S>>(n, monoid::Sum<S>(args...));
}

#endif // OTHERS_MONOID_SUM_HPP
