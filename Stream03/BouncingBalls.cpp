#include <iostream>
#include <string>
using namespace std;
class Bouncingball
{
public:
	static int bouncingBall(double h, double bounce, double window) {
		//Controllo i prerequisiti
		if (h <= 0 || bounce <= 0 || bounce >= 1 || window >= h) return -1;
		//cout << "h: " << h << " bounce: " << bounce << " window: " << window << endl;
		//Codice
		double init_h = h;
		int seen = 0;
		while (init_h > window) {
			//cout << "INIT: " << init_h << " seen: " << seen << " next_init_h: " << init_h * bounce<<endl;
			seen++;
			init_h = init_h * bounce;
			if (init_h > window) seen++;
		}
		return seen;
	}

	//Soluzione migliore presa da CW
	static int bouncingBall_CodeWars(double h, double bounce, double window) {
		if (h <= 0 || bounce <= 0 || bounce >= 1 || window >= h) return -1;
		return (int)floor(log(window / h) / log(bounce)) * 2 + 1;
	}
};


int main() {

	cout << Bouncingball::bouncingBall(3, 0.66, 1.5) << endl;
	cout << Bouncingball::bouncingBall(30, 0.66, 1.5);
	return 0;
}