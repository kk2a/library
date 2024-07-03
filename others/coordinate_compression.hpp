#ifndef OTHERS_COORDINATE_COMPRESSION_HPP
#define OTHERS_COORDINATE_COMPRESSION_HPP 1


// Coordinate Compression
template <typename S=int>
struct CC {
    vector<S> xs;
    bool initialized;
    CC() : initialized(false) {}
    CC(const vector<S>& xs_) : xs(xs_), initialized(false) {}
    void add(S x) {
        xs.push_back(x);
        initialized = false;
    }
    void add(const vector<S>& ys) {
        copy(begin(ys), end(ys), back_inserter(xs));
        initialized = false;
    }
    void build() {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
        initialized = true;
    }
    S operator[](int i) {
        if (!initialized) build();
        return xs[i];
    }
    int size() const {
        return xs.size();
    }

    int get(S x) {
        if (!initialized) build();
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    vector<int> get(const vector<S>& ys) {
        vector<int> ret(ys.size());
        for (int i = 0; i < (int)ys.size(); ++i) ret[i] = get(ys[i]);
        return ret;
    }
};

#endif // OTHERS_COORDINATE_COMPRESSION_HPP
