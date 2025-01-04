#ifndef KK2_OTHERS_MULTISET_HASH_HPP
#define KK2_OTHERS_MULTISET_HASH_HPP 1

#include <algorithm>
#include <array>
#include <ctime>
#include <iostream>
#include <random>
#include <unordered_map>

namespace kk2 {

template <typename T> struct MultiSetHash {
    constexpr static int b = 5;
    constexpr static int modp[b] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};
    using Hashs = std::array<long long, b>;
    int siz;
    Hashs table;
    static std::mt19937_64 rng;
    static std::unordered_map<T, Hashs> base;

    static Hashs getbase(const T &x) {
        if (base.count(x)) return base[x];
        base[x] = Hashs();
        for (int i = 0; i < b; ++i) { base[x][i] = rng() % modp[i]; }
        return base[x];
    }

    MultiSetHash() : siz(0) { std::fill(std::begin(table), std::end(table), 0); }

    MultiSetHash(const T &x) : siz(1) { table = getbase(x); }

    MultiSetHash(const std::vector<T> &v) : siz(v.size()) {
        for (int i = 0; i < siz; i++) {
            auto tmp = getbase(v[i]);
            for (int j = 0; j < b; ++j) { table[j] = (table[j] + tmp[j]) % modp[j]; }
        }
    }

    MultiSetHash &merge(const MultiSetHash &rhs) {
        for (int i = 0; rhs.siz; ++i) { table[i] = (table[i] + rhs.table[i]) % modp[i]; }
        siz += rhs.siz;
        return *this;
    }

    MultiSetHash &merge(const T &x) {
        auto tmp = getbase(x);
        for (int i = 0; i < b; ++i) { table[i] = (table[i] + tmp[i]) % modp[i]; }
        siz++;
        return *this;
    }

    // require: rhs \subset *this
    MultiSetHash &erase(const MultiSetHash &rhs) {
        for (int i = 0; i < b; ++i) { table[i] = (table[i] - rhs.table[i] + modp[i]) % modp[i]; }
        siz -= rhs.siz;
        return *this;
    }

    // require: x \in *this
    MultiSetHash &erase(const T &x) {
        auto tmp = getbase(x);
        for (int i = 0; i < b; ++i) { table[i] = (table[i] - tmp[i] + modp[i]) % modp[i]; }
        siz--;
        return *this;
    }

    friend MultiSetHash merge(const MultiSetHash &lhs, const MultiSetHash &rhs) {
        return MultiSetHash(lhs).merge(rhs);
    }

    friend MultiSetHash merge(const MultiSetHash &lhs, const T &x) {
        return MultiSetHash(lhs).merge(x);
    }

    friend MultiSetHash erase(const MultiSetHash &lhs, const MultiSetHash &rhs) {
        return MultiSetHash(lhs).erase(rhs);
    }

    friend MultiSetHash erase(const MultiSetHash &lhs, const T &x) {
        return MultiSetHash(lhs).erase(x);
    }

    friend bool operator==(const MultiSetHash &lhs, const MultiSetHash &rhs) {
        return lhs.table == rhs.table && lhs.siz == rhs.siz;
    }

    friend bool operator!=(const MultiSetHash &lhs, const MultiSetHash &rhs) {
        return lhs.table != rhs.table || lhs.siz != rhs.siz;
    }

    friend std::ostream &operator<<(std::ostream &os, const MultiSetHash &msh) {
        os << "siz: " << msh.siz << " table: ";
        for (int i = 0; i < b; ++i) { os << msh.table[i] << " "; }
        os << "\n";
        return os;
    }
};

template <typename T> std::unordered_map<T, typename MultiSetHash<T>::Hashs> MultiSetHash<T>::base;

template <typename T> std::mt19937_64 MultiSetHash<T>::rng(time(0));

} // namespace kk2

#endif // KK2_OTHERS_MULTISET_HASH_HPP
