#include <utility>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


vector<int> j_alter(vector<int>& items, int k, int increment, vector<int>& ret) {
	//Caso base
	if (items.empty()) return ret;

	//Trovo l'elemeto da eliminare alla D esima chiamata ricorsiva
	int len = items.size();
	int pos_to_delete = ((k-1) % len);

	int elem_deleted = items[pos_to_delete];
	ret.push_back(elem_deleted);
	items.erase(items.begin()+pos_to_delete);

	return j_alter(items, pos_to_delete+increment, increment, ret);
}


vector<int> josephus(vector<int> items, int k) {
	vector<int> ret{};
	return j_alter(items, k, k, ret);
}

int main() {
	cout << "Finale: ";
	for (auto i : josephus({ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 }, 59)) {
		cout<<i<<" ";
	}
	cout<<endl;
}


