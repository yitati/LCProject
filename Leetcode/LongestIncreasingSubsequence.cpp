/******************************************************************************/
/*
* Question: #300 Longest Increasing Subsequence
* Given an unsorted array of integers, find the length of longest increasing subsequence. 
* company tag: Facebook
* For example,
* Given [10, 9, 2, 5, 3, 7, 101, 18],
* The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. 
* Note that there may be more than one LIS combination, it is only necessary for you to return the length. 

* Your algorithm should run in O(n2) complexity. 
* Follow up: Could you improve it to O(n log n) time complexity? 
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;
// O(n^2) solution
int lengthOfLIS(vector<int>& nums)
{
	if (nums.empty()) return 0;
	int len = nums.size(), maxLen = 1;
	vector<int> dp(len, 1);
	for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j]) dp[i] = max(dp[j] + 1, dp[i]);
		}
		maxLen = max(maxLen, dp[i]);
	}

	return maxLen;
}

// O(nlogn) solution
/*
 * Algorithm details from this link - http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
 * And to recover the longest subarray list - http://www.geeksforgeeks.org/construction-of-longest-monotonically-increasing-subsequence-n-log-n/
 *
 *  In general, we have set of acitve lists of varying length. When adding an element A[i] to these lists, we scan the lists(for end elements)
 *  in decreasing order of their length. We will verify the end elements of all the lists to find a list whose end element is smaller than A[i]
 *  1. If A[i] is the smallest among all end candidates of active lists, we still start new active list of length 1.
 *  2. If A[i] is the largest among all end candidates of active lists, we will clone the largest active list, and extend it by A[i].
 *  3. If A[i] is in between, we will find a list with largest end element that is smaller than A[i]. Clone and extend this list by A[i].
 *  We will discard all other lists of same length as that of this modified list.
 *
 */

/*
 * If we keep a vector to log all the smallest tails of possible increasing list. then each time when we meet a new element, we try to check
 * it with all existing smallest tails, if it is the largest that means it should be large than all possible lists' tails. So we add it to the
 * vector and incresing by 1.
 * If we find it is smaller than some tail, then update the tail with new element.
 */
int lengthOfLIS_binarySearch(vector<int> & nums)
{
	vector<int> table;  // this is the array of all end elements
	for (int i = 0; i < nums.size(); i++)
	{
		auto it = lower_bound(table.begin(), table.end(), nums[i]);
		if (it == table.end()) table.push_back(nums[i]);
		*it = nums[i];
	}

	return table.size();
}
