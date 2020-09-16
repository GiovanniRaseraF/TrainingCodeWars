#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <limits>
using namespace std;

#include <string>

bool isAnagram(std::string test, std::string original){
    std::for_each(begin(test), end(test), [](char &val){val = std::tolower(val);});
    std::for_each(begin(original), end(original), [](char &val){val = std::tolower(val);});
    
    std::sort(begin(test), end(test));
    std::sort(begin(original), end(original));
    
    return original == test;
}

int main(){
    cout<<isAnagram(string{"CiOa"},string{"cAsiO"});
}