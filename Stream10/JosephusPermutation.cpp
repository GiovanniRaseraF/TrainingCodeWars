#include <utility>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

vector<int> josephus_ric(vector<int> items, int elem, int increment,vector<int> &ret) {
	//Caso base
	if (items.size() < increment) {
		for (auto i : items) ret.push_back(i);
		return ret;
	}
	
	//Valcolo dove si trova l'elemento da eliminare
	int len_items = items.size();
	vector<int>::iterator iterator_elem_to_delete = std::find(items.begin(), items.end(), elem);
	int pos_to_delete = std::distance(items.begin(), iterator_elem_to_delete);
	int pos_next_elem = (pos_to_delete + increment) % len_items;
	int next_elem = items[pos_next_elem];
	
	cout << "pos_to_delete: " << pos_to_delete << " pos_next_item: " << pos_next_elem << endl;
	for (auto i : items) cout << i << " ";
	cout << endl;
	
	//Eliminazione dell'elemento e inserimento nella lista di ritorno
	items.erase(items.begin()+pos_to_delete);
	ret.push_back(elem);

	//Chiamata ricorsiva
	return josephus_ric(items, next_elem, increment, ret);
}

vector<int> josephus(vector<int> items, int k) {
	vector<int> ret{};
	return josephus_ric(items, k, k, ret);
}

int main() {
	cout << "Finale: ";
	for (auto i : josephus({ 1, 2, 3, 4, 5, 6, 7 }, 3)) {
		cout<<i<<" ";
	}
	cout<<endl;
}

