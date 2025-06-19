#ifndef KK2_STRING_DYNAMIC_ROLLING_HASH_HPP
#define KK2_STRING_DYNAMIC_ROLLING_HASH_HPP

#include <cassert>
#include <vector>

#include "../bit/bitcount.hpp"
#include "../random/hash.hpp"
#include "../type_traits/container_traits.hpp"

namespace kk2 {

/**
 * @brief 文字の一点更新が可能文字列に対する動的なローリングハッシュ
 *
 * @tparam NUM
 */
template <int NUM> struct DynamicRollingHash {
    using H = random::Hash<NUM>;
    int _n, lg, siz;
    std::vector<H> d;
    bool is_built = false;

    DynamicRollingHash() {}
    DynamicRollingHash(int n) : _n(n) {
        lg = 0;
        while ((1 << lg) < _n) lg++;
        extend_base(lg + 1);
        siz = 1 << lg;
        d.resize(2 * siz);
    }
    template <class C, is_container_t<C> * = nullptr> DynamicRollingHash(const C &c) {
        _n = c.size();
        lg = 0;
        extend_base(_n + 1);
        while ((1 << lg) < _n) lg++;
        siz = 1 << lg;
        d.resize(2 * siz);
        for (int i = 0; i < _n; i++) d[siz + i] = H(c[i]);
        build();
    }

    inline int size() const { return _n; }

    void build() {
        assert(!is_built);
        is_built = true;
        for (int i = siz - 1; i >= 1; i--) update(i);
    }

    template <class T> void init_set(int p, T x) {
        assert(0 <= p && p < _n);
        assert(!is_built);
        d[siz + p] = H(x);
    }

    template <class T> void set(int p, T x) {
        assert(0 <= p && p < _n);
        assert(is_built);
        p += siz;
        d[p] = H(x);
        for (int i = 1; i <= lg; i++) update(p >> i);
    }

    H get(int i) const {
        assert(0 <= i && i < _n);
        assert(is_built);
        return d[siz + i];
    }

    /**
     * @brief `[l, r)`のハッシュ値を取得する
     *
     * 時間計算量: `O(log(r - l))`
     *
     * @return `[l, r)`のハッシュ値
     */
    H get(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        assert(is_built);
        H sml = H(0), smr = H(0);
        l += siz, r += siz;
        int l_siz = 0;

        while (l < r) {
            if (l & 1) sml = sml + d[l] * pw[l_siz], l++, l_siz += inner_size(l);
            if (r & 1) --r, smr = d[r] + smr * pw[inner_size(r)];
            l >>= 1, r >>= 1;
        }
        return sml + smr * pwi[l_siz];
    }

    H all_prod() const {
        assert(is_built);
        return d[1];
    }

    /**
     * @brief 文字列`lhs[l1, r1)`と`rhs[l2, r2)`の最長共通接頭辞を求める
     *
     * 時間計算量: `O(log^2(min(r1 - l1, r2 - l2)))`
     * @param lhs 文字列`lhs`のローリングハッシュ
     * @param l1 `lhs`の開始インデックス
     * @param r1 `lhs`の終了インデックス
     * @param rhs 文字列`rhs`のローリングハッシュ
     * @param l2 `rhs`の開始インデックス
     * @param r2 `rhs`の終了インデックス
     * @return `lhs[l1, l1 + lcp)`と`rhs[l2, l2 + lcp)`の最長共通接頭辞の長さ
     */
    static int lcp(const DynamicRollingHash &lhs,
                   int l1,
                   int r1,
                   const DynamicRollingHash &rhs,
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
     * 時間計算量: `O(log^2(min(r1 - l1, r2 - l2)))`
     * @param lhs 文字列`lhs`のローリングハッシュ
     * @param l1 `lhs`の開始インデックス
     * @param r1 `lhs`の終了インデックス
     * @param rhs 文字列`rhs`のローリングハッシュ
     * @param l2 `rhs`の開始インデックス
     *  @param r2 `rhs`の終了インデックス
     * @return `-1: lhs < rhs, 0: lhs == rhs, 1: lhs > rhs`
     */
    static int strcmp(const DynamicRollingHash &lhs,
                      int l1,
                      int r1,
                      const DynamicRollingHash &rhs,
                      int l2,
                      int r2) {
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

    /**
     * @brief 文字列`lhs`と`rhs`を結合して新しいローリングハッシュを作成する
     *
     * 時間計算量: `O(n + m)` (n: lhsの長さ, m: rhsの長さ)
     * @param lhs 文字列`lhs`のローリングハッシュ
     * @param rhs 文字列`rhs`のローリングハッシュ
     * @return 結合後のローリングハッシュ
     */
    static DynamicRollingHash merge(const DynamicRollingHash &lhs, const DynamicRollingHash &rhs) {
        DynamicRollingHash res(lhs._n + rhs._n);
        for (int i = 0; i < lhs._n; i++) res.init_set(i, lhs.get(i));
        for (int i = 0; i < rhs._n; i++) res.init_set(lhs._n + i, rhs.get(i));
        res.build();
        return res;
    }

  private:
    static inline std::vector<H> pw, pwi;
    static void extend_base(int m) {
        if (pw.size() == 0u) pw = {H(1), H::get_base()}, pwi = {H(1), pw[1].inv()};

        int n = pwpw.size();
        if (n > m) return;
        pw.resize(m + 1), pwi.resize(m + 1);
        for (int i = n; i <= m; ++i) pw[i] = pw[i - 1] * pw[1], pwi[i] = pwi[i - 1] * pwi[1];
    }

    inline int inner_size(int k) const { return 1 << (lg - msb(k)); }
    inline void update(int k) { d[k] = d[2 * k] + d[2 * k + 1] * inner_size(2 * k); }
};

using DRoliha = DynamicRollingHash<2>;

} // namespace kk2

#endif // KK2_STRING_DYNAMIC_ROLLING_HASH_HPP
