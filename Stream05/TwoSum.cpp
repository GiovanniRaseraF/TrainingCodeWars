#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;


/// <summary>
/// Il costo della funzione è dato dalla funzione di ordinamento perche il resto costa
/// O(n) siccome i tre while posso finire prima
///	Ha anche il problema di occupare memoria TETA(n) per il vettore di copia
/// </summary>
/// <returns></returns>
pair<std::size_t, std::size_t> two_sum(const vector<int>& numbers, int target) {
	//NON è detto che il vettore sia ordinato
	vector<int> copy{numbers};
	//cout << copy.size() << endl;
	std::sort(copy.begin(), copy.end());
	int i = 0, j = copy.size() - 1, sum = (copy[i] + copy[j]);

	//Errore di memoria sicuramente siccome non sono ORDINATI
	while (target != sum && i < copy.size() && j >= 0) {
		if (sum > target) j--;
		if (sum < target) i++;
		sum = (copy[i] + copy[j]);
	}
	//Cerco il calore anche se costa O(n)
	int pos_i = 0;
	int pos_j = 0;// std::find(numbers.begin(), numbers.end(), j)[0];
	while (pos_i < numbers.size() && (numbers[pos_i] != copy[i])) pos_i++;
	while (pos_j < numbers.size() && (numbers[pos_j] != copy[j] || pos_j == pos_i)) pos_j++;

	return {pos_i, pos_j};
}


/// <summary>
/// Bela soluzione ma ha una complessita troppo alta
/// La mia soluzione costa il prezzo dellordinamento
/// Questa nel caso peggiore O(n^2)
/// Per i due for
/// </summary>
/// <param name="numbers"></param>
/// <param name="target"></param>
/// <returns></returns>
std::pair<std::size_t, std::size_t> two_sumA(const std::vector<int>& numbers, int target) {
	for (auto i = 0; i < numbers.size(); i++)
		for (auto j = i + 1; j < numbers.size(); j++)
			if (numbers[i] + numbers[j] == target) return { i, j };
}

int main() {
	

	pair<std::size_t, std::size_t> val = two_sum({ 2, 2, 3 }, 4);
	cout << std::get<0>(val) << " " << std::get<1>(val) << endl;

	val = two_sum({ 1234, 5678, 9012 }, 14690);
	cout << std::get<0>(val) << " " << std::get<1>(val) << endl;

	val = two_sum({ 1, 2, 3 }, 4);
	cout << std::get<0>(val) << " " << std::get<1>(val) << endl;

	return 0;
}