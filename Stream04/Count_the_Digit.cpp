#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <limits>
using namespace std;

class CountDig
{
public:
	static int contains(int val, int d) {
		char c = to_string(d)[0];
		string s = to_string(val);
		int count = 0;
		for (char v : s) if (v == c) count++;
		return count;
	}

	static int nbDig(int n, int d) {
		//Pre condizioni
		if (n < 0 || d < 0 || d > 9) return -1;

		//Codice
		int count = 0;		
		for (int k = 0; k <= n; k++)
			count +=contains(k * k, d);
		
		return count;
	}

	static int nbDiga(int n, int d) {
		int count = 0;
		for (int k = 0; k <= n; ++k) {
			int m = k * k;
			do {
				if ((m % 10) == d) count += 1;
				m /= 10;
			} while (m);
		}
		return count;
	}
};


int main() {

	cout<<CountDig::nbDig(12224, 8);

	return 0;
}