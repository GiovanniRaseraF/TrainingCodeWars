#include <iostream>
#include <string>
using namespace std;
std::string testit(std::string s) {
	//if (s == "lcdhnrhzrsmpkvwppwk") return "gfpqrnpssk";
	for (char c : s) {
		string b;
		for (int i = 0; i < 8; i++) {
			b += to_string(int((c & (1 << i)) >> i));
		}
		cout << b << " ";
	}
	return "";
}
/*
aa -> a								(
ab -> a
bc -> b
aaaa -> aa
aaaaaa -> aa
lcdhnrhzrsmpkvwppwk -> gfpqrnpssk
fuyypaepniaaajycam -> myhjkaeng
*/

int main() {
	testit("lcdhnrhzrsmpkvwppwk");
	cout << endl;
	cout << char('a' ^ 'b') << endl;
	cout << string("lcdhnrhzrsmpkvwppwk").length()
		<< " " << string("gfpqrnpssk").length() << endl;
	return 0;
}