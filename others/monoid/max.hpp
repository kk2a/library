#ifndef OTHERS_MONOID_MAX_HPP
#define OTHERS_MONOID_MAX_HPP 1

namespace monoid {

template <class S>
struct Max {
    S a;
    bool minf;
    Max() : a(0), minf(true) {}
    Max (S a_, bool minf_ = false) : a(a_), minf(minf_) {}
    operator S() const { return a; }
    friend ostream& operator<<(ostream& os, const Max& max) {
        os << (max.minf ? "minf" : to_string(max.a));
        return os;
    }
    friend istream& operator>>(istream& is, Max& max) {
        is >> max.a;
        max.minf = false;
        return is;
    }
    Max& operator=(const S& rhs) {
        a = rhs;
        minf = false;
        return *this;
    }

    Max& add(const S& rhs) {
        if (minf) return *this;
        a += rhs;
        return *this;
    }
    Max& update(const S& rhs) {
        a = rhs;
        minf = false;
        return *this;
    }
    Max& op(const Max& rhs) {
        if (rhs.minf) return *this;
        if (minf) return *this = rhs;
        a = max(a, rhs.a);
        return *this;
    }

    bool is_minf() const { return minf; }
};

template <class S>
Max<S> MaxOp(Max<S> l, Max<S> r) { return l.op(r); }

template <class S>
Max<S> MaxUnit() { return Max<S>(); }

} // namespace monoid

template <class S, class... Args>
vector<monoid::Max<S>> GetVecMax(int n, Args... args) {
    return vector<monoid::Max<S>>(n, monoid::Max<S>(args...));
}

#endif // OTHERS_MONOID_MAX_HPP
