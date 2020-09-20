#include <utility>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <iostream>
#include <math.h>

using namespace std;
template<class TYPE>
int getLengthOfMissingArray(std::vector<std::vector<TYPE>> arrayOfArrays){
    //Controllo
    if (arrayOfArrays.empty()) return 0;
    //Codice
    auto compare = [](std::vector<TYPE>& a, std::vector<TYPE>& b) {return a.size() < b.size(); };
    std::sort(arrayOfArrays.begin(), arrayOfArrays.end(), compare);

    //Attenzione che il testo diceva che l'array che manca era tra il primo e l'ultimo 
    //quindi no bisogna partire da zero
    int val = arrayOfArrays[0].size();
    for(auto i : arrayOfArrays) {
        if (i.empty()) return 0;
        if (i.size() != (long)val) return val;
        val++;
    }

    return 0;
}

int main() {
    std::vector<std::vector<int>> testInput = { { 1, 2 }, { 4, 5, 1, 1 }, { 1 }, { 5, 6, 7, 8, 9 } };
    cout << getLengthOfMissingArray(testInput);
    return 0;
}

