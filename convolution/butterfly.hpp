#ifndef BUTTERFLY_HPP
#define BUTTERFLY_HPP 1

#include <algorithm>

#include "../math_mod/primitive_root.hpp"

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type>
void butterfly(FPS &a) {
    static int g = primitive_root<mint::getmod()>;
    int n = int(a.size());
    int h = 0;
    while ((1U << h) < (unsigned int)(n)) h++;
    static bool first = true;
    static mint sum_e2[30]; // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]
    static mint sum_e3[30];
    static mint es[30], ies[30]; // es[i]^(2^(2+i)) == 1
    if (first) {
        first = false;
        int cnt2 = __builtin_ctz(mint::getmod() - 1);
        mint e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();
        for (int i = cnt2; i >= 2; i--) {
            // e^(2^i) == 1
            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mint now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_e2[i] = es[i] * now;
            now *= ies[i];
        }
        now = 1;
        for (int i = 0; i <= cnt2 - 3; i++) {
            sum_e3[i] = es[i + 1] * now;
            now *= ies[i + 1];
        }
    }

    int len = 0;
    while (len < h) {
        if (h - len == 1) {
            int p = 1 << (h - len - 1);
            mint rot = 1;
            for (int s = 0; s < (1 << len); s++) {
                int offset = s << (h - len);
                for (int i = 0; i < p; i++) {
                    auto l = a[i + offset];
                    auto r = a[i + offset + p] * rot;
                    a[i + offset] = l + r;
                    a[i + offset + p] = l - r;
                }
                if (s + 1 != (1 << len))
                    rot *= sum_e2[__builtin_ctz(~(unsigned int)(s))];
            }
            len++;
        } else {
            int p = 1 << (h - len - 2);
            mint rot = 1, imag = es[0];
            for (int s = 0; s < (1 << len); s++) {
                mint rot2 = rot * rot;
                mint rot3 = rot2 * rot;
                int offset = s << (h - len);
                for (int i = 0; i < p; i++) {
                    auto a0 = a[i + offset];
                    auto a1 = a[i + offset + p] * rot;
                    auto a2 = a[i + offset + p * 2] * rot2;
                    auto a3 = a[i + offset + p * 3] * rot3;
                    auto a1na3imag = (a1 - a3) * imag;
                    a[i + offset] = a0 + a2 + a1 + a3;
                    a[i + offset + p] = a0 + a2 - a1 - a3;
                    a[i + offset + p * 2] = a0 - a2 + a1na3imag;
                    a[i + offset + p * 3] = a0 - a2 - a1na3imag;
                }
                if (s + 1 != (1 << len))
                    rot *= sum_e3[__builtin_ctz(~(unsigned int)(s))];
            }
            len += 2;
        }
    }
}

template <class FPS, class mint = typename FPS::value_type>
void butterfly_inv(FPS &a) {
    static constexpr int g = primitive_root<mint::getmod()>;
    int n = int(a.size());
    int h = 0;
    while ((1U << h) < (unsigned int)(n)) h++;
    static bool first = true;
    static mint sum_ie2[30]; // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]
    static mint sum_ie3[30];
    static mint es[30], ies[30]; // es[i]^(2^(2+i)) == 1
    static mint invn[30];
    if (first) {
        first = false;
        int cnt2 = __builtin_ctz(mint::getmod() - 1);
        mint e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();
        for (int i = cnt2; i >= 2; i--) {
            // e^(2^i) == 1
            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mint now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_ie2[i] = ies[i] * now;
            now *= es[i];
        }
        now = 1;
        for (int i = 0; i <= cnt2 - 3; i++) {
            sum_ie3[i] = ies[i + 1] * now;
            now *= es[i + 1];
        }

        invn[0] = 1;
        invn[1] = mint::getmod() / 2 + 1;
        for (int i = 2; i < 30; i++) invn[i] = invn[i - 1] * invn[1];
    }
    int len = h;
    while (len) {
        if (len == 1) {
            int p = 1 << (h - len);
            mint irot = 1;
            for (int s = 0; s < (1 << (len - 1)); s++) {
                int offset = s << (h - len + 1);
                for (int i = 0; i < p; i++) {
                    auto l = a[i + offset];
                    auto r = a[i + offset + p];
                    a[i + offset] = l + r;
                    a[i + offset + p] = (l - r) * irot;
                }
                if (s + 1 != (1 << (len - 1)))
                    irot *= sum_ie2[__builtin_ctz(~(unsigned int)(s))];
            }
            len--;
        } else {
            int p = 1 << (h - len);
            mint irot = 1, iimag = ies[0];
            for (int s = 0; s < (1 << ((len - 2))); s++) {
                mint irot2 = irot * irot;
                mint irot3 = irot2 * irot;
                int offset = s << (h - len + 2);
                for (int i = 0; i < p; i++) {
                    auto a0 = a[i + offset];
                    auto a1 = a[i + offset + p];
                    auto a2 = a[i + offset + p * 2];
                    auto a3 = a[i + offset + p * 3];
                    auto a2na3iimag = (a2 - a3) * iimag;

                    a[i + offset] = a0 + a1 + a2 + a3;
                    a[i + offset + p] = (a0 - a1 + a2na3iimag) * irot;
                    a[i + offset + p * 2] = (a0 + a1 - a2 - a3) * irot2;
                    a[i + offset + p * 3] = (a0 - a1 - a2na3iimag) * irot3;
                }
                if (s + 1 != (1 << (len - 2)))
                    irot *= sum_ie3[__builtin_ctz(~(unsigned int)(s))];
            }
            len -= 2;
        }
    }

    for (int i = 0; i < n; i++) a[i] *= invn[h];
}

template <class FPS, class mint = typename FPS::value_type>
void doubling(FPS &a) {
    int n = a.size();
    auto b = a;
    int z = 1;
    butterfly_inv(b);
    mint r = 1, zeta = mint(primitive_root<mint::getmod()>)
                           .pow((mint::getmod() - 1) / (n << 1));
    for (int i = 0; i < n; i++) {
        b[i] *= r;
        r *= zeta;
    }
    butterfly(b);
    std::copy(b.begin(), b.end(), std::back_inserter(a));
}

} // namespace kk2

#endif // BUTTERFLY_HPP
