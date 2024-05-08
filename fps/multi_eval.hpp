#ifndef FPS_MULTI_EVAL_HPP
#define FPS_MULTI_EVAL_HPP 1

#include <kk2/fps/fps.hpp>

template <class mint>
struct MultiPointEvaluation {
    using FPS = FormalPowerSeries<mint>;

    MultiPointEvaluation(const vector<mint> &v_, bool flag = false) : _n(int(v_.size())), v(v_) {
        log = 0;
        while ((1u << log) < (unsigned int)(_n)) log++;
        size = 1 << log;
        pr.resize(size << 1);
        l.resize(size << 1, _n);
        r.resize(size << 1, _n);
        siz.resize(size << 1, 0);
        inv2.resize(30);
        if (flag) build_ntt();
        else build();
    }
    MultiPointEvaluation(const vector<mint> &v_, const FPS &f_, bool flag = true) :
        MultiPointEvaluation(v_, flag) {
        this->f = f_;
    }

    void set(const FPS &f_) {
        this->f = f_;
    }

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

    // 遅い
    void build_ntt() {
        inv2[0] = mint(1);
        inv2[1] = mint(2).inv();
        for (int i = 2; i < 30; i++) inv2[i] = inv2[i - 1] * inv2[1];

        FPS g;
        g.reserve(size << 1);
        for (int i = 0; i < _n; i++) {
            l[i + size] = i;
            r[i + size] = i + 1;
            pr[i + size] = {-v[i] + 1, -v[i] - 1};
            siz[i + size] = 1;
        }
        for (int i = size - 1; i > 0; i--) {
            l[i] = l[i << 1 | 0];
            r[i] = r[i << 1 | 1];
            if (pr[i << 1 | 0].empty()) continue;
            else if (pr[i << 1 | 1].empty()) {
                pr[i] = pr[i << 1 | 0];
                siz[i] = siz[i << 1 | 0];
            }
            else if (pr[i << 1 | 0].size() == pr[i << 1 | 1].size()) {
                pr[i] = pr[i << 1 | 0];
                g.clear();
                copy(begin(pr[i << 1 | 1]), end(pr[i << 1 | 1]),
                     back_inserter(g));
                pr[i].db();
                g.db();
                pr[i].inplace_dot(g);
                siz[i] = siz[i << 1 | 0] + 1;
            }
            else {
                pr[i] = pr[i << 1 | 0];
                g.clear();
                copy(begin(pr[i << 1 | 1]), end(pr[i << 1 | 1]),
                     back_inserter(g));
                pr[i].db();
                g.ibut(); g *= inv2[siz[i << 1 | 1]];
                g.resize(pr[i].size(), mint(0));
                g.but();
                pr[i].inplace_dot(g);
                siz[i] = siz[i << 1 | 0];
            }
        }
        for (int i = 1; i < size << 1; i++) {
            pr[i].ibut(); pr[i] *= inv2[siz[i]];
            pr[i].shrink();
        }
    }

    vector<FPS> query(const FPS &f) {
        this->f = f;
        return query();
    }

    vector<mint> query() {
        if (f.empty() || !_n) return FPS(_n, mint(0));
        vector<mint> ret;
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

  private:
    int _n, size, log;
    vector<int> l, r, siz;
    vector<FPS> pr;
    vector<mint> v;
    // 2 ^ i
    vector<mint> inv2;
    FPS f;
};

#endif // FPS_MULTI_EVAL_HPP