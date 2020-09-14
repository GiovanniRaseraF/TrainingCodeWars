#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

string reverse_words_versione_senza_spazi(string str){
	istringstream s{ str };
	string word{}, ret{};
	while (!s.eof()) {
		s >> word;
		string rev{};
		for (int i = word.size() - 1; i >= 0; rev += word[i], i--);
		ret += rev + " ";
	}
	return ret.substr(0, ret.length()-1);
}

string reverse_wordas(string str){
	string ret{};
	int len = str.size(), i = 0, prev = 0;
	while (i < len) {
		
		while (str[i] != ' ' && i < len) i++;
		string word = str.substr(prev, (i-prev)), rev{};
		//cout << word << " --- " << rev << " ---- " << ret << endl;
		for (int j = word.size() - 1; j >= 0; rev += word[j], j--);
		ret += rev;
		//cout << word << " --- " << rev << " ---- " << ret << endl;
		while (str[i] == ' ' && i < len) {
			ret += ' ';
			i++;
		}
		prev = i;
	}
	return ret;
}

std::string reverse_words(std::string str) {
	auto b = str.begin();
	auto e = str.end();

	while (b < e) {
		auto k = std::find(b, e, ' ');
		std::reverse(b, k);
		b = k + 1;
	}
	return str;
}

int main() {
	cout << reverse_words("Hello come stai");
	//cout << reverse_words("Hello come stai");
	return 0;
}