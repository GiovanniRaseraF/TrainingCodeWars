#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <mutex>
#include <assert.h>
/*
Implementazione in c++ della coda con priorità aggiornabile
Authot:		Giovanni Rasera
Git:		https://github.com/GiovanniRaseraF/updatable-priority-queue
*/

template <
	class T,		
	//Un qualsiasi tipo di dato 
	
	class Container = std::vector<T>,	
	/*
	Un vettore di tipo
	IN C# dovrai specificare che sono
	comparabili {ma non sono sicuro}
	*/

 	class Compare = std::less<typename Container::value_type>
	// Importante
	/*
	Questa riga della definizione del templase definisce la funzione con 
	cui comparo gli elementi ed è ciò che mi permette di astrarre dal tipo
	di dato che inserisco

	Da notare che definisco less e quindi devo definire
	come viene eseguita l'operazione di:

	a     <    b     ?

	tu dovrai definire come vanno comparati a e b
	*/
>

class updatable_priority_queue{
private:
	Container heap;
	Compare	comparatore;

public:
	/// <summary>
	/// Costruttore a cui devo specificare come comparare due elementi
	/// </summary>
	/// <param name="comp"> Comparatore di less ( a < b ?) </param>
	updatable_priority_queue(Compare& comp) : comparatore{ comp }, heap{}{}
	
	////////Sezione legata al settaggio di valori

	/// <summary>
	/// Inserisce un elemento
	/// </summary>
	/// <param name="element"></param>
	void insert(T& element) {
		this->heap.push_back(element);
		this->bubble_up(this->size() - 1);
	}

	////////Sezione legata al get e non all'estrazione
	/*
	Questo vuol dire che nessuna di queste funzioni modifica parametri
	All'interno della coda
	*/

	/// <summary>
	/// Guarda una copia dell'elemento
	/// </summary>
	/// <param name="index"> indice </param>
	/// <returns> Una copia dell'elemento alla posisione specificata</returns>
	const T lookat(int index) {
		assert(index >= 0 && index < this->heap.size());
		//Copia
		T ret{ this->heap[index] };
		return ret;
	}

	/// <summary>
	/// Guardo alla copia dell'elemento 0 che è il Minimo
	/// </summary>
	T peek() {
		if (this->heap.empty()) return nullptr;
		//Copio l'elemento 0
		T ret{ this->heap[0] };
		return ret;
	}

	/// <summary>
	/// Guardo all'elemento 0 che è il Minimo
	/// </summary>
	T& peek_address() {
		if (this->heap.empty()) return nullptr;
		return this->heap[0];
	}

	int size() {
		return this->heap.size();
	}

	bool empty() {
		return this->heap.empty();
	}

private:
	/*
	TODO:
		- Da commentare tutto il codice
	*/
	void bubble_up(int index) {
		T& element = this->heap[index]; 
		T& parent;
		int parentIndex = 0;
		
		while (index > 0) {
			parentIndex = floor((index + 1) / 2) - 1;
			parent = this->heap[parentIndex];
			//Controllo
			if (!this->comparatore(element, parent) && !element == parent) {
				//Mi fermo se ho gia messo apposto la heap
				break;
			}
			//Mi sposto sul parent
			std::swap(this->heap[parentIndex], this->heap[index]);
			index = parentIndex;
		}
	}

	void sink_down(int index) {
		int length = this->heap.size();
		T& element = this->heap[index];
		int swapIndex = 0;

		while (true) {
			int rightChildIndex = (index + 1) * 2;
			int leftChildIndex = rightChildIndex - 1;
			swapIndex = -1;

			if (leftChildIndex < length) {
				T& leftChild = this->heap[leftChildIndex];

				if (this->comparatore(leftChild, element)) swapIndex = leftChildIndex;
				
				if (rightChildIndex < length) {
					const T& rightChild = this->heap[rightChildIndex];
					if ((swapIndex == -1 || this->comparatore(rightChild, leftChild)) && this->comparatore(rightChild, element)) {
						swapIndex = rightChildIndex;
					}
				}
			}

			if (swapIndex == -1) {
				break;
			}

			std::swap(this->heap[index], this->heap[swapIndex]);
			index = swapIndex;
		}
	}


};

using pr = updatable_priority_queue<std::pair<int, int>>;

int main() {
	using namespace std;
	
	
	auto compare = [](std::pair<int, int> a, std::pair<int, int> b) {
		return a.first < b.first;
	};

	updatable_priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, decltype(compare)> Q{compare};


	Q.


	return 0;
}