#ifndef KK2_DATA_STRUCTURE_MY_BITSET_HPP
#define KK2_DATA_STRUCTURE_MY_BITSET_HPP 1

#include <algorithm>
#include <bit>
#include <bitset>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

#include "../bit/bitcount.hpp"
#include "../type_traits/io.hpp"

namespace kk2 {

template <class Accessor> struct MonotoneRankRange {
    Accessor _accessor;

    struct StrideRange {
        Accessor _accessor;
        int _start, _end, _step;

        struct Iterator {
            using value_type = int;
            using difference_type = std::ptrdiff_t;
            using iterator_category = std::forward_iterator_tag;
            using reference = int;
            using pointer = void;

            int rank, end, step;
            mutable typename Accessor::MonotoneCursor cursor;

            Iterator(int rank_, int end_, int step_, const Accessor &accessor)
                : rank(rank_),
                  end(end_),
                  step(step_),
                  cursor(accessor.monotone_cursor()) {}

            int operator*() const { return cursor[rank]; }

            Iterator &operator++() {
                rank = step < end - rank ? rank + step : end;
                return *this;
            }

            Iterator operator++(int) {
                Iterator result = *this;
                ++*this;
                return result;
            }

            bool operator==(const Iterator &other) const { return rank == other.rank; }
        };

        Iterator begin() const { return Iterator(_start, _end, _step, _accessor); }
        Iterator end() const { return Iterator(_end, _end, _step, _accessor); }

        int size() const {
            if (_start == _end) return 0;
            return (_end - _start - 1) / _step + 1;
        }

        std::vector<int> to_vec() const {
            std::vector<int> result;
            result.reserve(size());
            for (int value : *this) result.push_back(value);
            return result;
        }
    };

    auto begin() const { return stride(0, 1).begin(); }
    auto end() const { return stride(0, 1).end(); }
    int size() const { return _accessor.size(); }

    int operator[](int rank) const { return _accessor[rank]; }

    auto monotone_cursor() const { return _accessor.monotone_cursor(); }

    StrideRange stride(int start, int step) const { return stride(start, step, size()); }

    StrideRange stride(int start, int step, int end) const {
        assert(0 <= start && start <= end && end <= size() && step > 0);
        return StrideRange{_accessor, start, end, step};
    }

    std::vector<int> to_vec() const {
        std::vector<int> result;
        result.reserve(size());
        for (int value : *this) result.push_back(value);
        return result;
    }
};

struct DynamicBitSet {
    struct RankSelect;

    using T = DynamicBitSet;
    using UInt = std::uint64_t;
    constexpr static int BLOCK_SIZE = sizeof(UInt) * 8;
    constexpr static int BLOCK_SIZE_LOG = __builtin_ctz(BLOCK_SIZE);
    constexpr static int BLOCK_MASK = BLOCK_SIZE - 1;
    constexpr static UInt ONE = 1;
    int n;
    std::vector<UInt> block;

