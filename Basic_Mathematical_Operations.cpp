#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <sstream>
#include <limits>
using namespace std;

int basicOp(char op, int val1, int val2) {
	switch(op){
	case '+':
		return val1 + val2;
	case '-':
		return val1 - val2;
	case '*':
		return val1 * val2;
	case '/':
		return val1 / val2;
	}
	return 0;
}

int main() {

	return 0;
}