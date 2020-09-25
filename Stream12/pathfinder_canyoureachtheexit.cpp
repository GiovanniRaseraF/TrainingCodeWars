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





bool path_finder(string maze) {
	// TODO: Determine whether one can reach the exit at (n - 1, n - 1)
	// starting from (0, 0) in a n × n maze (represented as a string)
	// and return a boolean value accordingly
	

	// Ho un grafo non orientato e devo trovare la strada per arrivare alla fine
	// Eseguo bfs e se dalla fine all'inizio non ci sono strade allora non 
	// ho strade possibili

	int* color = new int[];

	return false;
}

int main() {


	return 0;
}



typedef tuple<Color*, Nodo*, int*> BFSResult;
static BFSResult* BFS(Grafo* grafo, Nodo S, bool visualizza) {
	if (visualizza) cout << endl << "BFS VISIT";

	int V = grafo->rappresentazione->V;
	Color* color = new Color[V];
	Nodo* PGR = new Nodo[V];
	int* D = new int[V];
	queue<Nodo>* Q = new queue<Nodo>();

	//Inizializzazione
	for (int v = 0; v < V; v++) 		//for(each v � V / {S})
		if (v != S) {					//		V / {S}
			color[v] = Color::BIANCO;
			PGR[v] = NILL;
			D[v] = INT_MAX;
		}

	color[S] = Color::GRIGIO;
	PGR[S] = NILL;
	D[S] = 0;
	Q->push(S);

	//Comincio con la visita
	while (!Q->empty()) {
		Nodo u = Q->front();
		vNodi* adicenza = grafo->rappresentazione->puntatiDa_vNodi(u);
		//Controllo ogni nodo adiacente
		for (Nodo v : *adicenza) {
			if (color[v] == Color::BIANCO) {
				color[v] = Color::GRIGIO;
				D[v] = D[u] + 1;
				PGR[v] = u;
				//Carico nella cosa il nuovo nodo da visitare
				Q->push(v);
			}
		}

		Q->pop();
		color[u] = Color::NERO;
		//(L'utilizzo dei colori permette al mio codice di non reinserire u nella cosa e quindi di non rivisitarlo)
	}
	//Costruisco il vettore di ritorno
	BFSResult* res = new BFSResult(); std::get<0>(*res) = color; std::get<1>(*res) = PGR; std::get<2>(*res) = D;
	return res;
}