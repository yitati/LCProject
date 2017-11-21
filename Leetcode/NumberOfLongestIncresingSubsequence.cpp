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

#include <vector>

using namespace std;

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


