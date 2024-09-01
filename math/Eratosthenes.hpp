#ifndef MATH_ERATOSTHENES
#define MATH_ERATOSTHENES 1

namespace kk2 {

struct Erato {
    static inline vector<bool> _isprime{};
    static inline vector<int> _minfactor{}, _mobius{}, _primes{};

    Erato() = delete;

    static void set_upper(int m) {
        _isprime.resize(m + 1, true);
        _minfactor.resize(m + 1, -1);
        _mobius.resize(m + 1, 1);
        _isprime[1] = false;
        _minfactor[1] = 1;

        for (int p = 2; p <= m; ++p) {
            if (!_isprime[p]) continue;

            _minfactor[p] = p;
            _mobius[p] = -1;
            _primes.emplace_back(p);

            for (int q = p * 2; q <= m; q += p) {
                _isprime[q] = false;

                if (_minfactor[q] == -1) _minfactor[q] = p;
                if ((q / p) % p == 0) _mobius[q] = 0;
                else _mobius[q] = -_mobius[q];
            }
        }
    }

    static bool isprime(int n) {
        assert(n < (int)_isprime.size() && n != 0);
        return _isprime[n];
    }

    static int mobius(int n) {
        assert(n < (int)_mobius.size() && n != 0);
        return _mobius[n];
    }

    static int minfactor(int n) {
        assert(n < (int)_minfactor.size() && n != 0);
        return _minfactor[n];
    }

    static vector<int> primes() {
        return _primes;
    }

    static vector<pair<int, int>> factorize(int n) {
        assert(n < (int)_isprime.size() && n != 0);
        if (n == 1 || n == -1) return {};
        if (n < 0) n = -n;
        vector<pair<int, int>> res;
        while (n > 1) {
            int p = _minfactor[n];
            int exp = 0;

            while (_minfactor[n] == p) {
                n /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }

    static vector<int> divisors(int n) {
        assert(n < (int)_isprime.size() && n != 0);
        if (n == 1 || n == -1) return {1};
        if (n < 0) n = -n;
        vector<int> res{1};
        auto pf = factorize(n);

        for (auto p : pf) {
            int s = (int)res.size();
            for (int i = 0; i < s; ++i) {
                int v = 1;
                for (int j = 0; j < p.second; ++j) {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }
};

} // namespace kk2

#endif // MATH_ERATOSTHENES
