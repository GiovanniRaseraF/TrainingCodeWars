#include <iostream>
#include <math.h>
#include <vector>
#include <deque>
#include <numeric>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
class DirReduction{
public:
//{ "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" };
    static int s_to_i(std::string& str){
        if(str == "NORTH") return 1;
        if(str == "SOUTH") return -1;
        if(str == "EAST") return 2;
        if(str == "WEST") return -2;
        return 44;
    }
    static std::vector<std::string> dirReduc(std::vector<std::string> arr){
        for(unsigned long i = 0; i < arr.size() - 1; i++){
            int v1 = s_to_i(arr[i]);
            int v2 = s_to_i(arr[i+1]);
            if(v1 + v2 == 0){
                vector<string> new_arr{};
                for(unsigned long j = 0; j < arr.size(); j++) 
                    if(j != i && j != i+1) new_arr.push_back(arr[j]);

                return dirReduc(new_arr);

            }
        }

        return arr;
    }
};

int main(){
    DirReduction::dirReduc({ "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" , "SOUTH", "EAST", "SOUTH", "EAST", "SOUTH", "EAST", "SOUTH", "EAST", "SOUTH", "EAST","NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" , "SOUTH", "EAST", "SOUTH", "EAST", "SOUTH", "EAST", "SOUTH", "EAST", "SOUTH", "EAST","NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" , "SOUTH", "EAST", "SOUTH", "EAST", "SOUTH", "EAST", "SOUTH", "EAST", "SOUTH", "EAST" ,"WEST", "NORTH", "WEST" });
    return 0;
}