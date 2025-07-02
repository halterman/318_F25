#include <iostream>
#include <vector>
#include "vectorutils.h"


void print(std::vector<int> vec) {
	std::cout << '{';
	int n = vec.size();
	if (n > 0) {
		// Print the first element
		std::cout << vec[0];
		for (int i = 1; i < n; i++) {
			std::cout << ", " << vec[i];
		}
	}
	std::cout << "}\n";
}

int main() {
	std::vector<int> seq{10, 20, 30, 40, 50};
	print(seq);
	std::cout << sum(seq) << '\n';
}