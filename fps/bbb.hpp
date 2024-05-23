#ifndef FPS_BBB_HPP
#define FPS_BBB_HPP 1

#include "multi_eval.hpp"

// f(X) / \prod (X - a_i) = \sum c_i / (X - a_i)
// return {c_i}
template <class FPS, class mint = typename FPS::value_type>
vector<mint> BBB(const vector<mint> &a, const FPS &f) {
    if (a.empty() || f.empty()) return vector<mint>(a.size(), mint(0));
    int n = (int)a.size();
    MultiPointEvaluation<FPS> mpe(a);
    FPS gp = mpe.pr[1].diff();
    vector<mint> gpv = mpe.query(gp);
    vector<mint> fv = mpe.query(f);
    vector<mint> ret(n);
    for (int i = 0; i < n; i++) ret[i] = fv[i] / gpv[i];
    return ret;
}

// f(X) / \prod (1 - a_i X) = \sum c_i / (1- a_i X)
// return {c_i}
template <class FPS, class mint = typename FPS::value_type>
vector<mint> BBB1(const vector<mint> &a, const FPS &f) {
    if (a.empty() || f.empty()) return vector<mint>(a.size(), mint(0));
    int n = (int)a.size();
    vector<mint> ima(a.size());
    mint prod = 1;
    for (int i = 0; i < (int)a.size(); i++) {
        ima[i] = a[i].inv();
        prod *= -ima[i];
    }
    vector<mint> ret = BBB(ima, f);
    for (int i = 0; i < n; i++) ret[i] *= -a[i] * prod;
    return ret;
}

#endif // FPS_BBB_HPP
