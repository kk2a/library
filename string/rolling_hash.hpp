#ifndef ROLLING_HASH_HPP
#define ROLLING_HASH_HPP 1

#include <array>
#include <ctime>
#include <random>
#include <string>
#include <vector>

#include "../math_mod/pow_expr.hpp"

namespace kk2 {

// setbase() must be called before using Hash
struct RollingHash {
    struct Hash {
        long long h, pw, pwi;
    };

    constexpr static int b = 5;
    using T = std::array<Hash, b>;
    T table;
    constexpr static int modp[b] = {
        998244353, 1000000007, 1000000009, 1000000021, 1000000033};
    static int base[b], basei[b];

    static void setbase() {
        std::mt19937_64 rng(time(0));
        for (int i = 0; i < b; ++i) {
            base[i] = rng() % modp[i];
            basei[i] = quo(base[i], i);
        }
    }

    RollingHash(const int &v) {
        for (int i = 0; i < b; ++i) {
            table[i].h = v % modp[i];
            table[i].pw = base[i];
            table[i].pwi = basei[i];
        }
    }

    RollingHash(const char &c) {
        for (int i = 0; i < b; ++i) {
            table[i].h = c;
            table[i].pw = base[i];
            table[i].pwi = basei[i];
        }
    }

    template <class T> RollingHash(const std::vector<T> &v) {
        int n = v.size();
        for (int i = 0; i < b; ++i) {
            table[i].h = 0;
            table[i].pw = 1;
            table[i].pwi = 1;
            for (int j = n - 1; j >= 0; --j) {
                table[i].h = (table[i].h * base[i] + v[j] % modp[i]) % modp[i];
                table[i].pw = table[i].pw * base[i] % modp[i];
                table[i].pwi = table[i].pwi * basei[i] % modp[i];
            }
        }
    }

    RollingHash(const std::string &s) {
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

    RollingHash() {
        for (int i = 0; i < b; ++i) {
            table[i].h = 0;
            table[i].pw = 1;
            table[i].pwi = 1;
        }
    }

    RollingHash &push_front(const RollingHash &otherHash) {
        for (int i = 0; i < b; ++i) {
            table[i].h =
                (otherHash.table[i].h + table[i].h * otherHash.table[i].pw)
                % modp[i];
            table[i].pw = table[i].pw * otherHash.table[i].pw % modp[i];
            table[i].pwi = table[i].pwi * otherHash.table[i].pwi % modp[i];
        }
        return *this;
    }

    RollingHash &push_back(const RollingHash &otherHash) {
        for (int i = 0; i < b; ++i) {
            table[i].h =
                (table[i].h + otherHash.table[i].h * table[i].pw) % modp[i];
            table[i].pw = table[i].pw * otherHash.table[i].pw % modp[i];
            table[i].pwi = table[i].pwi * otherHash.table[i].pwi % modp[i];
        }
        return *this;
    }

    RollingHash &pop_front(const RollingHash &otherHash) {
        for (int i = 0; i < b; ++i) {
            table[i].h = (table[i].h - otherHash.table[i].h)
                         * otherHash.table[i].pwi % modp[i];
            if (table[i].h < 0) table[i].h += modp[i];
            table[i].pw = table[i].pw * otherHash.table[i].pwi % modp[i];
            table[i].pwi = table[i].pwi * otherHash.table[i].pw % modp[i];
        }
        return *this;
    }

    RollingHash &pop_back(const RollingHash &otherHash) {
        for (int i = 0; i < b; ++i) {
            long long minus = otherHash.table[i].h * table[i].pw % modp[i]
                              * otherHash.table[i].pwi % modp[i];
            table[i].h = (table[i].h - minus) % modp[i];
            if (table[i].h < 0) table[i].h += modp[i];
            table[i].pw = table[i].pw * otherHash.table[i].pwi % modp[i];
            table[i].pwi = table[i].pwi * otherHash.table[i].pw % modp[i];
        }
        return *this;
    }

    friend bool operator==(const RollingHash &lhs, const RollingHash &rhs) {
        for (int i = 0; i < b; ++i) {
            if (lhs.table[i].h != rhs.table[i].h) return false;
            if (lhs.table[i].pw != rhs.table[i].pw) return false;
        }
        return true;
    }

    friend bool operator!=(const RollingHash &lhs, const RollingHash &rhs) {
        return !(lhs == rhs);
    }

  private:
    constexpr static long long quo(long long a, int i) {
        return pow_mod_constexpr(a, modp[i] - 2, modp[i]);
    }
};

int RollingHash::base[5] = {3, 3, 3, 3, 3};
int RollingHash::basei[5] = {
    332748118, 333333336, 666666673, 666666681, 666666689};


using Roliha = RollingHash;

} // namespace kk2


#endif // ROLLING_HASH_HPP
