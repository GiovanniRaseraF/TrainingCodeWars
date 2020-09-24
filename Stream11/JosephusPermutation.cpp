#include <utility>
#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> j_alter(vector<int>& items, int k, int increment, vector<int>& ret) {
	//Caso base
	if (items.empty()) return ret;

	//Trovo l'elemeto da eliminare alla D esima chiamata ricorsiva
	int len = items.size();
	int pos_to_delete = ((k-1) % len);

	//Elimino l'elemento dal vettore items e lo aggiungo al vettore di ritorno
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

	cout<<endl;
}


