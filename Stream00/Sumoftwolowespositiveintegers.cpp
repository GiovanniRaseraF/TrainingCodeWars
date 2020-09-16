#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

long sumTwoSmallestNumbers(vector<int> numbers){
    long pos_first_min = 0;
    for(long i = 1; i < numbers.size(); i++)
        if(numbers[i] < numbers[pos_first_min]) pos_first_min = i;

    long pos_second_min = (pos_first_min + 1)%numbers.size();
    for(long i = 0; i < numbers.size(); i++)
        if(i != pos_first_min)
            if(numbers[i] < numbers[pos_second_min]) pos_second_min = i;
        
    cout<<numbers[pos_first_min]<<" " <<numbers[pos_second_min]<<endl;
    return numbers[pos_first_min] + numbers[pos_second_min];
}

int main(){
    vector<long> a{ 5, 8, 12, 19, 22 };
    cout<<sumTwoSmallestNumbers(a);
    return 0;
}