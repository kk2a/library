#ifndef DATA_STRUCTURE_PREFIX_SUM_HPP
#define DATA_STRUCTURE_PREFIX_SUM_HPP 1

#include <algorithm>
#include <array>
#include <cassert>
#include <vector>

namespace kk2 {

template <class T> struct PrefixSum {
    std::vector<T> acc;
    int n;

    constexpr PrefixSum() = default;

    constexpr PrefixSum(const std::vector<T> &a) : acc(a.size() + 1), n((int)a.size()) {
        for (int i = 0; i < n; ++i) { acc[i + 1] = acc[i] + a[i]; }
    }

    constexpr T sum(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return acc[r] - acc[l];
    }

    constexpr T get(int i) const {
        assert(0 <= i && i < n);
        return acc[i + 1] - acc[i];
    }

    constexpr T operator[](int i) const {
        assert(0 <= i && i < n);
        return acc[i + 1] - acc[i];
    }

    constexpr T operator()(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return acc[r] - acc[l];
    }

    constexpr int size() const { return n; }

    // require: acc is non-decreasing
    // return r s.t.
    // r = n or sum(l, r) >= x
    // r = l or sum(l, r) < x
    constexpr int lower(int l, T x) const {
        assert(0 <= l && l <= n);
        int ng = l - 1, ok = n;
        while (ok - ng > 1) {
            int mid = (ok + ng) >> 1;
            if (acc[mid] - acc[l] < x) ng = mid;
            else ok = mid;
        }
        return ok;
    }
};

} // namespace kk2

#endif // DATA_STRUCTURE_PREFIX_SUM_HPP
