#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class DoubleLinear{
    public:
        static int dblLinear(int n){
            set<int> u{};
            u.insert(1);
            int ret = 0;
            for(auto i : u){
                u.insert(2 * i + 1);
                u.insert(3 * i + 1);

                if(u.size() >= n + 1) break;
            }

            int a = 0;
            for(auto i : u){
                if(a == n){
                    ret = i;
                    break;
                }
                a++;
            }
            return ret;
        }
};

int main(){
    int val = 0;
    cin>>val;
    cout<<DoubleLinear::dblLinear(val);
    return 0;
}