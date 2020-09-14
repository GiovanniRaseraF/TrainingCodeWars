#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

map<char, int> symb{
	{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}
};


int solution(string s) {
	int len = s.length();
	vector<int> val{};
	int prev = 0;
	int sum = 0;
	int iter = 0;
	while(iter < len) {
		while (s[iter] == s[prev] && iter < len) iter++;
		val.push_back(symb[s[prev]] * (iter-prev));
		prev = iter;
	}

	//Caso in cui ho solo un valore
	if (val.size() == 1) return val[0];

	int init = 0;
	if (val.size() % 2 == 1) {
		init = val[0];
		sum = 0;
		for (int i = val.size()-1; i > 1; i -= 2) {
			if (val[i - 1] < val[i]) {
				sum = val[i] - val[i - 1];
			}
			else {
				sum = val[i] + val[i - 1];
			}
			init += sum;
		}
		return init;
	}
	else {
		sum = 0;
		for (int i = val.size()-1; i > 0; i -= 2) {
			if (val[i - 1] < val[i]) {
				sum = val[i] - val[i - 1];
			}
			else {
				sum = val[i] + val[i - 1];
			}
			init += sum;
		}
		return init;
	}
	return 0;
}




int mainn() {
	cout<<solution("DCCLXXXIX")<<endl;
	cout << solution("LXXXVIII") << endl;
	cout << solution("LXXXIII") << endl;
	cout << solution("VIII") << endl;
	cout << solution("C") << endl;
	cout << solution("XVIII") << endl;
	return 0;
}
