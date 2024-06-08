#ifndef SEG_UTILITY_HPP
#define SEG_UTILITY_HPP 1

#include "lazy.hpp"

namespace seg_utility {

template <class S>
struct Sum {
    S a, size;
    Sum() = default;
    Sum(S a, S size = 1) : a(a), size(size) {}
    operator S() const { return a; }
    friend ostream& operator<<(ostream& os, const Sum& aff) {
        os << aff.a;
        return os;
    }
};

template <class S>
Sum<S> gen_sum(S a) {
    return Sum<S>(a, 1);
}

template <class S>
Sum<S> gen_sum() {
    return Sum<S>(0, 1);
}

template <class S>
vector<Sum<S>> gen_sum(vector<S> a) {
    vector<Sum<S>> res;
    for (auto x : a) res.push_back(gen_sum(x));
    return res;
}

template <class S>
struct Affine {
    S a, b;
    Affine() = default;
    Affine(S a, S b) : a(a), b(b) {}
    friend ostream& operator<<(ostream& os, const Affine& aff) {
        os << aff.a << " " << aff.b;
        return os;
    }
};

template <class S>
Affine<S> gen_aff(S a, S b) {
    return Affine<S>(a, b);
}

template <class S>
Affine<S> gen_aff() {
    return Affine<S>(1, 0);
}

template <class S>
S Mx(S a, S b) {
    return max(a, b);
}

template <class S>
S Mn(S a, S b) {
    return min(a, b);
}

template <class S>
Sum<S> Sm(Sum<S> a, Sum<S> b) {
    return Sum<S>(a.a + b.a, a.size + b.size);
}

template <class S>
S Add(S a, S b) {
    return a + b;
}

template <class S, S ID>
S Update(S a, S b) {
    return a == ID ? b : a;
}

template <class S>
S Aff(Affine<S> aff, S x) {
    return aff.a * x + aff.b;
}

template <class S>
Affine<S> AffCompositon(Affine<S> a, Affine<S> b) {
    return Affine<S>(a.a * b.a, a.a * b.b + a.b);
}

template <class S>
Sum<S> AddSm(S a, Sum<S> b) {
    return Sum<S>(b.a + a * b.size, b.size);
}

template <class S, S ID>
Sum<S> UpdateSm(S a, Sum<S> b) {
    return Sum<S>(a == ID ? b.a : a, b.size);
}

template <class S>
Sum<S> AffSm(Affine<S> aff, Sum<S> x) {
    return Sum<S>(aff.a * x.a + aff.b * x.size, x.size);
}

template <class S, S e>
S Const() { return e; }

template <class S>
S Zero() { return S(); }

template <class S>
Sum<S> ZeroSm() { return Sum<S>(0, 1); }

template <class S>
Affine<S> Id() { return Affine<S>(1, 0); }

template <class S, S MINF>
using AddMax = LazySegTree<S, Mx<S>, Const<S, MINF>,
    S, Add<S>, Add<S>, Zero<S>>;

template <class S, S MINF, S ID>
using UpdateMax = LazySegTree<S, Mx<S>, Const<S, MINF>,
    S, Update<S, ID>, Update<S, ID>, Const<S, ID>>;

template <class S, S MINF>
using AffineMax = LazySegTree<S, Mx<S>, Const<S, MINF>,
    Affine<S>, Aff<S>, AffCompositon<S>, Id<S>>;

template <class S, S INF>
using AddMin = LazySegTree<S, Mn<S>, Const<S, INF>,
    S, Add<S>, Add<S>, Zero<S>>;

template <class S, S INF, S ID>
using UpdateMin = LazySegTree<S, Mn<S>, Const<S, INF>,
    S, Update<S, ID>, Update<S, ID>, Const<S, ID>>;

template <class S, S INF>
using AffineMin = LazySegTree<S, Mn<S>, Const<S, INF>,
    Affine<S>, Aff<S>, AffCompositon<S>, Id<S>>;

template <class S>
using AddSum = LazySegTree<Sum<S>, Sm<S>, ZeroSm<S>,
    S, AddSm<S>, Add<S>, Zero<S>>;

template <class S, S ID>
using UpdateSum = LazySegTree<Sum<S>, Sm<S>, ZeroSm<S>,
    S, UpdateSm<S, ID>, Update<S, ID>, Const<S, ID>>;

template <class S>
using AffineSum = LazySegTree<Sum<S>, Sm<S>, ZeroSm<S>,
    Affine<S>, AffSm<S>, AffCompositon<S>, Id<S>>;

} // namespace seg_utility

using seg_utility::AddMax;
using seg_utility::UpdateMax;
using seg_utility::AffineMax;
using seg_utility::AddMin;
using seg_utility::UpdateMin;
using seg_utility::AffineMin;
using seg_utility::AddSum;
using seg_utility::UpdateSum;
using seg_utility::AffineSum;
using seg_utility::gen_sum;
using seg_utility::gen_aff;

#endif // SEG_UTILITY_HPP
