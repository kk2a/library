#ifndef KK2_DATA_STRUCTURE_BIT_VECTOR_HPP
#define KK2_DATA_STRUCTURE_BIT_VECTOR_HPP 1

#include <vector>

#include "../bit/bitcount.hpp"

namespace kk2 {

struct BitVector {
    using u32 = unsigned int;
    using Uint = unsigned long long;
    static constexpr int B = 64;
    int n, zeros;
    std::vector<u32> count;
    std::vector<Uint> bits;
    BitVector() = default;

    BitVector(int n_) : n(n_), count(n_ / B + 1), bits(n_ / B + 1) {}

    inline void set(int i) { bits[i / B] |= Uint(1) << (i % B); }

    void build() {
        for (u32 i = 1; i < count.size(); ++i) count[i] = count[i - 1] + popcount(bits[i - 1]);
        zeros = n - rank1(n);
    }

    inline int get(int i) const { return (bits[i / B] >> (i % B)) & 1; }

    inline int rank0(int i) const { return i - rank1(i); }

    inline int rank1(int i) const {
        return count[i / B] + popcount(bits[i / B] & ((Uint(1) << (i % B)) - 1));
    }

    int select0(int i) const {
        if (i >= zeros) return -1;
        int lb = 0, ub = n;
        while (ub - lb > 1) {
            int mid = (lb + ub) / 2;
            if (rank0(mid) > i) ub = mid;
            else lb = mid;
        }
        return lb;
    }

    int select1(int i) const {
        if (i >= n - zeros) return -1;
        int lb = 0, ub = n;
        while (ub - lb > 1) {
            int mid = (lb + ub) / 2;
            if (rank1(mid) > i) ub = mid;
            else lb = mid;
        }
        return lb;
    }
};

} // namespace kk2

#endif // KK2_DATA_STRUCTURE_BIT_VECTOR_HPP
