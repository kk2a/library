#ifndef KK2_STRING_Z_ALGORITHM_HPP
#define KK2_STRING_Z_ALGORITHM_HPP 1

#include <string>
#include <vector>

namespace kk2 {

template <typename T> std::vector<int> z_algorithm(const std::vector<T> &s) {
    int n = s.size();
    if (n == 0) return {};
    std::vector<int> z(n);
    z[0] = n;
    int i = 1, j = 0;
    while (i < n) {
        while (i + j < n and s[j] == s[i + j]) ++j;
        z[i] = j;
        if (j == 0) {
            ++i;
            continue;
        }
        int k = 1;
        while (i + k < n and k + z[k] < j) z[i + k] = z[k], ++k;
        i += k, j -= k;
    }
    return z;
}

std::vector<int> z_algorithm(const std::string &s) {
    int n = s.size();
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) { s2[i] = s[i]; }
    return z_algorithm(s2);
}

} // namespace kk2

#endif // KK2_STRING_Z_ALGORITHM_HPP
