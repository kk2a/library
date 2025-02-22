#ifndef KK2_GRAPH_TREE_CARTESIAN_TREE_HPP
#define KK2_GRAPH_TREE_CARTESIAN_TREE_HPP 1

#include <utility>
#include <vector>

namespace kk2 {

template <class T>
std::pair<int, std::vector<int>> cartesian_tree(const std::vector<T> &a) {
    int n = a.size();
    std::vector<int> par(n, -1);
    std::vector<int> stk;
    for (int i = 0; i < n; ++i) {
        int last = -1;
        while (!stk.empty() && a[stk.back()] > a[i]) {
            last = stk.back();
            stk.pop_back();
        }
        if (last != -1) par[last] = i;
        if (!stk.empty()) par[i] = stk.back();
        stk.push_back(i);
    }
    return {stk[0], par};
}

} // namespace kk2

#endif // KK2_GRAPH_TREE_CARTESIAN_TREE_HPP
