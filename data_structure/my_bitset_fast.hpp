#ifndef DATA_STRUCTURE_MY_BITSET_FAST_HPP
#define DATA_STRUCTURE_MY_BITSET_FAST_HPP 1


struct DynamicBitSetFast {
    using T = DynamicBitSetFast;
    using u128 = __uint128_t;
    constexpr static int BLOCK_SIZE_LOG = 7;
    constexpr static int BLOCK_SIZE = 1 << BLOCK_SIZE_LOG;
    constexpr static int BLOCK_MASK = BLOCK_SIZE - 1;
    constexpr static u128 ONE = 1;
    int n;
    vector<u128> block;

    DynamicBitSetFast(int n_ = 0, bool x = 0) : n(n_) {
        u128 val = x ? -1 : 0;
        block.assign((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG, val);
        if (n & BLOCK_MASK) block.back() >>= BLOCK_SIZE - (n & BLOCK_MASK);
        // fit the last block
    }

    // Note that the string needs to be reversed.
    // For example, if the input is "1010",
    // the character at index 0 in the string is '1',
    // but in the bitset it will be considered as index 0.
    DynamicBitSetFast(const string& s) : n(s.size()) {
        block.resize((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);
        set(s);
    }

    int size() const { return n; }

    T& inplace_combine_bottom(const T& rhs) {
        block.resize((n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);
        if (!(n & BLOCK_MASK)) {
            copy(begin(rhs.block), end(rhs.block), begin(block) + (n >> BLOCK_SIZE_LOG));
            n += rhs.n;
            return *this;
        }
        int start = BLOCK_SIZE - (n & BLOCK_MASK);
        u128 start_mask = (ONE << start) - 1;
        u128 end_mask = ~start_mask;
        for (int i = 0; i < (rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            u128 x = rhs.block[i];
            block[i + (n >> BLOCK_SIZE_LOG)] |= (x & start_mask) << (BLOCK_SIZE - start);
            if (i + (n >> BLOCK_SIZE_LOG) + 1 < (n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG)
                block[i + (n >> BLOCK_SIZE_LOG) + 1] |= (x & end_mask) >> start;
        }
        n += rhs.n;
        return *this;
    }

    T combine_bottom(const T& rhs) const {
        return T(*this).inplace_combine_bottom(rhs);
    }

    T& inplace_combine_top(const T& rhs) {
        block.resize((n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);
        if (!(rhs.n & BLOCK_MASK)) {
            copy(begin(block), end(block), begin(block) + (rhs.n >> BLOCK_SIZE_LOG));
            copy(begin(rhs.block), end(rhs.block), begin(block));
            n += rhs.n;
            return *this;
        }
        int start = BLOCK_SIZE - (rhs.n & BLOCK_MASK);
        u128 start_mask = (ONE << start) - 1;
        u128 end_mask = ~start_mask;
        for (int i = ((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG) - 1; i >= 0; --i) {
            u128 x = block[i];
            block[i + (rhs.n >> BLOCK_SIZE_LOG)] |= (x & start_mask) << (BLOCK_SIZE - start);
            if (i + (rhs.n >> BLOCK_SIZE_LOG) + 1 < (n + rhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG)
                block[i + (rhs.n >> BLOCK_SIZE_LOG) + 1] |= (x & end_mask) >> start;
        }
        block[(rhs.n >> BLOCK_SIZE_LOG)] = ((block[0] & start_mask) << (BLOCK_SIZE - start)) | rhs.block.back();
        copy(begin(rhs.block), end(rhs.block), begin(block));
        n += rhs.n;
        return *this;
    }

    T combine_top(const T& rhs) const {
        return T(*this).inplace_combine_top(rhs);
    }

    void set(int i, int x) {
        assert(0 <= i && i < n);
        if (x) block[i >> BLOCK_SIZE_LOG] |= ONE << (i & BLOCK_MASK);
        else block[i >> BLOCK_SIZE_LOG] &= ~(ONE << (i & BLOCK_MASK));
    }

    void set(const string& s) {
        assert((int)s.size() == n);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            int r = n - (i << BLOCK_SIZE_LOG), l = max(0, r - BLOCK_SIZE);
            u128 val = 0;
            for (int j = l; j < r; ++j) {
                val = (val << 1) | (s[j] - '0');
            }
            block[i] = val;
        }
    }

    class BitReference {
        vector<u128>& block;
        int idx;
      public:
        BitReference(vector<u128>& block_, int idx_) : block(block_), idx(idx_) {}
        operator bool() const { return (block[idx >> BLOCK_SIZE_LOG] >> (idx & BLOCK_MASK)) & 1; }

        BitReference& operator=(bool x) {
            if (x) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);
            else block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));
            return *this;
        }

        BitReference& operator=(const BitReference& other) {
            if (other) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);
            else block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));
            return *this;
        }

        BitReference& operator&=(bool x) {
            if (!x) block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));
            return *this;
        }

