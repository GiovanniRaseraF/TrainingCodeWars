#include <math.h>
bool is_square(int n){
	int sr = floor(sqrt(n));
	return (sr * sr == n);
}