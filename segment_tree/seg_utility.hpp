#ifndef SEG_UTILITY_HPP
#define SEG_UTILITY_HPP 1

#include "seg.hpp"
#include "lazy.hpp"

namespace seg_utility {

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

    Sum& operator+=(const S& rhs) {
        a += rhs * size;
        return *this;
    }
    Sum& operator=(const S& rhs) {
        a = rhs * size;
        return *this;
    }
    Sum& operator*=(const S& rhs) {
        a *= rhs;
        return *this;
    }

    friend Sum operator+(const Sum& lhs, const S& rhs) {
        return Sum(lhs) += rhs;
    }
    friend Sum operator*(const Sum& lhs, const S& rhs) {
        return Sum(lhs) *= rhs;
    }
};

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

    Max& operator+=(const S& rhs) {
        a += rhs;
        return *this;
    }
    Max& operator=(const S& rhs) {
        a = rhs;
        minf = false;
        return *this;
    }

    friend Max operator+(const Max& lhs, const S& rhs) {
        return Max(lhs) += rhs;
    }

    bool is_minf() const { return minf; }
};

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

    Min& operator+=(const S& rhs) {
        a += rhs;
        return *this;
    }
    Min& operator=(const S& rhs) {
        a = rhs;
        inf = false;
        return *this;
    }

    friend Min operator+(const Min& lhs, const S& rhs) {
        return Min(lhs) += rhs;
    }

    bool is_inf() const { return inf; }
};

template <class S>
struct Update {
    S a;
    bool id;
    Update() : a(0), id(true) {}
    Update(S a_, bool id_ = false) : a(a_), id(id_) {}
    operator S() const { return a; }
    friend ostream& operator<<(ostream& os, const Update& update) {
        os << (update.id ? "id" : to_string(update.a));
        return os;
    }
};

template <class S>
struct Affine {
    S a, b; // x \mapsto ax + b
    Affine() : a(1), b(0) {};
    Affine(S a, S b) : a(a), b(b) {}
    friend ostream& operator<<(ostream& os, const Affine& aff) {
        os << aff.a << " " << aff.b;
        return os;
    }
};

template <class S>
Max<S> MaxOp(Max<S> l, Max<S> r) {
    return l.minf ? r : (r.minf ? l : Max<S>(max(l.a, r.a)));
}

template <class S>
Min<S> MinOp(Min<S> l, Min<S> r) {
    return l.inf ? r : (r.inf ? l : Min<S>(min(l.a, r.a)));
}

template <class S>
Sum<S> SumOp(Sum<S> l, Sum<S> r) {
    return Sum<S>(l.a + r.a, l.size + r.size);
}

template <class Add, class T>
T AddMap(Add f, T x) {
    return x + f;
}

template <class Add>
Add AddComposition(Add l, Add r) {
    return l + r;
}

template <class S, class T>
T UpdMap(Update<S> f, T x) {
    return f.id ? x : x = f.a;
}

template <class S>
Update<S> UpdComposition(Update<S> l, Update<S> r) {
    return l.id ? r : l;
}

template <class S, class T>
T AffMap(Affine<S> f, T x) {
    return x * f.a + f.b;
}

template <class S>
Affine<S> AffComposition(Affine<S> l, Affine<S> r) {
    return Affine<S>(l.a * r.a, l.a * r.b + l.b);
}

template <class S>
S Unit() { return S(); }

// seg
template <class S>
using MaxSeg = SegTree<Max<S>, MaxOp<S>, Unit<Max<S>>>;
template <class S>
using MinSeg = SegTree<Min<S>, MinOp<S>, Unit<Min<S>>>;
template <class S>
using SumSeg = SegTree<Sum<S>, SumOp<S>, Unit<Sum<S>>>;

// lazy
template <class S>
using AddMax = LazySegTree<Max<S>, MaxOp<S>, Unit<Max<S>>,
                           S, AddMap<S, Max<S>>, AddComposition<S>, Unit<S>>;
template <class S>
using AddMin = LazySegTree<Min<S>, MinOp<S>, Unit<Min<S>>,
                           S, AddMap<S, Min<S>>, AddComposition<S>, Unit<S>>;
template <class S>
using AddSum = LazySegTree<Sum<S>, SumOp<S>, Unit<Sum<S>>,
                           S, AddMap<S, Sum<S>>, AddComposition<S>, Unit<S>>;
template <class S>
using UpdateMax = LazySegTree<Max<S>, MaxOp<S>, Unit<Max<S>>,
                              Update<S>, UpdMap<S, Max<S>>, UpdComposition<S>, Unit<Update<S>>>;
template <class S>
using UpdateMin = LazySegTree<Min<S>, MinOp<S>, Unit<Min<S>>,
                              Update<S>, UpdMap<S, Min<S>>, UpdComposition<S>, Unit<Update<S>>>;
template <class S>
using UpdateSum = LazySegTree<Sum<S>, SumOp<S>, Unit<Sum<S>>,
                              Update<S>, UpdMap<S, Sum<S>>, UpdComposition<S>, Unit<Update<S>>>;
template <class S>
using AffineSum = LazySegTree<Sum<S>, SumOp<S>, Unit<Sum<S>>,
                              Affine<S>, AffMap<S, Sum<S>>, AffComposition<S>, Unit<Affine<S>>>;

template <class S, class... Args>
vector<S> GetVector(int n, Args... args) { return vector<S>(n, S(args...)); }

template <class S, class... Args>
vector<Max<S>> GetVectorMax(int n, Args... args) { return vector<Max<S>>(n, Max<S>(args...)); }

template <class S, class... Args>
vector<Min<S>> GetVectorMin(int n, Args... args) { return vector<Min<S>>(n, Min<S>(args...)); }

template <class S, class... Args>
vector<Sum<S>> GetVectorSum(int n, Args... args) { return vector<Sum<int>>(n, Sum<S>(args...)); }

} // namespace seg_utility

using seg_utility::MaxSeg;
using seg_utility::MinSeg;
using seg_utility::SumSeg;

using seg_utility::AddMax;
using seg_utility::AddMin;
using seg_utility::AddSum;
using seg_utility::UpdateMax;
using seg_utility::UpdateMin;
using seg_utility::UpdateSum;
using seg_utility::AffineSum;



#endif // SEG_UTILITY_HPP
