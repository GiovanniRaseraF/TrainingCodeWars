#include <utility>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int getPosFromCircularVect(vector<int>& vec, int start_pos, int pos)
{
	int final_pos = (start_pos + pos) % vec.size();
	return final_pos;
}

void jos_mio(vector<int>& items, int k, int start_pos, vector<int>& ret)
{
	if (items.empty()) return;

	if (items.size() == 1)
	{
		ret.push_back(items.at(0));
		return;
	}

	int to_delete_pos = getPosFromCircularVect(items, start_pos, k);
	ret.push_back(items.at(to_delete_pos));
	items.erase(items.begin() + to_delete_pos);

	to_delete_pos = (to_delete_pos - 1 >= 0) ? to_delete_pos - 1 : items.size() - 1;
	
	jos_mio(items, k, to_delete_pos, ret);
}

vector<int> josephus(vector<int>& items, int k) {
	vector<int> ret{};
	jos_mio(items, k, -1, ret);
	return ret;
}

int main()
{
	vector<int> vec = { 1, 2, 3, 4, 5, 6, 7 };

	cout << "Finale: " << std::endl;
	vector<int> final = josephus(vec, 3);

	for (auto i : final) {
		cout << i << " ";
	}
	cout << endl;
}
