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
		int value = rand() % 3-1;
		testcase[i] = value;
	}
	return testcase;
}

// four areas
// [0, i) - all elements < 0 (-1's)
// [i, j] - should be all 0's but
//    - [i, k) - known 0
//    - [k, j] - unknow area
// (j, n-1) - all elements > 0 (1's)

void rainbowSort(vector<int> & nums) {
	int n = nums.size();
	int i = 0, j = n - 1, k = 0;
	while (k <= j)
	{
		if (nums[k] == -1) 
		{
			swap(nums[k++], nums[i++]);
		}
		else if (nums[k] == 1)
		{
			swap(nums[k], nums[j--]);
		}
		else // nums[k] == 0
		{
			k++;
		}	
	}

}


/*
int main(int argc, char** argv) {
	srand(time(NULL));
	int tLength = 10;
	vector<int> testcase = generateTestCase(tLength);
	rainbowSort(testcase);
	int i = 0;
	int n = testcase.size();
	for (i = 0; i < n; i++)
	{
		cout << testcase[i] << endl;
	}
	system("pause");
}
*/
