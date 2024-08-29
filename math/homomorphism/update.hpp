#ifndef MATH_HOMOMORPHISM_UPDATE_HPP
#define MATH_HOMOMORPHISM_UPDATE_HPP 1

namespace kk2 {

namespace homomorphism {

template <class S>
struct Update {
    S a;
    bool id;
    Update() : a(S()), id(true) {}
    Update(S a_, bool id_ = false) : a(a_), id(id_) {}
    operator S() const { return a; }
    friend ostream& operator<<(ostream& os, const Update& update) {
        os << (update.id ? "id" : to_string(update.a));
        return os;
    }

    Update& composition(const Update& f) {
        if (f.id) return *this;
        return *this = f;
    }
};

template <class S, class T>
T UpdateMap(Update<S> f, T x) { return f.id ? x : x.update(f.a); }

template <class S>
Update<S> UpdateComposition(Update<S> l, Update<S> r) { return r.composition(l); }

template <class S>
Update<S> UpdateUnit() { return Update<S>(); }

} // namespace homomorphism

} // namespace kk2

#endif // MATH_HOMOMORPHISM_UPDATE_HPP
