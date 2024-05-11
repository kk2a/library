#ifndef MOD_COMB_HPP
#define MOD_COMB_HPP 1

template <class mint>
struct Comb {
    vector<mint> _frac, _ifrac, _inv;
    Comb(int max = 0) {
        _frac.resize(1, mint(1));
        _ifrac.resize(1, mint(1));
        _inv.resize(1, mint(1));
        if (max > 0) extend(max);
    }

    void extend(int m = -1) {
        int n = (int)_frac.size();
        if (m == -1) m = n << 1;
        if (n >= m) return;
        m = min<int>(m, mint::getmod() - 1);
        _frac.resize(m + 1);
        _ifrac.resize(m + 1);
        _inv.resize(m + 1);
        for (int i = n; i <= m; i++) _frac[i] = _frac[i - 1] * i;
        _ifrac[m] = _frac[m].inv();
        _inv[m] = _ifrac[m] * _frac[m - 1];
        for (int i = m; i > n; i--) {
            _ifrac[i - 1] = _ifrac[i] * i;
            _inv[i - 1] = _ifrac[i - 1] * _frac[i - 2];
        }
    }

    mint frac(int n) {
        if (n < 0) return 0;
        if ((int)_frac.size() <= n) extend(n);
        return _frac[n];
    }

    mint ifrac(int n) {
        if (n < 0) return 0;
        if ((int)_ifrac.size() <= n) extend(n);
        return _ifrac[n];
    }

    mint inv(int n) {
        if (n < 0) return -inv(-n);
        if ((int)_inv.size() <= n) extend(n);
        return _inv[n];
    }

    mint binom(int n, int k) {
        if (n < 0 || k < 0 || k > n) return 0;
        return frac(n) * ifrac(k) * ifrac(n - k);
    }

    inline mint operator()(int n, int k) { return binom(n, k); }

    template <class T>
    mint multinomial(const vector<T>& r) {
        static_assert(is_integral_v<T>, "T must be integral");
        int n = 0;
        for (auto &x : r) {
            if (x < 0) return 0;
            n += x;
        }
        mint res = frac(n);
        for (auto &x : r) res *= ifrac(x);
        return res;
    }

    template <class T>
    mint operator()(const vector<T>& r) { return multinomial(r); }

    mint binom_naive(int n, int k) {
        if (n < 0 || k < 0 || k > n) return 0;
        mint res = 1;
        k = min(k, n - k);
        for (int i = 1; i <= k; i++) res *= inv(i) * (n--);
        return res;
    }

    mint permu(int n, int k) {
        if (n < 0 || k < 0 || k > n) return 0;
        return frac(n) * ifrac(n - k);
    }

    mint homo(int n, int k) {
        if (n < 0 || k < 0) return 0;
        return k == 0 ? 1 : binom(n + k - 1, k);
    }
};

#endif // MOD_COMB_HPP
