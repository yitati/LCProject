/******************************************************************************/
/*
* Question: #525 Contiguous Array
* Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1. 

Example 1:

Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:

Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

* Note: The length of the given binary array will not exceed 50,000. 

*/
/*****************************************************************************/

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int findMaxLength(vector<int>& nums)
{
	int maxLen = 0, sum = 0;
	unordered_map<int, int> table;
	table[0] = -1;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0) sum--;
		else sum++;
		if (table.count(sum))
		{
			maxLen = max(maxLen, i - table[sum]);
		}
		else
		{
			table[sum] = i;
		}
	}
	return maxLen;
}