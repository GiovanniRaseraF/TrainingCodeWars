#include <utility>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <iostream>
#include <math.h>

using namespace std;
class SumSquaredDivisors{
public:
    static vector<long long> getDivisord(long long val){
        vector<long long> ret{};
        for(int i = 1; i <= val; i++) if(val % i == 0) ret.push_back(i);
        return ret;
    }


    static std::vector<std::pair<long long, long long>> 
                listSquared(long long m, long long n){
        //Controllo iniziale
        if(n < 1 || m < 1 || n < m) return {};
        std::vector<std::pair<long long, long long>> ret{};
        //Codice
        for(long long i = m; i <= n; i++){
            long long val = i;
            vector<long long> divisors = getDivisord(val);
            for(long long &v : divisors) v = v*v;
            long long somma = std::accumulate(divisors.begin(), divisors.end(), 0);
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
        SumSquaredDivisors::listSquared(42, 250);
        SumSquaredDivisors::listSquared(250, 500);
        SumSquaredDivisors::listSquared(300, 600);

        //dotest(1, 250, {{1, 1}, {42, 2500}, {246, 84100}});
        //dotest(42, 250, {{42, 2500}, {246, 84100}});
        //dotest(250, 500, {{287, 84100}});
        //dotest(300, 600, {});
    return 0;
}