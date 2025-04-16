#ifndef KK2_DATA_STRUCTURE_WAVELET_MATRIX_HPP
#define KK2_DATA_STRUCTURE_WAVELET_MATRIX_HPP 1

#include <algorithm>
#include <vector>

#include "../bit/bitcount.hpp"
#include "bit_vector.hpp"

namespace kk2 {

template <typename T> struct WaveletMatrix {
    int n, lg;
    std::vector<T> a;
    std::vector<BitVector> mat;
    bool built = false;

    WaveletMatrix() = default;

    WaveletMatrix(int n_) : n(n_), a(n_) {}

    WaveletMatrix(const std::vector<T> &a_) : n(a_.size()), a(a_) { build(); }

    void build() {
        built = true;
        lg = 0;
        T mx = *std::max_element(a.begin(), a.end());
        if (mx <= 0) mx = 1;
        lg = msb(mx) + 1;
        mat.resize(lg, BitVector(n));
        std::vector<T> now(a), nxt(n);
        for (int i = lg - 1; i >= 0; --i) {
            BitVector &bv = mat[i];
            for (int j = 0; j < n; ++j) {
                if ((now[j] >> i) & 1) bv.set(j);
            }
            bv.build();
            int one = bv.zeros, zero = 0;
            for (int j = 0; j < n; ++j) {
                if ((now[j] >> i) & 1) {
                    nxt[one++] = now[j];
                } else {
                    nxt[zero++] = now[j];
                }
            }
            std::swap(now, nxt);
        }
    }

    void set(int i, T x) {
        assert(0 <= i && i < n);
        assert(x >= 0);
        assert(!built);
        a[i] = x;
    }

    T access(int k) const {
        assert(0 <= k && k < n);
        return a[k];
    }

    int rank(T b, int k) {
        assert(0 <= k && k <= n);
        int l = 0, r = k;
        for (int i = lg - 1; i >= 0; --i) {
            r = (b >> i & 1) ? mat[i].rank1(r) + mat[i].zeros : mat[i].rank0(r);
            l = (b >> i & 1) ? mat[i].rank1(l) + mat[i].zeros : mat[i].rank0(l);
        }
        return r - l;
    }

    int select(T b, int k) {
        assert(0 <= k && k < n);
        int l = 0;
        for (int i = lg - 1; i >= 0; --i)
            l = (b >> i & 1) ? mat[i].rank1(l) + mat[i].zeros : mat[i].rank0(l);
        k += l;
        for (int i = 0; i < lg; ++i) {
            k = (b >> i & 1) ? mat[i].select1(k - mat[i].zeros) : mat[i].select0(k);
            if (k == -1) return -1;
        }
        return k;
    }

    T kth_smallest(int l, int r, int k) const {
        assert(0 <= l && l <= r && r <= n);
        assert(r - l > k);
        T res = 0;
        for (int i = lg - 1; i >= 0; --i) {
            int ll = mat[i].rank0(l), rr = mat[i].rank0(r);
            if (k < rr - ll) {
                l = ll, r = rr;
            } else {
                k -= rr - ll;
                res |= T(1) << i;
                l += mat[i].zeros - ll;
                r += mat[i].zeros - rr;
            }
        }
        return res;
    }

    T kth_largest(int l, int r, int k) const {
        assert(0 <= l && l <= r && r <= n);
        assert(r - l > k);
        return kth_smallest(l, r, r - l - k - 1);
    }

    int range_freq(int l, int r, T upper) const {
        assert(0 <= l && l <= r && r <= n);
        assert(0 <= upper);
        if (upper >> lg) return r - l;
        int res = 0;
        for (int i = lg - 1; i >= 0; --i) {
            if (upper >> i & 1) res += mat[i].rank0(r) - mat[i].rank0(l);
            l = (upper >> i & 1) ? mat[i].rank1(l) + mat[i].zeros : mat[i].rank0(l);
            r = (upper >> i & 1) ? mat[i].rank1(r) + mat[i].zeros : mat[i].rank0(r);
            if (l == r) break;
        }
        return res;
    }

    int range_freq(int l, int r, T lower, T upper) {
        assert(0 <= l && l <= r && r <= n);
        assert(0 <= lower && lower <= upper);
        return range_freq(l, r, upper) - range_freq(l, r, lower);
    }

    T max_not_greater(int l, int r, T b) {
        assert(0 <= l && l <= r && r <= n);
        int count = range_freq(l, r, b + 1);
        return count == 0 ? -1 : kth_smallest(l, r, count - 1);
    }

    T min_not_less(int l, int r, T b) {
        assert(0 <= l && l <= r && r <= n);
        int count = range_freq(l, r, b);
        return count == r - l ? -1 : kth_smallest(l, r, count);
    }
};

} // namespace kk2


#endif // KK2_DATA_STRUCTURE_WAVELET_MATRIX_HPP
