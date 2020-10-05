#include <iostream>
#include <vector>
#include <algorithm>
int findOdd(const std::vector<int>& num) {
	//your code here
	std::vector<int> numbers{};
	for (int n : num) numbers.push_back(n);

	std::sort(numbers.begin(), numbers.end());
	int somma = 0;
	int i = 0;
	for (int n : numbers) {
		if (i % 2 == 0) somma += n;
		else somma -= n;
		i++;
	}

	return somma;
}

#include <functional>
#include <numeric>
#include <vector>

int findOdd_CodeWars(const std::vector<int>& numbers) {
	return std::accumulate(numbers.cbegin(), numbers.cend(), 0, std::bit_xor<>());
}

int findOdd_MIO(const std::vector<int>& numbers) {
	int sum = 0;
	for (int i : numbers) {
		sum += (sum^i);
	}
	return sum;
}

int main() {
	std::vector<int> a{ 20, 1, -1, 2, -2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, -2, 5 };
	std::cout<<findOdd_MIO(a);
	return 0;
}

