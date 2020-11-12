#include <string>
#include <iostream>
#include <numeric>

using namespace std;

int digital_root(int n){
    string sn = to_string(n);
    if(sn.length() == 1) return n;
    int sum;
    for(char c : sn)
        sum += c - (int)'0';
    return digital_root(sum);
}

//Idea intelligente con proprietà dei numeri
int digital_root_CodeWars(int Z) {
    return --Z % 9 + 1;
}

int main(){
    return 0;
}