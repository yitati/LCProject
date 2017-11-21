/*
 * Laicode_CuttingWoodI.cpp

There is a wooden stick with length L >= 1, we need to cut it into pieces, where the cutting positions
are defined in an int array A. The positions are guaranteed to be in ascending order in the range of [1, L - 1].
The cost of each cut is the length of the stick segment being cut.
Determine the minimum total cost to cut the stick into the defined pieces.

Examples

L = 10, A = {2, 4, 7}, the minimum total cost is 10 + 4 + 6 = 20 (cut at 4 first then cut at 2 and cut at 7)

 */


#include <vector>
#include <climits>

using namespace std;

/*
 * this problem is very similar to merge stones
 * suppose there are cuts happen at i and j respectively, then the minimal cost we have at [i,j] is
 * dp[i][j] = min(dp[i][k], dp[k+1][j]) + length[i,j]
 * and k should be a possible cut point too.
 * And i is from 0  and j is ending at n
 */
int minCostWoodCutI(vector<int> cuts, int length){
	// add cutLen = 0 at the begining and add cutLen = len at the end
	cuts.insert(cuts.begin(), 0);
	cuts.push_back(length);

	vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size()));

	// since we are still making longer result using smaller results, so have to use len
	for(int len = 2; len <= cuts.size(); len++){
		for(int lhs=0; lhs + len - 1 < cuts.size(); lhs++){
			int rhs = lhs + len - 1;
			if(rhs == lhs + 1) {
				dp[lhs][rhs] = 0;
			}
			else{
				int sum = cuts[rhs] - cuts[lhs];
				int minCost = INT_MAX;
				for(int k=lhs+1; k<rhs; k++){  // k is the possible cutting point from (lhs, rhs)
					minCost = min(minCost, dp[lhs][k] + dp[k][rhs] + sum);
				}
				dp[lhs][rhs] = minCost;
			}
		}
	}

	return dp[0].back(); // dp[0][cuts.size()-1]
}



