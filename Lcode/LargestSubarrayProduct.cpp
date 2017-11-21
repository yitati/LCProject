/*
 * Laicode_LargestSubarrayProduct.cpp
 *

Given an unsorted array of doubles, find the subarray that has the greatest product.
Return the product.

Assumptions

The given array is not null and has length of at least 1.
Examples

{2.0, -0.1, 4, -2, -1.5}, the largest subarray product is 4 * (-2) * (-1.5) = 12

 */

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

double largestProduct(vector<double> input)
{
	if(input.empty()) return 0;
	double maxP = 1.0, minP = 1.0;
	double maxProduct = (double)INT_MIN;

	for(int i=0; i<input.size(); i++)
	{
		double oldMax = maxP;
		double oldMin = minP;
		maxP = max(input[i], max(oldMax * input[i], oldMin * input[i]));
		minP = min(input[i], min(oldMax * input[i], oldMin * input[i]));
		maxProduct = max(maxP, maxProduct);
		if(input[i] == 0)
		{
			maxP = 1;
			minP = 1;
		}
	}
	return maxProduct;
}

