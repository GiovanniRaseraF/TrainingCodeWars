#include <iostream>
#include <string>
using namespace std;
using ll = unsigned long long;
unsigned int coutBits(ll n){
    unsigned int sum = 0;
    for(int i = 0; i < 64; i++){
        sum += (n & (ll(1) << i)) >> i;

        cout<<sum<<"\n";
    }
    return sum;
}

int main(){
    cout<<coutBits(0);
    return 0;
}