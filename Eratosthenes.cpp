struct Erato {
    vector<bool> isprime;
    vector<int> minfactor;
    vector<int> mobius;
    vector<int> primes;

    Erato(int N) : isprime(N + 1, true), minfactor(N + 1, -1),
                   mobius(N + 1, 1) {
        isprime[1] = false;
        minfactor[1] = 1;

        for (int p = 2; p <= N; ++p) {
            if (!isprime[p]) continue;

            minfactor[p] = p;
            mobius[p] = -1;
            primes.emplace_back(p);
            
            for (int q = p * 2; q <= N; q += p) {
                isprime[q] = false;
                
                if (minfactor[q] == -1) minfactor[q] = p;
                if ((q / p) % p == 0) mobius[q] = 0;
                else mobius[q] = -mobius[q];
            }
        }
    }

    vector<pair<int, int>> factorize(int n) {
        vector<pair<int, int>> res;
        while (n > 1) {
            int p = minfactor[n];
            int exp = 0;

            while (minfactor[n] == p) {
                n /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }  

    vector<int> divisors(int n) {
        vector<int> res({1});
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
