#pragma once
#include <vector>

class CoefficientCalculator {
  public:
	static std::vector<long> calculate(int terms);
  private:
	static long getCoefficient(const std::vector<long>& coefficients, int index);
};
