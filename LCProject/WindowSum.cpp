/*
 * MianJing: Window Sum
 * Given an array of n integer, and a moving window(size k), move the window at each iteration
 * from the start of the array, find the sum of the element inside the window at each moving.
 *
Example:
For array [1, 2, 7, 8, 5], moving window size k = 3
1 + 2 + 7 = 10
2 + 7 + 8 = 17
7 + 8 + 5 = 20
return [10,17,20]
 *
 */

/*
 * two pointers Solution
 * 1. first we need to initialize the window
 * 2. we move the window to add the rhs to the window sum and subtract the lhs
 * from the window sum
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> winSum(vector<int>& nums, int k)
{
	if(nums.empty()) return {};
	// if k >= nums.size() we still want to return the sum of the array
	vector<int> window;
	int lhs = 0, rhs = 0, wSum = 0;
	// initialize the window
	while(rhs-lhs < k && rhs < nums.size())
	{
		wSum += nums[rhs++];
	}
	window.push_back(wSum);
	// move the window
	while(rhs < nums.size())
	{
		wSum += nums[rhs++];
		wSum -= nums[lhs++];
		window.push_back(wSum);
	}
	return window;
}

/*
int main(int argc, char ** argv)
{
	vector<int> nums = {1, 2, 3, 5, 6, 8, 7, 3, 4}; // 6, 10, 14, 19, 21, 18, 14
	vector<int> window = winSum(nums, 3);

	for(int sum : window){
		cout << sum << "   ";
	}

	return 0;

}
*/


