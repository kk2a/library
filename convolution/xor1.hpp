#ifndef CONVOLUTION_XOR
#define CONVOLUTION_XOR 1

template <class mint, class FPS>
FPS convolution_xor(FPS& a, FPS b) {
    int n = int(size(a));  // == int(size(b)
    if (!n) return {};
    int log = 0;
    while (1ull << log < n) log++;
    n = 1 << log;
    a.resize(n, 0), b.resize(n, 0);

    auto fwht = [&](FPS& a) -> void {
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j++) {
                if ((i & j) != 0) {
                    mint x = a[j], y = a[i ^ j];
                    a[j] = -x + y, a[i ^ j] = x + y;
                }
            }
        }
    };
    auto ifwht = [&](FPS& a) -> void {
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j++) {
                if ((i & j) != 0) {
                    mint x = a[j], y = a[i ^ j];
                    a[j] = (-x + y) / 2, a[i ^ j] = (x + y) / 2;
                }
            }
        }
    };

    fwht(a);
    fwht(b);
    for (int i = 0; i < n; i++) a[i] *= b[i]; 
    ifwht(a);

    return a;
}

#endif // CONVOLUTION_XOR
