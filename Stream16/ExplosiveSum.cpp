
#include <iostream>
using namespace std;

using ull = unsigned long long;

ull pk(ull n, ull k) {
    if (n == 0 && k == 0) return 1;
    if ((n <= 0 || k <= 0) && ((n == 0 && k != 0) || (n != 0 && k == 0) || (n != 0 && k != 0))) return 0;
    return pk(n - k, k) + pk(n - 1, k - 1);
}

ull exp_sum(ull n) {
    ull sum = 0;
    for (ull k = 1; k <= n; k++) {
        sum += pk(n, k);
    }
    return sum;
}

int main() {
    for (int i = 0; i < 11; i++) {
        cout << exp_sum(i) << endl;
    }
    return 0;
}