#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <limits>
using namespace std;

class Accumul{
public:
    static string accum(const string &s){
        string ret{};
        int i = 1;
        for(char c : s){
            char val = std::tolower(c);
            ret+=std::toupper(val);
            for(int j = 1; j < i; j++) ret+=val;
            ret+="-";
            i++;      
        }
        return ret.substr(0, ret.length()-1);
    }
};

int main(){

    return 0;
}