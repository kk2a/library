#ifndef FIND_ROOT_HPP
#define FIND_ROOT_HPP 1

#include "poly_gcd.hpp"
#include "mod_pow.hpp"

template <class FPS, class mint = typename FPS::value_type>
vector<mint> find_root(FPS f) {
    long long p = mint::getmod();
    vector<mint> res;
    if (p == 2) {
        for (int i = 0; i < 2; i++) {
            if (f.eval(mint(i)) == mint(0)) {
                res.push_back(mint(i));
            }
        }
        return res;
    }

    vector<FPS> fs;
    fs.push_back(PolyGcd(mod_pow(p, FPS{0, 1}, f) - FPS{0, 1}, f));
    mt19937_64 rng(time(0));
    while (!fs.empty()) {
        auto g = fs.back();
        fs.pop_back();
        if (g.size() == 2) res.push_back(-g[0]);
        if (g.size() <= 2) continue;
        FPS s = FPS{(long long)(rng() % p), 1};
        FPS t = PolyGcd(mod_pow((p - 1) / 2, s, g) - FPS{1}, g);
        fs.push_back(t);
        if (g.size() != t.size()) fs.push_back(g / t);
    }
    return res;
}

#endif // FIND_ROOT_HPP
