#ifndef SEGMENT_TREE_LAZY_HPP
#define SEGMENT_TREE_LAZY_HPP 1

#include "lazy_base.hpp"

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct LazySegTree : public LazySegTreeBase<S, op, e, F, mapping, composition, id> {
    using LazySegTreeBase<S, op, e, F, mapping, composition, id>::LazySegTreeBase;
  protected:
    void all_apply(int k, F f) override {
        this->d[k] = mapping(f, this->d[k]);
        if (k < this->size) this->lz[k] = composition(f, this->lz[k]);
    }
};

#endif // SEGMENT_TREE_LAZY_HPP
