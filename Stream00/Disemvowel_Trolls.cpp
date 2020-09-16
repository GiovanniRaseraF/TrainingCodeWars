#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
/*
string voc = "AEIOUaeiou";

bool contains(string& s, char c) {
	for (char i : s) {
		if (i == c) return true;
	}
	return false;
}

string disemvowel(string str){
	string ret{};
	for (char c : str) {
		if (contains(voc, c)) ret += "";
		else ret += c;
	}
	return ret;
}
*/

#include <string>
#include <regex>
std::string disemvowel(std::string str){
	return std::regex_replace(str, std::regex("[aeiouAEIOU]"), "");
}

int main() {

	return 0;
}