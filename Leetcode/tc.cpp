#include "../Leetcode/tc.h"

#include <ctime>
#include <cstdlib>

using namespace std;

vector<int> generateTestcase(int length) 
{
	vector<int> testcase(length);
	for (int i = 0; i < length; i++) {
		if ((rand() % ZEROFREQUENCY) == 0) {
			testcase[i] = 0;
		}
		else {
			testcase[i] = rand() % TESTCASERANGE + 1;
		}
	}
	return testcase;
}
