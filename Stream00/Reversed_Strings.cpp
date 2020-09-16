#include <string>
#include <algorithm>
using namespace std;

string reverseString(string str){
	string ret{};
	for (int i = str.length() - 1; i >= 0; i--) ret += str[i];
	return ret;
}

string reverseString_Twich(const std::string& str) {
	return std::string(str.rbegin(), str.rend());
}

int main() {
	return 0;
}