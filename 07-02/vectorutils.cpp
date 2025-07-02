#include "vectorutils.h"


int sum(std::vector<int> vec) {
	int total = 0;
	for (int elem : vec) {
		total += elem;
	}
	return total;
}
