#ifndef TEMPLATE_SIMPLEIO_HPP
#define TEMPLATE_SIMPLEIO_HPP 1

#include <fstream>
#include <string>

#include "../type_traits/type_traits.hpp"

namespace kk2 {

struct SimplePrinter : type_traits::ostream_tag {
  private:
    std::ofstream out;

  public:
    SimplePrinter(const char *s) : out(s) {}

    template <class T> SimplePrinter &operator<<(const T &x) {
        out << x;
        return *this;
    }

    SimplePrinter &operator<<(std::ostream &(*f)(std::ostream &)) {
        out << f;
        return *this;
    }

    void flush() { out << std::flush; }
};

} // namespace kk2

#endif // TEMPLATE_SIMPLEIO_HPP
