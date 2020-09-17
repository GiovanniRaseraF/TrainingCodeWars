#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <sstream>
#include <limits>
using namespace std;

    int max(int a, int b) { 
        if (a > b) return a;
        else return b;
    }

    //Dovevo fare la differenza altrimenti va in overflow
    bool isTriangle(double a, double b, double c) {
        return (a < (b + c)) && (b < (a + c)) && (c < (b + a));
    }

    bool isTrianglea(int a, int b, int c)
    {
        return a - b < c&& b - c < a&& c - a < b;
    }

  

int main() {
    return 0;
}