#include <string>
#include <vector>
#include <iostream>
using namespace std;
std::string range_extraction(std::vector<int> args) {
    string ret = "";
    //i all'interno del ciclo deve per forza cambiare
    int j = 0;
    for(int i = 0; i < args.size(); i++){
        int prec = args[i];
        //Vado alla ricerca di un range
        for(j = i+1; prec+1 == args[j]   && j < args.size(); ++j){
            prec = args[j];
        };

        //Forse ho trovato un range
        if(j - 1 - i >= 2)  {
            ret+= to_string(args[i]) + "-" + to_string(args[j-1]) + ",";
            i = j-1;
        }
        else                ret+= to_string(args[i]) + ",";
    }

    return ret.substr(0, ret.length()-1);
}

int main(){
    cout<<range_extraction({-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20})<<endl;
    cout<<range_extraction({-3,-2,-1,2,10,15,16,18,19,20})<<endl;
    return 0;
}