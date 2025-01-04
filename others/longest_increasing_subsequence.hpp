#ifndef KK2_OTHERS_LONGEST_INCREASING_SUBSEQUENCE_HPP
#define KK2_OTHERS_LONGEST_INCREASING_SUBSEQUENCE_HPP 1

#include <algorithm>
#include <utility>
#include <vector>

namespace kk2 {

// return indices of longest increasing subsequence
template <class T> std::vector<int> longest_increasing_subsequence(const std::vector<T> &a) {
    int n = a.size();
    std::vector<std::pair<T, int>> dp;
    std::vector<int> prev(n, -1);
    for (int i = 0; i < n; ++i) {
        auto it = std::lower_bound(dp.begin(), dp.end(), std::make_pair(a[i], -i));
        if (it != dp.begin()) {
            prev[i] = -std::prev(it)->second;
        }
        if (it == dp.end()) {
            dp.emplace_back(a[i], -i);
        } else {
            *it = std::make_pair(a[i], -i);
        }
    } 

    std::vector<int> res;
    for (int i = -std::prev(dp.end())->second; i >= 0; i = prev[i]) {
        res.push_back(i);
    }
    std::reverse(res.begin(), res.end());
    return res;
}

} // namespace kk2

#endif // KK2_OTHERS_LONGEST_INCREASING_SUBSEQUENCE_HPP
