#include "../../../data_structure/my_bitset.hpp"

#include <algorithm>
#include <cassert>
#include <vector>

int main() {
    for (int n : {0, 1, 63, 64, 65, 127, 128, 129}) {
        kk2::DynamicBitSet bits(n);
        assert(bits.size() == n);
        assert(bits.word_count() == (n + 63) / 64);
        assert(bits.popcount() == 0);
        assert(bits.ctz() == n);
        assert(bits.clz() == n);

        bits.set_all();
        assert(bits.popcount() == n);
        if (n) {
            assert(bits.find_next(0) == 0);
            assert(bits.find_prev(n - 1) == n - 1);
        }
        bits.flip();
        assert(bits.popcount() == 0);
    }

    kk2::DynamicBitSet bits(130);
    for (int i : {0, 2, 63, 64, 100, 129}) bits.set(i);
    assert(bits.find_next(0) == 0);
    assert(bits.find_next(1) == 2);
    assert(bits.find_next(3) == 63);
    assert(bits.find_next(65) == 100);
    assert(bits.find_next(130) == 130);
    assert(bits.find_next_zero(0) == 1);
    assert(bits.find_next_zero(2) == 3);
    assert(bits.find_prev(200) == 129);
    assert(bits.find_prev(128) == 100);
    assert(bits.find_prev(1) == 0);
    assert(bits.find_prev(-1) == -1);
    assert(bits.ctz() == 0);
    assert(bits.clz() == 0);

    kk2::DynamicBitSet a(70), b(67);
    a.set(0);
    a.set(69);
    b.set(1);
    b.set(66);

    auto top = a.combine_top(b);
    assert(top.size() == 137);
    assert(top[0] && top[69] && top[71] && top[136]);
    assert(top.popcount() == 4);

    auto bottom = a.combine_bottom(b);
    assert(bottom.size() == 137);
    assert(bottom[1] && bottom[66] && bottom[67] && bottom[136]);
    assert(bottom.popcount() == 4);

    kk2::DynamicBitSet repeated(150), pattern(64);
    pattern.set(1);
    pattern.set(63);
    repeated.inplace_or_repeated(pattern);
    for (int i : {1, 63, 65, 127, 129}) assert(repeated[i]);
    assert(repeated.popcount() == 5);

    kk2::DynamicBitSet selected_bits(130);
    std::vector<int> selected_indices{0, 2, 63, 64, 100, 129};
    for (int i : selected_indices) selected_bits.set(i);
    kk2::DynamicBitSet::RankSelect ones(selected_bits);
    assert(ones.size() == (int)selected_indices.size());
    assert(ones.to_vec() == selected_indices);
    assert(ones.stride(1, 2, 5).to_vec() == (std::vector<int>{2, 64}));
    for (int end = 0; end <= selected_bits.size(); ++end) {
        int expected = std::lower_bound(selected_indices.begin(), selected_indices.end(), end)
                       - selected_indices.begin();
        assert(ones.rank(end) == expected);
    }
    auto ones_cursor = ones.monotone_cursor();
    for (int rank = 0; rank < ones.size(); ++rank) {
        assert(ones[rank] == selected_indices[rank]);
        assert(ones_cursor[rank] == selected_indices[rank]);
    }

    kk2::DynamicBitSet::RankSelect zeros(std::move(selected_bits), false);
    assert(zeros.size() == 130 - (int)selected_indices.size());
    auto zeros_cursor = zeros.monotone_cursor();
    for (int rank = 0, index = 0; index < 130; ++index) {
        if (std::binary_search(selected_indices.begin(), selected_indices.end(), index)) continue;
        assert(zeros.contains(index));
        assert(zeros.select(rank) == index);
        assert(zeros_cursor[rank++] == index);
    }

    for (const char *s :
         {"0", "1", "101", "1000000000000000000000000000000000000000000000000000000000000001"}) {
        kk2::DynamicBitSet from_string(s);
        assert(from_string.to_string() == s);
    }

    for (int n = 0; n <= 140; ++n) {
        kk2::DynamicBitSet lhs(n);
        std::vector<bool> expected_lhs(n);
        for (int i = 0; i < n; ++i) {
            expected_lhs[i] = (1LL * i * i + 3 * i + 7) % 11 < 4;
            lhs.set(i, expected_lhs[i]);
        }
        assert(lhs.popcount() == std::count(expected_lhs.begin(), expected_lhs.end(), true));
        for (int i = -1; i <= n; ++i) {
            int next = std::max(i, 0);
            while (next < n && !expected_lhs[next]) ++next;
            assert(lhs.find_next(i) == next);
        }

        int m = 137 - n / 2;
        kk2::DynamicBitSet rhs(m);
        std::vector<bool> expected_rhs(m);
        for (int i = 0; i < m; ++i) {
            expected_rhs[i] = (1LL * i * i + 5 * i + 1) % 13 < 5;
            rhs.set(i, expected_rhs[i]);
        }

        auto joined = lhs.combine_top(rhs);
        for (int i = 0; i < n; ++i) assert(joined[i] == expected_lhs[i]);
        for (int i = 0; i < m; ++i) assert(joined[n + i] == expected_rhs[i]);

        auto prepended = lhs.combine_bottom(rhs);
        for (int i = 0; i < m; ++i) assert(prepended[i] == expected_rhs[i]);
        for (int i = 0; i < n; ++i) assert(prepended[m + i] == expected_lhs[i]);
    }
}
