// competitive-verifier: STANDALONE

#include "../../template/fastio.hpp"

#include <cassert>
#include <cstdio>
#include <limits>
#include <string>
#include <type_traits>

using kk2::fastio::Printer;
using kk2::fastio::Scanner;

int main() {
    static_assert(!std::is_copy_constructible_v<Scanner>);
    static_assert(!std::is_copy_constructible_v<Printer>);

    FILE *file = std::tmpfile();
    assert(file != nullptr);
    {
        Printer out(file);
        out << std::numeric_limits<int32_t>::min() << ' ' << std::numeric_limits<int32_t>::max()
            << ' ' << std::numeric_limits<uint64_t>::max() << ' '
            << std::numeric_limits<__int128_t>::min() << ' '
            << std::numeric_limits<__int128_t>::max() << ' '
            << std::numeric_limits<__uint128_t>::max() << '\n';
        for (uint32_t i = 0; i < 10000; ++i) out << i << ' ';
        out << '\n';
        const std::string long_token((1 << 17) + 17, 'x');
        out << long_token << '\n';
        assert(out.flush());

        std::rewind(file);
        Scanner in(file);
        int32_t i32_min, i32_max;
        uint64_t u64_max;
        __int128_t i128_min, i128_max;
        __uint128_t u128_max;
        std::string token;
        assert(in.read(i32_min));
        assert(in.read(i32_max));
        assert(in.read(u64_max));
        assert(in.read(i128_min));
        assert(in.read(i128_max));
        assert(in.read(u128_max));
        assert(i32_min == std::numeric_limits<int32_t>::min());
        assert(i32_max == std::numeric_limits<int32_t>::max());
        assert(u64_max == std::numeric_limits<uint64_t>::max());
        assert(i128_min == std::numeric_limits<__int128_t>::min());
        assert(i128_max == std::numeric_limits<__int128_t>::max());
        assert(u128_max == std::numeric_limits<__uint128_t>::max());
        for (uint32_t i = 0; i < 10000; ++i) {
            uint32_t value;
            assert(in.read(value));
            assert(value == i);
        }
        assert(in.read(token));
        assert(token == long_token);

        int unchanged = 42;
        assert(!in.read(unchanged));
        assert(unchanged == 42);
        assert(in.eof());
        assert(!in.good());
    }
    std::fclose(file);

    file = std::tmpfile();
    assert(file != nullptr);
    std::fputs("256", file);
    std::rewind(file);
    {
        Scanner in(file);
        uint8_t unchanged = 42;
        assert(!in.read(unchanged));
        assert(unchanged == 42);
        assert(!in.good());
    }
    std::fclose(file);

    FILE *first_file = std::tmpfile();
    FILE *second_file = std::tmpfile();
    assert(first_file != nullptr);
    assert(second_file != nullptr);
    {
        Printer first(first_file), second(second_file);
        first << "first";
        second << "second";
        assert(first.flush());
        assert(second.flush());

        std::rewind(first_file);
        std::rewind(second_file);
        Scanner first_in(first_file), second_in(second_file);
        assert(first_in.now() == 'f');
        assert(second_in.now() == 's');
        std::string first_value, second_value;
        assert(first_in.read(first_value));
        assert(second_in.read(second_value));
        assert(first_value == "first");
        assert(second_value == "second");
    }
    std::fclose(first_file);
    std::fclose(second_file);

    bool open_failed = false;
    try {
        Scanner invalid(static_cast<const char *>(nullptr));
    } catch (const std::system_error &) { open_failed = true; }
    assert(open_failed);
}
