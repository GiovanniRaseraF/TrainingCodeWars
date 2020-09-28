#include <utility>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <tuple>
#include <list>
#include <stack>
using namespace std;


//Rapresentazione della posizione
using pos = pair<int, int>;
//Rappresentazione deli nodi
using vnode = vector<pos>;

vnode findadix(pos node, string maze) {
	int x = node.first;
	int y = node.second;
	int len = 0;
	for (; maze[len] != '\n'; len++);
	int real_pos = len * y + x;
	//Caso in cui sono un muro e non ho altre cose
	if (maze[real_pos] == 'W') return {};
	//Caso in cui ho dei vicini da controllare
	auto p = [&len](int a, int b) {return len * b + a; };
	vnode ret{};

	//SOPRA SOTTO DESTRA SINISTRA
	if (y - 1 >= 0 && maze[p(x, y - 1)] == '.') ret.push_back({ x, y - 1});
	if (y + 1 >= 0 && maze[p(x, y + 1)] == '.') ret.push_back({ x, y + 1 });
	if (x - 1 >= 0 && maze[p(x - 1, y)] == '.') ret.push_back({ x - 1, y });
	if (x + 1 >= 0 && maze[p(x + 1, y)] == '.') ret.push_back({ x + 1, y });

	return ret;
}

bool path_finder(string maze) {
	// TODO: Determine whether one can reach the exit at (n - 1, n - 1)
	// starting from (0, 0) in a n × n maze (represented as a string)
	// and return a boolean value accordingly
	
	// Ho un grafo non orientato e devo trovare la strada per arrivare alla fine
	// Eseguo bfs e se dalla fine all'inizio non ci sono strade allora non 
	// ho strade possibili

	for (auto i : findadix({ 0,0 }, maze)) {
		cout << i.first << " " << i.second << endl;
	}
	cout << endl;
	for (auto i : findadix({ 2,4 }, maze)) {
		cout << i.first << " " << i.second << endl;
	}
	cout << endl;
	for (auto i : findadix({ 1,1 }, maze)) {
		cout << i.first << " " << i.second << endl;
	}
	cout << endl;
	for (auto i : findadix({ 2,1 }, maze)) {
		cout << i.first << " " << i.second << endl;
	}
	cout << endl;

	return false;
}

int main() {

	path_finder("......\n......\n......\n......\n.....W\n....W.");
	return 0;
}

