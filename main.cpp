#include <iostream>
#include <vector>
#include "CoefficientCalculator.h"

void displayCoefficientsForTerm(int term) {
	std::vector<long> coefficients = CoefficientCalculator::calculate(term);
	for (const auto& coefficient: coefficients) {
		std::cout << coefficient << " ";
	}
	std::cout << "\n";
}

int main() {
	for (int i = 1; i < 10; i++) {
		displayCoefficientsForTerm(i);
	}
	return EXIT_SUCCESS;
}
