#include <iostream>
#include <math.h>
#include <vector>
#include <deque>
#include <numeric>
#include <algorithm>
using namespace std;
using ll = long long;
class Decomp{
    public:
    static std::vector<ll> decompose(ll n){
        ll nn = n*n;
        deque<ll> work{};
        work.push_back(n-1);
        while(true){
            ll first = work.back();
            if(first == 0) work.pop_back();
            //Non ho una rappresentazione
            if(work.empty()) return {};
            //Vuol dire che ho da togliere
            if(first == 0 && !work.empty()){
                ll back = work.back();
                work.pop_back();
                work.push_back(back-1);
            }
            //Ho trovaro la somma giusta
            ll sum = 0;
            ll next = 0;
            for(int i = 0; i < work.size(); i++) sum += (work[i] * work[i]);
            if(sum == nn) break;
            else if(sum < nn){
                next = (ll) floor(sqrt(nn - sum));
                if(next == work.back()){
                    work.pop_back();
                    work.push_back(0);
                }else if(next > work.back()){
                    ll back = work.back();
                    work.pop_back();
                    work.push_back(back-1);
                }
                else
                    work.push_back(next);
            }
            else 
                return {};
        }
        vector<ll> ret{};
        for(int i = work.size() - 1; i >= 0; i--){
            ret.push_back(work[i]);
        }
        return ret;
    }
};

int main(){
    for(ll i : Decomp::decompose(50)){
        cout<<" "<<i;
    }
    return 0;
}