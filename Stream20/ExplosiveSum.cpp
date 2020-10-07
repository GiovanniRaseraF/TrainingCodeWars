
#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

using ull = unsigned long long;
ull calcolato = 0;
ull non_calcolato = 0;

//Per aumentare le prestazioni bisogna utilizzare memoization
ull exp_sum(int sum, int largestNumber, ull**& dict) {
    //Caso base
    assert(largestNumber >= 0);
    if (sum < 0) return 0;
    if (dict[sum][largestNumber] != 0) {
        calcolato++;
        return dict[sum][largestNumber];
    }

    non_calcolato++;
    if (sum == 0 && largestNumber == 0) {
        dict[sum][largestNumber] = 1;
        return 1;
    }
    if (largestNumber == 0) {
        dict[sum][largestNumber] = 0;
        return 0;
    }
    if (sum == 0) {
        dict[sum][largestNumber] = 1;
        return 1;
    }
    dict[sum][largestNumber] = exp_sum(sum, largestNumber - 1, dict) + exp_sum(sum - largestNumber, largestNumber, dict);
    return dict[sum][largestNumber];
}

ull exp_sum(int sum) {
    //Memoization
    
    ull** dict = new ull* [sum+1];
    
    for (int i = 0; i <= sum; i++) {
        dict[i] = new ull[sum + 1];
        for (int j = 0; j <= sum ; j++) dict[i][j] = 0;
    }
    dict[0][0] = 1;

    ull val = exp_sum(sum, sum, dict);

    //Devo eliminare tutto
    for (int i = 0; i <= sum; i++) {
        delete dict[i];
    }
    //
    return val;
}


ull exp_sum_CodeWars(unsigned int n)
{
    std::vector<ull> c(n + 1, 0); // array of coefficients of X^0 ... X^n
    c[0] = 1;  // start with 1X^0
    for (unsigned int k = 1; k <= n; ++k) // multiply by 1/(1-X^k)
        for (unsigned int i = 0; (i + k) <= n; ++i)
            c[i + k] += c[i];
    return c[n];
}

int main() {
    for (int i = 100; i < 101; i++) {
        std::cout << exp_sum(i) << endl;
    }

    //cout << calcolato << "   " << non_calcolato<<endl;
    return 0;
}