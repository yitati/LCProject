/*
 * BuyStockII.cpp
 *

Given an array of positive integers representing a stock’s price on each day.
On each day you can only make one operation: either buy or sell one unit of stock,
you can make as many transactions you want, but at any time you can only hold at
most one unit of stock. Determine the maximum profit you can make.

Assumptions

The give array is not null and is length of at least 2
Examples

{2, 3, 2, 1, 4, 5}, the maximum profit you can make is (3 - 2) + (5 - 1) = 5

 */

#include <vector>

using namespace std;

int maxProfitII(vector<int> input)
{
	int profit = 0;
	for(int i=1; i<input.size(); i++)
	{
		int diff = input[i]-input[i-1];
		if(diff > 0) profit += diff;
	}
	return profit;
}



