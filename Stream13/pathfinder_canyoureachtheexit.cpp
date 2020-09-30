#include <utility>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <iostream>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <tuple>
#include <list>
#include <stack>
#include <queue>
#include <climits>
using namespace std;


//Rapresentazione della posizione
using pos = pair<int, int>;
//Rappresentazione deli nodi
using vnode = vector<pos>;
enum Color {
	BIANCO, BLU, VUOLA
};

vnode findadix(pos node, vector<string> maze) {
	int x = node.first;
	int y = node.second;
	int len = maze.size();
	//caso in cui sono un muro e non ho altre cose
	if (maze[y][x] == 'w') return {};
	//caso in cui ho dei vicini da controllare
	vnode ret{};
	//sopra sotto destra sinistra
	if (y - 1 >= 0 && maze[y - 1][x] == '.') ret.push_back({ x, y - 1});
	if (y + 1 < len && maze[y + 1][x] == '.') ret.push_back({ x, y + 1 });
	if (x - 1 >= 0 && maze[y][x - 1] == '.') ret.push_back({ x - 1, y });
	if (x + 1 < len && maze[y][x + 1] == '.') ret.push_back({ x + 1, y });

	return ret;
}

bool path_finder(string m) {
	// Ho un grafo non orientato e devo trovare la strada per arrivare alla fine
	// Eseguo bfs e se dalla fine  non ci sono strade allora non 
	// ho strade possibili

	//Parsing della stringa
	vector<string> maze{};
	istringstream ss{m};
	string s;
	while (ss >> s) maze.push_back(s);
	int len = maze.size();
	int V = maze.size() * maze.size();
	//Fine parsing


	auto comp_pos = [](pos& p1, pos& p2) {return p1.first == p2.first && p1.second == p2.second; };
	auto find = [&comp_pos](pos& node, vnode& nodes) {
		int i = 0;
		for (auto a : nodes) {
			if (comp_pos(a, node)) return i;
			i++;
		}
		return -1;
	};
	//Inizializzo le strutture che mi servono per eseguire BFS
	Color* color = new Color[V];
	int* PGR = new int[V];			//NON CI SERVE
	int* D = new int[V];
	queue<pos> Q{};

	//Inizializzazioni delle strutture
	vnode nodes{};
	for (int y = 0; y < maze.size(); y++) {
		for (int x = 0; x < maze.size(); x++) {
			nodes.push_back({x, y});
		}
	}
	for (int i = 1; i < V; i++) {
		color[i] = Color::BIANCO;
		PGR[i] = -1;
		D[i] = INT_MAX;
	}
	color[0] = Color::GRIGIO;
	PGR[0] = -1;
	D[0] = 0;
	Q.push(nodes[0]);

	//Abbiamo a disposizione
	/*
	un vettore che ci dice se abbiamo gia calpestato una cella --> COLOR
	un vettore che ci dice a quanta distanza è una certa cella --> D  (distance)

	Abbiamo una CODA (queue) che ci permette di salvarci i nodi che dobbiamo calpestare e che abbiamo visto

	*/

	while (!Q.empty()) {
		//Estraggo l'elemento da analizzare
		pos u = Q.front();
		vnode adix = findadix(u, maze);
		int pos_u = find(u, nodes);
		//Controllo i nodi adiacenti
		for (int pos_i = 0; pos_i < adix.size(); pos_i++) {
			pos v = adix[pos_i];
			int pos_v = find(v, nodes);
			if (color[pos_v] == Color::BIANCO) {
				color[pos_v] = Color::BLU;
				D[pos_v] = D[pos_u]+1;
				PGR[pos_v] = pos_u;
				Q.push(v);
			}
		}

		//cout << Q.size() << endl;
		//cout << u.first << "-" << u.second << endl;
		Q.pop();
		color[pos_u] = Color::VIOLA;
	}

	//Controllo se è raggiungibile
	#define NONESISTENTE INT_MAX
	return !(D[V-1] == NONESISTENTE);
}

int main() {

	path_finder("......\n......\n......\n......\n.....W\n....W.");
	return 0;
}

