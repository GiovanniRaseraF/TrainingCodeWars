
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;
int main() {
	int max = 400;
	ull a, b;

	cout << "{";
	while ((cin >> a >> b) && a <= 400) {
		cout << "\"" << b << "\",";
	}
	cout << "};";

	return 0;
}