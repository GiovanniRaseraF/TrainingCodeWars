#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <sstream>
#include <limits>
using namespace std;

vector<int> countPositivesSumNegatives(vector<int> input){
	if (input.empty()) return vector<int>{};
	int count = 0, sum = 0;
	vector<int> ret{};
	for (int val : input) {
		if (val <= 0) sum += val;
		else count++;
	}
	ret.push_back(count);
	ret.push_back(sum);
	return ret;
}

int main() {
	
}