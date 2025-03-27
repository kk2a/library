#ifndef KK2_MATH_FLATTEN_INDICES_HPP
#define KK2_MATH_FLATTEN_INDICES_HPP 1

#include <vector>

namespace kk2 {

struct FlattenIndices {
  private:
    std::vector<int> _inner_dims;

  public:
    FlattenIndices(const std::vector<int> &dims) {
        _inner_dims.resize(dims.size() + 1);
        _inner_dims[0] = 1;
        for (unsigned int i = 1; i <= dims.size(); ++i)
            _inner_dims[i] = _inner_dims[i - 1] * dims[i - 1];
    }

    int operator()(const std::vector<int> &indices) const {
        int res = 0;
        for (unsigned int i = 0; i < indices.size(); ++i) res += indices[i] * _inner_dims[i];
        return res;
    }

    std::vector<int> operator()(int index) const {
        std::vector<int> res(_inner_dims.size() - 1);
        for (unsigned int i = 0; i < res.size(); ++i)
            res[i] = index / _inner_dims[i] % _inner_dims[i + 1];

        return res;
    }

    int next(int index, unsigned int i) const {
        assert(i < _inner_dims.size() - 1);
        if (index % _inner_dims[i + 1] / _inner_dims[i] == _inner_dims[i + 1] / _inner_dims[i] - 1)
            return -1;
        return index + _inner_dims[i];
    }

    int prev(int index, unsigned int i) const {
        assert(i < _inner_dims.size() - 1);
        if (index % _inner_dims[i + 1] / _inner_dims[i] == 0) return -1;
        return index - _inner_dims[i];
    }

    int size() const { return _inner_dims.back(); }
};

} // namespace kk2

#endif // KK2_MATH_FLATTEN_INDICES_HPP
