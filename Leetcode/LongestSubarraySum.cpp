/*
Given an unsorted integer array, find the subarray that has the greatest sum. Return the sum.

Assumptions

The given array is not null and has length of at least 1.
Examples

{2, -1, 4, -2, 1}, the largest subarray sum is 2 + (-1) + 4 = 5

{-2, -1, -3}, the largest subarray sum is -1
*/

#include <algorithm>
#include <vector>

using namespace std;

int longestSubarraySum(vector<int> input)
{
	if (input.empty()) return 0;
	int currSum = input[0], maxSum = currSum;
	for (int i = 1; i < input.size(); i++)
	{
		currSum = max(currSum + input[i], input[i]);
		maxSum = max(maxSum, currSum);
	}
	return maxSum;
}
