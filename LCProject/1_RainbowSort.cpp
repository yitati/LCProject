/*
Given an array of balls, where the color of the balls can only be Red, Green or Blue, sort the balls such that all 
the Red balls are grouped on the left side, all the Green balls are grouped in the middle and all the Blue balls are 
gourped on the right side. (Red is denoted by -1, Green is denoted by 0, Blue is denoted by 1)

{0} -> {0}
{1, 0} -> {0, 1}
{1, 0, 1, -1, 0} -> {-1, 0, 0, 1, 1}

*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>

using namespace std;

vector<int> generateTestCase(int length) {
	vector<int> testcase(length);
	for (int i = 0; i < length; i++) {
		int value = rand() % 3;
		if (value == 2) value = -1;
		testcase[i] = value;
	}
	return testcase;
}

// four areas
// [0, i) - all elements < 0 (-1)
// [i, j) - unknown area
// [j, x) - all elements >0
class Solution {
public:
	vector<int> rainbowSort(vector<int> a) {
		vector<int> nums;
		return nums;
	}
};

/*
int main(int argc, char** argv) {
	srand(time(NULL));
	int tLength = 10;
	vector<int> testcase = generateTestCase(tLength);
	Solution S;
	vector<int> sorted = S.rainbowSort(testcase);
	if (is_sorted(sorted.begin(), sorted.end())) {
		cout << "Sorted" << endl;
	}
}
*/