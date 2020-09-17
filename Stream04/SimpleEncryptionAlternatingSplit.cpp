#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

string encrypt(std::string text, int n){
    if (n <= 0 || text == "") return text;

    string s1{}, s2{};
    int i = 0;
    std::copy_if(text.begin(), text.end(), std::back_inserter(s1), [&i](char c) {i++; return (i - 1) % 2 == 0;});
    i = 0;
    std::copy_if(text.begin(), text.end(), std::back_inserter(s2), [&i](char c) {i++; return (i - 1) % 2 == 1; });

    return encrypt(s2 + s1, n-1);
}

string decrypt(std::string text, int n){
    if (n <= 0 || text == "") return text;
    
    string s1{}, s2{}, ret{};
    int middle = floor(text.length() / 2);
    s1 = text.substr(0, middle+1);
    s2 = text.substr(middle, middle+1);
    //Loop per mettere apposto la stringa
    for (int i = 0, i1 = 0, i2 = 0; i < text.length(); i++) {
        if (i % 2 == 0) {
            ret += s2[i2];
            i2++;
        }
        else {
            ret += s1[i1];
            i1++;
        }
    }

    return decrypt(ret, n-1);
}

int main() {
    cout<<decrypt(encrypt(string{ "This is a test!" }, 2), 2);

    return 0;
}