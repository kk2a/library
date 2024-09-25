#ifndef SEGMENT_TREE_BEATS_HPP
#define SEGMENT_TREE_BEATS_HPP 1



namespace kk2 {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)(),
          bool (*fail)(S)>
struct SegTreeBeats {



};

} // namespace kk2

#endif // SEGMENT_TREE_BEATS_HPP
