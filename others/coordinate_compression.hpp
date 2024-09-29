#ifndef OTHERS_COORDINATE_COMPRESSION_HPP
#define OTHERS_COORDINATE_COMPRESSION_HPP 1

#include <algorithm>
#include <vector>

namespace kk2 {

// Coordinate Compression
template <typename S = int> struct CC {
    std::vector<S> xs;
    bool initialized;

    CC() : initialized(false) {}

    CC(const std::vector<S> &xs_) : xs(xs_), initialized(false) {}

    void add(S x) {
        xs.push_back(x);
        initialized = false;
    }

    void add(const std::vector<S> &ys) {
        std::copy(std::begin(ys), std::end(ys), std::back_inserter(xs));
        initialized = false;
    }

    void build() {
        std::sort(std::begin(xs), std::end(xs));
        xs.erase(std::unique(std::begin(xs), std::end(xs)), std::end(xs));
        initialized = true;
    }

    S operator[](int i) {
        if (!initialized) build();
        return xs[i];
    }

    int size() {
        if (!initialized) build();
        return xs.size();
    }

    int get(S x) {
        if (!initialized) build();
        return std::upper_bound(std::begin(xs), std::end(xs), x) - std::begin(xs) - 1;
    }

    std::vector<int> get(const std::vector<S> &ys) {
        std::vector<int> ret(ys.size());
        for (int i = 0; i < (int)ys.size(); ++i) ret[i] = get(ys[i]);
        return ret;
    }

    int operator()(S x) { return get(x); }

    std::vector<int> operator()(const std::vector<S> &ys) { return get(ys); }

    int lower(S x) {
        if (!initialized) build();
        return std::lower_bound(std::begin(xs), std::end(xs), x) - std::begin(xs);
    }

    int upper(S x) {
        if (!initialized) build();
        return std::upper_bound(std::begin(xs), std::end(xs), x) - std::begin(xs);
    }

    bool exist(S x) {
        if (!initialized) build();
        int idx = lower(x);
        return idx < (int)xs.size() && xs[idx] == x;
    }
};

} // namespace kk2

#endif // OTHERS_COORDINATE_COMPRESSION_HPP
