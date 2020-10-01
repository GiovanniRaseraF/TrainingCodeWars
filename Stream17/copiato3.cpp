// C++ program to generate the number of unique partitions of a number

#include <iostream>
#define mx 100000
#define f(i,a,b) for(i=a;i<b;i++)

using namespace std;
using ull = unsigned long long;
// dp array to store the partition values, also known as partition array
// c is the counting variable to count unique partitions
ull  dp[mx];

// Function to generate the unique partition array for positive integer n and print it
// rem_val is the remaining value still need to be formed
// max_val is the maximum number that can be used in the formation of rem_val
void find_unique_partitions(ull  idx, ull  rem_val, ull  max_val, ull & c)
{
    ull  i = 0;
    if (rem_val == 0) {
        c++;
    }
    else {
        for (i = max_val; i >= 1; i--)// since a partition value "i" cannot exceed max_val and cant be less than 1.
        {
            if (i > rem_val)
                continue;
            else {
                dp[idx] = i; // allocate i to the current index
                find_unique_partitions(idx + 1, rem_val - i, i, c); // now max_val is updated to be i
            }
        }
    }
    return;
}


ull exp_sum(int n) {
    if (n == 0)  return 1;
    cout << n << endl;
    ull c = 0;
    find_unique_partitions(1, n, n, c);
    return c;
}



