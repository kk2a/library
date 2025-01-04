#ifndef KK2_FPS_POLY_FIND_ROOT_HPP
#define KK2_FPS_POLY_FIND_ROOT_HPP 1

#include <vector>

#include "../random/gen.hpp"
#include "mod_pow.hpp"
#include "poly_gcd.hpp"

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type>
std::vector<mint> find_root(const FPS &f) {
    long long p = mint::getmod();
    std::vector<mint> res;
    if (p == 2) {
        for (int i = 0; i < 2; i++) {
            if (f.eval(mint(i)) == mint(0)) { res.push_back(mint(i)); }
        }
        return res;
    }

    std::vector<FPS> fs;
    fs.push_back(poly_gcd(mod_pow(p, FPS{0, 1}, f) - FPS{0, 1}, f));
    while (!fs.empty()) {
        auto g = fs.back();
        fs.pop_back();
        if (g.size() == 2) res.push_back(-g[0]);
        if (g.size() <= 2) continue;
        FPS s = FPS{random::rng(0, p), 1};
        FPS t = poly_gcd(mod_pow((p - 1) / 2, s, g) - FPS{1}, g);
        fs.push_back(t);
        if (g.size() != t.size()) fs.push_back(g / t);
    }
    return res;
}

} // namespace kk2

#endif // KK2_FPS_POLY_FIND_ROOT_HPP
