#ifndef OTHERS_MONOID_MIN_HPP
#define OTHERS_MONOID_MIN_HPP 1

namespace monoid {

template <class S>
struct Min {
    S a;
    bool inf;
    Min() : a(0), inf(true) {}
    Min(S a_, bool inf_ = false) : a(a_), inf(inf_) {}
    operator S() const { return a; }
    friend ostream& operator<<(ostream& os, const Min& min) {
        os << (min.inf ? "inf" : to_string(min.a));
        return os;
    }
    friend istream& operator>>(istream& is, Min& min) {
        is >> min.a;
        min.inf = false;
        return is;
    }
    Min& operator=(const S& rhs) {
        a = rhs;
        inf = false;
        return *this;
    }

    Min& add(const S& rhs) {
        if (inf) return *this;
        a += rhs;
        return *this;
    }
    Min& update(const S& rhs) {
        a = rhs;
        inf = false;
        return *this;
    }
    Min& op(const Min& rhs) {
        if (rhs.inf) return *this;
        if (inf) return *this = rhs;
        a = min(a, rhs.a);
        return *this;
    }

    bool is_inf() const { return inf; }
};

template <class S>
Min<S> MinOp(Min<S> l, Min<S> r) { return l.op(r); }

template <class S>
Min<S> MinUnit() { return Min<S>(); }

} // namespace monoid

template <class S, class... Args>
vector<monoid::Min<S>> GetVecMin(int n, Args... args) {
    return vector<monoid::Min<S>>(n, monoid::Min<S>(args...));
}


#endif // OTHERS_MONOID_MIN_HPP
