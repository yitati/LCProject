/*
 * Laicode_MergeStones.cpp

 We have a list of piles of stones, each pile of stones has a certain weight, represented by an array of integers.
 In each move, we can merge two adjacent piles into one larger pile, the cost is the sum of the weights of the two piles.
 We merge the piles of stones until we have only one pile left. Determine the minimum total cost.

Assumptions

stones is not null and is length of at least 1
Examples

{4, 3, 3, 4}, the minimum cost is 28

merge first 4 and first 3, cost 7

merge second 3 and second 4, cost 7

merge two 7s, cost 14

total cost = 7 + 7 + 14 = 28

*/

/*
 *
 * For this kind of dp problem, we want to start with the last merge.
 * Suppose dp[i][j] denote the merge result of stones[i] to stones[j], then for the last merge we have
 * dp[i][j] = min(dp[i][k] + dp[k+1][j]) + sum[i...j] where sum[i...j] is the sum of stones from i to j
 * From the above deduction rule we know that when we are calculating dp[i][j], dp[i][k] and dp[k+1][j]
 * should be already calculated - so this is a problem that we need to use shorter result to calculate
 * longer result.
 *
 */

#include <vector>
#include <climits>

using namespace std;

int minCost(vector<int> stones)
{
	// then create a matrix to store the dp[i][j]
	vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), 0));

	// outer loop should use length of sub array
	for(int len=1; len <= stones.size(); len++){
		for(int lhs = 0; lhs + len -1 < stones.size(); lhs++){
			int rhs = lhs + len - 1;
			if(lhs == rhs) {
				dp[lhs][rhs] = 0;
				continue;
			}
			// calculate the regonal sum
			int sum = 0, minCost = INT_MAX;
			for(int k = lhs; k <= rhs; k++) sum += stones[k];
			// calculate the mincost
			for(int k = lhs; k < rhs; k++){
				minCost = min(minCost, sum + dp[lhs][k] + dp[k+1][rhs]);
			}
			dp[lhs][rhs] = minCost;
		}
	}

	return dp[0][stones.size()-1];
}
