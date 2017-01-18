/******************************************************************************/
/*
* Question: #55 Jump Game
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
* Each element in the array represents your maximum jump length at that position.
* Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

*/
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// update the maxReach for every point and see if it can reach to the last one
// garantee that every point is able to go to next level
bool canJump(vector<int>& nums) 
{
	int n = nums.size();
	int i = 0, maxReach = nums[0];
	for (i = 0; i <= maxReach && i < n-1; i++)
	{
		maxReach = max(maxReach, nums[i] + i);
	}
	return maxReach >= n - 1;
}

bool canJump_dp(vector<int>& nums)
{
	int n = nums.size();
	int i = 0, j = 0, maxReach = nums[0];
	vector<int> dp(n, 0);
	dp[0] = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= nums[i] && i+j <= n-1; j++)
		{
			dp[i + j] = 1;
			if (i + j >= n - 1) return true;
		}
	}
	return (dp[n - 1] == 1);
}


int main(int argc, char * * argv)
{
	int input[] = { 0, 2, 3 }; // false
	//int input[] = { 2,3,1,1,4 }; // true
	//int input[] = { 3,2,1,0,4 };  // false
	//int input[] = { 0 }; // true
	vector<int> nums(input, input + sizeof(input) / sizeof(int));

	cout << canJump_dp(nums) << endl;

	system("pause");
}
