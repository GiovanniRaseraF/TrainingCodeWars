
#include <iostream>
using namespace std;

using ull = unsigned long long;

ull pk(ull n, ull k) {
    // Base cases
    if (n == 0 || k == 0 || k > n)
        return 0;
    if (k == 1 || k == n)
        return 1;

    // S(n+1, k) = k*S(n, k) + S(n, k-1)
    return  k * pk(n - 1, k) + pk(n - 1, k - 1);
}

ull exp_sum(ull n) {
    ull sum = 0;
    int volte = 0;
    for (ull k = 1; k <= n; k++) {
        sum += pk(n, k);
    }

    cout << sum <<" "<< volte << endl;

    return sum;
}

int main() {
    for (int i = 0; i < 11; i++) {
        cout << exp_sum(i) << endl;
    }
    return 0;
}