    DynamicBitSet(int n_ = 0, bool x = 0) : n(n_) {
        UInt val = x ? -1 : 0;
        block.assign((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG, val);
        if (n & BLOCK_MASK) block.back() >>= BLOCK_SIZE - (n & BLOCK_MASK);
        // fit the last block
    }

    DynamicBitSet(const std::string &s) : n(s.size()) {
        block.resize((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);
        set(s);
    }

    inline int size() const { return n; }

    int word_count() const { return block.size(); }

    UInt &word(int i) {
        assert(0 <= i && i < word_count());
        return block[i];
    }

    const UInt &word(int i) const {
        assert(0 <= i && i < word_count());
        return block[i];
    }

    UInt *data() { return block.data(); }

    const UInt *data() const { return block.data(); }

    T &clear_unused_bits() {
        if ((n & BLOCK_MASK) && !block.empty()) block.back() &= (ONE << (n & BLOCK_MASK)) - 1;
        return *this;
    }

    T &inplace_combine_top(const T &rhs) {
        if (this == &rhs) {
            T copy = rhs;
            return inplace_combine_top(copy);
        }
        int old_n = n;
        n += rhs.n;
        block.resize((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);
        int offset = old_n & BLOCK_MASK;
        int word_offset = old_n >> BLOCK_SIZE_LOG;
        if (offset == 0) {
            std::copy(rhs.block.begin(), rhs.block.end(), block.begin() + word_offset);
        } else {
            for (int i = 0; i < rhs.word_count(); ++i) {
                block[word_offset + i] |= rhs.block[i] << offset;
                if (word_offset + i + 1 < word_count()) {
                    block[word_offset + i + 1] = rhs.block[i] >> (BLOCK_SIZE - offset);
                }
            }
        }
        return *this;
    }

    T combine_top(const T &rhs) const { return T(*this).inplace_combine_top(rhs); }

    T &inplace_combine_bottom(const T &rhs) {
        T result = rhs;
        result.inplace_combine_top(*this);
        *this = std::move(result);
        return *this;
    }

    T combine_bottom(const T &rhs) const { return T(*this).inplace_combine_bottom(rhs); }

    void set(int i, bool x = true) {
        assert(0 <= i && i < n);
        if (x) block[i >> BLOCK_SIZE_LOG] |= ONE << (i & BLOCK_MASK);
        else block[i >> BLOCK_SIZE_LOG] &= ~(ONE << (i & BLOCK_MASK));
    }

    void reset(int i) { set(i, false); }

    T &set_all(bool x = true) {
        std::fill(block.begin(), block.end(), x ? ~UInt(0) : UInt(0));
        if (x && (n & BLOCK_MASK)) block.back() &= (ONE << (n & BLOCK_MASK)) - 1;
        return *this;
    }

    T &reset_all() { return set_all(false); }

    void set(const std::string &s) {
        assert((int)s.size() == n);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            int r = n - (i << BLOCK_SIZE_LOG), l = std::max(0, r - BLOCK_SIZE);
            block[i] = 0;
            for (int j = l; j < r; j++) block[i] = (block[i] << 1) | (s[j] - '0');
        }
    }

    void set_reversed(const std::string &s) {
        assert((int)s.size() == n);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            int l = i << BLOCK_SIZE_LOG, r = std::min(n, l + BLOCK_SIZE);
            block[i] = 0;
            for (int j = r - 1; j >= l; --j) block[i] = (block[i] << 1) | (s[j] - '0');
        }
    }

    struct BitReference {
        std::vector<UInt> &block;
        int idx;

      public:
        BitReference(std::vector<UInt> &block_, int idx_) : block(block_), idx(idx_) {}

        operator bool() const { return (block[idx >> BLOCK_SIZE_LOG] >> (idx & BLOCK_MASK)) & 1; }

        template <InputStream IStream> friend IStream &operator>>(IStream &is, BitReference a) {
            bool c;
            is >> c;
            a = c;
            return is;
        }

        BitReference &operator=(bool x) {
            if (x) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);
            else block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));
            return *this;
        }

