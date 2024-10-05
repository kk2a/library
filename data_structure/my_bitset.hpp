#ifndef DATA_STRUCTURE_MY_BITSET_HPP
#define DATA_STRUCTURE_MY_BITSET_HPP 1

#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

namespace kk2 {

struct DynamicBitSet {
    using T = DynamicBitSet;
    using UInt = __uint128_t;
    constexpr static int BLOCK_SIZE = sizeof(UInt) * 8;
    constexpr static int BLOCK_SIZE_LOG = __builtin_ctz(BLOCK_SIZE);
    constexpr static int BLOCK_MASK = BLOCK_SIZE - 1;
    constexpr static UInt ONE = 1;
    int n;
    std::vector<UInt> block;

    DynamicBitSet(int n_ = 0, bool x = 0) : n(n_) {
        UInt val = x ? -1 : 0;
        block.assign((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG, val);
        if (n & BLOCK_MASK) block.back() >>= BLOCK_SIZE - (n & BLOCK_MASK);
        // fit the last block
    }

    // Note that the string needs to be reversed.
    // For example, if the input is "1010",
    // the character at index 0 in the string is '1',
    // but in the bitset it will be considered as index 0.
    DynamicBitSet(const std::string &s) : n(s.size()) {
        block.resize((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);
        set(s);
    }

    int size() const { return n; }

    T &inplace_combine_top(const T &rhs) {
        block.resize((n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);
        if (!(n & BLOCK_MASK)) {
            std::copy(std::begin(rhs.block),
                      std::end(rhs.block),
                      std::begin(block) + (n >> BLOCK_SIZE_LOG));
            n += rhs.n;
            return *this;
        }
        int start = BLOCK_SIZE - (n & BLOCK_MASK);
        UInt start_mask = (ONE << start) - 1;
        UInt end_mask = ~start_mask;
        for (int i = 0; i < (rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            UInt x = rhs.block[i];
            block[i + (n >> BLOCK_SIZE_LOG)] |= (x & start_mask) << (BLOCK_SIZE - start);
            if (i + (n >> BLOCK_SIZE_LOG) + 1 < (n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG)
                block[i + (n >> BLOCK_SIZE_LOG) + 1] |= (x & end_mask) >> start;
        }
        n += rhs.n;
        return *this;
    }

    T combine_top(const T &rhs) const { return T(*this).inplace_combine_top(rhs); }

    T &inplace_combine_bottom(const T &rhs) {
        block.resize((n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);
        if (!(rhs.n & BLOCK_MASK)) {
            std::copy(
                std::begin(block), std::end(block), std::begin(block) + (rhs.n >> BLOCK_SIZE_LOG));
            std::copy(std::begin(rhs.block), std::end(rhs.block), std::begin(block));
            n += rhs.n;
            return *this;
        }
        int start = BLOCK_SIZE - (rhs.n & BLOCK_MASK);
        UInt start_mask = (ONE << start) - 1;
        UInt end_mask = ~start_mask;
        for (int i = ((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG) - 1; i >= 0; --i) {
            UInt x = block[i];
            block[i + (rhs.n >> BLOCK_SIZE_LOG)] |= (x & start_mask) << (BLOCK_SIZE - start);
            if (i + (rhs.n >> BLOCK_SIZE_LOG) + 1 < (n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG)
                block[i + (rhs.n >> BLOCK_SIZE_LOG) + 1] |= (x & end_mask) >> start;
        }
        block[(rhs.n >> BLOCK_SIZE_LOG)] =
            ((block[0] & start_mask) << (BLOCK_SIZE - start)) | rhs.block.back();
        std::copy(std::begin(rhs.block), std::prev(std::end(rhs.block)), std::begin(block));
        n += rhs.n;
        return *this;
    }

    T combine_bottom(const T &rhs) const { return T(*this).inplace_combine_bottom(rhs); }

    void set(int i, int x) {
        assert(0 <= i && i < n);
        if (x) block[i >> BLOCK_SIZE_LOG] |= ONE << (i & BLOCK_MASK);
        else block[i >> BLOCK_SIZE_LOG] &= ~(ONE << (i & BLOCK_MASK));
    }

    void set(const std::string &s) {
        assert((int)s.size() == n);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            int r = n - (i << BLOCK_SIZE_LOG), l = std::max(0, r - BLOCK_SIZE);
            block[i] = 0;
            for (int j = l; j < r; j++) block[i] = (block[i] << 1) | (s[j] - '0');
        }
    }

    void set_reversed(const std::string &s) {
        assert((int)s.size() == n);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            int l = i << BLOCK_SIZE_LOG, r = std::min(n, l + BLOCK_SIZE);
            block[i] = 0;
            for (int j = r - 1; j >= l; --j) block[i] = (block[i] << 1) | (s[j] - '0');
        }
    }

    class BitReference {
        std::vector<UInt> &block;
        int idx;

      public:
        BitReference(std::vector<UInt> &block_, int idx_) : block(block_), idx(idx_) {}

        operator bool() const { return (block[idx >> BLOCK_SIZE_LOG] >> (idx & BLOCK_MASK)) & 1; }

        BitReference &operator=(bool x) {
            if (x) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);
            else block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));
            return *this;
        }

        BitReference &operator=(const BitReference &other) {
            if (other) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);
            else block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));
            return *this;
        }

        BitReference &operator&=(bool x) {
            if (!x) block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));
            return *this;
        }

