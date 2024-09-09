#ifndef FPS_MULTI_EVAL_HPP
#define FPS_MULTI_EVAL_HPP 1

#include <functional>
#include <vector>

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type>
struct SubProductTree {
    int _n, size;
    std::vector<int> l, r;
    std::vector<FPS> pr;
    std::vector<mint> v;
    FPS f;

    SubProductTree(const std::vector<mint> &v_) : _n(int(v_.size())), v(v_) {
        size = 1;
        while (size < (unsigned int)(_n)) size <<= 1;
        pr.resize(size << 1);
        l.resize(size << 1, _n);
        r.resize(size << 1, _n);
        build();
    }

    SubProductTree(const std::vector<mint> &v_, const FPS &f_)
        : SubProductTree(v_) {
        this->f = f_;
    }

    void set(const FPS &f_) { this->f = f_; }

    void build() {
        for (int i = 0; i < _n; i++) {
            l[i + size] = i;
            r[i + size] = i + 1;
            pr[i + size] = {-v[i], 1};
        }
        for (int i = size - 1; i > 0; i--) {
            l[i] = l[i << 1 | 0];
            r[i] = r[i << 1 | 1];
            if (pr[i << 1 | 0].empty()) continue;
            else if (pr[i << 1 | 1].empty()) pr[i] = pr[i << 1 | 0];
            else pr[i] = pr[i << 1 | 0] * pr[i << 1 | 1];
        }
    }

    std::vector<mint> query(const FPS &f) {
        this->f = f;
        return query();
    }

    std::vector<mint> query() {
        if (f.empty() || !_n) return FPS(_n, mint(0));
        std::vector<mint> ret;
        ret.reserve(_n);
        auto rec = [&](auto self, FPS a, int idx) -> void {
            if (l[idx] == r[idx]) return;
            a %= pr[idx];
            if ((int)a.size() <= 64) {
                for (int i = l[idx]; i < r[idx]; i++) {
                    ret.push_back(a.eval(v[i]));
                }
                return;
            }
            self(self, a, idx << 1 | 0);
            self(self, a, idx << 1 | 1);
        };
        rec(rec, f, 1);
        return ret;
    }
};

template <class FPS, class mint = typename FPS::value_type>
std::vector<mint> MultiEval(std::vector<mint> v, const FPS &f) {
    SubProductTree<FPS> mpe(v, f);
    return mpe.query();
}

} // namespace kk2

#endif // FPS_MULTI_EVAL_HPP
