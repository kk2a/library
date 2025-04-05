#ifndef KK2_OHTERS_VECTOR_POOL_HPP
#define KK2_OHTERS_VECTOR_POOL_HPP 1

#include <vector>

namespace kk2 {

template <typename T> struct VectorPool {
    std::vector<T> pool;
    std::vector<T *> ptrs;
    int pos = 0;

    VectorPool() = default;

    VectorPool(int n) : pool(n), ptrs(n) {}

    inline T *alloc() { return ptrs[pos++]; }

    inline void free(T *ptr) { ptrs[--pos] = ptr; }

    void clear() {
        for (size_t i = 0; i < pool.size(); i++) ptrs[i] = &pool[i];
        pos = 0;
    }

    T &operator[](int i) { return pool[i]; }
};

} // namespace kk2

#endif // KK2_OHTERS_VECTOR_POOL_HPP
