#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> create_adix(string observed){
    //Tabella delle adiacenze
    const vector<vector<string>> alph{
        {"0", "8"},
        {"1", "2", "4"},
        {"1", "2", "3", "5"},
        {"2", "3", "6"},
        {"1", "4", "5", "7"},
        {"2", "4", "5", "6", "8"},
        {"3", "5", "6", "9"},
        {"4", "7", "8"},
        {"5", "7", "8", "9", "0"},
        {"6", "8", "9"},
    };
    int pos = observed[0] - (int)'0';

    return alph[pos];
}

vector<string> get_pins(string observed) {
    //Caso base
    if(observed.length() == 0) return {};
    if(observed.length() == 1) return create_adix(observed);

    string first = observed.substr(0,1);
    vector<string> adix = create_adix(first);
    vector<string> ret{};

    //Itero ogni permutazine della stringa
    for(string c : adix){
        //Chiamo la ricorsione
        vector<string> res_ric = get_pins(observed.substr(1));
        //Aggiugo ogni risultato
        for(string s_ric : res_ric){
            ret.push_back(c + s_ric);
        }
    }

    return ret;
}


int main(){
    std::cout<<"hello world!!";
    return 0;
}
