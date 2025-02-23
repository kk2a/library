#ifndef KK2_UNIONFIND_PARTIAL_PERSISTENT_HPP
#define KK2_UNIONFIND_PARTIAL_PERSISTENT_HPP 1

#include <algorithm>
#include <cassert>
#include <numeric>
#include <utility>
#include <vector>

namespace kk2 {

struct PartialPersistentUnionFind {
    struct par_time {
        int par, time;
        par_time() = default;

        par_time(int par_, int time_) : par(par_), time(time_) {}
    };

    struct size_time {
        int size, time;
        size_time() = default;

        size_time(int size_, int time_) : size(size_), time(time_) {}

        bool operator<(const size_time &a) const { return time < a.time; }
    };

    int last_time;
    std::vector<par_time> par;
    std::vector<std::vector<size_time>> size_hist;

    PartialPersistentUnionFind(int n)
        : last_time(std::numeric_limits<int>::min()),
          par(n),
          size_hist(n) {
        for (int i = 0; i < n; ++i) {
            par[i] = par_time(-1, std::numeric_limits<int>::max());
            size_hist[i].emplace_back(1, last_time);
        }
    }

    bool same(int x, int y, int time) { return find(x, time) == find(y, time); }

    bool unite(int x, int y, int time) {
        assert(last_time <= time);
        last_time = time;
        x = find(x, time), y = find(y, time);
        if (x == y) return false;
        if (size_hist[x].back().size < size_hist[y].back().size) std::swap(x, y);
        par[y] = par_time(x, time);
        if (size_hist[x].back().time < time)
            size_hist[x].emplace_back(size_hist[x].back().size, time);
        size_hist[x].back().size += size_hist[y].back().size;
        return true;
    }

    int find(int x, int time) {
        while (par[x].time <= time) x = par[x].par;
        return x;
    }

    int size(int x, int time) {
        x = find(x, time);
        auto it = std::upper_bound(size_hist[x].begin(), size_hist[x].end(), size_time(0, time));
        return prev(it)->size;
    }
};

} // namespace kk2


#endif // KK2_UNIONFIND_PARTIAL_PERSISTENT_HPP
