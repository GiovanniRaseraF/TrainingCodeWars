#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string format_duration(int seconds) {
    if(seconds <= 0) return "now";
    constexpr int second_in_year = 365 * 24 * 60 * 60;
    constexpr int second_in_day = 24 * 60 * 60;
    constexpr int second_in_hour = 60 * 60;
    constexpr int second_in_minute = 60;

    int years = floor(seconds / second_in_year);
    int y_remain = seconds % second_in_year;

    int days = floor(y_remain / second_in_day);
    int d_remain = y_remain % second_in_day;

    int hours = floor(d_remain / second_in_hour);
    int h_remain = d_remain % second_in_hour;

    int minutes = floor(h_remain / second_in_minute);
    int m_remain = h_remain % second_in_minute;

    int secs = m_remain;

    string ret = "";
    
    cout<<years<<" years, "<<days<<" days, "<<hours<<" hours, "<<minutes<<" minutes, "<<secs<<" seconds"<<endl;
    return "";
}

int main(){
    format_duration(3662);
    format_duration(62);
    format_duration(120);
    format_duration(1);

    return 0;
}