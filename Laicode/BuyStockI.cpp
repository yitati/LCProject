/*
 * BuyStockI.cpp
 *
Given an array of positive integers representing a stock’s price on each day.
On each day you can only make one operation: either buy or sell one unit of
stock and you can make at most 1 transaction. Determine the maximum profit you can make.

Assumptions

The given array is not null and is length of at least 2.
Examples

{2, 3, 2, 1, 4, 5}, the maximum profit you can make is 5 - 1 = 4
 */

#include <vector>

using namespace std;

int maxProfitI(vector<int> input)
{
	if(input.size() < 2) return 0;
	int profit = 0;
	int buy = input[0];
	for(int i=1; i<input.size(); i++)
	{
		profit = max(input[i] - buy, profit);
		buy = min(input[i], buy);
	}
	return profit;
}
