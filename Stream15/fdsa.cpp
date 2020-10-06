
using namespace std;

using ull = unsigned long long;

ull pk(ull n, ull k){
    if(n == 0 && k == 0) return 1;
    if((n <= 0 || k <= 0) && ((n == 0 && k != 0) || (n != 0 && k == 0) || (n != 0 && k  != 0))) return 0;
    return pk(n-k, k) + pk(n-(k-1), k-1);
}

ull exp_sum(ull n){
    ull sum = 0;
    for(ull k = 1; k <= n; k++){
        sum += pk(n, k);
    }
    return sum;
}