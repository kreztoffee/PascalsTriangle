#include <gtest/gtest.h>
#include "CoefficientCalculator.h"

TEST(BasicAssertions, calculateWithNoTerms) {
// given
	int term = 0;
	std::vector<long> expectedCoefficients;
// when
	std::vector<long> retCoefficients = CoefficientCalculator::calculate(term);
// then
	ASSERT_TRUE(retCoefficients.empty()) << "expected there to be no returned coefficients";
}

TEST(BasicAssertions, calculateWithOneTerm) {
// given
	int term = 1;
	std::vector<long> expectedCoefficients{1};
// when
	std::vector<long> retCoefficients = CoefficientCalculator::calculate(term);
// then
	ASSERT_EQ(term, retCoefficients.size()) << "expected there to be one returned coefficient";

	for (int i = 0; i < retCoefficients.size(); ++i) {
		EXPECT_EQ(expectedCoefficients[i], retCoefficients[i]) << "terms differ at index " << i;
	}
}

TEST(BasicAssertions, calculateWithFiveTerms) {
// given
	int term = 5;
	std::vector<long> expectedCoefficients{1, 4, 6, 4, 1};
// when
	std::vector<long> retCoefficients = CoefficientCalculator::calculate(term);
// then
	ASSERT_EQ(term, retCoefficients.size()) << "expected there to be five returned coefficient";

	for (int i = 0; i < retCoefficients.size(); ++i) {
		EXPECT_EQ(expectedCoefficients[i], retCoefficients[i]) << "terms differ at index " << i;
	}
}

TEST(BasicAssertions, calculateWithNegativeTerms) {
// given
	int term = -1;
	std::vector<long> expectedCoefficients;
// when
	std::vector<long> retCoefficients = CoefficientCalculator::calculate(term);
// then
	ASSERT_TRUE(retCoefficients.empty()) << "expected there to be no returned coefficients";
}
