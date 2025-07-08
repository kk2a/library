#ifndef KK2_STRING_ROLLING_HASH_HPP
#define KK2_STRING_ROLLING_HASH_HPP 1

#include <cassert>
#include <string>
#include <vector>

#include "../random/hash.hpp"
#include "../type_traits/container_traits.hpp"

namespace kk2 {

/**
 * @brief 文字の変更が行われない文字列に対する静的なローリングハッシュ
 *
 * @tparam NUM
 */
template <int NUM> struct StaticRollingHash {
    using H = random::Hash<NUM>;
    static inline std::vector<H> pw, pwi;
    std::vector<H> prefix;

    StaticRollingHash() {}
    template <class T, is_integral_t<T> * = nullptr> StaticRollingHash(T v) : prefix({H(v)}) {}
    template <class C, is_container_t<C> * = nullptr> StaticRollingHash(const C &c) {
        if (c.empty()) return;
        extend_base(c.size());
        prefix.resize(c.size());
        prefix[0] = H(c[0]);
        for (size_t i = 1; i < c.size(); ++i) prefix[i] = prefix[i - 1] + H(c[i]) * pw[i];
    }

    inline int size() const { return prefix.size(); }

    // `i`番目の文字のハッシュ値を取得する
    H get(int i) const {
        assert(0 <= i and i < (int)prefix.size());
        if (i == 0) return prefix[i];
        return (prefix[i] - prefix[i - 1]) * pwi[i];
    }

    // `[l, r)`のハッシュ値を取得する
    H get(int l, int r) const {
        assert(0 <= l and l <= r and r <= (int)prefix.size());
        if (l == r) return H(0);
        if (l == 0) return prefix[r - 1];
        return (prefix[r - 1] - prefix[l - 1]) * pwi[l];
    }

    /**
     * @brief 文字列`lhs[l1, r1)`と`rhs[l2, r2)`の最長共通接頭辞を求める
     *
     * 時間計算量: `O(log(min(r1 - l1, r2 - l2)))`
     * @param lhs 文字列`lhs`のローリングハッシュ
     * @param l1 `lhs`の開始インデックス
     * @param r1 `lhs`の終了インデックス
     * @param rhs 文字列`rhs`のローリングハッシュ
     * @param l2 `rhs`の開始インデックス
     * @param r2 `rhs`の終了インデックス
     * @return `lhs[l1, l1 + lcp)`と`rhs[l2, l2 + lcp)`の最長共通接頭辞の長さ
     */
    static int lcp(const StaticRollingHash &lhs,
                   int l1,
                   int r1,
                   const StaticRollingHash &rhs,
                   int l2,
                   int r2) {
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

    /**
     * @brief 文字列`lhs[l1, r1)`と`rhs[l2, r2)`の辞書順比較を行う
     *
     * 時間計算量: `O(log(min(r1 - l1, r2 - l2)))`
     * @param lhs 文字列`lhs`のローリングハッシュ
     * @param l1 `lhs`の開始インデックス
     * @param r1 `lhs`の終了インデックス
     * @param rhs 文字列`rhs`のローリングハッシュ
     * @param l2 `rhs`の開始インデックス
     * @param r2 `rhs`の終了インデックス
     * @return `-1: lhs < rhs, 0: lhs == rhs, 1: lhs > rhs`
     */
    static int strcmp(const StaticRollingHash &lhs,
                      int l1,
                      int r1,
                      const StaticRollingHash &rhs,
                      int l2,
                      int r2) {
        int lcp_ = lcp(lhs, l1, r1, rhs, l2, r2);
        if (lcp_ == r1 - l1 and lcp_ == r2 - l2) return 0;
        else if (lcp_ == r1 - l1) return -1;
        else if (lcp_ == r2 - l2) return 1;
        else {
            auto c1 = lhs.get(l1 + lcp_)[0].val();
            auto c2 = rhs.get(l2 + lcp_)[0].val();
            return c1 < c2 ? -1 : 1;
        }
    }

    /**
     * @brief 文字列`lhs`と`rhs`のローリングハッシュを結合する
     *
     * 時間計算量: `O(lhs.size() + rhs.size())`
     *
     * @param lhs 文字列`lhs`のローリングハッシュ
     * @param rhs 文字列`rhs`のローリングハッシュ
     * @return 結合されたローリングハッシュ
     */
    static StaticRollingHash merge(const StaticRollingHash &lhs, const StaticRollingHash &rhs) {
        if (lhs.prefix.empty()) return rhs;
        if (rhs.prefix.empty()) return lhs;
        StaticRollingHash res;
        int n = lhs.prefix.size(), m = rhs.prefix.size();
        extend_base(n + m);
        res.prefix.resize(n + m);
        for (int i = 0; i < n; ++i) res.prefix[i] = lhs.prefix[i];
        for (int i = n; i < n + m; ++i)
            res.prefix[i] = res.prefix[n - 1] + rhs.prefix[i - n] * pw[n];
        return res;
    }

  private:
    static void extend_base(int m) {
        if (pw.size() == 0u) pw = {H(1), H::get_base()}, pwi = {H(1), pw[1].inv()};

        int n = pw.size();
        if (n > m) return;
        pw.resize(m + 1), pwi.resize(m + 1);
        for (int i = n; i <= m; ++i) pw[i] = pw[i - 1] * pw[1], pwi[i] = pwi[i - 1] * pwi[1];
    }
};

using SRoliha = StaticRollingHash<2>;

} // namespace kk2


#endif // KK2_STRING_ROLLING_HASH_HPP
