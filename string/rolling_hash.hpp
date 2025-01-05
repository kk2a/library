#ifndef KK2_STRING_ROLLING_HASH_HPP
#define KK2_STRING_ROLLING_HASH_HPP 1

#include <cassert>
#include <string>
#include <vector>

#include "../random/hash.hpp"

namespace kk2 {

template <int NUM> struct RollingHash {
    using H = random::Hash<NUM>;
    static std::vector<H> pw, pwi;
    std::vector<H> prefix;

    RollingHash() : prefix() {}

    template <class T, is_integral_t<T> * = nullptr> RollingHash(T v) : prefix({H(v)}) {}

    RollingHash(const std::string &s) : prefix(s.size()) {
        extend_base(s.size());
        prefix[0] = H(s[0]);
        for (size_t i = 1; i < s.size(); ++i) { prefix[i] = prefix[i - 1] + H(s[i]) * pw[i]; }
    }

    template <class T, is_integral_t<T> * = nullptr>
    RollingHash(const std::vector<T> &v) : prefix(v.size()) {
        extend_base(v.size());
        prefix[0] = H(v[0]);
        for (size_t i = 1; i < v.size(); ++i) { prefix[i] = prefix[i - 1] + H(v[i]) * pw[i]; }
    }

    // [l, r)
    H get(int l, int r) const {
        assert(0 <= l and l <= r and r <= (int)prefix.size());
        if (l == r) return H(0);
        if (l == 0) return prefix[r - 1];
        return (prefix[r - 1] - prefix[l - 1]) * pwi[l];
    }

    static int lcp(const RollingHash &lhs, int l1, int r1, const RollingHash &rhs, int l2, int r2) {
        int len = std::min(r1 - l1, r2 - l2);
        int ok = 0, ng = len + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if (lhs.get(l1, l1 + mid) == rhs.get(l2, l2 + mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return ok;
    }

    static int
    strcmp(const RollingHash &lhs, int l1, int r1, const RollingHash &rhs, int l2, int r2) {
        int lcp_ = lcp(lhs, l1, r1, rhs, l2, r2);
        if (lcp_ == r1 - l1 and lcp_ == r2 - l2) return 0;
        else if (lcp_ == r1 - l1) return -1;
        else if (lcp_ == r2 - l2) return 1;
        else {
            auto c1 = lhs.get(l1 + lcp_, l1 + lcp_ + 1)[0].val();
            auto c2 = rhs.get(l2 + lcp_, l2 + lcp_ + 1)[0].val();
            return c1 < c2 ? -1 : 1;
        }
    }

    static RollingHash merge(const RollingHash &lhs, const RollingHash &rhs) {
        RollingHash res;
        extend_base(lhs.prefix.size() + rhs.prefix.size());
        res.prefix = lhs.prefix;
        res.prefix.insert(res.prefix.end(), rhs.prefix.begin(), rhs.prefix.end());
        for (size_t i = lhs.prefix.size(); i < res.prefix.size(); ++i) {
            res.prefix[i] =
                res.prefix[i] * pw[lhs.prefix.size()] + res.prefix[lhs.prefix.size() - 1];
        }
        return res;
    }

  private:
    static void extend_base(int m) {
        if (pw.size() == 0u) {
            pw.push_back(H(1));
            pwi.push_back(H(1));
            pw.push_back(H::get_base());
            pwi.push_back(pw[1].inv());
        }

        int n = pw.size();
        if (n >= m) return;
        pw.resize(m);
        pwi.resize(m);
        for (int i = n; i < m; ++i) {
            pw[i] = pw[i - 1] * pw[1];
            pwi[i] = pwi[i - 1] * pwi[1];
        }
    }
};

template <int NUM> std::vector<typename RollingHash<NUM>::H> RollingHash<NUM>::pw;
template <int NUM> std::vector<typename RollingHash<NUM>::H> RollingHash<NUM>::pwi;

using Roliha = RollingHash<2>;

} // namespace kk2


#endif // KK2_STRING_ROLLING_HASH_HPP
