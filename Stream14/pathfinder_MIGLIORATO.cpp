#include <vector>
#include <numeric>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

bool path_finder(string m) {
	//Dati fondamentali
	int len = 0;
	while (m[len] != '\n') len++;
	int V = len * len;

	//Vettore delle distanze
	int* D = new int[V] {INT_MAX};
	int* color = new int[V] {0};
	queue<int> Q{};
	//Posizioni
	auto top = [&len](int pos) { return pos - (len + 1); };
	auto bot = [&len](int pos) { return pos + (len + 1); };
	auto rig = [](int pos) { return pos + 1; };
	auto lef = [](int pos) { return pos - 1; };
	D[0] = 0;
	color[0] = 1;
	Q.push(0);

	//BFS
	while (!Q.empty()) {
		int u = Q.front();
		vector<int> adix{};
		if (top(u) >= 0 && m[top(u)] == '.') adix.push_back(top(u));
		if (bot(u) < V+len && m[bot(u)] == '.') adix.push_back(bot(u));
		if (lef(u) >= 0 && m[lef(u)] == '.') adix.push_back(lef(u));
		if (rig(u) < V+len && m[rig(u)] == '.') adix.push_back(rig(u));

		for (int v : adix) {
			if (color[v] == 0) {
				color[v] = 1;
				D[v] = D[u] + 1;
				Q.push(v);
			}
		}

		Q.pop();
		color[u] = 2;
	}

	int last = D[V + len - 1];
	//Controllo se è raggiungibile
	return !(last == INT_MAX);
}

int main() {

	path_finder("......\n......\n......\n......\n.....W\n....W.");
	return 0;
}

