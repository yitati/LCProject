/******************************************************************************/
/*
* Question: #96 Unique Binary Search Tree
* Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
/*****************************************************************************/

#include <vector>

using namespace std;

/*
 * Given a sequence 1...n to construct a binary search tree, we could numerate each
 * number i in the sequence, and use the number as the root, naturally, the subsequence 1...(i-1)
 * on its left side would lay on the left branch of the root, and similarly the right subsequence
 * (i+1) ... n lay on the right branch of the root. We then can construct the subtree from
 * the subsequence recursively. Through above approach, we could ensure that the BST that we construct
 * are all unique, since they have unique roots.
 * Use dp[i] to denote the number of unique BST using sequence length of i, then we can easily get two base
 * cases -
 * - dp[0] = 1 (empty tree)
 * - dp[1] = 1 (single node tree)
 * and the deduction rule
 * - dp[i] = dp[j]*dp[i-j-1]
 */

int numTrees(int n)
{
	// valid value from 0 to n
	vector<int> dp(n+1, 0);
	dp[0]=1;
	dp[1]=1;
	for(int i=2; i<=n; i++)
	{
		for(int j=0; j<i; j++)
		{
			dp[i] += dp[j]*dp[i-j-1];
		}
	}
	return dp[n];
}
