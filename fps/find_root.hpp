#ifndef KK2_FPS_FIND_ROOT_HPP
#define KK2_FPS_FIND_ROOT_HPP 1

#include <ctime>
#include <random>
#include <vector>

#include "mod_pow.hpp"
#include "poly_gcd.hpp"

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type> std::vector<mint> find_root(FPS f) {
    long long p = mint::getmod();
    std::vector<mint> res;
    if (p == 2) {
        for (int i = 0; i < 2; i++) {
            if (f.eval(mint(i)) == mint(0)) { res.push_back(mint(i)); }
        }
        return res;
    }

    std::vector<FPS> fs;
    fs.push_back(PolyGcd(mod_pow(p, FPS{0, 1}, f) - FPS{0, 1}, f));
    std::mt19937_64 rng(time(0));
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

} // namespace kk2

#endif // KK2_FPS_FIND_ROOT_HPP
