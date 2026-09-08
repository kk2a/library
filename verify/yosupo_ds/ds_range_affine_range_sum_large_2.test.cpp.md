---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum_large_array
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum_large_array
  dependencies:
  - files:
    - filename: affine_sumwithsize.hpp
      icon: LIBRARY_ALL_AC
      path: math/action/affine_sumwithsize.hpp
    - filename: sum_with_size.hpp
      icon: LIBRARY_ALL_AC
      path: math/group/sum_with_size.hpp
    - filename: affine.hpp
      icon: LIBRARY_ALL_AC
      path: math/monoid/affine.hpp
    - filename: modint.hpp
      icon: LIBRARY_ALL_AC
      path: modint/modint.hpp
    - filename: coordinate_compression.hpp
      icon: LIBRARY_ALL_AC
      path: others/coordinate_compression.hpp
    - filename: lazy.hpp
      icon: LIBRARY_ALL_AC
      path: segment_tree/lazy.hpp
    - filename: constant.hpp
      icon: LIBRARY_ALL_AC
      path: template/constant.hpp
    - filename: fastio.hpp
      icon: LIBRARY_ALL_AC
      path: template/fastio.hpp
    - filename: io_util.hpp
      icon: LIBRARY_ALL_AC
      path: template/io_util.hpp
    - filename: macros.hpp
      icon: LIBRARY_ALL_AC
      path: template/macros.hpp
    - filename: template.hpp
      icon: LIBRARY_ALL_AC
      path: template/template.hpp
    - filename: type_alias.hpp
      icon: LIBRARY_ALL_AC
      path: template/type_alias.hpp
    - filename: algebra.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/algebra.hpp
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn:
  - math/action/affine_sumwithsize.hpp
  - math/group/sum_with_size.hpp
  - math/monoid/affine.hpp
  - modint/modint.hpp
  - others/coordinate_compression.hpp
  - segment_tree/lazy.hpp
  - template/constant.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  - template/template.hpp
  - template/type_alias.hpp
  - type_traits/algebra.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_affine_range_sum_large_array\n\
      \n#include \"../../segment_tree/lazy.hpp\"\n#include \"../../math/action/affine_sumwithsize.hpp\"\
      \n#include \"../../modint/modint.hpp\"\n#include \"../../others/coordinate_compression.hpp\"\
      \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
      \ {\n    using mint = kk2::mint998;\n    using A = kk2::action::AffineSumWithSize<mint,\
      \ mint>;\n    int n, q;\n    kin >> n >> q;\n    vc<array<int, 5>> queries(q);\n\
      \    kk2::CC<int> cc;\n    rep (i, q) {\n        auto &x = queries[i];\n   \
      \     kin >> x[0];\n        if (x[0] == 0) {\n            kin >> x[1] >> x[2]\
      \ >> x[3] >> x[4];\n            cc.add(x[1]), cc.add(x[2]);\n        } else\
      \ if (x[0] == 1) {\n            kin >> x[1] >> x[2];\n            cc.add(x[1]),\
      \ cc.add(x[2]);\n        }\n    }\n    cc.build();\n    rep (i, q) {\n     \
      \   auto &x = queries[i];\n        if (x[0] == 0) {\n            x[1] = cc.get(x[1]);\n\
      \            x[2] = cc.get(x[2]);\n        } else if (x[0] == 1) {\n       \
      \     x[1] = cc.get(x[1]);\n            x[2] = cc.get(x[2]);\n        }\n  \
      \  }\n    kk2::LazySegmentTree<A> seg(cc.size());\n    rep (i, cc.size() - 1)\
      \ seg.init_set(i, 0, cc[i + 1] - cc[i]);\n    seg.build();\n\n    for (auto\
      \ query : queries) {\n        if (query[0] == 0) {\n            auto [_, l,\
      \ r, a, b] = query;\n            seg.apply_range(l, r, a, b);\n        } else\
      \ {\n            auto [_0, l, r, _1, _2] = query;\n            kout << seg.prod(l,\
      \ r).a << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
    name: default
  - code: "#line 1 \"verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp\"\
      \n// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_affine_range_sum_large_array\n\
      \n#line 1 \"segment_tree/lazy.hpp\"\n\n\n\n#include <cassert>\n#include <vector>\n\
      \n#line 1 \"type_traits/algebra.hpp\"\n\n\n\n#include <concepts>\n\nnamespace\
      \ kk2 {\n\nnamespace algebra {\n\n// These concepts describe the static interface\
      \ expected by the library.\n// Algebraic laws such as associativity cannot be\
      \ checked by the type system.\n//\n// A user-defined monoid therefore needs\
      \ only:\n//\n//   struct MyMonoid {\n//       static MyMonoid op(const MyMonoid\
      \ &, const MyMonoid &);\n//       static MyMonoid unit();\n//   };\n//\n// The\
      \ return types are intentionally exact, so a typo such as returning the\n//\
      \ underlying scalar instead of MyMonoid is diagnosed at the concept boundary.\n\
      template <class T>\nconcept Semigroup = requires(const T &x, const T &y) {\n\
      \    { T::op(x, y) } -> std::same_as<T>;\n};\n\ntemplate <class T>\nconcept\
      \ Monoid = Semigroup<T> && requires {\n    { T::unit() } -> std::same_as<T>;\n\
      };\n\ntemplate <class T>\nconcept Group = Monoid<T> && requires(const T &x)\
      \ {\n    { T::inv(x) } -> std::same_as<T>;\n};\n\ntemplate <class T>\nconcept\
      \ CommutativeMonoid = Monoid<T> && requires {\n    { T::commutative } -> std::convertible_to<bool>;\n\
      } && bool(T::commutative);\n\ntemplate <class T>\nconcept CommutativeGroup =\
      \ Group<T> && requires {\n    { T::commutative } -> std::convertible_to<bool>;\n\
      } && bool(T::commutative);\n\n// An action specification owns the pair of algebraic\
      \ types and the mapping\n// between them. It is the interface required by lazy\
      \ propagation structures.\ntemplate <class T>\nconcept Action = requires {\n\
      \    typename T::A;\n    typename T::S;\n} && Monoid<typename T::A> && Monoid<typename\
      \ T::S>\n    && requires(const typename T::A &f, const typename T::S &x) {\n\
      \           { T::act(f, x) } -> std::same_as<typename T::S>;\n       };\n\n\
      } // namespace algebra\n\n} // namespace kk2\n\n\n#line 8 \"segment_tree/lazy.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <algebra::Action Action> struct LazySegmentTree\
      \ {\n    using S = typename Action::S;\n    using F = typename Action::A;\n\n\
      \  public:\n    LazySegmentTree() : LazySegmentTree(0) {}\n\n    LazySegmentTree(int\
      \ n) : _n(n) {\n        log = 0;\n        while ((1ll << log) < _n) log++;\n\
      \        size = 1 << log;\n        d = std::vector<S>(2 * size, S::unit());\n\
      \        lz = std::vector<F>(size, F::unit());\n    }\n\n    template <class...\
      \ Args> LazySegmentTree(int n, Args... args)\n        : LazySegmentTree(std::vector<S>(n,\
      \ S(args...))) {}\n\n    LazySegmentTree(const std::vector<S> &v) : _n(int(v.size()))\
      \ {\n        log = 0;\n        while ((1ll << log) < _n) log++;\n        size\
      \ = 1 << log;\n        d = std::vector<S>(2 * size, S::unit());\n        lz\
      \ = std::vector<F>(size, F::unit());\n        for (int i = 0; i < _n; i++) d[size\
      \ + i] = v[i];\n        build();\n    }\n\n    void build() {\n        assert(!is_built);\n\
      \        is_built = true;\n        for (int i = size - 1; i >= 1; i--) update(i);\n\
      \    }\n\n    template <class... Args> void init_set(int p, Args... args) {\n\
      \        assert(0 <= p && p < _n);\n        assert(!is_built);\n        d[p\
      \ + size] = S(args...);\n    }\n\n    using Monoid = S;\n    static S Op(S l,\
      \ S r) { return S::op(l, r); }\n    static S MonoidUnit() { return S::unit();\
      \ }\n\n    using Hom = F;\n    static S Map(F f, S x) { return Action::act(f,\
      \ x); }\n    static F Composition(F l, F r) { return F::op(l, r); }\n    static\
      \ F HomUnit() { return F::unit(); }\n\n    template <class... Args> void set(int\
      \ p, Args... args) {\n        assert(0 <= p && p < _n);\n        assert(is_built);\n\
      \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n\
      \        d[p] = S(args...);\n        for (int i = 1; i <= log; i++) update(p\
      \ >> i);\n    }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n \
      \       assert(is_built);\n        p += size;\n        for (int i = log; i >=\
      \ 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    S prod(int l, int\
      \ r) {\n        assert(0 <= l && l <= r && r <= _n);\n        assert(is_built);\n\
      \        if (l == r) return S::unit();\n        l += size;\n        r += size;\n\
      \        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
      \ l) push(l >> i);\n            if (((r >> i) << i) != r) push(r >> i);\n  \
      \      }\n        S sml = S::unit(), smr = S::unit();\n        while (l < r)\
      \ {\n            if (l & 1) sml = S::op(sml, d[l++]);\n            if (r & 1)\
      \ smr = S::op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n  \
      \      }\n        return S::op(sml, smr);\n    }\n\n    S all_prod() {\n   \
      \     assert(is_built);\n        return d[1];\n    }\n\n    template <class...\
      \ Args> void apply_point(int p, Args... args) {\n        assert(0 <= p && p\
      \ < _n);\n        assert(is_built);\n        p += size;\n        for (int i\
      \ = log; i >= 1; i--) push(p >> i);\n        d[p] = Action::act(F(args...),\
      \ d[p]);\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n\
      \    template <class... Args> void apply_range(int l, int r, Args... args) {\n\
      \        assert(0 <= l && l <= r && r <= _n);\n        assert(is_built);\n \
      \       if (l == r) return;\n        F f = F(args...);\n        l += size;\n\
      \        r += size;\n        for (int i = log; i >= 1; i--) {\n            if\
      \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
      \ push((r - 1) >> i);\n        }\n        {\n            int l2 = l, r2 = r;\n\
      \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
      \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n \
      \               r >>= 1;\n            }\n            l = l2;\n            r\
      \ = r2;\n        }\n        for (int i = 1; i <= log; i++) {\n            if\
      \ (((l >> i) << i) != l) update(l >> i);\n            if (((r >> i) << i) !=\
      \ r) update((r - 1) >> i);\n        }\n    }\n\n    template <bool (*g)(S)>\
      \ int max_right(int l) {\n        return max_right(l, [](S x) { return g(x);\
      \ });\n    }\n\n    template <class G> int max_right(int l, G g) {\n       \
      \ assert(0 <= l && l <= _n);\n        assert(g(S::unit()));\n        assert(is_built);\n\
      \        if (l == _n) return _n;\n        l += size;\n        for (int i = log;\
      \ i >= 1; i--) push(l >> i);\n        S sm = S::unit();\n        do {\n    \
      \        while (l % 2 == 0) l >>= 1;\n            if (!g(S::op(sm, d[l]))) {\n\
      \                while (l < size) {\n                    push(l);\n        \
      \            l = 2 * l;\n                    if (g(S::op(sm, d[l]))) {\n   \
      \                     sm = S::op(sm, d[l]);\n                        l++;\n\
      \                    }\n                }\n                return l - size;\n\
      \            }\n            sm = S::op(sm, d[l]);\n            l++;\n      \
      \  } while ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool\
      \ (*g)(S)> int min_left(int r) {\n        return min_left(r, [](S x) { return\
      \ g(x); });\n    }\n\n    template <class G> int min_left(int r, G g) {\n  \
      \      assert(0 <= r && r <= _n);\n        assert(g(S::unit()));\n        assert(is_built);\n\
      \        if (r == 0) return 0;\n        r += size;\n        for (int i = log;\
      \ i >= 1; i--) push((r - 1) >> i);\n        S sm = S::unit();\n        do {\n\
      \            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n         \
      \   if (!g(S::op(d[r], sm))) {\n                while (r < size) {\n       \
      \             push(r);\n                    r = 2 * r + 1;\n               \
      \     if (g(S::op(d[r], sm))) {\n                        sm = S::op(d[r], sm);\n\
      \                        r--;\n                    }\n                }\n  \
      \              return r + 1 - size;\n            }\n            sm = S::op(d[r],\
      \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n\
      \    int _n, size, log;\n    std::vector<S> d;\n    std::vector<F> lz;\n   \
      \ bool is_built = false;\n\n    void update(int k) { d[k] = S::op(d[2 * k],\
      \ d[2 * k + 1]); }\n\n    void all_apply(int k, const F &f) {\n        d[k]\
      \ = Action::act(f, d[k]);\n        if (k < size) lz[k] = F::op(f, lz[k]);\n\
      \    }\n\n    void push(int k) {\n        all_apply(2 * k, lz[k]);\n       \
      \ all_apply(2 * k + 1, lz[k]);\n        lz[k] = F::unit();\n    }\n};\n\n} //\
      \ namespace kk2\n\n\n#line 1 \"math/action/affine_sumwithsize.hpp\"\n\n\n\n\
      #line 1 \"math/group/sum_with_size.hpp\"\n\n\n\n#line 1 \"type_traits/io.hpp\"\
      \n\n\n\n#line 5 \"type_traits/io.hpp\"\n#include <fstream>\n#include <istream>\n\
      #include <ostream>\n#include <type_traits>\n\nnamespace kk2 {\n\nnamespace type_traits\
      \ {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\
      \ntemplate <typename T> using is_standard_istream =\n    typename std::conditional<std::is_same<T,\
      \ std::istream>::value\n                                  || std::is_same<T,\
      \ std::ifstream>::value,\n                              std::true_type,\n  \
      \                            std::false_type>::type;\ntemplate <typename T>\
      \ using is_standard_ostream =\n    typename std::conditional<std::is_same<T,\
      \ std::ostream>::value\n                                  || std::is_same<T,\
      \ std::ofstream>::value,\n                              std::true_type,\n  \
      \                            std::false_type>::type;\ntemplate <typename T>\
      \ using is_user_defined_istream = std::is_base_of<type_traits::istream_tag,\
      \ T>;\ntemplate <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
      \ T>;\n\ntemplate <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
      \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
      \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate\
      \ <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\
      \ntemplate <class T>\nconcept StandardInputStream = is_standard_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept StandardOutputStream = is_standard_ostream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept InputStream = is_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept OutputStream = is_ostream<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 5 \"math/group/sum_with_size.hpp\"\n\nnamespace\
      \ kk2 {\n\nnamespace group {\n\ntemplate <class S, class T = S> struct SumWithSize\
      \ {\n    static constexpr bool commutative = true;\n    using M = SumWithSize;\n\
      \    S a;\n    T size;\n\n    SumWithSize() : a(S()), size(0) {}\n    SumWithSize(S\
      \ a_, S size_ = T(1)) : a(a_), size(size_) {}\n    operator S() const { return\
      \ a; }\n    inline static M op(M l, M r) { return M(l.a + r.a, l.size + r.size);\
      \ }\n    inline static M inv(M x) { return M(-x.a, -x.size); }\n    inline static\
      \ M unit() { return M(); }\n    bool operator==(const M &rhs) const { return\
      \ a == rhs.a and size == rhs.size; }\n    bool operator!=(const M &rhs) const\
      \ { return a != rhs.a or size != rhs.size; }\n\n    template <OutputStream OStream>\n\
      \    friend OStream &operator<<(OStream &os, const M &x) {\n        return os\
      \ << x.a << \" \" << x.size;\n    }\n\n    template <InputStream IStream>\n\
      \    friend IStream &operator>>(IStream &is, M &x) {\n        is >> x.a;\n \
      \       x.size = T(1);\n        return is;\n    }\n};\n\n} // namespace group\n\
      \n} // namespace kk2\n\n\n#line 1 \"math/monoid/affine.hpp\"\n\n\n\n#line 5\
      \ \"math/monoid/affine.hpp\"\n\nnamespace kk2 {\n\nnamespace monoid {\n\ntemplate\
      \ <class S> struct Affine {\n    static constexpr bool commutative = false;\n\
      \    using M = Affine;\n    S a, b; // x \\mapsto ax + b\n\n    Affine() : a(S(1)),\
      \ b(S(0)) {};\n    Affine(S a, S b) : a(a), b(b) {}\n    inline S eval(S x)\
      \ const { return a * x + b; }\n    // l \\circ r\n    inline static M op(M l,\
      \ M r) { return M(l.a * r.a, l.a * r.b + l.b); }\n    inline static M unit()\
      \ { return M(); }\n    inline static M inv(M f) { return M(S(1) / f.a, -f.b\
      \ / f.a); }\n    bool operator==(const M &rhs) const { return a == rhs.a and\
      \ b == rhs.b; }\n    bool operator!=(const M &rhs) const { return a != rhs.a\
      \ or b != rhs.b; }\n\n    template <OutputStream OStream>\n    friend OStream\
      \ &operator<<(OStream &os, const M &x) {\n        return os << x.a << \" \"\
      \ << x.b;\n    }\n\n    template <InputStream IStream>\n    friend IStream &operator>>(IStream\
      \ &is, M &x) {\n        return is >> x.a >> x.b;\n    }\n};\n\n} // namespace\
      \ monoid\n\n} // namespace kk2\n\n\n#line 6 \"math/action/affine_sumwithsize.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace action {\n\ntemplate <class T, class U> struct\
      \ AffineSumWithSize {\n    using A = monoid::Affine<T>;\n    using S = group::SumWithSize<T,\
      \ U>;\n\n    inline static S act(A f, S x) { return S(f.a * x.a + f.b * x.size,\
      \ x.size); }\n};\n\n} // namespace action\n\n} // namespace kk2\n\n\n#line 1\
      \ \"modint/modint.hpp\"\n\n\n\n#line 5 \"modint/modint.hpp\"\n#include <iostream>\n\
      #line 7 \"modint/modint.hpp\"\n#include <utility>\n\n#line 1 \"type_traits/integral.hpp\"\
      \n\n\n\n#line 5 \"type_traits/integral.hpp\"\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\
      \ntemplate <typename T> using is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __int128_t>::value\n                                  or std::is_same<T, __int128>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T> using is_unsigned_int128\
      \ =\n    typename std::conditional<std::is_same<T, __uint128_t>::value\n   \
      \                               or std::is_same<T, unsigned __int128>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T> using is_integral =\n \
      \   typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
      \                                  or is_unsigned_int128<T>::value,\n      \
      \                        std::true_type,\n                              std::false_type>::type;\n\
      \ntemplate <typename T> using is_signed =\n    typename std::conditional<std::is_signed<T>::value\
      \ or is_signed_int128<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
      \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename\
      \ T> using to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
      \                              make_unsigned_int128<T>,\n                  \
      \            typename std::conditional<std::is_signed<T>::value,\n         \
      \                                               std::make_unsigned<T>,\n   \
      \                                                     std::common_type<T>>::type>::type;\n\
      \n#else\n\ntemplate <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
      template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
      template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
      template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
      \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
      template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
      template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
      \ntemplate <class T>\nconcept Integral = is_integral<std::remove_cv_t<T>>::value;\n\
      \ntemplate <class T>\nconcept SignedIntegral = is_signed<std::remove_cv_t<T>>::value;\n\
      \ntemplate <class T>\nconcept UnsignedIntegral = is_unsigned<std::remove_cv_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 11 \"modint/modint.hpp\"\n\nnamespace kk2 {\n\
      \ntemplate <int p> struct ModInt {\n    using mint = ModInt;\n\n  public:\n\
      \    static int Mod;\n\n    constexpr static unsigned int getmod() {\n     \
      \   if (p > 0) return p;\n        else return Mod;\n    }\n\n    static void\
      \ setmod(int Mod_) {\n        assert(1 <= Mod_);\n        Mod = Mod_;\n    }\n\
      \n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n       \
      \ return x;\n    }\n\n    constexpr ModInt() : _v(0) {}\n\n    template <Integral\
      \ T> constexpr ModInt(T v) {\n        if constexpr (SignedIntegral<T>) {\n \
      \           v = v % (long long)(getmod());\n            if (v < 0) v += getmod();\n\
      \            _v = v;\n        } else if constexpr (UnsignedIntegral<T>) {\n\
      \            _v = v %= getmod();\n        } else {\n            ModInt();\n\
      \        }\n    }\n\n    unsigned int val() const { return _v; }\n\n    mint\
      \ &operator++() {\n        _v++;\n        if (_v == getmod()) _v = 0;\n    \
      \    return *this;\n    }\n\n    mint &operator--() {\n        if (_v == 0)\
      \ _v = getmod();\n        _v--;\n        return *this;\n    }\n\n    mint operator++(int)\
      \ {\n        mint result = *this;\n        ++*this;\n        return result;\n\
      \    }\n\n    mint operator--(int) {\n        mint result = *this;\n       \
      \ --*this;\n        return result;\n    }\n\n    mint &operator+=(const mint\
      \ &rhs) {\n        _v += rhs._v;\n        if (_v >= getmod()) _v -= getmod();\n\
      \        return *this;\n    }\n\n    mint &operator-=(const mint &rhs) {\n \
      \       _v += getmod() - rhs._v;\n        if (_v >= getmod()) _v -= getmod();\n\
      \        return *this;\n    }\n\n    mint &operator*=(const mint &rhs) {\n \
      \       unsigned long long z = _v;\n        z *= rhs._v;\n        z %= getmod();\n\
      \        _v = z;\n        return *this;\n    }\n\n    mint &operator/=(const\
      \ mint &rhs) { return *this = *this * rhs.inv(); }\n    mint operator+() const\
      \ { return *this; }\n    mint operator-() const { return mint() - *this; }\n\
      \    friend mint operator+(const mint &lhs, const mint &rhs) { return mint(lhs)\
      \ += rhs; }\n    friend mint operator-(const mint &lhs, const mint &rhs) { return\
      \ mint(lhs) -= rhs; }\n    friend mint operator*(const mint &lhs, const mint\
      \ &rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const mint &lhs,\
      \ const mint &rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
      \ mint &lhs, const mint &rhs) { return lhs._v == rhs._v; }\n    friend bool\
      \ operator!=(const mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }\n\
      \n    mint pow(long long n) const {\n        assert(0 <= n);\n        mint x\
      \ = *this, r = 1;\n        while (n) {\n            if (n & 1) r *= x;\n   \
      \         x *= x;\n            n >>= 1;\n        }\n        return r;\n    }\n\
      \n    mint inv() const {\n        long long s = getmod(), t = _v;\n        long\
      \ long m0 = 0, m1 = 1;\n\n        while (t) {\n            long long u = s /\
      \ t;\n            s -= t * u;\n            m0 -= m1 * u;\n\n            std::swap(s,\
      \ t);\n            std::swap(m0, m1);\n        }\n        if (m0 < 0) m0 +=\
      \ getmod() / s;\n        return m0;\n    }\n\n    template <OutputStream OStream>\n\
      \    friend OStream &operator<<(OStream &os, const mint &mint_) {\n        os\
      \ << mint_._v;\n        return os;\n    }\n\n    template <InputStream IStream>\n\
      \    friend IStream &operator>>(IStream &is, mint &mint_) {\n        long long\
      \ x;\n        is >> x;\n        mint_ = mint(x);\n        return is;\n    }\n\
      \n  private:\n    unsigned int _v;\n};\n\ntemplate <int p> int ModInt<p>::Mod\
      \ = 998244353;\n\nusing mint998 = ModInt<998244353>;\nusing mint107 = ModInt<1000000007>;\n\
      \n} // namespace kk2\n\n\n#line 1 \"others/coordinate_compression.hpp\"\n\n\n\
      \n#include <algorithm>\n#line 6 \"others/coordinate_compression.hpp\"\n\nnamespace\
      \ kk2 {\n\n// Coordinate Compression\ntemplate <typename S = int> struct CC\
      \ {\n    std::vector<S> xs;\n    bool initialized;\n\n    CC() : initialized(false)\
      \ {}\n\n    CC(const std::vector<S> &xs_) : xs(xs_), initialized(false) {}\n\
      \n    void add(S x) {\n        xs.push_back(x);\n        initialized = false;\n\
      \    }\n\n    void add(const std::vector<S> &ys) {\n        std::copy(std::begin(ys),\
      \ std::end(ys), std::back_inserter(xs));\n        initialized = false;\n   \
      \ }\n\n    void build() {\n        std::sort(std::begin(xs), std::end(xs));\n\
      \        xs.erase(std::unique(std::begin(xs), std::end(xs)), std::end(xs));\n\
      \        initialized = true;\n    }\n\n    S operator[](int i) {\n        if\
      \ (!initialized) build();\n        return xs[i];\n    }\n\n    int size() {\n\
      \        if (!initialized) build();\n        return xs.size();\n    }\n\n  \
      \  int get(S x) {\n        if (!initialized) build();\n        return std::upper_bound(std::begin(xs),\
      \ std::end(xs), x) - std::begin(xs) - 1;\n    }\n\n    std::vector<int> get(const\
      \ std::vector<S> &ys) {\n        std::vector<int> ret(ys.size());\n        for\
      \ (int i = 0; i < (int)ys.size(); ++i) ret[i] = get(ys[i]);\n        return\
      \ ret;\n    }\n\n    int operator()(S x) { return get(x); }\n\n    std::vector<int>\
      \ operator()(const std::vector<S> &ys) { return get(ys); }\n\n    int lower(S\
      \ x) {\n        if (!initialized) build();\n        return std::lower_bound(std::begin(xs),\
      \ std::end(xs), x) - std::begin(xs);\n    }\n\n    int upper(S x) {\n      \
      \  if (!initialized) build();\n        return std::upper_bound(std::begin(xs),\
      \ std::end(xs), x) - std::begin(xs);\n    }\n\n    bool exist(S x) {\n     \
      \   if (!initialized) build();\n        int idx = lower(x);\n        return\
      \ idx < (int)xs.size() && xs[idx] == x;\n    }\n};\n\n} // namespace kk2\n\n\
      \n#line 1 \"template/template.hpp\"\n\n\n\n#line 5 \"template/template.hpp\"\
      \n#include <array>\n#include <bitset>\n#line 8 \"template/template.hpp\"\n#include\
      \ <chrono>\n#include <cmath>\n#include <deque>\n#include <functional>\n#include\
      \ <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
      \ <optional>\n#include <queue>\n#include <random>\n#include <set>\n#include\
      \ <stack>\n#include <string>\n#include <unordered_map>\n#include <unordered_set>\n\
      #line 26 \"template/template.hpp\"\n\n#line 1 \"template/constant.hpp\"\n\n\n\
      \n#line 1 \"template/type_alias.hpp\"\n\n\n\n#line 8 \"template/type_alias.hpp\"\
      \n\nusing u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned\
      \ long long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi\
      \ = std::pair<int, int>;\nusing pl = std::pair<i64, i64>;\nusing pil = std::pair<int,\
      \ i64>;\nusing pli = std::pair<i64, int>;\n\ntemplate <class T> using vc = std::vector<T>;\n\
      template <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using\
      \ vvvc = std::vector<vvc<T>>;\ntemplate <class T> using vvvvc = std::vector<vvvc<T>>;\n\
      \ntemplate <class T> using pq = std::priority_queue<T>;\ntemplate <class T>\
      \ using pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\n\n\
      #line 5 \"template/constant.hpp\"\n\ntemplate <class T> constexpr T infty =\
      \ 0;\ntemplate <> constexpr int infty<int> = (1 << 30) - 123;\ntemplate <> constexpr\
      \ i64 infty<i64> = (1ll << 62) - (1ll << 31);\ntemplate <> constexpr i128 infty<i128>\
      \ = (i128(1) << 126) - (i128(1) << 63);\ntemplate <> constexpr u32 infty<u32>\
      \ = infty<int>;\ntemplate <> constexpr u64 infty<u64> = infty<i64>;\ntemplate\
      \ <> constexpr u128 infty<u128> = infty<i128>;\ntemplate <> constexpr double\
      \ infty<double> = infty<i64>;\ntemplate <> constexpr long double infty<long\
      \ double> = infty<i64>;\n\nconstexpr int mod = 998244353;\nconstexpr int modu\
      \ = 1e9 + 7;\nconstexpr long double PI = 3.14159265358979323846;\n\n\n#line\
      \ 1 \"template/fastio.hpp\"\n\n\n\n#include <cctype>\n#include <cstdint>\n#include\
      \ <cstdio>\n#line 10 \"template/fastio.hpp\"\n\n#line 13 \"template/fastio.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace fastio {\n\nstruct Scanner : type_traits::istream_tag\
      \ {\n  private:\n    static constexpr size_t INPUT_BUF = 1 << 17;\n    size_t\
      \ pos = 0, end = 0;\n    bool is_eof = false;\n    static char buf[INPUT_BUF];\n\
      \    FILE *fp;\n\n  public:\n    Scanner() : fp(stdin) {}\n\n    Scanner(const\
      \ char *file) : fp(fopen(file, \"r\")) {}\n\n    ~Scanner() {\n        if (fp\
      \ != stdin) fclose(fp);\n    }\n\n    char now() {\n        if (is_eof) return\
      \ '\\0';\n        if (pos == end) {\n            end = fread(buf, 1, INPUT_BUF,\
      \ fp);\n            if (end != INPUT_BUF) buf[end] = '\\0';\n            if\
      \ (end == 0) is_eof = true;\n            pos = 0;\n        }\n        return\
      \ buf[pos];\n    }\n\n    void skip_space() {\n        while (isspace(now()))\
      \ ++pos;\n    }\n\n    template <UnsignedIntegral T> T next_unsigned_integral()\
      \ {\n        skip_space();\n        T res{};\n        while (isdigit(now()))\
      \ {\n            res = res * 10 + (now() - '0');\n            ++pos;\n     \
      \   }\n        return res;\n    }\n\n    template <SignedIntegral T> T next_signed_integral()\
      \ {\n        skip_space();\n        if (now() == '-') {\n            ++pos;\n\
      \            return T(-next_unsigned_integral<typename to_unsigned<T>::type>());\n\
      \        } else return (T)next_unsigned_integral<typename to_unsigned<T>::type>();\n\
      \    }\n\n    char next_char() {\n        skip_space();\n        auto res =\
      \ now();\n        ++pos;\n        return res;\n    }\n\n    std::string next_string()\
      \ {\n        skip_space();\n        std::string res;\n        while (true) {\n\
      \            char c = now();\n            if (isspace(c) or c == '\\0') break;\n\
      \            res.push_back(now());\n            ++pos;\n        }\n        return\
      \ res;\n    }\n\n    template <UnsignedIntegral T> Scanner &operator>>(T &x)\
      \ {\n        x = next_unsigned_integral<T>();\n        return *this;\n    }\n\
      \n    template <SignedIntegral T> Scanner &operator>>(T &x) {\n        x = next_signed_integral<T>();\n\
      \        return *this;\n    }\n\n    Scanner &operator>>(char &x) {\n      \
      \  x = next_char();\n        return *this;\n    }\n\n    Scanner &operator>>(std::string\
      \ &x) {\n        x = next_string();\n        return *this;\n    }\n};\n\nstruct\
      \ endl_struct_t {};\n\nstruct Printer : type_traits::ostream_tag {\n  private:\n\
      \    static char helper[10000][5];\n    static char leading_zero[10000][5];\n\
      \    constexpr static size_t OUTPUT_BUF = 1 << 17;\n    static char buf[OUTPUT_BUF];\n\
      \    size_t pos = 0;\n    FILE *fp;\n\n    template <class T> static constexpr\
      \ void div_mod(T &a, T &b, T mod) {\n        a = b / mod;\n        b -= a *\
      \ mod;\n    }\n\n    static void init() {\n        buf[0] = '\\0';\n       \
      \ for (size_t i = 0; i < 10000; ++i) {\n            leading_zero[i][0] = i /\
      \ 1000 + '0';\n            leading_zero[i][1] = i / 100 % 10 + '0';\n      \
      \      leading_zero[i][2] = i / 10 % 10 + '0';\n            leading_zero[i][3]\
      \ = i % 10 + '0';\n            leading_zero[i][4] = '\\0';\n\n            size_t\
      \ j = 0;\n            if (i >= 1000) helper[i][j++] = i / 1000 + '0';\n    \
      \        if (i >= 100) helper[i][j++] = i / 100 % 10 + '0';\n            if\
      \ (i >= 10) helper[i][j++] = i / 10 % 10 + '0';\n            helper[i][j++]\
      \ = i % 10 + '0';\n            helper[i][j] = '\\0';\n        }\n    }\n\n \
      \ public:\n    Printer() : fp(stdout) { init(); }\n\n    Printer(const char\
      \ *file) : fp(fopen(file, \"w\")) { init(); }\n\n    ~Printer() {\n        write();\n\
      \        if (fp != stdout) fclose(fp);\n    }\n\n    void write() {\n      \
      \  fwrite(buf, 1, pos, fp);\n        pos = 0;\n    }\n\n    void flush() {\n\
      \        write();\n        fflush(fp);\n    }\n\n    void put_char(char c) {\n\
      \        if (pos == OUTPUT_BUF) write();\n        buf[pos++] = c;\n    }\n\n\
      \    void put_cstr(const char *s) {\n        while (*s) put_char(*(s++));\n\
      \    }\n\n    void put_u32(uint32_t x) {\n        uint32_t y;\n        if (x\
      \ >= 100000000) { // 10^8\n            div_mod<uint32_t>(y, x, 100000000);\n\
      \            put_cstr(helper[y]);\n            div_mod<uint32_t>(y, x, 10000);\n\
      \            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
      \        } else if (x >= 10000) { // 10^4\n            div_mod<uint32_t>(y,\
      \ x, 10000);\n            put_cstr(helper[y]);\n            put_cstr(leading_zero[x]);\n\
      \        } else put_cstr(helper[x]);\n    }\n\n    void put_i32(int32_t x) {\n\
      \        if (x < 0) {\n            put_char('-');\n            put_u32(-x);\n\
      \        } else put_u32(x);\n    }\n\n    void put_u64(uint64_t x) {\n     \
      \   uint64_t y;\n        if (x >= 1000000000000ull) { // 10^12\n           \
      \ div_mod<uint64_t>(y, x, 1000000000000ull);\n            put_u32(y);\n    \
      \        div_mod<uint64_t>(y, x, 100000000ull);\n            put_cstr(leading_zero[y]);\n\
      \            div_mod<uint64_t>(y, x, 10000ull);\n            put_cstr(leading_zero[y]);\n\
      \            put_cstr(leading_zero[x]);\n        } else if (x >= 10000ull) {\
      \ // 10^4\n            div_mod<uint64_t>(y, x, 10000ull);\n            put_u32(y);\n\
      \            put_cstr(leading_zero[x]);\n        } else put_cstr(helper[x]);\n\
      \    }\n\n    void put_i64(int64_t x) {\n        if (x < 0) {\n            put_char('-');\n\
      \            put_u64(-x);\n        } else put_u64(x);\n    }\n\n    void put_u128(__uint128_t\
      \ x) {\n        constexpr static __uint128_t pow10_10 = 10000000000ull;\n  \
      \      constexpr static __uint128_t pow10_20 = pow10_10 * pow10_10;\n\n    \
      \    __uint128_t y;\n        if (x >= pow10_20) { // 10^20\n            div_mod<__uint128_t>(y,\
      \ x, pow10_20);\n            put_u64(uint64_t(y));\n            div_mod<__uint128_t>(y,\
      \ x, __uint128_t(10000000000000000ull));\n            put_cstr(leading_zero[y]);\n\
      \            div_mod<__uint128_t>(y, x, __uint128_t(1000000000000ull));\n  \
      \          put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x,\
      \ __uint128_t(100000000ull));\n            put_cstr(leading_zero[y]);\n    \
      \        div_mod<__uint128_t>(y, x, __uint128_t(10000ull));\n            put_cstr(leading_zero[y]);\n\
      \            put_cstr(leading_zero[x]);\n        } else if (x >= __uint128_t(10000))\
      \ { // 10^4\n            div_mod<__uint128_t>(y, x, __uint128_t(10000));\n \
      \           put_u64(uint64_t(y));\n            put_cstr(leading_zero[x]);\n\
      \        } else put_cstr(helper[x]);\n    }\n\n    void put_i128(__int128_t\
      \ x) {\n        if (x < 0) {\n            put_char('-');\n            put_u128(-x);\n\
      \        } else put_u128(x);\n    }\n\n    template <UnsignedIntegral T> Printer\
      \ &operator<<(T x) {\n        if constexpr (sizeof(T) <= 4) put_u32(x);\n  \
      \      else if constexpr (sizeof(T) <= 8) put_u64(x);\n        else put_u128(x);\n\
      \        return *this;\n    }\n\n    template <SignedIntegral T> Printer &operator<<(T\
      \ x) {\n        if constexpr (sizeof(T) <= 4) put_i32(x);\n        else if constexpr\
      \ (sizeof(T) <= 8) put_i64(x);\n        else put_i128(x);\n        return *this;\n\
      \    }\n\n    Printer &operator<<(char x) {\n        put_char(x);\n        return\
      \ *this;\n    }\n\n    Printer &operator<<(const std::string &x) {\n       \
      \ for (char c : x) put_char(c);\n        return *this;\n    }\n\n    Printer\
      \ &operator<<(const char *x) {\n        put_cstr(x);\n        return *this;\n\
      \    }\n\n    // std::cout << std::endl; \u306F\u95A2\u6570\u30DD\u30A4\u30F3\
      \u30BF\u3092\u6E21\u3057\u3066\u3044\u308B\u3089\u3057\u3044\n    Printer &operator<<(endl_struct_t)\
      \ {\n        put_char('\\n');\n        flush();\n        return *this;\n   \
      \ }\n};\n\nchar Scanner::buf[Scanner::INPUT_BUF];\nchar Printer::buf[Printer::OUTPUT_BUF];\n\
      char Printer::helper[10000][5];\nchar Printer::leading_zero[10000][5];\n\n}\
      \ // namespace fastio\n\n#if defined(INTERACTIVE) || defined(USE_STDIO)\nauto\
      \ &kin = std::cin;\nauto &kout = std::cout;\nauto (*kendl)(std::ostream &) =\
      \ std::endl<char, std::char_traits<char>>;\n#else\nfastio::Scanner kin;\nfastio::Printer\
      \ kout;\nfastio::endl_struct_t kendl;\n#endif\n\n} // namespace kk2\n\n\n#line\
      \ 1 \"template/io_util.hpp\"\n\n\n\n#line 7 \"template/io_util.hpp\"\n\n#line\
      \ 9 \"template/io_util.hpp\"\n\n// \u306A\u3093\u304Boj verify\u306F\u30D7\u30ED\
      \u30C8\u30BF\u30A4\u30D7\u5BA3\u8A00\u304C\u843D\u3061\u308B\n\nnamespace impl\
      \ {\n\nstruct read {\n    template <class IStream, class T> inline static void\
      \ all_read(IStream &is, T &x) { is >> x; }\n\n    template <class IStream, class\
      \ T, class U>\n    inline static void all_read(IStream &is, std::pair<T, U>\
      \ &p) {\n        all_read(is, p.first);\n        all_read(is, p.second);\n \
      \   }\n\n    template <class IStream, class T> inline static void all_read(IStream\
      \ &is, std::vector<T> &v) {\n        for (T &x : v) all_read(is, x);\n    }\n\
      \n    template <class IStream, class T, size_t F>\n    inline static void all_read(IStream\
      \ &is, std::array<T, F> &a) {\n        for (T &x : a) all_read(is, x);\n   \
      \ }\n};\n\nstruct write {\n    template <class OStream, class T> inline static\
      \ void all_write(OStream &os, const T &x) {\n        os << x;\n    }\n\n   \
      \ template <class OStream, class T, class U>\n    inline static void all_write(OStream\
      \ &os, const std::pair<T, U> &p) {\n        all_write(os, p.first);\n      \
      \  all_write(os, ' ');\n        all_write(os, p.second);\n    }\n\n    template\
      \ <class OStream, class T>\n    inline static void all_write(OStream &os, const\
      \ std::vector<T> &v) {\n        for (int i = 0; i < (int)v.size(); ++i) {\n\
      \            if (i) all_write(os, ' ');\n            all_write(os, v[i]);\n\
      \        }\n    }\n\n    template <class OStream, class T, size_t F>\n    inline\
      \ static void all_write(OStream &os, const std::array<T, F> &a) {\n        for\
      \ (int i = 0; i < (int)F; ++i) {\n            if (i) all_write(os, ' ');\n \
      \           all_write(os, a[i]);\n        }\n    }\n};\n\n} // namespace impl\n\
      \ntemplate <kk2::InputStream IStream, class T, class U>\nIStream &operator>>(IStream\
      \ &is, std::pair<T, U> &p) {\n    impl::read::all_read(is, p);\n    return is;\n\
      }\n\ntemplate <kk2::InputStream IStream, class T>\nIStream &operator>>(IStream\
      \ &is, std::vector<T> &v) {\n    impl::read::all_read(is, v);\n    return is;\n\
      }\n\ntemplate <kk2::InputStream IStream, class T, size_t F>\nIStream &operator>>(IStream\
      \ &is, std::array<T, F> &a) {\n    impl::read::all_read(is, a);\n    return\
      \ is;\n}\n\ntemplate <kk2::OutputStream OStream, class T, class U>\nOStream\
      \ &operator<<(OStream &os, const std::pair<T, U> &p) {\n    impl::write::all_write(os,\
      \ p);\n    return os;\n}\n\ntemplate <kk2::OutputStream OStream, class T>\n\
      OStream &operator<<(OStream &os, const std::vector<T> &v) {\n    impl::write::all_write(os,\
      \ v);\n    return os;\n}\n\ntemplate <kk2::OutputStream OStream, class T, size_t\
      \ F>\nOStream &operator<<(OStream &os, const std::array<T, F> &a) {\n    impl::write::all_write(os,\
      \ a);\n    return os;\n}\n\n\n#line 1 \"template/macros.hpp\"\n\n\n\n#define\
      \ rep1(a) for (long long _ = 0; _ < (long long)(a); ++_)\n#define rep2(i, a)\
      \ for (long long i = 0; i < (long long)(a); ++i)\n#define rep3(i, a, b) for\
      \ (long long i = (a); i < (long long)(b); ++i)\n#define repi2(i, a) for (long\
      \ long i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (long long i =\
      \ (a) - 1; i >= (long long)(b); --i)\n#define overload3(a, b, c, d, ...) d\n\
      #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define\
      \ repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n#define\
      \ fi first\n#define se second\n#define all(p) begin(p), end(p)\n\n\n#line 32\
      \ \"template/template.hpp\"\n\nusing kk2::kendl;\nusing kk2::kin;\nusing kk2::kout;\n\
      \nvoid Yes(bool b = 1) { kout << (b ? \"Yes\\n\" : \"No\\n\"); }\nvoid No(bool\
      \ b = 1) { kout << (b ? \"No\\n\" : \"Yes\\n\"); }\nvoid YES(bool b = 1) { kout\
      \ << (b ? \"YES\\n\" : \"NO\\n\"); }\nvoid NO(bool b = 1) { kout << (b ? \"\
      NO\\n\" : \"YES\\n\"); }\nvoid yes(bool b = 1) { kout << (b ? \"yes\\n\" : \"\
      no\\n\"); }\nvoid no(bool b = 1) { kout << (b ? \"no\\n\" : \"yes\\n\"); }\n\
      template <class T, class S> inline bool chmax(T &a, const S &b) { return (a\
      \ < b ? a = b, 1 : 0); }\ntemplate <class T, class S> inline bool chmin(T &a,\
      \ const S &b) { return (a > b ? a = b, 1 : 0); }\n\n\n#line 8 \"verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp\"\
      \nusing namespace std;\n\nint main() {\n    using mint = kk2::mint998;\n   \
      \ using A = kk2::action::AffineSumWithSize<mint, mint>;\n    int n, q;\n   \
      \ kin >> n >> q;\n    vc<array<int, 5>> queries(q);\n    kk2::CC<int> cc;\n\
      \    rep (i, q) {\n        auto &x = queries[i];\n        kin >> x[0];\n   \
      \     if (x[0] == 0) {\n            kin >> x[1] >> x[2] >> x[3] >> x[4];\n \
      \           cc.add(x[1]), cc.add(x[2]);\n        } else if (x[0] == 1) {\n \
      \           kin >> x[1] >> x[2];\n            cc.add(x[1]), cc.add(x[2]);\n\
      \        }\n    }\n    cc.build();\n    rep (i, q) {\n        auto &x = queries[i];\n\
      \        if (x[0] == 0) {\n            x[1] = cc.get(x[1]);\n            x[2]\
      \ = cc.get(x[2]);\n        } else if (x[0] == 1) {\n            x[1] = cc.get(x[1]);\n\
      \            x[2] = cc.get(x[2]);\n        }\n    }\n    kk2::LazySegmentTree<A>\
      \ seg(cc.size());\n    rep (i, cc.size() - 1) seg.init_set(i, 0, cc[i + 1] -\
      \ cc[i]);\n    seg.build();\n\n    for (auto query : queries) {\n        if\
      \ (query[0] == 0) {\n            auto [_, l, r, a, b] = query;\n           \
      \ seg.apply_range(l, r, a, b);\n        } else {\n            auto [_0, l, r,\
      \ _1, _2] = query;\n            kout << seg.prod(l, r).a << \"\\n\";\n     \
      \   }\n    }\n\n    return 0;\n}\n"
    name: bundled
  isFailed: false
  isVerificationFile: true
  path: verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases:
  - elapsed: 0.12787749899999312
    environment: g++
    memory: 6.672
    name: dense_00
    status: AC
  - elapsed: 0.5415752669999847
    environment: g++
    memory: 6.672
    name: dense_01
    status: AC
  - elapsed: 0.9972584139999867
    environment: g++
    memory: 12.616
    name: dense_02
    status: AC
  - elapsed: 0.0023999199999877874
    environment: g++
    memory: 3.604
    name: example_00
    status: AC
  - elapsed: 1.1253468479999924
    environment: g++
    memory: 12.484
    name: many_query_0_00
    status: AC
  - elapsed: 1.1375679949999835
    environment: g++
    memory: 12.488
    name: many_query_0_01
    status: AC
  - elapsed: 0.9181242280000106
    environment: g++
    memory: 12.616
    name: many_query_1_00
    status: AC
  - elapsed: 0.8839003079999941
    environment: g++
    memory: 12.616
    name: many_query_1_01
    status: AC
  - elapsed: 1.0240210519999948
    environment: g++
    memory: 12.62
    name: max_random_00
    status: AC
  - elapsed: 1.025604541000007
    environment: g++
    memory: 12.544
    name: max_random_01
    status: AC
  - elapsed: 1.0317026479999925
    environment: g++
    memory: 12.608
    name: max_random_02
    status: AC
  - elapsed: 0.8867233590000012
    environment: g++
    memory: 9.616
    name: near_0_and_N_00
    status: AC
  - elapsed: 0.8878745709999976
    environment: g++
    memory: 9.576
    name: near_0_and_N_01
    status: AC
  - elapsed: 1.0057292400000222
    environment: g++
    memory: 12.552
    name: query_0_then_1_00
    status: AC
  - elapsed: 1.0104592100000218
    environment: g++
    memory: 12.54
    name: query_0_then_1_01
    status: AC
  - elapsed: 0.15586626800001113
    environment: g++
    memory: 5.68
    name: random_00
    status: AC
  - elapsed: 0.17386950200000229
    environment: g++
    memory: 5.808
    name: random_01
    status: AC
  - elapsed: 0.5879222840000011
    environment: g++
    memory: 8.488
    name: random_02
    status: AC
  - elapsed: 0.22866214100000093
    environment: g++
    memory: 6.06
    name: random_03
    status: AC
  - elapsed: 1.0095734930000049
    environment: g++
    memory: 12.572
    name: random_04
    status: AC
  - elapsed: 0.1181438830000161
    environment: g++
    memory: 6.672
    name: small_N_00
    status: AC
  - elapsed: 0.1460434859999964
    environment: g++
    memory: 6.616
    name: small_N_01
    status: AC
  - elapsed: 0.1536280139999917
    environment: g++
    memory: 6.636
    name: small_N_02
    status: AC
  - elapsed: 0.1770389909999892
    environment: g++
    memory: 6.64
    name: small_N_03
    status: AC
  - elapsed: 0.1881670129999975
    environment: g++
    memory: 6.676
    name: small_N_04
    status: AC
  - elapsed: 0.0026285920000077567
    environment: g++
    memory: 3.588
    name: small_Q_00
    status: AC
  - elapsed: 0.0020804920000045968
    environment: g++
    memory: 3.812
    name: small_Q_01
    status: AC
  - elapsed: 0.002091161999999258
    environment: g++
    memory: 3.768
    name: small_Q_02
    status: AC
  - elapsed: 0.002068087999987256
    environment: g++
    memory: 3.768
    name: small_Q_03
    status: AC
  - elapsed: 0.002086403000021164
    environment: g++
    memory: 3.756
    name: small_Q_04
    status: AC
  - elapsed: 0.002123983999979373
    environment: g++
    memory: 3.808
    name: small_Q_05
    status: AC
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
layout: document
---
