/***************************************************************************
 * Question #530. Minimum Absolute Difference in BST
 * Given a binary search tree with non-negative values, find the minimum absolute difference
 * between values of any two nodes.

Example:
Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

 *  Note: There are at least two nodes in this BST.
 ***************************************************************************/

#include <climits>
#include "../Leetcode/BST.h"

using namespace std;

void findMinDiff(TreeNode* root, int lowerBound, int upperBound, long long& minDiff)
{
	if(!root) return;
	minDiff = min(minDiff, min((long long)root->val-lowerBound, upperBound-(long long)root->val));

	findMinDiff(root->left, lowerBound, root->val, minDiff);
	findMinDiff(root->right, root->val, upperBound, minDiff);
}

int getMinimumDifference(TreeNode* root)
{
	if(!root) return 0;
	long long minDiff = INT_MAX;
	findMinDiff(root, INT_MIN, INT_MAX, minDiff);
	return minDiff;
}