        BitReference& operator&=(const BitReference& other) {
            if (!other) block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));
            return *this;
        }

        BitReference& operator|=(bool x) {
            if (x) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        BitReference& operator|=(const BitReference& other) {
            if (other) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        BitReference& operator^=(bool x) {
            if (x) block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        BitReference& operator^=(const BitReference& other) {
            if (other) block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        BitReference& flip() {
            block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        BitReference& operator~() {
            block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        bool val() const {
            return (block[idx >> BLOCK_SIZE_LOG] >> (idx & BLOCK_MASK)) & 1;
        }
    };

    BitReference operator[](int i) {
        assert(0 <= i && i < n);
        return BitReference(block, i);
    }

    bool is_pinned(int i) const {
        assert(0 <= i && i < n);
        return (block[i >> BLOCK_SIZE_LOG] >> (i & BLOCK_MASK)) & 1;
    }

    T& operator=(const string& s) {
        set(s);
        return *this;
    }

    T& flip() {
        u128 mask = (ONE << (n & BLOCK_MASK)) - 1;
        for (u128& x : block) x = ~x;
        block.back() &= mask;
        return *this;
    }

    T& flip(int i) {
        assert(0 <= i && i < n);
        block[i >> BLOCK_SIZE_LOG] ^= ONE << (i & BLOCK_MASK);
        return *this;
    }

    T& operator~() {
        return flip();
    }

    T& operator&=(const T& other) {
        assert(n == other.n);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            block[i] &= other.block[i];
        }
        return *this;
    }

    T& operator|=(const T& other) {
        assert(n == other.n);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            block[i] |= other.block[i];
        }
        return *this;
    }

    T& operator^=(const T& other) {
        assert(n == other.n);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            block[i] ^= other.block[i];
        }
        return *this;
    }

    friend T operator&(const T& lhs, const T& rhs) {
        return T(lhs) &= rhs;
    }
    friend T operator|(const T& lhs, const T& rhs) {
        return T(lhs) |= rhs;
    }
    friend T operator^(const T& lhs, const T& rhs) {
        return T(lhs) ^= rhs;
    }
    friend bool operator==(const T& lhs, const T& rhs) {
        if (lhs.n != rhs.n) return false;
        for (int i = 0; i < (lhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            if (lhs.block[i] != rhs.block[i]) return false;
        }
        return true;
    }
    friend bool operator!=(const T& lhs, const T& rhs) {
        return !(lhs == rhs);
    }

    operator bool() const {
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            if (block[i]) return true;
        }
        return false;
    }

    string to_string(u128 x) const {
        return bitset<64>((u64)(x >> (BLOCK_SIZE / 2))).to_string() 
             + bitset<64>((u64)(x & ((ONE << (BLOCK_SIZE / 2)) - 1))).to_string();
    }

    string to_string() const {
        vector<string> tmp((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            tmp[i] = to_string(block[i]);
        }
        if (n & BLOCK_MASK) {
            reverse(begin(tmp.back()), end(tmp.back()));
            tmp.back().resize(n & BLOCK_MASK);
            reverse(begin(tmp.back()), end(tmp.back()));
        }
        string res;
        for (int i = (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i--;) {
            res += tmp[i];
        }
        return res;
    }

    friend ostream& operator<<(ostream& os, const T& bs) {
        return os << bs.to_string();
    }
};

#endif // DATA_STRUCTURE_MY_BITSET_FAST_HPP
