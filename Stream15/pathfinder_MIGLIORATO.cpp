#include <vector>
#include <numeric>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

//NON FUNZIONA IMPLEMENTAZIONE SBAGLIATA
bool path_finder(string m) {
	//Dati fondamentali
	int len = 0;
	while (m[len] != '\n') len++;
	int V = len * len;
	int strlen = m.length();

	//Vettore delle distanze
	int* D = new int[V] {INT_MAX};
	int* color = new int[V] {0};
	for (int i = 0; i < V; i++) {

	}
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
		if (bot(u) < strlen && m[bot(u)] == '.') adix.push_back(bot(u));
		if (lef(u) >= 0 && m[lef(u)] == '.') adix.push_back(lef(u));
		if (rig(u) < strlen && m[rig(u)] == '.') adix.push_back(rig(u));

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

	int last = D[strlen-1];
	//Controllo se è raggiungibile
	return !(last == INT_MAX);
}

//Soluzione migliore
#include <set>
using namespace std;

bool path_finder_CodeWars(string maze) {
	//Calcola la lunghezza di ogni riga
	int size = 0;
	while (maze[size] != '\n') size++;

	//Crea le strutture necessarie ad eseguire BFS
	std::set<int> visited;
	visited.insert(0);
	std::vector<int> agenda;
	agenda.push_back(0);

	//Esegue BFS ma non gli interessa della distanza è solo interessato 
	//Ad una cosa: cioe che l'ultimo elemento interessato viene inserito negli step
	//Nel caso l'ultimo elemento entri nella lista agenda allora vuol dire che è raggiungibile
	while (agenda.size()) {
		int current = agenda.back();
		agenda.pop_back();

		//Calcolo della posizioni
		int up = current - size - 1;
		int down = current + size + 1;
		int left = current - 1;
		int right = current + 1;
		int steps[] = { up, down, left, right };

		for (int step : steps) {
			//Controllo che non sia un elemento fuori dalla stringa
			if (step < 0) continue;
			if (step >= maze.size()) continue;
			//Conto di non averlo gia visitato
			if (visited.count(step)) continue;
			//Controllo che sia una posizione valida
			if (maze[step] != '.')  continue;

			//Inserisco il nodo appena fisitato nella lista dei visitati
			//Interessante l'ottimizzazione che anche se lo ho visto tramite gli elementi vicini allora ci posso andare
			visited.insert(step);
			//Lo salvo come prossimo elemento da visitare
			agenda.push_back(step);

			//Se è l'ultimo elemento allora posso dire che la posizione interessata è raggiungibile
			if (step == maze.size() - 1) return true;
		}
		
	}

	//Se tutto finisce ed arrivo a questo punto vuol dire che non è raggiungibile
	return false;
}

int main() {

	path_finder("......\n......\n......\n......\n.....W\n....W.");
	return 0;
}

