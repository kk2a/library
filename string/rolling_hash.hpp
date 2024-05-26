#ifndef ROLLING_HASH_HPP
#define ROLLING_HASH_HPP 1

template <int id>
struct Hashs {
    struct Hash {
        long long h, pw;
    };
    constexpr static int b = 5;
    using T = array<Hash, b>;
    T table;
    constexpr static int modp[b] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};
    static int base[b];

    static void setbase() {
        mt19937_64 rng(time(0));
        rep (i, 0, b) {
            set<int> st = {0, 1, modp[i] - 1};
            while(st.count(base[i] = rng() % modp[i]));
        }
    }
    
    template <class S>
    Hashs(S c) {
        rep (i, b) {
            table[i].h = c;
            table[i].pw = base[i];
        }
    }
    Hashs() {
        rep (i, b) {
            table[i].h = 0;
            table[i].pw = 1;
        }
    }

    // return hash of rhs + this
    void push_front(const Hashs &rhs) {
        rep (i, b) {
            table[i].h = (table[i].h * rhs.table[i].pw + rhs.table[i].h) % modp[i];
            table[i].pw = table[i].pw * rhs.table[i].pw % modp[i];
        }
    }

    // return hash of this + rhs
    void push_back(const Hashs &rhs) {
        rep (i, b) {
            table[i].h = (table[i].h + rhs.table[i].h * table[i].pw) % modp[i];
            table[i].pw = table[i].pw * rhs.table[i].pw % modp[i];
        }
    }

    // push_back
    Hashs& operator+=(const Hashs &rhs) {
        rep (i, b) {
            table[i].h = (table[i].h * rhs.table[i].pw + rhs.table[i].h) % modp[i];
            table[i].pw = table[i].pw * rhs.table[i].pw % modp[i];
        }
        return *this;
    }

    // push_front
    Hashs& operator-=(const Hashs &rhs) {
        rep (i, b) {
            table[i].h = (table[i].h + rhs.table[i].h * table[i].pw) % modp[i];
            table[i].pw = table[i].pw * rhs.table[i].pw % modp[i];
        }
        return *this;
    }

    friend Hashs operator+(const Hashs &lhs, const Hashs &rhs) {
        return Hashs(lhs) += rhs;
    }
    friend Hashs operator-(const Hashs &lhs, const Hashs &rhs) {
        return Hashs(lhs) -= rhs;
    }

    friend bool operator==(const Hashs &lhs, const Hashs &rhs) {
        rep (i, b) {
            if (lhs.table[i].h != rhs.table[i].h) return false;
            if (lhs.table[i].pw != rhs.table[i].pw) return false;
        }
        return true;
    }
    friend bool operator!=(const Hashs &lhs, const Hashs &rhs) {
        return !(lhs == rhs);
    }
};

template <int id>
int Hashs<id>::base[5] = {3, 3, 3, 3, 3};

#endif // ROLLING_HASH_HPP
