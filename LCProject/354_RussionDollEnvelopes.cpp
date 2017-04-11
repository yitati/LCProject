/******************************************************************************/
/*
* Question: #354 Russion Doll Envelopes
* You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
* One envelope can fit into another if and only if both the width and height of one envelope is 
* greater than the width and height of the other envelope.
* What is the maximum number of envelopes can you Russian doll? (put one inside other) 

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]). 

*/
/*****************************************************************************/

// Refer to problem 300 Longest Increasing Subsequence
// This problem is using the same solution with O(n^2) and O(nlogn) time complexity

#include <vector>
#include <algorithm>

using namespace std;

// O(n^2) solution
int maxEnvelopes(vector<pair<int, int>>& envelopes) 
{
	if (envelopes.empty()) return 0;
	int maxNum = 1;
	vector<int> dp(envelopes.size(), 1);

	// sort the vector of pairs based on the first element
	sort(envelopes.begin(), envelopes.end());

	for (int i = 1; i < envelopes.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maxNum = max(maxNum, dp[i]);
	}
	return maxNum;
}

// O(nlogn) solution
// Use lower_bound function
int maxEnvelopes_binarySearch(vector<pair<int, int>>& envelopes)
{
	sort(envelopes.begin(), envelopes.end(), [](pair<int, int>a, pair<int, int>b) {
		return a.first < b.first || (a.first == b.first && a.second > b.second); });

	vector<int> dp;
	for (auto e : envelopes)
	{
		auto it = lower_bound(dp.begin(), dp.end(), e.second);
		if (it == dp.end()) dp.push_back(e.second);
		else *it = e.second;
	}

	return dp.size();
}