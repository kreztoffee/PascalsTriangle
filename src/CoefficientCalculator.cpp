#include "CoefficientCalculator.h"

std::vector<long> CoefficientCalculator::calculate(int terms) {
	std::vector<long> currentCoefficients;
	if (terms < 1) {
		return currentCoefficients;
	}

	std::vector<long> previousCoefficients(1, 1);
	for (int i = 1; i <= terms; ++i) {
		currentCoefficients.clear();
		for (int j = 0; j < i; ++j) {
			currentCoefficients.push_back(
				getCoefficient(previousCoefficients, j - 1) + getCoefficient(previousCoefficients, j));
		}
		previousCoefficients = currentCoefficients;
	}

	return currentCoefficients;
}

long CoefficientCalculator::getCoefficient(const std::vector<long>& coefficients, int index) {
	if (index < 0 || index >= static_cast<int>(coefficients.size()) || coefficients.empty()) {
		return 0;
	}
	return coefficients[index];
}
