#ifndef DATA_STRUCTURE_BINARY_INDEXED_TREE_HPP
#define DATA_STRUCTURE_BINARY_INDEXED_TREE_HPP 1

#include <cassert>
#include <vector>

namespace kk2 {

template <typename T> struct BinaryIndexedTree {
    BinaryIndexedTree() : _n(0) {}

    BinaryIndexedTree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        for (p++; p <= _n; p += p & -p) data[p - 1] += x;
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

    T get(int p) {
        assert(0 <= p && p < _n);
        return sum(p + 1) - sum(p);
    }

  private:
    int _n;
    std::vector<T> data;

    T sum(int r) {
        T s{};
        for (; r > 0; r -= r & -r) s += data[r - 1];
        return s;
    }
};

} // namespace kk2

#endif // #ifndef DATA_STRUCTURE_BINARY_INDEXED_TREE_HPP
