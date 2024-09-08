#ifndef DATA_STRUCTURE_MY_BITSET_HPP
#define DATA_STRUCTURE_MY_BITSET_HPP 1

namespace kk2 {

// old version
struct DynamicBitSet {
    using T = DynamicBitSet;
    using u64 = uint64_t;
    int n;
    vector<u64> block;

    DynamicBitSet(int n_ = 0, int x = 0) : n(n_) {
        assert(x == 0 || x == 1);
        u64 val = x ? -1 : 0;
        block.assign((n + 63) >> 6, val);
        if (n) block.back() >>= ((u64)block.size() << 6) - n;
        // fit the last block
    }
    DynamicBitSet(const string& s) : n(s.size()) {
        block.resize((n + 63) >> 6);
        set(s);
    }

    int size() const { return n; }

    T& inplace_combine_bottom(const T& rhs) {
        block.resize((n + rhs.n + 63) >> 6);
        if (!(n & 63)) {
            copy(begin(rhs.block), end(rhs.block), begin(block) + (n >> 6));
            n += rhs.n;
            return *this;
        }
        int start = 64 - (n & 63);
        u64 start_mask = (1ULL << start) - 1;
        u64 end_mask = ~start_mask;
        for (int i = 0; i < (rhs.n + 63) >> 6; i++) {
            u64 x = rhs.block[i];
            block[i + (n >> 6)] |= (x & start_mask) << (64 - start);
            if (i + (n >> 6) + 1 < (n + rhs.n + 63) >> 6)
                block[i + (n >> 6) + 1] |= (x & end_mask) >> start;
        }
        n += rhs.n;
        return *this;
    }

    T combine_bottom(const T& rhs) const {
        return T(*this).inplace_combine_bottom(rhs);
    }

    T& inplace_combine_top(const T& rhs) {
        block.resize((n + rhs.n + 63) >> 6);
        if (!(rhs.n & 63)) {
            copy(begin(block), end(block), begin(block) + (rhs.n >> 6));
            copy(begin(rhs.block), end(rhs.block), begin(block));
            n += rhs.n;
            return *this;
        }
        int start = 64 - (rhs.n & 63);
        u64 start_mask = (1ULL << start) - 1;
        u64 end_mask = ~start_mask;
        for (int i = ((n + 63) >> 6) - 1; i >= 0; --i) {
            u64 x = block[i];
            block[i + (rhs.n >> 6)] |= (x & start_mask) << (64 - start);
            if (i + (rhs.n >> 6) + 1 < (n + rhs.n + 63) >> 6)
                block[i + (rhs.n >> 6) + 1] |= (x & end_mask) >> start;
        }
        block[(rhs.n >> 6)] = ((block[0] & start_mask) << (64 - start)) | rhs.block.back();
        copy(begin(rhs.block), prev(end(rhs.block)), begin(block));
        n += rhs.n;
        return *this;
    }

    T combine_top(const T& rhs) const {
        return T(*this).inplace_combine_top(rhs);
    }

    void set(int i, int x) {
        assert(0 <= i && i < n);
        if (x) block[i >> 6] |= 1ULL << (i & 63);
        else block[i >> 6] &= ~(1ULL << (i & 63));
    }

    void set(const string& s) {
        assert((int)s.size() == n);
        for (int i = 0; i < (n + 63) >> 6; i++) {
            string tmp = s.substr(i << 6, min(64, n - i));
            reverse(begin(tmp), end(tmp));
            block[i] = stoull(tmp, 0, 2);
        }
    }

    class Proxy {
        vector<u64>& bs;
        int i;
      public:
        Proxy(vector<u64>& bs_, int i_) : bs(bs_), i(i_) {}
        operator bool() const { return (bs[i >> 6] >> (i & 63)) & 1; }
        Proxy& operator=(bool x) {
            if (x) bs[i >> 6] |= 1ULL << (i & 63);
            else bs[i >> 6] &= ~(1ULL << (i & 63));
            return *this;
        }
        Proxy& operator=(const Proxy& x) {
            if (x) bs[i >> 6] |= 1ULL << (i & 63);
            else bs[i >> 6] &= ~(1ULL << (i & 63));
            return *this;
        }

