#include <utility>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <iostream>
#include <math.h>

using namespace std;
using ll = long long;
using pll = std::pair<ll, ll>;
using vpll = std::vector<pll>;

class SumSquaredDivisors{
public:
    //Molto molto lenta come ricerca
    static vector<ll> getDivisord(ll val){
        vector<ll> ret{};
        for(int i = 1; i <= val; i++) if(val % i == 0) ret.push_back(i);
        return ret;
    }

    //Dipende dal numero di divisiori che hanno i numeri
    static vpll listSquared(ll m, ll n){
        //Controllo iniziale
        if(n < 1 || m < 1 || n < m) return {};
        vpll ret{};
        //Codice
        for(ll i = m; i <= n; i++){
            ll val = i;
            vector<ll> divisors = getDivisord(val);
            for(ll &v : divisors) v = v*v;
            ll somma = std::accumulate(divisors.begin(), divisors.end(), 0);
            double radice = floor(sqrt(somma));
            if(radice*radice == somma) ret.push_back({val, somma});
        }

        return ret;

    }
};

     
  
int main(){
    
        for(auto i : SumSquaredDivisors::listSquared(1, 250)){
            cout<<std::get<0>(i)<<" "<<std::get<1>(i)<<endl;
        }

        for(auto i : SumSquaredDivisors::listSquared(42, 250)){
            cout<<std::get<0>(i)<<" "<<std::get<1>(i)<<endl;
        }
        for(auto i : SumSquaredDivisors::listSquared(250, 500)){
            cout<<std::get<0>(i)<<" "<<std::get<1>(i)<<endl;
        }
        for(auto i : SumSquaredDivisors::listSquared(300, 600)){
            cout<<std::get<0>(i)<<" "<<std::get<1>(i)<<endl;
        }
        //SumSquaredDivisors::listSquared(42, 250);
        //SumSquaredDivisors::listSquared(250, 500);
        //SumSquaredDivisors::listSquared(300, 600);

        //dotest(1, 250, {{1, 1}, {42, 2500}, {246, 84100}});
        //dotest(42, 250, {{42, 2500}, {246, 84100}});
        //dotest(250, 500, {{287, 84100}});
        //dotest(300, 600, {});
    return 0;
}