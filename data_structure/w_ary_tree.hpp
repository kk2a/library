#ifndef DATA_STRUCTURE_W_ARY_TREE_HPP
#define DATA_STRUCTURE_W_ARY_TREE_HPP 1

#include <vector>

namespace kk2 {

struct w_ary_tree {
    using Uint = unsigned long long;
    constexpr static int W = 64;
    std::vector<std::vector<Uint>> d;

    w_ary_tree() : d(1) {}

    w_ary_tree(const std::vector<bool> &a) {
        for (int n = a.size(); n != 1; n = (n + W - 1) / W) {
            std::vector<Uint> v((n + W - 1) / W);
            for (int i = 0; i < (n + W - 1) / W; ++i) {
                Uint x = 0;
                for (int j = 0; j < W && i * W + j < n; ++j) {
                    if (n == a.size()) x |= (Uint(a[i * W + j]) << j);
                    else x |= (Uint(d.back()[i * W + j]) << j);
                }
                v[i] = x;
            }
            d.push_back(v);
        }
    }
};

} // namespace kk2

#endif // DATA_STRUCTURE_W_ARY_TREE_HPP