#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <limits>
using namespace std;

#include <vector>

int positive_sum (const std::vector<int> arr){
    int ret = 0;
    for(int val : arr) if(val > 0) ret+=val;
    return ret;
}

int main(){

}