// competitive-verifier: STANDALONE

#include "../../../../type_traits/algebra.hpp"
#include "../../../../math/action/add_sumwithsize.hpp"
#include "../../../../math/action/affine_sumwithsize.hpp"
#include "../../../../math/group/add.hpp"
#include "../../../../math/monoid/affine.hpp"
#include "../../../../math/monoid/min.hpp"
#include "../../../../modint/mont.hpp"
#include "../../../../segment_tree/lazy.hpp"
#include "../../../../segment_tree/seg.hpp"

struct CustomMonoid {
    int value;

    CustomMonoid(int value_ = 0) : value(value_) {}

    static CustomMonoid op(const CustomMonoid &l, const CustomMonoid &r) {
        return CustomMonoid(l.value + r.value);
    }

    static CustomMonoid unit() { return CustomMonoid(0); }
};

struct CustomGroup {
    int value;

    CustomGroup(int value_ = 0) : value(value_) {}

    static CustomGroup op(const CustomGroup &l, const CustomGroup &r) {
        return CustomGroup(l.value + r.value);
    }

    static CustomGroup unit() { return CustomGroup(0); }
    static CustomGroup inv(const CustomGroup &x) { return CustomGroup(-x.value); }
};

struct CustomAction {
    using S = CustomMonoid;

    struct Add {
        int value;
        Add(int value_ = 0) : value(value_) {}
        static Add op(const Add &l, const Add &r) { return Add(l.value + r.value); }
        static Add unit() { return Add(0); }
    };

    using A = Add;

    static S act(const A &f, const S &x) { return S(x.value + f.value); }
};

struct MissingUnit {
    static MissingUnit op(const MissingUnit &, const MissingUnit &) { return {}; }
};

struct MissingAction {
    using S = CustomMonoid;
    using A = CustomGroup;
};

using Add = kk2::group::Add<int>;
using Min = kk2::monoid::Min<int>;
using Affine = kk2::monoid::Affine<kk2::mont998>;
using SumAction = kk2::action::AddSumWithSize<int, int>;
using AffineAction = kk2::action::AffineSumWithSize<int, int>;

static_assert(kk2::algebra::Monoid<CustomMonoid>);
static_assert(kk2::algebra::Group<CustomGroup>);
static_assert(kk2::algebra::Action<CustomAction>);
static_assert(!kk2::algebra::Monoid<MissingUnit>);
static_assert(!kk2::algebra::Action<MissingAction>);
static_assert(kk2::algebra::Semigroup<Add>);
static_assert(kk2::algebra::Monoid<Add>);
static_assert(kk2::algebra::Group<Add>);
static_assert(kk2::algebra::CommutativeGroup<Add>);
static_assert(kk2::algebra::CommutativeMonoid<Min>);
static_assert(kk2::algebra::Monoid<Affine>);
static_assert(kk2::algebra::Group<Affine>);
static_assert(kk2::algebra::Action<SumAction>);
static_assert(kk2::algebra::Action<AffineAction>);

int main() {
    kk2::SegmentTree<CustomMonoid> seg(std::vector<CustomMonoid>{{1}, {2}});
    kk2::LazySegmentTree<CustomAction> lazy(std::vector<CustomMonoid>{{1}, {2}});
    return seg.all_prod().value == 3 && lazy.all_prod().value == 3 ? 0 : 1;
}
