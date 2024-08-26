#ifndef CONVOLUTION_AND
#define CONVOLUTION_AND 1

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type>
FPS convolution_and(FPS& a, FPS b) {
    int n = int(size(a));  // == int(size(b)
    if (!n) return {};
    int log = 0;
    while (1ull << log < n) log++;
    n = 1 << log;
    a.resize(n, 0), b.resize(n, 0);

    auto fzt = [&](FPS& a) -> void {
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j++) {
                if ((i & j) == 0) a[j] += a[i ^ j];
            }
        }
    };
    auto ifzt = [&](FPS& a) -> void {
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j++) {
                if ((i & j) == 0) a[j] -= a[i ^ j];
            }
        }
    };

    fzt(a);
    fzt(b);
    for (int i = 0; i < n; i++) a[i] *= b[i]; 
    ifzt(a);

    return a;
}

} // namespace kk2

#endif // CONVOLUTION_AND