        BitReference &operator=(const BitReference &other) {
            if (other) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);
            else block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));
            return *this;
        }

        BitReference &operator&=(bool x) {
            if (!x) block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));
            return *this;
        }

        BitReference &operator&=(const BitReference &other) {
            if (!other) block[idx >> BLOCK_SIZE_LOG] &= ~(ONE << (idx & BLOCK_MASK));
            return *this;
        }

        BitReference &operator|=(bool x) {
            if (x) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        BitReference &operator|=(const BitReference &other) {
            if (other) block[idx >> BLOCK_SIZE_LOG] |= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        BitReference &operator^=(bool x) {
            if (x) block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        BitReference &operator^=(const BitReference &other) {
            if (other) block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        BitReference &flip() {
            block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        BitReference &operator~() {
            block[idx >> BLOCK_SIZE_LOG] ^= ONE << (idx & BLOCK_MASK);
            return *this;
        }

        bool val() const { return (block[idx >> BLOCK_SIZE_LOG] >> (idx & BLOCK_MASK)) & 1; }
    };

    BitReference operator[](int i) {
        assert(0 <= i && i < n);
        return BitReference(block, i);
    }

    bool operator[](int i) const {
        assert(0 <= i && i < n);
        return (block[i >> BLOCK_SIZE_LOG] >> (i & BLOCK_MASK)) & 1;
    }

    bool is_pinned(int i) const {
        assert(0 <= i && i < n);
        return (block[i >> BLOCK_SIZE_LOG] >> (i & BLOCK_MASK)) & 1;
    }

    T &operator=(const std::string &s) {
        set(s);
        return *this;
    }

    T &flip() {
        for (UInt &x : block) x = ~x;
        if (n & BLOCK_MASK) block.back() &= (ONE << (n & BLOCK_MASK)) - 1;
        return *this;
    }

    T &flip(int i) {
        assert(0 <= i && i < n);
        block[i >> BLOCK_SIZE_LOG] ^= ONE << (i & BLOCK_MASK);
        return *this;
    }

    int ctz() const { return find_next(0); }

    int clz() const {
        int last = find_prev(n - 1);
        return last == -1 ? n : n - 1 - last;
    }

    int find_next(int i) const {
        if (i < 0) i = 0;
        if (i >= n) return n;
        int j = i >> BLOCK_SIZE_LOG;
        UInt bits = block[j] & (~UInt(0) << (i & BLOCK_MASK));
        while (true) {
            if (bits) return std::min(n, j * BLOCK_SIZE + (int)std::countr_zero(bits));
            if (++j == word_count()) return n;
            bits = block[j];
        }
    }

    int find_next_zero(int i) const {
        if (i < 0) i = 0;
        if (i >= n) return n;
        int j = i >> BLOCK_SIZE_LOG;
        UInt bits = ~block[j] & (~UInt(0) << (i & BLOCK_MASK));
        while (true) {
            if (bits) return std::min(n, j * BLOCK_SIZE + (int)std::countr_zero(bits));
            if (++j == word_count()) return n;
            bits = ~block[j];
        }
    }

    int find_prev(int i) const {
        if (i >= n) i = n - 1;
        if (i < 0) return -1;
        int j = i >> BLOCK_SIZE_LOG;
        int offset = i & BLOCK_MASK;
        UInt bits = block[j] & (~UInt(0) >> (BLOCK_MASK - offset));
        while (true) {
            if (bits) return j * BLOCK_SIZE + (BLOCK_MASK - std::countl_zero(bits));
            if (j-- == 0) return -1;
            bits = block[j];
        }
    }

    int popcount() const {
        int res = 0;
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            res += kk2::popcount(block[i]);
        }
        return res;
    }

    T &operator~() { return flip(); }

    T &operator&=(const T &other) {
        assert(n == other.n);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            block[i] &= other.block[i];
        }
        return *this;
    }

    T &operator|=(const T &other) {
        assert(n == other.n);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            block[i] |= other.block[i];
        }
        return *this;
    }

    T &operator^=(const T &other) {
        assert(n == other.n);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            block[i] ^= other.block[i];
        }
        return *this;
    }

    T &inplace_or_repeated(const T &pattern) {
        assert(pattern.n > 0 && (pattern.n & BLOCK_MASK) == 0);
        int pattern_words = pattern.word_count();
        for (int begin = 0; begin < word_count(); begin += pattern_words) {
            int size = std::min(pattern_words, word_count() - begin);
            for (int i = 0; i < size; ++i) block[begin + i] |= pattern.block[i];
        }
        return clear_unused_bits();
    }

    friend T operator&(const T &lhs, const T &rhs) { return T(lhs) &= rhs; }

    friend T operator|(const T &lhs, const T &rhs) { return T(lhs) |= rhs; }

    friend T operator^(const T &lhs, const T &rhs) { return T(lhs) ^= rhs; }

    friend bool operator==(const T &lhs, const T &rhs) {
        if (lhs.n != rhs.n) return false;
        for (int i = 0; i < (lhs.n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            if (lhs.block[i] != rhs.block[i]) return false;
        }
        return true;
    }

    friend bool operator!=(const T &lhs, const T &rhs) { return !(lhs == rhs); }

    operator bool() const {
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            if (block[i]) return true;
        }
        return false;
    }

    std::string to_string(UInt x) const { return std::bitset<BLOCK_SIZE>(x).to_string(); }

    std::string to_string() const {
        std::vector<std::string> tmp((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            tmp[i] = to_string(block[i]);
        }
        if (n & BLOCK_MASK) {
            std::reverse(std::begin(tmp.back()), std::end(tmp.back()));
            tmp.back().resize(n & BLOCK_MASK);
            std::reverse(std::begin(tmp.back()), std::end(tmp.back()));
        }
        std::string res;
        for (int i = (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i--;) { res += tmp[i]; }
        return res;
    }

    std::string to_reversed_string() const {
        std::vector<std::string> tmp((n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG);
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            tmp[i] = to_string(block[i]);
        }
        if (n & BLOCK_MASK) {
            std::reverse(std::begin(tmp.back()), std::end(tmp.back()));
            tmp.back().resize(n & BLOCK_MASK);
            std::reverse(std::begin(tmp.back()), std::end(tmp.back()));
        }
        std::string res;
        for (int i = 0; i < (n + BLOCK_SIZE - 1) >> BLOCK_SIZE_LOG; i++) {
            std::reverse(std::begin(tmp[i]), std::end(tmp[i]));
            res += tmp[i];
        }
        return res;
    }

    template <OutputStream OStream> friend OStream &operator<<(OStream &os, const T &bs) {
        return os << bs.to_string();
    }

    template <InputStream IStream> friend IStream &operator>>(IStream &is, T &bs) {
        std::string s;
        is >> s;
        bs.set_reversed(s);
        return is;
    }
};

struct DynamicBitSet::RankSelect {
  private:
    DynamicBitSet _bits;
    std::vector<int> _prefix;

    UInt selected_word(int word) const { return _bits.word(word); }

  public:
    RankSelect() : _prefix(1) {}

    explicit RankSelect(DynamicBitSet bits, bool value = true)
        : _bits(std::move(bits)),
          _prefix(_bits.word_count() + 1) {
        for (int word = 0; word < _bits.word_count(); ++word) {
            UInt selected = value ? _bits.word(word) : ~_bits.word(word);
            if (word + 1 == _bits.word_count() && (_bits.size() & BLOCK_MASK)) {
                selected &= (ONE << (_bits.size() & BLOCK_MASK)) - 1;
            }
            _bits.word(word) = selected;
            _prefix[word + 1] = _prefix[word] + std::popcount(selected);
        }
    }

    int bit_size() const { return _bits.size(); }

    bool contains(int index) const {
        assert(0 <= index && index < bit_size());
        return _bits[index];
    }

    int rank(int end) const {
        assert(0 <= end && end <= bit_size());
        int word = end >> BLOCK_SIZE_LOG;
        int result = _prefix[word];
        if (end & BLOCK_MASK) {
            UInt mask = (ONE << (end & BLOCK_MASK)) - 1;
            result += std::popcount(selected_word(word) & mask);
        }
        return result;
    }

    int select(int rank) const {
        assert(0 <= rank && rank < size());
        int word =
            (int)(std::upper_bound(_prefix.begin(), _prefix.end(), rank) - _prefix.begin()) - 1;
        UInt selected = selected_word(word);
        int local_rank = rank - _prefix[word];
        while (local_rank--) selected &= selected - 1;
        return word * BLOCK_SIZE + std::countr_zero(selected);
    }

    int find_next(int index) const { return _bits.find_next(index); }

    struct MonotoneCursor {
      private:
        const RankSelect *_index;
        int _last_rank = -1;
        int _word = 0;

      public:
        explicit MonotoneCursor(const RankSelect &index) : _index(&index) {}

        int operator[](int rank) {
            assert(0 <= rank && _last_rank <= rank && rank < _index->size());
            _last_rank = rank;
            while (_index->_prefix[_word + 1] <= rank) ++_word;
            UInt selected = _index->selected_word(_word);
            int local_rank = rank - _index->_prefix[_word];
            while (local_rank--) selected &= selected - 1;
            return _word * BLOCK_SIZE + std::countr_zero(selected);
        }
    };

    int size() const { return _prefix.back(); }

    int operator[](int rank) const { return select(rank); }

    MonotoneCursor monotone_cursor() const & { return MonotoneCursor(*this); }
    MonotoneCursor monotone_cursor() const && = delete;

    struct RangeAccessor {
        const RankSelect *index;

        using MonotoneCursor = RankSelect::MonotoneCursor;

        int size() const { return index->size(); }
        int operator[](int rank) const { return (*index)[rank]; }
        MonotoneCursor monotone_cursor() const { return index->monotone_cursor(); }
    };

    using Range = MonotoneRankRange<RangeAccessor>;

    Range range() const & { return Range{RangeAccessor{this}}; }
    Range range() const && = delete;

    auto begin() const { return range().begin(); }
    auto end() const { return range().end(); }
    auto stride(int start, int step) const & { return range().stride(start, step); }
    auto stride(int start, int step, int end) const & { return range().stride(start, step, end); }
    auto stride(int, int) const && = delete;
    auto stride(int, int, int) const && = delete;
    std::vector<int> to_vec() const { return range().to_vec(); }
};

} // namespace kk2

#endif // KK2_DATA_STRUCTURE_MY_BITSET_HPP
