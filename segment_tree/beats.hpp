#ifndef SEGMENT_TREE_BEATS_HPP
#define SEGMENT_TREE_BEATS_HPP 1

#include "lazy_base.hpp"

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)(),
          bool (*fail)(S)>
struct SegTreeBeats : public LazySegTreeBase<S, op, e, F, mapping, composition, id> {
    using LazySegTreeBase<S, op, e, F, mapping, composition, id>::LazySegTreeBase;
  protected:
    void all_apply(int k, F f) override {
        this->d[k] = mapping(f, this->d[k]);
        if (k < this->size) {
            this->lz[k] = composition(f, this->lz[k]);
            if (fail(this->d[k])) this->push(k), this->update(k);
        }
    }
};

#endif // SEGMENT_TREE_BEATS_HPP
