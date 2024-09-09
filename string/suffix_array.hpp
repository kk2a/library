#ifndef STRING_SUFFIX_ARRAY_HPP
#define STRING_SUFFIX_ARRAY_HPP 1

#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>

namespace kk2 {

struct SuffixArray {
    SuffixArray() = default;

    SuffixArray(const std::string &s_)
        : _n((int)s_.size()),
          _s((int)s_.size()) {
        for (int i = 0; i < _n; ++i) _s[i] = s_[i];
        _upper = 255;
        init();
    }

    // all elements of s_ must be in [0, upper]
    SuffixArray(const std::vector<int> &s_, int upper_)
        : _n((int)s_.size()),
          _s(s_),
          _upper(upper_) {
        init();
    }

    template <class T>
    SuffixArray(const std::vector<T> &s_)
        : _n((int)s_.size()),
          _s((int)s_.size()) {
        std::vector<int> idx(_n);
        std::iota(std::begin(idx), std::end(idx), 0);
        std::sort(std::begin(idx), std::end(idx), [&](int l, int r) {
            return s_[l] < s_[r];
        });
        _upper = 0;
        for (int i = 0; i < _n; ++i) {
            if (i && s_[idx[i - 1]] != s_[idx[i]]) _upper++;
            _s[idx[i]] = _upper;
        }
        init();
    }

    std::vector<int> GetSA() const { return _sa; }

    bool op(int i, const std::string &t) const {
        int off = _sa[i];
        int m = std::min(_n - off, (int)t.size());
        for (int j = 0; j < m; ++j) {
            if (_s[off + j] != t[j]) return _s[off + j] < t[j];
        }
        return _n - off < (int)t.size();
    }

    bool op(int i, const std::vector<int> &t) const {
        int off = _sa[i];
        int m = std::min(_n - off, (int)t.size());
        for (int j = 0; j < m; ++j) {
            if (_s[off + j] != t[j]) return _s[off + j] < t[j];
        }
        return _n - off < (int)t.size();
    }

    // return the smallest index i s.t. s[sa[i]:] >= t
    int lower_bound(const std::vector<int> &t) const {
        int l = -1, r = _n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (op(m, t)) l = m;
            else r = m;
        }
        return r;
    }

    int lower_bound(const std::string &t) const {
        int l = -1, r = _n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (op(m, t)) l = m;
            else r = m;
        }
        return r;
    }

  private:
    int _n, _upper;
    std::vector<int> _sa, _s;

    std::vector<int> sa_naive(const std::vector<int> &s) {
        int n = (int)s.size();
        std::vector<int> sa(n);
        std::iota(std::begin(sa), std::end(sa), 0);
        std::sort(std::begin(sa), std::end(sa), [&](int l, int r) {
            if (l == r) return false;
            while (l < n && r < n) {
                if (s[l] != s[r]) return s[l] < s[r];
                l++;
                r++;
            }
            return l == n;
        });
        return sa;
    }

    std::vector<int> sa_doubling(const std::vector<int> &s, int upper) {
        int n = (int)s.size();
        std::vector<int> sa(n), cpy = s, tmp(n);
        std::iota(std::begin(sa), std::end(sa), 0);
        for (int len = 1; len < n; len <<= 1) {
            auto Compare = [&](int x, int y) {
                if (cpy[x] != cpy[y]) return cpy[x] < cpy[y];
                int rx = x + len < n ? cpy[x + len] : -1;
                int ry = y + len < n ? cpy[y + len] : -1;
                return rx < ry;
            };
            std::sort(std::begin(sa), std::end(sa), Compare);
            tmp[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                tmp[sa[i]] =
                    tmp[sa[i - 1]] + (Compare(sa[i - 1], sa[i]) ? 1 : 0);
            }
            std::swap(cpy, tmp);
        }
        return sa;
    }

    template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
    std::vector<int> sa_is(const std::vector<int> &s, int upper) {
        int n = (int)s.size();
        if (n == 0) return {};
        if (n == 1) return {0};
        if (n == 2) {
            if (s[0] < s[1]) return {0, 1};
            else return {1, 0};
        }
        if (n < THRESHOLD_NAIVE) return sa_naive(s);
        if (n < THRESHOLD_DOUBLING) return sa_doubling(s, upper);

        std::vector<int> sa(n);
        std::vector<bool> ls(n);
        for (int i = n - 2; i >= 0; i--) {
            ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
        }
        std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
        for (int i = 0; i < n; i++) {
            if (!ls[i]) sum_s[s[i]]++;
            else sum_l[s[i] + 1]++;
        }
        for (int i = 0; i <= upper; i++) {
            sum_s[i] += sum_l[i];
            if (i < upper) sum_l[i + 1] += sum_s[i];
        }

        auto induce = [&](const std::vector<int> &lms) {
            std::fill(std::begin(sa), std::end(sa), -1);
            std::vector<int> buf(upper + 1);
            std::copy(std::begin(sum_s), std::end(sum_s), std::begin(buf));
            for (auto d : lms) {
                if (d == n) continue;
                sa[buf[s[d]]++] = d;
            }
            std::copy(std::begin(sum_l), std::end(sum_l), std::begin(buf));
            sa[buf[s[n - 1]]++] = n - 1;
            for (int i = 0; i < n; i++) {
                int v = sa[i];
                if (v >= 1 && !ls[v - 1]) { sa[buf[s[v - 1]]++] = v - 1; }
            }
            std::copy(std::begin(sum_l), std::end(sum_l), std::begin(buf));
            for (int i = n - 1; i >= 0; i--) {
                int v = sa[i];
                if (v >= 1 && ls[v - 1]) { sa[--buf[s[v - 1] + 1]] = v - 1; }
            }
        };

        std::vector<int> lms_map(n + 1, -1);
        int m = 0;
        for (int i = 1; i < n; i++) {
            if (!ls[i - 1] && ls[i]) lms_map[i] = m++;
        }
        std::vector<int> lms;
        lms.reserve(m);
        for (int i = 1; i < n; i++) {
            if (!ls[i - 1] && ls[i]) { lms.push_back(i); }
        }

        induce(lms);

        if (m) {
            std::vector<int> sorted_lms;
            sorted_lms.reserve(m);
            for (int v : sa) {
                if (lms_map[v] != -1) sorted_lms.push_back(v);
            }
            std::vector<int> rec_s(m);
            int rec_upper = 0;
            rec_s[lms_map[sorted_lms[0]]] = 0;
            for (int i = 1; i < m; i++) {
                int l = sorted_lms[i - 1], r = sorted_lms[i];
                int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
                int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
                bool same = true;
                if (end_l - l != end_r - r) {
                    same = false;
                } else {
                    while (l < end_l) {
                        if (s[l] != s[r]) break;
                        l++;
                        r++;
                    }
                    if (l == n || s[l] != s[r]) same = false;
                }
                if (!same) rec_upper++;
                rec_s[lms_map[sorted_lms[i]]] = rec_upper;
            }

            std::vector<int> rec_sa =
                sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);

            for (int i = 0; i < m; i++) { sorted_lms[i] = lms[rec_sa[i]]; }
            induce(sorted_lms);
        }
        return sa;
    }

    void init() { _sa = sa_is(_s, _upper); }
};

} // namespace kk2

#endif // STRING_SUFFIX_ARRAY_HPP
