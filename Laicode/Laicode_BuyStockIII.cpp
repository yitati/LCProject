/*
 * Laicode_BuyStockIII.cpp
 *

Given an array of positive integers representing a stock’s price on each day.
On each day you can only make one operation: either buy or sell one unit of stock,
at any time you can only hold at most one unit of stock, and you can make at most
2 transactions in total. Determine the maximum profit you can make.

Assumptions

The give array is not null and is length of at least 2
Examples

{2, 3, 2, 1, 4, 5, 2, 11}, the maximum profit you can make is (5 - 1) + (11 - 2) = 13

 */

#include <vector>
#include <climits>

using namespace std;

/*
 * we need to do twice Buy Stock I, get the most buy profit at each point
 * and the sell profit at each point, then get the total of both.
 */
int maxProfit(vector<int> input)
{
	if(input.size() < 2) return 0;
	int n = input.size();
	int buy = input[0], sell = input[n-1], maxProfit = 0, tempMax = INT_MIN;
	vector<int> profit(n, 0);

	// calculate the max profit to sell before i (inclusive)
	for(int i=0; i<input.size(); i++)
	{
		tempMax = max(tempMax, input[i]-buy);
		profit[i] = tempMax;
		maxProfit = max(maxProfit, tempMax);
		buy = min(buy, input[i]);
	}
	// calculte the max profit to buy after i (exclusive)
	tempMax = INT_MIN;
	for(int i=n-2; i>0; i--)
	{
		tempMax = max(tempMax, sell-input[i]);
		profit[i-1] += tempMax;
		maxProfit = max(maxProfit, profit[i]);
		sell = max(sell, input[i]);
	}
	return maxProfit;
}


