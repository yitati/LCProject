/******************************************************************************
* Question: #377 Combination Sum IV
* company tag: Facebook, Google
* Given an integer array with all positive numbers and no duplicates, 
* find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

* Note that different sequences are counted as different combinations.
* Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*****************************************************************************/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// dp solution - samilar to fibonacci
// this is very similar to subset sum problems
int combinationSum4(vector<int>& nums, int target)
{
	vector<int> dp(target + 1);
	dp[0] = 1;
	for (int i = 1; i <= target; i++)
	{
		for (int j = 0; j<nums.size(); j++)
		{
			if (i - nums[j] >= 0)
			{
				dp[i] += dp[i - nums[j]];
			}
		}
	}
	return dp[target];
}

/*
What if negative numbers are allowed in the given array?
Then adding a num to the combination is not guaranteed to be increasing, which means I can add a huge bounch of negative nums
and add a huge bounch of positive nums to achieve a target sum. eg.target=0:[-1,1],[-1,-1,1,1],[-1,-1,-1,1,1,1]...

How does it change the problem?
We will have lots of lots of possible combinations, even infinity.

What limitation we need to add to the question to allow negative numbers?
For example, each negative num can only be used once, etc.
 */
