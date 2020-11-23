#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

string format_duration(int seconds) {
    if(seconds <= 0) return "now";
    constexpr int second_in_year = 365 * 24 * 60 * 60;
    constexpr int second_in_day = 24 * 60 * 60;
    constexpr int second_in_hour = 60 * 60;
    constexpr int second_in_minute = 60;
    vector<string> numbers{};

    int years = floor(seconds / second_in_year);
    int y_remain = seconds % second_in_year;
    if(years > 0)   numbers.push_back((to_string(years) + " year")      + (years == 1 ? "": "s"));

    int days = floor(y_remain / second_in_day);
    int d_remain = y_remain % second_in_day;
    if(days > 0)    numbers.push_back((to_string(days) + " day")        + (days == 1 ? "": "s"));

    int hours = floor(d_remain / second_in_hour);
    int h_remain = d_remain % second_in_hour;
    if(hours > 0)   numbers.push_back((to_string(hours) + " hour")      + (hours == 1 ? "": "s"));

    int minutes = floor(h_remain / second_in_minute);
    int m_remain = h_remain % second_in_minute;
    if(minutes > 0) numbers.push_back((to_string(minutes) + " minute")  + (minutes == 1 ? "": "s"));

    int secs = m_remain;
    if(secs > 0)    numbers.push_back((to_string(secs) + " second")     + (secs == 1 ? "": "s"));

    string ret = "";
    int len = numbers.size();

    if(len == 1)
        ret = numbers[0];
    else{
        int i = 0;
        for(; i < len - 2; i++){
            ret += numbers[i] + ", ";
        }
        ret += numbers[i] + " and " + numbers[i+1];
    }
    return ret;
}

int main(){
    cout<<format_duration(3662);
    cout<<format_duration(62);
    cout<<format_duration(120);
    cout<<format_duration(1);
//cout<<years<<" years, "<<days<<" days, "<<hours<<" hours, "<<minutes<<" minutes, "<<secs<<" seconds"<<endl;
    return 0;
}