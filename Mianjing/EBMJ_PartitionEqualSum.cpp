/*
 * EBMJ_PartitionEqualSum.cpp
 *

Partition problem is to determine whether a given set can be partitioned into two subsets
such that the sum of elements in both subsets is same.

Examples

arr[] = {1, 5, 11, 5}
Output: true
The array can be partitioned as {1, 5, 5} and {11}

arr[] = {1, 5, 3}
Output: false
The array cannot be partitioned into equal sum sets.

http://www.geeksforgeeks.org/dynamic-programming-set-18-partition-problem/
 */

#include <vector>

using namespace std;

// TODO -  today

/*
 * Solution 1 - Recursive Solution O(n^2)
 * 1) Calculate the sum of the array. If sum is odd, there cannot be two subsets with equal sum.
 * 2) Calculate sum/2 and find a subset array with sum equal to sum/2.
 */
bool isSubsetSum(vector<int> nums, int n, int sum)
{
	if(sum == 0) return true;
	if(n == 0 && sum != 0) return false;
	if(nums[n-1] > sum)
	{
		return isSubsetSum(nums, n-1, sum);
	}
	return isSubsetSum(nums, n-1, sum) || isSubsetSum(nums, n-1, sum-nums[n-1]);
}

bool findPartition(vector<int> nums)
{
	int length = nums.size();
	int sum = 0;
	for(int num : nums) sum += num;
	if(sum % 2 != 0) return false;
	return isSubsetSum(nums, length, sum/2);
}

// todo - finish up dp solution
// todo - today
/*
 * Solution 2 - DP solution
 */



