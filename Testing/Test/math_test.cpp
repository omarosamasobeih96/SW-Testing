#include "CppUTest\TestHarness.h"
#include "F:\Visual Studio Temp Projects\Testing\Testing\Competitive-Programming\math\math.cpp"
#include<iostream>
using namespace std;


TEST_GROUP(Math_Happy_COC) {
	// infeasible to force the combination where isLucky is true, isEven is false and hasSquare is true
};

TEST(Math_Happy_COC, Test1) {
	CHECK(checkHappy(4));
}

TEST(Math_Happy_COC, Test2) {
	CHECK(checkHappy(74));
}

TEST(Math_Happy_COC, Test3) {
	CHECK_FALSE(checkHappy(7));
}

TEST(Math_Happy_COC, Test4) {
	CHECK(checkHappy(16));
}

TEST(Math_Happy_COC, Test5) {
	CHECK_FALSE(checkHappy(2));
}

TEST(Math_Happy_COC, Test6) {
	CHECK_FALSE(checkHappy(81));
}

TEST(Math_Happy_COC, Test7) {
	CHECK_FALSE(checkHappy(3));
}


TEST_GROUP(Math_Happy_RACC) {

};

TEST(Math_Happy_RACC, Test1) {
	CHECK(checkHappy(74));
}

TEST(Math_Happy_RACC, Test2) {
	CHECK_FALSE(checkHappy(7));
}

TEST(Math_Happy_RACC, Test3) {
	CHECK(checkHappy(16));
}

TEST(Math_Happy_RACC, Test4) {
	CHECK_FALSE(checkHappy(2));
}


TEST_GROUP(Math_Happy_RICC) {
	// infeasible to force predicate to evaluate with true while isEven is major
};

TEST(Math_Happy_RICC, Test1) {
	CHECK(checkHappy(4));
}

TEST(Math_Happy_RICC, Test2) {
	CHECK(checkHappy(74));
}

TEST(Math_Happy_RICC, Test3) {
	CHECK_FALSE(checkHappy(7));
}

TEST(Math_Happy_RICC, Test4) {
	CHECK(checkHappy(16));
}

TEST(Math_Happy_RICC, Test5) {
	CHECK_FALSE(checkHappy(2));
}

TEST(Math_Happy_RICC, Test6) {
	CHECK_FALSE(checkHappy(81));
}

TEST(Math_Happy_RICC, Test7) {
	CHECK_FALSE(checkHappy(3));
}


TEST_GROUP(Math_Happy_CACC) {

};

TEST(Math_Happy_CACC, Test1) {
	CHECK(checkHappy(74));
}

TEST(Math_Happy_CACC, Test2) {
	CHECK_FALSE(checkHappy(7));
}

TEST(Math_Happy_CACC, Test3) {
	CHECK(checkHappy(16));
}

TEST(Math_Happy_CACC, Test4) {
	CHECK_FALSE(checkHappy(2));
}

TEST_GROUP(Math_Happy_GACC) {

};

TEST(Math_Happy_GACC, Test1) {
	CHECK(checkHappy(74));
}

TEST(Math_Happy_GACC, Test2) {
	CHECK_FALSE(checkHappy(7));
}

TEST(Math_Happy_GACC, Test3) {
	CHECK(checkHappy(16));
}

TEST(Math_Happy_GACC, Test4) {
	CHECK_FALSE(checkHappy(2));
}


TEST_GROUP(Math_Happy_GICC) {
	// infeasible to force predicate to evaluate with true while isEven is major
};

TEST(Math_Happy_GICC, Test1) {
	CHECK(checkHappy(4));
}

TEST(Math_Happy_GICC, Test2) {
	CHECK(checkHappy(74));
}

TEST(Math_Happy_GICC, Test3) {
	CHECK_FALSE(checkHappy(7));
}

TEST(Math_Happy_GICC, Test4) {
	CHECK(checkHappy(16));
}

TEST(Math_Happy_GICC, Test5) {
	CHECK_FALSE(checkHappy(2));
}

TEST(Math_Happy_GICC, Test6) {
	CHECK_FALSE(checkHappy(81));
}

TEST(Math_Happy_GICC, Test7) {
	CHECK_FALSE(checkHappy(3));
}


TEST_GROUP(Math_Happy_ClauseCoverage) {

};

TEST(Math_Happy_ClauseCoverage, Test1) {
	CHECK(checkHappy(4));
}

TEST(Math_Happy_ClauseCoverage, Test2) {
	CHECK_FALSE(checkHappy(3));
}

TEST_GROUP(Math_Happy_PredicateCoverage) {

};

