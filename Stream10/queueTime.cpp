#include <utility>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

long queueTime(std::vector<int> customers, int n) {
	//Creazione delle code
	vector<vector<int>> tills{};
	long len_c = customers.size();
	for (int i = 0; i < n; i++) tills.push_back({});
	
	int i = 0;
	for (; i < len_c && i < n; i++) {
		tills[i].push_back(customers[i]);
	}

	for (; i < len_c; i++) {
		int cust = customers[i];
		//Lo aggiungo alla coda che ci mette meno
		std::vector<vector<int>>::iterator res = std::min_element(tills.begin(), tills.end(),
			[](vector<int>& a, vector<int>& b) {
				long sum_a = std::accumulate(a.begin(), a.end(), 0);
				long sum_b = std::accumulate(b.begin(), b.end(), 0);
				return sum_a < sum_b;
		});
		int pos_min_till = std::distance(tills.begin(), res);
		//Lo aggiungo alla coda piu corta

		tills[pos_min_till].push_back(cust);
	}


	std::vector<vector<int>>::iterator res = std::max_element(tills.begin(), tills.end(),
		[](vector<int>& a, vector<int>& b) {
		long sum_a = std::accumulate(a.begin(), a.end(), 0);
		long sum_b = std::accumulate(b.begin(), b.end(), 0);
		return sum_a < sum_b;
	});
	int pos_max_till = std::distance(tills.begin(), res);
	vector<int> max_till = tills[pos_max_till];

	long ret_val = std::accumulate(max_till.begin(), max_till.end(), 0);
	
	return ret_val;
}


//La mai fa schifo rispetto a questa
long queueTime(std::vector<int> customers, int n) {
	std::vector<long> queues(n, 0);

	for (int i : customers)
		*std::min_element(queues.begin(), queues.end()) += i;

	return *std::max_element(queues.cbegin(), queues.cend());
}

/*
	cout << "\nCode\n";
	for (auto t : tills) {
		for (auto c : t) {
			cout << c << " ";
		}
		cout << endl;
	}
	*/
int main() {
	cout<<queueTime(std::vector<int>{5, 3, 4}, 1)<<endl;
		// should return 12
		// because when n=1, the total time is just the sum of the times

	cout<<queueTime(std::vector<int>{10, 2, 3, 3}, 2)<<endl;
		// should return 10
		// because here n=2 and the 2nd, 3rd, and 4th people in the 
		// queue finish before the 1st person has finished.

	cout<<queueTime(std::vector<int>{2, 3, 10}, 2);
		// should return 12
	return 0;
}