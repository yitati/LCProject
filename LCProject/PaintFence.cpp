/******************************************************************************/
/*
* Question: #276 Paint Fence
* There is a fence with n posts, each post can be painted with one of the k colors.
* You have to paint all the posts such that no more than two adjacent fence posts have the same color. 
* Return the total number of ways you can paint the fence. 
* Note:
* n and k are non-negative integers. 
*/
/*****************************************************************************/

int numWays(int n, int k)
{
	// first check base / corner case
	if (n == 0) return 0;
	else if (n == 1) return k;
	// we take first two posts as base case
	// if they painted with different colors, there will be k * (k-1) ways
	// if they painted with same color, there will be k ways
	int diffCount = k*(k - 1);
	int sameCount = k;
	// count from 2 to the last one
	for (int i = 2; i<n; i++)
	{
		int lastDiff = diffCount;
		// if the third one is painted differently with the second one, it has k-1 choice
		diffCount = (diffCount + sameCount) * (k - 1);
		// if the third one is painted same with the second one, it has (sum - lastSame) choice, which is lastDiff
		sameCount = lastDiff;
	}
	return diffCount + sameCount;
}