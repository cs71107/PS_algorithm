#include <cstdio>
#include <complex>

/*by cubelover*/

using namespace std;

typedef long long ll;
const int SZ = 20, N = 1 << SZ;


int Rev(int x) {
    int i, r = 0;
    for (i = 0; i < SZ; i++) {
        r = r << 1 | x & 1;
        x >>= 1;
    }
    return r;
}

void FFT(ll *a, bool f) {
    int i, j, k;
    ll z;
    for (i = 0; i < N; i++) {
        j = Rev(i);
        if (i < j) {
            z = a[i];
            a[i] = a[j];
            a[j] = z;
        }
    }
    for (i = 1; i < N; i <<= 1) for (j = 0; j < N; j += i << 1) for (k = 0; k < i; k++) {
        z = a[i + j + k];
        a[i + j + k] = a[j + k] - z;
        a[j + k] += z;
    }
    if (f) for (i = 0; i < N; i++) a[i] /= N;
}

int X[N];
int Y[N];

int main() {
    int n;
    scanf("%d", &n);


    for (int i = 0; i < 1 << n; i++) scanf("%d", &X[i]);
    for (int i = 0; i < 1 << n; i++ )scanf("%d", &Y[i]);

    FFT(X, false);
    FFT(Y, false);

    for (int i = 0; i < N; i++) X[i] *= Y[i];

    FFT(X, true);

    for (int i = 0; i < 1 << n; i++) printf("%d ", X[i]);

    return 0;
}

