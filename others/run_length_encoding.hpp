#ifndef OTHERS_RUN_LENGTH_ENCODING_HPP
#define OTHERS_RUN_LENGTH_ENCODING_HPP 1

#include <string>
#include <vector>

namespace kk2 {

namespace run_length_encoding {

template <class T> struct result {
    T value;
    int length;
};

template <class T> std::vector<result<T>> RunLengthEncoding(const std::vector<T> &v) {
    std::vector<result<T>> res;
    for (int i = 0; i < (int)v.size(); ++i) {
        if (res.empty() || res.back().value != v[i]) {
            res.push_back({v[i], 1});
        } else {
            res.back().length++;
        }
    }
    return res;
}

std::vector<result<char>> RunLengthEncoding(const std::string &s) {
    std::vector<result<char>> res;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (res.empty() || res.back().value != s[i]) {
            res.push_back({s[i], 1});
        } else {
            res.back().length++;
        }
    }
    return res;
}

} // namespace run_length_encoding

using run_length_encoding::RunLengthEncoding;

} // namespace kk2

#endif // OTHERS_RUN_LENGTH_ENCODING_HPP
