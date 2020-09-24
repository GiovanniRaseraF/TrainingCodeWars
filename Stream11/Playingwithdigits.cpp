#include <utility>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

using ll = long long;

class DigPow{
public:
	static int digPow(int number, int power) {
		//Trasformo il numero in stringa per andare meglio
		string str_number = to_string(number);
		//Calcolo n * k
		//int number_k = 0, k = 0;
		for (char n : str_number) {
			number_k += pow((int)n - (int)'0', power);
			power++;
		}

		//Calcolo k
		int mk = floor((double)number_k / (double)number);
		k = (mk * number == number_k)? mk : -1;

		return k;
	}
};


int main() {
	cout << DigPow::digPow(46288, 3);
	return 0;
}