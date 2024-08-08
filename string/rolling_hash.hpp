#ifndef ROLLING_HASH_HPP
#define ROLLING_HASH_HPP 1

#include "../math_mod/pow_expr.hpp"

// setbase() must be called before using Hashs
template <int id>
struct Hashs {
    struct Hash {
        long long h, pw, pwi;
    };
    constexpr static int b = 5;
    using T = array<Hash, b>;
    T table;
    constexpr static int modp[b] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};
    static int base[b], basei[b];

    static void setbase() {
        mt19937_64 rng(time(0));
        for (int i = 0; i < b; ++i) {
            unordered_set<int> st = {0, 1, modp[i] - 1};
            while (st.count(base[i] = rng() % modp[i]));
            basei[i] = quo(base[i], i);
        }
    }

    Hashs(char c) {
        for (int i = 0; i < b; ++i) {
            table[i].h = c;
            table[i].pw = base[i];
            table[i].pwi = basei[i];
        }
    }
    Hashs(string s) {
        int n = s.size();
        for (int i = 0; i < b; ++i) {
            table[i].h = 0;
            table[i].pw = 1;
            table[i].pwi = 1;
            for (int j = n - 1; j >= 0; --j) {
                table[i].h = (table[i].h * base[i] + s[j]) % modp[i];
                table[i].pw = table[i].pw * base[i] % modp[i];
                table[i].pwi = table[i].pwi * basei[i] % modp[i];
            }
        }
    }
    Hashs() {
        for (int i = 0; i < b; ++i) {
            table[i].h = 0;
            table[i].pw = 1;
            table[i].pwi = 1;
        }
    }

    void push_front(const Hashs &otherHash) {
        for (int i = 0; i < b; ++i) {
            table[i].h = (otherHash.table[i].h + table[i].h * otherHash.table[i].pw) % modp[i];
            table[i].pw = table[i].pw * otherHash.table[i].pw % modp[i];
            table[i].pwi = table[i].pwi * otherHash.table[i].pwi % modp[i];
        }
    }

    void push_back(const Hashs &otherHash) {
        for (int i = 0; i < b; ++i) {
            table[i].h = (table[i].h + otherHash.table[i].h * table[i].pw) % modp[i];
            table[i].pw = table[i].pw * otherHash.table[i].pw % modp[i];
            table[i].pwi = table[i].pwi * otherHash.table[i].pwi % modp[i];
        }
    }

    void pop_front(const Hashs &otherHash) {
        for (int i = 0; i < b; ++i) {
            table[i].h = (table[i].h - otherHash.table[i].h) * otherHash.table[i].pwi % modp[i];
            if (table[i].h < 0) table[i].h += modp[i];
            table[i].pw = table[i].pw * otherHash.table[i].pwi % modp[i];
            table[i].pwi = table[i].pwi * otherHash.table[i].pw % modp[i];
        }
    }

    void pop_back(const Hashs &otherHash) {
        for (int i = 0; i < b; ++i) {
            long long minus = otherHash.table[i].h * table[i].pw % modp[i] * otherHash.table[i].pwi % modp[i];
            table[i].h = (table[i].h - minus) % modp[i];
            if (table[i].h < 0) table[i].h += modp[i];
            table[i].pw = table[i].pw * otherHash.table[i].pwi % modp[i];
            table[i].pwi = table[i].pwi * otherHash.table[i].pw % modp[i];
        }
    }

    friend bool operator==(const Hashs &lhs, const Hashs &rhs) {
        for (int i = 0; i < b; ++i) {
            if (lhs.table[i].h != rhs.table[i].h) return false;
            if (lhs.table[i].pw != rhs.table[i].pw) return false;
        }
        return true;
    }
    friend bool operator!=(const Hashs &lhs, const Hashs &rhs) {
        return !(lhs == rhs);
    }

  private:
    constexpr static long long quo(long long a, int i) {
        return pow_mod_constexpr(a, modp[i] - 2, modp[i]);
    } 
};

template <int id>
int Hashs<id>::base[5] = {3, 3, 3, 3, 3};
template <int id>
int Hashs<id>::basei[5] = {332748118, 333333336, 666666673, 666666681, 666666689};

using Roliha = Hashs<0>;

#endif // ROLLING_HASH_HPP
