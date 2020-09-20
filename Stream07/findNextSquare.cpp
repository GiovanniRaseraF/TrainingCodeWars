#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

long int findNextSquare(long int sq) {
	// Return the next square if sq if a perfect square, -1 otherwise
	long int s = floor(sqrt(sq));
	if (s * s != sq) return -1;
	long int next = sq + 1;
	long int s_next = floor(sqrt(next));
	while (s_next * s_next != next) {
		next++;
		s_next = floor(sqrt(next));
	}

	return next;
}

//Soluzione migliore
///
/// Controllo che il numero sotto radice sia uguale alla trasformazione 
/// in intero della rafice

/// Se questo è vero allora faccio la radice + 1 alla seconda
/// Ovvio
///
long int findNextSquare(long int sq) {
	if (sqrt(sq) != (int)sqrt(sq)) { return -1; }
	return  pow(sqrt(sq) + 1, 2);
}

int main() {
	cout<<findNextSquare(121)<<endl;
	cout<<findNextSquare(625)<<endl;
	cout<<findNextSquare(114)<<endl;

	return 0;
}

