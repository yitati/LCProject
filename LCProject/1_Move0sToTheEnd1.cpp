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

// finally there will be 2 zones
// [0, k) - non-zero values
// [k, i] - unknown area
// (i, n-1] - all 0's
void moveZero(vector<int> & nums) {
	int n = nums.size();
	int k = 0, i = n - 1;
	while (k <= i)
	{
		if (nums[k] == 0)
		{
			swap(nums[k], nums[i--]);
		}
		else k++;
	}
}


/*
int main(int argc, char** argv) {
	// to generate real radom numbers
	srand(time(NULL));
	int tLength = 10;

	vector<int> testcase = generateTestcase(tLength);
	for (int v : testcase) {
		cout << v << " ";
	}
	cout << endl;

	moveZero(testcase);
	for (int v : testcase) {
		cout << v << " ";
	}
	cout << endl;
	system("pause");
}
*/
