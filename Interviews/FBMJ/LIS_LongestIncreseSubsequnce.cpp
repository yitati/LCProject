/*
 * LongestIncreseSubsequnce.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: JoanneY1
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

/******************************************************************************
* Question: #674 Longest Continuous Increasing Subsequence
* company tag: Facebook
* Given an unsorted array of integers, find the length of longest continuous increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1.
 * Note: Length of the array will not exceed 10,000.

*****************************************************************************/
int findLengthOfLCIS(vector<int>& nums) {
	int n = nums.size();
	if (n == 0)
		return 0;
	vector<int> dp(n, 1);
	int maxLen = 1;

	for (int i = 1; i < n; i++) {
		if (nums[i] > nums[i - 1]) {
			dp[i] = dp[i - 1] + 1;
		}
		maxLen = max(maxLen, dp[i]);
	}

	return maxLen;
}

/******************************************************************************
* Question: #673 Number of Longest Incresing Subsequence
* company tag: Facebook
* Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length
is 1, so output 5.

* Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit
* signed int.

 *****************************************************************************/
int findNumberOfLIS(vector<int>& nums) {
	int n = nums.size();
	if (n == 0)
		return 0;
	vector<int> len(n, 1); // the length of longest increasing subsequence ends with nums[i]
	vector<int> cnt(n, 1);  // the count of max length ends with nums[i]
	int maxLen = 1, maxCount = 1;
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (nums[j] < nums[i]) {
				if (len[j] + 1 > len[i]) {
					len[i] = len[j] + 1;
					cnt[i] = cnt[j];
				} else if (len[j] + 1 == len[i]) {
					cnt[i] += cnt[j];
				}
			}
		}

		if (maxLen == len[i])
			maxCount += cnt[i];
		else if (len[i] > maxLen) {
			maxLen = len[i];
			maxCount = cnt[i];
		}
	}
	return maxCount;
}



/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

/*
dp solution that will take O(n^2) time complexity
*/
int lengthOfLIS(vector<int>& nums)
{
  int nlen = nums.size();
  int maxLen = 0;
  vector<int> dp(nlen, 1);
  for(int i=1; i<nlen; i++)
  {
    for(int j=i-1; j>=0; j--)
    {
      if(nums[j] < nums[i]) dp[i] = max(dp[j]+1, dp[i]);
    }
    maxLen = max(maxLen, dp[i]);
  }

  return maxLen;
}

/*
O(nlogn) solution - we keep one vector to log the smallest tail number of possible increasing subsequence
with lenth i, when we meet a new element in the array, we compare it with tails in the vector, if it is
larger than all the values, then increase the length by one.
Ohterwise, we replace the tail with this new tail
*/
int lenOfLIS(vector<int> nums)
{
  vector<int> tails;
  for(int i=0; i<nums.size(); i++)
  {
    auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
    if(it == tails.end()) tails.push_back(nums[i]);
    else *it = nums[i];
  }
  return tails.size();
}


int lenLISBinarySearch(vector<int> nums)
{
  int nlen = nums.size();
  vector<int> tails(nlen);
  int size = 0;
  for(int x : nums)
  {
    int i=0, j=size;
    while(i != j)
    {
      int m = (i+j)/2;
      if(tails[m] < x) i = m+1;
      else j = m;
    }
    tails[i] = x;
    if(i == size) size++;
  }
  return size;
}