        Proxy& operator&=(bool x) {
            if (!x) bs[i >> 6] &= ~(1ULL << (i & 63));
            return *this;
        }
        Proxy& operator&=(const Proxy& x) {
            bs[i >> 6] &= x.bs[x.i >> 6] >> (x.i & 63);
            return *this;
        }

        Proxy& operator|=(bool x) {
            if (x) bs[i >> 6] |= 1ULL << (i & 63);
            return *this;
        }
        Proxy& operator|=(const Proxy& x) {
            bs[i >> 6] |= x.bs[x.i >> 6] >> (x.i & 63);
            return *this;
        }

        Proxy& operator^=(bool x) {
            if (x) bs[i >> 6] ^= 1ULL << (i & 63);
            return *this;
        }
        Proxy& operator^=(const Proxy& x) {
            bs[i >> 6] ^= x.bs[x.i >> 6] >> (x.i & 63);
            return *this;
        }

        Proxy& flip() {
            bs[i >> 6] ^= 1ULL << (i & 63);
            return *this;
        }
        Proxy& operator~() {
            bs[i >> 6] ^= 1ULL << (i & 63);
            return *this;
        }

        bool val() {
            return (bs[i >> 6] >> (i & 63)) & 1;
        }
    };

    Proxy operator[](int i) {
        assert(0 <= i && i < n);
        return Proxy(block, i);
    }

    bool is_pinned(int i) const {
        assert(0 <= i && i < n);
        return (block[i >> 6] >> (i & 63)) & 1;
    }

    T& operator=(const string& s) {
        assert((int)s.size() == n);
        set(s);
        return *this;
    }

    void flip() {
        u64 mask = (1ULL << (n & 63)) - 1;
        for (u64& x : block) x = ~x;
        block.back() &= mask;
    }

    void flip(int i) {
        assert(0 <= i && i < n);
        block[i >> 6] ^= 1ULL << (i & 63);
    }

    T& operator~() {
        flip();
        return *this;
    }

    T& operator&=(const T& rhs) {
        assert(n == rhs.n);
        for (int i = 0; i < (n + 63) >> 6; i++) {
            block[i] &= rhs.block[i];
        }
        return *this;
    }

    T& operator|=(const T& rhs) {
        assert(n == rhs.n);
        for (int i = 0; i < (n + 63) >> 6; i++) {
            block[i] |= rhs.block[i];
        }
        return *this;
    }

    T& operator^=(const T& rhs) {
        assert(n == rhs.n);
        for (int i = 0; i < (n + 63) >> 6; i++) {
            block[i] ^= rhs.block[i];
        }
        return *this;
    }

    friend T operator&(const T& lhs, const T& rhs) { return T(lhs) &= rhs; }
    friend T operator|(const T& lhs, const T& rhs) { return T(lhs) |= rhs; }
    friend T operator^(const T& lhs, const T& rhs) { return T(lhs) ^= rhs; }
    friend bool operator==(const T& lhs, const T& rhs) {
        assert(lhs.n == rhs.n);
        for (int i = 0; i < (lhs.n + 63) >> 6; i++) {
            if (lhs.block[i] != rhs.block[i]) return false;
        }
        return true;
    }
    friend bool operator!=(const T& lhs, const T& rhs) { return !(T(lhs) == rhs); }

    string to_string() const {
        string s;
        int i = 0;
        for (; i + 1 < (n + 63) >> 6; i++) {
            string tmp = bitset<64>(block[i]).to_string();
            reverse(begin(tmp), end(tmp));
            s += tmp;
        }
        int start = 64 - (n & 63);
        int len = n & 63;
        if (!len) start = 0, len = 64;
        string tmp = bitset<64>(block.back()).to_string().substr(start, len);
        reverse(begin(tmp), end(tmp));
        s += tmp;
        return s;
    }

    friend ostream& operator<<(ostream& os, const T& bs) {
        return os << bs.to_string();
    }

    operator bool() const {
        for (int i = 0; i < (n + 63) >> 6; i++) {
            if (block[i]) return true;
        }
        return false;
    }
};

} // namespace kk2

#endif // DATA_STRUCTURE_MY_BITSET_HPP
