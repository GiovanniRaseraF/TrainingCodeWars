#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class DoubleLinear{
    public:
        static int dblLinear(int n){
            vector<int> u{};
            u.push_back(1);
            int ret = 0;
            int i = 0;
            while(true){
                int val = u[i];
                u.push_back(2 * val + 1);
                u.push_back(3 * val + 1);
                if(u.size() >= n * 2) break;
                i++;
            }

            std::sort(u.begin(), u.end());
            int val = -1, pos = -1, changed = -1;
            for(auto a : u){
                if(changed == n) return val;
                if(a != val){
                    val = a;
                    changed++;
                }
            }

           return 0;
        }
};

int main(){
    int val = 0;
    cin>>val;
    cout<<DoubleLinear::dblLinear(val);
    return 0;
}