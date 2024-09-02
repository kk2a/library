#ifndef CONVOLUTION_XOR
#define CONVOLUTION_XOR 1

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type>
FPS convolution_xor(FPS& a, const FPS& b) {
    int n = int(size(a));  // == int(size(b)
    if (!n) return {};
    assert((n & -n) == n);
    FPS c(b);

    auto fwht = [&](FPS& a) -> void {
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j++) {
                if ((i & j) != 0) {
                    auto x = a[j], y = a[i ^ j];
                    a[j] = -x + y, a[i ^ j] = x + y;
                }
            }
        }
    };
    auto ifwht = [&](FPS& a) -> void {
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j++) {
                if ((i & j) != 0) {
                    auto x = a[j], y = a[i ^ j];
                    a[j] = (-x + y) / 2, a[i ^ j] = (x + y) / 2;
                }
            }
        }
    };

    fwht(a);
    fwht(c);
    for (int i = 0; i < n; i++) a[i] *= c[i]; 
    ifwht(a);

    return a;
}

} // namespace kk2

#endif // CONVOLUTION_XOR
