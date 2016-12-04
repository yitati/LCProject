/*
Given an array of integers, move all the 0s to the right end of the array.
The relative order of the elements in the original array does not need to be maintained

{1} -> {1}
{1, 0, 3, 0, 1} -> {1, 3, 1, 0, 0} or {1, 1, 3, 0, 0} or {3, 1, 1, 0, 0}

*/

#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

#define TESTCASERANGE 9
#define ZEROFREQUENCY 4

vector<int> generateTestcase(int length) {
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

class Solution {
public:
	vector<int> moveZero(vector<int> array) {
		vector<int> nums;
		return nums;
	}
};

/*
int main(int argc, char** argv) {
	srand(time(NULL));
	int tLength = 10;

	vector<int> testcase = generateTestcase(tLength);
	for (int v : testcase) {
		cout << v << " ";
	}
	cout << endl;

	Solution S;
	vector<int> moved = S.moveZero(testcase);
	for (int v : moved) {
		cout << v << " ";
	}
	cout << endl;
}
*/