        BitReference &operator&=(const BitReference &other) {
            if (!other) block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));
            return *this;
        }

        BitReference &operator|=(bool x) {
            if (x) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        BitReference &operator|=(const BitReference &other) {
            if (other) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        BitReference &operator^=(bool x) {
            if (x) block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        BitReference &operator^=(const BitReference &other) {
            if (other) block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        BitReference &flip() {
            block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        BitReference &operator~() {
            block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        bool val() const { return (block[idx >> BLOCK_SIZE_LOG] >> (idx & BLOCK_MASK)) & 1; }
    };

    BitReference operator[](int i) {
        assert(0 <= i && i < n);
        return BitReference(block, i);
    }

    bool is_pinned(int i) const {
        assert(0 <= i && i < n);
        return (block[i >> BLOCK_SIZE_LOG] >> (i & BLOCK_MASK)) & 1;
    }

    T &operator=(const std::string &s) {
        set(s);
        return *this;
    }

    T &flip() {
        UInt mask = (ONE << (n & BLOCK_MASK)) - 1;
        for (UInt &x : block) x = ~x;
        block.back() &= mask;
        return *this;
    }

    T &flip(int i) {
        assert(0 <= i && i < n);
        block[i >> BLOCK_SIZE_LOG] ^= ONE << (i & BLOCK_MASK);
        return *this;
    }

    T &operator~() { return flip(); }

    T &operator&=(const T &other) {
        assert(n == other.n);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            block[i] &= other.block[i];
        }
        return *this;
    }

    T &operator|=(const T &other) {
        assert(n == other.n);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            block[i] |= other.block[i];
        }
        return *this;
    }

    T &operator^=(const T &other) {
        assert(n == other.n);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            block[i] ^= other.block[i];
        }
        return *this;
    }

    friend T operator&(const T &lhs, const T &rhs) { return T(lhs) &= rhs; }

    friend T operator|(const T &lhs, const T &rhs) { return T(lhs) |= rhs; }

    friend T operator^(const T &lhs, const T &rhs) { return T(lhs) ^= rhs; }

    friend bool operator==(const T &lhs, const T &rhs) {
        if (lhs.n != rhs.n) return false;
        for (int i = 0; i < (lhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            if (lhs.block[i] != rhs.block[i]) return false;
        }
        return true;
    }

    friend bool operator!=(const T &lhs, const T &rhs) { return !(lhs == rhs); }

    operator bool() const {
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            if (block[i]) return true;
        }
        return false;
    }

    std::string to_string(UInt x) const {
        return std::bitset<64>((unsigned long long)(x >> (BLOCK_SIZE / 2))).to_string()
               + std::bitset<64>((unsigned long long)(x & ((ONE << (BLOCK_SIZE / 2)) - 1)))
                     .to_string();
    }

    std::string to_string() const {
        std::vector<std::string> tmp((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            tmp[i] = to_string(block[i]);
        }
        if (n & BLOCK_MASK) {
            std::reverse(std::begin(tmp.back()), std::end(tmp.back()));
            tmp.back().resize(n & BLOCK_MASK);
            std::reverse(std::begin(tmp.back()), std::end(tmp.back()));
        }
        std::string res;
        for (int i = (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i--;) { res += tmp[i]; }
        return res;
    }

    std::string to_reversed_string() const {
        std::vector<std::string> tmp((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            tmp[i] = to_string(block[i]);
        }
        if (n & BLOCK_MASK) {
            std::reverse(std::begin(tmp.back()), std::end(tmp.back()));
            tmp.back().resize(n & BLOCK_MASK);
            std::reverse(std::begin(tmp.back()), std::end(tmp.back()));
        }
        std::string res;
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            std::reverse(std::begin(tmp[i]), std::end(tmp[i]));
            res += tmp[i];
        }
        return res;
    }

    friend std::ostream &operator<<(std::ostream &os, const T &bs) { return os << bs.to_string(); }
};

} // namespace kk2

#endif // DATA_STRUCTURE_MY_BITSET_HPP
