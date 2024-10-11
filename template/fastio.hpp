#ifndef TEMPLATE_FASTIO_HPP
#define TEMPLATE_FASTIO_HPP 1

#include <cctype>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <string>

namespace kk2 {

namespace fastio {

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

struct Scanner {
  private:
    static constexpr size_t INPUT_BUF = 1 << 17;
    size_t pos = INPUT_BUF;
    static char buf[INPUT_BUF];
    FILE *fp;

  public:
    Scanner() { fp = stdin; }

    Scanner(const char *file) { fp = fopen(file, "r"); }

    ~Scanner() {
        if (fp != stdin) fclose(fp);
    }

    char now() {
        if (pos == INPUT_BUF) {
            size_t len = fread(buf, 1, INPUT_BUF, fp);
            if (len != INPUT_BUF) buf[len] = '\n';
            pos = 0;
        }
        return buf[pos];
    }

    void skip_space() {
        while (isspace(now())) ++pos;
    }

    uint32_t next_u32() {
        skip_space();
        uint32_t res = 0;
        while (isdigit(now())) {
            res = res * 10 + (now() - '0');
            ++pos;
        }
        return res;
    }

    int32_t next_i32() {
        skip_space();
        if (now() == '-') {
            ++pos;
            return (int32_t)(-next_u32());
        }
        else return (int32_t)next_uint();
    }

    uint64_t next_u64() {
        skip_space();
        uint64_t res = 0;
        while (isdigit(now())) {
            res = res * 10 + (now() - '0');
            ++pos;
        }
        return res;
    }

    int64_t next_i64() {
        skip_space();
        if (now() == '-') {
            ++pos;
            return (int64_t)(-next_u64());
        }
        else return (int64_t)next_u64();
    }

    __uint128_t next_u128() {
        skip_space();
        __uint128_t res = 0;
        while (isdigit(now())) {
            res = res * 10 + (now() - '0');
            ++pos;
        }
        return res;
    }

    __int128_t next_i128() {
        skip_space();
        if (now() == '-') {
            ++pos;
            return (__int128_t)(-next_u128());
        }
        else return (__int128_t)next_u128();
    }

    char next_char() {
        skip_space();
        auto res = now();
        ++pos;
        return res;
    }

    std::string next_string() {
        skip_space();
        std::string res;
        while (!isspace(now())) {
            res.push_back(now());
            ++pos;
        }
        return res;
    }

    Scanner &operator>>(int &x) {
        x = next_i32();
        return *this;
    }

    Scanner &operator>>(unsigned int &x) {
        x = next_u32();
        return *this;
    }

    Scanner &operator>>(long long &x) {
        x = next_i64();
        return *this;
    }

    Scanner &operator>>(unsigned long long &x) {
        x = next_u64();
        return *this;
    }

    Scanner &operator>>(__int128_t &x) {
        x = next_i128();
        return *this;
    }

    Scanner &operator>>(__uint128_t &x) {
        x = next_u128();
        return *this;
    }
};

#ifdef KK2
Scanner kin(INPUT_FILE);
#elif defined(INTERACTIVE)
#define kin std::cin
#else
Scanner kin;
#endif

} // namespace fastio

} // namespace kk2

#endif // TEMPLATE_FASTIO_HPP
