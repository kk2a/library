#ifndef KK2_DARA_STRUCTURE_PREFIX_SUM_ARBITRARY_HPP
#define KK2_DARA_STRUCTURE_PREFIX_SUM_ARBITRARY_HPP 1

#include <cassert>
#include <iostream>
#include <vector>

namespace kk2 {

template <class T>
struct PrefixSumArbitrary {
  private:
    std::vector<int> base;
    int dim;
    std::vector<T> acc;

    std::vector<int> inner_base;
    int n;

  public:
    constexpr PrefixSumArbitrary() = default;

    constexpr PrefixSumArbitrary(const std::vector<int> &base_)
        : base(base_),
          dim(int(base_.size())) {
        inner_base.resize(dim + 1, 1);
        for (int i = 1; i < dim + 1; ++i) { inner_base[i] = inner_base[i - 1] * base[i - 1]; }
        n = 1;
        for (int x : base) n *= x;
        acc.resize(n, T{});
    }

    constexpr PrefixSumArbitrary(const std::vector<int> &base_, const std::vector<T> &a)
        : base(base_),
          dim(int(base_.size())),
          acc(a) {
        inner_base.resize(dim + 1, 1);
        for (int i = 1; i < dim + 1; ++i) { inner_base[i] = inner_base[i - 1] * base[i - 1]; }
        n = 1;
        for (int x : base) n *= x;
        build();
    }

    constexpr void build() {
        for (int i = 0; i < dim; ++i) {
            for (int coord = 0; coord < n; ++coord) {
                if (coord / inner_base[i + 1] == (coord + inner_base[i]) / inner_base[i + 1]) {
                    acc[coord + inner_base[i]] += acc[coord];
                }
            }
        }
    }

    constexpr void init_set(const std::vector<int> &p, T x) {
        assert(int(p.size()) == dim);
        int coord = 0;
        for (int i = 0; i < dim; ++i) {
            assert(0 <= p[i] and p[i] < base[i]);
            coord += p[i] * inner_base[i];
        }
        acc[coord] = x;
    }

    constexpr T sum(const std::vector<int> &l, const std::vector<int> &r) const {
        assert(int(l.size()) == dim and int(r.size()) == dim);
        for (int i = 0; i < dim; ++i) {
            if (r[i] == 0) return T{};
        }

        T res{};
        for (int bit = 0; bit < (1 << dim); ++bit) {
            int coord = 0;
            bool bad = false;
            for (int i = 0; i < dim; ++i) {
                if (bit >> i & 1) {
                    if (l[i] == 0) {
                        bad = true;
                        break;
                    }
                    coord += (l[i] - 1) * inner_base[i];
                } else {
                    coord += (r[i] - 1) * inner_base[i];
                }
            }
            if (bad) continue;
            res += (__builtin_popcount(bit) & 1 ? -1 : 1) * acc[coord];
        }
        return res;
    }

    constexpr T operator()(const std::vector<int> &l, const std::vector<int> &r) const {
        return sum(l, r);
    }
};

} // namespace kk2

#endif // KK2_DARA_STRUCTURE_PREFIX_SUM_ARBITRARY_HPP
