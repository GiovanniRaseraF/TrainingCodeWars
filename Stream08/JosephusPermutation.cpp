#include <utility>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

vector<int> josephus_ric(vector<int>& items, int elem, int k, vector<int>& ret) {
	if (items.empty()) return ret;
	vector<int>::iterator a = std::find(items.begin(), items.end(), elem);
	int pos_k = std::distance(items.begin(), a);
	int next_k = items[(pos_k + k) % items.size()];

	items.erase(items.begin()+pos_k);
	ret.push_back(elem);
	return josephus_ric(items, next_k, k, ret);
}

vector<int> josephus(vector<int> items, int k) {
	vector<int> ret{};
	return josephus_ric(items, k, k, ret);
}

int main() {
	josephus({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 2);
}

