#include <vector>
#include <numeric>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

using ull = unsigned long long;

ull exp_sum_p(ull n, ull m) {
	if (n == 0) return 1;
	if (n == 1) return 1;

	ull sum = 0;
	for (ull k = 1; k <= m; k++) {
		sum += exp_sum_p(n-m, k);
	}

	return sum;
}

ull exp_sum(ull n) {
	ull sum = 0;
	for (ull m = 1; m <= n; m++) {
		sum += exp_sum_p(n, m);
	}
	return sum;
}

int main() {
	for (int i = 1; i <= 4; i++) {
		cout << "i: " << i << " -> " << exp_sum_p(4, i) << endl;
	}
	return 0;
}