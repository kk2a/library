#ifndef KK2_OHTERS_VECTOR_POOL_HPP
#define KK2_OHTERS_VECTOR_POOL_HPP 1

#include <memory>
#include <vector>

namespace kk2 {

template <typename T> struct VectorPool {
  private:
    static constexpr size_t CHUNK_SIZE = 1 << 11;
    std::vector<std::unique_ptr<T[]>> chunks; // 固定サイズ配列のポインタ
    std::vector<T *> free_ptrs;
    size_t pos = 0;

  public:
    VectorPool() = default;
    VectorPool(int n) { reserve(n); }

    inline T *alloc() {
        if (pos >= free_ptrs.size()) { expand(); }
        return free_ptrs[pos++];
    }

    inline void free(T *ptr) { free_ptrs[--pos] = ptr; }

    void clear() {
        pos = 0;
        size_t idx = 0;
        for (auto &chunk : chunks) {
            for (size_t i = 0; i < CHUNK_SIZE; i++) { free_ptrs[idx++] = &chunk[i]; }
        }
    }

    void reserve(int n) {
        size_t needed_chunks = (n + CHUNK_SIZE - 1) / CHUNK_SIZE;
        size_t current_chunks = chunks.size();

        if (needed_chunks <= current_chunks) return;

        chunks.reserve(needed_chunks);
        free_ptrs.reserve(n);

        // 一度に必要な分のチャンクを確保
        size_t old_free_size = free_ptrs.size();
        size_t new_chunks_count = needed_chunks - current_chunks;
        free_ptrs.resize(old_free_size + new_chunks_count * CHUNK_SIZE);

        for (size_t chunk_idx = 0; chunk_idx < new_chunks_count; ++chunk_idx) {
            auto new_chunk = std::make_unique<T[]>(CHUNK_SIZE);
            T *chunk_ptr = new_chunk.get();
            chunks.push_back(std::move(new_chunk));

            size_t base_idx = old_free_size + chunk_idx * CHUNK_SIZE;
            for (size_t i = 0; i < CHUNK_SIZE; ++i) { free_ptrs[base_idx + i] = &chunk_ptr[i]; }
        }
    }

  private:
    void expand() { add_chunk(); }

    void add_chunk() {
        auto new_chunk = std::make_unique<T[]>(CHUNK_SIZE);
        T *chunk_ptr = new_chunk.get();
        chunks.push_back(std::move(new_chunk));

        size_t old_size = free_ptrs.size();
        free_ptrs.resize(old_size + CHUNK_SIZE);

        for (size_t i = 0; i < CHUNK_SIZE; i++) { free_ptrs[old_size + i] = &chunk_ptr[i]; }
    }

  public:
    size_t size() const { return chunks.size() * CHUNK_SIZE; }

    size_t available() const { return free_ptrs.size() - pos; }
};

} // namespace kk2

#endif // KK2_OHTERS_VECTOR_POOL_HPP
