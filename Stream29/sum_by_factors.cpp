#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

class SumOfDivided{
public:
    static void find_factors(int n, vector<int> &ret){
        int first = 2;
        while(first <= n){
            if(n % first == 0){
                ret.push_back(first);
                n = n / first;
            }
            first++;
        }
    }

    static std::string sumOfDivided(std::vector<int> &lst){
        set<int> primes{};
        for(int val : lst){
            vector<int> res{};
            find_factors(val, res);
            for(int p : res){
                primes.insert(p);
            }
        }



    }
};


int main(){
    return 0;
}