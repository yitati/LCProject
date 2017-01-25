/******************************************************************************/
/*
* Question: #45 Jump Game II
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
* Each element in the array represents your maximum jump length at that position.
* Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

*/
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


// the idea is to use dfs and update the minJump from every possible path
// using dp - exceed the time limit since we need to loop for every step - this is not necessary
int jump_dp(vector<int>& nums) 
{
	int n = nums.size();
	unordered_set<int> visited;
	vector<int> dp(n, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i<n - 1; i++)
	{
		if (visited.find(i) != visited.end()) continue;
		visited.insert(i);
		if (nums[i] == 0) continue;
		for (int step = 1; step <= nums[i] && i + step < n; step++)
		{
			if (visited.find(i + step) != visited.end()) continue;
			dp[i + step] = min(dp[i + step], dp[i] + 1);
			visited.insert(i + step);
		}
	}
	return dp[n - 1];
}

// using bfs
// always calculate the maxReach of every step - if it covers the destination then return current step
int jump_bfs(vector<int> & nums)
{
	int n = nums.size();
	if (n < 2) return 0;
	int step = 0, i = 0, currReach = 0, nextReach = 0;
	while (currReach - i + 1 > 0)  // there are nodes we still need to check
	{
		step++;
		for (; i <= currReach; i++)
		{
			nextReach = max(nextReach, i + nums[i]);
			if (nextReach >= n - 1) return step;
		}
		currReach = nextReach;
	}
	return 0;
}

/*
int main(int argc, char * * argv)
{
	//int input[] = { 2,3,1,1,4 }; // true
	int input[] = { 0 }; // true
	vector<int> nums(input, input + sizeof(input) / sizeof(int));

	cout << jump(nums) << endl;

	system("pause");
}
*/

