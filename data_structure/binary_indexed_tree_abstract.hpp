#ifndef KK2_DATA_STRUCTURE_BINARY_INDEXED_TREE_ABSTRACT_HPP
#define KK2_DATA_STRUCTURE_BINARY_INDEXED_TREE_ABSTRACT_HPP 1

#include <cassert>
#include <vector>

namespace kk2 {

template <class A> struct BinaryIndexedTreeAbstract {
    BinaryIndexedTreeAbstract() : _n(0) {}
    BinaryIndexedTreeAbstract(int n) : _n(n), data(n, A::unit()) {}

    void add(int p, A x) {
        assert(0 <= p && p < _n);
        for (p++; p <= _n; p += p & -p) data[p - 1] = A::op(data[p - 1], x);
    }

    A sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return A::op(A::inv(sum(l)), sum(r));
    }

    A get(int p) {
        assert(0 <= p && p < _n);
        return A::op(sum(p + 1), A::inv(sum(p)));
    }

  private:
    int _n;
    std::vector<A> data;

    A sum(int r) {
        A s = A::unit();
        for (; r > 0; r -= r & -r) s = A::op(s, data[r - 1]);
        return s;
    }
};

} // namespace kk2

#endif // KK2_DATA_STRUCTURE_BINARY_INDEXED_TREE_ABSTRACT_HPP
