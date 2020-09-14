#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <sstream>
#include <limits>
using namespace std;

string highAndLow(const std::string& numbers) {
	istringstream s{ numbers };
	int min = 0, max = 0;
	s >> min;
	max = min;

	while (!s.eof()) {
		int val = 0;
		s >> val;
		if (val < min) min = val;
		if (val > max) max = val;
	}

	return to_string(max) + " " + to_string(min);
}

std::string highAndLow_Preso(const std::string& numbers) {
	std::stringstream ss(numbers);
	int temp, min = std::numeric_limits<int>::max(), max = std::numeric_limits<int>::min();
	while (ss >> temp) {
		min = (temp < min) ? temp : min;
		max = (temp > max) ? temp : max;
	};
	return std::to_string(max) + " " + std::to_string(min);
}

int main() {

	return 0;
}