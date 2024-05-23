#ifndef FPS__SAMPLE_POINT_SHIFT__H
#define FPS__SAMPLE_POINT_SHIFT__H 1

template <class FPS, class mint = FPS::value_type>
vector<mint> SamplePointShift(vector<mint> &y, mint t, int m = -1) {
    if (m == -1) m = y.size();
    long long tval = t.val();
    int k = (int)y.size() - 1;
    if (tval <= k) {
        FPS ret(m);
        int ptr = 0;
        for (long long i = tval; i <= k and ptr < m; i++) {
            ret[ptr++] = y[i];
        }
        if (k + 1 < tval + m) {
            auto suf = SamplePointShift<FPS>(y, k + 1, m - ptr);
            for (int i = k + 1; i < tval + m; i++) {
                ret[ptr++] = suf[i - (k + 1)];
            }
        }
        return ret;
    }
    if (tval + m > mint::getmod()) {
        auto pref = SamplePointShift<FPS>(y, t, mint::getmod() - tval);
        auto suf = SamplePointShift<FPS>(y, 0, m - pref.size());
        copy(begin(suf), end(suf), back_inserter(pref));
        return pref;
    }

    vector<mint> inv(k + 1, 1);
    FPS d(k + 1);
    for (int i = 2; i <= k; i++) inv[k] *= i;
    inv[k] = inv[k].inv();
    for (int i = k; i >= 1; i--) inv[i - 1] = inv[i] * i;
    for (int i = 0; i <= k; i++) {
        d[i] = inv[i] * inv[k - i] * y[i];
        if ((k - i) & 1) d[i] = -d[i];
    }

    FPS h(m + k);
    for (int i = 0; i < m + k; i++) {
        h[i] = (t - k + i).inv();
    }

    FPS dh = d * h;

    vector<mint> ret(m);
    mint cur = t;
    for (int i = 1; i <= k; i++) cur *= t - i;
    for (int i = 0; i < m; i++) {
        ret[i] = cur * dh[k + i];
        cur *= t + i + 1;
        cur *= h[i];
    }
    return ret;
}

#endif // FPS__SAMPLE_POINT_SHIFT__H