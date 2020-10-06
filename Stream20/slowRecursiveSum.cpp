#include <iostream>
using namespace std;
using ull = unsigned long long;
ull exp_sum_(int sum, int largestNumber) {
    if (sum == 0 && largestNumber == 0) return 1;
    if (largestNumber == 0)
        return 0;
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;

    return exp_sum_(sum, largestNumber - 1) + exp_sum_(sum - largestNumber, largestNumber);
}

ull exp_sum(int sum) {
    return exp_sum_(sum, sum);
}


int main() {
    cout << exp_sum(100);
    return 0;
}