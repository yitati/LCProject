/******************************************************************************/
/*
* Question: #209 Minimum Size Subarray Sum 
* Given an array of n positive integers and a positive interger s, find the minimal length of a subarray of which
* the sum >= s. If there isn't one, return 0 instead.
* For example, given the array [2, 3, 1, 2, 4, 3] and s = 7,
* the subarray [4, 3] has the minimal length under the problem constraint.
* More practice:
* If you have figured out the O(n) solution, try coding another solution of which the time 
* complexity is O(n log n).
*/
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* maintain one window that has lhs and rhs, keep sum between the window has sum >= s
* then move the lhs to right, find the coresponding max length
* The time complexity of this solution is O(n)
*/
int minSubArrayLen(int s, vector<int>& nums) 
{
	int n = nums.size();
	int minLength = n+1;
	int lhs = 0, rhs = 0;
	int currSum = 0;
	while (rhs < n)
	{
		while (currSum < s && rhs < n)
		{
			currSum += nums[rhs];
			rhs++;
		}
		while (currSum >= s)
		{
			minLength = min(minLength, rhs - lhs);
			currSum -= nums[lhs];
			lhs++;
		}
	}
	return minLength == n+1 ? 0 : minLength;
}

/*
int main(int argc, char * argv)
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(3);
	cout << minSubArrayLen(7, nums) << endl;

	system("pause");
}
*/