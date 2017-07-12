/******************************************************************************
* Question: #152 Maximum Product Subarray
* company tag: LinkedIn
* Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

*****************************************************************************/

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxProduct(vector<int>& nums) 
{
	int maxP = 1, minP = 1;
	int maxProduct = INT_MIN;
	for (int i = 0; i<nums.size(); i++)
	{
		int oldMaxP = maxP;
		int oldMinP = minP;
		maxP = max(max(oldMinP * nums[i], nums[i]), oldMaxP * nums[i]);
		minP = min(min(oldMaxP * nums[i], nums[i]), oldMinP * nums[i]);
		maxProduct = max(maxProduct, maxP);
		if (nums[i] == 0)
		{
			maxP = 1;
			minP = 1;
		}
	}

	return maxProduct;
}