TEST(Math_Happy_PredicateCoverage, Test1) {
	CHECK(checkHappy(16));
}

TEST(Math_Happy_PredicateCoverage, Test2) {
	CHECK_FALSE(checkHappy(2));
}

TEST_GROUP(MathUtilsTestGroup)
{
};

TEST(MathUtilsTestGroup, Test1)
{
	CHECK_EQUAL(3, gcd(6, 9));
	CHECK_EQUAL(1, gcd(10000, 23));
	CHECK_EQUAL(100, gcd(10000, 100));
	CHECK_EQUAL(13, gcd(13, 143));
	CHECK_EQUAL(13, gcd(26, 143));
}



TEST(MathUtilsTestGroup, Test2)
{
	LONGS_EQUAL(18, lcm(6, 9));
	LONGS_EQUAL(230000, lcm(10000, 23));
	LONGS_EQUAL(10000, lcm(10000, 100));
	LONGS_EQUAL(143, lcm(13, 143));
	LONGS_EQUAL(286, lcm(26, 143));
}

TEST(MathUtilsTestGroup, Test3)
{
	LONGS_EQUAL(9, powerr(3, 2));
	LONGS_EQUAL(25, powerr(5, 2));
	LONGS_EQUAL(216, powerr(6, 3));
	LONGS_EQUAL(100000, powerr(10, 5));
	LONGS_EQUAL(121, powerr(11, 2));
}

IGNORE_TEST(MathUtilsTestGroup, Test4)
{
	LONGS_EQUAL((1ll << 32), powerr(2, 32));
}

TEST(MathUtilsTestGroup, Test5)
{
	CHECK(isPrime(2));
	CHECK(isPrime(3));
	CHECK(isPrime(5));
	CHECK(isPrime(7));
	CHECK(isPrime(11));
	CHECK(isPrime(13));
	CHECK(isPrime(17));
	CHECK(isPrime(1e9 + 7));
}

TEST(MathUtilsTestGroup, Test6)
{
	CHECK_FALSE(isPrime(10));
	CHECK_FALSE(isPrime(15));
	CHECK_FALSE(isPrime(18));
	CHECK_FALSE(isPrime(49));
	CHECK_FALSE(isPrime(56));
	CHECK_FALSE(isPrime(1000));
	CHECK_FALSE(isPrime(1234));
	CHECK_FALSE(isPrime(1e9));
}

TEST(MathUtilsTestGroup, Test7)
{
	DOUBLES_EQUAL(12.56637061, circleArea(2), 0.000001);
	DOUBLES_EQUAL(530.9291585, circleArea(13), 0.1);
	DOUBLES_EQUAL(31415.92654, circleArea(100), 0.1);
	DOUBLES_EQUAL(314159265.4, circleArea(10000), 0.1);
}

IGNORE_TEST(MathUtilsTestGroup, Test8)
{
	DOUBLES_EQUAL(12.56637061, circleArea(2), 0.000001);
	DOUBLES_EQUAL(530.9291585, circleArea(13), 0.000001);
	DOUBLES_EQUAL(31415.92654, circleArea(100), 0.0000000001);
	DOUBLES_EQUAL(314159265.4, circleArea(10000), 0.000001);
}
TEST(MathUtilsTestGroup, Test9)
{
	UNSIGNED_LONGS_EQUAL(3, nPr(3, 1));
	UNSIGNED_LONGS_EQUAL(840, nPr(7, 4));
	UNSIGNED_LONGS_EQUAL(90, nPr(10, 2));
}




TEST(MathUtilsTestGroup, Test10)
{
	vector<int> expectedDivisors;
	int arr[] = { 1,2,3,4,6,9,12,18,36 };
	for (int i = 0; i < 9; i++) {
		expectedDivisors.push_back(arr[i]);
	}
	vector<int> divs = getDivisors(36);
	CHECK(expectedDivisors.size() == divs.size());
	for (int i = 0; i < divs.size(); i++)
	{
		LONGS_EQUAL(expectedDivisors[i], divs[i]);
	}
}

TEST(MathUtilsTestGroup, Test11)
{
	vector<int> expectedDivisors;
	int arr[] = { 1, 1000000007 };
	for (int i = 0; i < 2; i++) {
		expectedDivisors.push_back(arr[i]);
	}
	vector<int> divs = getDivisors(1000000007);
	CHECK(expectedDivisors.size() == divs.size());
	for (int i = 0; i < divs.size(); i++)
	{
		LONGS_EQUAL(expectedDivisors[i], divs[i]);
	}
}

