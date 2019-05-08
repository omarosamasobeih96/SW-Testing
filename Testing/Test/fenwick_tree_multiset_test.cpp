#include "CppUTest\TestHarness.h"
#include "F:\Visual Studio Temp Projects\Testing\Testing\Competitive-Programming\data_structures\fenwick_tree\fenwick_tree_multiset.cpp"
#include<iostream>
using namespace std;

const int MAX_N = 15;
const int MAX_V = 9;

TEST_GROUP(FenwickTree_Operator_RACC) {
	fenwick_multiset fm;
	int n;
	void setup() {
		n = MAX_N;
		for (int i = 0; i < n; ++i)
			fm.insert(rand() % MAX_V + 1);
	}
	void teardown() {

	}	
};

TEST(FenwickTree_Operator_RACC, Test1) {
	CHECK_THROWS(out_of_range, fm[0]);
}



TEST(FenwickTree_Operator_RACC, Test2) {
	int ret;
	try {
		ret = fm[1];
	}
	catch (exception e) {
		FAIL("test fail");
		return;
	}
	LONGS_EQUAL(ret, fm[1]);
}



TEST(FenwickTree_Operator_RACC, Test3) {
	CHECK_THROWS(out_of_range, fm[n+1]);
}




TEST_GROUP(FenwickTree_Insert_RACC) {
	fenwick_multiset fm;
	int n;
	void setup() {
		n = MAX_N;
		for (int i = 0; i < n; ++i)
			fm.insert(rand() % MAX_V + 1);
	}
	void teardown() {

	}
};

TEST(FenwickTree_Insert_RACC, Test1) {
	CHECK_THROWS(exception, fm.insert(0));
}



TEST(FenwickTree_Insert_RACC, Test2) {
	try {
		fm.insert(1);
	}
	catch (exception e) {
		FAIL("test fail");
		return;
	}
	LONGS_EQUAL(1, 1);
}



TEST(FenwickTree_Insert_RACC, Test3) {
	CHECK_THROWS(exception, fm.insert(N + 1));
}


TEST_GROUP(FenwickTree_Operator_ClauseCoverage) {
	fenwick_multiset fm;
	int n;
	void setup() {
		n = MAX_N;
		for (int i = 0; i < n; ++i)
			fm.insert(rand() % MAX_V + 1);
	}
	void teardown() {

	}
};

TEST(FenwickTree_Operator_ClauseCoverage, Test1) {
	CHECK_THROWS(out_of_range, fm[0]);
}


TEST(FenwickTree_Operator_ClauseCoverage, Test2) {
	CHECK_THROWS(out_of_range, fm[n+1]);
}


TEST_GROUP(FenwickTree_Insert_ClauseCoverage) {
	fenwick_multiset fm;
	int n;
	void setup() {
		n = MAX_N;
		for (int i = 0; i < n; ++i)
			fm.insert(rand() % MAX_V + 1);
	}
	void teardown() {

	}
};

TEST(FenwickTree_Insert_ClauseCoverage, Test1) {
	CHECK_THROWS(exception, fm.insert(0));
}


TEST(FenwickTree_Insert_ClauseCoverage, Test2) {
	CHECK_THROWS(exception, fm.insert(N + 1));
}

TEST_GROUP(FenwickTree_Operator_PredicateCoverage) {
	fenwick_multiset fm;
	int n;
	void setup() {
		n = MAX_N;
		for (int i = 0; i < n; ++i)
			fm.insert(rand() % MAX_V + 1);
	}
	void teardown() {

	}
};

TEST(FenwickTree_Operator_PredicateCoverage, Test1) {
	int ret;
	try {
		ret = fm[1];
	}
	catch (exception e) {
		FAIL("test fail");
		return;
	}
	LONGS_EQUAL(ret, fm[1]);
}


TEST(FenwickTree_Operator_PredicateCoverage, Test2) {
	CHECK_THROWS(out_of_range, fm[n + 1]);
}




TEST_GROUP(FenwickTree_Insert_PredicateCoverage) {
	fenwick_multiset fm;
	int n;
	void setup() {
		n = MAX_N;
		for (int i = 0; i < n; ++i)
			fm.insert(rand() % MAX_V + 1);
	}
	void teardown() {

	}
};

TEST(FenwickTree_Insert_PredicateCoverage, Test1) {
	CHECK_THROWS(exception, fm.insert(0));
}



TEST(FenwickTree_Insert_PredicateCoverage, Test2) {
	try {
		fm.insert(1);
	}
	catch (exception e) {
		FAIL("test fail");
		return;
	}
	LONGS_EQUAL(1, 1);
}