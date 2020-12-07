#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string find_screen_height(int wi, const string &r){

    stringstream s{r};
    int w, h; char c;
    s >> w >> c >> h;
    return to_string(wi) + "x" + to_string((int)((float)wi / (float)w * h));
}

