#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

class SumOfDivided{
public:
    static void find_factors(int n, vector<int> &ret){
        n = abs(n);
        int first = 2;
        while(first <= n){
            if(n % first == 0){
                ret.push_back(first);
                while(n % first == 0) 
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

        string ret = "";
        for(int p : primes){
            int sum = 0;
            for(int val : lst){
                if(abs(val) % p == 0){
                    sum += val;
                }
            }
            ret += "(" + to_string(p) + " " + to_string(sum) + ")";
        }

        return ret;
    }
};


int main(){
    vector<int> a{15, 30, -45};
    string s = SumOfDivided::sumOfDivided(a);
    cout<<s;
    return 0;
}