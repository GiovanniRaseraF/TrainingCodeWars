#include <utility>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <iostream>
#include <math.h>
#include <stdio.h> 
#include <string.h> 
#include <sstream>

using namespace std;

class Opstrings
{
public:
    

    static std::string vertMirror(const std::string &strng) {
        string ret{};
        istringstream input{strng};
        string s{};
        while (input >> s) {
            std::reverse(s.begin(), s.end());
            ret += s + "\n";
        }

        string r{};
        for (int i = 0; i < ret.length() - 1; i++) r += ret[i];
        return r;
    }

    static std::string horMirror(const std::string& strng) {
        vector<string> ret{};
        istringstream input{ strng };
        string s{};
        
        while (input >> s) {
            ret.push_back(s);
        }

        string fin{};
        std::reverse(ret.begin(), ret.end());
        for (auto i : ret) fin += i + "\n";

        string r{};
        for (int i = 0; i < fin.length() - 1; i++) r += fin[i];
        return r;
    }
    // your high order function oper
    //... oper(...);
    template<typename Func>
    static std::string oper(Func function, const std::string& s) {
        return function(s);
    }

};

int main() {
    cout<<Opstrings::oper(Opstrings::vertMirror, "abcd\nefgh\nijkl\nmnop");
    return 0;
}
