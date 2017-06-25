/******************************************************************************/
/*
* Question: #123 Best Time To Buy And Sell Stock III
* Say you have an array for which the ith element is the price of a given stock on day i.
* Design an algorithm to find the maximum profit. You may complete at most two transactions.
* Note:
* You may not engage in multiple transactions at the same time 
* (ie, you must sell the stock before you buy again).*/
/*****************************************************************************/

#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int maxProfitIII(vector<int>& prices) 
{
	int len = prices.size();
	if (len == 0) return 0;
	vector<int> profit(len, 0);
	int minPrice = prices[0];
	int maxPrice = prices[len - 1];
	int tmpMax = INT_MIN;
	int globalMax = 0;

	// calculate the max profit to sell before (inclusive) i
	profit[0] = 0;
	for (int i = 1; i < len; i++)
	{
		tmpMax = max(tmpMax, prices[i] - minPrice);
		profit[i] = tmpMax;
		globalMax = max(globalMax, profit[i]);
		minPrice = min(minPrice, prices[i]);
	}
	tmpMax = INT_MIN;
	// max profit when buying after (exclusive i)
	for (int i = len - 2; i > 0; i--)
	{
		tmpMax = max(tmpMax, maxPrice - prices[i]);
		profit[i - 1] += tmpMax;
		globalMax = max(globalMax, profit[i]);
		maxPrice = max(maxPrice, prices[i]);
	}
	// combine to get the sum
	return globalMax;
}
