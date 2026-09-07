// competitive-verifier: STANDALONE

#include <ostream>
#include <vector>

#include "../../../type_traits/container_traits.hpp"
#include "../../../type_traits/functional.hpp"
#include "../../../type_traits/integral.hpp"
#include "../../../type_traits/io.hpp"
#include "../../../type_traits/member.hpp"
#include "../../../type_traits/operator.hpp"

struct TaggedInput : kk2::type_traits::istream_tag {};
struct TaggedOutput : kk2::type_traits::ostream_tag {};

struct Debuggable {
    void debug_output(std::ostream &) const {}
};

struct HasVal {
    int val(int) const { return 0; }
};

static_assert(kk2::Vector<std::vector<int>>);
static_assert(kk2::Container<std::vector<int>>);
static_assert(!kk2::Container<std::vector<int>::iterator>);

static_assert(kk2::Integral<int>);
static_assert(kk2::Integral<__int128>);
static_assert(kk2::SignedIntegral<int>);
static_assert(kk2::UnsignedIntegral<unsigned>);
static_assert(!kk2::SignedIntegral<unsigned>);

static_assert(kk2::InputStream<std::istream>);
static_assert(kk2::OutputStream<std::ostream>);
static_assert(kk2::InputStream<TaggedInput>);
static_assert(kk2::OutputStream<TaggedOutput>);
static_assert(!kk2::InputStream<int>);

static_assert(kk2::FunctionPointer<void (*)(int, int)>);
static_assert(kk2::TwoArgsFunctionPointer<void (*)(int, int)>);
static_assert(!kk2::TwoArgsFunctionPointer<void (*)(int)>);
static_assert(!kk2::TwoArgsFunctionPointer<int>);

static_assert(kk2::HasDebugOutput<Debuggable, std::ostream &>);
static_assert(kk2::HasVal<HasVal, int>);
static_assert(kk2::HasPlus<int>);
static_assert(kk2::HasEqualTo<int>);
static_assert(kk2::HasLogicalNot<bool>);

int main() {}
