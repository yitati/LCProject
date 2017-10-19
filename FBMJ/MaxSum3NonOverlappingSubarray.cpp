/*
In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers,
return the lexicographically smallest one.

Example:
Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
Note:
nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).
 */


#include <vector>

using namespace std;

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
	int n = nums.size();
	if (k < 1 || k > n / 3)
		return {};

	vector<int> sum = { 0 }, posLeft(n, 0), posRight(n, n - k), ans(3, 0);

	for (int num : nums)
		sum.push_back(sum.back() + num);

	// calculate the posLeft
	for (int i = k, maxSum = sum[k]; i < n; i++) {
		if (sum[i + 1] - sum[i - k + 1] > maxSum) {
			posLeft[i] = i - k + 1;
			maxSum = sum[i + 1] - sum[i - k + 1];
		} else
			posLeft[i] = posLeft[i - 1];
	}

	// calculate the posRight
	for (int i = n - k - 1, maxSum = sum[n] - sum[n - k]; i >= 0; i--) {
		if (sum[i + k] - sum[i] >= maxSum) {
			posRight[i] = i;
			maxSum = sum[i + k] - sum[i];
		} else
			posRight[i] = posRight[i + 1];
	}

	// calculate sum
	for (int i = k, maxSum = INT_MIN; i + 2 * k <= n; i++) {
		int l = posLeft[i - 1], r = posRight[i + k];
		int curr = sum[l + k] - sum[l] + sum[i + k] - sum[i] + sum[r + k]
				- sum[r];
		if (curr > maxSum) {
			maxSum = curr;
			ans = {l, i, r};
		}
	}

	return ans;
}
