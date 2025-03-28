#ifndef KK2_OTHERS_MO_HPP
#define KK2_OTHERS_MO_HPP 1

#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <numeric>
#include <vector>

namespace kk2 {

struct Mo {
    Mo(int n_, int q_) : n(n_), q(q_), ord(q) {
        block_size = std::max<int>(1, n / std::max(1.0, std::sqrt(q * 2.0 / 3.0)));
        std::iota(ord.begin(), ord.end(), 0);
        queries.reserve(q);
    }

    Mo(int n_, const std::vector<std::pair<int, int>> &queries_)
        : n(n_),
          q(queries_.size()),
          ord(q),
          queries(queries_) {
        block_size = std::max<int>(1, n / std::max(1.0, std::sqrt(q * 2.0 / 3.0)));
        std::iota(ord.begin(), ord.end(), 0);
    }

    void add_query(int l, int r) {
        assert(0 <= l and l <= r and r <= n);
        queries.emplace_back(l, r);
    }

    void add_query(const std::pair<int, int> &p) { add_query(p.first, p.second); }

    template <typename IL, typename IR, typename EL, typename ER, typename F>
    void calculate(const IL &insert_left,
                   const IR &insert_right,
                   const EL &erase_left,
                   const ER &erase_right,
                   const F &f) {
        assert((int)queries.size() == q);
        std::vector<int> block_id(n);
        for (int i = 0, cnt = 0, b = 0; i < n; i++) {
            block_id[i] = b;
            if (++cnt == block_size) {
                b++;
                cnt = 0;
            }
        }
        std::sort(ord.begin(), ord.end(), [&](int l, int r) {
            int l_b = block_id[queries[l].first];
            int r_b = block_id[queries[r].first];
            if (l_b != r_b) return l_b < r_b;
            if (l_b & 1) return queries[l].second < queries[r].second;
            return queries[l].second > queries[r].second;
        });

        int nowl = 0, nowr = 0;
        for (int i : ord) {
            while (nowl > queries[i].first) insert_left(--nowl);
            while (nowr < queries[i].second) insert_right(nowr++);
            while (nowl < queries[i].first) erase_left(nowl++);
            while (nowr > queries[i].second) erase_right(--nowr);
            f(i);
        }
    }

    template <typename I, typename E, typename F>
    void calculate(const I &insert, const E &erase, const F &f) {
        calculate(insert, insert, erase, erase, f);
    }

  private:
    int n, q, block_size;
    std::vector<int> ord;
    std::vector<std::pair<int, int>> queries;
};

} // namespace kk2

#endif // KK2_OTHERS_MO_HPP
