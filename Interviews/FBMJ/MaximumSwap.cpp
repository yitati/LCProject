/***********************************************************************************************************
 * MaximumSwap.cpp
 * company tag: Facebook
 * Given a non-negative integer, you could swap two digits at most once to get the maximum valued number.
 * Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.

 * Note:
 * The given number is in the range [0, 108]
 ***********************************************************************************************************/

#include <string>
#include <vector>

using namespace std;

int maximumSwap(int num) {
	string nums = to_string(num);    // to put the numbers from integer
	int n = nums.length();
	vector<int> maxNum(n, -1); // to put the index of max numbers appeared in the right

	int currIdx = n - 1;
	// from right to left
	for (int i = n - 1; i >= 0; i--) {
		if (nums[i] > nums[currIdx]) {
			currIdx = i;
		}
		maxNum[i] = currIdx;
	}
	// from left to right
	for (int i = 0; i < n; i++) {
		if (nums[i] != nums[maxNum[i]]) {
			swap(nums[i], nums[maxNum[i]]);
			break;
		}
	}

	return atoi(nums.c_str());
}
