/*
 * Laicode_LongestAscendingSubsequence.cpp
 *

Given an array A[0]...A[n-1] of integers, find out the length of the longest ascending subsequence.

Assumptions

A is not null
Examples
Input: A = {5, 2, 6, 3, 4, 7, 5}
Output: 4
Because [2, 3, 4, 5] is the longest ascending subsequence.

 */

#include <vector>

using namespace std;

// Same with LC 300 Longest Increasing Subsequence

// Solution 1 - DP solution
/*
 * suppose dp[i] denotes the longest ascending subsequence ending at i
 * then dp[i] = max(dp[j]) + 1 and j should be in range [0, i-1]
 */
int longestAscendingSubsequence(vector<int> a)
{
	vector<int> dp(a.size(), 1);
	if(a.empty()) return 0;

	int maxLen = 1;
	for(int i = 1; i<a.size(); i++)
	{
		for(int j=i-1; j>=0; j--)
		{
			if(a[i] > a[j]) dp[i] = max(dp[i], dp[j]+1);
		}
		maxLen = max(maxLen, dp[i]);
	}

	return maxLen;
}

// Solution 2 - O(nlgn) solution
/*
 * The idea is that as you iterate the sequence, you keep track of the minimum value a subsequence
 * of given length might end with, for all so far possible subsequence lengths. So dp[i] is the
 * minimum value a subsequence of length i+1 might end with. Having this info, for each new number
 * we iterate to, we can determine the longest subsequence where it can be appended using binary search.
 * The final answer is the length of the longest subsequence we found so far.
 */
int LIS_binarySearch(vector<int> a)
{
	vector<int> collect;
	for(int i=0; i<a.size(); i++)
	{
		auto it = lower_bound(collect.begin(), collect.end(), a[i]);
		if(it == collect.end()) collect.push_back(a[i]);
		else *it = a[i];
	}
	return collect.size();
}
