#include <string>
#include <vector>

std::vector<std::string> solution(const std::string &s)
{
    if(s.length() == 0) return {};
    int a = 0;
    std::vector<std::string> ret{};
    std::string add;
    for(char c : s){
        if(a % 2 == 1){
            add += c;
            ret.push_back(add);
            add = "";
        }else{
            add += c;
        }
        a++;
    }

    std::string& last = add;
    if(last.length() == 1) {
        last += "_";
        ret.push_back(last);
    }
    return ret; // Your code here
}