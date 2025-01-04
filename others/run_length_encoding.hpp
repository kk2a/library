#ifndef KK2_OTHERS_RUN_LENGTH_ENCODING_HPP
#define KK2_OTHERS_RUN_LENGTH_ENCODING_HPP 1

#include <string>
#include <vector>

#include "../type_traits/type_traits.hpp"

namespace kk2 {

namespace run_length_encoding {

template <class T> struct rle_element {
    T value;
    int length;

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const rle_element &rle) {
        return os << "(value: " << rle.value << ", length: " << rle.length << ")";
    }
};

template <typename C, typename T = typename C::value_type>
std::vector<rle_element<T>> RunLengthEncoding(const C &v) {
    std::vector<rle_element<T>> res;
    for (int i = 0; i < (int)v.size(); ++i) {
        if (res.empty() || res.back().value != v[i]) {
            res.emplace_back(v[i], 1);
        } else {
            res.back().length++;
        }
    }
    return res;
}

} // namespace run_length_encoding

using run_length_encoding::RunLengthEncoding;

} // namespace kk2

#endif // KK2_OTHERS_RUN_LENGTH_ENCODING_HPP
