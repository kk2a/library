#ifndef KK2_DATA_STRUCTURE_W_ARY_TREE_HPP
#define KK2_DATA_STRUCTURE_W_ARY_TREE_HPP 1

#include <algorithm>
#include <cassert>
#include <optional>
#include <vector>

#include "../bit/bitcount.hpp"

namespace kk2 {

struct w_ary_tree {
    using Uint = unsigned long long;
    constexpr static int W = 64;
    int _n;
    std::vector<std::vector<Uint>> d;

    w_ary_tree() : d(1) {}

    w_ary_tree(const std::vector<bool> &a) : _n(a.size()) {
        if (_n == 0) return;
        if (_n == 1) {
            d = {{Uint(a[0])}};
            return;
        }
        for (int n = _n; n != 1; n = (n + W - 1) / W) {
            std::vector<Uint> v((n + W - 1) / W);
            for (int i = 0; i < (n + W - 1) / W; ++i) {
                Uint x = 0;
                for (int j = 0; j < W && i * W + j < n; ++j) {
                    if (n == _n) x |= (Uint(a[i * W + j]) << j);
                    else x |= ((d.back()[i * W + j] ? Uint(1) : Uint(0)) << j);
                }
                v[i] = x;
            }
            d.push_back(v);
        }
        std::reverse(d.begin(), d.end());
    }

    w_ary_tree(const std::string &s) : _n(s.size()) {
        if (_n == 0) return;
        if (_n == 1) {
            d = {{Uint(s[0] - '0')}};
            return;
        }
        for (int n = _n; n != 1; n = (n + W - 1) / W) {
            std::vector<Uint> v((n + W - 1) / W);
            for (int i = 0; i < (n + W - 1) / W; ++i) {
                Uint x = 0;
                for (int j = 0; j < W && i * W + j < n; ++j) {
                    if (n == _n) x |= (Uint(s[i * W + j] - '0') << j);
                    else x |= ((d.back()[i * W + j] ? Uint(1) : Uint(0)) << j);
                }
                v[i] = x;
            }
            d.push_back(v);
        }
        std::reverse(d.begin(), d.end());
    }

    int count(int x) const {
        assert(0 <= x && x < _n);
        return d.back()[x / W] >> (x % W) & 1;
    }

    void insert(int x) {
        assert(0 <= x && x < _n);
        for (int dep = (int)d.size() - 1; dep >= 0; --dep, x /= W) {
            if (d[dep][x / W] >> (x % W) & 1) break;
            d[dep][x / W] |= Uint(1) << (x % W);
        }
    }

    void erase(int x) {
        assert(0 <= x && x < _n);
        for (int dep = (int)d.size() - 1; dep >= 0; --dep, x /= W) {
            if (dep == (int)d.size() - 1) {
                if (~d[dep][x / W] >> (x % W) & 1) break;
                d[dep][x / W] ^= Uint(1) << (x % W);
            } else {
                if (d[dep + 1][x]) break;
                if (~d[dep][x / W] >> (x % W) & 1) break;
                d[dep][x / W] ^= Uint(1) << (x % W);
            }
        }
    }

    // return max y s.t. count(y) == 1 && y <= x
    std::optional<int> predecessor(int x) const {
        if (x < 0) return std::nullopt;
        if (x >= _n) x = _n - 1;
        int dep = (int)d.size() - 1;
        for (;; --dep, x /= W) {
            Uint mask = up_mask(d[dep][x / W], x % W);
            if (dep != (int)d.size() - 1) mask &= ~(Uint(1) << (x % W));
            int next = _msb(mask);
            if (next != -1) {
                ++dep;
                x = (x / W) * W + next;
                break;
            }
            if (dep == 0) return std::nullopt;
        }

        for (; dep < (int)d.size(); x = x * W + _msb(d[dep][x]), ++dep) {}
        return x;
    }

    // return min y s.t. count(y) == 1 && y >= x
    std::optional<int> successor(int x) const {
        if (x >= _n) return std::nullopt;
        if (x < 0) x = 0;
        int dep = (int)d.size() - 1;
        for (;; --dep, x /= W) {
            Uint mask = dw_mask(d[dep][x / W], x % W);
            if (dep != (int)d.size() - 1) mask &= ~(Uint(1) << (x % W));
            int next = _lsb(mask);
            if (next != -1) {
                ++dep;
                x = (x / W) * W + next;
                break;
            }
            if (dep == 0) return std::nullopt;
        }


        for (; dep < (int)d.size(); x = x * W + _lsb(d[dep][x]), ++dep) {}
        return x;
    }

  private:
    static int _msb(Uint x) { return x ? msb<Uint>(x) : -1; }

    static int _lsb(Uint x) { return x ? lsb<Uint>(x) : -1; }

    static Uint up_mask(Uint x, int i) { return x & (((Uint(1) << i) - 1) | (Uint(1) << i)); }

    static Uint dw_mask(Uint x, int i) { return x & ~((Uint(1) << i) - 1); }
};

} // namespace kk2

#endif // KK2_DATA_STRUCTURE_W_ARY_TREE_HPP