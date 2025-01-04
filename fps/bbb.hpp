#ifndef KK2_FPS_BBB_HPP
#define KK2_FPS_BBB_HPP 1

#include <vector>

#include "multi_eval.hpp"

namespace kk2 {

// f(X) / \prod (X - a_i) = \sum c_i / (X - a_i)
// return {c_i}
template <class FPS, class mint = typename FPS::value_type>
std::vector<mint> BBB(const std::vector<mint> &a, const FPS &f) {
    if (a.empty() || f.empty()) return std::vector<mint>(a.size(), mint());
    int n = (int)a.size();
    SubProductTree<FPS> mpe(a);
    FPS gp = mpe.pr[1].diff();
    std::vector<mint> gpv = mpe.query(gp);
    std::vector<mint> fv = mpe.query(f);
    std::vector<mint> ret(n);
    for (int i = 0; i < n; i++) ret[i] = fv[i] / gpv[i];
    return ret;
}

// f(X) / \prod (1 - a_i X) = \sum c_i / (1- a_i X)
// return {c_i}
template <class FPS, class mint = typename FPS::value_type>
std::vector<mint> BBB1(const std::vector<mint> &a, const FPS &f) {
    if (a.empty() || f.empty()) return std::vector<mint>(a.size(), mint(0));
    int n = (int)a.size();
    std::vector<mint> ima(a.size());
    mint prod = 1;
    for (int i = 0; i < (int)a.size(); i++) {
        ima[i] = a[i].inv();
        prod *= -ima[i];
    }
    std::vector<mint> ret = BBB(ima, f);
    for (int i = 0; i < n; i++) ret[i] *= -a[i] * prod;
    return ret;
}

} // namespace kk2

#endif // KK2_FPS_BBB_HPP
