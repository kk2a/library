#ifndef DATA_STRUCTURE_W_ARY_TREE_HPP
#define DATA_STRUCTURE_W_ARY_TREE_HPP 1

#include <vector>

namespace kk2 {

struct w_ary_tree {
    using Uint = unsigned long long;
    constexpr static int W = 64;
    std::vector<Uint> d;
    w_ary_tree() : d(1) {}
    w_ary_tree(const std::vector<bool> &a) {
        
    }
};

} // namespace kk2

#endif // DATA_STRUCTURE_W_ARY_TREE_HPP